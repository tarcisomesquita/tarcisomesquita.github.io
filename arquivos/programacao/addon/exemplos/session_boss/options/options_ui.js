/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// Options module

(function(scope, modulename) {
    "use strict";

    // Imports:
    // import logger
    // import appcfg
    // import app
    // import settings

    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    var module = function() { };    // Module object to be returned; local reference to the package object for use below.
    if (modulename)
        scope[modulename] = module; // set module name in scope, otherwise caller sets the name with the returned module object.

    let orgSettings = settings.ofLatest();
    let curSettings  = settings.ofLatest();
    let hasChanged  = false;

    // Firefox's Content Security Policy for WebExtensions prohibits running any Javascript in the html page.
    // Wait for the page loaded event before doing anything.
    window.addEventListener("load", function(event){
        // Page is loaded and ready for the script to run.
        Promise.resolve()
            .then(() => settings.pLoadCurrent())
            .then(() => appcfg.initLogLevel())
            .then(() => log.info("Page initialization starts") )
            .then(() => settings.pLoad().then( s => orgSettings = s ))
            .then(s  => curSettings = Object.assign({}, s))
            .then(() => setupOptionUI())
            .then(() => setupDOMListeners())
            .then(() => refreshControls())
            .then(() => refreshSettings())
            .then(() => activateTab("tab-general"))
            .then(() => log.info("Page initialization done") )
            .catch( e => log.warn(e) )
    });

    function refreshControls() {
        if (hasChanged) {
            $("#saveChanges").removeClass("disabled");
            $("#undoChanges").removeClass("disabled");
        } else {
            $("#saveChanges").addClass("disabled");
            $("#undoChanges").addClass("disabled");
        }
    }

    function updateChanges() {
        hasChanged = true;
        refreshControls();
    }

    function refreshSettings() {
        $("#autoRestoreOnStartup").prop("checked", curSettings.autoRestoreOnStartup);
        $("#autoRestoreTimeLimit").val(curSettings.autoRestoreTimeLimit);
        $("#lazyTabLoadingOnRestore").prop("checked", curSettings.lazyTabLoadingOnRestore);
        $("#enableScheduleBackup").prop("checked", curSettings.enableScheduleBackup);
        $("#enableOnChangeBackup").prop("checked", curSettings.enableOnChangeBackup);
        $("#restoreActionOnStartup").val(curSettings.restoreActionOnStartup);
        $("#launchToFullPage").prop("checked", curSettings.launchToFullPage);
        $("#maxUserSessions").val(curSettings.maxUserSessions);
        $("#maxOnchangeSession").val(curSettings.maxOnchangeSession);
        $("#includePrivateWindows").prop("checked", curSettings.includePrivateWindows);
        $("#loggingLevel").val(curSettings.loggingLevel);

        $(".is-error").removeClass("is-error");
    }

    function setupOptionUI() {
        let $select;

        $select = $("#restoreActionOnStartup");
        settings.RESTORE_ACTIONS.forEach( action => $select.append($("<option>", { value: action.value }).text(action.text)) );

        $select = $("#loggingLevel");
        logger.LEVELS.forEach( (level, i) => $select.append($("<option>", { value: level }).text(logger.LEVEL_NAMES[i])) );
    }

    function setupDOMListeners() {
        // Handle click on the tabs.
        $("ul.tab li.tab-item").click(function(){
		    let tabid = $(this).data("tabid");
		    $(this).addClass("active").siblings().removeClass("active");
            $(".tab-body#" + tabid).show().siblings().hide();
        })

        // Input handlers
        checkedHandler("autoRestoreOnStartup");
        checkedHandler("lazyTabLoadingOnRestore");
        checkedHandler("enableScheduleBackup");
        checkedHandler("enableOnChangeBackup");
        checkedHandler("launchToFullPage");
        checkedHandler("includePrivateWindows");
        textHandler("autoRestoreTimeLimit", 5, 60);
        textHandler("maxUserSessions",
                    appcfg.MAX_USER_SESSION_LO_LIMIT,
                    appcfg.MAX_USER_SESSION_HI_LIMIT);
        textHandler("maxOnchangeSession",
                    appcfg.MAX_ONCHANGE_SESSION_LO_LIMIT,
                    appcfg.MAX_ONCHANGE_SESSION_HI_LIMIT);
        valHandler("restoreActionOnStartup");
        valHandler("loggingLevel");

        // On change handlers.
        $("#maxUserSessions").on("change", function(){
            if (curSettings["maxUserSessions"] < orgSettings["maxUserSessions"])
                $("popup-msg").prop("delay", 10)[0].open = "Setting Max User Sessions to be less than the original will remove the oldest extra sessions.";
        });
        $("#maxOnchangeSession").on("change", function(){
            if (curSettings["maxOnchangeSession"] < orgSettings["maxOnchangeSession"])
                $("popup-msg").prop("delay", 10)[0].open = "Setting Max On-Change Sessions to be less than the original will remove the oldest extra sessions.";
        });

        // Button handlers
        $("#saveChanges").on("click",                   function(){ settings.pSave(curSettings).then(() => postSaving(orgSettings, curSettings) ) });
        $("#undoChanges").on("click",                   function(){ settings.pSave(orgSettings).then(() => postSaving(curSettings, orgSettings)) });
        $("#resetToDefault").on("click",                function(){
            curSettings = settings.ofLatest();
            refreshSettings();
            updateChanges();
        });

        $("form#tab-general").on("keyup keypress", function(e){
            if ((e.keyCode || e.which) === 13) {    // disable form submit on Enter
                e.preventDefault();
                return false;
            }
        });        
    }

    function checkedHandler(property) {
        $("#" + property).on("change", function(){
            curSettings[property] = this.checked;
            updateChanges();
        });
    }

    function valHandler(property) {
        $("#" + property).on("change", function(){
            curSettings[property] = $(this).val();
            updateChanges();
        });
    }

    function textHandler(property, minVal, maxVal) {
        $("#" + property).on("change", function(){
            curSettings[property] = Math.max(Math.min($(this).val(), maxVal), minVal);
            $(this).val(curSettings[property]);
            updateChanges();
        });
    }


    function activateTab(tabid) {
        $("ul.tab li.tab-item[data-tabid='" + tabid + "']").addClass("active").siblings().removeClass("active");
        $(".tab-body#" + tabid).show().siblings().hide();
    }

    function postSaving(oldSettings, newSettings) {
        orgSettings = Object.assign({}, newSettings);
        curSettings = Object.assign({}, newSettings);
        hasChanged = false;
        refreshControls();
        refreshSettings();
    }

    function stopEvent(e) {
        e.preventDefault();
        return false;
    }

    
    return module;

}(this, "options_ui"));     // Pass in the global scope as 'this' scope.

