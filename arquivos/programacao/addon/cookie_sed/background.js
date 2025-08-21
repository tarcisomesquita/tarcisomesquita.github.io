let filter = browser.webRequest.filterResponseData(details.requestId);
filter.ondata = (event) => {
  console.log(`filter.ondata received ${event.data.byteLength} bytes`);
  filter.write(event.data);
};
filter.onstop = (event) => {
  // The extension should always call filter.close() or filter.disconnect()
  // after creating the StreamFilter, otherwise the response is kept alive forever.
  // If processing of the response data is finished, use close. If any remaining
  // response data should be processed by Firefox, use disconnect.
  filter.close();
};


await fetch("https://sed.educacao.sp.gov.br/Inicio", {
  "headers": {
    },
    "method": "GET",
    "mode": "cors"
});