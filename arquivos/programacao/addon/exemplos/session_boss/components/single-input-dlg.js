/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// single-input-dlg web component
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
                <div class="modal-title h5"></div>
              </div>
              <div class="modal-body" style="border-top:1px dotted gray; border-bottom:1px dotted gray; padding-bottom:1.8rem;">
                <div class="content">
                  <form>
                    <div class="form-group">
                      <label class="form-label" for="input-value"></label>
                      <input class="form-input input-value" type="text">
                    </div>
                  </form>
                </div>
              </div>
              <div class="modal-footer">
                <button class="btn mw4 btn-primary modal-submit">Save</button>
                <button class="btn mw4             modal-cancel">Cancel</button>
              </div>
            </div>
          </div>
        </template>`);
    
    class Component extends HTMLElement {
        constructor() {
            super();
            pmc.attrsAsProperties(this, "title", "label", "maxlength", "placeholder");
            this.attachShadow({mode: "open"}).appendChild(template.content.cloneNode(true));
        }

        set open(existingValue) {
            dlg.open($(this.shadowRoot.querySelector("#modal-dlg")))
                .values({ ".modal-title":   this.title || "Confirmation" })
                .values({ ".form-label":    this.label || "Label" })
                .values({ ".input-value":   existingValue })
                .attrs( { ".input-value":   { maxlength: this.maxlength || "", placeholder: this.placeholder || "" } })
                .click( { ".modal-submit":  inputValues => pmc.fire(this, "save", inputValues) })
                .show("input:text:first");
        }

        connectedCallback() {}
        disconnectedCallback() {}
        adoptedCallback() {}
        attributeChangedCallback(attr, oldVal, newVal) {}
    }

    window.customElements.define("single-input-dlg", Component);

}());

