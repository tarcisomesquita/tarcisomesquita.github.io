// receive configuration (latitude, longitude) from https://webbrowsertools.com/geolocation/

window.addEventListener("message", function (e) {
  if (e) {
    if (e.data) {
      if (e.data.method === "configure-geolocation") {
        if (e.data.geo) {
          const geo = e.data.geo.split(',');
          /*  */
          if (geo && geo.length) {
            chrome.runtime.sendMessage({
              "method": e.data.method,
              "data": {
                "latitude": Number(geo[0].trim()),
                "longitude": Number(geo[1].trim())
              },
            }, function () {
              return chrome.runtime.lastError;
            });
            /*  */
            window.setTimeout(function () {
              window.top.postMessage({
                "method": "configuration-accepted"
              }, '*');
            }, 750);
          }
        }
      }
    }
  }
});
