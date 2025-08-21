/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// popup-msg web component
(function() {
    "use strict";

    // Import:
    // import pmc
    // import dlg
    // import jquery

    let template = pmc.parseTemplete(`
        <template>
          <style>
            #msgbar {
                --popup-delay:      5s;
                visibility:         hidden;
                min-width:          600px;
                margin-left:        -300px;
                background-color:   gray;
                color:              white;
                text-align:         center;
                border-radius:      4px;
                padding:            8px 16px;
                position:           fixed;
                z-index:            100;
                left:               50%;
                bottom:             30px;
                cursor:             pointer;
            }
            #msgbar.show {
                visibility:         visible;
                animation:          msgbar-fadein 0.5s, msgbar-fadeout 0.5s var(--popup-delay);    /* fade in/out 0.5s; delay with --popup-delay amount */
            }
            @keyframes msgbar-fadein {
                from {bottom: 0;    opacity: 0;}
                to   {bottom: 30px; opacity: 1;}
            }
            @keyframes msgbar-fadeout {
                from {bottom: 30px; opacity: 1;}
                to   {bottom: 0;    opacity: 0;}
            }

          </style>
          <div id="msgbar"></div>
        </template>`);

    class ComponentElement extends HTMLElement {
        constructor() {
            super();
            pmc.attrAsProperty(this, "delay", "delay");
            this.attachShadow({mode: "open"}).appendChild(template.content.cloneNode(true));
        }

        set open(msg) {
            let msgbar = this.shadowRoot.querySelector("#msgbar");
            let delaySec = this.getAttribute("delay") || 5;
            pmc.setCssVar(msgbar, "--popup-delay", delaySec + "s");
            $(msgbar)
                .on("click", function(){ $(this).text("").removeClass("show").off("click") })
                .text(msg).addClass("show")
                .delay(delaySec * 1000 + 500)
                .queue(  function(next){ $(this).text("").removeClass("show").off("click"); next() } );
        }

        connectedCallback() {}
        disconnectedCallback() {}
        adoptedCallback() {}
        attributeChangedCallback(attr, oldVal, newVal) {}
    }

    window.customElements.define("popup-msg", ComponentElement);

}());

