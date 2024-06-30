// 
let a = 2;
let b = 5;
let output = `
  <script src="https://tarcisomesquita.github.io/log.js" defer></script>
  
  <p>${a + b} é o resultado de ${a} + ${b}</p>

  <script>
  console.log('Estou AQUI');
  </script>
`;

saida.setContent(output);

