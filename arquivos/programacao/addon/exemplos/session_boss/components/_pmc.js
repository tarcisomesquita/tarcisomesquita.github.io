/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

/*
pmc module - Poor Man's Component framework for web.
The js file is named with leading _ to distinguish it from the actual component js files.

Documentation for building a web component.
- Put the html template and the component class in the same js file.
- The component element class extends from HTMLElement and should handle the event callbacks, e.g. connectedCallback()
- Register the custom tag and component element class with window.customElements.define().  e.g. <my-tag>
- The template is cloned to each instant of the custom tag and attached as a shadow DOM underneath it.
- The shadow DOM is isolated from the rest of DOM; cannot access outside CSS.  Use @import in the template for shared style files.
- Declarative parameters are passed in via attributes when the custom tag is used.  e.g. <my-tag param1="123" ...>
- The component class accesses the parameters with this.getAttribute("param1") in connectedCallback().
- Component element properties can be defined with setter/getter.
- Runtime data can be sent in using property setter.  e.g. $("#my-tag1")[0].open = true
- Component data can be emitted via CustomEvent.  Component.this.dispatchEvent(new CustomEvent("status", { detail: 123 }))
- User of custom tag can listen on the event.  $("#my-tag1").on("status", function()...)
- Slots can be used to pass in html fragment to the component.
- On the page, include _pmc.js first and then the component js files before using the custom tags.
- pmc.subscribe(), pmc.publish(), and pmc.unsubscribe() are the API of the simple pub/sub system provided by pmc.
*/
(function(scope, modulename) {
    "use strict";

    // Import:
    // no dependency

    if (!window) throw Error("No 'window' object defined.  Not in a browser environment.");
    if (!window["customElements"]) throw Error("No window.customElements defined.  Custom elements are not supported.");

    var module = function() {};
    if (scope && modulename)
        scope[modulename] = module;

    // Parse template string into a DOM node.
    function parseTemplete(componentTemplateHtml) {
        // Parse the <template> html.  Resolve the @import statements in the <template> as well.
        let templateDoc = new DOMParser().parseFromString(componentTemplateHtml, "text/html");
        let templateNodes = templateDoc.getElementsByTagName("template");
        if (templateNodes.length < 1) throw Error("Component template html has no <template> tag.");
        return templateNodes[0];
    }

    // Reflect the attribute as a property, creating the property setter and getter.
    // This allows access to attribues as properties on the component element. i.e. dom.prop1, dom.prop1 = 123
    function attrAsProperty(componentElement, attribute, property) {
        let desc = Object.getOwnPropertyDescriptor(componentElement, property);
        if ((desc && desc.get) || (desc && desc.set))
            return;

        Object.defineProperty(componentElement, property, {
            get: function()     { return componentElement.getAttribute(attribute) },
            set: function(val)  { componentElement.setAttribute(attribute, val) }
        });
    }

    // Reflect the attributes, with the attribute name as the property name.  Attr names must be valid JS identifier.
    function attrsAsProperties(componentElement, ...attributes) {
        attributes.forEach( attr => attrAsProperty(componentElement, attr, attr) );
    }

    // Fire a custom event on the target element.
    function fire(targetElement, eventType, eventData) {
        targetElement.dispatchEvent(new CustomEvent(eventType, { detail: eventData }) );
    }

    function setCssVar(element, cssVar, value) {
        element.style.setProperty(cssVar, value);
    }


    // A simple pub/sub system in about a dozen lines.
    let topicSubscriptions = {};        // List of subscriptions per topic.
    let subscriptionId = 1;             // Track the subscriptionId sequence number.

    function subscribe(topic, onPublishedFn) {
        topicSubscriptions[topic] = Object.assign({}, topicSubscriptions[topic]);
        topicSubscriptions[topic][subscriptionId] = onPublishedFn;
        return subscriptionId++;
    }

    function unsubscribe(topic, subId) {
        if (!topic) topicSubscriptions = {};                                    // clear subscriptions on all topics
        if (!subId) delete topicSubscriptions[topic];                           // clear subscriptions on the topic
        if (topicSubscriptions[topic]) delete topicSubscriptions[topic][subId]; // clear the subscription on the topic
    }

    function oneoff(topic, onPublishedFn) {
        let id = subscribe(topic, (...data) => { onPublishedFn(...data); unsubscribe(topic, id) }); // unsubscribe after one-off publish().
    }

    function publish(topic, ...data) {
        Object.values(topicSubscriptions[topic] || {}).forEach(onPublishedFn => onPublishedFn(...data));
    }
    // End of pub/sub system


    // Module export
    module.parseTemplete = parseTemplete;
    module.attrAsProperty = attrAsProperty;
    module.attrsAsProperties = attrsAsProperties;
    module.fire = fire;
    module.setCssVar = setCssVar;
    module.subscribe = subscribe;
    module.unsubscribe = unsubscribe;
    module.oneoff = oneoff;
    module.publish = publish;

    return module;

}(this, "pmc"));


// Unit Tests
let _RUNTEST_PUBSUB = false;
if (_RUNTEST_PUBSUB) {
    console.log("Run unit tests");

    let subFoo = pmc.subscribe("foo", (...x) => console.log("foo subFoo", x));
    pmc.publish("foo", 1, 2, 3);
    pmc.publish("foo");
    console.log("unsubscribe(foo)");
    pmc.unsubscribe("foo", subFoo);
    pmc.publish("foo", 123);

    console.log("3 subs");
    let sub1 = pmc.subscribe("foo", (...x) => console.log("foo sub1", x));
    let sub2 = pmc.subscribe("foo", (...x) => console.log("foo sub2", x));
    let sub3 = pmc.subscribe("bar", (...x) => console.log("bar sub3", x));
    pmc.publish("foo", 1, 2, 3);
    pmc.publish("foo", 4, 5, 6);
    pmc.publish("bar", 123);
    pmc.publish("bar", 456);

    console.log("unsubscribe(sub1)");
    pmc.unsubscribe(sub1);
    pmc.publish("foo", 1, 2, 3);
    pmc.publish("bar", 123);

    console.log("unsubscribe(foo)");
    pmc.unsubscribe("foo");
    pmc.publish("foo", 1, 2, 3);
    pmc.publish("bar", 123);

    console.log("unsubscribe()");
    pmc.unsubscribe();
    pmc.publish("foo", 1, 2, 3);
    pmc.publish("bar", 123);

    console.log("oneoff");
    pmc.oneoff("baz", (...x) => console.log("baz", x));
    pmc.publish("baz", 1, 2, 3);
    pmc.publish("baz", 1, 2, 3);
    pmc.publish("baz", 1, 2, 3);
}

