
import './translate-help-pages.js';

document.getElementById('open-firefox-downloads-folder').addEventListener('click', function() {
    browser.downloads.showDefaultFolder();
});
