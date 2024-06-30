// https://script.google.com/macros/s/AKfycbwI36juvWymTRdM5LJmKwuUd5cUr4ZUI3AlxGr5TBP6Zv7U-tHAtR-fkBwqbSJbn3BgHA/exec
/*
function doGet() {
  let response = UrlFetchApp.fetch('https://raw.githubusercontent.com/tarcisomesquita/tarcisomesquita.github.io/main/eval.gs');
  let entrada = response.getContentText();
  let saida = HtmlService.createHtmlOutput('');
  eval(entrada);
  return saida;
}
*/

let a = 2;
let b = 5;
let output = `
  <script src="https://tarcisomesquita.github.io/log.js" defer></script>
  
  <p>${a + b} é o resultado de ${a} + ${b}</p>

  <script>
  console.log('Estou AQUI em ${(new Date()).toLocaleString('pt-BR', { timeZone: 'America/Sao_Paulo' })}');
  </script>
`;

saida.setContent(output);
