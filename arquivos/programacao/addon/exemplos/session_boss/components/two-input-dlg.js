/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// two-input-dlg web component
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
              <div class="modal-body" style="border-top:1px dotted gray; border-bottom:1px dotted gray; padding-bottom:1.5rem;">
                <div class="content">
                  <form>
                    <div class="form-group">
                      <label      class="form-label  input-label1" for="input-value1">Label1</label>
                      <textarea   class="form-input  input-value1" rows="1"></textarea>
                      <label      class="form-label  input-label2 mt-2" for="input-value2">Label2</label>
                      <textarea   class="form-input  input-value2" rows="2"></textarea>
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
            pmc.attrsAsProperties(this, "title", "label1", "label2", "textRows1", "textRows2");
            this.attachShadow({mode: "open"}).appendChild(template.content.cloneNode(true));
        }

        set open(inputs) {
            dlg.open($(this.shadowRoot.querySelector("#modal-dlg")))
                .values({ ".modal-title":   this.title || "Title",
                          ".input-label1":  this.label1 || "Label",
                          ".input-value1":  inputs[".input-value1"],
                          ".input-label2":  this.label2 || "Label",
                          ".input-value2":  inputs[".input-value2"] })
                .attrs( { ".input-value1":  {rows: this.textRows1 || ""},
                          ".input-value2":  {rows: this.textRows2 || ""} })
                .click( { ".modal-submit": inputValues => pmc.fire(this, "save", inputValues) })
                .show(".input-value1");
        }
        
        connectedCallback() {}
        disconnectedCallback() {}
        adoptedCallback() {}
        attributeChangedCallback(attr, oldVal, newVal) {}
    }

    window.customElements.define("two-input-dlg", Component);

}());

