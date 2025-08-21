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
    let exportUrl = browser.runtime.getURL("popup/boss_export.html");
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

        $("#global-cmds").on("click", ".cmd-close-ui",      function(){ sendCmd({ cmd: "close-tab", tabId: currentTabId }) });
        $("#global-cmds").on("click", ".cmd-fullpage-ui",   function(){ sendCmd({ cmd: "activate-ui" }); sendCmd({ cmd: "close-tab", tabId: currentTabId }) });
        $("#global-cmds").on("click", ".cmd-about",         function(){ $("about-dlg")[0].open = browser.runtime.getManifest() });
        $("#main-content").on("click", ".cmd-export-file",  exportToFile);
        $("#main-content").on("click", ".cmd-export-text",  exportToText);
        $("#main-content").on("click", ".cmd-clear-text",   function(){
            $("#export-text").val("");
            $("#export-text-pane").addClass("d-invisible");
            $("#export-status-pane").hide();
            $("#export-status").text("");
        });
    }

    function exportToFile(e) {
        let exportType = $("input:radio[name=stype]:checked").val() || "all-sessions";
        sendCmd({  cmd: "export-data",  exportType: exportType  });
    }

    function exportToText(e) {
        let exportType = $("input:radio[name=stype]:checked").val() || "all-sessions";
        $("#export-status-pane").hide();
        Sessions.pLoadAllSessionsData()
            .then( sessionsData => dataio.pGenerateExportData(sessionsData, exportType) )
            .then( exportObj => {
                $("#export-text-pane").removeClass("d-invisible");
                $("#export-text").val(JSON.stringify(exportObj, null, 4) + "\n");
                $("#export-text").focus().select();
            })
            .catch(e => {
                $("#export-status-pane").show();
                $("#export-status").text(e);
            });
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
            if (app.has(storageChange, "cmdLogStore")) {
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
        case "export-data":
            $("popup-msg")[0].open = "Export data '" + lastCmdMsg.pendingResult.filename + "' done";
            break;
        default:
            break;
        }
        lastCmdMsg = {};
    }
    
    function setCssVar(cssVar, value) {
        $("html").css(cssVar, value);
    }

    return module;

}(this, "export_panel"));    // Pass in the global scope as 'this' scope.


