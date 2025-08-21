var config = {};

config.test = {"page": "https://webbrowsertools.com/geolocation/"};

config.addon = {
  set state (val) {app.storage.write("state", val)},
  get state () {return app.storage.read("state") !== undefined ? app.storage.read("state") : "ON"}
};

config.welcome = {
  set lastupdate (val) {app.storage.write("lastupdate", val)},
  get lastupdate () {return app.storage.read("lastupdate") !== undefined ? app.storage.read("lastupdate") : 0}
};

config.options = {
  "geolocation": {
    set timestamp (val) {app.storage.write("timestamp", val)},
    get timestamp () {return app.storage.read("timestamp") !== undefined ? app.storage.read("timestamp") : (new Date()).getTime()},
    "coords": {
      set speed (val) {app.storage.write("speed", val)},
      set heading (val) {app.storage.write("heading", val)},
      set latitude (val) {app.storage.write("latitude", val)},
      set altitude (val) {app.storage.write("altitude", val)},
      set accuracy (val) {app.storage.write("accuracy", val)},
      set longitude (val) {app.storage.write("longitude", val)},
      set altitudeAccuracy (val) {app.storage.write("altitudeAccuracy", val)},
      get speed () {return app.storage.read("speed") !== undefined ? app.storage.read("speed") : null},
      get heading () {return app.storage.read("heading") !== undefined ? app.storage.read("heading") : null},
      get accuracy () {return app.storage.read("accuracy") !== undefined ? app.storage.read("accuracy") : 1768},
      get altitude () {return app.storage.read("altitude") !== undefined ? app.storage.read("altitude") : null},
      get latitude () {return app.storage.read("latitude") !== undefined ? app.storage.read("latitude") : 51.482594},
      get longitude () {return app.storage.read("longitude") !== undefined ? app.storage.read("longitude") : -0.007661},
      get altitudeAccuracy () {return app.storage.read("altitudeAccuracy") !== undefined ? app.storage.read("altitudeAccuracy") : null}
    }
  }
};

config.get = function (name) {
  return name.split('.').reduce(function (p, c) {
    return p[c];
  }, config);
};

config.set = function (name, value) {
  const _set = function (name, value, scope) {
    name = name.split('.');
    if (name.length > 1) {
      _set.call((scope || this)[name.shift()], name.join('.'), value);
    } else {
      this[name[0]] = value;
    }
  }
  /*  */
  _set(name, value, config);
};
