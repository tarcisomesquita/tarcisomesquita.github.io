/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// appcfg module, app global constants and settings.
(function(scope, modulename) {
    "use strict";

    // Imports:
    // import logger
    let Logger = logger.Logger;

    let module = function() { };
    if (scope && modulename)
        scope[modulename] = module;

    const APPNAME = "sessionboss";
    const APPTITLE = "Session Boss";
    let logLevel = logger.LOG;
    //let logLevel = logger.WARN;

    let log = new Logger(APPNAME, modulename, logLevel);

    function getLogLevel()  { return logLevel }
    function initLogLevel() {
        logLevel = settings.ofCurrent.loggingLevel;
        log.out("Current loging level: " + logger.LEVEL_NAMES[module.LOGLEVEL()]);
    }

    // Module export
    module.APPNAME = APPNAME;
    module.APPTITLE = APPTITLE;
    module.LOGLEVEL = getLogLevel;
    module.initLogLevel = initLogLevel;

    module.MAX_USER_SESSION = 20;       // default initial max.
    module.MAX_USER_SESSION_LO_LIMIT = 10;
    module.MAX_USER_SESSION_HI_LIMIT = 300;
    module.MAX_ONCHANGE_SESSION = 8;    // default initial max; onchange data is saved every 15 seconds, so at worst 8 sessions save 2 minutes of changes.
    module.MAX_ONCHANGE_SESSION_LO_LIMIT = 5;
    module.MAX_ONCHANGE_SESSION_HI_LIMIT = 99;
    module.MAX_SNAPSHOTS = 50;
    module.SNAPSHOT_BASE = "snapshot";
    module.APP_ID = "sessionboss";      // for import and export data format

    return module;

}(this, "appcfg"));      // Pass in the global scope as 'this' scope.

