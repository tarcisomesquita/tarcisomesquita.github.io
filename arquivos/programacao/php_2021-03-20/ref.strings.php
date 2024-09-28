<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="pt_BR">
<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: Fun&ccedil;&otilde;es para String - Manual </title>

 <link rel="shortcut icon" href="https://www.php.net/favicon.ico">
 <link rel="search" type="application/opensearchdescription+xml" href="http://php.net/phpnetimprovedsearch.src" title="Add PHP.net search">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/releases/feed.php" title="PHP Release feed">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/feed.atom" title="PHP: Hypertext Preprocessor">

 <link rel="canonical" href="https://www.php.net/manual/pt_BR/ref.strings.php">
 <link rel="shorturl" href="https://www.php.net/strings">
 <link rel="alternate" href="https://www.php.net/strings" hreflang="x-default">

 <link rel="contents" href="https://www.php.net/manual/pt_BR/index.php">
 <link rel="index" href="https://www.php.net/manual/pt_BR/book.strings.php">
 <link rel="prev" href="https://www.php.net/manual/pt_BR/string.constants.php">
 <link rel="next" href="https://www.php.net/manual/pt_BR/function.addcslashes.php">

 <link rel="alternate" href="https://www.php.net/manual/en/ref.strings.php" hreflang="en">
 <link rel="alternate" href="https://www.php.net/manual/pt_BR/ref.strings.php" hreflang="pt_BR">
 <link rel="alternate" href="https://www.php.net/manual/zh/ref.strings.php" hreflang="zh">
 <link rel="alternate" href="https://www.php.net/manual/fr/ref.strings.php" hreflang="fr">
 <link rel="alternate" href="https://www.php.net/manual/de/ref.strings.php" hreflang="de">
 <link rel="alternate" href="https://www.php.net/manual/ja/ref.strings.php" hreflang="ja">
 <link rel="alternate" href="https://www.php.net/manual/ro/ref.strings.php" hreflang="ro">
 <link rel="alternate" href="https://www.php.net/manual/ru/ref.strings.php" hreflang="ru">
 <link rel="alternate" href="https://www.php.net/manual/es/ref.strings.php" hreflang="es">
 <link rel="alternate" href="https://www.php.net/manual/tr/ref.strings.php" hreflang="tr">

<link rel="stylesheet" type="text/css" href="/cached.php?t=1539771603&amp;f=/fonts/Fira/fira.css" media="screen">
<link rel="stylesheet" type="text/css" href="/cached.php?t=1539765004&amp;f=/fonts/Font-Awesome/css/fontello.css" media="screen">
<link rel="stylesheet" type="text/css" href="/cached.php?t=1540425603&amp;f=/styles/theme-base.css" media="screen">
<link rel="stylesheet" type="text/css" href="/cached.php?t=1540425603&amp;f=/styles/theme-medium.css" media="screen">

 <!--[if lte IE 7]>
 <link rel="stylesheet" type="text/css" href="https://www.php.net/styles/workarounds.ie7.css" media="screen">
 <![endif]-->

 <!--[if lte IE 8]>
 <script>
  window.brokenIE = true;
 </script>
 <![endif]-->

 <!--[if lte IE 9]>
 <link rel="stylesheet" type="text/css" href="https://www.php.net/styles/workarounds.ie9.css" media="screen">
 <![endif]-->

 <!--[if IE]>
 <script src="https://www.php.net/js/ext/html5.js"></script>
 <![endif]-->

 <base href="https://www.php.net/manual/pt_BR/ref.strings.php">

</head>
<body class="docs ">

<nav id="head-nav" class="navbar navbar-fixed-top">
  <div class="navbar-inner clearfix">
    <a href="/" class="brand"><img src="/images/logos/php-logo.svg" width="48" height="24" alt="php"></a>
    <div id="mainmenu-toggle-overlay"></div>
    <input type="checkbox" id="mainmenu-toggle">
    <ul class="nav">
      <li class=""><a href="/downloads">Downloads</a></li>
      <li class="active"><a href="/docs.php">Documentation</a></li>
      <li class=""><a href="/get-involved" >Get Involved</a></li>
      <li class=""><a href="/support">Help</a></li>
    </ul>
    <form class="navbar-search" id="topsearch" action="/search.php">
      <input type="hidden" name="show" value="quickref">
      <input type="search" name="pattern" class="search-query" placeholder="Search" accesskey="s">
    </form>
  </div>
  <div id="flash-message"></div>
</nav>
<nav id="trick"><div><dl>
<dt><a href='/manual/en/getting-started.php'>Getting Started</a></dt>
	<dd><a href='/manual/en/introduction.php'>Introduction</a></dd>
	<dd><a href='/manual/en/tutorial.php'>A simple tutorial</a></dd>
<dt><a href='/manual/en/langref.php'>Language Reference</a></dt>
	<dd><a href='/manual/en/language.basic-syntax.php'>Basic syntax</a></dd>
	<dd><a href='/manual/en/language.types.php'>Types</a></dd>
	<dd><a href='/manual/en/language.variables.php'>Variables</a></dd>
	<dd><a href='/manual/en/language.constants.php'>Constants</a></dd>
	<dd><a href='/manual/en/language.expressions.php'>Expressions</a></dd>
	<dd><a href='/manual/en/language.operators.php'>Operators</a></dd>
	<dd><a href='/manual/en/language.control-structures.php'>Control Structures</a></dd>
	<dd><a href='/manual/en/language.functions.php'>Functions</a></dd>
	<dd><a href='/manual/en/language.oop5.php'>Classes and Objects</a></dd>
	<dd><a href='/manual/en/language.namespaces.php'>Namespaces</a></dd>
	<dd><a href='/manual/en/language.errors.php'>Errors</a></dd>
	<dd><a href='/manual/en/language.exceptions.php'>Exceptions</a></dd>
	<dd><a href='/manual/en/language.generators.php'>Generators</a></dd>
	<dd><a href='/manual/en/language.references.php'>References Explained</a></dd>
	<dd><a href='/manual/en/reserved.variables.php'>Predefined Variables</a></dd>
	<dd><a href='/manual/en/reserved.exceptions.php'>Predefined Exceptions</a></dd>
	<dd><a href='/manual/en/reserved.interfaces.php'>Predefined Interfaces and Classes</a></dd>
	<dd><a href='/manual/en/context.php'>Context options and parameters</a></dd>
	<dd><a href='/manual/en/wrappers.php'>Supported Protocols and Wrappers</a></dd>
</dl>
<dl>
<dt><a href='/manual/en/security.php'>Security</a></dt>
	<dd><a href='/manual/en/security.intro.php'>Introduction</a></dd>
	<dd><a href='/manual/en/security.general.php'>General considerations</a></dd>
	<dd><a href='/manual/en/security.cgi-bin.php'>Installed as CGI binary</a></dd>
	<dd><a href='/manual/en/security.apache.php'>Installed as an Apache module</a></dd>
	<dd><a href='/manual/en/security.sessions.php'>Session Security</a></dd>
	<dd><a href='/manual/en/security.filesystem.php'>Filesystem Security</a></dd>
	<dd><a href='/manual/en/security.database.php'>Database Security</a></dd>
	<dd><a href='/manual/en/security.errors.php'>Error Reporting</a></dd>
	<dd><a href='/manual/en/security.globals.php'>Using Register Globals</a></dd>
	<dd><a href='/manual/en/security.variables.php'>User Submitted Data</a></dd>
	<dd><a href='/manual/en/security.magicquotes.php'>Magic Quotes</a></dd>
	<dd><a href='/manual/en/security.hiding.php'>Hiding PHP</a></dd>
	<dd><a href='/manual/en/security.current.php'>Keeping Current</a></dd>
<dt><a href='/manual/en/features.php'>Features</a></dt>
	<dd><a href='/manual/en/features.http-auth.php'>HTTP authentication with PHP</a></dd>
	<dd><a href='/manual/en/features.cookies.php'>Cookies</a></dd>
	<dd><a href='/manual/en/features.sessions.php'>Sessions</a></dd>
	<dd><a href='/manual/en/features.xforms.php'>Dealing with XForms</a></dd>
	<dd><a href='/manual/en/features.file-upload.php'>Handling file uploads</a></dd>
	<dd><a href='/manual/en/features.remote-files.php'>Using remote files</a></dd>
	<dd><a href='/manual/en/features.connection-handling.php'>Connection handling</a></dd>
	<dd><a href='/manual/en/features.persistent-connections.php'>Persistent Database Connections</a></dd>
	<dd><a href='/manual/en/features.safe-mode.php'>Safe Mode</a></dd>
	<dd><a href='/manual/en/features.commandline.php'>Command line usage</a></dd>
	<dd><a href='/manual/en/features.gc.php'>Garbage Collection</a></dd>
	<dd><a href='/manual/en/features.dtrace.php'>DTrace Dynamic Tracing</a></dd>
</dl>
<dl>
<dt><a href='/manual/en/funcref.php'>Function Reference</a></dt>
	<dd><a href='/manual/en/refs.basic.php.php'>Affecting PHP's Behaviour</a></dd>
	<dd><a href='/manual/en/refs.utilspec.audio.php'>Audio Formats Manipulation</a></dd>
	<dd><a href='/manual/en/refs.remote.auth.php'>Authentication Services</a></dd>
	<dd><a href='/manual/en/refs.utilspec.cmdline.php'>Command Line Specific Extensions</a></dd>
	<dd><a href='/manual/en/refs.compression.php'>Compression and Archive Extensions</a></dd>
	<dd><a href='/manual/en/refs.creditcard.php'>Credit Card Processing</a></dd>
	<dd><a href='/manual/en/refs.crypto.php'>Cryptography Extensions</a></dd>
	<dd><a href='/manual/en/refs.database.php'>Database Extensions</a></dd>
	<dd><a href='/manual/en/refs.calendar.php'>Date and Time Related Extensions</a></dd>
	<dd><a href='/manual/en/refs.fileprocess.file.php'>File System Related Extensions</a></dd>
	<dd><a href='/manual/en/refs.international.php'>Human Language and Character Encoding Support</a></dd>
	<dd><a href='/manual/en/refs.utilspec.image.php'>Image Processing and Generation</a></dd>
	<dd><a href='/manual/en/refs.remote.mail.php'>Mail Related Extensions</a></dd>
	<dd><a href='/manual/en/refs.math.php'>Mathematical Extensions</a></dd>
	<dd><a href='/manual/en/refs.utilspec.nontext.php'>Non-Text MIME Output</a></dd>
	<dd><a href='/manual/en/refs.fileprocess.process.php'>Process Control Extensions</a></dd>
	<dd><a href='/manual/en/refs.basic.other.php'>Other Basic Extensions</a></dd>
	<dd><a href='/manual/en/refs.remote.other.php'>Other Services</a></dd>
	<dd><a href='/manual/en/refs.search.php'>Search Engine Extensions</a></dd>
	<dd><a href='/manual/en/refs.utilspec.server.php'>Server Specific Extensions</a></dd>
	<dd><a href='/manual/en/refs.basic.session.php'>Session Extensions</a></dd>
	<dd><a href='/manual/en/refs.basic.text.php'>Text Processing</a></dd>
	<dd><a href='/manual/en/refs.basic.vartype.php'>Variable and Type Related Extensions</a></dd>
	<dd><a href='/manual/en/refs.webservice.php'>Web Services</a></dd>
	<dd><a href='/manual/en/refs.utilspec.windows.php'>Windows Only Extensions</a></dd>
	<dd><a href='/manual/en/refs.xml.php'>XML Manipulation</a></dd>
	<dd><a href='/manual/en/refs.ui.php'>GUI Extensions</a></dd>
