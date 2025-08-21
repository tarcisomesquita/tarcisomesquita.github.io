/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

(function(scope, modulename) {
    "use strict";

    var module = function() { };    // Module object to be returned; local reference to the package object for use below.
    if (modulename)
        scope[modulename] = module; // set module name in scope, otherwise caller sets the name with the returned module object.

    const   QS = selector => document.querySelector(selector);
    const   QA = selector => document.querySelectorAll(selector);

    // Firefox's Content Security Policy for WebExtensions prohibits running any Javascript in the html page.
    // Have to wait for the page loaded event before doing anything.
    window.addEventListener("load", function(event){
        Promise.resolve()
            .then(() => setupPage() )
            .catch( e => console.warn(e) )
    });

    function setupPage() {
        let urlmap = parseUrl();
        if (urlmap.qsMap.explain)
            QS("#param-explain").textContent = urlmap.qsMap.explain;
        if (urlmap.qsMap.error)
            QS("#param-errmsg").textContent = urlmap.qsMap.error;
        if (urlmap.qsMap.url)
            QS("#param-url").value = urlmap.qsMap.url;
        if (urlmap.qsMap.title)
            document.title = urlmap.qsMap.title;
        QS("#param-url").focus();
        QS("#param-url").select();
    }

    function parseQueryString(qs) {
        return qs.split('&').reduce( (qsMap, term) => {
            var pair    = term.split('=');
            var name    = decodeURIComponent(pair[0]);
            qsMap[name] = decodeURIComponent(pair[1]) || "";
            return qsMap;
        }, {});
    }

    function parseUrl(fullUrl) {
        fullUrl = fullUrl || window.location.href;
        var uriHashParts = fullUrl.split("#");
        var url = uriHashParts[0];
        var qsParts = url.split("?");
        var qs = qsParts.length > 1 ? qsParts[1].trim() : "";
        return {
            full:   fullUrl,
            path:   qsParts[0],                                     // uri path
            qs:     qs,                                             // old query string
            qsMap:  parseQueryString(qs),                           // query map
            hash:   uriHashParts.length > 1 ? uriHashParts[1] : "", // hash
        };
    }

    return module;

}(this, "errorpage"));    // Pass in the global scope as 'this' scope.


