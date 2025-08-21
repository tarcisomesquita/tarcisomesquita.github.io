/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// dlg module

(function(scope, modulename) {
    "use strict";

    // Imports:
    // import logger
    // import appcfg

    let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    var module = function() { };        // Module object to be returned; local reference to the package object for use below.
    if (scope && modulename)
        scope[modulename] = module;     // set module name in scope, otherwise caller sets the name with the returned module object.

    // module public functions
    
    // dlgSelector          - selector for the dialog's containing html div.
    // inputValues          - map of { selector: value } to populate the dlg's input fields; return result has the values of the selectors.
    // htmlUnsafeTexts      - map of { selector: html } to set the dialog's html elements using direct .html() API, e.g. Foo<br>bar
    //                        WARNING: BE EXTRA CAREFUL SINCE IT IS UNSAFE.  DON'T PASS IN ANY UNTRUSTED HTML, LIKE UNSAFE USER INPUT.
    // elementAttributes    - map of { selector: attributes } to set the attributes of elements, i.e. title, style, maxlength, placeholder, etc.
    // clickHandlers        - map of { selector: handler } to set the onClicked handlers on the clickable elements, i.e. buttons.
    // focusSelector        - selector for the element to get the initial focus.
    class DlgOpen {
        constructor($dlgSelector) {
            this.$modal = $dlgSelector;
            this.$modal.data("clickFns", { ".modal-submit": nop, ".modal-cancel": nop });  // nop handlers on default buttons.
        }

        values(inputValues)         { populateValues(this.$modal, inputValues);             return this }
        htmls(htmlUnsafeTexts)      { populateUnsafeTexts(this.$modal, htmlUnsafeTexts);    return this }
        attrs(elementAttributes)    { populateAttributes(this.$modal, elementAttributes);   return this }
        click(clickHandlers)        { this.$modal.data("clickFns", Object.assign(this.$modal.data("clickFns"), clickHandlers)); return this }

        show(focusSelector) {
            let $modal = this.$modal;
            let clickHandlers = $modal.data("clickFns");
            Object.keys(clickHandlers).forEach( selector => $modal.find(selector).off("click").on("click", onClicked.bind(null, $modal, selector)) );
            $modal.off("keypress").on("keypress", function(e){ if (e.keyCode == 13) onEnter(e, $modal) });  // reset & reinstall handler on every call.
            $modal.off("keyup").on("keyup", function(e){ if (e.keyCode == 27) onCancel(e, $modal) });       // reset & reinstall handler on every call.
            showDlg($modal);
            $modal.find(focusSelector || ".modal-submit").focus().select();
        }
    }

    // module private functions
    
    function nop() {}
    function showDlg($modal) {  $modal.addClass("active")       }
    function hideDlg($modal) {  $modal.removeClass("active")    }

    function populateValues($modal, inputValues) {
        $modal.data("inputValues", inputValues);            // save inputValues as data in $modal so gatherInputValues() will use it later.
        for (let selectorKey in (inputValues || {})) {
            let $elem = $modal.find(selectorKey);
            if ($elem.length) {
                if ($elem.is("input") || $elem.is("textarea"))
                    $elem.val(inputValues[selectorKey]);
                else
                    $elem.text(inputValues[selectorKey]);   // safe text substitution
            }
        }
    }

    function populateUnsafeTexts($modal, htmlUnsafeTexts) {
        for (let selectorKey in (htmlUnsafeTexts || {})) {
            let $elem = $modal.find(selectorKey);
            if ($elem.length) {
                $elem.html(htmlUnsafeTexts[selectorKey]);   // unsafe html substitution
            }
        }
    }

    function populateAttributes($modal, elementAttributes) {
        for (let selectorKey in (elementAttributes || {})) {
            let $elem = $modal.find(selectorKey);
            if ($elem.length) {
                let propertiesForElem = elementAttributes[selectorKey];
                $elem.prop(propertiesForElem);
            }
        }
    }

    function gatherInputValues($modal) {
        let inputValues = $modal.data("inputValues") || {};
        Object.keys(inputValues).forEach( key => {
            let $elem = $modal.find(key);
            if ($elem.is("input:radio")) {
                $elem.each( function() {
                    if ($(this).is(":checked"))
                        inputValues[key] = $(this).val();
                });
            } else if ($elem.is("input:file")) {
                inputValues[key] = $elem.get(0).files;                  // return an array of File objects (HTML5 File type).
            } else if ($elem.is("input") || $elem.is("textarea")) {
                inputValues[key] = $elem.val();
            }
        });
        return inputValues;
    }

    function onClicked($modal, selector) {
        let clickHandlers = $modal.data("clickFns");
        if (clickHandlers[selector])
            clickHandlers[selector](gatherInputValues($modal));
        hideDlg($modal);
    }

    function onEnter(e, $modal) {
        e.preventDefault();
        let clickHandlers = $modal.data("clickFns");
        if (clickHandlers[".modal-close"])          // default to ENTER key to close if .modal-close handler is installed.
            onClicked($modal, ".modal-close");
        else
            onClicked($modal, ".modal-submit");
    }

    function onCancel(e, $modal) {
        e.preventDefault();
        onClicked($modal, ".modal-cancel");
    }

    // Module export
    module.open = (x) => new DlgOpen(x);

    return module;

}(this, "dlg"));    // Pass in the global scope as 'this' scope.

