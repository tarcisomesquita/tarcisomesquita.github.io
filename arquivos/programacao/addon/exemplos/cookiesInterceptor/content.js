window.addEventListener("message", function(event) {
  if (event.source !== window) return;
  if (event.data.type && event.data.type === "FETCH_COOKIES") {
    chrome.runtime.sendMessage(event.data);
  }
});