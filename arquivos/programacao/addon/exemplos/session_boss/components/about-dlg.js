/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// about-dlg web component
(function() {
    "use strict";

    // Import:
    // import pmc
    // import dlg
    // import jquery

    let template = pmc.parseTemplete(`
        <template>
          <style>
            @import "/pkg/spectre.css/spectre.min.css";
            @import "/pkg/spectre.css/spectre-icons.min.css";
          </style>
          <div id="modal-dlg" class="modal">
            <div class="modal-container" role="document">
              <div class="modal-header">
                <a href="javascript:void(0)" class="btn btn-clear float-right  modal-close" aria-label="Close"></a>
                <div class="modal-title h5">About the Extension</div>
              </div>
              <div class="modal-body" style="border-top:1px dotted gray; border-bottom:1px dotted gray; padding-bottom:1.8rem;">
                <div class="content">
                  <form>
                    <div class="flex-centered">
                      <div class="text-msg" >
                        <br>
                        <center style="font-size:150%;"><b><NAME></NAME></b></center>
                        <center>version: <VERSION></VERSION></center>
                        <center>Copyright 2018 <AUTHOR></AUTHOR>.  All rights reserved.</center>
                        <center></center>
                        <br>
                        <center>The following 3rd party packages are used in this software:</center>
                        <center>  jQuery, licensed under the MIT License</center>
                        <center>  Spectre.css, licensed under the MIT License</center>
                        <center>  Moment.js, licensed under the MIT License</center>
                      </div>
                    </div>
                  </form>
                </div>
              </div>
              <div class="modal-footer">
                <button class="btn btn-link modal-submit mw4">Ok</button>
              </div>
            </div>
          </div>
        </template>`);

    class ComponentElement extends HTMLElement {
        constructor() {
            super();
            this.attachShadow({mode: "open"}).appendChild(template.content.cloneNode(true));
        }

        set open(manifest) {
            dlg.open($(this.shadowRoot.querySelector("#modal-dlg"))).values(manifest).show();
        }

        connectedCallback() {}
        disconnectedCallback() {}
        adoptedCallback() {}
        attributeChangedCallback(attr, oldVal, newVal) {}
    }

    window.customElements.define("about-dlg", ComponentElement);

}());

