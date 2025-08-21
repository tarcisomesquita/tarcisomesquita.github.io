const validPattern = /https:\/\/docs\.google\.com\/spreadsheets\/d\/([a-zA-Z0-9-_]+)\/edit\?gid=([0-9]+)/;

const updateIcon = (tabId, url) => {
  const iconPath = validPattern.test(url) ? "icon-enabled-128.png" : "icon-disabled-128.png";
  browser.browserAction.setIcon({
    path: {
      "128": iconPath
    },
    tabId: tabId
  });
};


browser.tabs.onUpdated.addListener((tabId, changeInfo, tab) => {
  if (changeInfo.url) {
    updateIcon(tabId, changeInfo.url);
  }
});

browser.tabs.onActivated.addListener(async (activeInfo) => {
  const tab = await browser.tabs.get(activeInfo.tabId);
  updateIcon(tab.id, tab.url);
});