</dl>
<dl>
<dt>Keyboard Shortcuts</dt><dt>?</dt>
<dd>This help</dd>
<dt>j</dt>
<dd>Next menu item</dd>
<dt>k</dt>
<dd>Previous menu item</dd>
<dt>g p</dt>
<dd>Previous man page</dd>
<dt>g n</dt>
<dd>Next man page</dd>
<dt>G</dt>
<dd>Scroll to bottom</dd>
<dt>g g</dt>
<dd>Scroll to top</dd>
<dt>g h</dt>
<dd>Goto homepage</dd>
<dt>g s</dt>
<dd>Goto search<br>(current page)</dd>
<dt>/</dt>
<dd>Focus search box</dd>
</dl></div></nav>
<div id="goto">
    <div class="search">
         <div class="text"></div>
         <div class="results"><ul></ul></div>
   </div>
</div>

  <div id="breadcrumbs" class="clearfix">
    <div id="breadcrumbs-inner">
          <div class="next">
        <a href="function.addcslashes.php">
          addcslashes &raquo;
        </a>
      </div>
              <div class="prev">
        <a href="string.constants.php">
          &laquo; Constantes pr&eacute;-definidas        </a>
      </div>
          <ul>
            <li><a href='index.php'>Manual do PHP</a></li>      <li><a href='funcref.php'>Refer&ecirc;ncia das Fun&ccedil;&otilde;es</a></li>      <li><a href='refs.basic.text.php'>Processamento de Texto</a></li>      <li><a href='book.strings.php'>Strings</a></li>      </ul>
    </div>
  </div>




<div id="layout" class="clearfix">
  <section id="layout-content">
  <div class="page-tools">
    <div class="change-language">
      <form action="/manual/change.php" method="get" id="changelang" name="changelang">
        <fieldset>
          <label for="changelang-langs">Change language:</label>
          <select onchange="document.changelang.submit()" name="page" id="changelang-langs">
            <option value='en/ref.strings.php'>English</option>
            <option value='pt_BR/ref.strings.php' selected="selected">Brazilian Portuguese</option>
            <option value='zh/ref.strings.php'>Chinese (Simplified)</option>
            <option value='fr/ref.strings.php'>French</option>
            <option value='de/ref.strings.php'>German</option>
            <option value='ja/ref.strings.php'>Japanese</option>
            <option value='ro/ref.strings.php'>Romanian</option>
            <option value='ru/ref.strings.php'>Russian</option>
            <option value='es/ref.strings.php'>Spanish</option>
            <option value='tr/ref.strings.php'>Turkish</option>
            <option value="help-translate.php">Other</option>
          </select>
        </fieldset>
      </form>
    </div>
    <div class="edit-bug">
      <a href="https://edit.php.net/?project=PHP&amp;perm=pt_BR/ref.strings.php">Edit</a>
      <a href="https://bugs.php.net/report.php?bug_type=Documentation+problem&amp;manpage=ref.strings">Report a Bug</a>
    </div>
  </div><div id="ref.strings" class="reference">
 <h1 class="title">Funções para String</h1>

 <div class="partintro">
  <h1 class="title">Veja Também</h1>
  <p class="para">
   Para funções de manuseio de string mais poderosas, de uma olhada em
   <a href="ref.regex.php" class="link">funções de expressão regular POSIX</a>
   e <a href="ref.pcre.php" class="link">funções de expressão regular
   compatíveis com Perl </a>.
  </p>
 </div>

 













  





  



































  

















  





  





































  



















  







  





  














  







  

























  












  





  






  











  












  

















  












  











  




































  






  










































  












  






  











  











  





  


















  






  












  












  






  


















  
















































  






  





















































<h2>Índice</h2><ul class="chunklist chunklist_reference"><li><a href="function.addcslashes.php">addcslashes</a> — String entre aspas com barras no estilo C</li><li><a href="function.addslashes.php">addslashes</a> — Adiciona barras invertidas a uma string</li><li><a href="function.bin2hex.php">bin2hex</a> — Converte um dado bin&aacute;rio em representa&ccedil;&atilde;o hexadecimal</li><li><a href="function.chop.php">chop</a> — Sin&ocirc;nimo de rtrim</li><li><a href="function.chr.php">chr</a> — Retorna um caracter espec&iacute;fico</li><li><a href="function.chunk-split.php">chunk_split</a> — Divide uma string em pequenos peda&ccedil;os</li><li><a href="function.convert-cyr-string.php">convert_cyr_string</a> — Converte de um conjunto caracteres cir&iacute;lico para outro</li><li><a href="function.convert-uudecode.php">convert_uudecode</a> — Decodifica uma string codificada com uuencode</li><li><a href="function.convert-uuencode.php">convert_uuencode</a> — Codifica com uuencode uma string</li><li><a href="function.count-chars.php">count_chars</a> — Retorna informa&ccedil;&otilde;es sobre os caracteres usados numa string</li><li><a href="function.crc32.php">crc32</a> — Calcula polin&ocirc;mio crc32 de uma string</li><li><a href="function.crypt.php">crypt</a> — Encripta&ccedil;&atilde;o unidirecional de string (hashing)</li><li><a href="function.echo.php">echo</a> — Exibe uma ou mais strings</li><li><a href="function.explode.php">explode</a> — Divide uma string em strings</li><li><a href="function.fprintf.php">fprintf</a> — Escreve uma string formatada para um stream</li><li><a href="function.get-html-translation-table.php">get_html_translation_table</a> — Retorna a tabela de tradu&ccedil;&atilde;o usada por htmlspecialchars e htmlentities</li><li><a href="function.hebrev.php">hebrev</a> — Converte texto l&oacute;gico Hebraico para texto visual</li><li><a href="function.hebrevc.php">hebrevc</a> — Converte um texto l&oacute;gico Hebr&aacute;ico para um texto visual com convers&atilde;o newline</li><li><a href="function.hex2bin.php">hex2bin</a> — Decodes a hexadecimally encoded binary string</li><li><a href="function.html-entity-decode.php">html_entity_decode</a> — Converte todas as entidades HTML para os seus caracteres</li><li><a href="function.htmlentities.php">htmlentities</a> — Converte todos os caracteres aplic&aacute;veis em entidades html.</li><li><a href="function.htmlspecialchars-decode.php">htmlspecialchars_decode</a> — Converte especiais entidades HTML para caracteres</li><li><a href="function.htmlspecialchars.php">htmlspecialchars</a> — Converte caracteres especiais para a realidade HTML</li><li><a href="function.implode.php">implode</a> — Junta elementos de uma matriz em uma string</li><li><a href="function.join.php">join</a> — Sin&ocirc;nimo de implode</li><li><a href="function.lcfirst.php">lcfirst</a> — Torna min&uacute;sculo o primeiro caractere de uma string</li><li><a href="function.levenshtein.php">levenshtein</a> — Calcula a dist&acirc;ncia Levenshtein entre duas strings</li><li><a href="function.localeconv.php">localeconv</a> — Obt&eacute;m a informa&ccedil;&atilde;o da formata&ccedil;&atilde;o num&eacute;rica</li><li><a href="function.ltrim.php">ltrim</a> — Retira espa&ccedil;os em branco (ou outros caracteres) do in&iacute;cio da string</li><li><a href="function.md5-file.php">md5_file</a> — Calcula hash md5 de um dado arquivo</li><li><a href="function.md5.php">md5</a> — Calcula o &quot;hash MD5&quot; de uma string</li><li><a href="function.metaphone.php">metaphone</a> — Calcula a metaphone key de uma string</li><li><a href="function.money-format.php">money_format</a> — Formata um n&uacute;mero como uma string de moeda</li><li><a href="function.nl-langinfo.php">nl_langinfo</a> — Retorna informa&ccedil;&atilde;o de linguagem e local</li><li><a href="function.nl2br.php">nl2br</a> — Insere quebras de linha HTML antes de todas newlines em uma string</li><li><a href="function.number-format.php">number_format</a> — Formata um n&uacute;mero com os milhares agrupados</li><li><a href="function.ord.php">ord</a> — Retorna o valor ASCII do caractere</li><li><a href="function.parse-str.php">parse_str</a> — Converte a string em vari&aacute;veis</li><li><a href="function.print.php">print</a> — Mostra uma string</li><li><a href="function.printf.php">printf</a> — Mostra uma string formatada</li><li><a href="function.quoted-printable-decode.php">quoted_printable_decode</a> — Converte uma string quoted-printable para uma string de 8 bit</li><li><a href="function.quoted-printable-encode.php">quoted_printable_encode</a> — Converte uma string de 8 bits em uma string quoted-printable</li><li><a href="function.quotemeta.php">quotemeta</a> — Adiciona uma barra invertida antes dos meta caracteres</li><li><a href="function.rtrim.php">rtrim</a> — Retira espa&ccedil;o em branco (ou outros caracteres) do final da string</li><li><a href="function.setlocale.php">setlocale</a> — Define informa&ccedil;&otilde;es locais</li><li><a href="function.sha1-file.php">sha1_file</a> — Calcula a hash sha1 de um arquivo</li><li><a href="function.sha1.php">sha1</a> — Calcula a hash sha1 de uma string</li><li><a href="function.similar-text.php">similar_text</a> — Calcula a similaridade entre duas strings</li><li><a href="function.soundex.php">soundex</a> — Calcula a chave soundex de uma string</li><li><a href="function.sprintf.php">sprintf</a> — Retorna a string formatada</li><li><a href="function.sscanf.php">sscanf</a> — Interpreta a entrada de uma string de acordo com um formato</li><li><a href="function.str-getcsv.php">str_getcsv</a> — Analisa uma string CSV e retorna os dados em um array</li><li><a href="function.str-ireplace.php">str_ireplace</a> — Vers&atilde;o que n&atilde;o diferencia mai&uacute;sculas e min&uacute;sculas de str_replace.</li><li><a href="function.str-pad.php">str_pad</a> — Preenche uma string para um certo tamanho com outra string</li><li><a href="function.str-repeat.php">str_repeat</a> — Repete uma string</li><li><a href="function.str-replace.php">str_replace</a> — Substitui todas as ocorr&ecirc;ncias da string de procura com a string de substitui&ccedil;&atilde;o</li><li><a href="function.str-rot13.php">str_rot13</a> — Executa a transforma&ccedil;&atilde;o rot13 em uma string</li><li><a href="function.str-shuffle.php">str_shuffle</a> — Mistura uma string aleatoriamente</li><li><a href="function.str-split.php">str_split</a> — Converte uma string para um array</li><li><a href="function.str-word-count.php">str_word_count</a> — Retorna informa&ccedil;&atilde;o sobre as palavras usadas em uma string</li><li><a href="function.strcasecmp.php">strcasecmp</a> — Compara&ccedil;&atilde;o de strings sem diferenciar mai&uacute;sculas e min&uacute;sculas segura para bin&aacute;rio</li><li><a href="function.strchr.php">strchr</a> — Sin&ocirc;nimo de strstr</li><li><a href="function.strcmp.php">strcmp</a> — Compara&ccedil;&atilde;o de string segura para bin&aacute;rio</li><li><a href="function.strcoll.php">strcoll</a> — Compara&ccedil;&atilde;o de string baseada no local</li><li><a href="function.strcspn.php">strcspn</a> — Encontra o tamanho do segmento inicial que n&atilde;o contenha a m&aacute;scara</li><li><a href="function.strip-tags.php">strip_tags</a> — Retira as tags HTML e PHP de uma string</li><li><a href="function.stripcslashes.php">stripcslashes</a> — Desfaz o efeito de addcslashes</li><li><a href="function.stripos.php">stripos</a> — Encontra a primeira ocorrencia de uma string sem diferenciar mai&uacute;sculas e min&uacute;sculas</li><li><a href="function.stripslashes.php">stripslashes</a> — Desfaz o efeito de addslashes</li><li><a href="function.stristr.php">stristr</a> — strstr sem diferenciar mai&uacute;sculas e min&uacute;sculas</li><li><a href="function.strlen.php">strlen</a> — Retorna o tamanho de uma string</li><li><a href="function.strnatcasecmp.php">strnatcasecmp</a> — Compara&ccedil;&atilde;o de strings sem diferenciar mai&uacute;sculas/min&uacute;sculas usando o algoritmo &quot;natural order&quot;</li><li><a href="function.strnatcmp.php">strnatcmp</a> — Compara&ccedil;&atilde;o de strings usando o algoritmo &quot;natural order&quot;</li><li><a href="function.strncasecmp.php">strncasecmp</a> — Compara&ccedil;&atilde;o de string caso-sensitivo de Bin&aacute;rio seguro dos primeiros n caracteres</li><li><a href="function.strncmp.php">strncmp</a> — Compara&ccedil;&atilde;o de string segura para bin&aacute;rio para os primeiros n caracteres</li><li><a href="function.strpbrk.php">strpbrk</a> — Procura na string por um dos caracteres de um conjunto</li><li><a href="function.strpos.php">strpos</a> — Encontra a posi&ccedil;&atilde;o da primeira ocorr&ecirc;ncia de uma string</li><li><a href="function.strrchr.php">strrchr</a> — Encontra a ultima ocorr&ecirc;ncia de um caractere em uma string</li><li><a href="function.strrev.php">strrev</a> — Reverte uma string</li><li><a href="function.strripos.php">strripos</a> — Encontra a posi&ccedil;&atilde;o da &uacute;ltima ocorr&ecirc;ncia de uma string case-insensitive em uma string</li><li><a href="function.strrpos.php">strrpos</a> — Encontra a posi&ccedil;&atilde;o da &uacute;ltima ocorr&ecirc;ncia de um caractere em uma string</li><li><a href="function.strspn.php">strspn</a> — Encontra o comprimento do segmento inicial combinando com a m&aacute;scara</li><li><a href="function.strstr.php">strstr</a> — Encontra a primeira ocorrencia de uma string</li><li><a href="function.strtok.php">strtok</a> — Tokeniza uma string</li><li><a href="function.strtolower.php">strtolower</a> — Converte uma string para min&uacute;sculas</li><li><a href="function.strtoupper.php">strtoupper</a> — Converte uma string para mai&uacute;sculas</li><li><a href="function.strtr.php">strtr</a> — Traduz certos caracteres</li><li><a href="function.substr-compare.php">substr_compare</a> — A compara&ccedil;&atilde;o bin&aacute;ria entre duas strings de um offset at&eacute; o limite do comprimento de caracteres</li><li><a href="function.substr-count.php">substr_count</a> — Conta o n&uacute;mero de ocorr&ecirc;ncias de uma substring</li><li><a href="function.substr-replace.php">substr_replace</a> — Substitui o texto dentro de uma parte de uma string</li><li><a href="function.substr.php">substr</a> — Retorna uma parte de uma string</li><li><a href="function.trim.php">trim</a> — Retira espa&ccedil;o no &iacute;nicio e final de uma string</li><li><a href="function.ucfirst.php">ucfirst</a> — Converte para mai&uacute;scula o primeiro caractere de uma string</li><li><a href="function.ucwords.php">ucwords</a> — Converte para mai&uacute;sculas o primeiro caractere de cada palavra</li><li><a href="function.vfprintf.php">vfprintf</a> — Escreve uma string formatada para um stream</li><li><a href="function.vprintf.php">vprintf</a> — Mostra uma string formatada</li><li><a href="function.vsprintf.php">vsprintf</a> — Retorna uma string formatada</li><li><a href="function.wordwrap.php">wordwrap</a> — Quebra uma string em um dado n&uacute;mero de caracteres</li></ul>
</div>

