wget -O teste.txt \
--header='user-agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36' \
--header='content-type: application/x-www-form-urlencoded;charset=UTF-8' \
--header='referer: https://script.google.com/macros/s/AKfycbwPLqZbVlalxIbSpChnAwKsigsr9wT_HH7PgGt64GSILFn1l34SUyttHGgtHlmJHmQpKQ/exec' \
--header='x-same-domain: 1' \
--post-data='request=%5B%22route%22%2C%22%5B%5C%22%7B%20%5C%5C%5C%22id%5C%5C%5C%22%3A%20%5C%5C%5C%22passaporte%5C%5C%5C%22%2C%20%5C%5C%5C%22usuario%5C%5C%5C%22%3A%20%5C%5C%5C%22sed.decourt%40gmail.com%5C%5C%5C%22%2C%20%5C%5C%5C%22token%5C%5C%5C%22%3A%5C%5C%5C%226VM4ERUOP7U%5C%5C%5C%22%2C%20%5C%5C%5C%22matricula%5C%5C%5C%22%3A%5C%5C%5C%22232546%5C%5C%5C%22%20%7D%5C%22%5D%22%2Cnull%2C%5B0%5D%2Cnull%2Cnull%2C1%2C0%5D' \
'https://script.google.com/macros/s/AKfycbwPLqZbVlalxIbSpChnAwKsigsr9wT_HH7PgGt64GSILFn1l34SUyttHGgtHlmJHmQpKQ/callback'


function textFinder() {
  let inicio = Date.now();
  let planilha_values = SpreadsheetApp.openById('ID').getSheets()[0].getDataRange().getDisplayValues();
  
  for (let i = 0; i < planilha_values.length; i++) {
    for (let j = 0; j < planilha_values[i].length; j++) {
      if (/hotmail/.test(String(planilha_values[i][j]))) Logger.log(planilha_values[i][j]);
    }
  }
  Logger.log(`Tempo gasto: ${Date.now() - inicio} ms`);
}

function uploadFile() {
  try {
    // Makes a request to fetch a URL.
    const image = UrlFetchApp.fetch('http://goo.gl/nd7zjB').getBlob();
    let file = {
      title: 'google_logo.png',
      mimeType: 'image/png'
    };
    // Insert new files to user's Drive
    file = Drive.Files.insert(file, image);
    Logger.log('ID: %s, File size (bytes): %s', file.id, file.fileSize);
  }
  catch (err) {
    console.log('Failed to upload file with error %s', err.message);
  }
}

function coordenadas() {
  //var results = Maps.newGeocoder().geocode('Rua Amélia Bueno Camargo, Jardim Santana, Campinas').results;
  var results = Maps.newGeocoder().reverseGeocode(-22.833720, -47.096172);

  Logger.log(JSON.stringify(results))
}

/**
 * Função para mostrar um exemplo de JSDoc.
 * @see https://example.com
 * 
 * @param {string} argumento1 Primeiro parâmetro.
 * @param {string} argumento2 Segundo parâmetro.
 * @param {boolean} argumento2 Terceiro parâmetro.
 * @returns {Array} Valor retornado.
 * @example Aplicação 1
 * 
 * let t = teste('abc', 'dc', True);
 * 
 * let t2 = teste('abc', 'dc', False);
 */
function teste(argumento1 = 'valor padrão', argumento2, argumento3) {
  return [];
}

/*
number: Números inteiros ou decimais.
string: Textos.
boolean: Valores lógicos (true ou false).
Date: Datas.
Object: Objetos personalizados.
Array: Arrays.
*/


https://support.google.com/docs/answer/3093281?hl=pt-br
Função GOOGLEFINANCE
https://www.google.com/finance/quote/VALE3:BVMF

=GOOGLEFINANCE("BVMF:BBAS3")

=GOOGLEFINANCE("TICKER", "ATRIBUTO")

https://support.google.com/docs/answer/3093281?hl=pt-BR

