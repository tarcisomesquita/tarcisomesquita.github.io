// Content script para detectar quando estamos na página SED
console.log("SED Cookie Sender - Content script carregado");

// Função para verificar e enviar cookie quando a página carregar
function checkAndSendCookie() {
  if (document.readyState === 'complete') {
    // Verifica se existe cookie SED através do document.cookie
    const cookies = document.cookie.split(';');
    const sedCookie = cookies.find(cookie => cookie.trim().startsWith('SED='));
    
    if (sedCookie) {
      console.log("Cookie SED encontrado na página!");
      
      // Envia mensagem para o background script
      chrome.runtime.sendMessage({
        action: "sendCookie"
      }, (response) => {
        if (response) {
          console.log("Resposta:", response.message);
        }
      });
    } else {
      console.log("Cookie SED não encontrado na página");
    }
  }
}

// Executa quando a página carregar completamente
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', checkAndSendCookie);
} else {
  checkAndSendCookie();
}

// Também executa quando a página terminar de carregar completamente
window.addEventListener('load', checkAndSendCookie);

// Observer para mudanças no DOM que podem indicar login/logout
const observer = new MutationObserver(() => {
  setTimeout(checkAndSendCookie, 1000); // Aguarda 1 segundo após mudanças no DOM
});

observer.observe(document.body, {
  childList: true,
  subtree: true
});