<section id="usernotes">
 <div class="head">
  <span class="action"><a href="/manual/add-note.php?sect=ref.strings&amp;redirect=https://www.php.net/manual/pt_BR/ref.strings.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></span>
  <h3 class="title">User Contributed Notes <span class="count">23 notes</span></h3>
 </div><div id="allnotes">
  <div class="note" id="53834">  <div class="votes">
    <div id="Vu53834">
    <a href="/manual/vote-note.php?id=53834&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd53834">
    <a href="/manual/vote-note.php?id=53834&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V53834" title="47% like this...">
    -3
    </div>
  </div>
  <a href="#53834" class="name">
  <strong class="user"><em>t0russ at gmail dot com</em></strong></a><a class="genanchor" href="#53834"> &para;</a><div class="date" title="2005-06-14 10:38"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom53834">
<div class="phpcode"><code><span class="html">
to kristin at greenaple dot on dot ca:<br />thanx for sharing.<br />your function in recursive form proved to be slightly faster and it returns false (as it should) when the character is not found instead of number 0:<br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">strnposr</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$needle</span><span class="keyword">, </span><span class="default">$occurance</span><span class="keyword">, </span><span class="default">$pos </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; return (</span><span class="default">$occurance</span><span class="keyword">&lt;</span><span class="default">2</span><span class="keyword">)?</span><span class="default">strpos</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$needle</span><span class="keyword">, </span><span class="default">$pos</span><span class="keyword">):</span><span class="default">strnposr</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">,</span><span class="default">$needle</span><span class="keyword">,</span><span class="default">$occurance</span><span class="keyword">-</span><span class="default">1</span><span class="keyword">,</span><span class="default">strpos</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$needle</span><span class="keyword">, </span><span class="default">$pos</span><span class="keyword">) + </span><span class="default">1</span><span class="keyword">);<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="48368">  <div class="votes">
    <div id="Vu48368">
    <a href="/manual/vote-note.php?id=48368&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd48368">
    <a href="/manual/vote-note.php?id=48368&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V48368" title="43% like this...">
    -3
    </div>
  </div>
  <a href="#48368" class="name"><strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#48368"> &para;</a><div class="date" title="2004-12-20 08:31"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom48368">
<div class="phpcode"><code><span class="html">
In response to hackajar &lt;matt&gt; yahoo &lt;trot&gt; com,<br /><br />No string-to-array function exists because it is not needed. If you reference a string with an offset like you do with an array, the character at that offset will be return. This is documented in section III.11's "Strings" article under the "String access and modification by character" heading.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="81937">  <div class="votes">
    <div id="Vu81937">
    <a href="/manual/vote-note.php?id=81937&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd81937">
    <a href="/manual/vote-note.php?id=81937&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V81937" title="44% like this...">
    -5
    </div>
  </div>
  <a href="#81937" class="name">
  <strong class="user"><em>Verdauga</em></strong></a><a class="genanchor" href="#81937"> &para;</a><div class="date" title="2008-03-19 06:06"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom81937">
<div class="phpcode"><code><span class="html">
Just a note in regards to bloopletech a few posts down:<br /><br />The word "and" should not be used when converting numbers to text.&nbsp; "And" (at least in US English) should only be used to indicate the decimal place.<br /><br />Example:<br />1,796,706 =&gt; one million, seven hundred ninety-six thousand, seven hundred six.<br />594,359.34 =&gt; five hundred ninety four thousand, three hundred fifty nine and thirty four hundredths</span>
</code></div>
  </div>
 </div>
  <div class="note" id="62307">  <div class="votes">
    <div id="Vu62307">
    <a href="/manual/vote-note.php?id=62307&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd62307">
    <a href="/manual/vote-note.php?id=62307&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V62307" title="44% like this...">
    -5
    </div>
  </div>
  <a href="#62307" class="name">
  <strong class="user"><em>SteveRusin</em></strong></a><a class="genanchor" href="#62307"> &para;</a><div class="date" title="2006-02-24 11:00"><strong>13 years ago</strong></div>
  <div class="text" id="Hcom62307">
<div class="phpcode"><code><span class="html">
The functions below:<br /><br />function beginsWith( $str, $sub ) <br />function endsWith( $str, $sub ) <br /><br />Are correct, but flawed.&nbsp; You'd need to use the === operator instead:<br /><br />function beginsWith( $str, $sub ) {<br />&nbsp;&nbsp; return ( substr( $str, 0, strlen( $sub ) ) === $sub );<br />}<br />function endsWith( $str, $sub ) {<br />&nbsp;&nbsp; return ( substr( $str, strlen( $str ) - strlen( $sub ) ) === $sub );<br />}<br /><br />Otherwise, endsWith would return "foobar.0" ends with ".0" as well as "0" or "00" or any amount of zeros because numerically .0 does equal 0.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="44652">  <div class="votes">
    <div id="Vu44652">
    <a href="/manual/vote-note.php?id=44652&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd44652">
    <a href="/manual/vote-note.php?id=44652&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V44652" title="44% like this...">
    -5
    </div>
  </div>
  <a href="#44652" class="name">
  <strong class="user"><em>terry dot greenlaw at logicalshift dot com</em></strong></a><a class="genanchor" href="#44652"> &para;</a><div class="date" title="2004-08-11 10:52"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom44652">
<div class="phpcode"><code><span class="html">
Here's a simpler "simplest" way to toggle through a set of 1..n colors for web backgrounds:<br /><br /><span class="default">&lt;?php<br />$colours </span><span class="keyword">= array(</span><span class="string">'#000000'</span><span class="keyword">, </span><span class="string">'#808080'</span><span class="keyword">, </span><span class="string">'#A0A0A0'</span><span class="keyword">, </span><span class="string">'#FFFFFF'</span><span class="keyword">);<br /><br /></span><span class="comment">// Get a colour<br /></span><span class="default">$color </span><span class="keyword">= </span><span class="default">next</span><span class="keyword">(</span><span class="default">$colors</span><span class="keyword">) or </span><span class="default">$color </span><span class="keyword">= </span><span class="default">reset</span><span class="keyword">(</span><span class="default">$colors</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />The code doesn't need to know anything about the number of elements being cycled through. That way you won't have to tracking down all the code when changing the number of colors or the color values.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="68504">  <div class="votes">
    <div id="Vu68504">
    <a href="/manual/vote-note.php?id=68504&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd68504">
    <a href="/manual/vote-note.php?id=68504&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V68504" title="43% like this...">
    -5
    </div>
  </div>
  <a href="#68504" class="name">
  <strong class="user"><em>admin at rotarymulundeast dot org</em></strong></a><a class="genanchor" href="#68504"> &para;</a><div class="date" title="2006-07-30 03:16"><strong>13 years ago</strong></div>
  <div class="text" id="Hcom68504">
