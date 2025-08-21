/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/


// Not sure when the browser delivers the onInstalled event.  Just set it up as early as possible.
let gJustInstalled = false;
browser.runtime.onInstalled.addListener(function(info){
    // console.log("runtime.onInstalled", info);
    gJustInstalled = info.reason == "install" || info.reason == "update";
});


// module boss_daemon, background script.
(function(scope, modulename) {
    "use strict";

    // Import:
    // import logger
    // import appcfg
    // import app
    // import ringbuf
    // import db
    // import settings
    // import session
    // import sessions
    // import dataio
    let Session  = session.Session;
    let Sessions = sessions.Sessions;
    let RingBuf  = ringbuf.RingBuf;

    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

 
    var module = function() { };        // Module object to be returned.
    if (scope && modulename)
        scope[modulename] = module;     // set module name in scope, otherwise caller sets the name with the returned module object.

    let cmdLog = new RingBuf(10);       // save a short log of command and its result; UI client can monitor storage event to pick up cmd result.

    // Global state
    let gCtx = {
        atLeastOneSessionRestored:  false,
        lastRestoringTime:          0,
        pendingRestoredTabs:        {},
        sessions:                   Sessions.newInitSessions(),
        previousExitId:             "",
        windowCount:                0,
        majorVersion:               "0",            // major browser version to detect new browser features.
        lastGC:                     Date.now(),     // push the GC schedule one interval away at startup.
        tabs_onUpdated_url:         "",
        uiUrl:                      browser.runtime.getURL("popup/boss_popup.html"),
        importUrl:                  browser.runtime.getURL("popup/boss_import.html"),
        optionsUrl:                 browser.runtime.getURL("options/options.html"),
    };
    gCtx.filterUrls = [ gCtx.uiUrl, gCtx.importUrl, gCtx.optionsUrl ];  // skip addon's own urls when snapshotting session.

    // deprecated
    gCtx.pAddPendingTab = function(tab) {
        gCtx.atLeastOneSessionRestored = true;
        gCtx.pendingRestoredTabs[tab.id] = tab;
    }

    // TODO: deprecated
    const GC_INTERVAL_MS = 11 * 60 * 1000;  // Garbage collect the pendingTabs once in a while.  Make it interleave with the backup schedule.
    gCtx.gcPendingTabs = function() {
        let nowMS = Date.now();
        if (nowMS - gCtx.lastGC > GC_INTERVAL_MS) {
            let survivingPendingRestoredTabs = {};      // copying garbage collection.
            browser.tabs.query({})
                .then( tabs => tabs.forEach( tab => {
                    if (app.has(gCtx.pendingRestoredTabs, tab.id)) {
                        survivingPendingRestoredTabs[tab.id] = gCtx.pendingRestoredTabs[tab.id];
                    }
                }))
                .then( () => {
                    gCtx.pendingRestoredTabs = survivingPendingRestoredTabs;
                })
            gCtx.lastGC = nowMS;
        }
    }
    // Global state end

    
    // init() is called at the end of script definition, before the callbacks.
    function init() {
        Promise.resolve()
            .then(() => settings.pLoadCurrent())
            .then(() => appcfg.initLogLevel())
            .then(() => log.info("boss_daemon init ===================================================== ") )
            .then(() => browser.runtime.getBrowserInfo().then(info => gCtx.majorVersion = app.defObjVal(info, "version", "0").split(".")[0]) )
            .then(() => db.pOpenDB())
            .then(() => Sessions.pLoadAllSessionsData().then( sessions => gCtx.sessions = sessions) )
            .then(() => checkPreviousExit() )
            .then(() => browser.storage.onChanged.addListener(storage_onChanged) )
            //.then(() => browser.browserAction.onClicked.addListener(browserAction_onClicked) )
            .then(() => browser.commands.onCommand.addListener(commands_onCommand) )
            .then(() => browser.windows.onCreated.addListener(windows_onCreated) )
            .then(() => browser.windows.onRemoved.addListener(windows_onRemoved) )
            //.then(() => browser.tabs.onActivated.addListener(tabs_onActivated) )  // deprecated
            .then(() => browser.tabs.onAttached.addListener(tabs_onAttached) )
            .then(() => browser.tabs.onDetached.addListener(tabs_onDetached) )
            .then(() => browser.tabs.onMoved.addListener(tabs_onMoved) )
            .then(() => browser.tabs.onRemoved.addListener(tabs_onRemoved) )
            .then(() => browser.tabs.onUpdated.addListener(tabs_onUpdated) )
            .then(() => pSetupMessageHandlers() )
            .then(() => setupAlarms() )
            .then(() => autoRestoreOnStartup() )
            .then(() => log.info("boss_daemon init done ----------------------------------------------- ") )
            .catch( e => log.warn(e) )
    }

    function checkPreviousExit() {
        gCtx.previousExitId = gCtx.sessions.autoSavedIdOnCrash || "";
    }

    function storage_onChanged(storageChange) {
        // log.info("storage_onChanged", storageChange);
        if (app.has(storageChange, settings.STORAGE_NAME)) {
            settings.pLoadCurrent()
                .then(() => appcfg.initLogLevel())
                .then(() => gCtx.sessions.settingOnChanged());
        }
    }

    // Browser action button won't be clicked when the manifest file's browser_action has default_popup defined.
    function browserAction_onClicked() {
        log.info("browserAction_onClicked, command as: launch");
    }

    function commands_onCommand(command) {
        log.info("commands_onCommand, command: " + command);
        pActivateTabUI();
    }

    function windows_onCreated() {
        gCtx.windowCount++;
    }

    function windows_onRemoved() {
        gCtx.windowCount--;
        if (gCtx.windowCount <= 0 ) {
            log.info("windows_onRemoved, normal browser shutdown detected");
            // gCtx.sessions.pClearCrashStore();
        }
    }

    // TODO: deprecated
    function tabs_onActivated(activeInfo) {
        let pendingTab = gCtx.pendingRestoredTabs[activeInfo.tabId];
        if (pendingTab) {
            if (!pendingTab.active) {
                log.info("tabs_onActivated tab " + activeInfo.tabId + " win " + activeInfo.windowId + " restore url " + pendingTab.url);
                browser.tabs.sendMessage(activeInfo.tabId, {
                    cmd:    "restore-url",
                    url:    pendingTab.url,
                }).then(() => {
                    // Only delete the pending tab after a successful send.
                    delete gCtx.pendingRestoredTabs[activeInfo.tabId];
                }).catch(e => {
                    // A tab could be clicked/activated before its on_inject script has started listening for the msg.
                    // The on_inject script would call cs-query-pending-tab later to get the pending tab.
                    console.error(`catch tab ${pendingTab.id}: ${e}`)
                })
            } else {
                log.info("tabs_onActivated tab " + activeInfo.tabId + " win " + activeInfo.windowId + ", the pendingTab is active.  The tab will refresh itself.");
            }
        } else {
            // No pending tab in the list for the activated tab id.
            // 1. Other tabs opened by the user and not restored by Session Boss.
            // 2. Pending tabs that have been filled out when activated/clicked would be removed from the pending list,
            //    and not be found again in the subsequent activations.
            // 3. The active tab when first restored will fire an onActivated event, which can be before the pending list
            //    has been set up, due to race condition between the tab restoration code and the onActivated event.
            //    It's ok since the active tab's on_inject will handle active tab url in pQueryPendingTab().
            // 4. The extension being reloaded would wipe out the pending list.  Can't do much in the case.
            log.info("tabs_onActivated tab " + activeInfo.tabId + " win " + activeInfo.windowId + " not a pendingTab");
        }
    }

    // Batch up events for some times before doing the backup.
    let dBackupSessionOnEvents30 = app.debounce(function(){
        // Cancel backup if the tab changes came within 60 seconds of the last restore.
        if (Date.now() - gCtx.lastRestoringTime < 60*1000) {
            // log.info("dBackupSessionOnEvents30 cancelled due to too close to the last restore time.");
            return;
        }
        // log.info("dBackupSessionOnEvents30");
        gCtx.sessions.pBackupSessionOnChange(gCtx);
    }, 30*1000, false);

    function backupSessionOnEvents30() {
        // log.info("backupSessionOnEvents30");
        dBackupSessionOnEvents30();
    }

    let dBackupSessionOnEvents60 = app.debounce(function(){
        // log.info("dBackupSessionOnEvents60");
        gCtx.sessions.pBackupSessionOnChange(gCtx);
    }, 60*1000, true);

    function backupSessionOnEvents60() {
        // log.info("backupSessionOnEvents60");
        dBackupSessionOnEvents60();
    }

    function tabs_onAttached(tabId, attachInfo) {
        // log.info("tabs_onAttached " + tabId, attachInfo);
        backupSessionOnEvents30();
    }

    function tabs_onDetached(tabId, detachInfo) {
        // log.info("tabs_onDetached " + tabId, detachInfo);
        backupSessionOnEvents30();
    }

    function tabs_onMoved(tabId, moveInfo) {
        // log.info("tabs_onMoved " + tabId, moveInfo);
        backupSessionOnEvents30();
    }

    function tabs_onRemoved(tabId, removeInfo) {
        // log.info("tabs_onRemoved " + tabId, removeInfo);
        if (removeInfo.isWindowClosing) {
            // Don't save the session for closed window immediately.  The user is probably just rapidly closing tabs to quit the browser.
            log.info("tabs_onRemoved, isWindowClosing, wait 60s");
            backupSessionOnEvents60();
        } else {
            // Don't save the session for closed tabs immediately, which would overwrite the old current session without the closed tab.
            // Wait some time make sure closing tabs is really what the user wants.
            // log.info("tabs_onRemoved, wait 60s");
            backupSessionOnEvents60();
        }
    }

    function tabs_onUpdated(tabId, changeInfo, tab) {
        // log.info("tabs_onUpdated " + tabId, changeInfo);
        if (app.has(changeInfo, "url")) {
            gCtx.tabs_onUpdated_url = changeInfo.url;
        }
        if (app.defObjVal(changeInfo, "status", "") == "complete") {                // "complete" is triggered when the tab has been completely loaded.
            // log.info("tabs_onUpdated completed " + tabId);
            let mostRecentSession = gCtx.sessions.mostRecentSession;
            if (!mostRecentSession || mostRecentSession.urlOfTab(tabId) != tab.url) {
                if (!app.startsWithAny(gCtx.tabs_onUpdated_url, gCtx.filterUrls)) { // skip any update triggered from the filterUrls.
                    backupSessionOnEvents30();
                }
                gCtx.tabs_onUpdated_url = "";
            } else {
                // log.info("tabs_onUpdated completed " + tabId + " is duplicate as last one.  Ignored.");
            }
        }
    }


    function pSetupMessageHandlers() {
        // log.info("pSetupMessageHandlers");
        return browser.runtime.onMessage.addListener(function(msg, sender, sendResponse) {
            // log.info("onMessage() ", msg);
            try {
                switch (msg.cmd) {
                case "cs-log":
                    log.info("cs-log: ", msg.obj);
                    return;
                case "cs-query-pending-tab":
                    if (sender && sender.tab) {
                        let pendingTab = gCtx.pendingRestoredTabs[sender.tab.id];
                        log.info("cs-query-pending-tab " + sender.tab.id + " win " + sender.tab.windowId + ", atLeastOneSessionRestored: " + gCtx.atLeastOneSessionRestored + ", pendingTab: " + pendingTab);
                        if (pendingTab && pendingTab.active) {
                            // The active pending tab will be restored upon returning to on_inject queryPendingTab().  Clean up the pending tab.
                            delete gCtx.pendingRestoredTabs[pendingTab.id];
                        }
                        sendResponse({
                            status:         "ok",
                            hasRestored:    gCtx.atLeastOneSessionRestored,
                            pendingTab:     pendingTab,
                        });
                    }
                    return;
                case "undo-snapshot":
                    gCtx.sessions.pUndoSnapshot(gCtx);
                    break;
                case "redo-snapshot":
                    gCtx.sessions.pRedoSnapshot(gCtx);
                    break;
                case "save-all":
                    gCtx.sessions.pSaveAllWindows(gCtx);
                    break;
                case "save-window":
                    gCtx.sessions.pSaveCurrentWindow(gCtx);
                    break;
                case "update-sess":
                    gCtx.sessions.pUpdateSession(gCtx, msg.sessionId);
                    break;
                case "delete-sess":
                    gCtx.sessions.pDeleteSession(msg.sessionId);
                    break;
                case "toggle-auto-resotre":
                    gCtx.sessions.pToggleAutoRestore(msg.sessionId);
                    break;
                case "onchange-backup-now":
                    gCtx.sessions.pBackupSessionOnChange(gCtx)
                        .then(  res => pAddCmdLog(msg.cmd, { status: "ok",     message: res}) )
                        .catch( err => pAddCmdLog(msg.cmd, { status: "error",  message: err}) );
                    break;
                case "scheduled-backup-now":
                    gCtx.sessions.pRunScheduledBackup(gCtx);
                    // gCtx.sessions.pForceBackuppForceScheduledBackup();
                    break;
                case "del-all-user":
                    gCtx.sessions.pDeleteAllUserSessions();
                    //gCtx.sessions = Sessions.newInitSessions();
                    break;
                case "del-all-backup":
                    gCtx.sessions.pDeleteAllBackupSessions();
                    break;
                case "del-all-onchange":
                    gCtx.sessions.pDeleteAllOnChangeSessions();
                    break;
                case "purge-all":
                    gCtx.sessions.pPurgeAllData();
                    break;
                case "del-all-favicons":
                    db.pClearFaviconDb()
                        .then(  ()  => sendResponse({ status: "ok",     message: "Deleted all favicons"}) )
                        .catch( err => sendResponse({ status: "error",  message: err}) );
                    break;
                case "replace-sess":
                    gCtx.sessions.pRestoreSessionAsReplacement(msg.sessionId, msg.searchTerms, msg.searchByTab, gCtx)
                        .then(  ()  => sendResponse({ status: "ok",     message: "Restoring"}) )
                        .catch( err => sendResponse({ status: "error",  message: err}) );
                    break;
                case "restore-sess":
                    gCtx.sessions.pRestoreSessionAsAddition(msg.sessionId, msg.searchTerms, msg.searchByTab, gCtx)
                        .then(  ()  => sendResponse({ status: "ok",     message: "Restoring"}) )
                        .catch( err => sendResponse({ status: "error",  message: err}) );
                    break;
                case "replace-win":
                    gCtx.sessions.pRestoreWindowAsCurrentReplacement(msg.sessionId, msg.wid, msg.searchTerms, msg.searchByTab, gCtx)
                        .then(  ()  => sendResponse({ status: "ok",     message: "Restoring"}) )
                        .catch( err => sendResponse({ status: "error",  message: err}) );
                    break;
                case "append-win":
                    gCtx.sessions.pRestoreWindowAsCurrentAddition(msg.sessionId, msg.wid, msg.searchTerms, msg.searchByTab, gCtx)
                        .then(  ()  => sendResponse({ status: "ok",     message: "Restoring"}) )
                        .catch( err => sendResponse({ status: "error",  message: err}) );
                    break;
                case "restore-win":
                    gCtx.sessions.pRestoreWindowAsNew(msg.sessionId, msg.wid, msg.searchTerms, msg.searchByTab, gCtx)
                        .then(  ()  => sendResponse({ status: "ok",     message: "Restoring"}) )
                        .catch( err => sendResponse({ status: "error",  message: err}) );
                    break;
                case "delete-win":
                    gCtx.sessions.pDeleteWindow(msg.sessionId, msg.wid);
                    break;
                case "update-win":
                    gCtx.sessions.pUpdateWindow(gCtx, msg.sessionId, msg.wid);
                    break;
                case "explicit-win":
                    gCtx.sessions.pSetWindowProperty(msg.sessionId, msg.wid, "_explicitRestore", msg._explicitRestore);
                    break;
                case "rename-win": {
                    let preface = msg.newName.trim().replace(/[\[\]]+/g, "");
                    gCtx.sessions.pSetWindowProperty(msg.sessionId, msg.wid, "_name", preface);
                    break;
                }
                case "restore-tab":
                    gCtx.sessions.pRestoreTab(gCtx, msg.sessionId, msg.wid, msg.tid);
                    break;
                case "delete-tab":
                    gCtx.sessions.pDeleteTab(msg.sessionId, msg.wid, msg.tid);
                    break;
                case "set-tab-url":
                    gCtx.sessions.pSetTabProperty(msg.sessionId, msg.wid, msg.tid, "url", msg.url);
                    break;
                case "reorder-tabs":
                    gCtx.sessions.pReorderTabs(msg.sessionId, msg.wid, msg.tabIds);
                    break;
                case "update-tabs":
                    gCtx.sessions.pUpdateTabs(msg.sessionId, msg.wid, msg.changedTabs, msg.moved, msg.deleted, msg.orderedIds);
                    break;
                case "copy-sess":
                    gCtx.sessions.pCopyToUser(msg.sessionId);
                    break;
                case "rename-sess":
                    gCtx.sessions.pRenameSession(msg.sessionId, msg.newName);
                    break;
                case "setgroup-sess":
                    gCtx.sessions.pSetSessionGroup(msg.sessionId, msg.group);
                    break;
                case "export-data":
                    dataio.pExportData(gCtx.sessions, msg.exportType);
                    break;
                case "export-sess":
                    dataio.pExportSession(gCtx.sessions, msg.sessionId);
                    break;
                case "import-merge":
                    // Note: async call won't send back response in a timely manner.  UI should monitor storage change event to look for import completion.
                    dataio.pImportAllSessions(gCtx.sessions, msg.pendingResult.parsed)
                        .then(  msg => { log.info("result: " + msg); sendResponse({ status: "ok",   message: msg }) } )
                        .catch( err => sendResponse({ status: "error",  message: err})  );
                    break;
                case "import-replace":
                    dataio.pImportReplaceSessions(gCtx.sessions, msg.pendingResult.parsed)
                        .then(  msg => { log.info("result: " + msg); sendResponse({ status: "ok",   message: msg }) } )
                        .catch( err => sendResponse({ status: "error",  message: err})  );
                    break;
                case "import-as-new":
                    dataio.pImportAsUserSession(gCtx.sessions, msg.session)
                        .then(  msg => { log.info("result: " + msg); sendResponse({ status: "ok",   message: msg }) } )
                        .catch( err => sendResponse({ status: "error",  message: err})  );
                    break;
                case "import-favicon":
                    db.pImportFaviconDb(msg.pendingResult.parsed.favicon_db)
                        .then(  res => pAddCmdLog(msg.cmd, { status: "ok",     message: res}) )
                        .catch( err => pAddCmdLog(msg.cmd, { status: "error",  message: err}) );
                    break;
                case "get-prev-exit":
                    sendResponse({
                        previousExitId: gCtx.previousExitId,
                    });
                    break;
                case "activate-ui":
                    pActivateTabUI();
                    break;
                case "close-tab":
                    pCloseTab(msg.tabId);
                    break;
                case "log-tabs":
                    Sessions.pDumpTabs({});
                    break;
                case "log-sess":
                    gCtx.sessions.pDumpSession(msg.sessionId);
                    break;
                case "dbg-test":
                    // broadcastToTabs((tab) => ({
                    //     cmd:    "show-msg",
                    //     text:   `foobar id: ${tab.id}, url: ${tab.url} `
                    // }));
                    break;
                default:
                    log.info("onMessage() unknown cmd: ", msg);
                    break;
                }
            } catch(e) {
                log.error(e);
            }
        });
    }

    function setupAlarms() {
        browser.alarms.create("boss-scheduled-backup",  { periodInMinutes: 5 });
        // deprecated
        // browser.alarms.create("boss-gc",                { periodInMinutes: 3 });

        browser.alarms.onAlarm.addListener(function(alarmInfo){
            if (alarmInfo.name == "boss-scheduled-backup") {
                if (settings.ofCurrent.enableScheduleBackup) {
                    gCtx.sessions.pRunScheduledBackup(gCtx);
                } else {
                    log.info("Schedule Backup has been disabled via Preferences.");
                }
            } else if (alarmInfo.name == "boss-gc") {
                // deprecated
                gCtx.gcPendingTabs();
            }
        });
    }

    function autoRestoreOnStartup() {
        log.info("autoRestoreOnStartup " +
                 "- settings.restoreActionOnStartup: " + settings.ofCurrent.restoreActionOnStartup +
                 ", gJustInstalled: " + gJustInstalled +
                 ", autoRestoreSessionId: " + gCtx.sessions.autoRestoreSessionId);

        // setting deprecated
        // if (!settings.ofCurrent.autoRestoreOnStartup) {
        //     log.info("Skip autoRestoreOnStartup.  Auto-restore has been disabled via the Preferences page.");
        //     return;
        // }

        if (gJustInstalled) {
            log.info("Skip autoRestoreOnStartup.  Extension has just been installed/upgraded, not a real startup.");
            return;
        }

        log.info("Restore action at startup: " + settings.ofCurrent.restoreActionOnStartup);
        switch (settings.ofCurrent.restoreActionOnStartup) {
        case settings.RESTORE_ACTION_NO_ACTION:
            log.info("Skip autoRestoreOnStartup.  Restore action set to NO_ACTION.");
            break;
        case settings.RESTORE_ACTION_USER_SELECTED:
            if (gCtx.sessions.autoRestoreSessionId) {
                log.info("Doing auto-restore on user selected session...");
                gCtx.sessions.pRestoreSessionAsReplacement(gCtx.sessions.autoRestoreSessionId, [], false, gCtx)
                    .then(() => log.info("auto-restore on user selected session done"))
                    .catch(e => log.error("auto-restore user selected session failed", e))
            } else {
                log.info("Skip autoRestoreOnStartup.  No session has been set as auto-restore.");
            }
            break;
        case settings.RESTORE_ACTION_LAST_ON_CHANGE:
            if (gCtx.sessions.lastOnChangeSavedId) {
                gCtx.sessions.pRestoreSessionAsReplacement(gCtx.sessions.lastOnChangeSavedId, [], false, gCtx)
                    .then(() => log.info("auto-restore the last on-change session done"))
                    .catch(e => log.error("auto-restore the last on-change session failed", e))
            } else {
                log.info("Skip autoRestoreOnStartup.  No last on-change session.");
            }
            break;
        case settings.RESTORE_ACTION_LAST_SCHEDULED:
            if (gCtx.sessions.lastOnChangeSavedId) {
                gCtx.sessions.pRestoreSessionAsReplacement(gCtx.sessions.lastBackupSavedId, [], false, gCtx)
                    .then(() => log.info("auto-restore the last scheduled backup session done"))
                    .catch(e => log.error("auto-restore the last scheduled backup session failed", e))
            } else {
                log.info("Skip autoRestoreOnStartup.  No last scheduled backup session.");
            }
            break;
        default:
            log.warn("Unknown restore action at startup: " + settings.ofCurrent.restoreActionOnStartup);
            break;
        }
    }

    function broadcastToTabs(msgDataGetter) {
        return browser.tabs.query({})
            .then( tabs =>
                   Promise.all(
                       tabs.map( tab => {
                           if (!tab.incognito) {
                               log.info(`sendMessage to ${tab.id} ${tab.url}`);
                               let msg = msgDataGetter(tab);
                               return browser.tabs.sendMessage(tab.id, msg)
                                   .catch(e => console.error(`error on tab ${tab.id}, ${tab.url}: ${e}`));
                           }
                       })) );
    }

    function pActivateTabUI() {
        return browser.tabs.query({url: gCtx.uiUrl}).then( tabs => {
            let uiTab = tabs.length > 0 ? tabs[0] : null;
            if (uiTab) {
                return browser.windows.getLastFocused().then( focusedWin => {
                    let winHasFocus = uiTab.windowId == focusedWin.id;
                    let tabIsActive = uiTab.active;
                    return pEnsureUIPageInFront(uiTab.id, uiTab.windowId, winHasFocus, tabIsActive);
                });
            } else {
                return browser.tabs.create({ url: gCtx.uiUrl });
            }
        });
    }

    function pCloseTab(tabId) {
        return browser.tabs.remove(tabId);
    }

    function pEnsureUIPageInFront(uiTid, uiWid, winHasFocus, tabIsActive) {
        if (winHasFocus) {
            if (tabIsActive) {
                return Promise.resolve();
            } else {
                return browser.tabs.update(uiTid, {active: true});
            }
        } else {
            return browser.windows.update(uiWid, {focused: true}).then( () => {
                if (tabIsActive) {
                    return Promise.resolve();
                } else {
                    return browser.tabs.update(uiTid, {active: true});
                }
            })
        }
    }

    // The command log is stored here to trigger an storage event so that UI can pick up on the result of the command.
    function pSaveCmdLog() {
        return browser.storage.local.set({
            "cmdLogStore": {
                cmds: cmdLog.toArrayNewest()
            }
        });
    }

    function pAddCmdLog(cmd, result) {
        cmdLog.push({ cmd: cmd, res: result });
        return pSaveCmdLog();
    }


    init();

    
    return module;

}(this, "boss_daemon"));    // Pass in the global scope as 'this' scope.

