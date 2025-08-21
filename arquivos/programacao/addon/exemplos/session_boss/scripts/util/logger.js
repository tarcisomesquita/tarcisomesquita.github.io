/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// logger module, for lightweight logging.
// With prefix on app name and module name for easier filtering when viewing the log.
(function(scope, modulename) {
    "use strict";

    var logger = function() { };       // Module object to be returned; local reference to the package object for use below.
    if (modulename)
        scope[modulename] = logger;    // set module name in scope, otherwise caller sets the name with the returned module object.

    // No import.  No dependency.

    // Log levels
    const NONE = 0;
    const ERROR = 1;
    const WARN = 2;
    const INFO = 3;
    const LOG = 4;      // this is the finest logging level, like debug.

    const LEVELS = [NONE, ERROR, WARN, INFO, LOG];
    const LEVEL_NAMES = ["NONE", "ERROR", "WARN", "INFO", "LOG"];


    class Logger {
        constructor(app, module, level) {
            this._app = app;
            this._module = module;
            this._levelFn = (typeof level === "function") ? level : () => level;
            this._tagtime = {};                 // benchmark tagged times
            this._tagtime[""] = Date.now();     // set up the default empty benchmark tag.
        }

        get app()       { return this._app              }
        get module()    { return this._module           }
        get level()     { return this._levelFn()        }
        get _logNone()  { return this.level == NONE     }
        get _logError() { return this.level >= ERROR    }
        get _logWarn()  { return this.level >= WARN     }
        get _logInfo()  { return this.level >= INFO     }
        get _logLog()   { return this.level >= LOG      }

        error(...a)     { if (this._logError) console.error(this._fmt(a))   };
        warn(...a)      { if (this._logWarn)  console.warn(this._fmt(a))    };
        info(...a)      { if (this._logInfo)  console.info(this._fmt(a))    };
        log(...a)       { if (this._logLog)   console.log(this._fmt(a))     };
        out(...a)       { console.log(this._fmt(a))                         };
        dump()          { return this._fmtarr(Array.prototype.slice.call(arguments)) }  // dump the arguments to string/json
        bench(msg)      { this.tagTime("", msg) }                                       // benchmark on the default empty tag
        tagOn(tag, msg) {                                                               // start benchmark on the tag, reset timer.
            delete this._tagtime[tag];
            this.tagTime(tag, msg);
        }
        tagTime(tag, msg) {                                                             // benchmark on the tag, report lapsed time, and update tag timer.
            let now  = Date.now();
            let last = this._tagtime[tag] || now;
            this._tagtime[""] = this._tagtime[tag] = now;                               // update time on the tag and the default empty tag.
            if (this._logInfo)
                console.log( this._prefix() + " - " + tag + " " + (now - last) + "ms - " + msg );
        }

        // With prefix on app name and module name for easier filtering when viewing the log.
        _prefix()       { return this.app + ":" + this.module };
        _fmt(a)         { return this._prefix() + " - " + this._fmtarr(a) }
        _fmtarr(a)      { return !a || !a.length ? "" : a.length == 1 ? this._fmtobj(a[0]) : "[" + [].map.call(a, o => this._fmtobj(o) + "\r\n").join(", ") + "]" }
        _fmtobj(obj)    { return this._json(obj instanceof Error ? this._fromerr(obj) : obj) }
        _fromerr(e)     { return {error: e.name, msg: e.message, file: e.fileName || "", line: e.lineNumber || "", stack: e.stack ? e.stack.split("\n") : "" } }
        _json(obj)      { return JSON.stringify(obj, null, 4) };
    }


    // Module export
    logger.NONE = NONE;
    logger.ERROR = ERROR;
    logger.WARN = WARN;
    logger.INFO = INFO;
    logger.LOG = LOG;
    logger.LEVELS = LEVELS;
    logger.LEVEL_NAMES = LEVEL_NAMES;
    logger.Logger = Logger;
    return logger;

}(this, "logger"));    // Pass in the global scope as 'this' scope.


// Unit Tests
let _RUNTEST_LOGGER = false;
if (_RUNTEST_LOGGER) {
    console.log("Run unit tests");

    let none = new logger.Logger("LoggerTests", "TestNone", logger.NONE);
    none.error("none not shown");
    none.warn("warn not shown");
    none.info("info not shown");
    none.log("log not shown");

    let error = new logger.Logger("LoggerTests", "TestError", logger.ERROR);
    error.error("error shown");
    error.warn("warn not shown");
    error.info("info not shown");
    error.log("log not shown");

    let warn = new logger.Logger("LoggerTests", "TestWarn", logger.WARN);
    warn.error("error shown");
    warn.warn("warn shown");
    warn.info("info not shown");
    warn.log("log not shown");

    let info = new logger.Logger("LoggerTests", "TestInfo", logger.INFO);
    info.error("error shown");
    info.warn("warn shown");
    info.info("info shown");
    info.log("log not shown");

    let log = new logger.Logger("LoggerTests", "TestLog", logger.LOG);
    log.error("error shown");
    log.warn("warn shown");
    log.info("info shown");
    log.log("log shown");

    let logFn = new logger.Logger("LoggerTests", "TestLog", () => logger.LOG);
    logFn.error("error shown");
    logFn.warn("warn shown");
    logFn.info("info shown");
    logFn.log("again log shown");

    console.log(log.dump(1, 2, 3));
    console.log(log.dump({ foo: 'a', bar: 'b', baz: [1, 2, 3] }));

}

