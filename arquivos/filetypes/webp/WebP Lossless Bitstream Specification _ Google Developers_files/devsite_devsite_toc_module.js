(function(_ds){var window=this;'use strict';var Dca=function(a){var b=a.Nt,c=a.Sb,d=a.Rp;a=a.Ir;var e='<ul class="devsite-nav-list"><li class="devsite-nav-item devsite-nav-heading devsite-toc-toggle" role="heading" aria-level="2"><span class="devsite-nav-title"><span class="devsite-nav-text">On this page</span></span>';c&&(e=e+'<button type="button" title="'+_ds.qE("Expand/collapse contents"),e+='" class="devsite-nav-show-all button-transparent material-icons"></button>');e+="</li>";for(var f=b.length,k=0;k<f;k++){var l=b[k];e+=
'<li class="devsite-nav-item"'+(c&&l.index<a?" visible":"")+'><a href="#'+_ds.Y(l.id)+'" class="devsite-nav-title gc-analytics-event" data-category="Site-Wide Custom Events" data-action="click" data-label="'+(c?"Embedded nav":"Right nav")+'" data-value="'+_ds.Y(k)+'" track-type="navigation" track-name="'+(c?"embeddedNav":"rightNav")+'" track-metadata-position="'+_ds.Y(k)+'" track-metadata-link-destination="#'+_ds.Y(l.id)+'"><span class="devsite-nav-text" tooltip>'+_ds.gE(l.text)+"</span></a>";if(_ds.hE(l.children).length){e+=
'<ul class="devsite-nav-list">';l=l.children;for(var m=l.length,n=0;n<m;n++){var p=l[n];e+='<li class="devsite-nav-item"'+(c&&p.index<a?" visible":"")+'><a href="#'+_ds.Y(p.id)+'" class="devsite-nav-title gc-analytics-event" data-category="Site-Wide Custom Events" data-action="click" data-label="'+(c?"Embedded nav":"Right nav")+'" data-value="'+_ds.Y(k)+"."+_ds.Y(n)+'" track-type="navigation" track-name="'+(c?"embeddedNav":"rightNav")+'" track-metadata-position="'+_ds.Y(k)+"."+_ds.Y(n)+'" track-metadata-link-destination="#'+
_ds.Y(p.id)+'"><span class="devsite-nav-text" tooltip>'+_ds.gE(p.text)+"</span></a></li>"}e+="</ul>"}e+="</li>"}d&&(e=c?e+'<li class="devsite-nav-item devsite-apix-link"><a href="#try-it" class="devsite-nav-title"><span class="devsite-nav-text" tooltip>Try it</span></a></li>':e+'<button type="button" class="devsite-show-apix button-primary">Try it!</button>');c&&(e=e+'<li class="devsite-toc-toggle"><button type="button" class="button-flat devsite-nav-more-items material-icons" track-type="navigation" track-name="embeddedNavExpand" title="'+
_ds.qE("Expand/collapse contents"),e+='"></button></li>');return(0,_ds.U)(e+"</ul>")},E8=function(){var a=_ds.Yh.call(this)||this;a.eventHandler=new _ds.Sl;a.K=new _ds.Zl;a.D=new Set;a.G=new Map;a.M=new _ds.Pl(function(){return void D8(a)},16);a.L=new _ds.Pl(function(){return void Eca(a)},33);a.v=null;a.m=null;a.h=[];a.H=!1;a.C=null;a.Sb=!1;a.J=[];a.ic((0,_ds.Mg)(Fca),(0,_ds.Mg)(Gca),(0,_ds.Mg)(Hca),(0,_ds.Mg)(Ica),(0,_ds.Mg)(Jca),(0,_ds.Mg)(Kca));return a},Lca=function(a){_ds.P(a,function c(){var d=
this,e,f,k,l;return _ds.G(c,function(m){switch(m.j){case 1:e=d;if(!("IntersectionObserver"in _ds.Ui())){m.F(2);break}d.C&&d.C.disconnect();f=document.querySelector("devsite-header");k=152;if(!f){m.F(3);break}return _ds.y(m,window.customElements.whenDefined("devsite-header"),4);case 4:(l=Number(f.getAttribute("top-row--height"))+Number(f.getAttribute("bottom-row--height")))&&(k=l);case 3:d.C=new IntersectionObserver(function(n){n=_ds.q(n);for(var p=n.next();!p.done;p=n.next())p=p.value,p.isIntersecting?
e.D.add(p.target):e.D.delete(p.target);e.L.Ea()},{rootMargin:k+"px 0px 0px 0px",threshold:[0,1]});case 2:d.K.resolve(),_ds.z(m)}})})},Eca=function(a){return _ds.P(a,function c(){var d=this;return _ds.G(c,function(e){if(1==e.j)return _ds.y(e,Mca(d),2);if(d.m){var f="#"+d.m.id,k=encodeURI(f);f=d.G.get(f)||d.G.get(k);d.v!==f&&(d.v&&d.v.classList.remove("devsite-nav-active"),f&&(f.classList.add("devsite-nav-active"),d.v=f))}_ds.z(e)})})},D8=function(a){if(!a.hasAttribute("disabled")){var b=document.querySelector("devsite-content .devsite-article-body");
b?(a.Sb?a.classList.add("devsite-toc-embedded"):a.classList.add("devsite-toc"),Nca(a,b),a.H=!0):a.mb()}},Nca=function(a,b){var c=[],d=!1,e="";switch(a.getAttribute("depth")){case "1":e="h2:not(.hide-from-toc):not(#contents):not(#table-of-contents)";break;default:e="h2:not(.hide-from-toc):not(#contents):not(#table-of-contents), h3:not(.hide-from-toc):not(#contents):not(#table-of-contents)"}a.h=[].concat(_ds.ta(b.querySelectorAll(e))).filter(function(k){return k.id&&k.dataset.text}).filter(function(k){return Oca(k)});
b=_ds.q(a.h.entries());for(e=b.next();!e.done;e=b.next()){var f=_ds.q(e.value);e=f.next().value;f=f.next().value;e={id:f.id,level:f.tagName.toLowerCase(),text:f.dataset.text,children:[],index:e};"h2"===e.level?(c.push(e),d=!0):d?c[c.length-1].children.push(e):c.push(e)}_ds.ac(a.J,c,a.xk.bind(a))&&a.H||(c.length?(Pca(a,c),a.show(),a.Sb||Qca(a)):a.mb(),a.J=c)},Mca=function(a){return _ds.P(a,function c(){var d=this,e,f,k,l,m,n,p,r;return _ds.G(c,function(t){switch(t.j){case 1:e=d;f=0;k=document.querySelector("devsite-header");
if(!k){t.F(2);break}return _ds.y(t,window.customElements.whenDefined("devsite-header"),3);case 3:f=k.Rh();case 2:l=d.h.findIndex(function(u){return e.D.has(u)&&u.getBoundingClientRect().top>=f});m=d.h[l];if(!m){d.m&&d.m.getBoundingClientRect().top>window.innerHeight&&(n=d.h.indexOf(d.m),0<n&&(d.m=d.h[n-1]));t.F(0);break}return _ds.y(t,Rca(d),5);case 5:p=t.h,r=m.getBoundingClientRect().top-f,d.m=r>p&&0<l?d.h[l-1]:m,_ds.z(t)}})})},Rca=function(a){return _ds.P(a,function c(){var d,e,f,k;return _ds.G(c,
function(l){if(1==l.j)return e=d=0,(f=document.querySelector("devsite-header"))?_ds.y(l,window.customElements.whenDefined("devsite-header"),3):l.F(2);2!=l.j&&(d=f.Rh(),e=f.Eq());k=window.innerHeight-d;return l.return(Math.max(e-d,Math.floor(k/5)))})})},Qca=function(a){_ds.P(a,function c(){var d=this,e,f,k;return _ds.G(c,function(l){if(1==l.j)return _ds.y(l,d.K.promise,2);if(!d.C)return l.return();d.C.disconnect();d.D.clear();d.v&&d.v.classList.remove("devsite-nav-active");d.v=null;e=_ds.q(d.h);for(f=
e.next();!f.done;f=e.next())k=f.value,d.C.observe(k);_ds.z(l)})})},Oca=function(a){return _ds.YM.find(function(b){return!!_ds.Gj(a,b,6)})||_ds.Fj(a,"devsite-selector",null,6)||_ds.Gj(a,"devsite-dialog",3)?!1:!0},Pca=function(a,b){var c=_ds.aF(Dca,{Nt:b,Sb:a.Sb,Rp:!!document.body.querySelector("devsite-apix, .devsite-apix"),Ir:5});b=_ds.q(c.querySelectorAll("a.devsite-nav-title"));for(var d=b.next();!d.done;d=b.next()){d=d.value;var e=d.hash,f=encodeURI(d.hash);a.G.set(e,d);a.G.set(f,d)}_ds.aj(a);
a.Sb&&_ds.Zh(a,"hidden","",c);a.appendChild(c);if(a.Sb){if(8<=a.getElementsByClassName("devsite-nav-item").length){b=_ds.q(a.querySelectorAll(".devsite-nav-show-all, .devsite-nav-more-items"));for(d=b.next();!d.done;d=b.next())a.eventHandler.listen(d.value,"click",function(){a.hasAttribute("expanded")?a.removeAttribute("expanded"):_ds.Zh(a,"expanded","")});_ds.Zh(a,"expandable","")}setTimeout(function(){c.removeAttribute("hidden")},0)}};var Fca=_ds.sa(["disabled"]),Gca=_ds.sa(["has-sidebar"]),Hca=_ds.sa(["hidden"]),Ica=_ds.sa(["expandable"]),Jca=_ds.sa(["expanded"]),Kca=_ds.sa(["visible"]);_ds.w(E8,_ds.Yh);_ds.g=E8.prototype;_ds.g.connectedCallback=function(){this.Sb=this.hasAttribute("devsite-toc-embedded");D8(this);this.Z()};_ds.g.disconnectedCallback=function(){this.mb();this.H=!1;_ds.Yl(this.eventHandler)};
_ds.g.Z=function(){var a=this;this.Sb||this.eventHandler.listen(document.body,"devsite-content-updated devsite-element-hidden devsite-element-visible devsite-page-loaded devsite-sticky-resize devsite-sticky-scroll".split(" "),function(){a.L.Ea()});this.eventHandler.listen(document.body,"devsite-content-updated",function(){D8(a)})};_ds.g.Vf=function(a){a=a&&"false"===a.toLowerCase();this.J=[];_ds.aj(this);a?(_ds.Zh(this,"disabled",""),this.mb()):(this.removeAttribute("disabled"),this.show(),this.M.Ea())};
_ds.g.mb=function(){_ds.aj(this);this.dispatchEvent(new CustomEvent("devsite-element-hidden",{bubbles:!0}));this.removeAttribute("visible");_ds.Zh(this,"hidden","");if(!this.Sb){var a=document.querySelector(".devsite-main-content");a&&a.removeAttribute("has-sidebar")}};
_ds.g.show=function(){this.dispatchEvent(new CustomEvent("devsite-element-visible",{bubbles:!0}));this.removeAttribute("hidden");_ds.Zh(this,"visible","");if(!this.Sb){var a=document.querySelector(".devsite-main-content");a&&_ds.Zh(this,"has-sidebar","",a);Lca(this)}};_ds.g.xk=function(a,b){var c=!0;if(a.children.length||b.children.length)c=_ds.ac(a.children,b.children,this.xk.bind(this));return c&&a.id===b.id&&a.text===b.text};
_ds.ja.Object.defineProperties(E8,{observedAttributes:{configurable:!0,enumerable:!0,get:function(){return["max-height","offset"]}}});E8.prototype.renderUpdatedContent=E8.prototype.Vf;E8.prototype.disconnectedCallback=E8.prototype.disconnectedCallback;E8.prototype.connectedCallback=E8.prototype.connectedCallback;try{window.customElements.define("devsite-toc",E8)}catch(a){console.warn("Unrecognized DevSite custom element - DevsiteToc",a)};})(_ds_www);