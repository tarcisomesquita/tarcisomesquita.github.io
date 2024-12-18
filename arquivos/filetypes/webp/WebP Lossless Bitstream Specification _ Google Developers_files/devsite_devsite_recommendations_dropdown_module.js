(function(_ds){var window=this;'use strict';var maa=function(a){a=a.bb;var b='<button type="button" class="devsite-recommendations-dropdown-toggle" id="devsite-recommendations-dropdown-toggle" aria-haspopup="true" aria-controls="recommendations-dropdown-popup"><span>Recommended</span><span class="devsite-icon devsite-recommendations-dropdown-icon"></span></button><ul class="devsite-recommendations-dropdown-list devsite-select-list" role="listbox">';for(var c=a.length,d=0;d<c;d++)b+=laa(a[d]);return(0,_ds.U)(b+"</ul>")},laa=function(a){var b=
"",c=_ds.RE(a.getTitle(),_ds.M(a,3),_ds.M(a,4));b+='<li role="option" class="devsite-select-item"><h3 class="significatio-card-heading no-link"><a href="'+_ds.Y(_ds.JE(a.getUrl()))+"?"+_ds.CE(_ds.M(a,8))+'" data-category="Site-Wide Custom Events" data-label="devsite-recommendation card link" data-action="click">'+_ds.gE(c.filter(function(d){return 0<_ds.hE(d).length})[0])+'</a></h3><p class="significatio-card-description">'+_ds.gE(_ds.mE(_ds.M(a,5)))+'</p><div class="significatio-card-meta">Updated <span class="significatio-date" date="'+
_ds.Y(_ds.Te(_ds.Ge(a,_ds.GD,7),1))+'"></span></div></li>';return(0,_ds.U)(b)},U6=function(a){var b=_ds.Yh.call(this)||this;b.timeZone=a;b.eventHandler=new _ds.Sl(b);b.D=null;b.h=null;b.v=new _ds.Zl;b.loaded=b.v.promise;b.m=new _ds.Zl;b.H=b.m.promise;b.G=!1;b.C=null;return b},naa=function(a){a.h&&a.eventHandler.listen(a.h,"click",function(){var b;if(null===(b=a.h)||void 0===b?0:b.classList.contains("active"))V6(a);else{var c,d;null===(c=a.h)||void 0===c?void 0:c.classList.add("active");null===(d=
a.D)||void 0===d?void 0:d.classList.add("active");if(!a.G){a.G=!0;var e;if(b=null===(e=a.C)||void 0===e?void 0:_ds.gL(e)){e=_ds.q(b);for(b=e.next();!b.done;b=e.next())if(b=b.value,c=_ds.Ge(b,_ds.dK,10))c={targetPage:b.getUrl(),targetType:_ds.qe(c,3,0),targetRank:_ds.Te(c,2),targetIdenticalDescriptions:_ds.Te(c,4),targetTitleWords:_ds.Te(c,5),targetDescriptionWords:_ds.Te(c,6),experiment:_ds.M(c,7)},b={category:"Site-Wide Custom Events",action:"recommended",label:b.getUrl(),additionalParams:{recommendations:c}},
a.dispatchEvent(new CustomEvent("devsite-analytics-observation",{detail:b,bubbles:!0})),b={eventData:JSON.stringify({type:"recommendations",name:"impression",metadata:c})},a.dispatchEvent(new CustomEvent("devsite-analytics-observation-cloudtrack",{detail:b,bubbles:!0}));a.m.resolve()}else a.m.reject("empty")}}});a.eventHandler.listen(document,"click",function(b){var c;!a.contains(b.target)&&(null===(c=a.h)||void 0===c?0:c.classList.contains("active"))&&V6(a)})},V6=function(a){var b,c;null===(b=a.h)||
void 0===b?void 0:b.classList.remove("active");null===(c=a.D)||void 0===c?void 0:c.classList.remove("active")};_ds.w(U6,_ds.Yh);U6.prototype.connectedCallback=function(){var a=this;this.eventHandler.listen(document,"devsite-on-recommendations",function(b){b=b.ma;!a.C&&b&&b.detail&&(2===_ds.qe(b.detail,5,0)&&(b=b.detail,a.render(b),a.D=a.querySelector(".devsite-recommendations-dropdown-list"),a.h=a.querySelector(".devsite-recommendations-dropdown-toggle"),naa(a),a.C=b),a.v.resolve())})};U6.prototype.disconnectedCallback=function(){_ds.Yl(this.eventHandler);this.v.reject("Disconnected")};
U6.prototype.render=function(a){if(this.isConnected){_ds.$E(this,maa,{bb:_ds.gL(a)});a=Array.from(this.querySelectorAll(".significatio-date"));a=_ds.q(a);for(var b=a.next();!b.done;b=a.next()){b=b.value;var c=b.getAttribute("date");try{b.textContent=(new Date(1E3*Number(c))).toLocaleDateString("default",{month:"short",year:"numeric",day:"numeric",timeZone:this.timeZone})}catch(d){}}}};try{window.customElements.define("devsite-recommendations-dropdown",U6)}catch(a){console.warn("Unrecognized DevSite custom element - DevsiteRecommendationsDropdown",a)};})(_ds_www);
