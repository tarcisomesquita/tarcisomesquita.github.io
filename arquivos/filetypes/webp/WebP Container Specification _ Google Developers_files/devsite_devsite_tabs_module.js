(function(_ds){var window=this;'use strict';var Tba=function(a){var b=a.gj;a=a.columns;for(var c='<div class="dropdown-tabbed-menu"><ul class="dropdown-tabbed-menu-list">',d=a.length,e=0;e<d;e++){var f=a[e];c+='<li class="dropdown-tabbed-menu-list-item"><a href="#" column-id="'+_ds.Y(f.Qp)+'" tabindex="0" track-type="nav" track-name="'+_ds.Y(f.text)+'" track-metadata-eventdetail="#" track-metadata-position="nav - '+_ds.Y(b)+'" track-metadata-module="secondary nav">'+_ds.gE(f.text)+"</a></li>"}return(0,_ds.U)(c+"</ul></div>")},
Uba=function(a){var b=a.gj,c=a.href;a=a.text;return(0,_ds.U)('<div class="dropdown-tabbed-menu-button"><a href="'+_ds.Y(_ds.JE(c))+'" track-type="nav" track-name="'+_ds.Y(a)+'" track-metadata-eventdetail="'+_ds.Y(c)+'" track-metadata-position="nav - '+_ds.Y(b)+'" track-metadata-module="secondary nav">'+_ds.gE(a)+"</a></div>")},f8=function(){var a=_ds.Yh.call(this)||this;a.M=20;a.eventHandler=new _ds.Sl;a.m=new _ds.Sl;a.J=new _ds.Pl(function(){e8(a)},a.M);a.K=null;a.C=null;a.H=!1;a.G=0;a.h=null;a.D=
null;a.L=0;a.Sc=[];a.v=null;a.ic(a.j(Vba),a.j(Wba),a.j(Xba),a.j(Yba),a.j(Zba),a.j($ba),a.j(aca),a.j(bca),a.j(cca),a.j(dca),a.j(eca),a.j(fca),a.j(gca),a.j(hca),a.j(ica),a.j(jca));return a},kca=function(a){return _ds.P(a,function c(){var d,e=this;return _ds.G(c,function(f){if(1==f.j)return _ds.y(f,(0,_ds.ao)(),2);d=f.h;if(d.isTouchEnabled())return f.return();g8(e,300);_ds.z(f)})})},lca=function(a,b){return _ds.P(a,function d(){var e,f=this;return _ds.G(d,function(k){if(1==k.j)return _ds.y(k,(0,_ds.ao)(),
2);e=k.h;if(e.isTouchEnabled())return k.return();h8(f,b);_ds.z(k)})})},h8=function(a,b){var c,d=b.target,e=a.Af(d);e&&(e===a.h||(null===(c=a.h)||void 0===c?0:c.contains(d))?i8(a,b):j8(a,e))},g8=function(a,b){b=void 0===b?0:b;_ds.Yl(a.m);window.clearTimeout(a.G);var c=a.querySelector("tab[dropdown--open]");if(c){var d=c.querySelector(".devsite-tabs-dropdown");_ds.Zh(a,"dropdown-transition","",d);_ds.Wl(a.m,d,_ds.IM,function(){null===d||void 0===d?void 0:d.removeAttribute("dropdown-transition");a.removeAttribute("dropdown--open");
_ds.Zh(a,"hidden","",d)});a.G=window.setTimeout(function(){c.removeAttribute("dropdown--open");k8(a,c)},b)}else a.removeAttribute("dropdown--open");l8(a)},j8=function(a,b){_ds.P(a,function d(){var e=this,f,k,l,m,n,p,r,t,u,v,x,B;return _ds.G(d,function(D){if(1==D.j){f=e;l8(e);if(!b.hasAttribute("dropdown"))return g8(e),D.return();_ds.Yl(e.m);window.clearTimeout(e.G);return b.hasAttribute("dropdown--open")?D.return():_ds.y(D,(0,_ds.ao)(),2)}k=D.h;k.isTouchEnabled()&&_ds.Wl(e.m,document.body,"click",
function(C){f.contains(C.target)||g8(f)});l=e.querySelector("tab[dropdown--open]");m=b.querySelector(".devsite-tabs-dropdown");if(!m)return l&&(l.removeAttribute("dropdown--open"),k8(e,l)),D.return();m.removeAttribute("hidden");_ds.bm(m,"left","");n=_ds.Pi(window||window);p=Array.from(m.querySelectorAll(".devsite-tabs-dropdown-column"));!b.hasAttribute("dropdown-full")&&1<p.length&&(r=[],p.forEach(function(C){r.push(C.scrollWidth)}),t=Math.max.apply(null,r),u=t*p.length,u<n.width?p.forEach(function(C){_ds.bm(C,
"width",t+"px")}):_ds.Zh(e,"dropdown-full","",b));v=m.getBoundingClientRect();b.hasAttribute("dropdown-full")?_ds.bm(m,"left","-"+v.left+"px"):(x=Math.min(v.left,v.left+v.width-n.width),0<x&&_ds.bm(m,"left","-"+x+"px"));l?(l.removeAttribute("dropdown--open"),k8(e,l),B=l.querySelector(".devsite-tabs-dropdown"),null===B||void 0===B?void 0:B.removeAttribute("dropdown-transition"),_ds.Zh(e,"hidden","",B)):(_ds.Zh(e,"dropdown-transition","",m),_ds.Wl(e.m,m,_ds.IM,function(){return m.removeAttribute("dropdown-transition")}));
window.requestAnimationFrame(function(){_ds.Zh(f,"dropdown--open","");_ds.Zh(f,"dropdown--open","",b);k8(f,b)});_ds.z(D)})})},i8=function(a,b){var c;_ds.P(a,function e(){var f=this,k,l,m;return _ds.G(e,function(n){switch(n.j){case 1:return k=f,b.preventDefault(),b.stopPropagation(),document.body.dispatchEvent(new CustomEvent("devsite-close-overflow-tabs")),_ds.y(n,_ds.Rk(),2);case 2:return f.hasAttribute("overflow-menu--open")?n.return():_ds.y(n,(0,_ds.ao)(),3);case 3:return l=n.h,_ds.y(n,l.whenReady(),
4);case 4:l.isTouchEnabled()&&(m=function(p){k.contains(p.target)||l8(k);_ds.Xl(k.m,document.body,["devsite-close-overflow-tabs","click"],m)},f.m.listen(document.body,["devsite-close-overflow-tabs","click"],m)),null===(c=f.D)||void 0===c?void 0:c.removeAttribute("hidden"),_ds.Zh(f,"overflow-menu--open",""),_ds.z(n)}})})},l8=function(a){_ds.Zh(a,"hidden","",a.D);a.removeAttribute("overflow-menu--open")},e8=function(a){var b,c,d;_ds.Zh(a,"hidden","",a.h);if(!(a.Sc&&3>a.Sc.length)){var e=m8(a,a);if(0!==
e){var f=(null===(b=a.Sc)||void 0===b?void 0:b.slice())||[],k=0,l;f.forEach(function(t){t.parentNode!==a.v&&(l?_ds.cj(t,l):_ds.dj(a.v,t,0));l=t;k+=m8(a,t)});if(!(k<=e)){var m=a.L;null===(c=a.h)||void 0===c?void 0:c.removeAttribute("hidden");var n=a.querySelector("[active]");for(n&&(m+=m8(a,n));null===f||void 0===f?0:f.length;){var p=f.shift();if(p!==n){var r=m8(a,p||null);m+r<=e?m+=r:null===(d=a.D)||void 0===d?void 0:d.appendChild(p)}}}}}},m8=function(a,b){if(!b)return 0;for(var c=[],d=b;d.parentElement&&
0===d.offsetWidth;)c.push(d),_ds.Zh(a,"render-hidden","",d),d=d.parentElement;a=_ds.tm(b).width;c=_ds.q(c);for(b=c.next();!b.done;b=c.next())b.value.removeAttribute("render-hidden");return a},k8=function(a,b){_ds.Zh(a,"aria-expanded",""+b.hasAttribute("dropdown--open"),b.querySelector(".devsite-tabs-dropdown-toggle"))},mca=function(a,b){return _ds.P(a,function d(){var e;return _ds.G(d,function(f){if(1==f.j)return _ds.y(f,(0,_ds.ao)(),2);e=f.h;return e.isTouchEnabled()||!b.hasAttribute("generated-tab-menu")?
f.return(!1):f.return(!0)})})},oca=function(a){var b;null===(b=a.Sc)||void 0===b?void 0:b.forEach(function(c,d){return _ds.P(a,function f(){var k=this,l,m,n,p,r,t,u,v,x;return _ds.G(f,function(B){if(1==B.j)return l=k,_ds.y(B,mca(k,c),2);m=B.h;if(!m)return B.return();n=Array.from(c.querySelectorAll(".devsite-tabs-dropdown-column"));p=c.querySelector(".devsite-tabs-dropdown");r=c.querySelector("a");n.forEach(function(D,C){_ds.Zh(l,"column-id","tab-"+d+"-column-"+C,D)});t=n.map(function(D){var C=D.querySelector(".devsite-nav-title")||
D.querySelector(".devsite-nav-item-title");return{Qp:D.getAttribute("column-id"),text:null===C||void 0===C?void 0:C.textContent}});r&&(u=_ds.aF(Tba,{gj:(r.textContent||"").toLowerCase().trim(),columns:t}),p&&(v=c.querySelector(".devsite-tabs-dropdown-content")))&&(p.insertBefore(u,v),x=c.querySelector(".dropdown-tabbed-menu a"),nca(c),k.eventHandler.listen(u,"click",function(D){D.preventDefault();var C=c.querySelector(".dropdown-tabbed-menu-button");D=D.target;C&&D.tagName&&"a"===D.tagName.toLowerCase()&&
!C.contains(D)&&n8(l,c,(null===D||void 0===D?void 0:D.getAttribute("column-id"))||"")}),x&&n8(k,c,x.getAttribute("column-id")||""));_ds.z(B)})})})},n8=function(a,b,c){var d=Array.from(b.querySelectorAll(".devsite-tabs-dropdown-column"));b=Array.from(b.querySelectorAll(".dropdown-tabbed-menu a"));b.forEach(function(e){return e.removeAttribute("active")});d.forEach(function(e){return _ds.Zh(a,"hidden","",e)});b=b.find(function(e){return e.getAttribute("column-id")===c});d=d.find(function(e){return e.getAttribute("column-id")===
c});b&&d&&(_ds.Zh(a,"active","",b),d.removeAttribute("hidden"))},nca=function(a){var b=a.querySelector(".dropdown-tabbed-menu-button-target");if(!a.querySelector(".dropdown-tabbed-menu-button")&&b){var c=a.querySelector("a");c&&(c=c.textContent,b=b.querySelector(".devsite-nav-item a"),a=a.querySelector(".dropdown-tabbed-menu"),b&&(c=_ds.aF(Uba,{gj:(c||"").toLowerCase().trim(),href:b.getAttribute("href")||"",text:b.textContent||""}),null===a||void 0===a?void 0:a.appendChild(c)))}};var Vba=_ds.sa(["active"]),Wba=_ds.sa(["aria-expanded"]),Xba=_ds.sa(["aria-selected"]),Yba=_ds.sa(["collapsed"]),Zba=_ds.sa(["column-id"]),$ba=_ds.sa(["connected"]),aca=_ds.sa(["dropdown"]),bca=_ds.sa(["dropdown-full"]),cca=_ds.sa(["dropdown--open"]),dca=_ds.sa(["dropdown-transition"]),eca=_ds.sa(["hidden"]),fca=_ds.sa(["no-overflow"]),gca=_ds.sa(["overflow-menu--open"]),hca=_ds.sa(["overflow-tab"]),ica=_ds.sa(["render-hidden"]),jca=_ds.sa(["scrollbars"]);_ds.w(f8,_ds.Yh);_ds.g=f8.prototype;
_ds.g.disconnectedCallback=function(){_ds.Yl(this.eventHandler);_ds.Yl(this.m)};_ds.g.connectedCallback=function(){this.H||(this.kb(),this.H=!0);_ds.Zh(this,"connected","");var a;this.hasAttribute("no-overflow")||(_ds.Zh(this,"collapsed","",this.h),this.L=m8(this,this.h),null===(a=this.h)||void 0===a?void 0:a.removeAttribute("collapsed"),this.Z(),e8(this));oca(this)};
_ds.g.Z=function(){var a=this;this.eventHandler.listen(document.body,"devsite-sticky-resize",function(){return a.J.Ea()});this.eventHandler.listen(this,"click",function(e){if(!(e.shiftKey||e.ctrlKey||e.metaKey||e.altKey)){var f=e.target,k=a.Af(f);if(k)if(a.C&&a.C(e))e.preventDefault(),e.stopPropagation();else if(k===a.h)i8(a,e);else if(l8(a),f.classList.contains("devsite-tabs-dropdown-toggle"))e.preventDefault(),e.stopPropagation(),k.hasAttribute("dropdown--open")?g8(a):j8(a,k);else{var l;"A"===f.tagName?
l=f:l=_ds.Fj(f,"A");var m=k.querySelector(".devsite-tabs-dropdown");m&&m.contains(f)?l&&l.hasAttribute("href")||(e.preventDefault(),e.stopPropagation()):(a.Ej(k),l&&l&&"#"!==l.href||a.J.Ea())}}});if(this.querySelector("tab[dropdown]")||this.querySelector("tab[overflow-tab]")){var b="onpointermove"in window?"pointerover":"mouseover",c="onpointermove"in window?"pointerleave":"mouseleave",d=this.querySelectorAll("tab[clickable]");if(d.length){b=_ds.q(d);for(c=b.next();!c.done;c=b.next())this.eventHandler.listen(c.value,
"click",function(e){var f,k=e.target,l=a.Af(k),m=null===l||void 0===l?void 0:l.querySelector(".devsite-tabs-dropdown");!m||(null===(f=a.h)||void 0===f?0:f.contains(k))||m.contains(k)||(e.preventDefault(),e.stopPropagation(),(null===l||void 0===l?0:l.hasAttribute("dropdown--open"))?g8(a):h8(a,e))});this.eventHandler.listen(document.body,"click",function(e){a.v&&!a.v.contains(e.target)&&g8(a)})}else this.eventHandler.listen(this,b,function(e){return void lca(a,e)}),this.eventHandler.listen(this,c,function(){return void kca(a)})}b=
[].concat(_ds.ta(this.querySelectorAll(".devsite-tabs-close-button")));b=_ds.q(b);for(c=b.next();!c.done;c=b.next())this.eventHandler.listen(c.value,"click",function(){return g8(a)})};_ds.g.Af=function(a){for(;a&&a!==this;){if("TAB"===a.tagName.toUpperCase())return a;a=a.parentElement}return null};_ds.g.cS=function(a){this.C=a};_ds.g.$ka=function(){this.C=null};
_ds.g.Ej=function(a){var b=this.K||this.querySelector("[active]");b&&(b.removeAttribute("active"),_ds.Zh(this,"aria-selected","false",b));_ds.Zh(this,"active","",a);_ds.Zh(this,"aria-selected","true",a);this.K=a};
_ds.g.kb=function(){var a;this.Sc=Array.from(this.querySelectorAll("tab"));var b=this.querySelector(".devsite-tabs-wrapper");b||(b=this.ownerDocument.createElement("div"),b.classList.add("devsite-tabs-wrapper"),this.appendChild(b),null===(a=this.Sc)||void 0===a?void 0:a.forEach(function(e){return null===b||void 0===b?void 0:b.appendChild(e)}));this.v=b;this.appendChild(b);if(!this.hasAttribute("no-overflow")){var c=this.ownerDocument.createElement("tab");_ds.Zh(this,"overflow-tab","",c);var d=this.ownerDocument.createElement("a");
_ds.li(d,"#");d.textContent="More";d.classList.add("devsite-icon");d.classList.add("devsite-icon-arrow-drop-down");c.appendChild(d);this.h=c;d=this.ownerDocument.createElement("div");d.classList.add("devsite-tabs-overflow-menu");_ds.Zh(this,"scrollbars","",d);_ds.Zh(this,"hidden","",d);this.D=d;c.appendChild(d);b.appendChild(c)}};f8.prototype.connectedCallback=f8.prototype.connectedCallback;f8.prototype.disconnectedCallback=f8.prototype.disconnectedCallback;try{window.customElements.define("devsite-tabs",f8)}catch(a){console.warn("devsite.app.customElement.DevsiteTabs",a)};})(_ds_www);