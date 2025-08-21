/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// sessiongroup module for backup session group.
(function(scope, modulename) {
    "use strict";

    // Import:
    // import logger
    // import appcfg
    // import moment
    // import app
    let Session = session.Session;
    
    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    var module = function() { };       // Module object to be returned.
    if (scope && modulename)
        scope[modulename] = module;    // set module name in scope, otherwise caller sets the name with the returned module object.

    const BACKUP_15MIN   = 0;   // index to the BACKUP_GROUP_CFGS
    const BACKUP_HOURLY  = 1;
    const BACKUP_DAILY   = 2;
    const BACKUP_WEEKLY  = 3;
    const BACKUP_MONTHLY = 4;
    const BACKUP_GROUP_CFGS = [
        { groupType: "15-minute",   slotCount: 4,   startOfUnit: "minute",  durationUnit: "minutes",    units: 15,  duration: moment.duration(15, "minutes")    },
        { groupType: "hourly",      slotCount: 4,   startOfUnit: "hour",    durationUnit: "hours",      units: 1,   duration: moment.duration(1,  "hours")      },
        { groupType: "daily",       slotCount: 4,   startOfUnit: "day",     durationUnit: "days",       units: 1,   duration: moment.duration(1,  "days")       },
        { groupType: "weekly",      slotCount: 4,   startOfUnit: "week",    durationUnit: "weeks",      units: 1,   duration: moment.duration(1,  "weeks")      },
        { groupType: "monthly",     slotCount: 4,   startOfUnit: "month",   durationUnit: "months",     units: 1,   duration: moment.duration(1,  "months")     },
    ];
    const BACKUP_GROUP_MAP = BACKUP_GROUP_CFGS.reduce( (map, cfg) => { map[cfg.groupType] = cfg; return map }, {} );
    const BACKUP_GROUP_TYPES = BACKUP_GROUP_CFGS.map( cfg => cfg.groupType );

    // Class for a group of sessions for a time range type,
    // e.g. the group of sessions for the 15-minute range type, or the group for the daily range type.
    class SessionGroup {

        constructor(groupType, jsonObj) {
            this._type = "SessionGroup";
            this._version = 1;
            if (jsonObj) {
                this._fromObj(jsonObj);
            } else {
                this._newVersion1(groupType);
            }
        }

        _fromObj(jsonObj) {
            switch (jsonObj._version) {
            case 1:
                return this._fromVersion1(jsonObj);
            default:
                throw Error("Unsupported object version " + jsonObj._version);
            }
        }

        _newVersion1(groupType) {
            let cfg = BACKUP_GROUP_MAP[groupType];
            if (!cfg)
                throw Error("Invalid groupType " + groupType);
            this.groupType = groupType;
            this._sessions = new Array(cfg.slotCount).fill(null);   // index 0th has the most recent session, biggest timestamp.
        }

        _fromVersion1(jsonObj) {
            let cfg = BACKUP_GROUP_MAP[jsonObj.groupType];
            if (!cfg)
                throw Error("Missing or invalid groupType field in jsonObj");
            this.groupType = cfg.groupType;
            this._sessions = new Array(cfg.slotCount).fill(null);
            let jsonSessions = jsonObj._sessions || [];
            let count = Math.min(jsonSessions.length, this.length);
            for (let i = 0; i < count; i++)
                this._sessions[i] = jsonSessions[i] ? new Session(jsonSessions[i]) : null;
            this._validateVersion1();
        }

        _validateVersion1() {
            if (!BACKUP_GROUP_MAP[this.groupType])
                throw Error("Unsupported groupType " + this.groupType);
        }

        get length()        { return this._sessions.length }
        get sessions()      { return this._sessions }       // alias for the _session array.
        get newest()        { return this._sessions[0] }    // index 0th has the most recent session.
        set newest(sess)    { this._sessions[0] = this.updateSessionGroupInfo(sess) }
        // get uiSessions()    { return (this.groupType == "15-minute" ? this._sessions.slice(0) : this._sessions.slice(1)).filter(Boolean) }
        get uiSessions()    { return this._sessions.filter(Boolean) }
        get uiSessionCount(){ return this.uiSessions.length }

        propagateSessions(groupRangeMap) {
            let needSave = false;
            let cfg = BACKUP_GROUP_MAP[this.groupType];
            let groupRange = backupGroupTimeRange(groupRangeMap, cfg);
            log.info("### propagateSessions " + this.groupType +
                     "; groupRange begin: " + groupRange.beginTime.format("M/D/YYYY h:mma") + ", END: " + groupRange.endTime.format("M/D/YYYY h:mma"));

            // Clear out sessions that're completely outside of the group's time range.
            let oldSessionCount = this._sessions.filter(Boolean).length;
            this._sessions = this._sessions.map( s => s && moment(s.sessionTimeMS).isBefore(groupRange.beginTime) ? null :  s );
            let newSessionCount = this._sessions.filter(Boolean).length;
            needSave = newSessionCount < oldSessionCount;                               // need to save if new count is less than old count
            if (newSessionCount < oldSessionCount)
                log.info("newSessionCount " + newSessionCount + " < oldSessionCount " + oldSessionCount + ".  " + (oldSessionCount - newSessionCount) + " sessions were deleted");
            else
                log.info("No sessions were deleted due to expiration.  Session count " + newSessionCount);

            // Propagate the session at slot 0 if it's outside of slot 0's time range.
            if (this.newest) {
                let slotRange   = newestSlotTimeRange(groupRangeMap, cfg);              // newest slot's time range based on the current time.
                let newestTime  = moment(this.newest.sessionTimeMS);
                log.info("newest session: " + newestTime.format("M/D/YYYY h:mm:ssa") +
                         ", slotRange begin: " + slotRange.beginTime.format("M/D/YYYY h:mma") + " END: " + slotRange.endTime.format("M/D/YYYY h:mma"));
                if (newestTime.isBefore(slotRange.endTime)) {
                    log.info("newest session is older than slotRange.endTime.  Propagate it.");
                    this._sessions.unshift(null);                                       // newest was outside of slot 0's time range, move it and set slot 0 to null.
                    needSave = true;
                } else {
                    log.info("newest session is NOT older than slotRange.endTime.");
                }
            } else {
                log.info("newest slot is empty/null");
            }

            this._sessions.length = cfg.slotCount;                                      // trim/expand the session array to ensure a fixed size.
            return needSave;
        }

        // batchAdd is used for adding a set of sessions to the schedule group in the correct time order and size,
        // for importing old sessions back into the Scheduled Backup group.
        batchAddStart() {
            this._batching = this._sessions.filter(Boolean);                            // create the transient array to hold the batch-adding sessions.
        }

        batchAddDone() {
            let cfg = BACKUP_GROUP_MAP[this.groupType];
            this._sessions = this._batching.sort( (s1, s2) => s1.sessionTimeMS - s2.sessionTimeMS );  // ordered by the largest timestamp (most recent).
            this._sessions.length = cfg.slotCount;
            this.updateSessionsGroupInfo();
            this.batchAddCleanup();
        }

        batchAddCleanup() {
            delete this._batching;                                                      // remove the transient data before saving to store.
        }

        batchAddByTime(groupRangeMap, candidateSession) {
            let cfg = BACKUP_GROUP_MAP[this.groupType];
            let groupRange = groupRangeMap[this.groupType];
            let oldestGroupBeginTime = moment(groupRange.beginTime).subtract(this.length * cfg.units, cfg.durationUnit);   // go into previous interval
            let youngestGroupEndTime = moment(groupRange.endTime  ).subtract(this.length * cfg.units, cfg.durationUnit);   // go into previous interval
            let candidateTime = moment(candidateSession.sessionTimeMS);
            log.info("-------- batchAddByTime - candidateSession name: " + candidateSession.sessionName + ", time: " + candidateTime.format("M/D/YYYY h:mm:ssa"));
            log.info("cfg.durationUnit: " + cfg.durationUnit + ", cfg.units: " + cfg.units);
            log.info("oldestGroupBeginTime: " + oldestGroupBeginTime.format("M/D/YYYY h:mm:ssa") + ", youngestGroupEndTime: " +
                     youngestGroupEndTime.format("M/D/YYYY h:mm:ssa"));
            if (candidateTime.isBefore(oldestGroupBeginTime) || candidateTime.isAfter(youngestGroupEndTime)) {
                log.info("Outside of the time range of the group.");
                return false;       // not imported
            } else {
                log.info("Within the time range of the group.");
                this._batching.push(candidateSession);
                return true;        // imported
            }
        }

        clearSessionsInGroup() {
            for (let i = 0; i < this._sessions.length; i++)
                this._sessions[i] = null
            return this;
        }

        updateSessionsGroupInfo() {
            this._sessions.forEach( sess => this.updateSessionGroupInfo(sess) );
        }

        updateSessionGroupInfo(sess) {
            if (sess) {
                sess.setGroup(this.groupType);
                sess.setGroupTitle("group:" + this.groupType);
                sess.setSessionName("backup " + sess.shortTime + " " + this.groupType);
            }
            return sess;
        }

    }

    function createBackupGroups() {
        return BACKUP_GROUP_CFGS.map(cfg => new SessionGroup(cfg.groupType));
    }

    function roundToInterval(momentTime, intervalDuration) {
        return moment(Math.floor((+momentTime) / (+intervalDuration)) * (+intervalDuration));
    }

    // Time interval range of each group based on current time.
    function currentGroupRangeMap() {
        let now = moment();
        return BACKUP_GROUP_CFGS.reduce( (map, cfg) => app.setObjVal(map, cfg.groupType, currentGroupTimeRange(cfg, now)), {} );
    }

    // Group time range spanning the current time.
    // The beginTime is before the current time while endTime will be after the current time; the backup range should be one interval before that.
    // [beginTime of now, endTime]
    // [In the past (lower time value), more recent (higher time value)]
    function currentGroupTimeRange(cfg, now) {
        let roundDownOfNow  = moment(now).startOf(cfg.startOfUnit);     // start time of interval spanning current time, e.g. 12:00am for current day.
        let beginTime       = cfg.groupType == "15-minute" ? roundToInterval(now, cfg.duration) : roundDownOfNow;   // beginTime is rounded down.
        let endTime         = moment(beginTime).add(cfg.slotCount * cfg.units, cfg.durationUnit);                   // range includes all time slots.
        return { beginTime: beginTime, endTime: endTime, now: now };
    }

    // A group range spans the current time.  The backup group range needs to go back on interval before the current time.
    function backupGroupTimeRange(groupRangeMap, cfg) {
        let groupRange      = groupRangeMap[cfg.groupType];
        let groupBeginTime  = moment(groupRange.beginTime).subtract(cfg.slotCount * cfg.units, cfg.durationUnit);   // go into previous interval
        let groupEndTime    = moment(groupRange.endTime  ).subtract(cfg.slotCount * cfg.units, cfg.durationUnit);   // go into previous interval
        return { beginTime: groupBeginTime, endTime: groupEndTime, now: groupRange.now };
    }

    function backupSlotTimeRange(groupRangeMap, cfg, slot) {
        let groupRange      = groupRangeMap[cfg.groupType];
        let groupEndTime    = moment(groupRange.endTime  ).subtract(cfg.slotCount * cfg.units, cfg.durationUnit);   // go into previous interval
        let slotBeginTime   = moment(groupEndTime).subtract((slot + 1) * cfg.units, cfg.durationUnit);
        let slotEndTime     = moment(groupEndTime).subtract((slot    ) * cfg.units, cfg.durationUnit);
        return { beginTime: slotBeginTime, endTime: slotEndTime, now: groupRange.now };
    }

    function newestSlotTimeRange(groupRangeMap, cfg) {
        let groupRange      = groupRangeMap[cfg.groupType];
        let groupEndTime    = moment(groupRange.endTime).subtract(cfg.slotCount * cfg.units, cfg.durationUnit);     // go into previous interval
        let slotBeginTime   = moment(groupEndTime).subtract(1 * cfg.units, cfg.durationUnit);
        let slotEndTime     = moment(groupEndTime);
        return { beginTime: slotBeginTime, endTime: slotEndTime, now: groupRange.now };
    }


    // Module export
    module.BACKUP_15MIN             = BACKUP_15MIN;
    module.BACKUP_HOURLY            = BACKUP_HOURLY;
    module.BACKUP_DAILY             = BACKUP_DAILY;
    module.BACKUP_WEEKLY            = BACKUP_WEEKLY;
    module.BACKUP_MONTHLY           = BACKUP_MONTHLY;
    module.BACKUP_GROUP_CFGS        = BACKUP_GROUP_CFGS;
    module.BACKUP_GROUP_MAP         = BACKUP_GROUP_MAP;
    module.BACKUP_GROUP_TYPES       = BACKUP_GROUP_TYPES;
    module.SessionGroup             = SessionGroup;
    module.createBackupGroups       = createBackupGroups;
    module.currentGroupRangeMap     = currentGroupRangeMap;

    
    return module;

}(this, "sessiongroup"));   // Pass in the global scope as 'this' scope.

