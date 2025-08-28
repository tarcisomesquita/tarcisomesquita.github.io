function renderRequests(requests) {
  const container = document.getElementById('requests');
  container.innerHTML = '';
  if (!requests || requests.length === 0) {
    container.textContent = 'Nenhuma requisição interceptada.';
    return;
  }
  requests.reverse().forEach(req => {
    const div = document.createElement('div');
    div.className = 'request';
    div.innerHTML = `
      <div class="url">${req.url}</div>
      <div><b>Cookies:</b> <span class="cookie">${req.cookies || '(Nenhum cookie disponível)'}</span></div>
      <div><b>Horário:</b> ${req.time}</div>
    `;
    container.appendChild(div);
  });
}

chrome.storage.local.get('interceptedRequests', (data) => {
  renderRequests(data.interceptedRequests);
});