<div class="phpcode"><code><span class="html">
Here's an easier way to find nth...<br /><br />function nth($numbex){<br />&nbsp; if ($numbex%10 == 1 &amp;&amp; $numbex%100 != 11) $sth='st';<br />&nbsp; elseif ($numbex%10 == 2 &amp;&amp; $numbex%100 != 12) $sth='nd';<br />&nbsp; elseif ($numbex%10 == 3 &amp;&amp; $numbex%100 != 13) $sth='rd';<br />&nbsp; else $sth = 'th';<br />&nbsp; return $sth;<br />}<br /><br />there is is no need to check if the user has entered a non-integer as we may be using this function for expressing variables as well eg. ith value of x , nth root of z ,etc...</span>
</code></div>
  </div>
 </div>
  <div class="note" id="47276">  <div class="votes">
    <div id="Vu47276">
    <a href="/manual/vote-note.php?id=47276&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd47276">
    <a href="/manual/vote-note.php?id=47276&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V47276" title="44% like this...">
    -5
    </div>
  </div>
  <a href="#47276" class="name">
  <strong class="user"><em>andy a t onesandzeros d o t biz</em></strong></a><a class="genanchor" href="#47276"> &para;</a><div class="date" title="2004-11-09 02:54"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom47276">
<div class="phpcode"><code><span class="html">
I use these little doo-dads quite a bit. I just thought I'd share them and maybe save someone a little time. No biggy. :)<br /><br />// returns true if $str begins with $sub<br />function beginsWith( $str, $sub ) {<br />&nbsp; &nbsp; return ( substr( $str, 0, strlen( $sub ) ) == $sub );<br />}<br /><br />// return tru if $str ends with $sub<br />function endsWith( $str, $sub ) {<br />&nbsp; &nbsp; return ( substr( $str, strlen( $str ) - strlen( $sub ) ) == $sub );<br />}<br /><br />// trims off x chars from the front of a string<br />// or the matching string in $off is trimmed off<br />function trimOffFront( $off, $str ) {<br />&nbsp; &nbsp; if( is_numeric( $off ) )<br />&nbsp; &nbsp; &nbsp; &nbsp; return substr( $str, $off );<br />&nbsp; &nbsp; else<br />&nbsp; &nbsp; &nbsp; &nbsp; return substr( $str, strlen( $off ) );<br />}<br /><br />// trims off x chars from the end of a string<br />// or the matching string in $off is trimmed off<br />function trimOffEnd( $off, $str ) {<br />&nbsp; &nbsp; if( is_numeric( $off ) )<br />&nbsp; &nbsp; &nbsp; &nbsp; return substr( $str, 0, strlen( $str ) - $off );<br />&nbsp; &nbsp; else<br />&nbsp; &nbsp; &nbsp; &nbsp; return substr( $str, 0, strlen( $str ) - strlen( $off ) );<br />}</span>
</code></div>
  </div>
 </div>
  <div class="note" id="112605">  <div class="votes">
    <div id="Vu112605">
    <a href="/manual/vote-note.php?id=112605&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd112605">
    <a href="/manual/vote-note.php?id=112605&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V112605" title="42% like this...">
    -6
    </div>
  </div>
  <a href="#112605" class="name">
  <strong class="user"><em>str at maphpia dot com</em></strong></a><a class="genanchor" href="#112605"> &para;</a><div class="date" title="2013-07-03 08:19"><strong>6 years ago</strong></div>
  <div class="text" id="Hcom112605">
<div class="phpcode"><code><span class="html">
I was looking for a function to find the common substring in 2 different strings. I tried both the mb_string_intersect and string_intersect functions listed here but didn't work for me. I found the algorithm at <a href="http://en.wikibooks.org/wiki/Algorithm_implementation/Strings/Longest_common_substring#PHP" rel="nofollow" target="_blank">http://en.wikibooks.org/wiki/Algorithm_implementation/Strings/Longest_common_substring#PHP</a> so here I post you the function<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="comment">/**<br /> * Finds the matching string between 2 strings<br /> *<br /> * @param string $string1<br /> * @param string $string2<br /> * @param number $minChars<br /> *<br /> * @return NULL|string<br /> *<br /> * @link <a href="http://en.wikibooks.org/wiki/Algorithm_implementation/Strings/Longest_common_substring#PHP" rel="nofollow" target="_blank">http://en.wikibooks.org/wiki/Algorithm_implementation/Strings/Longest_common_substring#PHP</a><br /> */<br /></span><span class="keyword">function </span><span class="default">string_intersect</span><span class="keyword">(</span><span class="default">$string_1</span><span class="keyword">, </span><span class="default">$string_2</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="default">$string_1_length </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$string_1</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$string_2_length </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$string_2</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$return&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">= </span><span class="string">""</span><span class="keyword">;<br /><br />&nbsp; &nbsp; if (</span><span class="default">$string_1_length </span><span class="keyword">=== </span><span class="default">0 </span><span class="keyword">|| </span><span class="default">$string_2_length </span><span class="keyword">=== </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// No similarities<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">return </span><span class="default">$return</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="default">$longest_common_subsequence </span><span class="keyword">= array();<br /><br />&nbsp; &nbsp; </span><span class="comment">// Initialize the CSL array to assume there are no similarities<br />&nbsp; &nbsp; </span><span class="keyword">for (</span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$i </span><span class="keyword">&lt; </span><span class="default">$string_1_length</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">++) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">] = array();<br />&nbsp; &nbsp; &nbsp; &nbsp; for (</span><span class="default">$j </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$j </span><span class="keyword">&lt; </span><span class="default">$string_2_length</span><span class="keyword">; </span><span class="default">$j</span><span class="keyword">++) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">][</span><span class="default">$j</span><span class="keyword">] = </span><span class="default">0</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="default">$largest_size </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">;<br /><br />&nbsp; &nbsp; for (</span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$i </span><span class="keyword">&lt; </span><span class="default">$string_1_length</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">++) {<br />&nbsp; &nbsp; &nbsp; &nbsp; for (</span><span class="default">$j </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$j </span><span class="keyword">&lt; </span><span class="default">$string_2_length</span><span class="keyword">; </span><span class="default">$j</span><span class="keyword">++) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// Check every combination of characters<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">if (</span><span class="default">$string_1</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">] === </span><span class="default">$string_2</span><span class="keyword">[</span><span class="default">$j</span><span class="keyword">]) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// These are the same in both strings<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">if (</span><span class="default">$i </span><span class="keyword">=== </span><span class="default">0 </span><span class="keyword">|| </span><span class="default">$j </span><span class="keyword">=== </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// It's the first character, so it's clearly only 1 character long<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">][</span><span class="default">$j</span><span class="keyword">] = </span><span class="default">1</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// It's one character longer than the string from the previous character<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">][</span><span class="default">$j</span><span class="keyword">] = </span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i </span><span class="keyword">- </span><span class="default">1</span><span class="keyword">][</span><span class="default">$j </span><span class="keyword">- </span><span class="default">1</span><span class="keyword">] + </span><span class="default">1</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">][</span><span class="default">$j</span><span class="keyword">] &gt; </span><span class="default">$largest_size</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// Remember this as the largest<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$largest_size </span><span class="keyword">= </span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">][</span><span class="default">$j</span><span class="keyword">];<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// Wipe any previous results<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$return&nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">= </span><span class="string">""</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// And then fall through to remember this new value<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">}<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$longest_common_subsequence</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">][</span><span class="default">$j</span><span class="keyword">] === </span><span class="default">$largest_size</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// Remember the largest string(s)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$return </span><span class="keyword">= </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$string_1</span><span class="keyword">, </span><span class="default">$i </span><span class="keyword">- </span><span class="default">$largest_size </span><span class="keyword">+ </span><span class="default">1</span><span class="keyword">, </span><span class="default">$largest_size</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// Else, $CSL should be set to 0, which it was already initialized to<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">}<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="comment">// Return the list of matches<br />&nbsp; &nbsp; </span><span class="keyword">return </span><span class="default">$return</span><span class="keyword">;<br />}</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="57877">  <div class="votes">
    <div id="Vu57877">
    <a href="/manual/vote-note.php?id=57877&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd57877">
    <a href="/manual/vote-note.php?id=57877&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V57877" title="43% like this...">
    -6
    </div>
  </div>
  <a href="#57877" class="name"><strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#57877"> &para;</a><div class="date" title="2005-10-17 03:27"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom57877">
<div class="phpcode"><code><span class="html">
to: james dot d dot baker at gmail dot com<br /><br />PHP has a builtin function&nbsp; for doing what your function does,<br /><br /><a href="http://php.net/ucfirst" rel="nofollow" target="_blank">http://php.net/ucfirst</a><br /><a href="http://php.net/ucwords" rel="nofollow" target="_blank">http://php.net/ucwords</a></span>
</code></div>
  </div>
 </div>
  <div class="note" id="87116">  <div class="votes">
    <div id="Vu87116">
    <a href="/manual/vote-note.php?id=87116&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd87116">
    <a href="/manual/vote-note.php?id=87116&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V87116" title="42% like this...">
    -7
    </div>
  </div>
  <a href="#87116" class="name">
  <strong class="user"><em>Stephen Dewey</em></strong></a><a class="genanchor" href="#87116"> &para;</a><div class="date" title="2008-11-19 05:33"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom87116">
