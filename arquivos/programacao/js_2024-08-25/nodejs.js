
// https://nodejs.org/en/download/
// https://nodejs.org/download/docs/v16.15.1/api/
// export PATH=$PATH:/home/lubuntu/node-v16.15.1-linux-x64/bin/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

node -e 'console.log("OK")'
echo 'console.log("OK")' | node

echo 'console.log("My %s has %d ears", "cat", 2)' | node

// %s format a variable as a string
// %d format a variable as a number
// %i format a variable as its integer part only
// %o format a variable as an object

// Color the output
echo 'console.log("\x1b[33m%s\x1b[0m", "hi!")' | node

echo 'process.stdout.write("Teste saida\n");' | node

process.stdin returns a stream connected to stdin
process.stdout returns a stream connected to stdout
process.stderr returns a stream connected to stderr
fs.createReadStream() creates a readable stream to a file
fs.createWriteStream() creates a writable stream to a file
net.connect() initiates a stream-based connection
http.request() returns an instance of the http.ClientRequest class, which is a writable stream
zlib.createGzip() compress data using gzip (a compression algorithm) into a stream
zlib.createGunzip() decompress a gzip stream.
zlib.createDeflate() compress data using deflate (a compression algorithm) into a stream
zlib.createInflate() decompress a deflate stream

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
console.log("OK")
EOF

node app.js

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
console.log(process.argv);

process.argv.forEach((val, index) => {
  console.log(`${index}: ${val}`);
});

const args = process.argv.slice(2);
console.log(args[0]);
EOF

node app.js maria joão josé
node app.js name=joe

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

readline.question('Qual é o seu nome? ', name => {
  console.log(`Hi ${name}!`);
  readline.close();
});
EOF

node app.js

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const https = require('https');

function callback(response) {
  console.log(response.agent);
  if (response.statusCode === 200) {
  	response.on(
  	  'data', 
  	  data => {
        process.stdout.write(data);
  	  }
  	);
  }
  else {
  	console.log(response.httpVersion);
  	console.log(response.statusCode);
  	console.log(response.statusMessage);
  	console.log(' = = = = = = = = = = = = = = = = = = = =');
  	console.log(response.req.host);
  	console.log(response.req.path);
  	console.log(' = = = = = = = = = = = = = = = = = = = =');
  	console.log(response.req._header);
  	console.log(' = = = = = = = = = = = = = = = = = = = =');
  	console.log(response.headers['content-length']);
  	console.log(response.headers['content-type']);
  	console.log(response.headers['last-modified']);
  	console.log(' = = = = = = = = = = = = = = = = = = = =');
  }
}

const options = {
  hostname: 'tarcisomesquita.github.io',
  port: 443,
  path: '/ceejapd/',
  method: 'GET',
};

const request = https.request(options, callback);

request.on('error', error => {
  console.error(error);
});

request.end();
EOF

node app.js 

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const https = require('https');

const data = JSON.stringify({
  todo: 'Buy the milk',
});

const options = {
  hostname: 'localhost',
  port: 443,
  path: '/echo',
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
    'Content-Length': data.length,
  },
};

const req = https.request(options, res => {
  console.log(`statusCode: ${res.statusCode}`);

  res.on('data', d => {
    process.stdout.write(d);
  });
});

req.on('error', error => {
  console.error(error);
});

req.write(data);
req.end();
EOF

node app.js

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout privatekey.key -out certificate.crt
certificate.crt é o arquivo do certificado

cat > app.js << 'EOF'
const https = require('https');
const fs = require('fs');

const options = {
  key: fs.readFileSync('privatekey.key'),
  cert: fs.readFileSync('certificate.crt')  
};

https.createServer(options, (req, res) => {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end('Hello from HTTPS server!');
}).listen(443);

console.log('HTTPS server listening on port 443');
EOF

node app.js

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

const options = {
    hostname: 'seu-servidor.com',
    port: 443,
    path: '/api/dados',
    method: 'GET',
    cert: fs.readFileSync('client.crt'),
    key: fs.readFileSync('client.key') // Se necessário
};

https.request(options, (res) => {
  console.log(`statusCode: ${res.statusCode}`);

  res.on('data', (d) => {
    process.stdout.write(d);
  });
}).on('error', (error) => {
  console.error(error);  

});

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const http = require('node:http');

function requestListener(request, response) {
  console.log('Estou na função requestListener');
  
  response.statusCode = 200;
  response.setHeader('Content-Type', 'text/txt');
  response.write('Hello World!\n');
  response.end();
}

function callbackListen() {
  console.log('Listening on port 8000');
}

const server = http.createServer(requestListener);
server.listen(8000, callbackListen);
EOF

node app.js
wget -O - -q http://localhost:8000

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const http = require('node:http');

function requestListener(request, response) {
  console.log('');
  console.log(request.method);
  console.log(request.httpVersion);
  console.log(request.url);
  console.log(request.headers);
  
  response.statusCode = 200;
  response.setHeader('Content-Type', 'text/plain');
  response.write('OKK\n');
  
  console.log('');
  console.log(response.statusCode);
  console.log(response.statusMessage);
  console.log(response.outputData);
  console.log(response.outputSize);
  console.log(response.shouldKeepAlive);
  console.log(response._header);

  response.end();
}

