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
    // import moment
    // import logger
    // import appcfg
    // import app
    // import ringbuf
    // import settings
    // import session
    // import sessiongroup
    let RingBuf = ringbuf.RingBuf;
    let Session = session.Session;
    let SessionGroup = sessiongroup.SessionGroup;

    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    var module = function() { };       // Module object to be returned.
    if (scope && modulename)
        scope[modulename] = module;    // set module name in scope, otherwise caller sets the name with the returned module object.


    class Sessions {

        static newInitSessions() {
            return new Sessions()._normalize();
        }

        constructor() {}

        // _normalize() should be called after deserialization on the data objects.
        // deserialization restores the objects; _normalize() creates any missing objects as a last ditch effort.
        _normalize() {
            //log.info("Sessions._normalize()");

            // Snapshot change log
            this.changeLog = (this.changeLog && this.changeLog instanceof RingBuf) ? this.changeLog : new RingBuf(appcfg.MAX_SNAPSHOTS);
            this.snapshotCursor = app.defObjVal(this, "snapshotCursor", this.changeLog.newestIndex);    // -1 for empty.
            //log.info("_normalize() snapshotCursor = " + this.snapshotCursor + ", changeLog.newestIndex = " + this.changeLog.newestIndex);

            // User sessions
            this.userSessions = this.userSessions || [];
            this.lastUserSavedId = this.lastUserSavedId || "";
            this.lastOperationId = this.lastOperationId || "";
            this.autoRestoreSessionId = this.autoRestoreSessionId || "";

            // Backup sessions
            if (!this.backupSessionGroups) {
                this.backupSessionGroups = sessiongroup.createBackupGroups();
            }
            this.lastBackupSavedId = this.lastBackupSavedId || "";

            // OnChange sessions
            this.onchangeSessionList = (this.onchangeSessionList && this.onchangeSessionList instanceof RingBuf) ?
                                        this.onchangeSessionList : new RingBuf(settings.ofCurrent.maxOnchangeSession);
            this.lastOnChangeSavedId = this.lastOnChangeSavedId || "";

            // Crash store
            // This is the auto-saved session id before FF exits, saved along with Auto/OnCrash stores.
            // boss_daemon copies it at startup and saves it as the last FF saved id.
            this.autoSavedIdOnCrash = this.autoSavedIdOnCrash || "";

            // App state store
            // TODO: make restore log to save a log of session restoration.
            this.lastRestoredId = this.lastRestoredId || "";            // Updated everytime a restore happens.

            // Transient data
            this._updateSessionMapById();                               // create this._sessionMapById = {};

            return this;
        }

        _clearAllSessionsData(bResetChangeLog) {
            if (bResetChangeLog) {
                // changeLog
                this.changeLog = new RingBuf(appcfg.MAX_SNAPSHOTS);
                this.snapshotCursor = this.changeLog.newestIndex;
            }

            // User session store
            this.userSessions = null;
            this.lastUserSavedId = null;
            this.lastOperationId = null;
            this.autoRestoreSessionId = null;

            // Auto backup store
            this.backupSessionGroups = null;
            this.lastBackupSavedId = null;

            // OnChange session store
            this.onchangeSessionList = null;
            this.lastOnChangeSavedId = "";

            // Crash store
            this.autoSavedIdOnCrash = "";

            // App state store
            this.lastRestoredId = null;

            // Re-create the member variables.
            this._normalize();
        }

        static startsWithSnapshotName(name) {
            return name.startsWith(appcfg.SNAPSHOT_BASE);
        }

        // Store name has the form of: snapshotNN
        _getSnapshotName() {
            let snapshotId = this.changeLog.pos(this.snapshotCursor);   // use RingBuf.pos() as snapshotId since it wraps around.
            return appcfg.SNAPSHOT_BASE + app.pad(snapshotId, 2);        // old store name will be re-used when id wraps around.
        }


        _prepChangeLog(saveParams) {
            saveParams["changeLogStore"] = {
                changeLog:          this.changeLog,
                snapshotCursor:     this.snapshotCursor,
            };
            return saveParams;
        }

        _prepChangeLogAndSnapshot(saveParams) {
            // Push a new slot in the changeLog RingBuf to allocate a snapshotId for the userSession data.
            // The RingBuf wraps around when its max size is exceeded, and thus the snapshotId will wrap around.
            this.changeLog.push("");
            // Always append changes as a new snapshot at the end of the change log.
            // Changes to a undo'ed snapshot will be appended at the end of the change log.
            this.snapshotCursor = this.changeLog.newestIndex;
            this._prepChangeLog(saveParams);

            // Write out the the changeLogStore and the snapshotStore at the same time.
            // Failing in the middle can always roll back to the previous snapshotStore with the previous snapshotName.
            let snapshotStore = {
                userSessions:           this.userSessions,      // save the userSessions in the snapshotStore.
                lastUserSavedId:        this.lastUserSavedId,
                lastOperationId:        this.lastOperationId,
                autoRestoreSessionId:   this.autoRestoreSessionId,
                saveTime:               new Date().getTime(),
            };
            let snapshotName = this._getSnapshotName();
            saveParams[snapshotName] = snapshotStore;

            log.info("_prepChangeLogAndSnapshot snapshotCursor = " + this.snapshotCursor +
                ", changeLog.newestIndex = " + this.changeLog.newestIndex + ", snapshotName = " + snapshotName);
            return saveParams;
        }

        _prepSaveBackupSessions(saveParams) {
            //log.info("_prepSaveBackupSessions");
            saveParams["backupSessionStore"] = {
                backupSessionGroups:    this.backupSessionGroups,
                lastBackupSavedId:      this.lastBackupSavedId,
            };
            return saveParams;
        }

        _prepSaveOnChangeSessions(saveParams) {
            saveParams["onchangeSessionStore"] = {
                onchangeSessionList:    this.onchangeSessionList,
                lastOnChangeSavedId:    this.lastOnChangeSavedId,
            }
            return saveParams;
        }

        _prepSaveCrashState(saveParams) {
            saveParams["crashStore"] = {
                autoSavedIdOnCrash: this.autoSavedIdOnCrash,
            };
            // log.info("_prepSaveCrashState ", saveParams["crashStore"]);
            return saveParams;
        }

        _prepSaveAppState(saveParams) {
            saveParams["appStateStore"] = {
                lastRestoredId:     this.lastRestoredId,
            };
            return saveParams;
        }


        _deserializeChangeLog(changeLogStore) {
            this.changeLog      = new RingBuf(appcfg.MAX_SNAPSHOTS, changeLogStore.changeLog);
            this.snapshotCursor = changeLogStore.snapshotCursor;
            return this;
        }

        _deserializeUserSessions(snapshotStore) {
            //log.info("_deserializeUserSessions");
            if (snapshotStore) {
                this.userSessions = (snapshotStore.userSessions || []).map(sessData => new Session(sessData));
                this.lastUserSavedId = snapshotStore.lastUserSavedId;
                this.lastOperationId = snapshotStore.lastOperationId;
                this.autoRestoreSessionId = snapshotStore.autoRestoreSessionId;
            } else {
                this.userSessions = null;
                this.lastUserSavedId = null;
                this.lastOperationId = null;
                this.autoRestoreSessionId = null;
            }
            //log.info("_deserializeUserSessions ", this.userSessions);
        }

        _deserializeBackupSessions(backupSessionStore) {
            //log.info("_deserializeBackupSessions");
            if (backupSessionStore && backupSessionStore.backupSessionGroups) {
                //log.info("backupSessionStore.backupSessionGroups: ", backupSessionStore.backupSessionGroups);
                this.backupSessionGroups = sessiongroup.createBackupGroups();   // create the list structure of the groups.
                let groupCount = Math.min(this.backupSessionGroups.length, backupSessionStore.backupSessionGroups.length);
                for (let i = 0; i < groupCount; i++) {
                    if (backupSessionStore.backupSessionGroups[i]) {
                        try {
                            this.backupSessionGroups[i] = new SessionGroup(null, backupSessionStore.backupSessionGroups[i]);
                        } catch(e) {
                            log.error("Failed to deserialize backupSessionGroups ", e);
                        }
                    }
                }
            } else {
                log.info("backupSessionStore.backupSessionGroups is null");
                this.backupSessionGroups = null;
            }

            this.lastBackupSavedId = backupSessionStore ? backupSessionStore.lastBackupSavedId : null;

            return this;
        }

        _deserializeOnChangeSessions(onchangeSessionStore) {
            if (onchangeSessionStore && onchangeSessionStore.onchangeSessionList) {
                this.onchangeSessionList = new RingBuf(settings.ofCurrent.maxOnchangeSession, onchangeSessionStore.onchangeSessionList);
                for (let i = 0; i < this.onchangeSessionList.length; i++) {
                    this.onchangeSessionList.set(i, new Session(this.onchangeSessionList.get(i)));
                }
                if (settings.ofCurrent.maxOnchangeSession != this.onchangeSessionList.capacity)
                    this.onchangeSessionList = ringbuf.withNewCapacity(this.onchangeSessionList, settings.ofCurrent.maxOnchangeSession);
                this.lastOnChangeSavedId = onchangeSessionStore.lastOnChangeSavedId || "";
            }
            return this;
        }

        _deserializeAppStore(appStateStore) {
            Object.assign(this, appStateStore || {});
            return this;
        }

        _deserializeCrashStore(crashStore) {
            Object.assign(this, crashStore || {});
            return this;
        }


        _pSaveChangeLog() {
            return browser.storage.local.set(this._prepChangeLog({}));
        }

        _pLoadChangeLog() {
            //log.info("_pLoadChangeLog");
            return browser.storage.local.get("changeLogStore").then( loadedMap => {
                if (loadedMap && loadedMap["changeLogStore"]) {
                    this._deserializeChangeLog(loadedMap["changeLogStore"]);
                    log.info("_pLoadChangeLog snapshotCursor = " + this.snapshotCursor);
                } else {
                    throw "changeLogStore not found";
                }
            } )
        }

        // Load snapshotStore based on the current this.snapshotCursor
        _pLoadUserSessionSnapshot() {
            let snapshotName = this._getSnapshotName();    // Load the snapshot store based on the current cursor.
            // log.info("_pLoadUserSessionSnapshot snapshotCursor = " + this.snapshotCursor + ", snapshotName = " + snapshotName);
            return browser.storage.local.get(snapshotName).then( snapshotMap => {
                if (snapshotMap && snapshotMap[snapshotName]) {
                    this._deserializeUserSessions(snapshotMap[snapshotName]);
                } else {
                    throw Error("snapshotStore " + snapshotName + " not found");
                }
            });
        }

        _pLoadChangeLogAndUserSessions() {
            return this._pLoadChangeLog()
                .then( () => this._pLoadUserSessionSnapshot() )
        }

        _pSaveChangeLogAndUserSessions() {
            return browser.storage.local.set(this._prepChangeLogAndSnapshot({}));
        }

        _pSaveBackupSessions() {
            log.info("_pSaveBackupSessions");
            let saveParams = {};
            this.backupSessionGroups.forEach( g => g.batchAddCleanup() );
            this._prepSaveBackupSessions(saveParams);
            this._prepSaveCrashState(saveParams);
            return browser.storage.local.set(saveParams);
        }

        _pSaveOnChangeSessions() {
            //log.info("_pSaveOnChangeSessions");
            let saveParams = {};
            this._prepSaveOnChangeSessions(saveParams);
            this._prepSaveCrashState(saveParams);           // TODO: check this.
            return browser.storage.local.set(saveParams);
        }

        pSaveAllSessions() {
            return Promise.all([this._pSaveChangeLogAndUserSessions(), this._pSaveBackupSessions(), this._pSaveOnChangeSessions()]);
        }

        // Should be called by the normal shutdown event code.
        // Note: After switching semantic to last FF exit id rather than last FF crash id, don't need to clear it.
        pClearCrashStore() {
            //log.info("pClearCrashStore()");
            this.autoSavedIdOnCrash = "";
            return browser.storage.local.set(this._prepSaveCrashState({})).then( () => log.info("pClearCrashStore() done") );
        }

        _pSaveAppState() {
            return browser.storage.local.set(this._prepSaveAppState({}));
        }

        _pSaveLastRestoreId(lastRestoredId) {
            this.lastRestoredId = lastRestoredId;
            return this._pSaveAppState();
        }


        // load all sessonsData
        static pLoadAllSessionsData() {
            log.info("pLoadAllSessionsData");
            let newSessions = new Sessions();
            return newSessions
                ._pLoadChangeLogAndUserSessions()
                .catch(e => log.warn("Error in loading change log and user session data. ", e) )
                .then( () => browser.storage.local.get(["backupSessionStore", "onchangeSessionStore", "appStateStore", "crashStore"]) )
                .then( loadedMap => newSessions
                       ._deserializeBackupSessions(loadedMap["backupSessionStore"] || null)
                       ._deserializeOnChangeSessions(loadedMap["onchangeSessionStore"] || null)
                       ._deserializeAppStore(loadedMap["appStateStore"] || {})
                       ._deserializeCrashStore(loadedMap["crashStore"]  || {})
                       ._normalize() )
                .catch(e => {
                    log.error("Error loading any Sessions data.  Return an empty Sessions object.  ", e);
                    return Sessions.newInitSessions();
                });
        }

        iterateAllSessions(fn) {
            this.iterateUserSessions(fn);
            this.iterateScheduledSessions(fn);
            this.iterateOnChangeSessions(fn);
        }

        iterateUserSessions(fn) {
            this.userSessions.forEach( sess => fn(sess) );
        }

        iterateScheduledSessions(fn) {
            this.backupSessionGroups.forEach( group => group.sessions.filter(Boolean).forEach( sess => fn(sess) ) );
        }

        iterateOnChangeSessions(fn) {
            for (let i = this.onchangeSessionList.length - 1; i >= 0; i--) {   // iterate in the order from newest to oldest.
                fn(this.onchangeSessionList.get(i));
            }
        }

        _updateSessionMapById() {
            this._sessionMapById = {};
            this.iterateAllSessions( sess => this._sessionMapById[sess.sessionId] = sess );
        }

        getSessionById(sessionId) {
            return sessionId ? this._sessionMapById[sessionId] : null;
        }


        get userCount()         { return this.userSessions.length }
        get scheduledCount()    { return this.backupSessionGroups.reduce( (sum, group) => sum + group.uiSessionCount, 0 ) }
        get onchangeCount()     { return this.onchangeSessionList.length }
        get totalCount()        { return this.userCount + this.scheduledCount + this.onchangeCount }
        get scheduledSessions() { return app.flatten(this.backupSessionGroups.map( group => group.uiSessions )) }
        get mostRecentSession() { return this.backupSessionGroups[sessiongroup.BACKUP_15MIN].newest }
        get onchangeSessions()  { return this.onchangeSessionList.toArrayNewest() }
        get reachedUserMax()    { return this.userSessions.length >= settings.ofCurrent.maxUserSessions }

        _setLastAutoSavedId(sessionId) {
            this.lastBackupSavedId = sessionId;
            this.autoSavedIdOnCrash = sessionId;
        }

        _setLastOnChangeSavedId(sessionId, setAutoSavedIdOnCrash) {
            this.lastOnChangeSavedId = sessionId;
            if (setAutoSavedIdOnCrash)
                this.autoSavedIdOnCrash = sessionId;
        }

        _addUser(sess) {
            this.userSessions.push(sess.setSessionType(session.USER));
            this._trimUserSessions();
            this._updateSessionMapById();
            return sess;
        }

        _trimUserSessions() {
            if (this.userSessions.length > settings.ofCurrent.maxUserSessions) {
                this.userSessions = this.userSessions.slice(-settings.ofCurrent.maxUserSessions);
                return true;
            } else {
                return false;
            }
        }

        _updateOnchangeCapacity() {
            if (settings.ofCurrent.maxOnchangeSession != this.onchangeSessionList.capacity) {
                this.onchangeSessionList = ringbuf.withNewCapacity(this.onchangeSessionList, settings.ofCurrent.maxOnchangeSession);
                return true;
            } else {
                return false;
            }
        }

        _updateLastSaved(sess) {
            this.lastUserSavedId = sess.sessionId;
            this.lastOperationId = sess.sessionId;
            return sess;
        }

        lastSavedLabel(sess) {
            let lastUserSavedSess = this._sessionMapById[this.lastUserSavedId];
            let lastAutoSavedSess = this._sessionMapById[this.lastBackupSavedId];
            let lastOnChangeSavedSess = this._sessionMapById[this.lastOnChangeSavedId];
            
            let currentSess = !isEarlier(lastUserSavedSess, lastAutoSavedSess) ? lastUserSavedSess : lastAutoSavedSess;
            currentSess     = !isEarlier(currentSess, lastOnChangeSavedSess)   ? currentSess : lastOnChangeSavedSess;

            if (currentSess && currentSess.sessionId == sess.sessionId)
                return "current";
            if (this.lastUserSavedId == sess.sessionId)
                return "saved";
            if (this.lastBackupSavedId == sess.sessionId)
                return "saved";
            if (this.lastOnChangeSavedId == sess.sessionId)
                return "saved";
            return "";
        }

        _findBackupSession(matcher) {
            let found;
            this.backupSessionGroups.forEach( group => {
                found = found || group.sessions.filter(Boolean).find( s => matcher(s) );
            });
            return found;
        }

        _findOnChangeSession(matcher) {
            return this.onchangeSessionList.find(matcher);
        }

        _findSession(sessionId) {
            let sess =
                this.userSessions.find(s => s.sessionId == sessionId) ||
                this.onchangeSessionList.find(s => s.sessionId == sessionId) ||
                this._findBackupSession(s => s.sessionId == sessionId);
            return sess;
        }

        _pFindSession(sessionId, ensureWindows) {
            let sess = this._findSession(sessionId);
            if (!sess) {
                return Promise.reject("Session " + sessionId + " is not found.");
            }
            if (ensureWindows && sess.windowCount == 0) {
                return Promise.reject("No window in session " + sessionId);
            }
            return Promise.resolve(sess);
        }

        pFindSession(sessionId) {
            return this._pFindSession(sessionId, false);
        }

        pUndoSnapshot(gCtx) {
            if (this.snapshotCursor > 0) {
                this.snapshotCursor--;
                return this._pLoadUserSessionSnapshot().then( () => this._pSaveChangeLog() );
            } else {
                return Promise.resolve();
            }
        }

        pRedoSnapshot(gCtx) {
            if (this.snapshotCursor < this.changeLog.newestIndex) {
                this.snapshotCursor++;
                return this._pLoadUserSessionSnapshot().then( () => this._pSaveChangeLog() );
            } else {
                return Promise.resolve();
            }
        }

        pSaveAllWindows(gCtx) {
            return session.pSnapshotSession(gCtx, {})
                .then( newSession => this._addUser(newSession.setSavedAs(session.AS_ALL)) )
                .then( newSession => this._updateLastSaved(newSession) )
                .then( newSession => this._pSaveChangeLogAndUserSessions() );
        }

        pSaveCurrentWindow(gCtx) {
            return session.pSnapshotSession(gCtx, {currentWindow: true})
                .then( newSession => this._addUser(newSession.setSavedAs(session.AS_WIN)) )
                .then( newSession => this._updateLastSaved(newSession) )
                .then( newSession => this._pSaveChangeLogAndUserSessions() );
        }

        _update(oldSess, newSess) {
            // Preserve the old session id, type, name, and saveAs.
            newSess
                .setSessionId(oldSess.sessionId)
                .setSessionType(oldSess.sessionType)
                .setSessionName(oldSess.sessionName)
                .setGroup(oldSess.group)
                .setSavedAs(oldSess.savedAs);
            // Update session only works on user session.  The auto backup are onchange sessions are immutable.
            let index = this.userSessions.findIndex(s => s.sessionId == oldSess.sessionId);
            if (index > -1) {
                this.userSessions[index] = newSess;
                this._updateLastSaved(newSess);
            }
            this._updateSessionMapById();
        }

        pUpdateSession(gCtx, sessionId) {
            return this._pFindSession(sessionId).then( sess => {
                return session.pSnapshotSession(gCtx, sess.isAsWin ? {currentWindow: true} : {})
                    .then( newSession => this._update(sess, newSession) )
                    .then( () => this._pSaveChangeLogAndUserSessions() )
            });
        }

        pUpdateWindow(gCtx, sessionId, winId) {
            return this._pFindSession(sessionId).then( sess => {
                return session.pSnapshotSession(gCtx, {currentWindow: true})
                    .then( newSession => sess.updateWindow(winId, newSession) )
                    .then( () => this._pSaveChangeLogAndUserSessions() );
            });
        }

        pSetWindowProperty(sessionId, winId, propName, propValue) {
            return this._pFindSession(sessionId)
                .then( sess => sess.setWindowProperty(winId, propName, propValue) )
                .then( ()   => this._pSaveChangeLogAndUserSessions() );
        }

        pToggleAutoRestore(sessionId) {
            this.autoRestoreSessionId = this.autoRestoreSessionId == sessionId ? "" : sessionId;
            return this._pSaveChangeLogAndUserSessions();
        }

        // sessionId: string, searchTerms: [string], searchByTab: bool, gCtx: {}
        pRestoreSessionAsReplacement(sessionId, searchTerms, searchByTab, gCtx) {
            return this._pFindSession(sessionId, true).then( sess => {
                sess.pRestoreSession(true, searchTerms, searchByTab, gCtx)  // async restoring in background
                    .then(() => this._pSaveLastRestoreId(sessionId))
                    .catch(e => {
                        log.error("sess.pRestoreSession. ", e);
                    });
            }).catch(e => {
                log.error("this._pFindSession. ", e);
            });
        }
        
        // sessionId: string, searchTerms: [string], searchByTab: bool, gCtx: {}
        pRestoreSessionAsAddition(sessionId, searchTerms, searchByTab, gCtx) {
            return this._pFindSession(sessionId, true).then( sess => {
                sess.pRestoreSession(false, searchTerms, searchByTab, gCtx)
                    .then(() => this._pSaveLastRestoreId(sessionId));
            });
        }

        // sessionId: string, wid: string, searchTerms: [string], searchByTab: bool, gCtx: {}
        pRestoreWindowAsNew(sessionId, wid, searchTerms, searchByTab, gCtx) {
            return this._pFindSession(sessionId, true).then( sess => {
                sess.pRestoreWindow(wid, searchTerms, searchByTab, gCtx)
                    .then(() => this._pSaveLastRestoreId(sessionId));
            });
        }
        
        // sessionId: string, wid: String, searchTerms: [string], searchByTab: bool, gCtx: {}
        pRestoreWindowAsCurrentReplacement(sessionId, wid, searchTerms, searchByTab, gCtx) {
            return this._pFindSession(sessionId, true).then( sess => {
                let winToRestore = sess.windows.find( w => w.id == wid );
                if (!winToRestore)
                    throw Error("Window " + wid + " not found in session " + sess.sessionName);
                sess.pRestoreWindowToCurrentWindow(winToRestore, true, searchTerms, searchByTab, gCtx)
                    .then(() => this._pSaveLastRestoreId(sess.sessionId));
            });
        }

        // sessionId: string, wid: String, searchTerms: [string], searchByTab: bool, gCtx: {}
        pRestoreWindowAsCurrentAddition(sessionId, wid, searchTerms, searchByTab, gCtx) {
            return this._pFindSession(sessionId, true).then( sess => {
                let winToRestore = sess.windows.find( w => w.id == wid );
                if (!winToRestore)
                    throw Error("Window " + wid + " not found in session " + sess.sessionName);
                sess.pRestoreWindowToCurrentWindow(winToRestore, false, searchTerms, searchByTab, gCtx)
                    .then(() => this._pSaveLastRestoreId(sess.sessionId));
            });
        }

        pRenameSession(sessionId, newName) {
            return this._pFindSession(sessionId).then( sess => {
                sess.setSessionName(newName);
                return this._pSaveChangeLogAndUserSessions().then(() => "Session renamed.");
            });
        }

        pSetSessionGroup(sessionId, group) {
            return this._pFindSession(sessionId).then( sess => {
                sess.setGroup(group);
                return this._pSaveChangeLogAndUserSessions().then(() => "Session group set.");
            });
        }

        pCopyToUser(sessionId) {
            return this._pFindSession(sessionId).then( sess => this.pAddUserCopy(sess, true, false) );
        }

        pAddUserCopy(sess, setNewName, setNewTime) {
            let newSessionName = setNewName ? this._makeSessionNameCopy(sess.sessionName) : "";
            let newSess = this._addUser(sess.cloneAsUser(newSessionName, setNewTime));
            this.lastOperationId = newSess.sessionId;
            return this._pSaveChangeLogAndUserSessions();
        }

        // The merge functions are used by import.
        mergeUserSessions(userSessions) {
            log.info("mergeUserSessions");
            // Merge or add user sessions.
            let newSessions     = userSessions.filter(s => this._sessionMapById[s.sessionId] == null);
            let existingPairs   = userSessions.map(p0 => [p0, this._sessionMapById[p0.sessionId]]).filter(p => p[1]);   // p[0] is from, p[1] is existing.
            let nonUserPairs    = existingPairs.filter(p => p[1].sessionType != session.USER);
            let nonUserClones   = nonUserPairs.map(p => p[0].cloneAsUser(null, false));                                 // clone non-user sessions.
            existingPairs.filter(p => p[1].sessionType == session.USER).forEach(p => p[1].mergeByLastModified(p[0]));   // merge existing sessions.
            this.userSessions = [this.userSessions, newSessions, nonUserClones].flat().sort( (s1, s2) => s2.sessionTimeMS - s1.sessionTimeMS );
            this._trimUserSessions();
            this._updateSessionMapById();
        }

        mergeScheduledSessions(scheduledSessions) {
            log.info("mergeScheduledSessions");
            // Merge or add scheduled sessions.
            let existingList    = this.scheduledSessions;
            let existingIdSet   = new Set(existingList.map(s => s.sessionId));
            scheduledSessions = scheduledSessions.filter( s => !existingIdSet.has(s.sessionId) );   // scheduled sessions are immutable; skip duplicates.
            this.backupSessionGroups.forEach( g => g.batchAddStart() );
            let groupRangeMap = sessiongroup.currentGroupRangeMap();
            scheduledSessions.forEach( sess => {
                let skip = false;
                log.info("######## scheduledSession: " + sess.sessionName);
                this.backupSessionGroups.forEach( g => skip = skip || g.batchAddByTime(groupRangeMap, sess) )   // once added, can skip the rest of the groups.
            });
            this.backupSessionGroups.forEach( g => g.batchAddDone() );
            this._updateSessionMapById();
        }

        mergeOnchangeSessions(onchangeSessions) {
            log.info("mergeOnchangeSessions");
            // Merge and add onchange sessions.
            let existingList    = this.onchangeSessions;
            let existingIdSet   = new Set(existingList.map(s => s.sessionId));
            onchangeSessions = onchangeSessions.filter( s => !existingIdSet.has(s.sessionId) );     // onchange sessions are immutable; skip duplicates.
            onchangeSessions = [existingList, onchangeSessions].flat().sort( (s1, s2) => s2.sessionTimeMS - s1.sessionTimeMS );
            this.onchangeSessionList.clear().pushItems(onchangeSessions);
            this._updateSessionMapById();
        }

        _deleteUserSession(sessionId) {
            let oldArray = this.userSessions;
            let newArray = oldArray.filter(s => s.sessionId != sessionId);
            this.userSessions = newArray;
            this._updateSessionMapById();
            return oldArray.length != newArray.length;
        }

        _deleteScheduledBackupSession(sessionId) {
            let deleted = false;
            this.backupSessionGroups.forEach( group => {
                group.sessions.forEach( (s, i, sessions) => {
                    if (s && s.sessionId == sessionId) {
                        sessions[i] = null;
                        deleted = true;
                    }
                })
            });
            this._updateSessionMapById();
            return deleted;
        }

        _deleteOnChangeSessions(sessionId) {
            let deleted = this.onchangeSessionList.deleteItems( s => s.sessionId == sessionId );
            this._updateSessionMapById();
            return deleted;
        }

        pDeleteSession(sessionId) {
            log.info("pDeleteSession " + sessionId);
            if (this._deleteUserSession(sessionId)) {
                return this._pSaveChangeLogAndUserSessions();
            } else if (this._deleteScheduledBackupSession(sessionId)) {
                return this._pSaveBackupSessions();
            } else if (this._deleteOnChangeSessions(sessionId)) {
                return this._pSaveOnChangeSessions();
            } else {
                return Promise.reject("No session found for session Id");
            }
        }

        pDeleteWindow(sessionId, winId) {
            return this._pFindSession(sessionId).then( sess => {
                if (sess.deleteWindow(winId)) {
                    return this._pSaveChangeLogAndUserSessions();
                } else {
                    return Promise.reject("No window found for the window id " + winId);
                }
            });
        }

        pRestoreTab(gCtx, sessionId, winId, tabId) {
            return this._pFindSession(sessionId).then( sess => sess.pRestoreTab(gCtx, winId, tabId) );
        }

        pUpdateTabs(sessionId, winId, changedTabs, moved, deleted, orderedIds) {
            log.info("pUpdateTabs sessionId:" + sessionId + ", winId:" + winId);
            return this._pFindSession(sessionId)
                .then( sess => sess.updateTabs(winId, changedTabs, moved, deleted, orderedIds) )
                .then( ()   => this._pSaveChangeLogAndUserSessions() );
        }

        pDeleteTab(sessionId, winId, tabId) {
            log.info("pDeleteTab sessionId:" + sessionId + ", winId:" + winId + ", tabId;" + tabId);
            return this._pFindSession(sessionId)
                .then( sess => sess.deleteTab(winId, tabId) )
                .then( ()   => this._pSaveChangeLogAndUserSessions() );
        }

        pSetTabProperty(sessionId, winId, tabId, propName, propValue) {
            return this._pFindSession(sessionId)
                .then( sess => sess.setTabProperty(winId, tabId, propName, propValue) )
                .then( ()   => this._pSaveChangeLogAndUserSessions() );
        }

        pReorderTabs(sessionId, winId, tabIds) {
            return this._pFindSession(sessionId)
                .then( sess => sess.reorderTabs(winId, tabIds) )
                .then( ()   => this._pSaveChangeLogAndUserSessions() );
        }
    
        _makeSessionNameCopy(name) {
            let suffix = " - Copy";
            let index = name.indexOf(suffix);
            let baseName = index < 0 ? name : name.substring(0, index);
            let newName  = baseName + suffix;
            let endingNums = this.userSessions
                .filter(s => s.sessionName.startsWith(newName))
                .map(   s => s.sessionName.substring(newName.length))
                .map(   n => Number.parseInt(n))
                .filter(n => Number.isInteger(n));
            let maxNum = endingNums.length > 0 ? Math.max.apply(null, endingNums) : Math.NaN;
            newName = newName + (Number.isInteger(maxNum) ? maxNum+1 : "1");
            return newName;
        }

        pRunScheduledBackup(gCtx) {
            let now = moment();
            log.info("pRunScheduledBackup now: " + moment(now).format("M/D/YYYY h:mm:ss a"));

            let groupRangeMap   = sessiongroup.currentGroupRangeMap();
            let needSaves       = this.backupSessionGroups.map( group => group.propagateSessions(groupRangeMap) );
            let needSave        = needSaves.reduce((sum, flag) => sum || flag, false);
            let needBackup      = this.backupSessionGroups.filter(group => group.newest == null).length > 0;  // some newest slots are empty after propagation.
            log.info("pRunScheduledBackup - needSave = " + needSave + ", needBackup = " + needBackup);

            if (needBackup) {
                return this.pMakeScheduledBackup(gCtx).then(() => {
                    this._updateSessionMapById();
                    return this._pSaveBackupSessions();
                });
            } else {
                if (needSave) {
                    return this._pSaveBackupSessions();
                } else {
                    return Promise.resolve();
                }
            }
        }

        pMakeScheduledBackup(gCtx) {
            return this.pGetMostRecentScheduledSession(gCtx).then( mostRecentSession => {
                if (!this.backupSessionGroups[sessiongroup.BACKUP_15MIN].newest) {
                    this.backupSessionGroups[sessiongroup.BACKUP_15MIN].newest = mostRecentSession;
                    this._setLastAutoSavedId(this.backupSessionGroups[sessiongroup.BACKUP_15MIN].newest.sessionId);
                }

                log.info("pMakeScheduledBackup, clone mostRecentSession to fill the empty newest slot (slot 0) in each session group, for later propagation.");
                this.backupSessionGroups
                    .filter( group => group.newest == null )                            // only fill in the empty newest slots.
                    .forEach( group => group.newest = mostRecentSession.clone(true) )   // slot 0 got a new session with current time until it's propagated to a new slot.
            });
        }

        pGetMostRecentScheduledSession(gCtx) {
            let mostRecentSession = this.backupSessionGroups[sessiongroup.BACKUP_15MIN].newest;
            if (mostRecentSession) {
                return Promise.resolve(mostRecentSession);
            } else {
                log.info("pGetMostRecentSession, no mostRecentSession.  Need to take a snapshot of the current browser session.");
                return session.pSnapshotSession(gCtx, {}).then(newSession => newSession
                                                               .setSessionType(session.SCHEDULED)
                                                               .setSavedAs(session.AS_ALL)
                                                               .setSessionName("backup " + newSession.shortTime));
            }
        }

        pForceScheduledBackup(gCtx) {
            log.info("pForceScheduledBackup");
            this.backupSessionGroups[sessiongroup.BACKUP_15MIN].newest = null;
            return this.pMakeScheduledBackup(gCtx).then(() => {
                this._updateSessionMapById();
                return this._pSaveBackupSessions();
            });
        }

        pBackupSessionOnChange(gCtx) {
            log.info("pBackupSessionOnChange");
            if (!settings.ofCurrent.enableOnChangeBackup) {
                //log.info("On-Change Backup has been disabled in Preferences.  Skip.");
                return Promise.resolve("On-Change Backup has been disabled in Preferences.");
            }
            return session.pSnapshotSession(gCtx, {}).then(newSession => {
                if (!this.onchangeSessionList.empty && this.onchangeSessionList.newest().computeTabUrlHash() == newSession.computeTabUrlHash()) {
                    return Promise.resolve("No change in the browser tabs.  Session is same as the last one.");
                } else {
                    //log.info("pBackupSessionOnChange new session.");
                    newSession
                        .setSessionType(session.ONCHANGE)
                        .setSavedAs(session.AS_ALL)
                        .setSessionName("Backup " + newSession.shortTime + " " + session.GROUP_ONCHANGE)
                        .setGroup(session.GROUP_ONCHANGE);
                    this.onchangeSessionList.push(newSession);
                    this._setLastOnChangeSavedId(newSession.sessionId, true);
                    this._updateSessionMapById();
                    return this._pSaveOnChangeSessions().then(() => "New On-Change session saved");
                }
            });
        }

        pDeleteAllUserSessions() {
            log.info("pDeleteAllUserSessions");

            // Note: Giving up on snapshotting backup sessions in DeleteAll.  The undo/redo semantic is too complicate with little benefit.
            // Delete only the user sessions.  Have a separate command to clean up the backup sessions in Option page.

            // Clear user session store.
            this.userSessions = null;
            this.lastUserSavedId = null;
            this.lastOperationId = null;
            this.autoRestoreSessionId = null;
            this._normalize();
            return this._pSaveChangeLogAndUserSessions();
        }

        pDeleteAllBackupSessions() {
            log.info("pDeleteAllBackupSessions");
            // Auto backup store
            this.backupSessionGroups = null;
            this.lastBackupSavedId = null;
            this._normalize();
            return this._pSaveBackupSessions();
        }

        pDeleteAllOnChangeSessions() {
            log.info("pDeleteAllOnChangeSessions");
            // OnChange session store
            this.onchangeSessionList = null;
            this.lastOnChangeSavedId = "";
            this._normalize();
            return this._pSaveOnChangeSessions();
        }

        pPurgeAllData() {
            log.info("pPurgeAllData");
            // Clear the data in memory.
            this._clearAllSessionsData(true);
            // Clear the saved data.
            return browser.storage.local.clear();
        }

        static pDumpTabs(tabQueryFilter) {
            log.info("pDumpTabs");
            return browser.tabs.query(tabQueryFilter).then( tabs => tabs.forEach( tab => log.info("tab: ", tab) ) );
        }

        pDumpSession(sessionId) {
            log.info("dumpSession " + sessionId);
            this._pFindSession(sessionId).then( sess => log.info(sess) );
        }

        settingOnChanged() {
            if (this._updateOnchangeCapacity())
                this._pSaveOnChangeSessions();
        }

        computeMessageDigestOnUsers() {
            let md5 = new SparkMD5();
            this.iterateUserSessions( sess => md5.append(sess.computeMessageDigest()) );
            return md5.end();
        }
        
        computeMessageDigestOnScheduled() {
            let md5 = new SparkMD5();
            this.iterateScheduledSessions( sess => md5.append(sess.computeMessageDigest()) );
            return md5.end();
        }
        
        computeMessageDigestOnOnChange() {
            let md5 = new SparkMD5();
            this.iterateOnChangeSessions( sess => md5.append(sess.computeMessageDigest()) );
            return md5.end();
        }
        
        computeMessageDigestOnAll() {
            let md5 = new SparkMD5();
            md5.append(this.computeMessageDigestOnUsers());
            md5.append(this.computeMessageDigestOnScheduled());
            md5.append(this.computeMessageDigestOnOnChange());
            return md5.end();
        }

    }


    // Module private functions

    function isEarlier(s1, s2) {
        return compareSessionTime(s1, s2) < 0;
    }

    function compareSessionTime(s1, s2) {
        if (s1 == null && s2 == null)   return 0;
        if (s1 == null)                 return 1;
        if (s2 == null)                 return -1;
        return s2.sessionTimeMS - s1.sessionTimeMS;
    }


    // Module exports 
    module.Sessions = Sessions;

    
    return module;
    
}(this, "sessions"));    // Pass in the global scope as 'this' scope.

