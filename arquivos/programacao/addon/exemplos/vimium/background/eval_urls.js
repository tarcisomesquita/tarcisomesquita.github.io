"use strict"
;__filename="background/eval_urls.js",define(["require","exports","./store","./utils","./browser","./normalize_urls","./parse_urls","./ports","./exclusions","./open_urls"],(e,s,r,a,t,l,n,c,u,i)=>{
Object.defineProperty(s,"__esModule",{value:!0}),r.Fr=(e,s,u,p)=>{let d,g,h,y,m;if(s|=0,
e==="paste"?e+=" .":!e.includes("%20")||e.includes(" ")||e.startsWith("run")||(e=e.replace(/%20/g," ")),
s<0||!(e=e.trim())||(d=e.search(/[/ ]/))<=0||!/^[a-z][\da-z\-]*(?:\.[a-z][\da-z\-]*)*$/i.test(g=e.slice(0,d).toLowerCase())||/\.(?:css|html?|js)$/i.test(g))return null
;if(!(e=e.slice(d+1).trim()))return null;let x=/[\s+,\uff0b\uff0c]+/g;if(s===1)switch(g){case"sum":case"mul":
e=e.replace(x,g==="sum"?" + ":" * "),g="e";break;case"avg":case"average":h=e.split(x),
e="("+h.join(" + ")+") / "+h.length,g="e"}if(s===1)switch(g){case"e":case"exec":case"eval":case"expr":case"calc":
case"m":case"math":return t.import2("/lib/math_parser.js").then(o.bind(0,e));case"error":return[e,3]
}else if(s>=2)switch(g){case"run":case"run1":case"run-one":case"run-one-key":return[[g,e],6];case"status":case"state":
return s>=3&&f(e),[e,s>=3?4:7];case"url-copy":case"search-copy":case"search.copy":case"copy-url":if(m=l._r(e,null,1,p),
m instanceof Promise)return m.then(e=>{let s=e[0]||e[2]||"";return s=s instanceof Array?s.join(" "):s,
Promise.resolve(r.Kl(s)).then(e=>[e,1])});m=l.dr===5&&m instanceof Array?m[0]:m,e=m instanceof Array?m.join(" "):m
;case"cp":case"copy":case"clip":let n=r.Kl(e);return typeof n=="string"?[e,1]:n.then(e=>[e,1]);case"browser-search":
case"browser-search2":case"browser-search.at":case"browser-search-at":case"bs":case"bs2":case"bs.at":case"bs-at":
case"b-s":case"b-s2":case"b-s.at":case"b-s-at":case"b-search":case"b-search2":case"b-search.at":case"b-search-at":{
let s="NEW_TAB";if(g.endsWith("2")||g.endsWith("at")){let r=/^[-\w][^ /]*/.exec(e);if(r){let a=i.parseReuse(r[0])
;s=a===2?"NEW_WINDOW":a>=0||a===-3?"CURRENT_TAB":s,e=e.slice(r[0].length+1)}}return e=e.trim().replace(a.F," "),
r.es<111?t.n.search.search(s==="CURRENT_TAB"&&r.ye>=0?{tabId:r.ye,query:e}:{query:e}):t.n.search.query({disposition:s,
text:e}),[e,9]}}switch(g){case"urls":return s<1?null:b(e,s);case"cd":case"up":if(h=(e+"  ").split(" "),!h[2]){
if(s<1)return null;if(m=c.I(),typeof m!="string")return m.then(a=>{
let t=a&&r.Fr("cd "+e+" "+(e.includes(" ")?a:". "+a),s,u,p)
;return t?typeof t=="string"?[t,7]:t:[a?"fail in parsing":"No current tab found",3]});h[2]=m}g=h[0];let t=g[0]==="/"
;d=parseInt(g,10),d=isNaN(d)?g==="/"?1:t?g.replace(/(\.+)|./g,"$1").length+1:-g.replace(/\.(\.+)|./g,"$1").length||-1:d
;let i=n.Se({u:h[2],p:d,t:null,f:1,a:h[1]!=="."?h[1]:""});return i&&i.u||[i?i.e:"No upper path",3];case"parse":
case"decode":g=e.split(" ",1)[0],g.search(/\/|%2f/i)<0?e=e.slice(g.length+1).trimLeft():g="~",h=[e=a.Dl(e)],
e=l._r(e,null,0,p),l.dr!==4&&(y=n.Se({u:e}))?y.u===""?h=[g]:(h=y.u.split(" "),h.unshift(g)):h=h[0].split(a.F);break
;case"sed":case"substitute":case"sed-p":case"sed.p":case"sed2":let o=e.split(" ",1)[0];e=e.slice(o.length+1).trim()
;let f=g==="sed2"?e.split(" ",1)[0]:"";return[e=(e=e.slice(f.length).trim())&&r.R(e,g.endsWith("p")?32768:0,f?{r:o,k:f
}:/^[@#$-]?[\w\x80-\ufffd]+$|^\.$/.test(o)?{r:null,k:o}:{r:o,k:null}),5];case"u":case"url":case"search":
h=a.Dl(e,!0).split(a.F);break;case"paste":
if(s>0)return m=r.Ql(e),m instanceof Promise?m.then(e=>[e?e.trim().replace(a.F," "):"",5]):[m?m.trim().replace(a.F," "):"",5]
;default:return null}if(u)return[h,2];if(p&&p>12)return null;let _=h[0]&&r.Gl.map.has(h[0])?h.shift():null
;return l.C(h,_,p===12?0:s,p)};let o=(e,s)=>{
l.ss.test(e)&&(e=e.slice(1,-1)),e=(e=(e=e.replace(/\uff0c/g," ")).replace(/deg\b/g,"\xb0").replace(/[\xb0']\s*\d+(\s*)(?=\)|$)/g,(e,s)=>(e=e.trim())+(e[0]==="'"?"''":"'")+s).replace(/([\u2070-\u2079\xb2\xb3\xb9]+)|[\xb0\uff0b\u2212\xd7\xf7]|''?/g,(e,s)=>{
let r,a=""
;if(!s)return e==="\xb0"?"/180*PI+":(r="\uff0b\u2212\xd7\xf7".indexOf(e))>=0?"+-*/"[r]:`/${e==="''"?3600:60}/180*PI+`
;for(let s of e)a+=s<"\xba"?s>"\xb3"?1:s<"\xb3"?2:3:s.charCodeAt(0)-8304;return a&&"**"+a
}).replace(/([\d.])rad\b/g,"$1")).replace(/^=+|=+$/g,"").trim()
;let r=[].reduce.call(e,(e,s)=>e+(s==="("?1:s===")"?-1:0),0);for(;r<0;r++)e="("+e;for(;r-- >0;)e+=")";if(e){
for(;e&&e[0]==="("&&e.slice(-1)===")";)e=e.slice(1,-1).trim();e=e||"()"}
let a="",t=s.MathParser||globalThis.MathParser||{};if(t.evaluate){try{a=t.evaluate(e!=="()"?e:"0"),
a=typeof a=="function"?"":""+a}catch(e){}t.clean(),t.errormsg&&(t.errormsg="")}return[a,0,e]},f=e=>{let s=r.ye
;parseInt(e,10)&&(s=parseInt(e,10),e=e.slice(e.search(/[/ ]/)+1));let t=r.Ol.get(s||(s=r.ye));if(!t)return
;if(t.c&512)return void console.log(`Unexpected inactive Tab ${s}`);r.$=t.T||t.a
;let l=e.search(/[/ ]/),n=l>0?e.slice(l+1):"";e=e.toLowerCase(),l>0&&(e=e.slice(0,l)),
e.includes("-")&&e.endsWith("able")&&(e+="d");let i=!!n&&/^silent/i.test(n);n=(i?n.slice(7):n).trim();let o,f=0,b=e=>{
console.log(e),f||c.showHUD(e),f=1};if(n.includes("%")&&/%[a-f0-9]{2}/i.test(n)&&(n=a.Ye(n)),
n&&!n.startsWith("^ "))b('"vimium://status" only accepts a list of hooked keys'),n="";else if(n){
let e=n.match(/<(?!<)(?:a-)?(?:c-)?(?:m-)?(?:s-)?(?:[a-z]\w+|[^\sA-Z])>|\S/g)
;n=e?e.join(" ").replace(/<(\S+)>/g,"$1"):""}let p=r.$.s,d=p.d,g=u.rs?d===1?d:(o=u.as(p.Rl,p),
o?1:o===null?0:2):0,h=e==="enable"?0:e==="disable"?2:e==="toggle-disabled"?d!==2?g===2?null:2:g===2?0:null:e==="toggle-enabled"?d!==0?g===0?null:0:g===0?2:null:e==="toggle-next"?d===1?0:d===0?g===2?null:2:g===2?0:null:e==="toggle"||e==="next"?d!==0?0:2:(e!=="reset"&&b(`Unknown status action: "${e}", so reset`),
null),y=!!n&&e==="enable",m=h===null?0:h===2?3:1,x={N:1,p:h===2||y?n:null,f:m},_=m?h:0;t.ts=m?{d:_,ls:x.p}:null
;for(let e of t.E){let s=e.s;!m&&u.rs&&(o=x.p=u.as(s.Rl,s),_=o===null?0:o?1:2,_!==1&&s.d===_)||(s.d=_,e.postMessage(x))}
_=t.a.s.d,i||f||c.showHUDEx(r.$,"newStat",0,[[_!==0||y?_===2?"fullyDisabled":"halfDisabled":"fullyEnabled"]]),
r.t&&_!==d&&r.o(s,_)},b=(e,s)=>{let a=e.indexOf(":")+1||e.indexOf(" ")+1;if(a<=0)return["No search engines given",3]
;let t=e.slice(0,a-1).split(e.lastIndexOf(" ",a-1)>=0?" ":"|").filter(e=>r.Gl.map.has(e))
;if(t.length<=0)return["No valid search engines found",3];let n=e.slice(a).trim().split(" "),c=["openUrls"]
;for(let e of t)c.push(l.C(n,e,s));return c.some(e=>e instanceof Promise)?Promise.all(c).then(e=>[e,6]):[c,6]}});