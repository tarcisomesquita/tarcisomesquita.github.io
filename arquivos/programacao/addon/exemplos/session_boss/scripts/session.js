/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// session module
(function(scope, modulename) {
    "use strict";

    // Import
    // import /pkg/spark-md5/spark-md5.min.js
    // import moment
    // import logger
    // import appcfg
    // import db
    // import app
    // import settings
    // import container

    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    var module = function() { };       // Module object to be returned.
    if (scope && modulename)
        scope[modulename] = module;    // set module name in scope, otherwise caller sets the name with the returned module object.

    const USER = "user";
    const SCHEDULED = "auto";
    const ONCHANGE = "onchange";
    const AS_ALL = "as_all";
    const AS_WIN = "as_win";
    const GROUP_ONCHANGE = "on-change";
    const ERROR_PAGE_URL = browser.runtime.getURL("error.html");

    class Session {

        constructor(jsonObj) {
            this._type = "Session";
            this._version = 3;          // current version for the object format.
            if (jsonObj) {
                this._fromObj(jsonObj);
            } else {
                this._newVersion3();
            }
        }

        _fromObj(jsonObj) {
            switch (jsonObj._version) {
            case 1:
                return this._fromVersion1(jsonObj);
            case 2:
                return this._fromVersion2(jsonObj);
            case 3:
                return this._fromVersion3(jsonObj);
            default:
                throw Error("Unsupported session object version.");
            }
        }

        _newVersion1() {
            this.sessionId      = app.uuid();
            this.sessionTimeMS  = new Date().getTime();
            this.sessionType    = USER;
            this.savedAs        = AS_ALL;
            this.sessionName    = this.userSessionTsName;
            this.windows        = [];
            this.tabsOfWindow   = {};
            this.group          = "";       // belonging group, mainly for backup session grouping.
            this.groupTitle     = "";       // title for UI tooltip over group.
            this.tabMap         = {};       // map tabId to slim tab info (e.g. url); see _updateTabData() for its population.
        }

        _fromVersion1(jsonObj) {
            this.sessionId      = jsonObj.sessionId || app.uuid();
            this.sessionTimeMS  = (jsonObj.sessionTimeMS && jsonObj.sessionTimeMS > 0) ? jsonObj.sessionTimeMS : new Date().getTime();
            this.sessionType    = jsonObj.sessionType || USER;
            this.savedAs        = jsonObj.savedAs || AS_ALL;
            this.sessionName    = jsonObj.sessionName || this.userSessionTsName;
            this.windows        = jsonObj.windows || [];
            this.tabsOfWindow   = jsonObj.tabsOfWindow || {};
            this.group          = jsonObj.group || "";
            this.groupTitle     = jsonObj.groupTitle || "";
            this.tabMap         = jsonObj.tabMap || {};
        }

        _digestVersion1(md5) {
            md5.append(String(this.sessionId));
            md5.append(String(this.sessionTimeMS));
            md5.append(String(this.sessionType));
            md5.append(String(this.savedAs));
            md5.append(String(this.sessionName));
            this.windows.forEach( w => {
                md5.append(String(w.id));
                md5.append(String(w.focused));
                md5.append(String(w.top));
                md5.append(String(w.left));
                md5.append(String(w.width));
                md5.append(String(w.height));
                md5.append(String(w.type));
                md5.append(String(w.state));
                md5.append(String(w.title));
            });
            this.iterateAllTabs( t => {
                md5.append(String(t.id));
                md5.append(String(t.index));
                md5.append(String(t.windowId));
                md5.append(String(t.active));
                md5.append(String(t.pinned));
                md5.append(String(t.incognito));
                md5.append(String(t.cookieStoreId));
                md5.append(String(t.url));
                md5.append(String(t.title));
                // md5.append(String(t.favhash));              // don't add to digest since it's updated unpredictably.
                md5.append(String(t.isArticle));
                md5.append(String(t.isInReaderMode));
            });
            md5.append(String(this.group));
            md5.append(String(this.groupTitle));
        }

        _newVersion2() {
            this._newVersion1();
            // add extra attributes for the new version of the Window object.
            this.windows.forEach( w => {
                w._explicitRestore = false;
                w._name = "";
            });
        }

        _fromVersion2(jsonObj) {
            this._fromVersion1(jsonObj);
            this.windows.forEach( w => {    // .windows has been loaded in _fromVersion1().
                w._explicitRestore = app.defObjVal(w, "_explicitRestore", false);
                w._name = app.defObjVal(w, "_name", "");
            });
        }

        _digestVersion2(md5) {
            this._digestVersion1(md5);
            // this.windows.forEach( w => {
            //     md5.append(String(w._explicitRestore));
            //     md5.append(String(w._name));       // don't add to digest since it's updated unpredictably.
            // });
        }

        _newVersion3() {
            this._newVersion2();
            this._lastModified = 0;          // 0 for never modified or from an older version object.
            this.importTime = 0;
        }

        _fromVersion3(jsonObj) {
            this._fromVersion2(jsonObj);
            this._lastModified = jsonObj._lastModified || 0;
            this.importTime = jsonObj.importTime || 0;
        }

        _digestVersion3(md5) {
            this._digestVersion2(md5);
            // md5.append(String(this._lastModified));  // don't add to digest since it's updated unpredictably.
        }

        computeMessageDigest() {
            let md5 = new SparkMD5();
            this._digestVersion3(md5);
            return md5.end();
        }

        clone(withNewId) {
            let deepCopy = new Session(JSON.parse(JSON.stringify(this)));
            return withNewId ? deepCopy.setSessionId(app.uuid()) : deepCopy;
        }

        cloneAsUser(newName, setNewTime) {
            let newSess = this.clone(true).setSessionType(USER);
            if (newName)
                newSess.setSessionName(newName);
            if (setNewTime)
                newSess.sessionTimeMS = new Date().getTime();
            if (this.isScheduled || this.isOnChange)
                newSess.setGroup("").setGroupTitle("");
            return newSess;
        }

        mergeByLastModified(sess) {
            if (this.lastModified < sess.lastModified) {
                // Just copy all the fields.  Most are the same, except the modified ones, e.g. sessionName.
                Object.assign(this, sess);
                return true;    // merged
            }
            return false;       // not merged
        }

        // Iterate the tabs in place.  Modification to tab in callback changes the tab in the session directly.
        iterateAllTabs(fn) {
            this.windows.forEach( w => {
                if (this.tabsOfWindow[w.id]) {
                    this.tabsOfWindow[w.id].forEach( tab => fn(tab) );
                }
            });
        }

        setSessionId(sessionId) {
            this.sessionId = sessionId;
            return this;
        }

        setSessionName(sessionName) {
            this.sessionName = sessionName;
            return this.updateLastModified();
        }

        setGroup(group) {
            this.group = group;
            this.setGroupTitle(`group:${this.group}`);
            return this.updateLastModified();
        }

        setGroupTitle(groupTitle) {
            this.groupTitle = groupTitle;
            return this.updateLastModified();
        }

        setSessionType(sessionType) {
            if (!sessionType) throw Error("no sessionType");
            this.sessionType = sessionType;
            return this;
        }

        setSavedAs(savedAs) {
            if (!savedAs) throw Error("no savedAs");
            this.savedAs = savedAs || AS_ALL;
            return this;
        }

        updateLastModified() {
            this._lastModified = new Date().getTime();
            return this;
        }

        _updateTabData() {
            this.tabMap = {};
            this.iterateAllTabs( tab => {
                this.tabMap[tab.id] = {
                    url: tab.url || "",
                };
            });
            return this;
        }

        _pShrinkTabFavIcons() {
            return Promise.all( this.allTabs.map( tab => db.pSaveFaviconImage(tab).then( favhash => {
                if (favhash) {
                    tab.favhash = favhash;
                    tab.favIconUrl = null;
                }
            }) ));
        }

        pRestoreTabFavIconsInSession(tids) {
            let tidsSet = new app.AnySet(tids);
            return pRestoreTabFavIcons( this.allTabs.filter( tab => tidsSet.has(tab.id) ).filter( tab => !tab.favIconUrl ) );
        }

        get isUser()            { return this.sessionType == USER }
        get isScheduled()       { return this.sessionType == SCHEDULED  }
        get isOnChange()        { return this.sessionType == ONCHANGE }
        get isAsAll()           { return this.savedAs == AS_ALL }
        get isAsWin()           { return this.savedAs == AS_WIN }
        get windowCount()       { return this.windows.length }
        get tabCount()          { return Object.values(this.tabsOfWindow).reduce((count, tabs) => count + tabs.length, 0) }
        get allTabs()           { return [].concat.apply([], Object.values(this.tabsOfWindow))  }
        get shortTime()         { return moment(this.sessionTimeMS).format("MM-DD HH:mm")       }
        get fullTime()          { return moment(this.sessionTimeMS).format("YYYY-MM-DD HH:mm")  }
        get fullTime12()        { return moment(this.sessionTimeMS).format("YYYY-MM-DD HH:mma") }
        get lastModified()      { return this._lastModified ? this._lastModified : this.sessionTimeMS } // if not set, use sessionTimeMS
        get lastModifiedTime()  { return moment(this.lastModified).format("YYYY-MM-DD HH:mma")  }
        get userSessionTsName() { return "User Session " + this.shortTime }
        get subTitleInfo()      { return `${this.windowCount}W ${this.tabCount}T, ${moment(this.sessionTimeMS).fromNow()}` }
        get focusedWindow()     { return this.windows.find( w => w.focused ) }
        windex(winId)           { return this.windows.findIndex( w => w.id == winId ) }
        windowTabs(winId)       { return this.tabsOfWindow[winId] }
        windowTabCount(winId)   { return this.windowTabs(winId).length }
        windowTabsClone(winId)  { return this.windowTabs(winId).map( tab => Object.assign({}, tab) ) }
        isOlder(sessB)          { return this.sessionTimeMS < sessB.sessionTimeMS }     // smaller timestamp is older.
        findTab(winId, tabId)   { return this.windowTabs(winId).find( tab => tab.id == tabId ) }
        urlOfTab(tabId)         { return app.has(this.tabMap, tabId) ? app.defObjVal(this.tabMap[tabId], "url", "") : "" }
        windowPreface(windex)   { return this.windows[windex]._name }

        windowName(windex) {
            let title = this.windows[windex].title;
            if (this.windowPreface(windex)) {
                let prefaceInfo = parseTitlePreface(title);
                if (prefaceInfo) {
                    title = title.substring(prefaceInfo.roffset + 1).trim();            // remove the old preface in title.
                }
                title = "[" + this.windowPreface(windex) + "] " + title;                // replace with the user entered preface.
            }
            return title ? title : "Window #" + (windex + 1);
        }

        // isReplacingWindows: bool, searchTerms: [String], searchByTab: bool, gCtx: {}
        pRestoreSession(isReplacingWindows, searchTerms, searchByTab, gCtx) {
            log.info("pRestoreSession isReplacingWindows: " + isReplacingWindows + ", searchTerms: " + searchTerms + ", searchByTab: " + searchByTab);
            let windowsToRestore = this.windows.filter( w => !w._explicitRestore );     // excludes explicitly restored windows.
            let windRestoreInfos = this._prepareWindowsForRestore(windowsToRestore, searchTerms, searchByTab);
            return this._pRestoreWindows(windRestoreInfos, false, isReplacingWindows, true, gCtx);
        }

        // widToRestore: String, searchTerms: [String], searchByTab: bool, gCtx: {}
        pRestoreWindow(widToRestore, searchTerms, searchByTab, gCtx) {
            log.info("pRestoreWindow  widToRestore: " + widToRestore + ", searchTerms: " + searchTerms + ", searchByTab: " + searchByTab);
            let windowsToRestore = this.windows.filter( w => widToRestore == w.id );    // builds window list of one.
            let windRestoreInfos = this._prepareWindowsForRestore(windowsToRestore, searchTerms, searchByTab);
            return this._pRestoreWindows(windRestoreInfos, false, false, false, gCtx);
        }

        pRestoreWindowToCurrentWindow(winToRestore, isReplacingTabs, searchTerms, searchByTab, gCtx) {
            log.info("pRestoreWindowToCurrentWindow");
            let windowsToRestore = [ winToRestore ];                                    // only one window to restore into the current window.
            let windRestoreInfos = this._prepareWindowsForRestore(windowsToRestore, searchTerms, searchByTab);
            return this._pRestoreWindows(windRestoreInfos, true, isReplacingTabs, false, gCtx);
        }
        
        _prepareWindowsForRestore(windowsToRestore, searchTerms, searchByTab) {
            // log.info("_prepareWindowsForRestore searchTerms:" + searchTerms);
            let windRestoreInfos = windowsToRestore.map( win => ({
                originalWindow: win,
                originalTabs:   ensureOneActiveTab(filterTabs(this.windowTabs(win.id), searchTerms, searchByTab)),
                targetWindow:   null,
                newTabs:        [],
                tidsToRemove:   [],
            }) ).filter( info => info.originalTabs.length > 0 );    // don't restore window with 0 tabs after filtering.
            return windRestoreInfos;
        }

        _pRestoreWindows(windRestoreInfos, isCurrentWinTarget, isReplace, partOfAGroup, gCtx) {
            // log.info("_pRestoreWindows");
            let isReplacingWindows = isCurrentWinTarget ? false : isReplace;    // if current window is target, don't replace; otherwise, depending on tab replacement.
            let cids;
            let widsToRemove = [];
            let tabMappings = {
                newTidToOriginalTab: {},
                originalTidToNewTab: {},
            };

            return container.pGetContainerInfos()
                .then( infos    => cids = new Set(infos.map( c => c.cookieStoreId )) )                      // 1. get existing containers in system.
                .then( ()       => pGetWindowIdsToRemove(isReplacingWindows) )                              // 2. get windows to remove before creating new ones.
                .then( wids     => widsToRemove = wids )
                .then( ()       => pCreateTargetWindows(windRestoreInfos, isCurrentWinTarget, isReplace) )  // 3. create or obtain the target windows.
                .then( ()       => pPostCreateOnWindows(windRestoreInfos) )                                 // 3a. do any post window creation ops.
                .then( ()       => pFocusRestoringWindow(windRestoreInfos, partOfAGroup) )                  // 4. focus on the single restoring window.
                .then( ()       => windRestoreInfos.map( i => pRestoreWinTabs(i, gCtx, cids, tabMappings))) // 5. restore the tabs of each window.
                .then( restores => Promise.all(restores) )
                .then( ()       => windRestoreInfos.map( i => pUpdateOpenerTabIds(i.newTabs, tabMappings))) // 6. update OpenerTabId of any out of order tabs.
                .then( updates  => Promise.all(updates) )
                .then( ()       => windRestoreInfos.map( i => pRemoveOldTabs(i) ))                          // 7. remove any old tabs on each restored window.
                .then( removes  => Promise.all(removes) )
                .then( ()       => pRemoveWindows(widsToRemove) );                                          // 8. remove any old windows being replaced.
        }

        deleteWindow(winId) {
            let index = this.windows.findIndex( w => w.id == winId );
            if (index > -1) {
                this.windows.splice(index, 1);
                delete this.tabsOfWindow[winId];
                this.updateLastModified();
                this._updateTabData();
                return true;
            }
            return false;
        }

        updateWindow(winId, newSess) {
            let index = this.windows.findIndex( w => w.id == winId );
            if (index > -1) {
                let newWin = newSess.windows[0];    // there's only one item in the window array, the current window.
                let newWinId = newWin.id;
                newWin.id = winId;                  // use the old winId, to preserve unique window id.
                this.windows[index] = newWin;
                this.tabsOfWindow[winId] = newSess.tabsOfWindow[newWinId];
                this.tabsOfWindow[winId].forEach( tab => { tab.windowId = winId });
                this.updateLastModified();
                this._updateTabData();
                return true;
            }
            return false;
        }

        setWindowProperty(winId, propName, propValue) {
            let index = this.windows.findIndex( w => w.id == winId );
            if (index > -1) {
                this.windows[index][propName] = propValue;
                this.updateLastModified();
                this._updateTabData();
                return true;
            }
            return false;
        }

        setWindowOrderPos(winId, newPos) {
            if (newPos < 0 || newPos >= this.windows.length)
                throw Error("The new window position " + newPos + " is out of range [0, " + this.windows.length + ")");
            let index = this.windows.findIndex( w => w.id == winId );
            if (index > -1) {
                this.windows = app.arrayMove(this.windows, index, newPos);
                this.updateLastModified();
                return true;
            }
            return false;
        }

        pRestoreTab(gCtx, winId, tabId) {
            let tabs = this.tabsOfWindow[winId];
            if (!tabs)
                throw Error("Tabs are not found for the window " + winId + " in the session " + this.sessionName);
            let index = tabs.findIndex( tab => tab.id == tabId );
            if (index == -1)
                throw Error("Tab " + tabId + " is not found for the window " + winId + " in the session " + this.sessionName);
            let tabMappings = {
                newTidToOriginalTab: {},
                originalTidToNewTab: {},
            };
            let originalTab = Object.assign({}, tabs[index]);
            originalTab.active = true;
            return browser.windows.getCurrent({populate: true})
                .then( currentWindow => {
                    let createParams = {
                        windowId:           currentWindow.id,
                        active:             originalTab.active,
                        pinned:             originalTab.pinned,
                        cookieStoreId:      originalTab.cookieStoreId,
                        url:                resolveReaderModeUrl(originalTab.url),
                        openInReaderMode:   originalTab.openInReaderMode || isReaderModeUrl(originalTab.url),
                    };
                    return pRestoreTabInWindow(originalTab, createParams, currentWindow.id, gCtx, tabMappings);
                })
                .then( newTab   => pUpdateOpenerTabIds([newTab], tabMappings) )
                .then( updates  => Promise.all(updates) )
                .then( () => log.info("pRestoreTab done") );
        }

        updateTabs(winId, changedTabs, moved, deleted, orderedIds) {
            let tabs = this.tabsOfWindow[winId];
            if (tabs) {
                // Update the url/title from changedTabs
                if (Object.keys(changedTabs).length > 0) {
                    tabs.filter( tab => app.has(changedTabs, tab.id) ).forEach( tab => {
                        tab.url   = changedTabs[tab.id].url;
                        tab.title = changedTabs[tab.id].title;
                    });
                }
                if (Object.keys(deleted).length > 0) {
                    tabs = tabs.filter( tab => !app.has(deleted, tab.id) ); // delete by omission in copying.
                }
                let tabMapById = tabs.reduce( (map, tab) => { map[tab.id] = tab; return map }, {});
                tabs = orderedIds.map( tid => tabMapById[tid] ).filter(Boolean);
                this.tabsOfWindow[winId] = tabs;
                this.updateLastModified();
            }
        }

        deleteTab(winId, tabId) {
            let tabs = this.tabsOfWindow[winId];
            if (tabs) {
                let index = tabs.findIndex( tab => tab.id == tabId );
                if (index > -1) {
                    tabs.splice(index, 1);
                    this.updateLastModified();
                    this._updateTabData();
                    return true;
                }
            }
            return false;
        }

        setTabProperty(winId, tabId, propName, propValue) {
            let tabs = this.tabsOfWindow[winId];
            if (tabs) {
                let tab = tabs.find( tab => tab.id == tabId );
                if (tab) {
                    tab[propName] = propValue;
                    this.updateLastModified();
                    this._updateTabData();
                    return true;
                }
            }
            return false;
        }

        reorderTabs(winId, tabIds) {
            let tabs = this.tabsOfWindow[winId];
            if (tabs) {
                let tabMapById = tabs.reduce( (map, tab) => { map[tab.id] = tab; return map }, {} );
                this.tabsOfWindow[winId] = tabIds.map( tid => tabMapById[tid] );
                this.updateLastModified();
                this._updateTabData();
            }
        }

        computeTabUrlHash() {
            let md5 = new SparkMD5();
            this.iterateAllTabs( tab => { md5.append(tab.url) });
            return md5.end();
        }

    }


    // Module public functions
    
    async function pSnapshotSession(gCtx, tabQueryFilter) {
        let tabs = await browser.tabs.query(tabQueryFilter);
        tabs = tabs
            .filter( tab => (!app.startsWithAny(tab.url, gCtx.filterUrls)) && (settings.ofCurrent.includePrivateWindows || !tab.incognito) );
        let newSess = new Session();
        let uniqueWinIds = new Set(tabs.map( tab => tab.windowId ));
        uniqueWinIds.forEach( winId => newSess.tabsOfWindow[winId] = [] );
        tabs.forEach( tab => newSess.tabsOfWindow[tab.windowId].push(normalizeTab(tab)) );
        newSess.windows = await Promise.all( [...uniqueWinIds].map( wid => browser.windows.get(wid) ) );
        newSess.windows = newSess.windows.map( w => normalizeWindow(w) );
        newSess._updateTabData();
        await newSess._pShrinkTabFavIcons();
        return newSess;
    }

    function filterSessions(sessList, searchTerms, searchByTab) {
        sessList = filterByGroups(sessList, searchTerms);
        return searchByTab ? filterByTabs(sessList, searchTerms) : filterByNames(sessList, searchTerms);
    }

    // tabs: [Tab], searchTerms: [String], searchByTab: bool.  Return a copy of the array.
    function filterTabs(tabs, searchTerms, searchByTab) {
        let filterTokens = getFilterTokens(searchTerms);
        return searchByTab ? tabs.filter( t => app.hasAll(t.title, filterTokens, true) ) : tabs.slice();
    }

    function pRestoreTabFavIcons(tabs) {
        return Promise.all(tabs.map( tab => {
            return db.pGetFaviconImage(tab)
                .then( res => tab.favIconUrl = tab.favIconUrl || res.favIconUrl )   // update tab.favIconUrl in place.
        } ));
    }

    function pRestoreTabFavIcon(tab) {
        return db.pGetFaviconImage(tab).then( res => tab.favIconUrl = tab.favIconUrl || res.favIconUrl );
    }

    function normalizeWindow(win) {
        let newWin = {};
        newWin.id = win.id;
        newWin.focused = win.focused;
        newWin.top = win.top;
        newWin.left = win.left;
        newWin.width = win.width;
        newWin.height = win.height;
        newWin.type = win.type;
        newWin.state = win.state;
        newWin.title = win.title;
        // Hack: Firefox doesn't provide an API to read the titlePreface of a window.  Do a best effort parsing from the title.
        let prefaceInfo = parseTitlePreface(newWin.title);
        if (prefaceInfo) {
            newWin._name = prefaceInfo.preface;
        }
        return newWin;
    }

    function normalizeTab(tab) {
        let newTab = {};
        newTab.id = tab.id;
        newTab.index = tab.index;
        newTab.windowId = tab.windowId;
        newTab.active = tab.active;
        newTab.pinned = tab.pinned;
        newTab.incognito = tab.incognito;
        newTab.cookieStoreId = tab.cookieStoreId;
        newTab.url = tab.url;
        newTab.title = tab.title;
        newTab.favIconUrl = tab.favIconUrl;
        newTab.favhash = tab.favhash;
        newTab.sessionId = tab.sessionId;

        newTab.openerTabId = tab.openerTabId;
        newTab.isArticle = tab.isArticle;
        newTab.isInReaderMode = tab.isInReaderMode;
        return newTab;
    }


    // Module private functions

    function getGroupTokens(searchTerms)  { return app.toLower(searchTerms.filter(t => t.startsWith("group:")).map(t => t.substring("group:".length))) };
    function getFilterTokens(searchTerms) { return app.toLower(searchTerms.filter(t => !t.startsWith("group:"))) };

    function filterByGroups(sessList, searchTerms) {
        let groupTokens = getGroupTokens(searchTerms);
        return groupTokens.length == 0 ? sessList : sessList.filter(s => app.hasAny(s.group, groupTokens));
    }

    function filterByTabs(sessList, searchTerms) {
        let filterTokens = getFilterTokens(searchTerms);
        return sessList.filter( s => {
            let tabs = s.allTabs;
            return tabs.length == 0 || tabs.some( t => app.hasAll(t.title, filterTokens, true) );   // empty session with 0 windows & tabs qualifies, too.
        });
    }
    
    function filterByNames(sessList, searchTerms) {
        let filterTokens = getFilterTokens(searchTerms);
        return sessList.filter( s => app.hasAll(s.sessionName, filterTokens, true) || app.hasAll(s.subTitleInfo, filterTokens, true) );
    }


    // User editing can remove the active tab.  Promote one if no active tab exists.
    function ensureOneActiveTab(tabs) {
        if (tabs.length > 0 && !tabs.some(tab => tab.active)) {
            tabs[0] = Object.assign({}, tabs[0]);
            tabs[0].active = true;
        }
        return tabs;
    }

    function pGetWindowIdsToRemove(isReplacingWindows) {
        return isReplacingWindows ? pGetAllBrowserWindowIds() : Promise.resolve([]);
    }

    function pGetAllBrowserWindowIds() {
        return browser.windows.getAll({}).then( windows => windows.map(w => w.id) );
    }

    function windCreateInfo(win) {
        let createInfo = {
            state:      win.state,
            type:       win.type,
            url:        "about:blank",  // the first dummy tab
        };
        // Only "normal" window state has dimension.  For the other states, let the browser decide.
        if (win.state == "normal") {
            createInfo.left     = win.left;
            createInfo.top      = win.top;
            createInfo.width    = win.width;
            createInfo.height   = win.height;
        }
        return createInfo;
    }

    // Fill the targetWindow and tidsToRemove fields of windRestoreInfos.
    function pCreateTargetWindows(windRestoreInfos, isCurrentWinTarget, isReplace) {
        // log.info("pCreateTargetWindows isCurrentWinTarget: " + isCurrentWinTarget + ",  isReplace: " + isReplace);
        if (isCurrentWinTarget) {
            return browser.windows.getCurrent({populate: true}).then( currentWindow => {
                let info = windRestoreInfos[0];
                info.targetWindow = currentWindow,
                info.existingTabCount = currentWindow.tabs.length;
                info.tidsToRemove = isReplace ? currentWindow.tabs.map( tab => tab.id ) : [];   // tabs of the current window will all be removed.
            });
        } else {
            return Promise.all( windRestoreInfos.map( info => {
                return browser.windows.create(windCreateInfo(info.originalWindow)).then( newWindow => {
                    info.targetWindow = newWindow;
                    info.existingTabCount = newWindow.tabs.length;
                    info.tidsToRemove = [ newWindow.tabs[0].id ];                               // the first dummy tab will be removed.
                })
            } ));
        }
    }

    function pPostCreateOnWindows(windRestoreInfos) {
        // Currently the only post-create op is pSetWindowTitlePreface().
        return Promise.all( windRestoreInfos.map(pSetWindowTitlePreface) )
    }

    function pSetWindowTitlePreface(info) {
        let preface = info.originalWindow._name;
        preface = preface ? "[" + preface + "] " : "";      // Clear the titlePreface if preface is empty.
        return browser.windows.update(info.targetWindow.id, { titlePreface: preface });
    }

    function parseTitlePreface(title) {
        title = title || "";
        let loffset = title.indexOf("[");
        let roffset = title.indexOf("]");
        if (loffset > -1 && roffset > -1 && loffset < roffset && title.trim()[0] == '[') {
            let preface = title.substring(loffset + 1, roffset).trim();
            return {
                preface: preface,
                loffset: loffset,
                roffset: roffset,
            }
        }
    }

    function pFocusRestoringWindow(windRestoreInfos, partOfAGroup) {
        let index = 0;      // default to focus on the first window, for single target restoration.
        if (partOfAGroup) {
            index = windRestoreInfos.findIndex( info => info.originalWindow.focused );          // restore the original focused window.
        }
        if (windRestoreInfos.length == 0 || index < 0)
            return Promise.resolve();
        else
            return browser.windows.update(windRestoreInfos[index].targetWindow.id, { focused: true });
    }

    function pRestoreWinTabs(windRestoreInfo, gCtx, cids, tabMappings) {
        let targetWid = windRestoreInfo.targetWindow.id;
        let restoringTabs = windRestoreInfo.originalTabs;
        let createParamList = restoringTabs.map( (originalTab, index) => ({
            windowId:           targetWid,
            active:             originalTab.active,
            pinned:             originalTab.pinned,
            cookieStoreId:      cids.has(originalTab.cookieStoreId) ? originalTab.cookieStoreId : container.CT_FIREFOX_DEFAULT,
            url:                resolveReaderModeUrl(originalTab.url),
            openInReaderMode:   originalTab.openInReaderMode || isReaderModeUrl(originalTab.url),
            index:              windRestoreInfo.existingTabCount + index,       // force ordering by index in case the timing of the promise calls are off.
        }) );
        let newTabs = [];
        let p = Promise.resolve();
        restoringTabs.forEach( (tab, index) => {
            p = p.then(() => pRestoreTabInWindow(tab, createParamList[index], targetWid, gCtx, tabMappings)
                       .then( t => newTabs.push(t) ));
        });
        return p.then(() => windRestoreInfo.newTabs = newTabs.filter(Boolean)); // filter out null tabs from restore error.
    }

    function setupDiscarded(createParams) {
        // Active, reader-mode, or pinned tab cannot be restored with discarded flag set.
        return createParams.active || createParams.openInReaderMode || createParams.pinned ? false : true;
    }

    async function pRestoreTabInWindow(originalTab, createParams, windowId, gCtx, tabMappings) {
        // log.info("pRestoreTabInWindow, originalTab.url: " + originalTab.url);
        let canDiscarded = Number(gCtx.majorVersion) >= 63; // Firefox 63+ supports setting the discarded flag.
        let newTab;
        if (!settings.ofCurrent.lazyTabLoadingOnRestore || !canDiscarded) {
            // restore as fully loaded tabs.
            newTab = await browser.tabs.create(createParams).catch( e => {
                return pCreateErrorTab(createParams, originalTab.title, e);
            });
        } else {
            // restore as lazily loaded with discarded; setting title is only allowed on a discarded tab.
            createParams.discarded  = setupDiscarded(createParams);
            createParams.title      = createParams.discarded ? originalTab.title : null;
            newTab = await browser.tabs.create(createParams).catch( e => {
                log.warn(e);
                return pCreateErrorTab(createParams, originalTab.title, e);
            });
        }

        if (newTab)
            updateMappingWithNewTab(tabMappings, originalTab, newTab);
        return newTab;
    }

    function pCreateErrorTab(createParams, title, error) {
        log.error("pCreateErrorTab", error);
        let url = ERROR_PAGE_URL +
            "?url="   + encodeURIComponent(createParams.url) +
            "&error=" + encodeURIComponent(error.message) +
            "&title=" + encodeURIComponent(title);
        if (!error.message.startsWith("Illegal URL:")) {
            url = url + "&explain=Unable%20to%20restore%20tab";
        }
        let errorParams = {
            url:            url,
            windowId:       createParams.windowId,
        };
        return browser.tabs.create(errorParams)
            .catch( e => {
                log.error("browser.tabs.create() in pCreateErrorTab(). ", e);
                log.error(errorParams);
            });
    }

    function updateMappingWithNewTab(tabMappings, originalTab, newTab) {
        // Tracking the mapping of original tab and new tab.
        tabMappings.newTidToOriginalTab[newTab.id] = originalTab;
        tabMappings.originalTidToNewTab[originalTab.id] = newTab;
    }

    function pUpdateOpenerTabIds(newTabs, tabMappings) {
        log.info("pUpdateOpenerTabIds", tabMappings);
        let updates = newTabs.map( newTab => {
            let orginalTab      = tabMappings.newTidToOriginalTab[newTab.id];
            let orgOpenerTid    = orginalTab.openerTabId;
            let newOpenerTab    = tabMappings.originalTidToNewTab[orgOpenerTid];
            if (newOpenerTab) {
                return browser.tabs.update(newTab.id, { openerTabId: newOpenerTab.id }).catch(e => {
                    // FireFox older than version 57 doesn't support setting openerTabId.
                    console.warn(e.message);
                });
            } else {
                return Promise.resolve();
            }
        });
        return updates;
    }

    function pRemoveOldTabs(windRestoreInfo) {
        // Only remove old tabs on the target window if there are new tabs restored; otherwise, the window is closed unexpectedly.
        if (windRestoreInfo.newTabs.length > 0)
            return browser.tabs.remove(windRestoreInfo.tidsToRemove);
        else
            return Promise.resolve();
    }

    function pRemoveWindows(windowIds) {
        //log.info("pRemoveWindows ", windowIds);
        return Promise.all( windowIds.map( wid => browser.windows.remove(wid) ) )
    }

    function mapUrl(url) {
        return url == "about:newtab" ? "about:blank" : url;
    }

    const READER_MODE_PREFIX = "about:reader?url=";
    function isReaderModeUrl(url)       { return url.indexOf(READER_MODE_PREFIX) == 0 }
    function getReaderModeUrl(url)      { return decodeURIComponent(url.substr(READER_MODE_PREFIX.length)) }
    function resolveReaderModeUrl(url)  { return isReaderModeUrl(url) ? getReaderModeUrl(url) : url }

    // Module exports 
    module.USER = USER;
    module.SCHEDULED = SCHEDULED;
    module.ONCHANGE = ONCHANGE;
    module.AS_ALL = AS_ALL;
    module.AS_WIN = AS_WIN;
    module.GROUP_ONCHANGE = GROUP_ONCHANGE;
    module.Session = Session;
    module.pSnapshotSession = pSnapshotSession;
    module.filterSessions = filterSessions;
    module.filterTabs = filterTabs;
    module.pRestoreTabFavIcons = pRestoreTabFavIcons;
    module.pRestoreTabFavIcon = pRestoreTabFavIcon;
    module.normalizeWindow = normalizeWindow;
    module.normalizeTab = normalizeTab;
    
    
    return module;

}(this, "session"));    // Pass in the global scope as 'this' scope.

