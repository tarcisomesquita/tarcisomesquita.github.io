(function(_ds){var window=this;'use strict';var Lba=function(a){var b=a.Ct,c="";a=Math.max(0,Math.ceil(a.Sr-1));for(var d=0;d<a;d++)c+='<div class="devsite-spinner__layer devsite-spinner__layer-'+_ds.Y(1+d)+'"'+(b?' style="border-color: '+_ds.Y(_ds.OE(b))+';"':"")+'><div class="devsite-spinner__circle-clipper devsite-spinner__left"><div class="devsite-spinner__circle"></div></div><div class="devsite-spinner__gap-patch"><div class="devsite-spinner__circle"></div></div><div class="devsite-spinner__circle-clipper devsite-spinner__right"><div class="devsite-spinner__circle"></div></div></div>';
return(0,_ds.U)(c)},Y7=function(){return _ds.Yh.apply(this,arguments)||this};_ds.w(Y7,_ds.Yh);Y7.prototype.connectedCallback=function(){var a;if(this.hasAttribute("single-color")){var b=this.getAttribute("single-color");b&&b.startsWith("#")&&(a=b)}_ds.$E(this,Lba,{Sr:5,Ct:a});if(a=this.getAttribute("size"))this.style.width=a+"px",this.style.height=a+"px"};Y7.prototype.connectedCallback=Y7.prototype.connectedCallback;try{window.customElements.define("devsite-spinner",Y7)}catch(a){console.warn("devsite.app.customElement.DevsiteSpinner",a)};})(_ds_www);