function callbackListen() {
  console.log('Listening on port 8000');
}

const server = http.createServer(requestListener);
server.listen(8000, callbackListen);
EOF

node app.js
wget -O - -q http://localhost:8000

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const http = require('node:http');
const url = require('node:url');

function requestListener(request, response) {
  console.log(request.url);
  
  response.writeHead(200, {'Content-Type': 'text/html'});
  response.write(request.url + "<br>\n");
  
  let q = url.parse(request.url, true).query;
  let txt = q.year + "<br>\n" + q.month + "<br>\n";
  response.end(txt);
}

function callbackListen() {
  console.log('Listening on port 8000');
}

const server = http.createServer(requestListener);
server.listen(8000, callbackListen);
EOF

node app.js
wget -O - -q 'http://localhost:8000/?year=2017&month=July'

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const http = require('http');
const fs = require('fs');

const server = http.createServer((req, res) => {
//  const stream = fs.createReadStream(`${__dirname}/lixo_data.txt`);
  const stream = fs.createReadStream(`/dev/random`);
  stream.pipe(res); // Instead of waiting until the file is fully read, we start streaming it to the HTTP client as soon as we have a chunk of data ready to be sent.
});
server.listen(8000);
EOF

node app.js
wget -O - -q 'http://localhost:8000' | dd of=/dev/null status=progress

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const http = require('http');

function handler(request, response) {
  console.log(request.url);
  
  request.on('error', (err) => {
    console.error(err);
    response.statusCode = 400;
    response.end();
  });
  
  response.on('error', (err) => {
    console.error(err);
  });
  
  if (request.method === 'POST' && request.url === '/echo') {
    request.pipe(response); // devolve o que recebeu
  }
  else {
    console.error('ERRO');
    response.statusCode = 404;
    response.end();
  }
}

const server = http.createServer(handler);

server.listen(8000, () => {
  console.log(`Server running at https://localhost:8000/guest`);
});
EOF

node app.js

wget -O - -q --post-data='ls -l' https://localhost:8000/echo; echo ''

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

cat > app.js << 'EOF'
const hostname = '127.0.0.1';
const port = 3000;
const http = require('http');

const handler = (request, response) => {
  console.log(request.url);
  
  const { headers, method, url } = request;
  let body = [];
  
  request.on('error', (err) => {
    console.error(err);
  });
  
  request.on('data', (chunk) => {
    body.push(chunk);
  })
  
  request.on('end', () => {
    body = Buffer.concat(body).toString();
    
    response.on('error', (err) => {
      console.error(err);
    });

    response.statusCode = 200;
    response.setHeader('Content-Type', 'application/json');
    
    const responseBody = { headers, method, url, body };
    
    response.write(JSON.stringify(responseBody));
    response.end();
  });
}

const server = http.createServer(handler);

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
EOF

node app.js

wget -O - -q http://localhost:3000; echo ""

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

sudo apt-get install mysql-server
sudo mysql -u root

USE mysql;
CREATE USER 'testo'@'localhost' IDENTIFIED WITH mysql_native_password BY '1234aA@%';
GRANT ALL PRIVILEGES ON *.* TO 'testo'@'localhost';
FLUSH PRIVILEGES;
SELECT user, plugin, authentication_string FROM user;

mysql -u testo -p


SHOW DATABASES;
CREATE DATABASE pets;
USE pets;
CREATE TABLE cats
(
  id              INT unsigned NOT NULL AUTO_INCREMENT, # Unique ID for the record
  name            VARCHAR(150) NOT NULL,                # Name of the cat
  owner           VARCHAR(150) NOT NULL,                # Owner of the cat
  birth           DATE NOT NULL,                        # Birthday of the cat
  PRIMARY KEY     (id)                                  # Make the id the primary key
);

INSERT INTO cats ( name, owner, birth) VALUES
  ( 'Sandy', 'Lennon', '2015-01-03' ),
  ( 'Cookie', 'Casey', '2013-11-13' ),
  ( 'Charlie', 'River', '2016-05-21' );
  
SELECT * FROM cats;
SELECT name FROM cats WHERE owner = 'Casey';

cat > db_connection.js << 'EOF' 
var mysql = require('mysql');

var con = mysql.createConnection({
  host: 'localhost',
  user: 'testo',
  password: '1234aA@%',
  database: 'pets'
});

con.connect((err) => {
  if (err) {
    console.log(err.message);
    return;
  }
  console.log('Conectado');
});

var values = [
  ['John', 'Highway', '2015-01-03'],
  ['Viola', 'Sideway', '2016-05-21']
];
con.query('INSERT INTO cats (name, owner, birth) VALUES ?', [values], (err, response) => {
  if (err) {
    console.log(err.message);
    return;
  }
  
  console.log("Number of records inserted: " + response.affectedRows);
});

