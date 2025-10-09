chrome.cookies.get(
  { url: "https://sed.educacao.sp.gov.br", name: "SED" },
  function(cookie) {
    if (cookie && cookie.value) {
      chrome.runtime.sendMessage({
        type: "SEND_COOKIE_SED",
        cookie: cookie.value
      });
    }
  }
);