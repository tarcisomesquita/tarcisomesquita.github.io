/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/


// module dataio, import and export utils
(function(scope, modulename) {
    "use strict";

    // Import:
    // import logger
    // import appcfg
    // import app
    // import db
    // import container
    // import settings
    // import session
    // import sessions
    let Session  = session.Session;
    let Sessions = sessions.Sessions;

    // Export data types
    const D_ALL_SESSIONS        = "all-sessions";
    const D_USER_SESSIONS       = "user-sessions";
    const D_SCHEDULED_SESSIONS  = "scheduled-sessions";
    const D_ONCHANGE_SESSIONS   = "onchange-sessions";
    const D_FAVICON_DB          = "favicon-db";
    const D_CONTAINER_DEF       = "container-def";

    // Export file types
    const F_SESSION             = "Session";
    const F_SESSIONS            = "Sessions";
    const F_FAVICON_DB          = "favicon-db";
    const F_CONTAINER_DEF       = "container-def";


    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);
 
    var module = function() { };       // Module object to be returned.
    if (scope && modulename)
        scope[modulename] = module;    // set module name in scope, otherwise caller sets the name with the returned module object.


    // Module public functions

    function pGenerateExportData(sessionsData, exportType) {
        switch (exportType) {
        case D_ALL_SESSIONS: {
            let exportObj = prepExportObj(F_SESSIONS);
            exportObj[D_USER_SESSIONS]      = sessionsData.userSessions.map( sess => toSessionExportObj(sess) );
            exportObj[D_SCHEDULED_SESSIONS] = sessionsData.scheduledSessions.map( sess => toSessionExportObj(sess) );
            exportObj[D_ONCHANGE_SESSIONS]  = sessionsData.onchangeSessions.map( sess => toSessionExportObj(sess) );
            return Promise.resolve(exportObj);
        }
        case D_USER_SESSIONS: {
            let exportObj = prepExportObj(F_SESSIONS);
            exportObj[D_USER_SESSIONS]      = sessionsData.userSessions.map( sess => toSessionExportObj(sess) );
            return Promise.resolve(exportObj);
        }
        case D_SCHEDULED_SESSIONS: {
            let exportObj = prepExportObj(F_SESSIONS);
            exportObj[D_SCHEDULED_SESSIONS] = sessionsData.scheduledSessions.map( sess => toSessionExportObj(sess) );
            return Promise.resolve(exportObj);
        }
        case D_ONCHANGE_SESSIONS: {
            let exportObj = prepExportObj(F_SESSIONS);
            exportObj[D_ONCHANGE_SESSIONS]  = sessionsData.onchangeSessions.map( sess => toSessionExportObj(sess) );
            return Promise.resolve(exportObj);
        }
        case D_FAVICON_DB: {
            let exportObj = prepExportObj(F_FAVICON_DB);
            return db.pExportFaviconDb().then( faviconDbObj => {
                exportObj[D_FAVICON_DB] = faviconDbObj;
                return exportObj;
            });
        }
        case D_CONTAINER_DEF: {
            let exportObj = prepExportObj(F_CONTAINER_DEF);
            return container.pGetContainerInfos().then( contextualIdentities => {
                exportObj[D_CONTAINER_DEF] = contextualIdentities;
                return exportObj;
            });
        }
        default:
            return Promise.reject("Unknown export type " + exportType);
        }
    }

    function pExportData(sessionsData, exportType) {
        return pGenerateExportData(sessionsData, exportType)
            .then( exportObj => pDownloadJson(exportObj, appcfg.APPTITLE + " - " + exportType + ".json") );
    }

    function pExportSession(sessionsData, sessionId) {
        let exportObj = prepExportObj(F_SESSION);
        sessionsData.pFindSession(sessionId).then( sess => {
            let exportType = sessionTypeToExportType(sess.sessionType);
            exportObj[exportType] = [ toSessionExportObj(sess) ];
            return pDownloadJson(exportObj, appcfg.APPTITLE + " - " + app.normalizeFilename(sess.sessionName, ".") + ".json");
        }).catch(e => log.error(e));
    }

    function pReadImportFile(html5File) {
        return app.pReadFile(html5File)
            .then( text => validateImportFile(JSON.parse(text)) )
            .then( json => parseImportJson(json) );
    }

    function pImportAllSessions(sessionsData, parsedJson) {
        let userSessions        = parsedJson.sessLists[D_USER_SESSIONS     ].map( result => new Session(result.session) );
        let scheduledSessions   = parsedJson.sessLists[D_SCHEDULED_SESSIONS].map( result => new Session(result.session) );
        let onchangeSessions    = parsedJson.sessLists[D_ONCHANGE_SESSIONS ].map( result => new Session(result.session) );
        let nowMS               = new Date().getTime();
        [userSessions, scheduledSessions, onchangeSessions].flat().forEach( s => s.importTime = nowMS );
        sessionsData.mergeUserSessions(userSessions);
        sessionsData.mergeScheduledSessions(scheduledSessions);
        sessionsData.mergeOnchangeSessions(onchangeSessions);
        return sessionsData.pSaveAllSessions();
    }

    function pImportReplaceSessions(sessionsData, parsedJson) {
        return Promise.all([sessionsData.pDeleteAllUserSessions(),
                            sessionsData.pDeleteAllBackupSessions(),
                            sessionsData.pDeleteAllOnChangeSessions()])
            .then( () => pImportAllSessions(sessionsData, parsedJson) );
    }

    function pImportAsUserSession(sessionsData, sessJson) {
        let importedSess = new Session(sessJson);
        importedSess.importTime = new Date().getTime();
        return sessionsData.pAddUserCopy(importedSess, false, true).then(() => "Imported as new user session - " + importedSess.sessionName);
    }

    // Module private functions

    function prepExportObj(exportFileType) {
        return {
            appId:          appcfg.APP_ID,
            exportTime:     new Date().toISOString(),
            type:           exportFileType,
            version:        1,
        };
    }

    function toSessionExportObj(sess) {
        let sessExportObj = {
            msgDigest:      sess.computeMessageDigest(),
        };
        sessExportObj = Object.assign(sessExportObj, sess);
        delete sessExportObj.tabMap;
        sessExportObj.windows
            .map( w => w.id )
            .map( wid => sessExportObj.tabsOfWindow[wid] = sessExportObj.tabsOfWindow[wid].map( tab => session.normalizeTab(tab) ) );
        return sessExportObj;
    }

    function pDownloadJson(obj, filename) {
        let json = JSON.stringify(obj, null, 4) + "\n";
        return browser.downloads.download({
            url:            URL.createObjectURL(new Blob([json], { type: "aplication/json" })),
            filename:       filename,
            saveAs:         true,
            conflictAction: "uniquify",
        }).catch(e => log.error(e));
    }

    function validateImportFile(json) {
        if (json.appId != appcfg.APP_ID) throw Error("File's app id is mismatched or missing.");
        if (!json.version) throw Error("File's version is missing.");
        if (!json.type) throw Error("File's type is missing.");
        return json;
    }

    function validateImportSession(json) {
        if (json._type != "Session") throw Error("Object type 'Session' is not found.");
        if (!json._version) throw Error("Object version is not found.");
        if (!json.msgDigest) throw Error("Message digest is missing.  The importing session data has been tampered.");
        return json;
    }

    function parseImportJson(json) {
        let result;
        switch (json.type) {
        case F_SESSION:
            result = parseImportSessionsJson(json);
            break;
        case F_SESSIONS:
            result = parseImportSessionsJson(json);
            break;
        case F_FAVICON_DB:
            result = parseImportFaviconsJson(json);
            break;
        case F_CONTAINER_DEF:
            result = parseImportContainerDefJson(json);
            break;
        default:
            throw Error("Unknown data file type: " + json.type);
        }
        result.type = json.type;
        result.exportTime = json.exportTime ? new Date(json.exportTime) : null;
        return result;
    }

    function parseImportSessionsJson(json) {
        let sessLists = [D_USER_SESSIONS, D_SCHEDULED_SESSIONS, D_ONCHANGE_SESSIONS].reduce( (sessLists, exportDataType) => {
            sessLists[exportDataType] = (json[exportDataType] || []).map( sessJson => parseImportSession(sessJson) );
            return sessLists;
        }, {});
        return { sessLists: sessLists };
    }

    function parseImportSession(json) {
        let res = {
            status:         "success",      // same as the CSS class label-success
            msg:            "",
            session:        {},
        };
        try {
            res.session = new Session(validateImportSession(json));
            // TODO: msg digest Verification is not reliable.  Need more testing.
            if (false) {
                let newDigest = res.session.computeMessageDigest();
                log.info("parseImportSession " + json.sessionName);
                log.info("|" + json.msgDigest + "|");
                log.info("|" + newDigest + "|");
                if (json.msgDigest != newDigest) {
                    res.status = "warning";     // same as the CSS class label-warning
                    res.msg = "Warning: mismatched message digest.  The session data in the data file has been tampered.";
                }
            }
        } catch (e) {
            res.status = "error";           // same as the CSS class label-error
            res.msg = e.toString();
        }
        return res;
    }

    function parseImportFaviconsJson(json) {
        return { favicon_db: db.validateImportFaviconDb(json[D_FAVICON_DB] || {}) };
    }

    function parseImportContainerDefJson(json) {
        return { container_def: json[D_CONTAINER_DEF] || {} };
    }
    
    function sessionTypeToExportType(sessionType) {
        switch (sessionType) {
        case session.USER:      return D_USER_SESSIONS;
        case session.SCHEDULED: return D_SCHEDULED_SESSIONS;
        case session.ONCHANGE:  return D_ONCHANGE_SESSIONS;
        default:                return "";
        }
    }


    // Module exports
    module.D_ALL_SESSIONS = D_ALL_SESSIONS;
    module.D_USER_SESSIONS = D_USER_SESSIONS;
    module.D_SCHEDULED_SESSIONS = D_SCHEDULED_SESSIONS;
    module.D_ONCHANGE_SESSIONS = D_ONCHANGE_SESSIONS;
    module.D_FAVICON_DB = D_FAVICON_DB;
    module.F_SESSION = F_SESSION;
    module.F_SESSIONS = F_SESSIONS;
    module.F_FAVICON_DB = F_FAVICON_DB;
    module.F_CONTAINER_DEF = F_CONTAINER_DEF;
    module.pGenerateExportData = pGenerateExportData;
    module.pExportData = pExportData;
    module.pExportSession = pExportSession;
    module.pReadImportFile = pReadImportFile;
    module.pImportAllSessions = pImportAllSessions;
    module.pImportReplaceSessions = pImportReplaceSessions;
    module.pImportAsUserSession = pImportAsUserSession;

    
    return module;

}(this, "dataio"));    // Pass in the global scope as 'this' scope.

