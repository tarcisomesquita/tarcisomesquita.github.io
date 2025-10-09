document.addEventListener('DOMContentLoaded', function() {
  const sendButton = document.getElementById('sendCookie');
  const checkButton = document.getElementById('checkCookie');
  const statusDiv = document.getElementById('status');
  
  // Função para atualizar status
  function updateStatus(message, type = 'info') {
    statusDiv.textContent = message;
    statusDiv.className = `status ${type}`;
  }
  
  // Função para verificar se existe cookie SED
  async function checkCookie() {
    try {
      const cookies = await chrome.cookies.getAll({
        domain: ".educacao.sp.gov.br"
      });
      
      const sedCookie = cookies.find(cookie => cookie.name === "SED");
      
      if (sedCookie) {
        updateStatus(`Cookie SED encontrado! Valor: ${sedCookie.value.substring(0, 20)}...`, 'success');
        sendButton.disabled = false;
        return sedCookie;
      } else {
        updateStatus('Cookie SED não encontrado. Faça login primeiro.', 'error');
        sendButton.disabled = true;
        return null;
      }
    } catch (error) {
      updateStatus('Erro ao verificar cookie: ' + error.message, 'error');
      sendButton.disabled = true;
      return null;
    }
  }
  
  // Event listener para botão de verificar cookie
  checkButton.addEventListener('click', async function() {
    checkButton.disabled = true;
    updateStatus('Verificando cookie...', 'info');
    
    await checkCookie();
    
    checkButton.disabled = false;
  });
  
  // Event listener para botão de enviar cookie
  sendButton.addEventListener('click', function() {
    sendButton.disabled = true;
    updateStatus('Enviando cookie...', 'info');
    
    // Envia mensagem para o background script
    chrome.runtime.sendMessage({
      action: "sendCookie"
    }, function(response) {
      sendButton.disabled = false;
      
      if (response && response.success) {
        updateStatus(response.message, 'success');
      } else {
        updateStatus(response ? response.message : 'Erro desconhecido', 'error');
      }
    });
  });
  
  // Verifica cookie automaticamente ao abrir popup
  checkCookie();
});