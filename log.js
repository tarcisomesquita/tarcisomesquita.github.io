let logToken = '';
let logEmail = '';

const set_cookie = (id,value) => {
  let expira = new Date((new Date()).getTime() + 365*24*3600*1000).toISOString();
  document.cookie = `${id}=${value};expires=${expira};path=/;`;
}

function getCookie(id) {
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

logToken = getCookie('token');
logEmail = getCookie('email');


if (logToken === '') {
  logToken = (Math.random().toString(36)+"00000000000").substring(2,13).toUpperCase();
  set_cookie('token', logToken);
}

if (logEmail === '') {
  logEmail = 'indefinido@gmail.com';
  set_cookie('email', logEmail);
}

let logMsg = `entry.340072360=${location.href};${logToken};${logEmail};${screen.width}x${screen.height};${navigator.deviceMemory};${navigator.userAgent.replace(/;/g,',')}`;

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