<div class="phpcode"><code><span class="html">
If you want a function to return all text in a string up to the Nth occurrence of a substring, try the below function.<br /><br />Works in PHP &gt;= 5.<br /><br />(Pommef provided another sample function for this purpose below, but I believe it is incorrect.)<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="comment">// Returns all of $haystack up to (but excluding) the $n_occurrence occurrence of $needle. Therefore:<br />//&nbsp; &nbsp; &nbsp; &nbsp; If there are &lt; $n_occurrence occurrences of $needle in $haystack, the entire string will be returned.<br />//&nbsp; &nbsp; &nbsp; &nbsp; If there are &gt;= $n_occurrence occurrences of $needle in $haystack, the returned string will end before the $n_occurrence'th needle.<br />// This function only makes sense for $n_occurrence &gt;= 1<br /></span><span class="keyword">function </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="default">$needle</span><span class="keyword">, </span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$n_occurrence</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="comment">// After exploding by $needle, every entry in $arr except (possibly) part of the last entry should have its content returned.<br />&nbsp; &nbsp; </span><span class="default">$arr </span><span class="keyword">= </span><span class="default">explode</span><span class="keyword">(</span><span class="default">$needle</span><span class="keyword">,</span><span class="default">$haystack</span><span class="keyword">,</span><span class="default">$n_occurrence</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="comment">// Examine last entry in $arr. If it contains $needle, cut out all text except for the text before $needle.<br />&nbsp; &nbsp; </span><span class="default">$last </span><span class="keyword">= </span><span class="default">count</span><span class="keyword">(</span><span class="default">$arr</span><span class="keyword">) - </span><span class="default">1</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$pos_in_last </span><span class="keyword">= </span><span class="default">strpos</span><span class="keyword">(</span><span class="default">$arr</span><span class="keyword">[</span><span class="default">$last</span><span class="keyword">],</span><span class="default">$needle</span><span class="keyword">);<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; if (</span><span class="default">$pos_in_last </span><span class="keyword">!== </span><span class="default">false</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arr</span><span class="keyword">[</span><span class="default">$last</span><span class="keyword">] = </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$arr</span><span class="keyword">[</span><span class="default">$last</span><span class="keyword">],</span><span class="default">0</span><span class="keyword">,</span><span class="default">$pos_in_last</span><span class="keyword">);<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; return </span><span class="default">implode</span><span class="keyword">(</span><span class="default">$needle</span><span class="keyword">,</span><span class="default">$arr</span><span class="keyword">);<br />}<br /><br /></span><span class="default">$string </span><span class="keyword">= </span><span class="string">'d24jkdslgjldk2424jgklsjg24jskgldjk24'</span><span class="keyword">;<br /><br />print </span><span class="string">'S:&nbsp; ' </span><span class="keyword">. </span><span class="default">$string </span><span class="keyword">. </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br />print </span><span class="string">'1: ' </span><span class="keyword">. </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'24'</span><span class="keyword">,</span><span class="default">$string</span><span class="keyword">,</span><span class="default">1</span><span class="keyword">) . </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br />print </span><span class="string">'2: ' </span><span class="keyword">. </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'24'</span><span class="keyword">,</span><span class="default">$string</span><span class="keyword">,</span><span class="default">2</span><span class="keyword">) . </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br />print </span><span class="string">'3: ' </span><span class="keyword">. </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'24'</span><span class="keyword">,</span><span class="default">$string</span><span class="keyword">,</span><span class="default">3</span><span class="keyword">) . </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br />print </span><span class="string">'4: ' </span><span class="keyword">. </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'24'</span><span class="keyword">,</span><span class="default">$string</span><span class="keyword">,</span><span class="default">4</span><span class="keyword">) . </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br />print </span><span class="string">'5: ' </span><span class="keyword">. </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'24'</span><span class="keyword">,</span><span class="default">$string</span><span class="keyword">,</span><span class="default">5</span><span class="keyword">) . </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br />print </span><span class="string">'6: ' </span><span class="keyword">. </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'24'</span><span class="keyword">,</span><span class="default">$string</span><span class="keyword">,</span><span class="default">6</span><span class="keyword">) . </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br />print </span><span class="string">'7: ' </span><span class="keyword">. </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'24'</span><span class="keyword">,</span><span class="default">$string</span><span class="keyword">,</span><span class="default">7</span><span class="keyword">) . </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;<br /><br /></span><span class="comment">/*<br />// prints:<br />S: d24jkdslgjldk2424jgklsjg24jskgldjk24<br />1: d<br />2: d24jkdslgjldk<br />3: d24jkdslgjldk24<br />4: d24jkdslgjldk2424jgklsjg<br />5: d24jkdslgjldk2424jgklsjg24jskgldjk<br />6: d24jkdslgjldk2424jgklsjg24jskgldjk24<br />7: d24jkdslgjldk2424jgklsjg24jskgldjk24<br />*/<br /><br /></span><span class="default">?&gt;<br /></span><br />Note that this function can be combined with wordwrap() to accomplish a routine but fairly difficult web design goal, namely, limiting inline HTML text to a certain number of lines. wordwrap() can break your string using &lt;br&gt;, and then you can use this function to only return text up to the N'th &lt;br&gt;.<br /><br />You will still have to make a conservative guess of the max number of characters per line with wordwrap(), but you can be more precise than if you were simply truncating a multiple-line string with substr().<br /><br />See example:<br /><br /><span class="default">&lt;?php<br /><br />$text </span><span class="keyword">= </span><span class="string">'Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Pellentesque id massa. Duis sollicitudin ipsum vel diam. Aliquam pulvinar sagittis felis. Nullam hendrerit semper elit. Donec convallis mollis risus. Cras blandit mollis turpis. Vivamus facilisis, sapien at tincidunt accumsan, arcu dolor suscipit sem, tristique convallis ante ante id diam. Curabitur mollis, lacus vel gravida accumsan, enim quam condimentum est, vitae rutrum neque magna ac enim.'</span><span class="keyword">;<br /><br /></span><span class="default">$wrapped_text </span><span class="keyword">= </span><span class="default">wordwrap</span><span class="keyword">(</span><span class="default">$text</span><span class="keyword">,</span><span class="default">100</span><span class="keyword">,</span><span class="string">'&lt;br&gt;'</span><span class="keyword">,</span><span class="default">true</span><span class="keyword">);<br /><br /></span><span class="default">$three_lines </span><span class="keyword">= </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'&lt;br&gt;'</span><span class="keyword">,</span><span class="default">$wrapped_text</span><span class="keyword">,</span><span class="default">3</span><span class="keyword">);<br /><br />print </span><span class="string">'&lt;br&gt;&lt;br&gt;' </span><span class="keyword">. </span><span class="default">$three_lines</span><span class="keyword">;<br /><br /></span><span class="default">$four_lines </span><span class="keyword">= </span><span class="default">nsubstr</span><span class="keyword">(</span><span class="string">'&lt;br&gt;'</span><span class="keyword">,</span><span class="default">$wrapped_text</span><span class="keyword">,</span><span class="default">4</span><span class="keyword">);<br /><br />print </span><span class="string">'&lt;br&gt;&lt;br&gt;' </span><span class="keyword">. </span><span class="default">$four_lines</span><span class="keyword">;<br /><br /></span><span class="comment">/*<br />prints:<br /><br />Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Pellentesque id massa. Duis sollicitudin<br />ipsum vel diam. Aliquam pulvinar sagittis felis. Nullam hendrerit semper elit. Donec convallis<br />mollis risus. Cras blandit mollis turpis. Vivamus facilisis, sapien at tincidunt accumsan, arcu<br /><br />Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Pellentesque id massa. Duis sollicitudin<br />ipsum vel diam. Aliquam pulvinar sagittis felis. Nullam hendrerit semper elit. Donec convallis<br />mollis risus. Cras blandit mollis turpis. Vivamus facilisis, sapien at tincidunt accumsan, arcu<br />dolor suscipit sem, tristique convallis ante ante id diam. Curabitur mollis, lacus vel gravida<br /><br />*/<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="51100">  <div class="votes">
    <div id="Vu51100">
    <a href="/manual/vote-note.php?id=51100&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd51100">
    <a href="/manual/vote-note.php?id=51100&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V51100" title="40% like this...">
    -6
    </div>
  </div>
  <a href="#51100" class="name">
  <strong class="user"><em>Pommef</em></strong></a><a class="genanchor" href="#51100"> &para;</a><div class="date" title="2005-03-19 01:15"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom51100">
<div class="phpcode"><code><span class="html">
Example: Give me everything up to the fourth occurance of '/'.<br /><br /><span class="default">&lt;?php<br /><br />&nbsp;&nbsp; $haystack </span><span class="keyword">= </span><span class="string">"/home/username/www/index.php"</span><span class="keyword">;<br />&nbsp;&nbsp; </span><span class="default">$needle </span><span class="keyword">= </span><span class="string">"/"</span><span class="keyword">;<br />&nbsp; <br />&nbsp;&nbsp; function </span><span class="default">strnpos</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$needle</span><span class="keyword">, </span><span class="default">$occurance</span><span class="keyword">, </span><span class="default">$pos </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$res </span><span class="keyword">= </span><span class="default">implode</span><span class="keyword">(</span><span class="default">$needle</span><span class="keyword">,</span><span class="default">$haystack</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$res </span><span class="keyword">= </span><span class="default">array_slice</span><span class="keyword">(</span><span class="default">$res</span><span class="keyword">, </span><span class="default">$pos</span><span class="keyword">,&nbsp; </span><span class="default">$occurance</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">explode </span><span class="keyword">(</span><span class="default">$needle</span><span class="keyword">,</span><span class="default">$res</span><span class="keyword">); <br />&nbsp; &nbsp; } <br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="59950">  <div class="votes">
    <div id="Vu59950">
    <a href="/manual/vote-note.php?id=59950&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd59950">
    <a href="/manual/vote-note.php?id=59950&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V59950" title="36% like this...">
    -5
    </div>
  </div>
  <a href="#59950" class="name">
  <strong class="user"><em>navarr at gmail dot com</em></strong></a><a class="genanchor" href="#59950"> &para;</a><div class="date" title="2005-12-20 06:24"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom59950">
<div class="phpcode"><code><span class="html">
stripos for PHP4.x<br /><br /><span class="default">&lt;?php<br />&nbsp; </span><span class="keyword">function </span><span class="default">stripos</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">,</span><span class="default">$needle</span><span class="keyword">) {<br />&nbsp; &nbsp; return </span><span class="default">strpos</span><span class="keyword">(</span><span class="default">strtoupper</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">),</span><span class="default">strtoupper</span><span class="keyword">(</span><span class="default">$needle</span><span class="keyword">));<br />&nbsp; }<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="58019">  <div class="votes">
    <div id="Vu58019">
    <a href="/manual/vote-note.php?id=58019&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd58019">
    <a href="/manual/vote-note.php?id=58019&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V58019" title="46% like this...">
    -8
    </div>
  </div>
  <a href="#58019" class="name">
  <strong class="user"><em>admin at fivestarbuy dot com</em></strong></a><a class="genanchor" href="#58019"> &para;</a><div class="date" title="2005-10-21 09:18"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom58019">
<div class="phpcode"><code><span class="html">
This example lets you parse an unparsed strings variables. Warning: This could cause security leaks if you allow users to pass $variables through this engine. I recommend only using this for your Content Management System.<br /><br />&lt;?<br />$mytime=time();<br />$mydog="My Dog Ate My PHP!";<br /><br /># Your Parsing String:<br />$s1 = 'Hyphen Variable Preserving: $mytime, and $mydog';<br />echo "Before: &lt;br&gt;&lt;br&gt;$s1&lt;br&gt;&lt;br&gt;";<br /><br /># Remember, wherever you define this, it will not be defined GLOBAL into the function<br /># which is why we define it here. Defining it global could lead to security issues.<br />$vardata=get_defined_vars();<br /><br /># Parse the string<br />$s1 = StrParse($s1,$vardata);<br /><br />echo "After: &lt;br&gt;&lt;br&gt;$s1";<br /><br />function StrParse($str,$vardata) {<br /># Takes a string, or piece of data, that contains PHP Variables<br /> <br /> # For example, unparsed variables like:&nbsp; Test using time: $mytime<br /> # This example shows $mytime, and not the actual variable value.<br /> # The end result shows the actual variable value of $mytime.<br /><br /> # This is useful for building a content management system,<br /> # and directing your variables into your content data,<br /> # where content is stored in a file or database, unparsed.<br /> # Of course this could slow down page loads, but it's a good way<br /> # to parse data from current variables into your loaded new data<br /> # making it compatible.<br /> <br /># Then the variables are replaced with the actual variable..<br />$getvarkeys=array_keys($vardata);<br />$ret=$str;<br />for ($x=0; $x &lt; count($getvarkeys); $x++) {<br />&nbsp; &nbsp; $myvar=$getvarkeys[$x];<br />&nbsp; &nbsp; #echo "Variable: " . $myvar . " [" . $vardata[$myvar] . "]&lt;br&gt;";<br />&nbsp; &nbsp; $ret=str_replace('$' . $myvar, $vardata[$myvar], $ret);<br />}<br />return $ret;<br /><br />}<br /><br />?&gt;</span>
</code></div>
  </div>
 </div>
  <div class="note" id="52259">  <div class="votes">
    <div id="Vu52259">
    <a href="/manual/vote-note.php?id=52259&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd52259">
    <a href="/manual/vote-note.php?id=52259&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V52259" title="42% like this...">
    -8
    </div>
  </div>
  <a href="#52259" class="name">
  <strong class="user"><em>php at moechofe dot com</em></strong></a><a class="genanchor" href="#52259"> &para;</a><div class="date" title="2005-04-26 06:34"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom52259">
