/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

(function(scope, modulename) {
    "use strict";

    // Imports:
    // import logger
    // import appcfg
    // import app
    // import dlg
    // import container
    // import session
    // import sessiongroup
    // import sessions
    // import dataio
    let Session  = session.Session;
    let Sessions = sessions.Sessions;

    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    var module = function() { };    // Module object to be returned; local reference to the package object for use below.
    if (modulename)
        scope[modulename] = module; // set module name in scope, otherwise caller sets the name with the returned module object.

    let lastCmdMsg = {};
    let currentTabId;
    let uiUrl = browser.runtime.getURL("popup/boss_popup.html");
    let importUrl = browser.runtime.getURL("popup/boss_import.html");
    let pendingResult;

    window.addEventListener("load", function(event){
        Promise.resolve()
            .then(() => settings.pLoadCurrent())
            .then(() => appcfg.initLogLevel())
            .then(() => log.tagOn("init", "### Initialization starts. ###") )
            .then(() => browser.tabs.getCurrent().then( tab => currentTabId = tab.id ) )
            .then(() => pMonitorSessionDataChange())
            .then(() => setupDOMListeners())
            .then(() => log.tagTime("init", "*** Initialization done ***") )
            .catch( e => log.warn(e) )
    });

    function setupDOMListeners() {
        log.info("setupDOMListeners");

        // Global menu at the top navbar
        $("#global-cmds").on("click", ".cmd-close-ui",      function(){
            sendCmd({ cmd: "close-tab", tabId: currentTabId })
        });

        $("#global-cmds").on("click", ".cmd-fullpage-ui",   function(){
            sendCmd({ cmd: "activate-ui" });
            sendCmd({ cmd: "close-tab", tabId: currentTabId });
        });

        $("#global-cmds").on("click", ".cmd-about",         function(){ $("about-dlg")[0].open = browser.runtime.getManifest() });

        function findSessionFromDataSid($elem) {
            let sid = $elem.closest(".import-item").data("sid");
            return findSessionInResult(sid);
        }

        $("#main-content .import-file-input").on("change",  function(){
            let files = Array.from($(this).get(0).files);
            let file = files[0];                                    // allow only one file at a time
            let filename = $(this).val().replace(/.*[\/\\]/, '');   // get filename and clean up fakepath shit.
            pendingResult = null;
            dataio.pReadImportFile(file).then( parsed => {
                pendingResult = {
                    parsed:     parsed,
                    filename:   filename,
                };
                $("#import-status-pane").hide();
                $("#import-status").text("");
                $("#import-file-info").text("File loaded.  Found the following " + parsed.type + " data.  " +
                                            (parsed.exportTime ? "Export time was: " + parsed.exportTime : "")).show();
                $("#import-parsed-pane").show();
                switch (parsed.type) {
                case dataio.F_SESSION:          displayImportSessionsResult(parsed.sessLists);          break;
                case dataio.F_SESSIONS:         displayImportSessionsResult(parsed.sessLists);          break;
                case dataio.F_FAVICON_DB:       displayImportFaviconsResult(parsed.favicon_db);         break;
                case dataio.F_CONTAINER_DEF:    displayImportContainersResult(parsed.container_def);    break;
                default:                        $("#import-parsed").html("Unknown data.");              break;
            }
            }).catch(e => {
                $("#import-status-pane").show();
                $("#import-status").text(e.toString());
                $("#import-file-info").text("").hide();
                $("#import-parsed-pane").hide();
                $("#import-parsed").html("");
            });
        });

        $("#import-parsed-pane").on("click", ".cmd-import-merge",   function(){ asyncCmd({ cmd: "import-merge", pendingResult: pendingResult }) });
        $("#import-parsed-pane").on("click", ".cmd-import-replace", function(){
            $("confirm-dlg")[0].open = `This will delete all existing sessions before import from the file.
                                        The deleted Scheduled backups and On-Change backups cannot be undone.  Proceed?`;
            $("confirm-dlg").one("confirm", () => asyncCmd({ cmd: "import-replace", pendingResult: pendingResult }));
        });
        $("#import-parsed-pane").on("click", ".cmd-import-favicon", function(){ asyncCmd({ cmd: "import-favicon",   pendingResult: pendingResult }) });
        $("#import-parsed-pane").on("click", ".cmd-import-cdef",    importContainerDef);
        $("#import-parsed").on("click", ".cmd-import-as-user",      function(){ callCmd({  cmd: "import-as-new",    session: findSessionFromDataSid($(this)) }) });

    }

    function importContainerDef() {
        let cdef = pendingResult.parsed.container_def;
        container.pRecreate(cdef).then( result => $("popup-msg")[0].open = result );
    }

    function sendCmd(msg) {
        lastCmdMsg = msg;
        return browser.runtime.sendMessage(msg);    // response is returned in .then( response => ... ).
    }

    function callCmd(msg) {
        lastCmdMsg = msg;
        return browser.runtime.sendMessage(msg).then( res => {
            if (res)
                $("popup-msg").prop("delay", 5)[0].open = res.message;
        });
    }

    function asyncCmd(msg) {
        lastCmdMsg = msg;
        return browser.runtime.sendMessage(msg).then( res => {
            // Only immediate display error since the command can be long running and the correct result won't be back for a while.
            if (res && res.status != "ok") {
                $("popup-msg").prop("delay", 5)[0].open = res.message;
            }
        });
    }

    function pMonitorSessionDataChange() {
        // Monitor Sessions storage change due to last command to refresh UI.
        return browser.storage.onChanged.addListener(storageChange => {
            let keys = Object.keys(storageChange);
            let hasSnapshot = keys.filter( key => Sessions.startsWithSnapshotName(key) ).length > 0;
            if (app.has(storageChange, "changeLogStore") ||
                hasSnapshot ||
                app.has(storageChange, "backupSessionStore") ||
                app.has(storageChange, "onchangeSessionStore") ||
                app.has(storageChange, "appStateStore")) {
                dRefreshUIForLastCmd();
            } else if (app.has(storageChange, "cmdLogStore")) {
                let cmds = storageChange["cmdLogStore"].newValue.cmds;
                if (cmds.length > 0) {
                    lastCmdMsg.returnCmd = cmds[0];
                    dRefreshUIForLastCmd();
                }
            } else {
                // log.info("storageChange change keys: " + keys.join(", ") + " ignored.");
            }
        });
    }

    function fmtResultStatus(res) {
        return "Status: " + res.status + (res.status == "error" ? "  Message: " + res.message : "");
    }

    let dRefreshUIForLastCmd = app.debounce(refreshUIForLastCmdNow, 250, false);
    function refreshUIForLastCmdNow() {
        // log.info("refreshUIForLastCmdNow " + lastCmd);
        switch (lastCmdMsg.cmd) {
        case "import-merge":
            $("popup-msg")[0].open = "Import and merge '" + lastCmdMsg.pendingResult.filename + "' done";
            break;
        case "import-replace":
            $("popup-msg")[0].open = "Import and replace '" + lastCmdMsg.pendingResult.filename + "' done";
            break;
        case "import-as-new":
            $("popup-msg")[0].open = "Import session '" + lastCmdMsg.session.sessionName + "' done";
            break;
        case "import-favicon":
            $("popup-msg")[0].open = "Import favicon-db '" + lastCmdMsg.pendingResult.filename + "' done.  " + fmtResultStatus(lastCmdMsg.returnCmd.res);
            break;
        default:
            break;
        }
        lastCmdMsg = {};
    }
    
    function setCssVar(cssVar, value) {
        $("html").css(cssVar, value);
    }

    function findSessionInResult(sid) {
        if (!pendingResult)
            return null;
        return [dataio.D_USER_SESSIONS, dataio.D_SCHEDULED_SESSIONS, dataio.D_ONCHANGE_SESSIONS]
            .map( sessionListType => pendingResult.parsed[sessionListType] || [] )
            .flat()
            .map( result => result.session )
            .find( sess => sess.sessionId == sid );
    }

    function displayImportSessionsResult(sessLists) {
        $("#session-import-cmds").show();
        $("#favicon-import-cmds").hide();
        $("#container-import-cmds").hide();
        
        // Cannot trust the imported file's text to render as HTML.  Render template html first, then fill in the imported data as text.
        let templateHtml = [dataio.D_USER_SESSIONS, dataio.D_SCHEDULED_SESSIONS, dataio.D_ONCHANGE_SESSIONS]
            .map( exportDataType => renderImportSessionList(exportDataType, sessLists[exportDataType]) ).join("");
        $("#import-parsed").html(templateHtml);

        // Fill in untrusted data as text.
        [dataio.D_USER_SESSIONS, dataio.D_SCHEDULED_SESSIONS, dataio.D_ONCHANGE_SESSIONS]
            .forEach( exportDataType => fillImportSessionList(exportDataType, sessLists[exportDataType]) );
    }

    // HTML rendered should not have unsafe text.
    function renderImportSessionList(exportDataType, listRes) {
        return `
            <div class="mt-1 mb-3">
              <div class="bold title" style="font-size:110%;">${exportDataType}
                <span style="cursor: default; font-size:70%;" title="Session type of the following sessions">&#9432;</span>
              </div>
              <div style="padding: 0.2rem 0.4rem 0.2rem 0.6rem">
                ${ listRes.length > 0 ? listRes.map( (sessRes, index) => renderImportSessionResult(exportDataType, sessRes, index) ).join("") 
                                      : "<div class='text-gray'>none</div>" }
              </div>
            </div>
        `;
    }

    // The imported session data in res.session is treated as untrusted and not rendered.
    function renderImportSessionResult(exportDataType, res, index) {
        return `
            <div id="${app.formatId(exportDataType)}-${index}" data-sid="PLACEHOLER"
                 class="import-item flex-flow-horizontal flex-center-v" style="padding: .1rem 0; border-bottom: .05rem dotted #b7b9bd;" >
              <div class="sessionName" title="Session name">PLACEHOLER</div>
              <div class="label label-${res.status} dptr mx-4 label-small ${res.status == 'success' ? 'hidden' : ''} " title="${res.msg}">${res.status}</div>
              <div class="flex-flow-child-max"></div>
              <div class="ml-2">
                <button class="cmd-import-as-user btn btn-lv4 mw8 mr-0 ${res.status == 'error' ? 'disabled' : ''}"
                        title="Import this session as a new user session">Import as New User</button>
              </div>
            </div>
        `;
    }

    function fillImportSessionList(exportDataType, listRes) {
        listRes.forEach( (sessRes, index) => fillImportSessionResult(exportDataType, sessRes, index) );
    }

    function fillImportSessionResult(exportDataType, res, index) {
        let $item = $("#" + app.formatId(exportDataType) + "-" + index);
        $item.data("sid", res.session.sessionId);
        $item.find(".sessionName").text(res.session.sessionName);
    }

    function displayImportFaviconsResult(db) {
        $("#session-import-cmds").hide();
        $("#favicon-import-cmds").show();
        $("#container-import-cmds").hide();

        // Cannot trust the imported file's text to render as HTML.  Render template html first, then fill in the imported data as attrs.
        $("#import-parsed").html(renderImportFaviconList(db));
        fillImportFaviconList(db);
    }

    function renderImportFaviconList(db) {
        return `
            <div>
              <span>${db["faviconImage"].length} favicon images and ${db["faviconTabUrl"].length + db["faviconLastUse"].length} other data items found.</span>
            </div>
            <div class="my-2">
              ${ db["faviconImage"].map( (fav, index) => `<img id="fav-${index}" class="import-fav-img">` ).join("") }
            </div>
        `;
    }

    function fillImportFaviconList(db) {
        db["faviconImage"].forEach( (fav, index) => {
            $("#fav-" + index).attr("src", fav.image);
        });
    }

    function displayImportContainersResult(container_def) {
        $("#session-import-cmds").hide();
        $("#favicon-import-cmds").hide();
        $("#container-import-cmds").show();

        // Cannot trust the imported file's text to render as HTML.  Render template html first, then fill in the imported data as attrs.
        $("#import-parsed").html(renderImportContainers(container_def));
        fillImportContainers(container_def);
    }

    function renderImportContainers(container_def) {
        return `
            <div>
              <span>${container_def.length} containers found.</span>
            </div>
            <div class="my-2">
              <table class="table table-striped">
                <tr> 
                  <th>Cookie Store Id</th> <th>Name</th> <th>Color Code</th> <th>Icon URL</th> <th>Icon Image</th>
                </tr>
              ${ container_def.map( (cdef, index) => `
                <tr id="cdef-${index}">
                  <td></td>                <td></td>     <td></td>           <td></td>         <td><img class="tab-container-icon"></img></td>
                </tr>
              ` ).join("")
              }
              </table>
            </div>
        `;
    }

    function fillImportContainers(container_def) {
        container_def.map( (cdef, index) => {
            $("#cdef-" + index + " td:nth-child(1)").text(cdef.cookieStoreId);
            $("#cdef-" + index + " td:nth-child(2)").text(cdef.name);
            $("#cdef-" + index + " td:nth-child(3)").text(cdef.colorCode);
            $("#cdef-" + index + " td:nth-child(4)").text(cdef.iconUrl);
            $("#cdef-" + index + " td:nth-child(5) img").attr("src", cdef.iconUrl);
            $("#cdef-" + index + " td").filter(":nth-child(2), :nth-child(3)").css("color", cdef.colorCode);
        });
    }

    return module;

}(this, "import_panel"));    // Pass in the global scope as 'this' scope.


