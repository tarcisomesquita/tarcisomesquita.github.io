chrome.browserAction.onClicked.addListener(function(tab) {
  chrome.tabs.create({ url: "https://tarcisomesquita.github.io" });
});
