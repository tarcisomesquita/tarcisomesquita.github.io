"use strict";__filename="background/normalize_urls.js",define(["require","exports","./store","./utils"],(e,t,r,l)=>{
Object.defineProperty(t,"__esModule",{value:!0
}),t.Zn=t.fn=t.mi=t.Hl=t.di=t.C=t.kn=t.pi=t.ci=t._r=t.wi=t.gi=t.dr=t.$i=t.hi=t.bi=t.xi=t.vi=t.ss=t.Ei=t._i=void 0,
t._i=/^([^:]+(:[^:]+)?@)?([^:]+|\[[^\]]+])(:\d{2,5})?$/,t.Ei=/^(?:ext|web)\+[a-z]+:/,
t.ss=/^"[^"]*"$|^'[^']*'$|^\u201c[^\u201d]*\u201d$/,t.vi=/\$([sS$])?(?:\{([^}]*)})?/g,t.xi=/\$([+-]?\d+|\$)/g,
t.bi=/^[\w\x80-\ufffd]{1,8}!?>/,t.hi=/<[\w\x80-\ufffd]{1,8}!?$/,t.$i=/\|([\w\x80-\ufffd]{1,8}|(,|%2[cC])[\w,-]*)$/
;let i=["blank","newtab","options","show"],n="options.html",s={__proto__:null,about:"",changelog:"/RELEASE-NOTES.md",
help:"/wiki",home:"",license:"/LICENSE.txt",option:n,permissions:"/PRIVACY-POLICY.md#permissions-required",
policy:"/PRIVACY-POLICY.md",action:n,popup:n,preference:n,preferences:n,privacy:"/PRIVACY-POLICY.md#privacy-policy",
profile:n,profiles:n,readme:"#readme",release:"/RELEASE-NOTES.md",releases:"/RELEASE-NOTES.md",
"release-notes":"/RELEASE-NOTES.md",setting:n,settings:n,wiki:"/wiki"};t.dr=0,t.gi=!1,t.wi=()=>{t.dr=0},
t._r=(e,i,n,s)=>{if(e=e.trim(),t.dr=0,l.Vl(e))return e=e.replace(/\xa0/g," "),l.Bl(),e;let o,m,d,p,c=-1,w=0,g=!1
;d=e.replace(/[\n\r]+[\t \xa0]*/g,"").replace(/\xa0/g," ");let $=d[0]==='"'&&d.endsWith('"'),h=d
;return e=d=$?d.slice(1,-1):d,
/^[A-Za-z]:(?:[\\/](?![:*?"<>|/])|$)|^\/(?:Users|home|root)\/[^:*?"<>|/]+/.test(e)||e.startsWith("\\\\")&&e.length>3?f(e):((o=(e=d.toLowerCase()).indexOf(" ")+1||e.indexOf("\t")+1)>1&&(e=e.slice(0,o-1)),
(o=e.indexOf(":"))===0?c=4:o!==-1&&l.sn.test(e)?e.startsWith("vimium:")?(c=3,n|=0,e=d.slice(9),
n<-1||!e?d="vimium://"+e:n===-1||$||!(d=r.Fr(e,n,null,(s||0)+1))?d=t.kn(e,!1,n):typeof d!="string"&&(c=5)):t.Ei.test(e)?c=0:((m=e.indexOf("/",o+3))===-1?e.length<d.length:e.charCodeAt(m+1)<33)?c=4:/[^a-z]/.test(e.slice(0,o))?c=(o=e.charCodeAt(o+3))>32&&o!==47?0:4:e.startsWith("file:")?c=0:e.startsWith("chrome:")?c=e.length<d.length&&e.includes("/")?4:0:e=e.slice(o+3,m>=0?m:void 0):(o!==-1&&e.lastIndexOf("/",o)<0&&(c=t.ci(d.toLowerCase(),o,e.length%d.length)),
w=2,
m=d.length,c===-1&&e.startsWith("//")&&(e=e.slice(2),w=1,m-=2),c!==-1?e==="about:blank/"&&(d="about:blank"):(o=e.indexOf("/"))<=0?(o===0||e.length<m)&&(c=4):e.length>=m||e.charCodeAt(o+1)>32?(g=e.length>o+1,
e=e.slice(0,o)):c=4),c===-1&&e.lastIndexOf("%")>=0&&(e=l.Ye(e)).includes("/")&&(c=4),
c===-1&&e.startsWith(".")&&(e=e.slice(1)),
c!==-1||((p=t._i.exec(e))?(e=p[3]).endsWith("]")?c=l.xn(e,6)?w:4:e==="localhost"||e.endsWith(".localhost")||l.xn(e,4)||p[4]&&g?c=w:(o=e.lastIndexOf("."))<0||(c=l.zi(e.slice(o+1),!1,e))===0?(m=e.length-o-1,
c=w!==2&&(o<0||(w!==0?m>=3&&m<=5:m>=2&&m<=14)&&!/[^a-z]/.test(e.slice(o+1)))||u(e,p[4])>0?w:4):c=/[^.\da-z_\-]|xn--|^-/.test(e)?e.startsWith("xn--")||e.includes(".xn--")||(e.length===o+3||c!==1?!w:u(e,p[4]))?w:4:w!==2||g?w:e.endsWith(".so")&&e.startsWith("lib")&&e.indexOf(".")===e.length-3?4:p[2]||p[4]||!p[1]||/^ftps?(\b|_)/.test(e)?2:e.startsWith("mail")||e.indexOf(".mail")>0||(m=e.indexOf("."))===o?4:e.indexOf(".",++m)!==o?2:e.length===o+3&&c===1&&l.zi(e.slice(m,o),!0)?4:2:(c=4,
e.length===d.length&&l.xn(e=`[${e}]`,6)&&(d=e,c=2))),l.Bl(),s||(t.gi=!1),t.dr=c,
c===0?/^extension:\/\//i.test(d)?"moz-"+d:d:c===4?t.C(h.split(l.F),i,n,s):c<=2?c===2&&a(d,e)||(u(e,p&&p[4])===2?"https:":"http:")+(c===2?"//":"")+d:d)
};let u=(e,t)=>{let l=t&&r.zt.Zt.get(e+t)||r.zt.Zt.get(e);return l?l.rl?2:1:0},a=(e,t)=>{
if(/^(?!www\.)[a-z\d-]+\.([a-z]{3}(\.[a-z]{2})?|[a-z]{2})\/?$/i.test(e)&&!u(t)){let l=r.zt.Zt.get("www."+t)
;if(l)return`${l.rl?"https":"http"}://www.${e.toLowerCase().replace("/","")}/`}return""};t.ci=(e,r,i)=>{
let n=e.substr(r+1,1)==="/";if(e.substr(r+1,1)==="%")return 4;switch(e.slice(0,r)){case"about":
return n?4:i>0||e.includes("@",r)?-1:0;case"blob":case"view-source":
return(e=e.slice(r+1)).startsWith("blob:")||e.startsWith("view-source:")?4:(t._r(e,null,-2,1),t.dr<=2?0:4);case"data":
return n?4:(r=e.indexOf(",",r))<0||i>0&&i<r?-1:0;case"file":return 0;case"filesystem":return e=e.slice(r+1),
l.sn.test(e)?(t._r(e,null,-2,1),t.dr===0&&/[^/]\/(?:persistent|temporary)(?:\/|$)/.test(e)?0:4):4;case"magnet":
return e[r+1]!=="?"?-1:0;case"mailto":return n?4:(r=e.indexOf("/",r))>0&&e.lastIndexOf("?",r)<0?-1:0;case"tel":
return/\d/.test(e)?0:4;default:return t.Ei.test(e)?0:n?4:-1}},t.pi=e=>{
let t=e.startsWith("filesystem:")?11:e.startsWith("view-source:")?12:0;return t?e.slice(t):e},t.kn=(e,t,l)=>{
let n,u,a="",o="",f=e.trim();if(!f)return t?"":r.Le+"pages/";if((n=f.indexOf(" ")+1)&&(o=f.slice(n).trim(),
f=f.slice(0,n-1)),(n=f.search(/[\/#?]/)+1)&&(a=f.slice(n-1).trim(),f=f.slice(0,n-1)),f==="display"&&(f="show"),
!/\.\w+$/.test(f))if(f=f.toLowerCase(),
(u=s[f])!=null)(f==="release"||f==="releases")&&(u+="#v"+r.Q.mo.replace(/\D/g,"")),
u=f=u&&u[0]!=="/"&&u[0]!=="#"?u:r.Q.ta+(u.includes(".")?"/blob/master"+u:u);else{if(f==="newtab")return r.newTabUrl_f
;if(f[0]==="/"||i.indexOf(f)>=0)f+=".html";else{if(l===1||l===-1)return"vimium://"+e.trim()
;f="show.html#!url vimium://"+f}}return t||u&&u.includes("://")||(f=r.Le+(f[0]==="/"?f.slice(1):"pages/"+f)),a&&(f+=a),
f+(o&&(f.includes("#")?" ":"#!")+o)},t.C=(e,l,i,n)=>{let s=r.Gl.map.get(l=l||"~"),u=s?t.Hl(e,s.Rl,s.r):e.join(" ")
;return n||(t.gi=!!s&&l!=="~"),l!=="~"?t._r(u,null,i,(n||0)+1):(t.dr=4,u)
},t.di=(e,t)=>e.lastIndexOf("://",21)<0||l.Vl(e)||e.startsWith("vimium://run")||e.startsWith("data:")||!/\?|#.*=/.test(e.slice(0,t))?"%20":"+",
t.Hl=(e,i,n,s)=>{let u,a=0;return i=e.length===0&&n?n:i.replace(t.vi,(n,o,f,m)=>{let d
;if(n.endsWith("$")||!o&&!f)return"$";o||(/^s:/i.test(f)?(o=f[0],f=f===null||f===void 0?void 0:f.slice(2)):o="s")
;let p=e,c=f?t.$i.exec(f):null;c&&f.charAt(c.index-1)!=="\\"?f=f.slice(0,c.index):c=null
;let w=f?t.hi.exec(f)||t.bi.exec(f):null
;return!w||w[0][0]==="<"&&f.charAt(w.index-1)==="\\"||(f=w[0][0]==="<"?f.slice(0,w.index):f.slice(w[0].length),
p=r.Al(w[0][0]==="<"?w[0].slice(1):w[0].slice(0,-1)).split(" ")),o==="S"?(d=p,o=" "):(d=p===e&&u?u:p.map(l.Ul),
p===e&&!u&&(u=d),o=t.di(i,m)),f&&f.includes("\\")&&(f=f.replace(/\\([\\<>|])/g,"$1")),
f=d.length===0?"":f&&f.includes("$")?f.replace(t.xi,(e,t)=>{if(t==="$")return"$";let r=parseInt(t,10)
;if(!r)return d.join(o);if(r<0)r+=d.length+1;else if(t[0]==="+")return d.slice(r-1).join(o);return d[r-1]||""
}):d.join(f!=null?f:o),c&&(f=r.R(f,0,l.Ye(c[0].slice(1)))),s!=null&&f&&(s.push(m+=a,m+f.length),a+=f.length-n.length),f
}),l.Bl(),s==null?i:{Rl:i,jr:s}},t.mi=e=>{let r=e.indexOf(":"),l=r;if(r<=0)return e
;if(t.Ei.test(e.slice(0,r+1).toLowerCase()))return e.slice(0,r).toLowerCase()+e.slice(r)
;if(e.substr(r,3)==="://")if(r=e.indexOf("/",r+3),
r<0)r=l,l=-1;else if(r===7&&e.slice(0,4).toLowerCase()==="file")return r=e.charAt(9)===":"?3:e.substr(9,3).toLowerCase()==="%3a"?5:0,
"file:///"+(r?e[8].toUpperCase()+":/":"")+e.slice(r+8);let i=e.slice(0,r),n=i.toLowerCase()
;return l===-1&&/^(file|ftp|https?|rt[ms]p|wss?)$/.test(i)&&(e+="/"),i!==n?n+e.slice(r):e};let o=e=>{let t=l.Ye(e)
;return/[^\w.$+-\x80-\ufffd]|\s/.test(t)?e.replace(/%24/g,"$"):t},f=e=>{
if((e=e.replace(/\\/g,"/")).startsWith("//")&&!e.startsWith("//./")){let t=(e=e.slice(2)).split("/",1)[0]
;t.includes("%")&&(e=o(t)+e.slice(t.length)),e.includes("/")||(e+="/")}else e.startsWith("//")&&(e=e.slice(4)),
e[1]===":"&&(e=e[0].toUpperCase()+":/"+e.slice(3)),e[0]!=="/"&&(e="/"+e);if(!/[%?#&\s]/.test(e))return l.Bl(),
"file://"+e;let t="";if(e.indexOf("#")){let r=/\.[A-Za-z\d]{1,4}(\?[^#]*)?#/.exec(e)
;r?(t=e.slice(r.index+r[0].length-1),
t=t.includes("=")||!t.includes("/")||t.includes(":~:")?r[1]?r[1]+t:t:""):(r=/#(\w+=|:~:)/.exec(e))&&(t=e.slice(r.index)),
t&&(e=e.slice(0,-t.length))}
return e="file://"+e.replace(/[?#&\s]/g,encodeURIComponent)+t.replace(/\s/g,encodeURIComponent),l.Bl(),e};t.fn=(e,t)=>{
if(r.G>1&&e.startsWith("file://")){let r=e.indexOf("/",7);if(r<0||r===e.length-1)return r<0?e+"/":e
;let i=r===7?e.charAt(9)===":"?3:e.substr(9,3).toLowerCase()==="%3a"?5:0:0,n=i?e[8].toUpperCase()+":":r>7?"\\\\"+o(e.slice(7,r)):"",s=e.slice(i?i+7:r>7?r:0),u=t?/[?#]/.exec(t):null,a=!t||u?/[?#]/.exec(s):null,f=a?a.index:0
;if(f&&u){let e=l.Ye(t.slice(t.indexOf("/",i?9:r>7?8:0),u.index));e===s.slice(0,e.length)&&(f=e.length)}
let m=f?s.slice(f):"";s=f?s.slice(0,f):s,s=s.replace(/\/+/g,"\\"),e=n+s+m}return e};let m=e=>{
let t=(new DOMParser).parseFromString(e,"image/svg+xml").firstElementChild
;for(let e of t?[].slice.call(t.querySelectorAll("script,use")):[])e.remove();if(!t||!t.lastElementChild)return""
;for(let e of"id class aria-hidden".split(" "))t.removeAttribute(e);let r,i=t.attributes;for(let e=i.length;0<=--e;){
let r=i.item(e).name;r.startsWith("data-")&&t.removeAttribute(r)}if(!t.getAttribute("xmlns")){let e=[].slice.call(i)
;for(let r of e)t.removeAttributeNode(r);t.setAttribute("xmlns","http://www.w3.org/2000/svg")
;for(let r of e)t.setAttributeNode(r)}
for(let e=t.ownerDocument.createTreeWalker(t,NodeFilter.SHOW_TEXT);r=e.nextNode();){let e=r.data,t=e.trim()
;t.length<e.length&&(r.data=t?(l.F.test(e[0])?" ":"")+t+(l.F.test(e.slice(-1))?" ":""):" ")}
return t.outerHTML.replace(/\xa0/g," ")};t.Zn=e=>{let t
;return t=m(e),t=t.replace(/<\/?[A-Z:]+(?=\s|>)/g,e=>e.toLowerCase()),
t=t.replace(/(?:[%?#]|[^\S ])+/g,encodeURIComponent),"data:image/svg+xml,"+t}});