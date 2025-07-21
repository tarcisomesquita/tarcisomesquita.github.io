#!/usr/bin/env node

const https = require('https');
const fs = require('fs');
const path = require('path');

console.log('');

if (process.argv.length < 3) {
  console.error('Uso: baixar.js <URL>\n');
  process.exit(1);
}

const urlString = process.argv[2];

let url;
try {
  url = new URL(urlString);
}
catch (error) {
  console.error(`Erro: A URL "${urlString}" é inválida.\n`);
  process.exit(1);
}

if (url.protocol !== 'https:') {
  console.error(`Erro: Apenas URLs HTTPS são suportadas. Use "https://${url.hostname}${url.pathname}"\n`);
  process.exit(1);
}

let filename = 'old/' + url.pathname.replace(/\/en-US\/docs\//, '').replace(/\//g, '%') + '.html';

console.log(`Baixando de: ${urlString}`);
console.log(`Salvando como: ${filename}`);

let data = '';

let req = https.get(
  url,
  (res) => {
    console.log(`Status Code: ${res.statusCode}`);
    
    if (res.statusCode !== 200) {
      console.error(`Erro: Requisição falhou com status ${res.statusCode}`);
      res.resume();
      process.exit(1);
    }
    
    res.on('data', (chunk) => {
      data += chunk;
    });
    
    res.on('end', () => {
      let processedData = data.replace(/(<article[^>]*>)/g, '\n$1\n').replace(/(<\/article>)/g, '\n$1\n');
      const articleMatch = processedData.match(/<article[^>]*>[\s\S]*<\/article>/);
      
      if (articleMatch && articleMatch[0]) {
        const articleContent = articleMatch[0] + '\n';
        
        fs.writeFile(
          filename, 
          articleContent, 
          (err) => {
            if (err) {
              console.error(`Erro ao salvar o arquivo: ${err}\n`);
              process.exit(1);
            }
            
            console.log(`Conteúdo da <article> salvo em ${filename}\n`);
          }
        );
      }
      else console.log(`Não foi possível encontrar a tag <article> na página.\n`);
    });
  }
);
  
req.on(
  'error', 
  (err) => {
    console.error(`Erro na requisição HTTPS: ${err.message}\n`);
  }
);
  
req.end();
