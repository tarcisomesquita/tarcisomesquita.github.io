function loggetCookie(id) {
  let name = id + "=";
  let ca = document.cookie.split(';');
  for(let i = 0; i < ca.length; i++) {
    let c = ca[i];
    while (c.charAt(0) == ' ') c = c.substring(1);
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  return '';
}

function logsend() {
  let logCookie = loggetCookie('logCookie');
  let logEmail = loggetCookie('usuario');
  //console.log(`loggetCookie() > logCookie = ${logCookie}`);

  if (logCookie === '') {
    logCookie = (Math.random().toString(36) + "00000000000").substring(2,13).toUpperCase();
    document.cookie = `logCookie=${logCookie};expires=2025-01-01T00:00:00.000Z;path=/;samesite=none;secure;`;
  }
  //console.log(`loggetCookie() > logCookie = ${logCookie}`);
  
  // definido em 2023/09/22
  let logMsg = `entry.340072360=${document.URL};${logCookie};${logEmail};${screen.width}x${screen.height};${navigator.deviceMemory}GiB;${navigator.userAgent.replace(/;/g,',')};${document.referrer}`;
  
  // to log_pagina
  fetch(
    'https://docs.google.com/forms/u/0/d/e/1FAIpQLScGwq8tvtiFUjhTQ58SlhN0b9rymqGGeXbJJoFB2YWks4FSPA/formResponse', 
    {
      method: 'POST',
      mode: 'no-cors',
      credentials: 'omit',
      headers: {  
        'Content-type': 'application/x-www-form-urlencoded;charset=utf-8'
      },
     'body': encodeURI(logMsg)
    }
  );
}

