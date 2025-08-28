let interceptedRequests = [];

chrome.runtime.onMessage.addListener((msg, sender, sendResponse) => {
  if (msg.type === "FETCH_COOKIES") {
    interceptedRequests.push({
      url: msg.url,
      cookies: msg.cookies,
      options: msg.options,
      time: new Date().toISOString()
    });
    chrome.storage.local.set({ interceptedRequests });
  }
});

// Recebe do content.js via window.postMessage -> chrome.runtime.sendMessage
chrome.runtime.onConnect.addListener(function(port) {
  port.onMessage.addListener(function(msg) {
    if (msg.type === "FETCH_COOKIES") {
      interceptedRequests.push({
        url: msg.url,
        cookies: msg.cookies,
        options: msg.options,
        time: new Date().toISOString()
      });
      chrome.storage.local.set({ interceptedRequests });
    }
  });
});

// Limpa ao instalar
chrome.runtime.onInstalled.addListener(() => {
  interceptedRequests = [];
  chrome.storage.local.set({ interceptedRequests });
});