<div class="phpcode"><code><span class="html">
<span class="default">&lt;?php<br />&nbsp; </span><span class="comment">/*<br />&nbsp; * str_match<br />&nbsp; *<br />&nbsp; * return a string with only cacacteres defined in a expression return false if the expression is not valid<br />&nbsp; *<br />&nbsp; * @param $str string the string<br />&nbsp; * @param $match the expression based on the class definition off a PCRE regular expression.<br />&nbsp; *&nbsp;&nbsp; the '[', ']', '\' and '^' at class start need to be escaped.<br />&nbsp; *&nbsp;&nbsp; like : -a-z0-9_@.<br />&nbsp; */<br />&nbsp; </span><span class="keyword">function </span><span class="default">str_match</span><span class="keyword">( </span><span class="default">$str</span><span class="keyword">, </span><span class="default">$match </span><span class="keyword">)<br />&nbsp; {<br />&nbsp; &nbsp; </span><span class="default">$return </span><span class="keyword">= </span><span class="string">''</span><span class="keyword">;<br />&nbsp; &nbsp; if( </span><span class="default">eregi</span><span class="keyword">( </span><span class="string">'(.*)'</span><span class="keyword">, </span><span class="default">$match</span><span class="keyword">, </span><span class="default">$class </span><span class="keyword">) )<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$match </span><span class="keyword">= </span><span class="string">'['</span><span class="keyword">.</span><span class="default">$regs</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">].</span><span class="string">']'</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; for( </span><span class="default">$i</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">&lt;</span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">); </span><span class="default">$i</span><span class="keyword">++ )<br />&nbsp; &nbsp; &nbsp; if( </span><span class="default">ereg</span><span class="keyword">( </span><span class="string">'['</span><span class="keyword">.</span><span class="default">$class</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">].</span><span class="string">']'</span><span class="keyword">, </span><span class="default">$str</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">] ) )<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$return </span><span class="keyword">.= </span><span class="default">$str</span><span class="keyword">{</span><span class="default">$i</span><span class="keyword">};<br />&nbsp; &nbsp; &nbsp; return </span><span class="default">$return</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; else return </span><span class="default">false</span><span class="keyword">;<br />&nbsp; }<br /><br />&nbsp; </span><span class="comment">/*<br />&nbsp; * example<br />&nbsp; * accept only alphanum caracteres from the GET/POST parameters 'a'<br />&nbsp; */<br /><br />&nbsp; </span><span class="keyword">if( ! empty(</span><span class="default">$_REQUEST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">]) )<br />&nbsp; &nbsp; </span><span class="default">$_REQUEST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">] = </span><span class="default">str_match</span><span class="keyword">( </span><span class="default">$_REQUEST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">], </span><span class="string">'a-zA-Z0-9' </span><span class="keyword">);<br />&nbsp; else<br />&nbsp; &nbsp; </span><span class="default">$_REQUEST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">] = </span><span class="string">'default'</span><span class="keyword">;<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="53284">  <div class="votes">
    <div id="Vu53284">
    <a href="/manual/vote-note.php?id=53284&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd53284">
    <a href="/manual/vote-note.php?id=53284&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V53284" title="42% like this...">
    -8
    </div>
  </div>
  <a href="#53284" class="name">
  <strong class="user"><em>james dot d dot baker at gmail dot com</em></strong></a><a class="genanchor" href="#53284"> &para;</a><div class="date" title="2005-05-27 10:45"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom53284">
