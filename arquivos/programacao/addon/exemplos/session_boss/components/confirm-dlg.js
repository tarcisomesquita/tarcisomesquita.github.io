/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// confirm-dlg web component
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
          <div id="modal-dlg" class="modal modal-sm">
            <div class="modal-container" role="document" style="max-width: 400px;">
              <div class="modal-header">
                <a href="javascript:void(0)" class="btn btn-clear float-right  modal-close" aria-label="Close"></a>
                <div class="modal-title h5">Confirmation</div>
              </div>
              <div class="modal-body" style="border-top:1px dotted gray; border-bottom:1px dotted gray; padding-bottom:1.8rem;">
                <div class="content">
                  <form>
                    <div class="form-group">
                      <div class="text-msg" >(message)</div>
                      <input class="input-context" type="hidden">
                    </div>
                  </form>
                </div>
              </div>
              <div class="modal-footer">
                <button class="btn mw4 btn-primary modal-submit">Confirm</button>
                <button class="btn mw4             modal-cancel">Cancel</button>
              </div>
            </div>
          </div>
        </template>`);
    
    class Component extends HTMLElement {
        constructor() {
            super();
            pmc.attrsAsProperties(this, "title");
            this.attachShadow({mode: "open"}).appendChild(template.content.cloneNode(true));
        }

        set open(textMsg) {
            let $modal = $(this.shadowRoot.querySelector("#modal-dlg"));
            dlg.open($(this.shadowRoot.querySelector("#modal-dlg")))
                .values({ ".modal-title":   this.title || "Confirmation" })
                .htmls( { ".text-msg":      textMsg })
                .click( { ".modal-submit":  () => pmc.fire(this, "confirm") })
                .show(".modal-cancel");
        }

        connectedCallback() {}
        disconnectedCallback() {}
        adoptedCallback() {}
        attributeChangedCallback(attr, oldVal, newVal) {}
    }

    window.customElements.define("confirm-dlg", Component);

}());

