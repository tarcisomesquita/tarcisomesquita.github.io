/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// container module
(function(scope, modulename) {
    "use strict";

    // Import
    // none

    var module = function() { };       // Module object to be returned.
    if (scope && modulename)
        scope[modulename] = module;    // set module name in scope, otherwise caller sets the name with the returned module object.

    // Special Firefox container types.
    const CT_FIREFOX_DEFAULT = "firefox-default";
    const CT_FIREFOX_PRIVATE = "firefox-private";
    const CT_SPECIAL_TYPES = [CT_FIREFOX_DEFAULT, CT_FIREFOX_PRIVATE];

    // Colors
    const COLOR_DEFAULT = "#97999d";
    const COLOR_PRIVATE = "#8D20AE";    // purple

    // Get the containers defined in the system.
    function pGetContainerInfos() {
        return browser.contextualIdentities.query({})
            .then( contextualIdentities => {
                contextualIdentities.unshift({
                    cookieStoreId:  CT_FIREFOX_PRIVATE,
                    name:           "Private Browsing",
                    colorCode:      COLOR_PRIVATE,
                    iconUrl:        "",
                });
                contextualIdentities.unshift({
                    cookieStoreId:  CT_FIREFOX_DEFAULT,
                    name:           "General Tabs",
                    colorCode:      COLOR_DEFAULT,
                    iconUrl:        "",
                });
                return contextualIdentities;
            });
    }

    function pRecreate(container_def) {
        let existingIdSet;
        let newContainers;
        return pGetContainerInfos()
            .then( contextualIdentities => existingIdSet = new Set(contextualIdentities.map( c => c.cookieStoreId )) )
            .then( () => newContainers = container_def.filter( cdef => !existingIdSet.has(cdef.cookieStoreId) ) )
            .then( () => Promise.all(newContainers.map( c => browser.contextualIdentities.create({
                // TODO: Big problem. contextualIdentities.create() will create a new cookieStoreId every single time.
                // This makes it not portable across machines.  The cookieStoreId in tabs are not portable across machine.
                // Need to have a container management process to migrate all the tab's cookieStoreId to new cookieStoreId
                // in a new machine.
            }))) );
    }

    function is_firefox_default(id) { return id == CT_FIREFOX_DEFAULT }
    function is_firefox_private(id) { return id == CT_FIREFOX_PRIVATE }
    function is_real_container(id)  { return !is_firefox_default(id) && !is_firefox_private(id) }


    // Module exports 
    module.CT_FIREFOX_DEFAULT   = CT_FIREFOX_DEFAULT;
    module.CT_FIREFOX_PRIVATE   = CT_FIREFOX_PRIVATE;
    module.CT_SPECIAL_TYPES     = CT_SPECIAL_TYPES;
    module.COLOR_DEFAULT        = COLOR_DEFAULT;
    module.COLOR_PRIVATE        = COLOR_PRIVATE;
    module.pGetContainerInfos   = pGetContainerInfos;
    module.pRecreate            = pRecreate;
    module.is_firefox_default   = is_firefox_default;
    module.is_firefox_private   = is_firefox_private;
    module.is_real_container    = is_real_container;

    return module;

}(this, "container"));    // Pass in the global scope as 'this' scope.