function obterValorDaCelulaComFormula() {
  var spreadsheet = SpreadsheetApp.getActiveSpreadsheet();
  var sheet = spreadsheet.getActiveSheet();

  // Insere a fórmula na célula A1
  sheet.getRange("A1").setFormula('=GOOGLEFINANCE("AAPL", "price")');

  // Espera um pouco para garantir que a fórmula seja calculada (opcional)
  SpreadsheetApp.flush();

  // Obtém o valor da célula A1
  var valor = sheet.getRange("A1").getValue();

  // Exibe o valor no log
  Logger.log('O valor da cotação da Apple é: ' + valor);
}



https://developers.google.com/apps-script/samples/automations/equipment-requests?hl=pt-br
cria formulário

https://developers.google.com/apps-script/samples/automations/offsite-activity-signup?hl=pt-br
cria formulário

https://developers.google.com/apps-script/samples/automations/timesheets?hl=pt-br
cria formulário

https://developers.google.com/apps-script/samples/automations/employee-certificate?hl=pt-br
cria certificados e envia por email

https://developers.google.com/apps-script/samples/automations/event-session-signup?hl=pt-br
cria formulário

https://developers.google.com/apps-script/samples/automations/generate-pdfs?hl=pt-br
converte planilha em pdf

const emailTo = Session.getEffectiveUser().getEmail();

https://developers.google.com/apps-script/samples/automations/import-csv-sheets?hl=pt-br
importa csv para planilha

https://developers.google.com/apps-script/samples/automations/upload-files?hl=pt-br

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

function doGet(request) {
  var events = CalendarApp.getEvents(
    new Date(Number(request.parameters.start) * 1000),
    new Date(Number(request.parameters.end) * 1000));
  var result = {
    available: events.length == 0
  };
  return ContentService.createTextOutput(JSON.stringify(result))
    .setMimeType(ContentService.MimeType.JSON);
}

Como antes, publique-o como um app da Web anônimo para que ele funcione. Nesse caso, os usuários do novo serviço podem usá-lo adicionando parâmetros de URL ao final da chamada URL do serviço. Os parâmetros start e end fornecem um período para verificação. especificado na época padrão do Unix.

curl -L URL_OF_YOUR_SCRIPT?start=1325437200&end=1325439000

O serviço retornará um JSON que informa se há algo em seu agenda nesse intervalo.

{"available":true}

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

function doGet(request) {
  var events = CalendarApp.getEvents(
    new Date(Number(request.parameters.start) * 1000),
    new Date(Number(request.parameters.end) * 1000));
  var result = {
    available: events.length == 0
  };
  return ContentService.createTextOutput(
    request.parameters.prefix + '(' + JSON.stringify(result) + ')')
    .setMimeType(ContentService.MimeType.JAVASCRIPT);
}

Para chamar esse serviço em um navegador, crie uma tag de script com o atributo src é o URL do seu serviço, com um parâmetro adicional chamado prefix. Isso é o nome da função no JavaScript do lado do cliente que será chamada pelo valor retornado pelo serviço.

<script src="URL_OF_YOUR_SCRIPT?start=1325437200&end=1325439000&prefix=alert"></script>

alert({"available":true})

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

https://developers.google.com/identity/protocols/oauth2/scopes?hl=pt-br
https://www.googleapis.com/auth/script.external_request
https://www.googleapis.com/auth/spreadsheets
https://www.googleapis.com/auth/spreadsheets.readonly
https://www.googleapis.com/auth/drive
https://www.googleapis.com/auth/drive.readonly
https://mail.google.com/
https://www.googleapis.com/auth/gmail.modify
https://www.googleapis.com/auth/gmail.readonly
https://www.googleapis.com/auth/gmail.send
https://www.googleapis.com/auth/forms

appsscript.json
{
  "access": "ANYONE_ANONYMOUS",
  "executeAs": "USER_DEPLOYING",
  "timeZone": "America/Sao_Paulo",
  "oauthScopes": [
    "https://www.googleapis.com/auth/spreadsheets.readonly",
    "https://www.googleapis.com/auth/userinfo.email"
  ],
  "dependencies": {
},
  "exceptionLogging": "NONE",
  "runtimeVersion": "V8"
}
