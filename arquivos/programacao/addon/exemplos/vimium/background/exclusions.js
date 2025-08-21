"use strict"
;__filename="background/exclusions.js",define(["require","exports","./store","./utils","./browser","./normalize_urls","./settings","./ports"],(e,t,l,n,r,i,u,o)=>{
Object.defineProperty(t,"__esModule",{value:!0}),t.vn=t.dn=t.as=t.mn=t.pn=t.rs=t.Il=t.Fl=t.$n=void 0,t.$n=(e,t)=>{
let l,r,u
;return t=t&&t.replace(/<(\S+)>/g,"$1"),e[0]==="^"?(l=n.pl(e.startsWith("^$|")?e.slice(3):e,"",0))||console.log("Failed in creating an RegExp from %o",e):e[0]==="`"&&((r=n.gn(e.slice(1),0))||console.log("Failed in creating an URLPattern from %o",e)),
u=l?{t:1,v:l,k:t}:r?{t:3,v:{p:r,s:e.slice(1)},k:t}:{t:2,v:e.startsWith(":vimium://")?i.kn(e.slice(10),!1,-1):e.slice(1),
k:t},u},t.Fl=e=>{let t;if(e[0]==="^"){
e=e.startsWith("^$|")?e.slice(3):e,t=".*$".includes(e.slice(-2))?e.endsWith(".*$")?3:e.endsWith(".*")?2:0:0,
e=t!==0&&e[e.length-t]!=="\\"?e.slice(0,-t):e;let l=n.pl(e,"");return l?{t:1,v:l}:null}if(e[0]==="`"){
let t=e.slice(1),l=n.gn(t);return l?{t:3,v:{p:l,s:t}}:null}
if(e==="localhost"||!e.includes("/")&&e.includes(".")&&(!/:(?!\d+$)/.test(e)||n.xn(e,6))){let t
;e=(e=(e=e.toLowerCase()).endsWith("*")?e.slice(0,/^[^\\]\.\*$/.test(e.slice(-3))?-2:-1):e).startsWith(".*")&&!/[(\\[]/.test(e)?"*."+e.slice(2):e
;let l=n.pl("^https?://"+(e.startsWith("*")&&e[1]!=="."?"[^/]"+e:(t=e.replace(/\./g,"\\."),
t.startsWith("*")?t.replace("*\\.","(?:[^./]+\\.)*?"):t)),"",0);return l?{t:1,v:l}:e.includes("*")?null:{t:2,
v:"https://"+(e.startsWith(".")?e.slice(1):e)+"/"}}
return t=(e=(e=(e[0]===":"?e.slice(1):e).replace(/([\/?#])\*$/,"$1")).startsWith("vimium://")?i.kn(e.slice(9),!1,-1):e.startsWith("extension:")?"moz-"+e:e).indexOf("://"),
{t:2,v:t>0&&t+3<e.length&&e.indexOf("/",t+3)<0?e+"/":e}
},t.Il=(e,t)=>e.t===1?e.v.test(t):e.t===2?t.startsWith(e.v):e.v.p.test(t);let f=!1;t.rs=f;let s=!1;t.pn=s
;let v=!1,a=[],c=e=>{a=e.map(e=>t.$n(e.pattern,e.passKeys))};t.mn=e=>(e?[t.$n(e,"")]:a).map(e=>({t:e.t,
v:e.t===1?e.v.source:e.t===2?e.v:e.v.s})),t.as=(e,r)=>{var i;let u=""
;for(let t of a)if(t.t===1?t.v.test(e):t.t===2?e.startsWith(t.v):t.v.p.test(e)){let e=t.k
;if(e.length===0||e[0]==="^"&&e.length>2||v)return e&&e.trim();u+=e}
if(!u&&r.J&&e.lastIndexOf("://",5)<0&&!n.sn.test(e)){let e=(i=l.Ol.get(r.u))===null||i===void 0?void 0:i.T
;if(e!=null)return t.as(e.s.Rl,e.s)}return u?u.trim():null};let d=()=>{let e=r.N()?e=>{l.bn[10](e),o.hn()}:null
;return d=()=>e,e};t.dn=()=>{let e=new Set;for(let{k:t}of a)if(t){if(t[0]==="^"&&t.length>2)return!0
;for(let l of t.split(" "))e.add(l)}return e.size?e:null},t.vn=e=>{let n=a.length>0?null:{N:1,p:null,f:0}
;if(e)return void(n||u.Nn({N:3,H:10,U:0}));let r=l.l!=null||l.l!==void 0&&l.t,i=a;o.p(4096,e=>{let i=e.a.s.d,u=e.a.s
;for(let l of e.E){let r=null,i=0;if(n){if(l.s.d===0)continue}else if(r=t.as(l.s.Rl,l.s),i=r===null?0:r?1:2,
!r&&l.s.d===i)continue;e.ts||(l.postMessage(n||{N:1,p:r,f:0}),l.s.d=i)}r&&i!==u.d&&l.o(u.u,u.d)},()=>i===a)};let m=()=>{
let e=a.length>0,n=e||f?d():null;if(!n)return;if(f!==e){t.rs=f=e;let l=r.N().onHistoryStateUpdated
;e?l.addListener(n):l.removeListener(n)}let i=e&&l.q.exclusionListenHash;if(s!==i){t.pn=s=i
;let e=r.N().onReferenceFragmentUpdated;i?e.addListener(n):e.removeListener(n)}};l.dl.exclusionRules=e=>{
let n=!a.length,r=l.jn;c(e),v=l.q.exclusionOnlyFirstMatch,m(),setTimeout(()=>{setTimeout(t.vn,10,n),
l.jn===r&&u.hl("keyMappings",null)},1)},l.dl.exclusionOnlyFirstMatch=e=>{v=e},l.dl.exclusionListenHash=m,u.Tl.then(()=>{
c(l.q.exclusionRules),v=l.q.exclusionOnlyFirstMatch})});