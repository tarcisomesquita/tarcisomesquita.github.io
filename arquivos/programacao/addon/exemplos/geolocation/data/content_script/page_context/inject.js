{
  const options = JSON.parse(geoLocationStorage);
  //
  if (navigator) {
    if (navigator.geolocation) {
      if (navigator.geolocation.__proto__) {
        if (navigator.geolocation.__proto__.getCurrentPosition) {
          navigator.geolocation.__proto__.getCurrentPosition = new Proxy(navigator.geolocation.__proto__.getCurrentPosition, {
            apply(target, self, args) {
              if (args) {
                if (args[0]) {
                  if (typeof args[0] === "function") {
                    const success = args[0];
                    //
                    args[0] = function (position) {
                      if (position) {
                        if ("timestamp" in position) {
                          Object.defineProperty(position, "timestamp", {"value": options.timestamp !== null ? options.timestamp : null});
                        }
                        //
                        if ("coords" in position) {
                          Object.defineProperty(position.coords, "speed", {"value": options.coords.speed !== null ? options.coords.speed : null});
                          Object.defineProperty(position.coords, "heading", {"value": options.coords.heading !== null ? options.coords.heading : null});
                          Object.defineProperty(position.coords, "latitude", {"value": options.coords.latitude !== null ? options.coords.latitude : null});
                          Object.defineProperty(position.coords, "accuracy", {"value": options.coords.accuracy !== null ? options.coords.accuracy : null});
                          Object.defineProperty(position.coords, "altitude", {"value": options.coords.altitude !== null ? options.coords.altitude : null});
                          Object.defineProperty(position.coords, "longitude", {"value": options.coords.longitude !== null ? options.coords.longitude : null});
                          Object.defineProperty(position.coords, "altitudeAccuracy", {"value": options.coords.altitudeAccuracy !== null ? options.coords.altitudeAccuracy : null});
                        }
                      }
                      //
                      success.apply(this, arguments);
                    };
                  }
                }
              }
              //
              return Reflect.apply(target, self, args);
            }
          });
        }
      }
    }
  }
}
