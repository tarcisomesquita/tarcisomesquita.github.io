(function(_ds){var window=this;'use strict';var L6=function(){return _ds.Yh.apply(this,arguments)||this},M6=function(a){_ds.aj(a);switch(a.getAttribute("type")){case "indeterminate":var b=a.getAttribute("color"),c=document.createElement("div");c.classList.add("devsite-progress--indeterminate");for(var d=1;4>=d;d++){var e=document.createElement("div");e.classList.add("devsite-progress--indeterminate-"+d);!b||1!=d&&3!=d||(e.style.backgroundColor=b);c.appendChild(e)}a.appendChild(c)}};_ds.w(L6,_ds.Yh);
L6.prototype.connectedCallback=function(){M6(this)};L6.prototype.attributeChangedCallback=function(a,b,c){b!==c&&M6(this)};_ds.ja.Object.defineProperties(L6,{observedAttributes:{configurable:!0,enumerable:!0,get:function(){return["color","type"]}}});L6.prototype.attributeChangedCallback=L6.prototype.attributeChangedCallback;L6.prototype.connectedCallback=L6.prototype.connectedCallback;try{window.customElements.define("devsite-progress",L6)}catch(a){console.warn("devsite.app.customElement.DevsiteProgress",a)};})(_ds_www);