<div class="phpcode"><code><span class="html">
<span class="default">&lt;?php<br /></span><span class="comment">/*<br />Written By James Baker, May 27th 2005<br /><br />sentenceCase($string);<br />&nbsp; &nbsp; $string: The string to convert to sentence case.<br /><br />Converts a string into proper sentence case (First letter of each sentance capital, all the others smaller)<br /><br />Example Usage:<br />echo sentenceCase("HELLO WORLD!!! THIS IS A CAPITALISED SENTENCE. this isn't.");<br /><br />Returns:<br />Hello world!!! This is a capitalised sentence. This isn't.<br />*/<br /><br /></span><span class="keyword">function </span><span class="default">sentenceCase</span><span class="keyword">(</span><span class="default">$s</span><span class="keyword">){<br />&nbsp; &nbsp; </span><span class="default">$str </span><span class="keyword">= </span><span class="default">strtolower</span><span class="keyword">(</span><span class="default">$s</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$cap </span><span class="keyword">= </span><span class="default">true</span><span class="keyword">;<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; for(</span><span class="default">$x </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$x </span><span class="keyword">&lt; </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">); </span><span class="default">$x</span><span class="keyword">++){<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$letter </span><span class="keyword">= </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">, </span><span class="default">$x</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; if(</span><span class="default">$letter </span><span class="keyword">== </span><span class="string">"." </span><span class="keyword">|| </span><span class="default">$letter </span><span class="keyword">== </span><span class="string">"!" </span><span class="keyword">|| </span><span class="default">$letter </span><span class="keyword">== </span><span class="string">"?"</span><span class="keyword">){<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$cap </span><span class="keyword">= </span><span class="default">true</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }elseif(</span><span class="default">$letter </span><span class="keyword">!= </span><span class="string">" " </span><span class="keyword">&amp;&amp; </span><span class="default">$cap </span><span class="keyword">== </span><span class="default">true</span><span class="keyword">){<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$letter </span><span class="keyword">= </span><span class="default">strtoupper</span><span class="keyword">(</span><span class="default">$letter</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$cap </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$ret </span><span class="keyword">.= </span><span class="default">$letter</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; return </span><span class="default">$ret</span><span class="keyword">;<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="48626">  <div class="votes">
    <div id="Vu48626">
    <a href="/manual/vote-note.php?id=48626&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd48626">
    <a href="/manual/vote-note.php?id=48626&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V48626" title="40% like this...">
    -8
    </div>
  </div>
  <a href="#48626" class="name">
  <strong class="user"><em>kristin at greenapple dot on dot ca</em></strong></a><a class="genanchor" href="#48626"> &para;</a><div class="date" title="2005-01-02 08:32"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom48626">
<div class="phpcode"><code><span class="html">
I really searched for a function that would do this as I've seen it in other languages but I couldn't find it here. This is particularily useful when combined with substr() to take the first part of a string up to a certain point.<br /><br />strnpos() - Find the nth position of needle in haystack.<br /><br /><span class="default">&lt;?php<br /><br />&nbsp; &nbsp; </span><span class="keyword">function </span><span class="default">strnpos</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$needle</span><span class="keyword">, </span><span class="default">$occurance</span><span class="keyword">, </span><span class="default">$pos </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; for (</span><span class="default">$i </span><span class="keyword">= </span><span class="default">1</span><span class="keyword">; </span><span class="default">$i </span><span class="keyword">&lt;= </span><span class="default">$occurance</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">++) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$pos </span><span class="keyword">= </span><span class="default">strpos</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$needle</span><span class="keyword">, </span><span class="default">$pos</span><span class="keyword">) + </span><span class="default">1</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$pos </span><span class="keyword">- </span><span class="default">1</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; }<br /><br /></span><span class="default">?&gt;<br /></span><br />Example: Give me everything up to the fourth occurance of '/'.<br /><br /><span class="default">&lt;?php<br /><br />&nbsp; &nbsp; $haystack </span><span class="keyword">= </span><span class="string">"/home/username/www/index.php"</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$needle </span><span class="keyword">= </span><span class="string">"/"</span><span class="keyword">;<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="default">$root_dir </span><span class="keyword">= </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">strnpos</span><span class="keyword">(</span><span class="default">$haystack</span><span class="keyword">, </span><span class="default">$needle</span><span class="keyword">, </span><span class="default">4</span><span class="keyword">));<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; echo </span><span class="default">$root_dir</span><span class="keyword">;<br />&nbsp; &nbsp; <br /></span><span class="default">?&gt;<br /></span><br />Returns: /home/username/www<br /><br />Use this example with the server variable $_SERVER['SCRIPT_NAME'] as the haystack and you can self-discover a document's root directory for the purposes of locating global files automatically!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="76705">  <div class="votes">
    <div id="Vu76705">
    <a href="/manual/vote-note.php?id=76705&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd76705">
    <a href="/manual/vote-note.php?id=76705&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V76705" title="39% like this...">
    -9
    </div>
  </div>
  <a href="#76705" class="name">
  <strong class="user"><em>m</em></strong></a><a class="genanchor" href="#76705"> &para;</a><div class="date" title="2007-07-26 05:10"><strong>12 years ago</strong></div>
  <div class="text" id="Hcom76705">
<div class="phpcode"><code><span class="html">
Regarding the code for the function beginsWith($str, $sub), I found that it has problems when only one character is present after the string searched for. I found that this works better instead:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">beginsWith</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">, </span><span class="default">$sub</span><span class="keyword">) {<br />&nbsp; &nbsp; return (</span><span class="default">strncmp</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">, </span><span class="default">$sub</span><span class="keyword">, </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$sub</span><span class="keyword">)) == </span><span class="default">0</span><span class="keyword">);<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="46918">  <div class="votes">
    <div id="Vu46918">
    <a href="/manual/vote-note.php?id=46918&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd46918">
    <a href="/manual/vote-note.php?id=46918&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V46918" title="40% like this...">
    -9
    </div>
  </div>
  <a href="#46918" class="name">
  <strong class="user"><em>[tab!]</em></strong></a><a class="genanchor" href="#46918"> &para;</a><div class="date" title="2004-10-27 12:29"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom46918">
<div class="phpcode"><code><span class="html">
//<br />// string strtrmvistl(&nbsp; string str, [int maxlen = 64], <br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; [bool right_justify = false],<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; [string delimter = "&lt;br&gt;\n"])<br />// <br />// splits a long string into two chunks (a start and an end chunk) <br />// of a given maximum length and seperates them by a given delimeter. <br />// a second chunk can be right-justified within maxlen.<br />// may be used to 'spread' a string over two lines.<br />//<br /><br />function strtrmvistl($str, $maxlen = 64, $right_justify = false, $delimter = "&lt;br&gt;\n") {<br />&nbsp; &nbsp; if(($len = strlen($str = chop($str))) &gt; ($maxlen = max($maxlen, 12))) {<br />&nbsp; &nbsp; &nbsp; &nbsp; $newstr = substr($str, 0, $maxlen - 3);<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; if($len &gt; ($maxlen - 3)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $endlen = min(($len - strlen($newstr)), $maxlen - 3);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $newstr .= "..." . $delimter;<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if($right_justify)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $newstr .= str_pad('', $maxlen - $endlen - 3, ' ');<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $newstr .= "..." . substr($str, $len - $endlen);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; return($newstr);<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; return($str);<br />}</span>
</code></div>
  </div>
 </div>
  <div class="note" id="62523">  <div class="votes">
    <div id="Vu62523">
    <a href="/manual/vote-note.php?id=62523&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd62523">
    <a href="/manual/vote-note.php?id=62523&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V62523" title="45% like this...">
    -11
    </div>
  </div>
  <a href="#62523" class="name">
  <strong class="user"><em>administrador(ensaimada)sphoera(punt)com</em></strong></a><a class="genanchor" href="#62523"> &para;</a><div class="date" title="2006-03-02 06:10"><strong>13 years ago</strong></div>
  <div class="text" id="Hcom62523">
<div class="phpcode"><code><span class="html">
I've prepared this simple function to obtain a string delimited between tags (not only XML tags!). Anybody needs something like this?.<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">get_string_between</span><span class="keyword">(</span><span class="default">$string</span><span class="keyword">, </span><span class="default">$start</span><span class="keyword">, </span><span class="default">$end</span><span class="keyword">){<br />&nbsp; &nbsp; </span><span class="default">$string </span><span class="keyword">= </span><span class="string">" "</span><span class="keyword">.</span><span class="default">$string</span><span class="keyword">;<br />&nbsp; &nbsp;&nbsp; </span><span class="default">$ini </span><span class="keyword">= </span><span class="default">strpos</span><span class="keyword">(</span><span class="default">$string</span><span class="keyword">,</span><span class="default">$start</span><span class="keyword">);<br />&nbsp; &nbsp;&nbsp; if (</span><span class="default">$ini </span><span class="keyword">== </span><span class="default">0</span><span class="keyword">) return </span><span class="string">""</span><span class="keyword">;<br />&nbsp; &nbsp;&nbsp; </span><span class="default">$ini </span><span class="keyword">+= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$start</span><span class="keyword">);&nbsp; &nbsp;&nbsp; <br />&nbsp; &nbsp;&nbsp; </span><span class="default">$len </span><span class="keyword">= </span><span class="default">strpos</span><span class="keyword">(</span><span class="default">$string</span><span class="keyword">,</span><span class="default">$end</span><span class="keyword">,</span><span class="default">$ini</span><span class="keyword">) - </span><span class="default">$ini</span><span class="keyword">;<br />&nbsp; &nbsp;&nbsp; return </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$string</span><span class="keyword">,</span><span class="default">$ini</span><span class="keyword">,</span><span class="default">$len</span><span class="keyword">);<br />}<br /><br /></span><span class="default">$string </span><span class="keyword">= </span><span class="string">"this [custom] function is useless!!"</span><span class="keyword">;<br />echo </span><span class="default">get_string_between</span><span class="keyword">(</span><span class="default">$string</span><span class="keyword">,</span><span class="string">"["</span><span class="keyword">,</span><span class="string">"]"</span><span class="keyword">);<br /></span><span class="comment">// must return "custom";<br /></span><span class="default">?&gt;<br /></span>more functions at <a href="http://www.sphoera.com" rel="nofollow" target="_blank">http://www.sphoera.com</a></span>
</code></div>
  </div>
 </div>
  <div class="note" id="53546">  <div class="votes">
    <div id="Vu53546">
    <a href="/manual/vote-note.php?id=53546&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd53546">
    <a href="/manual/vote-note.php?id=53546&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V53546" title="37% like this...">
    -9
    </div>
  </div>
  <a href="#53546" class="name">
  <strong class="user"><em>rh at richardhoward dot net</em></strong></a><a class="genanchor" href="#53546"> &para;</a><div class="date" title="2005-06-05 11:41"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom53546">
<div class="phpcode"><code><span class="html">
<span class="default">&lt;?php<br /></span><span class="comment">/**<br />Utility class: static methods for cleaning &amp; escaping untrusted (i.e.<br />user-supplied) strings.<br /><br />Any string can (usually) be thought of as being in one of these 'modes':<br /><br />pure = what the user actually typed / what you want to see on the page /<br />&nbsp; &nbsp; &nbsp;&nbsp; what is actually stored in the DB<br />gpc&nbsp; = incoming GET, POST or COOKIE data<br />sql&nbsp; = escaped for passing safely to RDBMS via SQL (also, data from DB<br />&nbsp; &nbsp; &nbsp;&nbsp; queries and file reads if you have magic_quotes_runtime on--which<br />&nbsp; &nbsp; &nbsp;&nbsp; is rare)<br />html = safe for html display (htmlentities applied)<br /><br />Always knowing what mode your string is in--using these methods to<br />convert between modes--will prevent SQL injection and cross-site scripting.<br /><br />This class refers to its own namespace (so it can work in PHP 4--there is no<br />self keyword until PHP 5). Do not change the name of the class w/o changing<br />all the internal references.<br /><br />Example usage: a POST value that you want to query with:<br />$username = Str::gpc2sql($_POST['username']);<br />*/<br /><br />//This sets SQL escaping to use slashes; for Sybase(/MSSQL)-style escaping<br />// ( ' --&gt; '' ), set to true.<br /></span><span class="default">define</span><span class="keyword">(</span><span class="string">'STR_SYBASE'</span><span class="keyword">, </span><span class="default">false</span><span class="keyword">);<br /><br />class </span><span class="default">Str </span><span class="keyword">{<br />&nbsp; &nbsp; function </span><span class="default">gpc2sql</span><span class="keyword">(</span><span class="default">$gpc</span><span class="keyword">, </span><span class="default">$maxLength </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">Str</span><span class="keyword">::</span><span class="default">pure2sql</span><span class="keyword">(</span><span class="default">Str</span><span class="keyword">::</span><span class="default">gpc2pure</span><span class="keyword">(</span><span class="default">$gpc</span><span class="keyword">), </span><span class="default">$maxLength</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">gpc2html</span><span class="keyword">(</span><span class="default">$gpc</span><span class="keyword">, </span><span class="default">$maxLength </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">Str</span><span class="keyword">::</span><span class="default">pure2html</span><span class="keyword">(</span><span class="default">Str</span><span class="keyword">::</span><span class="default">gpc2pure</span><span class="keyword">(</span><span class="default">$gpc</span><span class="keyword">), </span><span class="default">$maxLength</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">gpc2pure</span><span class="keyword">(</span><span class="default">$gpc</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">ini_get</span><span class="keyword">(</span><span class="string">'magic_quotes_sybase'</span><span class="keyword">))<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$pure </span><span class="keyword">= </span><span class="default">str_replace</span><span class="keyword">(</span><span class="string">"''"</span><span class="keyword">, </span><span class="string">"'"</span><span class="keyword">, </span><span class="default">$gpc</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; else </span><span class="default">$pure </span><span class="keyword">= </span><span class="default">get_magic_quotes_gpc</span><span class="keyword">() ? </span><span class="default">stripslashes</span><span class="keyword">(</span><span class="default">$gpc</span><span class="keyword">) : </span><span class="default">$gpc</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$pure</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">html2pure</span><span class="keyword">(</span><span class="default">$html</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">html_entity_decode</span><span class="keyword">(</span><span class="default">$html</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">html2sql</span><span class="keyword">(</span><span class="default">$html</span><span class="keyword">, </span><span class="default">$maxLength </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">Str</span><span class="keyword">::</span><span class="default">pure2sql</span><span class="keyword">(</span><span class="default">Str</span><span class="keyword">::</span><span class="default">html2pure</span><span class="keyword">(</span><span class="default">$html</span><span class="keyword">), </span><span class="default">$maxLength</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">pure2html</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">, </span><span class="default">$maxLength </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$maxLength </span><span class="keyword">? </span><span class="default">htmlentities</span><span class="keyword">(</span><span class="default">substr</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">$maxLength</span><span class="keyword">))<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; : </span><span class="default">htmlentities</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">pure2sql</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">, </span><span class="default">$maxLength </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$maxLength</span><span class="keyword">) </span><span class="default">$pure </span><span class="keyword">= </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">$maxLength</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; return (</span><span class="default">STR_SYBASE</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; ? </span><span class="default">str_replace</span><span class="keyword">(</span><span class="string">"'"</span><span class="keyword">, </span><span class="string">"''"</span><span class="keyword">, </span><span class="default">$pure</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; : </span><span class="default">addslashes</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">sql2html</span><span class="keyword">(</span><span class="default">$sql</span><span class="keyword">, </span><span class="default">$maxLength </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$pure </span><span class="keyword">= </span><span class="default">Str</span><span class="keyword">::</span><span class="default">sql2pure</span><span class="keyword">(</span><span class="default">$sql</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$maxLength</span><span class="keyword">) </span><span class="default">$pure </span><span class="keyword">= </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">$maxLength</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">Str</span><span class="keyword">::</span><span class="default">pure2html</span><span class="keyword">(</span><span class="default">$pure</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; function </span><span class="default">sql2pure</span><span class="keyword">(</span><span class="default">$sql</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return (</span><span class="default">STR_SYBASE</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; ? </span><span class="default">str_replace</span><span class="keyword">(</span><span class="string">"''"</span><span class="keyword">, </span><span class="string">"'"</span><span class="keyword">, </span><span class="default">$sql</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; : </span><span class="default">stripslashes</span><span class="keyword">(</span><span class="default">$sql</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="75830">  <div class="votes">
    <div id="Vu75830">
    <a href="/manual/vote-note.php?id=75830&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd75830">
    <a href="/manual/vote-note.php?id=75830&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V75830" title="36% like this...">
    -9
    </div>
  </div>
  <a href="#75830" class="name">
  <strong class="user"><em>mike &amp;#34;eyes&amp;#34; moe</em></strong></a><a class="genanchor" href="#75830"> &para;</a><div class="date" title="2007-06-17 05:59"><strong>12 years ago</strong></div>
  <div class="text" id="Hcom75830">
<div class="phpcode"><code><span class="html">
Here is a truly random string generator it uses the most common string functions it will work on anywhere.<br /><br /><span class="default">&lt;?php<br />&nbsp; &nbsp; </span><span class="keyword">function </span><span class="default">random_string</span><span class="keyword">(</span><span class="default">$max </span><span class="keyword">= </span><span class="default">20</span><span class="keyword">){<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$chars </span><span class="keyword">= </span><span class="default">explode</span><span class="keyword">(</span><span class="string">" "</span><span class="keyword">, </span><span class="string">"a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9"</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; for(</span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$i </span><span class="keyword">&lt; </span><span class="default">$max</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">++){<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$rnd </span><span class="keyword">= </span><span class="default">array_rand</span><span class="keyword">(</span><span class="default">$chars</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$rtn </span><span class="keyword">.= </span><span class="default">base64_encode</span><span class="keyword">(</span><span class="default">md5</span><span class="keyword">(</span><span class="default">$chars</span><span class="keyword">[</span><span class="default">$rnd</span><span class="keyword">]));<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">substr</span><span class="keyword">(</span><span class="default">str_shuffle</span><span class="keyword">(</span><span class="default">strtolower</span><span class="keyword">(</span><span class="default">$rtn</span><span class="keyword">)), </span><span class="default">0</span><span class="keyword">, </span><span class="default">$max</span><span class="keyword">);<br />&nbsp; &nbsp; }<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="55805">  <div class="votes">
    <div id="Vu55805">
    <a href="/manual/vote-note.php?id=55805&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd55805">
    <a href="/manual/vote-note.php?id=55805&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V55805" title="36% like this...">
    -10
    </div>
  </div>
  <a href="#55805" class="name">
  <strong class="user"><em>webmaster at cafe-clope dot net</em></strong></a><a class="genanchor" href="#55805"> &para;</a><div class="date" title="2005-08-13 04:40"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom55805">
<div class="phpcode"><code><span class="html">
A comprehensive concatenation function, that works with array and strings<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">str_cat</span><span class="keyword">() {<br />&nbsp; </span><span class="default">$args </span><span class="keyword">= </span><span class="default">func_get_args</span><span class="keyword">() ;<br />&nbsp; &nbsp; <br />&nbsp; </span><span class="comment">// Asserts that every array given as argument is $dim-size.<br />&nbsp; // Keys in arrays are stripped off.<br />&nbsp; // If no array is found, $dim stays unset.<br />&nbsp; </span><span class="keyword">foreach(</span><span class="default">$args </span><span class="keyword">as </span><span class="default">$key </span><span class="keyword">=&gt; </span><span class="default">$arg</span><span class="keyword">) {<br />&nbsp; &nbsp; if(</span><span class="default">is_array</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; if(!isset(</span><span class="default">$dim</span><span class="keyword">))<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$dim </span><span class="keyword">= </span><span class="default">count</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">) ;<br />&nbsp; &nbsp; &nbsp; elseif(</span><span class="default">$dim </span><span class="keyword">!= </span><span class="default">count</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">))<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">FALSE </span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$args</span><span class="keyword">[</span><span class="default">$key</span><span class="keyword">] = </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">) ;<br />&nbsp; &nbsp; }<br />&nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; </span><span class="comment">// Concatenation<br />&nbsp; </span><span class="keyword">if(isset(</span><span class="default">$dim</span><span class="keyword">)) {<br />&nbsp; &nbsp; </span><span class="default">$result </span><span class="keyword">= array() ;<br />&nbsp; &nbsp; for(</span><span class="default">$i</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">;</span><span class="default">$i</span><span class="keyword">&lt;</span><span class="default">$dim</span><span class="keyword">;</span><span class="default">$i</span><span class="keyword">++) {<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$result</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">] = </span><span class="string">'' </span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; foreach(</span><span class="default">$args </span><span class="keyword">as </span><span class="default">$arg</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$result</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">] .= ( </span><span class="default">is_array</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">) ? </span><span class="default">$arg</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">] : </span><span class="default">$arg </span><span class="keyword">) ;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; return </span><span class="default">$result </span><span class="keyword">;<br />&nbsp; } else {<br />&nbsp; &nbsp; return </span><span class="default">implode</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">) ;<br />&nbsp; }<br />}<br /></span><span class="default">?&gt;<br /></span><br />A simple example :<br /><br /><span class="default">&lt;?php<br />str_cat</span><span class="keyword">(array(</span><span class="default">1</span><span class="keyword">,</span><span class="default">2</span><span class="keyword">,</span><span class="default">3</span><span class="keyword">), </span><span class="string">'-'</span><span class="keyword">, array(</span><span class="string">'foo' </span><span class="keyword">=&gt; </span><span class="string">'foo'</span><span class="keyword">, </span><span class="string">'bar' </span><span class="keyword">=&gt; </span><span class="string">'bar'</span><span class="keyword">, </span><span class="string">'noop' </span><span class="keyword">=&gt; </span><span class="string">'noop'</span><span class="keyword">)) ;<br /></span><span class="default">?&gt;<br /></span><br />will return :<br />Array (<br />&nbsp; [0] =&gt; 1-foo<br />&nbsp; [1] =&gt; 2-bar<br />&nbsp; [2] =&gt; 3-noop<br />)<br /><br />More usefull :<br /><br /><span class="default">&lt;?php<br />$myget </span><span class="keyword">= </span><span class="default">$_GET </span><span class="keyword">; </span><span class="comment">// retrieving previous $_GET values<br /></span><span class="default">$myget</span><span class="keyword">[</span><span class="string">'foo'</span><span class="keyword">] = </span><span class="string">'b a r' </span><span class="keyword">; </span><span class="comment">// changing one value<br /></span><span class="default">$myget </span><span class="keyword">= </span><span class="default">str_cat</span><span class="keyword">(</span><span class="default">array_keys</span><span class="keyword">(</span><span class="default">$myget</span><span class="keyword">), </span><span class="string">'='</span><span class="keyword">, </span><span class="default">array_map</span><span class="keyword">(</span><span class="string">'rawurlencode'</span><span class="keyword">, </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$myget</span><span class="keyword">))) ;<br /></span><span class="default">$querystring </span><span class="keyword">= </span><span class="default">implode</span><span class="keyword">(</span><span class="default">ini_get</span><span class="keyword">(</span><span class="string">'arg_separator.output'</span><span class="keyword">), </span><span class="default">$myget</span><span class="keyword">)) ;<br /></span><span class="default">?&gt;<br /></span><br />will return a valid querystring with some values changed.<br /><br />Note that <span class="default">&lt;?php str_cat</span><span class="keyword">(</span><span class="string">'foo'</span><span class="keyword">, </span><span class="string">'&amp;'</span><span class="keyword">, </span><span class="string">'bar'</span><span class="keyword">) ; </span><span class="default">?&gt;</span> will return 'foo&amp;bar', while <span class="default">&lt;?php str_cat</span><span class="keyword">(array(</span><span class="string">'foo'</span><span class="keyword">), </span><span class="string">'&amp;'</span><span class="keyword">, </span><span class="string">'bar'</span><span class="keyword">) ; </span><span class="default">?&gt;</span> will return array(0 =&gt; foo&amp;bar)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="107432">  <div class="votes">
    <div id="Vu107432">
    <a href="/manual/vote-note.php?id=107432&amp;page=ref.strings&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd107432">
    <a href="/manual/vote-note.php?id=107432&amp;page=ref.strings&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V107432" title="30% like this...">
    -16
    </div>
  </div>
  <a href="#107432" class="name">
  <strong class="user"><em>Tomek Rychtyk</em></strong></a><a class="genanchor" href="#107432"> &para;</a><div class="date" title="2012-02-08 09:58"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom107432">
<div class="phpcode"><code><span class="html">
Get the intersection of two strings using array_intersect<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">string_intersect</span><span class="keyword">(</span><span class="default">$string1</span><span class="keyword">, </span><span class="default">$string2</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="default">$array1 </span><span class="keyword">= </span><span class="default">$array2 </span><span class="keyword">= array();<br /><br />&nbsp; &nbsp; for(</span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">, </span><span class="default">$j </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">, </span><span class="default">$s1_len </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$string1</span><span class="keyword">), </span><span class="default">$s2_len </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$string2</span><span class="keyword">);(</span><span class="default">$i </span><span class="keyword">&lt; </span><span class="default">$s1_len</span><span class="keyword">) || (</span><span class="default">$j </span><span class="keyword">&lt; </span><span class="default">$s2_len</span><span class="keyword">); </span><span class="default">$i</span><span class="keyword">++, </span><span class="default">$j</span><span class="keyword">++) {<br />&nbsp; &nbsp; &nbsp; &nbsp; if(</span><span class="default">$i </span><span class="keyword">&lt; </span><span class="default">$s1_len</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$array1</span><span class="keyword">[] = </span><span class="default">$string1</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">];<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; if(</span><span class="default">$j </span><span class="keyword">&lt; </span><span class="default">$s2_len</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$array2</span><span class="keyword">[] = </span><span class="default">$string2</span><span class="keyword">[</span><span class="default">$j</span><span class="keyword">];<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; return </span><span class="default">implode</span><span class="keyword">(</span><span class="string">''</span><span class="keyword">, </span><span class="default">array_intersect</span><span class="keyword">(</span><span class="default">$array1</span><span class="keyword">, </span><span class="default">$array2</span><span class="keyword">));<br />}<br /><br /></span><span class="default">?&gt;<br /></span><br />For more advanced comparison you can use array_uintersect as well.</span>
</code></div>
  </div>
 </div></div>

 <div class="foot"><a href="/manual/add-note.php?sect=ref.strings&amp;redirect=https://www.php.net/manual/pt_BR/ref.strings.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></div>
</section>    </section><!-- layout-content -->
        <aside class='layout-menu'>

        <ul class='parent-menu-list'>
                                    <li>
                <a href="book.strings.php">Strings</a>

                                    <ul class='child-menu-list'>

                                                <li class="">
                            <a href="intro.strings.php" title="Introdu&ccedil;&atilde;o">Introdu&ccedil;&atilde;o</a>
                        </li>
                                                <li class="">
                            <a href="strings.setup.php" title="Instala&ccedil;&atilde;o/Configura&ccedil;&atilde;o">Instala&ccedil;&atilde;o/Configura&ccedil;&atilde;o</a>
                        </li>
                                                <li class="">
                            <a href="string.constants.php" title="Constantes pr&eacute;-&#8203;definidas">Constantes pr&eacute;-&#8203;definidas</a>
                        </li>
                                                <li class="current">
                            <a href="ref.strings.php" title="Fun&ccedil;&otilde;es para String">Fun&ccedil;&otilde;es para String</a>
                        </li>
                                                <li class="">
                            <a href="changelog.strings.php" title="Changelog">Changelog</a>
                        </li>
                        
                    </ul>
                
            </li>
                        
                    </ul>
    </aside>


  </div><!-- layout -->

  <footer>
    <div class="container footer-content">
      <div class="row-fluid">
      <ul class="footmenu">
        <li><a href="/copyright.php">Copyright &copy; 2001-2020 The PHP Group</a></li>
        <li><a href="/my.php">My PHP.net</a></li>
        <li><a href="/contact.php">Contact</a></li>
        <li><a href="/sites.php">Other PHP.net sites</a></li>
        <li><a href="/privacy.php">Privacy policy</a></li>
      </ul>
      </div>
    </div>
  </footer>

    
 <!-- External and third party libraries. -->
 <script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script src="/cached.php?t=1421837618&amp;f=/js/ext/modernizr.js"></script>
<script src="/cached.php?t=1421837618&amp;f=/js/ext/hogan-2.0.0.min.js"></script>
<script src="/cached.php?t=1421837618&amp;f=/js/ext/typeahead.min.js"></script>
<script src="/cached.php?t=1421837618&amp;f=/js/ext/mousetrap.min.js"></script>
<script src="/cached.php?t=1421837618&amp;f=/js/search.js"></script>
<script src="/cached.php?t=1539765004&amp;f=/js/common.js"></script>

<a id="toTop" href="javascript:;"><span id="toTopHover"></span><img width="40" height="40" alt="To Top" src="/images/to-top@2x.png"></a>

</body>
</html>
