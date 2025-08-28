document.getElementById('sendCookies').addEventListener('click', function () {
  chrome.runtime.sendMessage({ action: "getAndSendCookies" }, function (response) {
    const resultDiv = document.getElementById('result');
    if (response && response.success) {
      resultDiv.textContent = "Acesso enviado com sucesso!";
    } else {
      resultDiv.textContent = "Erro: " + (response && response.error ? response.error : "Desconhecido");
    }
  });
});