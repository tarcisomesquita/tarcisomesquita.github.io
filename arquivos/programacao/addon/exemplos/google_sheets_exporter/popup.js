// Regex to check for a valid Google Sheets URL
const regex = /https:\/\/docs\.google\.com\/spreadsheets\/d\/([a-zA-Z0-9-_]+)\/edit\?gid=([0-9]+)/;

async function checkUrlAndToggleDisplay() {
  const [tab] = await browser.tabs.query({ active: true, currentWindow: true });

  if (regex.test(tab.url)) {
    document.getElementById("exportButton").style.display = "block";
    document.getElementById("invalidMessage").style.display = "none";
  } else {
    document.getElementById("exportButton").style.display = "none";
    document.getElementById("invalidMessage").style.display = "block";
  }
}

document.getElementById("exportButton").addEventListener("click", async () => {
  const [tab] = await browser.tabs.query({ active: true, currentWindow: true });
  const matches = tab.url.match(regex);

  if (matches && matches[1] && matches[2]) {
    const key = matches[1];
    const gid = matches[2];
    const exportUrl = `https://docs.google.com/spreadsheets/d/${key}/export?format=xlsx&gid=${gid}`;

    browser.tabs.create({ url: exportUrl });
  }
});

checkUrlAndToggleDisplay();