con.query('SELECT * FROM cats', (err, rows) => {
  if (err) {
    console.log(err.message);
    return;
  }
  
  console.log(JSON.stringify(rows));
  
  for (let i=0; i < rows.length; i++) {
    console.log(`${rows[i]['name']}\t\t${rows[i]['owner']}`);
  }
});

con.end((err) => {
  if (err) {
    console.log(err.message);
    return;
  }
  console.log('Conexão terminada');
});

EOF

node db_connection.js 


var http = require('http');
var fs = require('fs');
http.createServer(function (req, res) {
  fs.readFile('demofile1.html', function(err, data) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write(data);
    return res.end();
  });
}).listen(8080);

var fs = require('fs');

fs.appendFile('mynewfile1.txt', 'Hello content!', function (err) {
  if (err) throw err;
  console.log('Saved!');
});


var fs = require('fs');

fs.appendFile('mynewfile1.txt', ' This is my text.', function (err) {
  if (err) throw err;
  console.log('Updated!');
}); 

The fs.writeFile() method replaces the specified file and content

Delete "mynewfile2.txt":
var fs = require('fs');

fs.unlink('mynewfile2.txt', function (err) {
  if (err) throw err;
  console.log('File deleted!');
}); 


var fs = require('fs');

fs.rename('mynewfile1.txt', 'myrenamedfile.txt', function (err) {
  if (err) throw err;
  console.log('File Renamed!');
}); 




https://nodejs.org/en/docs/guides/anatomy-of-an-http-transaction/

https://www.mysqltutorial.org/mysql-nodejs/

https://medium.com/baixada-nerd/criando-um-crud-completo-com-nodejs-express-e-mongodb-parte-2-3-220a127d586f



 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// Assume add.wasm file exists that contains a single function adding 2 provided arguments
const fs = require('fs');

const wasmBuffer = fs.readFileSync('/path/to/add.wasm');
WebAssembly.instantiate(wasmBuffer).then(wasmModule => {
  // Exported function live under instance.exports
  const { add } = wasmModule.instance.exports;
  const sum = add(5, 6);
  console.log(sum); // Outputs: 11
});

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


const http = require('http');
const fs = require('fs');

const server = http.createServer(function (req, res) {
  fs.readFile(`${__dirname}/data.txt`, (err, data) => {
    res.end(data);
  });
});
server.listen(3000);

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

const buf = Buffer.alloc(1024);
const buf = Buffer.from('Hey!');
console.log(buf[0]); // 72
console.log(buf[1]); // 101
console.log(buf[2]); // 121
console.log(buf.toString());
console.log(buf.length);
for (const item of buf) {
  console.log(item); // 72 101 121 33
}
buf.write('Hey!');
const bufcopy = Buffer.alloc(4); // allocate 4 bytes
bufcopy.set(buf);

const buf = Buffer.from('Hey?');
const bufcopy = Buffer.from('Moo!');
bufcopy.set(buf.subarray(1, 3), 1);
console.log(bufcopy.toString()); // 'Mey!'

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

require('path').basename('/test/something.txt'); // something.txt
require('path').dirname('/test/something/file.txt'); // /test/something
require('path').extname('/test/something/file.txt'); // '.txt'
require('path').format({ root: '/Users/joe', name: 'test', ext: '.txt' }); //  '/Users/joe/test.txt'
require('path').parse('/users/test.txt');
results in
{
  root: '/',
  dir: '/users',
  base: 'test.txt',
  ext: '.txt',
  name: 'test'
}

require('path').resolve('joe.txt'); // '/Users/joe/joe.txt' if run from my home folder


 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
https://nodejs.dev/learn/the-nodejs-fs-module
https://nodejs.dev/learn/writing-files-with-nodejs
https://nodejs.dev/learn/reading-files-with-nodejs

fs.stat('/Users/joe/test.txt', (err, stats) => {
  if (err) {
    console.error(err);
  }
  // we have access to the file stats in `stats`
});

blocks the thread until the file stats are ready:
const fs = require('fs');
try {
  const stats = fs.statSync('/Users/joe/test.txt');
} catch (err) {
  console.error(err);
}

const fs = require('fs/promises');
async function example() {
  try {
    const stats = await fs.stat('/Users/joe/test.txt');
    stats.isFile(); // true
    stats.isDirectory(); // false
    stats.isSymbolicLink(); // false
    stats.size; // 1024000 //= 1MB
  } catch (err) {
    console.log(err);
  }
}
example();


fs.open('/Users/joe/test.txt', 'r', (err, fd) => {
  // fd is our file descriptor
});

Other flags you'll commonly use are:
    r+ open the file for reading and writing, if file doesn't exist it won't be created.
    w+ open the file for reading and writing, positioning the stream at the beginning of the file. The file is created if not existing.
    a open the file for writing, positioning the stream at the end of the file. The file is created if not existing.
    a+ open the file for reading and writing, positioning the stream at the end of the file. The file is created if not existing.

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


https://nodejs.dev/learn/modern-asynchronous-javascript-with-async-and-await

https://nodejs.dev/learn/understanding-javascript-promises
https://nodejs.dev/learn/javascript-asynchronous-programming-and-callbacks

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
