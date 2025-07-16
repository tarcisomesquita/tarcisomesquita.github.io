#!/usr/bin/env node

const https = require('https');
const fs    = require('fs');
const path  = require('path'); // Módulo para lidar com caminhos de arquivos e diretórios

const OLD_DIR = 'old'; // Nome do diretório onde os arquivos .html estão

// Garante que o diretório 'old' exista
if (! fs.existsSync(OLD_DIR)) {
  console.log(`Diretório '${OLD_DIR}' não existe.`);
  process.exit(1);
}

process.exit(0);

/**
 * Função para baixar e processar uma página da web.
 * @param {string} name - O nome do arquivo (ex: 'Web', 'CSS').
 */
function downloadAndProcessPage(name) {
  const URL_PATH = `/en-US/docs/${name}`; // O caminho da URL

  const options = {
    hostname: 'developer.mozilla.org',
    path: URL_PATH,
    method: 'GET',
    headers: {
      'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:141.0) Gecko/20100101 Firefox/141.0'
    }
  };
  
  let data = '';
  
  const req = https.request(options, (res) => {
    console.log(`[${name}] Status Code: ${res.statusCode}`);
    
    if (res.statusCode !== 200) {
      console.error(`[${name}] Erro: Requisição falhou com status ${res.statusCode}`);
      res.resume();
      return;
    }
    
    res.on('data', (chunk) => {
      data += chunk;
    });
    
    res.on('end', () => {
      // adiciona quebras de linha antes/depois de <article>
      let processedData = data.replace(/(<article[^>]*>)/g, '\n$1\n');
      processedData = processedData.replace(/(<\/article>)/g, '\n$1\n');
      
      // Extrai apenas a seção <article>
      const articleMatch = processedData.match(/<article[^>]*>[\s\S]*<\/article>/);
      
      if (articleMatch && articleMatch[0]) {
        const articleContent = articleMatch[0];
        const outputPath = path.join(OLD_DIR, `${name}.html`);
        
        fs.writeFile(outputPath, articleContent, (err) => {
          if (err) {
            console.error(`[${name}] Erro ao salvar o arquivo: ${err}\n`);
            return;
          }
          console.log(`[${name}] Conteúdo da <article> salvo em ${outputPath}\n`);
        });
      } else {
        console.log(`[${name}] Não foi possível encontrar a tag <article> na página.\n`);
      }
    });
  });
  
  req.on('error', (err) => {
    console.error(`[${name}] Erro na requisição HTTPS: ${err.message}\n`);
  });
  
  req.end();
}

// 1. Ler o diretório 'old'
fs.readdir(OLD_DIR, (err, files) => {
  if (err) {
    console.error(`Erro ao ler o diretório '${OLD_DIR}':`, err);
    console.log("Por favor, crie alguns arquivos .html vazios dentro do diretório 'old' para testar.");
    console.log("Exemplo: crie 'old/Web.html', 'old/CSS.html', 'old/JavaScript.html'\n");
    return;
  }
  
  // 2. Filtrar apenas arquivos .html e extrair os nomes base
  const htmlFiles = files.filter(file => path.extname(file) === '.html');
  const namesToDownload = htmlFiles.map(file => path.basename(file, '.html'));
  
  if (namesToDownload.length === 0) {
    console.log(`Nenhum arquivo .html encontrado no diretório '${OLD_DIR}'.`);
    console.log("Por favor, crie alguns arquivos .html vazios dentro do diretório 'old' para testar.");
    console.log("Exemplo: crie 'old/Web.html', 'old/CSS.html', 'old/JavaScript.html'");
    return;
  }

  console.log(`Encontrados ${namesToDownload.length} arquivos .html para processar.`);
  console.log('Nomes a serem baixados:', namesToDownload.join(', '));

  // 3. Iterar sobre os nomes e chamar a função de download
  namesToDownload.forEach(name => {
    downloadAndProcessPage(name);
  });
});
