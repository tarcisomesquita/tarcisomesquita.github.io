var background = (function () {
  let tmp = {};
  chrome.runtime.onMessage.addListener(function (request) {
    for (let id in tmp) {
      if (tmp[id] && (typeof tmp[id] === "function")) {
        if (request.path === "background-to-options") {
          if (request.method === id) {
            tmp[id](request.data);
          }
        }
      }
    }
  });
  /*  */
  return {
    "receive": function (id, callback) {
      tmp[id] = callback;
    },
    "send": function (id, data) {
      chrome.runtime.sendMessage({
        "method": id, 
        "data": data,
        "path": "options-to-background"
      }, function () {
        return chrome.runtime.lastError;
      });
    }
  }
})();

var config = {
  "reload": function () {
    document.location.reload();
  },
  "set": function (o) {
    if (window[o.pref]) {
      window[o.pref].value = o.value
    }
  },
  "load": function () {
    const test = document.querySelector("#test");
    const support = document.querySelector("#support");
    const donation = document.querySelector("#donation");
    const prefs = [...document.querySelectorAll("*[data-pref]")];
    /*  */
    test.addEventListener("click", function () {background.send("test")});
    support.addEventListener("click", function () {background.send("support")});
    donation.addEventListener("click", function () {background.send("donation")});
    /*  */
    prefs.forEach(function (elem) {
      const pref = elem.getAttribute("data-pref");
      window[pref] = config.connect(elem, pref);
    });
    /*  */
    window.removeEventListener("load", config.load, false);
  },
  "connect": function (elem) {
    let att = "value";
    let pref = elem.getAttribute("data-pref");
    if (elem) {
      if (elem.type === "checkbox") att = "checked";
      if (elem.localName === "textarea") att = "value";
      if (elem.localName === "span") att = "textContent";
      if (elem.localName === "select") att = "selectedIndex";
      /*  */
      background.send("get", pref);
      elem.addEventListener("change", function () {
        background.send("changed", {
          "pref": pref,
          "value": this[att]
        });
      });
    }
    /*  */
    return {
      get value () {
        return elem[att];
      },
      set value (val) {
        if (elem.type === "file") return;
        elem[att] = val;
      }
    }
  }
};

background.receive("set", config.set);
background.receive("reload", config.reload);

window.addEventListener("load", config.load, false);
