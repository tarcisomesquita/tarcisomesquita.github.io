/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// Setting module
(function(scope, modulename) {
    "use strict";

    // Imports:
    // import logger
    // import appcfg
    // import appcfg

    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    let module = function() { };        // Module object to be returned.
    if (scope && modulename)
        scope[modulename] = module;     // set module name in scope, otherwise caller sets the name with the returned module object.

    const TYPE_NAME = "SessionBossSettings";
    const STORAGE_NAME = "sessionBossSettings";

    const RESTORE_ACTION_NO_ACTION      = "NO_ACTION";
    const RESTORE_ACTION_USER_SELECTED  = "USER_SELECTED"; 
    const RESTORE_ACTION_LAST_SCHEDULED = "LAST_SCHEDULED";
    const RESTORE_ACTION_LAST_ON_CHANGE = "LAST_ON_CHANGE";
    const RESTORE_ACTIONS = [
        { value: RESTORE_ACTION_NO_ACTION,      text: "No Action" },
        { value: RESTORE_ACTION_USER_SELECTED,  text: "Restore the selected Auto-Restore session" },
        { value: RESTORE_ACTION_LAST_SCHEDULED, text: "Restore the last Scheduled backup session" },
        { value: RESTORE_ACTION_LAST_ON_CHANGE, text: "Restore the last On-Change backup session" },
    ];
    const RESTORE_ACTION_DEFAULT = RESTORE_ACTION_USER_SELECTED;

    class Setting {
        constructor(json) {
            this._type = TYPE_NAME;
            
            this._version = 1;
            this.lazyTabLoadingOnRestore    = defVal(json, "lazyTabLoadingOnRestore", true);
            this.autoRestoreOnStartup       = defVal(json, "autoRestoreOnStartup", true);       // deprecated
            this.enableScheduleBackup       = defVal(json, "enableScheduleBackup", true);
            this.enableOnChangeBackup       = defVal(json, "enableOnChangeBackup", true);
            
            this._version = 2;
            this.autoRestoreTimeLimit       = defVal(json, "autoRestoreTimeLimit", 20);         // deprecated
            
            this._version = 3;
            this.restoreActionOnStartup     = defVal(json, "restoreActionOnStartup", RESTORE_ACTION_DEFAULT);
            this.launchToFullPage           = defVal(json, "launchToFullPage", false);
            this.maxUserSessions            = defVal(json, "maxUserSessions", appcfg.MAX_USER_SESSION);
            this.maxOnchangeSession         = defVal(json, "maxOnchangeSession", appcfg.MAX_ONCHANGE_SESSION);

            this._version = 4;
            this.includePrivateWindows      = defVal(json, "includePrivateWindows", false);  // default to not saving private browsing windows for better privacy protection.

            this._version = 5;
            this.loggingLevel               = defVal(json, "loggingLevel", logger.WARN);
        }
    }

    function defVal(json, field, defaultVal) { return json && json.hasOwnProperty(field) ? json[field] : defaultVal };
    function ofLatest(json) { return new Setting(json)  }   // Get the latest version with default settings, or upgrade to latest version if json is given.

    function pLoad() {
        return browser.storage.local.get(STORAGE_NAME)
            .then( store => store ? ofLatest(store[STORAGE_NAME]) : ofLatest() )
            .catch( e => { log.warn(e); return ofLatest() })
    }
    function pSave(settingsObj)     { return browser.storage.local.set({ [STORAGE_NAME]: settingsObj }) };
    function pRemove()              { return browser.storage.local.remove(STORAGE_NAME)                 };
    function pUpdate(name, value)   { return pLoad().then(obj => { obj[name] = value; return obj }).then(pSave) };

    // Global module level singleton setting
    function pLoadCurrent()         { return pLoad().then( theSetting => module.ofCurrent = theSetting ) }

    // Module export

    module.RESTORE_ACTION_NO_ACTION = RESTORE_ACTION_NO_ACTION;
    module.RESTORE_ACTION_USER_SELECTED = RESTORE_ACTION_USER_SELECTED;
    module.RESTORE_ACTION_LAST_SCHEDULED = RESTORE_ACTION_LAST_SCHEDULED;
    module.RESTORE_ACTION_LAST_ON_CHANGE = RESTORE_ACTION_LAST_ON_CHANGE;
    module.RESTORE_ACTIONS = RESTORE_ACTIONS;
    module.RESTORE_ACTION_DEFAULT = RESTORE_ACTION_DEFAULT;

    module.TYPE_NAME = TYPE_NAME;
    module.STORAGE_NAME = STORAGE_NAME;
    module.ofLatest = ofLatest;
    module.pLoad = pLoad;
    module.pSave = pSave;
    module.pRemove = pRemove;
    module.pUpdate = pUpdate;
    module.ofCurrent = ofLatest();          // starts with default settings; pLoadCurrent() updates it.
    module.pLoadCurrent = pLoadCurrent;

    
    return module;

}(this, "settings"));   // Pass in the global scope as 'this' scope.

