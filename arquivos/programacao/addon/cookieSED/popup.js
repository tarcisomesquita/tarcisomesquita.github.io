document.addEventListener(
  'DOMContentLoaded', 
  function() {
    const sendButton = document.getElementById('sendCookie');
    const statusDiv = document.getElementById('status');
    
    function updateStatus(message, type = 'info') {
      statusDiv.textContent = message;
      statusDiv.className = `status ${type}`;
    }
    
    // Event listener para botão de enviar cookie
    sendButton.addEventListener(
      'click', 
      function() {
        sendButton.disabled = true;
        updateStatus('Enviando cookie...', 'info');
        
        // Envia mensagem para o background script
        chrome.runtime.sendMessage(
          { action: "sendCookie" }, 
          function(response) {
            sendButton.disabled = false;
            
            if (response && response.success) updateStatus(response.message, 'success');
            else                              updateStatus(response ? response.message : 'Erro desconhecido', 'error');
          }
        );
      }
    );
  }
);
