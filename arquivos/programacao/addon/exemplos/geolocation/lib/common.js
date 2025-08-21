var core = {
  "start": function () {
    core.load();
  },
  "install": function () {
    core.load();
  },
  "load": function () {
    app.contextmenu.create({
      "contexts": ["action"],
      "title": "What is my Geolocation?", 
      "id": "change-geolocation-test-page"
    }, app.error);
  },
  "action": {
    "storage": function (changes, namespace) {
      /*  */
    },
    "load": function () {
      app.button.icon(null, config.addon.state);
      app.button.title(null, "Change Geolocation: " + config.addon.state);
      /*  */
      app.webnavigation.on.committed.add();
    },
    "button": function () {
      config.addon.state = config.addon.state === "ON" ? "OFF" : "ON";
      /*  */
      app.button.icon(null, config.addon.state);
      app.button.title(null, "Change Geolocation: " + config.addon.state);
    },
    "contextmenu": function (e) {
      if (e) {
        if (e.menuItemId === "change-geolocation-test-page") {
          app.tab.open(config.test.page);
        }
      }
    },
    "message": function (request) {
      if (request) {
        if (request.method === "configure-geolocation") {
          if (request.data) {
            config.options.geolocation.coords.latitude = request.data.latitude;
            config.options.geolocation.coords.longitude = request.data.longitude;
            /*  */
            setTimeout(function () {
              app.options.send("reload");
            }, 300);
          }
        }
      }
    },
    "options": {
      "get": function (pref) {
        app.options.send("set", {
          "pref": pref,
          "value": config.get(pref)
        });
      },
      "set": function (o) {
        config.set(o.pref, o.value);
        app.options.send("set", {
          "pref": o.pref,
          "value": config.get(o.pref)
        });
      }
    },
    "inject": function (e) {
      if (config.addon.state === "ON") {
        const code = config.options.geolocation;
        const arg = JSON.stringify(code);
        /*  */
        app.tab.inject.js({
          "args": [arg],
          "world": "MAIN",
          "injectImmediately": true,
          "target": {
            "tabId": e.tabId,
            "frameIds": [e.frameId]
          },
          "func": function (q) {
            window.geoLocationStorage = q;
          }
        }, function () {
          app.tab.inject.js({
            "world": "MAIN",
            "injectImmediately": true,
            "target": {
              "tabId": e.tabId,
              "frameIds": [e.frameId]
            },
            "files": [
              "/data/content_script/page_context/inject.js"
            ]
          });
        });
      }
    }
  }
};

app.storage.load(core.action.load);

app.button.on.clicked(core.action.button);
app.contextmenu.on.clicked(core.action.contextmenu);
app.webnavigation.on.committed.callback(core.action.inject);

app.options.receive("get", core.action.options.get);
app.options.receive("changed", core.action.options.set);
app.options.receive("test", function () {app.tab.open(config.test.page)});
app.options.receive("support", function () {app.tab.open(app.homepage())});
app.options.receive("donation", function () {app.tab.open(app.homepage() + "?reason=support")});

app.on.startup(core.start);
app.on.installed(core.install);
app.on.storage(core.action.storage);
app.on.message(core.action.message);
