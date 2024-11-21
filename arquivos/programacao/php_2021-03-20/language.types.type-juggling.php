<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="pt_BR">
<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: Manipula&ccedil;&atilde;o de tipos - Manual </title>

 <link rel="shortcut icon" href="https://www.php.net/favicon.ico">
 <link rel="search" type="application/opensearchdescription+xml" href="http://php.net/phpnetimprovedsearch.src" title="Add PHP.net search">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/releases/feed.php" title="PHP Release feed">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/feed.atom" title="PHP: Hypertext Preprocessor">

 <link rel="canonical" href="https://www.php.net/manual/pt_BR/language.types.type-juggling.php">
 <link rel="shorturl" href="https://www.php.net/types.type-juggling">
 <link rel="alternate" href="https://www.php.net/types.type-juggling" hreflang="x-default">

 <link rel="contents" href="https://www.php.net/manual/pt_BR/index.php">
 <link rel="index" href="https://www.php.net/manual/pt_BR/language.types.php">
 <link rel="prev" href="https://www.php.net/manual/pt_BR/language.pseudo-types.php">
 <link rel="next" href="https://www.php.net/manual/pt_BR/language.variables.php">

 <link rel="alternate" href="https://www.php.net/manual/en/language.types.type-juggling.php" hreflang="en">
 <link rel="alternate" href="https://www.php.net/manual/pt_BR/language.types.type-juggling.php" hreflang="pt_BR">
 <link rel="alternate" href="https://www.php.net/manual/zh/language.types.type-juggling.php" hreflang="zh">
 <link rel="alternate" href="https://www.php.net/manual/fr/language.types.type-juggling.php" hreflang="fr">
 <link rel="alternate" href="https://www.php.net/manual/de/language.types.type-juggling.php" hreflang="de">
 <link rel="alternate" href="https://www.php.net/manual/ja/language.types.type-juggling.php" hreflang="ja">
 <link rel="alternate" href="https://www.php.net/manual/ro/language.types.type-juggling.php" hreflang="ro">
 <link rel="alternate" href="https://www.php.net/manual/ru/language.types.type-juggling.php" hreflang="ru">
 <link rel="alternate" href="https://www.php.net/manual/es/language.types.type-juggling.php" hreflang="es">
 <link rel="alternate" href="https://www.php.net/manual/tr/language.types.type-juggling.php" hreflang="tr">

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

 <base href="https://www.php.net/manual/pt_BR/language.types.type-juggling.php">

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
        <a href="language.variables.php">
          Vari&aacute;veis &raquo;
        </a>
      </div>
              <div class="prev">
        <a href="language.pseudo-types.php">
          &laquo; Pseudo-tipos e vari&aacute;veis utilizadas nesta documenta&ccedil;&atilde;o        </a>
      </div>
          <ul>
            <li><a href='index.php'>Manual do PHP</a></li>      <li><a href='langref.php'>Refer&ecirc;ncia da Linguagem</a></li>      <li><a href='language.types.php'>Tipos</a></li>      </ul>
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
            <option value='en/language.types.type-juggling.php'>English</option>
            <option value='pt_BR/language.types.type-juggling.php' selected="selected">Brazilian Portuguese</option>
            <option value='zh/language.types.type-juggling.php'>Chinese (Simplified)</option>
            <option value='fr/language.types.type-juggling.php'>French</option>
            <option value='de/language.types.type-juggling.php'>German</option>
            <option value='ja/language.types.type-juggling.php'>Japanese</option>
            <option value='ro/language.types.type-juggling.php'>Romanian</option>
            <option value='ru/language.types.type-juggling.php'>Russian</option>
            <option value='es/language.types.type-juggling.php'>Spanish</option>
            <option value='tr/language.types.type-juggling.php'>Turkish</option>
            <option value="help-translate.php">Other</option>
          </select>
        </fieldset>
      </form>
    </div>
    <div class="edit-bug">
      <a href="https://edit.php.net/?project=PHP&amp;perm=pt_BR/language.types.type-juggling.php">Edit</a>
      <a href="https://bugs.php.net/report.php?bug_type=Documentation+problem&amp;manpage=language.types.type-juggling">Report a Bug</a>
    </div>
  </div><div id="language.types.type-juggling" class="sect1">
 <h2 class="title">Manipulação de tipos</h2>

 <p class="simpara">
  O PHP não obriga (ou suporta) a definição de tipo explícita na declaração de
  variáveis: o tipo de uma variável é determinado pelo contexto em que a variável é
  utilizada. Isto significa que, atribuir um valor <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
  a variável <var class="varname"><var class="varname">$var</var></var>, fará <var class="varname"><var class="varname">$var</var></var> se tornar uma
  <span class="type"><a href="language.types.string.php" class="type string">string</a></span>. Se um valor <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span> for atribuído a
  <var class="varname"><var class="varname">$var</var></var>, ela se torna um <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>.
 </p>

 <p class="para">
  Um exemplo de conversão automática do PHP é o operador de multiplicação &#039;*&#039;.
  Se qualquer um dos operandos for <span class="type"><a href="language.types.float.php" class="type float">float</a></span>, todos
  os operadores serão avaliados como <span class="type"><a href="language.types.float.php" class="type float">float</a></span>, e o resultado será um
  <span class="type"><a href="language.types.float.php" class="type float">float</a></span>. De outra forma, se os operadores forem interpretados como
  <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>s, o resultado será um <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>. Note que isso
  <em class="emphasis">não</em> muda os tipos dos operadores: apenas muda como
  esses operadores são avaliados e qual o tipo da expressão.
 </p>

 <div class="informalexample">
  <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$foo&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">"1"</span><span style="color: #007700">;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;string&nbsp;(ASCII&nbsp;49)<br /></span><span style="color: #0000BB">$foo&nbsp;</span><span style="color: #007700">*=&nbsp;</span><span style="color: #0000BB">2</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;agora&nbsp;um&nbsp;inteiro&nbsp;(2)<br /></span><span style="color: #0000BB">$foo&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">$foo&nbsp;</span><span style="color: #007700">*&nbsp;</span><span style="color: #0000BB">1.3</span><span style="color: #007700">;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;agora&nbsp;um&nbsp;float&nbsp;(2.6)<br /></span><span style="color: #0000BB">$foo&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">5&nbsp;</span><span style="color: #007700">*&nbsp;</span><span style="color: #DD0000">"10&nbsp;pequenos&nbsp;porcos"</span><span style="color: #007700">;&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;&nbsp;um&nbsp;inteiro&nbsp;(50)<br /></span><span style="color: #0000BB">$foo&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">5&nbsp;</span><span style="color: #007700">*&nbsp;</span><span style="color: #DD0000">"10&nbsp;minúsculos&nbsp;porcos"</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;um&nbsp;inteiro&nbsp;(50)<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>

  </div>

 </div>

 <p class="simpara">
  Se os últimos dois exemplos lhe parecerem estranhos, veja a <a href="language.types.string.php#language.types.string.conversion" class="link">Conversão de
  strings para números</a>.
 </p>

 <p class="simpara">
  Para forçar uma variável ser avaliada como um certo tipo, veja a seção
  <a href="language.types.type-juggling.php#language.types.typecasting" class="link">Conversão de tipo</a>. Se desejar mudar o tipo de uma variável, veja
  a função <span class="function"><a href="function.settype.php" class="function">settype()</a></span>.
 </p>

 <p class="para">
  Para testar qualquer um dos exemplo desta seção, você pode
  usar a função <span class="function"><a href="function.var-dump.php" class="function">var_dump()</a></span>.
 </p>

 <blockquote class="note"><p><strong class="note">Nota</strong>: 
  <p class="para">
   O comportamento de uma conversão automática para <span class="type"><a href="language.types.array.php" class="type array">array</a></span> é atualmente
   indefinida.
  </p>

  <p class="para">
   O PHP também suporta indexação em <span class="type"><a href="language.types.string.php" class="type string">string</a></span>s via índice usando a
   mesma sintaxe de <span class="type"><a href="language.types.array.php" class="type array">array</a></span>, o seguinte exemplo é válido
   para todas versões do PHP:
  </p>

  <div class="informalexample">
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$a&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'car'</span><span style="color: #007700">;&nbsp;</span><span style="color: #FF8000">//&nbsp;$a&nbsp;é&nbsp;uma&nbsp;string<br /></span><span style="color: #0000BB">$a</span><span style="color: #007700">[</span><span style="color: #0000BB">0</span><span style="color: #007700">]&nbsp;=&nbsp;</span><span style="color: #DD0000">'b'</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$a&nbsp;é&nbsp;ainda&nbsp;uma&nbsp;string<br /></span><span style="color: #007700">echo&nbsp;</span><span style="color: #0000BB">$a</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;bar<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>

  <p class="para">
   Veja a seção intitulada <a href="language.types.string.php#language.types.string.substr" class="link">Acessando
   caracteres da string</a> para mais informações.
  </p>
 </p></blockquote>

 <div class="sect2" id="language.types.typecasting">
  <h3 class="title">Conversão de Tipos</h3>

  <p class="para">
   A conversão de tipos no PHP funciona como no C: o nome de um
   tipo desejado é escrito entre parênteses antes da variável que se deseja converter.
  </p>

  <div class="informalexample">
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$foo&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">10</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;um&nbsp;inteiro<br /></span><span style="color: #0000BB">$bar&nbsp;</span><span style="color: #007700">=&nbsp;(boolean)&nbsp;</span><span style="color: #0000BB">$foo</span><span style="color: #007700">;&nbsp;</span><span style="color: #FF8000">//&nbsp;$bar&nbsp;é&nbsp;um&nbsp;booleano<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>

  <p class="para">
   As conversões permitidas são:
  </p>

  <ul class="itemizedlist">
   <li class="listitem">
    <span class="simpara">(int), (integer) - molde para inteiro</span>
   </li>
   <li class="listitem">
    <span class="simpara">(bool), (boolean) - converte para booleano</span>
   </li>
   <li class="listitem">
    <span class="simpara">(float), (double), (real) - converte para número de ponto flutuante</span>
   </li>
   <li class="listitem">
    <span class="simpara">(string) - converte para string</span>
   </li>
   <li class="listitem">
    <span class="simpara">(array) - converte para array</span>
   </li>
   <li class="listitem">
    <span class="simpara">(object) - converte para objeto</span>
   </li>
   <li class="listitem">
    <span class="simpara">(unset) - converte para <span class="type"><a href="language.types.null.php" class="type NULL">NULL</a></span></span>
   </li>
  </ul>

  <p class="para">
   (binary) e o prefixo b foram adicionados no PHP 5.2.1. Note que
   (binary) é essencialmente o mesmo que (string), mas não deve ser
   invocado
  </p>

  <p class="para">
   Conversão (unset) está depreciada a partir do PHP 7.2.0. Note que (unset)
   é o mesmo que atribuir <span class="type"><a href="language.types.null.php" class="type NULL">NULL</a></span> a variável ou chamada. Conversão
   (unset) será removida a partir do PHP 8.0.0.
  </p>

  <p class="para">
   Note que tabulações e espaços são permitidos dentro dos parênteses, então
   o seguinte são funcionalmente equivalentes:
  </p>

  <div class="informalexample">
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$foo&nbsp;</span><span style="color: #007700">=&nbsp;(int)&nbsp;</span><span style="color: #0000BB">$bar</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$foo&nbsp;</span><span style="color: #007700">=&nbsp;(&nbsp;int&nbsp;)&nbsp;</span><span style="color: #0000BB">$bar</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
    </div>


    <p class="para">
     Convertendo <span class="type"><a href="language.types.string.php" class="type string">string</a></span>s literais e variáveis para <span class="type"><a href="language.types.string.php" class="type string">string</a></span>s
     binárias:
    </p>

    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$binary&nbsp;</span><span style="color: #007700">=&nbsp;(binary)</span><span style="color: #0000BB">$string</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$binary&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">b"binary&nbsp;string"</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>

  <blockquote class="note"><p><strong class="note">Nota</strong>: 
   <p class="para">
    Em vez de converter uma variável para <span class="type"><a href="language.types.string.php" class="type string">string</a></span>, pode-se também englobar
    a variável entre aspas duplas.
   </p>

   <div class="informalexample">
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$foo&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">10</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;um&nbsp;interio<br /></span><span style="color: #0000BB">$str&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">"</span><span style="color: #0000BB">$foo</span><span style="color: #DD0000">"</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$str&nbsp;é&nbsp;uma&nbsp;string<br /></span><span style="color: #0000BB">$fst&nbsp;</span><span style="color: #007700">=&nbsp;(string)&nbsp;</span><span style="color: #0000BB">$foo</span><span style="color: #007700">;&nbsp;</span><span style="color: #FF8000">//&nbsp;$fst&nbsp;tambem&nbsp;é&nbsp;uma&nbsp;string<br /><br />//&nbsp;Isto&nbsp;imprimirah&nbsp;"eles&nbsp;são&nbsp;o&nbsp;mesmo"<br /></span><span style="color: #007700">if&nbsp;(</span><span style="color: #0000BB">$fst&nbsp;</span><span style="color: #007700">===&nbsp;</span><span style="color: #0000BB">$str</span><span style="color: #007700">)&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #DD0000">"eles&nbsp;são&nbsp;o&nbsp;mesmo"</span><span style="color: #007700">;<br />}<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>
  </p></blockquote>

  <p class="para">
   Pode não ser tão óbvio o que ocorre exatamente quando se converte
   entre certos tipos. Para mais informações, veja essas seções:
  </p>

  <ul class="itemizedlist">
   <li class="listitem">
    <span class="simpara">
      <a href="language.types.boolean.php#language.types.boolean.casting" class="link">Convertendo para booleano</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
      <a href="language.types.integer.php#language.types.integer.casting" class="link">Convertendo para inteiro</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
      <a href="language.types.float.php#language.types.float.casting" class="link">Convertendo para ponto flutuante</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
      <a href="language.types.string.php#language.types.string.casting" class="link">Convertendo para string</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
      <a href="language.types.array.php#language.types.array.casting" class="link">Convertendo para array</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
      <a href="language.types.object.php#language.types.object.casting" class="link">Convertendo para objeto</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
      <a href="language.types.resource.php#language.types.resource.casting" class="link">Convertendo para
      recurso</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
     <a href="language.types.null.php#language.types.null.casting" class="link">Convertendo para NULL</a>
    </span>
   </li>
   <li class="listitem">
    <span class="simpara">
     <a href="types.comparisons.php" class="link">Tabelas de comparação entre tipos</a>
    </span>
   </li>
  </ul>

 </div>
</div>
<section id="usernotes">
 <div class="head">
  <span class="action"><a href="/manual/add-note.php?sect=language.types.type-juggling&amp;redirect=https://www.php.net/manual/pt_BR/language.types.type-juggling.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></span>
  <h3 class="title">User Contributed Notes <span class="count">35 notes</span></h3>
 </div><div id="allnotes">
  <div class="note" id="49849">  <div class="votes">
    <div id="Vu49849">
    <a href="/manual/vote-note.php?id=49849&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd49849">
    <a href="/manual/vote-note.php?id=49849&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V49849" title="68% like this...">
    60
    </div>
  </div>
  <a href="#49849" class="name">
  <strong class="user"><em>Raja</em></strong></a><a class="genanchor" href="#49849"> &para;</a><div class="date" title="2005-02-10 03:05"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom49849">
<div class="phpcode"><code><span class="html">
Uneven division of an integer variable by another integer variable will result in a float by automatic conversion -- you do not have to cast the variables to floats in order to avoid integer truncation (as you would in C, for example):<br /><br />$dividend = 2;<br />$divisor = 3;<br />$quotient = $dividend/$divisor;<br />print $quotient; // 0.66666666666667</span>
</code></div>
  </div>
 </div>
  <div class="note" id="123680">  <div class="votes">
    <div id="Vu123680">
    <a href="/manual/vote-note.php?id=123680&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd123680">
    <a href="/manual/vote-note.php?id=123680&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V123680" title="92% like this...">
    11
    </div>
  </div>
  <a href="#123680" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#123680"> &para;</a><div class="date" title="2019-03-11 05:16"><strong>9 months ago</strong></div>
  <div class="text" id="Hcom123680">
<div class="phpcode"><code><span class="html">
"An example of PHP's automatic type conversion is the multiplication operator '*'. If either operand is a float, then both operands are evaluated as floats, and the result will be a float. Otherwise, the operands will be interpreted as integers, and the result will also be an integer. Note that this does not change the types of the operands themselves; the only change is in how the operands are evaluated and what the type of the expression itself is."<br /><br />I understand what the doc is trying to say here, but this sentence is not correct as stated, other types can be coerced into floats.<br /><br />e.g.<br /><br /><span class="default">&lt;?php<br />$a </span><span class="keyword">= </span><span class="string">"1.5"</span><span class="keyword">; </span><span class="comment">// $a is a string<br /></span><span class="default">$b </span><span class="keyword">= </span><span class="default">100</span><span class="keyword">; </span><span class="comment">// $b is an int<br /></span><span class="default">$c </span><span class="keyword">= </span><span class="default">$a </span><span class="keyword">* </span><span class="default">$b</span><span class="keyword">; </span><span class="comment">// $c is a float, value is 150<br />// multiplication resulted in a float despite fact that neither operand was a float</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="27205">  <div class="votes">
    <div id="Vu27205">
    <a href="/manual/vote-note.php?id=27205&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd27205">
    <a href="/manual/vote-note.php?id=27205&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V27205" title="66% like this...">
    28
    </div>
  </div>
  <a href="#27205" class="name">
  <strong class="user"><em>yury at krasu dot ru</em></strong></a><a class="genanchor" href="#27205"> &para;</a><div class="date" title="2002-11-27 01:24"><strong>17 years ago</strong></div>
  <div class="text" id="Hcom27205">
<div class="phpcode"><code><span class="html">
incremental operator ("++") doesn't make type conversion from boolean to int, and if an variable is boolean and equals TRUE than after ++ operation it remains as TRUE, so:<br /><br />$a = TRUE; <br />echo ($a++).$a;&nbsp; // prints "11"</span>
</code></div>
  </div>
 </div>
  <div class="note" id="24809">  <div class="votes">
    <div id="Vu24809">
    <a href="/manual/vote-note.php?id=24809&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd24809">
    <a href="/manual/vote-note.php?id=24809&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V24809" title="62% like this...">
    20
    </div>
  </div>
  <a href="#24809" class="name"><strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#24809"> &para;</a><div class="date" title="2002-08-28 10:26"><strong>17 years ago</strong></div>
  <div class="text" id="Hcom24809">
<div class="phpcode"><code><span class="html">
Printing or echoing a FALSE boolean value or a NULL value results in an empty string:<br />(string)TRUE //returns "1"<br />(string)FALSE //returns ""<br />echo TRUE; //prints "1"<br />echo FALSE; //prints nothing!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="111930">  <div class="votes">
    <div id="Vu111930">
    <a href="/manual/vote-note.php?id=111930&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd111930">
    <a href="/manual/vote-note.php?id=111930&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V111930" title="61% like this...">
    18
    </div>
  </div>
  <a href="#111930" class="name">
  <strong class="user"><em>fardelian</em></strong></a><a class="genanchor" href="#111930"> &para;</a><div class="date" title="2013-04-13 03:23"><strong>6 years ago</strong></div>
  <div class="text" id="Hcom111930">
<div class="phpcode"><code><span class="html">
Casting objects to arrays is a pain. Example:<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">class </span><span class="default">MyClass </span><span class="keyword">{<br /><br />&nbsp; &nbsp; private </span><span class="default">$priv </span><span class="keyword">= </span><span class="string">'priv_value'</span><span class="keyword">;<br />&nbsp; &nbsp; protected </span><span class="default">$prot </span><span class="keyword">= </span><span class="string">'prot_value'</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$pub </span><span class="keyword">= </span><span class="string">'pub_value'</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$MyClasspriv </span><span class="keyword">= </span><span class="string">'second_pub_value'</span><span class="keyword">;<br /><br />}<br /><br /></span><span class="default">$test </span><span class="keyword">= new </span><span class="default">MyClass</span><span class="keyword">();<br />echo </span><span class="string">'&lt;pre&gt;'</span><span class="keyword">;<br /></span><span class="default">print_r</span><span class="keyword">((array) </span><span class="default">$test</span><span class="keyword">);<br /><br /></span><span class="comment">/*<br />Array<br />(<br />&nbsp; &nbsp; [MyClasspriv] =&gt; priv_value<br />&nbsp; &nbsp; [*prot] =&gt; prot_value<br />&nbsp; &nbsp; [pub] =&gt; pub_value<br />&nbsp; &nbsp; [MyClasspriv] =&gt; second_pub_value<br />)<br /> */<br /><br /></span><span class="default">?&gt;<br /></span><br />Yes, that looks like an array with two keys with the same name and it looks like the protected field was prepended with an asterisk. But that's not true:<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">foreach ((array) </span><span class="default">$test </span><span class="keyword">as </span><span class="default">$key </span><span class="keyword">=&gt; </span><span class="default">$value</span><span class="keyword">) {<br />&nbsp; &nbsp; </span><span class="default">$len </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$key</span><span class="keyword">);<br />&nbsp; &nbsp; echo </span><span class="string">"</span><span class="keyword">{</span><span class="default">$key</span><span class="keyword">}</span><span class="string"> (</span><span class="keyword">{</span><span class="default">$len</span><span class="keyword">}</span><span class="string">) =&gt; </span><span class="keyword">{</span><span class="default">$value</span><span class="keyword">}</span><span class="string">&lt;br /&gt;"</span><span class="keyword">;<br />&nbsp; &nbsp; for (</span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$i </span><span class="keyword">&lt; </span><span class="default">$len</span><span class="keyword">; ++</span><span class="default">$i</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; echo </span><span class="default">ord</span><span class="keyword">(</span><span class="default">$key</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">]) . </span><span class="string">' '</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; echo </span><span class="string">'&lt;hr /&gt;'</span><span class="keyword">;<br />}<br /><br /></span><span class="comment">/*<br />MyClasspriv (13) =&gt; priv_value<br />0 77 121 67 108 97 115 115 0 112 114 105 118<br />*prot (7) =&gt; prot_value<br />0 42 0 112 114 111 116<br />pub (3) =&gt; pub_value<br />112 117 98<br />MyClasspriv (11) =&gt; second_pub_value<br />77 121 67 108 97 115 115 112 114 105 118<br /> */<br /><br /></span><span class="default">?&gt;<br /></span><br />The char codes show that the protected keys are prepended with '\0*\0' and private keys are prepended with '\0'.__CLASS__.'\0' so be careful when playing around with this.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="100460">  <div class="votes">
    <div id="Vu100460">
    <a href="/manual/vote-note.php?id=100460&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd100460">
    <a href="/manual/vote-note.php?id=100460&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V100460" title="63% like this...">
    9
    </div>
  </div>
  <a href="#100460" class="name">
  <strong class="user"><em>rmirabelle</em></strong></a><a class="genanchor" href="#100460"> &para;</a><div class="date" title="2010-10-17 10:18"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom100460">
<div class="phpcode"><code><span class="html">
The object casting methods presented here do not take into account the class hierarchy of the class you're trying to cast your object into.<br /><br />/**<br />&nbsp; &nbsp;&nbsp; * Convert an object to a specific class.<br />&nbsp; &nbsp;&nbsp; * @param object $object<br />&nbsp; &nbsp;&nbsp; * @param string $class_name The class to cast the object to<br />&nbsp; &nbsp;&nbsp; * @return object<br />&nbsp; &nbsp;&nbsp; */<br />&nbsp; &nbsp; public static function cast($object, $class_name) {<br />&nbsp; &nbsp; &nbsp; &nbsp; if($object === false) return false;<br />&nbsp; &nbsp; &nbsp; &nbsp; if(class_exists($class_name)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $ser_object&nbsp; &nbsp;&nbsp; = serialize($object);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $obj_name_len&nbsp; &nbsp;&nbsp; = strlen(get_class($object));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $start&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; = $obj_name_len + strlen($obj_name_len) + 6;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $new_object&nbsp; &nbsp; &nbsp; = 'O:' . strlen($class_name) . ':"' . $class_name . '":';<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $new_object&nbsp; &nbsp;&nbsp; .= substr($ser_object, $start);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $new_object&nbsp; &nbsp;&nbsp; = unserialize($new_object);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; /**<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; * The new object is of the correct type but<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; * is not fully initialized throughout its graph.<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; * To get the full object graph (including parent<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; * class data, we need to create a new instance of <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; * the specified class and then assign the new <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; * properties to it.<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; */<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $graph = new $class_name;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; foreach($new_object as $prop =&gt; $val) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $graph-&gt;$prop = $val;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return $graph;<br />&nbsp; &nbsp; &nbsp; &nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; throw new CoreException(false, "could not find class $class_name for casting in DB::cast");<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return false;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }</span>
</code></div>
  </div>
 </div>
  <div class="note" id="109059">  <div class="votes">
    <div id="Vu109059">
    <a href="/manual/vote-note.php?id=109059&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd109059">
    <a href="/manual/vote-note.php?id=109059&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V109059" title="58% like this...">
    12
    </div>
  </div>
  <a href="#109059" class="name">
  <strong class="user"><em>ieee at REMOVE dot bk dot ru</em></strong></a><a class="genanchor" href="#109059"> &para;</a><div class="date" title="2012-06-17 04:26"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom109059">
<div class="phpcode"><code><span class="html">
There are some shorter and faster (at least on my machine) ways to perform a type cast.<br /><span class="default">&lt;?php<br />$string</span><span class="keyword">=</span><span class="string">'12345.678'</span><span class="keyword">;<br /></span><span class="default">$float</span><span class="keyword">=+</span><span class="default">$string</span><span class="keyword">; <br /></span><span class="default">$integer</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">|</span><span class="default">$string</span><span class="keyword">;<br /></span><span class="default">$boolean</span><span class="keyword">=!!</span><span class="default">$string</span><span class="keyword">;<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="103594">  <div class="votes">
    <div id="Vu103594">
    <a href="/manual/vote-note.php?id=103594&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd103594">
    <a href="/manual/vote-note.php?id=103594&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V103594" title="58% like this...">
    6
    </div>
  </div>
  <a href="#103594" class="name">
  <strong class="user"><em>jphansen at uga dot edu</em></strong></a><a class="genanchor" href="#103594"> &para;</a><div class="date" title="2011-04-21 10:53"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom103594">
<div class="phpcode"><code><span class="html">
Type casting from string to int and vice versa is probably the most common conversation. PHP does this very simply through the +. and .= operators, removing any explicit casting:<br /><br /><span class="default">&lt;?php<br />$x </span><span class="keyword">= </span><span class="default">1</span><span class="keyword">;<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">); </span><span class="comment">// int(1)<br /></span><span class="default">$x </span><span class="keyword">.= </span><span class="default">1</span><span class="keyword">;<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">); </span><span class="comment">// string(2) "11"; also an empty string ("") would cast to string without changing $x<br /><br /></span><span class="default">$x </span><span class="keyword">= </span><span class="string">"1"</span><span class="keyword">;<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">);&nbsp; </span><span class="comment">// string(1) "1"<br /></span><span class="default">$x </span><span class="keyword">+= </span><span class="default">1</span><span class="keyword">;<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">); </span><span class="comment">// int(2); also a zero value (0) would cast to int without changing $x<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="115373">  <div class="votes">
    <div id="Vu115373">
    <a href="/manual/vote-note.php?id=115373&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd115373">
    <a href="/manual/vote-note.php?id=115373&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V115373" title="56% like this...">
    4
    </div>
  </div>
  <a href="#115373" class="name">
  <strong class="user"><em>kuzawinski dot marcin at NOSPAM dot gmail dot com</em></strong></a><a class="genanchor" href="#115373"> &para;</a><div class="date" title="2014-07-14 09:40"><strong>5 years ago</strong></div>
  <div class="text" id="Hcom115373">
<div class="phpcode"><code><span class="html">
You REALLY must be aware what you are doing, when you cast a lot&nbsp; in your code. For example, you can accidentaly change FALSE to TRUE&nbsp; (probably not in one line, like here):<br /><br />if(TRUE === (boolean) (array) (int) FALSE) {<br />&nbsp; &nbsp; kaboom();<br />}</span>
</code></div>
  </div>
 </div>
  <div class="note" id="102877">  <div class="votes">
    <div id="Vu102877">
    <a href="/manual/vote-note.php?id=102877&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd102877">
    <a href="/manual/vote-note.php?id=102877&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V102877" title="56% like this...">
    4
    </div>
  </div>
  <a href="#102877" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#102877"> &para;</a><div class="date" title="2011-03-11 11:01"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom102877">
<div class="phpcode"><code><span class="html">
Checking for strings to be integers?<br />How about if a string is a float?<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="comment">/* checks if a string is an integer with possible whitespace before and/or after, and also isolates the integer */<br /></span><span class="default">$isInt</span><span class="keyword">=</span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">'/^\s*([0-9]+)\s*$/'</span><span class="keyword">, </span><span class="default">$myString</span><span class="keyword">, </span><span class="default">$myInt</span><span class="keyword">);<br /><br />echo </span><span class="string">'Is Integer? '</span><span class="keyword">,&nbsp; (</span><span class="default">$isInt</span><span class="keyword">) ? </span><span class="string">'Yes: '</span><span class="keyword">.</span><span class="default">$myInt</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">] : </span><span class="string">'No'</span><span class="keyword">, </span><span class="string">"\n"</span><span class="keyword">;<br /><br /></span><span class="comment">/* checks if a string is an integer with no whitespace before or after&nbsp; */<br /></span><span class="default">$isInt</span><span class="keyword">=</span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">'/^[0-9]+$/'</span><span class="keyword">, </span><span class="default">$myString</span><span class="keyword">);<br /><br />echo </span><span class="string">'Is Integer? '</span><span class="keyword">,&nbsp; (</span><span class="default">$isInt</span><span class="keyword">) ? </span><span class="string">'Yes' </span><span class="keyword">: </span><span class="string">'No'</span><span class="keyword">, </span><span class="string">"\n"</span><span class="keyword">;<br /><br /></span><span class="comment">/* When checking for floats, we assume the possibility of no decimals needed.&nbsp; If you MUST require decimals (forcing the user to type 7.0 for example) replace the sequence:<br />[0-9]+(\.[0-9]+)? <br />with <br />[0-9]+\.[0-9]+ <br />*/<br /><br />/* checks if a string is a float with possible whitespace before and/or after, and also isolates the number */<br /></span><span class="default">$isFloat</span><span class="keyword">=</span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">'/^\s*([0-9]+(\.[0-9]+)?)\s*$/'</span><span class="keyword">, </span><span class="default">$myString</span><span class="keyword">, </span><span class="default">$myNum</span><span class="keyword">);<br /><br />echo </span><span class="string">'Is Number? '</span><span class="keyword">,&nbsp; (</span><span class="default">$isFloat</span><span class="keyword">) ? </span><span class="string">'Yes: '</span><span class="keyword">.</span><span class="default">$myNum</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">] : </span><span class="string">'No'</span><span class="keyword">, </span><span class="string">"\n"</span><span class="keyword">;<br /><br /></span><span class="comment">/* checks if a string is a float with no whitespace before or after */<br /></span><span class="default">$isInt</span><span class="keyword">=</span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">'/^[0-9]+(\.[0-9]+)?$/'</span><span class="keyword">, </span><span class="default">$myString</span><span class="keyword">);<br /><br />echo </span><span class="string">'Is Number? '</span><span class="keyword">,&nbsp; (</span><span class="default">$isFloat</span><span class="keyword">) ? </span><span class="string">'Yes' </span><span class="keyword">: </span><span class="string">'No'</span><span class="keyword">, </span><span class="string">"\n"</span><span class="keyword">;<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="100050">  <div class="votes">
    <div id="Vu100050">
    <a href="/manual/vote-note.php?id=100050&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd100050">
    <a href="/manual/vote-note.php?id=100050&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V100050" title="55% like this...">
    3
    </div>
  </div>
  <a href="#100050" class="name">
  <strong class="user"><em>martinscotta at gmail dot com</em></strong></a><a class="genanchor" href="#100050"> &para;</a><div class="date" title="2010-09-21 08:44"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom100050">
<div class="phpcode"><code><span class="html">
in response to bhsmither at gmail.com<br /><br />It raises a warning because of the bad enquoted variable<br /><br /><span class="default">&lt;?php<br /><br />error_reporting</span><span class="keyword">( </span><span class="default">E_ALL </span><span class="keyword">| </span><span class="default">E_STRICT </span><span class="keyword">);<br /><br /></span><span class="default">$foo</span><span class="keyword">[</span><span class="string">'ten'</span><span class="keyword">] = </span><span class="default">10</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// $foo['ten'] is an array holding an integer at key "ten"<br /></span><span class="default">$str </span><span class="keyword">= </span><span class="string">"</span><span class="keyword">{</span><span class="default">$foo</span><span class="keyword">[</span><span class="string">'ten'</span><span class="keyword">]}</span><span class="string">"</span><span class="keyword">;&nbsp; </span><span class="comment">// works "10"<br /></span><span class="default">$str </span><span class="keyword">= </span><span class="string">"</span><span class="default">$foo</span><span class="keyword">[</span><span class="default">ten</span><span class="keyword">]</span><span class="string">"</span><span class="keyword">;&nbsp; &nbsp; &nbsp; </span><span class="comment">// DO NOT work!</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="89637">  <div class="votes">
    <div id="Vu89637">
    <a href="/manual/vote-note.php?id=89637&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd89637">
    <a href="/manual/vote-note.php?id=89637&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V89637" title="55% like this...">
    3
    </div>
  </div>
  <a href="#89637" class="name">
  <strong class="user"><em>edgar dot klerks at gmail dot com</em></strong></a><a class="genanchor" href="#89637"> &para;</a><div class="date" title="2009-03-17 08:04"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom89637">
<div class="phpcode"><code><span class="html">
It seems (unset) is pretty useless. But for people who like to make their code really compact (and probably unreadable). You can use it to use an variable and unset it on the same line:<br /><br />Without cast: <br /><br /><span class="default">&lt;?php<br /><br />$hello </span><span class="keyword">= </span><span class="string">'Hello world'</span><span class="keyword">;<br />print </span><span class="default">$hello</span><span class="keyword">;<br />unset(</span><span class="default">$hello</span><span class="keyword">);<br /><br /></span><span class="default">?&gt;<br /></span><br />With the unset cast: <br /><br /><span class="default">&lt;?php<br /><br />$hello </span><span class="keyword">= </span><span class="string">'Hello world'</span><span class="keyword">;<br /></span><span class="default">$hello </span><span class="keyword">= (unset) print </span><span class="default">$hello</span><span class="keyword">;<br /><br /></span><span class="default">?&gt;<br /></span><br />Hoorah, we lost another line!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="62113">  <div class="votes">
    <div id="Vu62113">
    <a href="/manual/vote-note.php?id=62113&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd62113">
    <a href="/manual/vote-note.php?id=62113&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V62113" title="54% like this...">
    2
    </div>
  </div>
  <a href="#62113" class="name">
  <strong class="user"><em>miracle at 1oo-percent dot de</em></strong></a><a class="genanchor" href="#62113"> &para;</a><div class="date" title="2006-02-20 05:26"><strong>13 years ago</strong></div>
  <div class="text" id="Hcom62113">
<div class="phpcode"><code><span class="html">
If you want to convert a string automatically to float or integer (e.g. "0.234" to float and "123" to int), simply add 0 to the string - PHP will do the rest.<br /><br />e.g.<br /><br />$val = 0 + "1.234";<br />(type of $val is float now)<br /><br />$val = 0 + "123";<br />(type of $val is integer now)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="102737">  <div class="votes">
    <div id="Vu102737">
    <a href="/manual/vote-note.php?id=102737&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd102737">
    <a href="/manual/vote-note.php?id=102737&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V102737" title="53% like this...">
    2
    </div>
  </div>
  <a href="#102737" class="name">
  <strong class="user"><em>namaroulis at gmail dot com</em></strong></a><a class="genanchor" href="#102737"> &para;</a><div class="date" title="2011-03-02 01:47"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom102737">
<div class="phpcode"><code><span class="html">
I found it tricky to check if a posted value was an integer.<br /><br /><span class="default">&lt;?php<br /><br />$_POST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">] = </span><span class="string">"42"</span><span class="keyword">;<br /><br /></span><span class="default">is_int</span><span class="keyword">( </span><span class="default">$_POST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">] ); </span><span class="comment">//false<br /></span><span class="default">is_int</span><span class="keyword">( </span><span class="default">intval</span><span class="keyword">( </span><span class="string">"anything" </span><span class="keyword">) ); </span><span class="comment">//always true<br /></span><span class="default">?&gt;<br /></span><br />A method I use for checking if a string represents an integer value.<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">check_int</span><span class="keyword">( </span><span class="default">$str </span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return&nbsp; </span><span class="default">is_numeric</span><span class="keyword">( </span><span class="default">$str </span><span class="keyword">) &amp;&amp; </span><span class="default">intval</span><span class="keyword">( </span><span class="default">$str </span><span class="keyword">) - </span><span class="default">$str </span><span class="keyword">== </span><span class="default">0</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="124070">  <div class="votes">
    <div id="Vu124070">
    <a href="/manual/vote-note.php?id=124070&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd124070">
    <a href="/manual/vote-note.php?id=124070&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V124070" title="100% like this...">
    1
    </div>
  </div>
  <a href="#124070" class="name">
  <strong class="user"><em>Dhairya Lakhera</em></strong></a><a class="genanchor" href="#124070"> &para;</a><div class="date" title="2019-07-25 10:02"><strong>5 months ago</strong></div>
  <div class="text" id="Hcom124070">
<div class="phpcode"><code><span class="html">
Value of uninitialized variable of different data types.<br /><br />settype($a,'bool');<br />var_dump($a);&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; //boolean false<br /><br />settype($b,'string');<br />var_dump($b);&nbsp; &nbsp; &nbsp; &nbsp; //string '' (length=0)<br /><br />settype($c,'array');<br />var_dump($c);&nbsp; &nbsp; &nbsp; &nbsp; //array (size=0)&nbsp; empty<br /><br />settype($d,'int');<br />var_dump($d);&nbsp; &nbsp; &nbsp;&nbsp; //int 0<br /><br />settype($e,'float');<br />var_dump($e);&nbsp; &nbsp; &nbsp; //float 0<br /><br />settype($f,'object');<br />var_dump($f);&nbsp; &nbsp;&nbsp; //object(stdClass)[1]</span>
</code></div>
  </div>
 </div>
  <div class="note" id="86419">  <div class="votes">
    <div id="Vu86419">
    <a href="/manual/vote-note.php?id=86419&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd86419">
    <a href="/manual/vote-note.php?id=86419&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V86419" title="51% like this...">
    1
    </div>
  </div>
  <a href="#86419" class="name">
  <strong class="user"><em>hek at theeks dot net</em></strong></a><a class="genanchor" href="#86419"> &para;</a><div class="date" title="2008-10-17 09:24"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom86419">
<div class="phpcode"><code><span class="html">
It would be useful to know the precedence (for lack of a better word) for type juggling.&nbsp; This entry currently explains that "if either operand is a float, then both operands are evaluated as floats, and the result will be a float" but could (and I think should) provide a hierarchy that indicates, for instance, "between an int and a boolean, int wins; between a float and an int, float wins; between a string and a float, string wins" and so on (and don't count on my example accurately capturing the true hierarchy, as I haven't actually done the tests to figure it out).&nbsp; Thanks!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="107419">  <div class="votes">
    <div id="Vu107419">
    <a href="/manual/vote-note.php?id=107419&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd107419">
    <a href="/manual/vote-note.php?id=107419&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V107419" title="50% like this...">
    0
    </div>
  </div>
  <a href="#107419" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#107419"> &para;</a><div class="date" title="2012-02-07 06:31"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom107419">
<div class="phpcode"><code><span class="html">
namaroulis stated "I found it tricky to check if a posted value was an integer"; to test if a variable is a number or a numeric string (such as form input, which is always a string), you must use is_numeric():<br /><br /><span class="default">&lt;?php<br />$_POST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">] = </span><span class="string">"42"</span><span class="keyword">;<br /><br /></span><span class="default">is_numeric</span><span class="keyword">( </span><span class="default">$_POST</span><span class="keyword">[</span><span class="string">'a'</span><span class="keyword">] ); </span><span class="comment">// true<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="105671">  <div class="votes">
    <div id="Vu105671">
    <a href="/manual/vote-note.php?id=105671&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd105671">
    <a href="/manual/vote-note.php?id=105671&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V105671" title="50% like this...">
    0
    </div>
  </div>
  <a href="#105671" class="name">
  <strong class="user"><em>hemi68 at hotmail dot com</em></strong></a><a class="genanchor" href="#105671"> &para;</a><div class="date" title="2011-09-06 08:01"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom105671">
<div class="phpcode"><code><span class="html">
Cast a string to binary using PHP &lt; 5.2.1<br /><br /> $binary = unpack('c*', $string);</span>
</code></div>
  </div>
 </div>
  <div class="note" id="96869">  <div class="votes">
    <div id="Vu96869">
    <a href="/manual/vote-note.php?id=96869&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd96869">
    <a href="/manual/vote-note.php?id=96869&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V96869" title="50% like this...">
    0
    </div>
  </div>
  <a href="#96869" class="name">
  <strong class="user"><em>bhsmither at gmail.com</em></strong></a><a class="genanchor" href="#96869"> &para;</a><div class="date" title="2010-03-19 03:41"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom96869">
<div class="phpcode"><code><span class="html">
<span class="default">&lt;?php<br />$foo</span><span class="keyword">[</span><span class="string">'ten'</span><span class="keyword">] = </span><span class="default">10</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// $foo['ten'] is an array holding an integer at key "ten"<br /></span><span class="default">$str </span><span class="keyword">= </span><span class="string">"</span><span class="default">$foo</span><span class="keyword">[</span><span class="string">'ten']"</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// throws T_ENCAPSED_AND_WHITESPACE error<br /></span><span class="default">$str </span><span class="keyword">= </span><span class="string">"</span><span class="default">$foo</span><span class="keyword">[</span><span class="default">ten</span><span class="keyword">]</span><span class="string">"</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// works because constants are skipped in quotes<br /></span><span class="default">$fst </span><span class="keyword">= (string) </span><span class="default">$foo</span><span class="keyword">[</span><span class="string">'ten'</span><span class="keyword">]; </span><span class="comment">// works with clear intention<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="86205">  <div class="votes">
    <div id="Vu86205">
    <a href="/manual/vote-note.php?id=86205&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd86205">
    <a href="/manual/vote-note.php?id=86205&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V86205" title="50% like this...">
    0
    </div>
  </div>
  <a href="#86205" class="name">
  <strong class="user"><em>wbcarts at juno dot com</em></strong></a><a class="genanchor" href="#86205"> &para;</a><div class="date" title="2008-10-07 06:05"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom86205">
<div class="phpcode"><code><span class="html">
WHERE'S THE BEEF?<br /><br />Looks like type-casting user-defined objects is a real pain, and ya gotta be nuttin' less than a brain jus ta cypher-it. But since PHP supports OOP, you can add the capabilities right now. Start with any simple class.<br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Point </span><span class="keyword">{<br />&nbsp; protected </span><span class="default">$x</span><span class="keyword">, </span><span class="default">$y</span><span class="keyword">;<br /><br />&nbsp; public function </span><span class="default">__construct</span><span class="keyword">(</span><span class="default">$xVal </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">, </span><span class="default">$yVal </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">x </span><span class="keyword">= </span><span class="default">$xVal</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">y </span><span class="keyword">= </span><span class="default">$yVal</span><span class="keyword">;<br />&nbsp; }<br />&nbsp; public function </span><span class="default">getX</span><span class="keyword">() { return </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">x</span><span class="keyword">; }<br />&nbsp; public function </span><span class="default">getY</span><span class="keyword">() { return </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">y</span><span class="keyword">; }<br />}<br /><br /></span><span class="default">$p </span><span class="keyword">= new </span><span class="default">Point</span><span class="keyword">(</span><span class="default">25</span><span class="keyword">, </span><span class="default">35</span><span class="keyword">);<br />echo </span><span class="default">$p</span><span class="keyword">-&gt;</span><span class="default">getX</span><span class="keyword">();&nbsp; &nbsp; &nbsp; </span><span class="comment">// 25<br /></span><span class="keyword">echo </span><span class="default">$p</span><span class="keyword">-&gt;</span><span class="default">getY</span><span class="keyword">();&nbsp; &nbsp; &nbsp; </span><span class="comment">// 35<br /></span><span class="default">?&gt;<br /></span>Ok, now we need extra powers. PHP gives us several options:<br />&nbsp; A. We can tag on extra properties on-the-fly using everyday PHP syntax...<br />&nbsp; &nbsp; $p-&gt;z = 45; // here, $p is still an object of type [Point] but gains no capability, and it's on a per-instance basis, blah.<br />&nbsp; B. We can try type-casting it to a different type to access more functions...<br />&nbsp; &nbsp; $p = (SuperDuperPoint) $p; // if this is even allowed, I doubt it. But even if PHP lets this slide, the small amount of data Point holds would probably not be enough for the extra functions to work anyway. And we still need the class def + all extra data. We should have just instantiated a [SuperDuperPoint] object to begin with... and just like above, this only works on a per-instance basis.<br />&nbsp; C. Do it the right way using OOP - and just extend the Point class already.<br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Point3D </span><span class="keyword">extends </span><span class="default">Point </span><span class="keyword">{<br />&nbsp; protected </span><span class="default">$z</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// add extra properties...<br /><br />&nbsp; </span><span class="keyword">public function </span><span class="default">__construct</span><span class="keyword">(</span><span class="default">$xVal </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">, </span><span class="default">$yVal </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">, </span><span class="default">$zVal </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; </span><span class="default">parent</span><span class="keyword">::</span><span class="default">__construct</span><span class="keyword">(</span><span class="default">$xVal</span><span class="keyword">, </span><span class="default">$yVal</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">z </span><span class="keyword">= </span><span class="default">$zVal</span><span class="keyword">;<br />&nbsp; }<br />&nbsp; public function </span><span class="default">getZ</span><span class="keyword">() { return </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">z</span><span class="keyword">; }&nbsp; </span><span class="comment">// add extra functions...<br /></span><span class="keyword">}<br /><br /></span><span class="default">$p3d </span><span class="keyword">= new </span><span class="default">Point3D</span><span class="keyword">(</span><span class="default">25</span><span class="keyword">, </span><span class="default">35</span><span class="keyword">, </span><span class="default">45</span><span class="keyword">);&nbsp; </span><span class="comment">// more data, more functions, more everything...<br /></span><span class="keyword">echo </span><span class="default">$p3d</span><span class="keyword">-&gt;</span><span class="default">getX</span><span class="keyword">();&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// 25<br /></span><span class="keyword">echo </span><span class="default">$p3d</span><span class="keyword">-&gt;</span><span class="default">getY</span><span class="keyword">();&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// 35<br /></span><span class="keyword">echo </span><span class="default">$p3d</span><span class="keyword">-&gt;</span><span class="default">getZ</span><span class="keyword">();&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// 45<br /></span><span class="default">?&gt;<br /></span>Once the new class definition is written, you can make as many Point3D objects as you want. Each of them will have more data and functions already built-in. This is much better than trying to beef-up any "single lesser object" on-the-fly, and it's way easier to do.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="54070">  <div class="votes">
    <div id="Vu54070">
    <a href="/manual/vote-note.php?id=54070&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd54070">
    <a href="/manual/vote-note.php?id=54070&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V54070" title="50% like this...">
    0
    </div>
  </div>
  <a href="#54070" class="name"><strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#54070"> &para;</a><div class="date" title="2005-06-22 05:47"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom54070">
<div class="phpcode"><code><span class="html">
If you have a boolean, performing increments on it won't do anything despite it being 1.&nbsp; This is a case where you have to use a cast.<br /><br />&lt;html&gt;<br />&lt;body&gt; &lt;!-- don't want w3.org to get mad... --&gt;<br /><span class="default">&lt;?php<br />$bar </span><span class="keyword">= </span><span class="default">TRUE</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span>I have <span class="default">&lt;?=$bar?&gt;</span> bar.<br /><span class="default">&lt;?php<br />$bar</span><span class="keyword">++;<br /></span><span class="default">?&gt;<br /></span>I now have <span class="default">&lt;?=$bar?&gt;</span> bar.<br /><span class="default">&lt;?php<br />$bar </span><span class="keyword">= (int) </span><span class="default">$bar</span><span class="keyword">;<br /></span><span class="default">$bar</span><span class="keyword">++;<br /></span><span class="default">?&gt;<br /></span>I finally have <span class="default">&lt;?=$bar?&gt;</span> bar.<br />&lt;/body&gt;<br />&lt;/html&gt;<br /><br />That will print<br /><br />I have 1 bar.<br />I now have 1 bar.<br />I finally have 2 bar.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="40282">  <div class="votes">
    <div id="Vu40282">
    <a href="/manual/vote-note.php?id=40282&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd40282">
    <a href="/manual/vote-note.php?id=40282&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V40282" title="50% like this...">
    0
    </div>
  </div>
  <a href="#40282" class="name">
  <strong class="user"><em>philip_snyder at hotmail dot com</em></strong></a><a class="genanchor" href="#40282"> &para;</a><div class="date" title="2004-02-27 07:08"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom40282">
<div class="phpcode"><code><span class="html">
Re: the typecasting between classes post below... fantastic, but slightly flawed. Any class name longer than 9 characters becomes a problem... SO here's a simple fix:<br /><br />function typecast($old_object, $new_classname) {<br />&nbsp; if(class_exists($new_classname)) {<br />&nbsp; &nbsp; // Example serialized object segment<br />&nbsp; &nbsp; // O:5:"field":9:{s:5:...&nbsp;&nbsp; &lt;--- Class: Field<br />&nbsp; &nbsp; $old_serialized_prefix&nbsp; = "O:".strlen(get_class($old_object));<br />&nbsp; &nbsp; $old_serialized_prefix .= ":\"".get_class($old_object)."\":";<br /><br />&nbsp; &nbsp; $old_serialized_object = serialize($old_object);<br />&nbsp; &nbsp; $new_serialized_object = 'O:'.strlen($new_classname).':"'.$new_classname . '":';<br />&nbsp; &nbsp; $new_serialized_object .= substr($old_serialized_object,strlen($old_serialized_prefix));<br />&nbsp;&nbsp; return unserialize($new_serialized_object);<br />&nbsp; }<br />&nbsp; else<br />&nbsp;&nbsp; return false;<br />}<br /><br />Thanks for the previous code. Set me in the right direction to solving my typecasting problem. ;)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="116397">  <div class="votes">
    <div id="Vu116397">
    <a href="/manual/vote-note.php?id=116397&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd116397">
    <a href="/manual/vote-note.php?id=116397&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V116397" title="47% like this...">
    -1
    </div>
  </div>
  <a href="#116397" class="name">
  <strong class="user"><em>mbrowne83 (at GM)</em></strong></a><a class="genanchor" href="#116397"> &para;</a><div class="date" title="2014-12-27 01:15"><strong>5 years ago</strong></div>
  <div class="text" id="Hcom116397">
<div class="phpcode"><code><span class="html">
The code listed in some of the comments here for supposedly "casting" from one class to another using unserialize/serialize does not actually change the class of the existing object; it creates a new object. So it's not the same as a cast.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="115845">  <div class="votes">
    <div id="Vu115845">
    <a href="/manual/vote-note.php?id=115845&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd115845">
    <a href="/manual/vote-note.php?id=115845&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V115845" title="47% like this...">
    -1
    </div>
  </div>
  <a href="#115845" class="name">
  <strong class="user"><em>Eric Lavoie</em></strong></a><a class="genanchor" href="#115845"> &para;</a><div class="date" title="2014-10-02 09:24"><strong>5 years ago</strong></div>
  <div class="text" id="Hcom115845">
<div class="phpcode"><code><span class="html">
(array) null<br />array(null)<br /><br />are not the same.<br /><br />var_dump((array) null) =&gt; <br />array (size=0)<br />&nbsp; empty<br /><br />var_dump(array (null)) =&gt; <br />array (size=1)<br />&nbsp; 0 =&gt; null</span>
</code></div>
  </div>
 </div>
  <div class="note" id="83956">  <div class="votes">
    <div id="Vu83956">
    <a href="/manual/vote-note.php?id=83956&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd83956">
    <a href="/manual/vote-note.php?id=83956&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V83956" title="47% like this...">
    -1
    </div>
  </div>
  <a href="#83956" class="name">
  <strong class="user"><em>alexgr at gmail dot com</em></strong></a><a class="genanchor" href="#83956"> &para;</a><div class="date" title="2008-06-20 03:43"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom83956">
<div class="phpcode"><code><span class="html">
For a Cast to a User Defined Object you can define a cast method:<br /><br />class MyObject {<br />&nbsp; &nbsp; /**<br />&nbsp; &nbsp;&nbsp; * @param MyObject $object<br />&nbsp; &nbsp;&nbsp; * @return MyObject<br />&nbsp; &nbsp;&nbsp; */<br />&nbsp; &nbsp; static public function cast(MyObject $object) {<br />&nbsp; &nbsp; &nbsp; &nbsp; return $object;<br />&nbsp; &nbsp; }<br />}<br /><br />In your php page code you can:<br />$myObject = MyObject::cast($_SESSION["myObject"]);<br /><br />Then, PHP will validate the value and your IDE will help you.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="45062">  <div class="votes">
    <div id="Vu45062">
    <a href="/manual/vote-note.php?id=45062&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd45062">
    <a href="/manual/vote-note.php?id=45062&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V45062" title="48% like this...">
    -1
    </div>
  </div>
  <a href="#45062" class="name">
  <strong class="user"><em>tom5025_ at hotmail dot com</em></strong></a><a class="genanchor" href="#45062"> &para;</a><div class="date" title="2004-08-24 01:27"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom45062">
<div class="phpcode"><code><span class="html">
function strhex($string)<br />{<br />&nbsp;&nbsp; $hex="";<br />&nbsp;&nbsp; for ($i=0;$i&lt;strlen($string);$i++)<br />&nbsp; &nbsp; &nbsp;&nbsp; $hex.=dechex(ord($string[$i]));<br />&nbsp;&nbsp; return $hex;<br />}<br />function hexstr($hex)<br />{<br />&nbsp;&nbsp; $string="";<br />&nbsp;&nbsp; for ($i=0;$i&lt;strlen($hex)-1;$i+=2)<br />&nbsp; &nbsp; &nbsp;&nbsp; $string.=chr(hexdec($hex[$i].$hex[$i+1]));<br />&nbsp;&nbsp; return $string;<br />}<br /><br />to convert hex to str and vice versa</span>
</code></div>
  </div>
 </div>
  <div class="note" id="50791">  <div class="votes">
    <div id="Vu50791">
    <a href="/manual/vote-note.php?id=50791&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd50791">
    <a href="/manual/vote-note.php?id=50791&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V50791" title="47% like this...">
    -1
    </div>
  </div>
  <a href="#50791" class="name">
  <strong class="user"><em>toma at smartsemantics dot com</em></strong></a><a class="genanchor" href="#50791"> &para;</a><div class="date" title="2005-03-09 06:24"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom50791">
<div class="phpcode"><code><span class="html">
In my much of my coding I have found it necessary to type-cast between objects of different class types.<br /><br />More specifically, I often want to take information from a database, convert it into the class it was before it was inserted, then have the ability to call its class functions as well.<br /><br />The following code is much shorter than some of the previous examples and seems to suit my purposes.&nbsp; It also makes use of some regular expression matching rather than string position, replacing, etc.&nbsp; It takes an object ($obj) of any type and casts it to an new type ($class_type).&nbsp; Note that the new class type must exist:<br /><br />function ClassTypeCast(&amp;$obj,$class_type){<br />&nbsp; &nbsp; if(class_exists($class_type,true)){<br />&nbsp; &nbsp; &nbsp; &nbsp; $obj = unserialize(preg_replace"/^O:[0-9]+:\"[^\"]+\":/i", <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; "O:".strlen($class_type).":\"".$class_type."\":", serialize($obj)));<br />&nbsp; &nbsp; }<br />}</span>
</code></div>
  </div>
 </div>
  <div class="note" id="31781">  <div class="votes">
    <div id="Vu31781">
    <a href="/manual/vote-note.php?id=31781&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd31781">
    <a href="/manual/vote-note.php?id=31781&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V31781" title="45% like this...">
    -2
    </div>
  </div>
  <a href="#31781" class="name">
  <strong class="user"><em>post_at_henribeige_dot_de</em></strong></a><a class="genanchor" href="#31781"> &para;</a><div class="date" title="2003-05-03 09:37"><strong>16 years ago</strong></div>
  <div class="text" id="Hcom31781">
<div class="phpcode"><code><span class="html">
If you want to do not only typecasting between basic data types but between classes, try this function. It converts any class into another. All variables that equal name in both classes will be copied.<br /><br />function typecast($old_object, $new_classname) {<br />&nbsp; if(class_exists($new_classname)) {<br />&nbsp; &nbsp; $old_serialized_object = serialize($old_object);<br />&nbsp; &nbsp; $new_serialized_object = 'O:' . strlen($new_classname) . ':"' . $new_classname . '":' . <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; substr($old_serialized_object, $old_serialized_object[2] + 7);<br />&nbsp; &nbsp; return unserialize($new_serialized_object);<br />&nbsp; }<br />&nbsp; else<br />&nbsp; &nbsp; return false;<br />}<br /><br />Example:<br /><br />class A {<br />&nbsp; var $secret;<br />&nbsp; function A($secret) {$this-&gt;secret = $secret;}<br />&nbsp; function output() {echo("Secret class A: " . $this-&gt;secret);}<br />}<br /><br />class B extends A {<br />&nbsp; var $secret;<br />&nbsp; function output() {echo("Secret class B: " . strrev($this-&gt;secret));}<br />}<br /><br />$a = new A("Paranoia");<br />$b = typecast($a, "B");<br /><br />$a-&gt;output();<br />$b-&gt;output();<br />echo("Classname \$a: " . get_class($a) . "Classname \$b: " . get_class($b));<br /><br />Output of the example code above:<br /><br />Secret class A: Paranoia<br />Secret class B: aionaraP<br />Classname $a: a<br />Classname $b: b</span>
</code></div>
  </div>
 </div>
  <div class="note" id="85906">  <div class="votes">
    <div id="Vu85906">
    <a href="/manual/vote-note.php?id=85906&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd85906">
    <a href="/manual/vote-note.php?id=85906&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V85906" title="44% like this...">
    -2
    </div>
  </div>
  <a href="#85906" class="name">
  <strong class="user"><em>lucazd at gmail dot com</em></strong></a><a class="genanchor" href="#85906"> &para;</a><div class="date" title="2008-09-23 09:20"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom85906">
<div class="phpcode"><code><span class="html">
@alexgr (20-Jun-2008)<br /><br />Correct me if I'm wrong, but that is not a cast, it might be useful sometimes, but the IDE will not reflect what's really happening:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">MyObject </span><span class="keyword">{<br />&nbsp; &nbsp; </span><span class="comment">/**<br />&nbsp; &nbsp;&nbsp; * @param MyObject $object<br />&nbsp; &nbsp;&nbsp; * @return MyObject<br />&nbsp; &nbsp;&nbsp; */<br />&nbsp; &nbsp; </span><span class="keyword">static public function </span><span class="default">cast</span><span class="keyword">(</span><span class="default">MyObject $object</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$object</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; </span><span class="comment">/** Does nothing */<br />&nbsp; &nbsp; </span><span class="keyword">function </span><span class="default">f</span><span class="keyword">() {}<br />}<br /><br />class </span><span class="default">X </span><span class="keyword">extends </span><span class="default">MyObject </span><span class="keyword">{<br />&nbsp; &nbsp; </span><span class="comment">/** Throws exception */<br />&nbsp; &nbsp; </span><span class="keyword">function </span><span class="default">f</span><span class="keyword">() { throw new </span><span class="default">exception</span><span class="keyword">(); }<br />}<br /><br /></span><span class="default">$x </span><span class="keyword">= </span><span class="default">MyObject</span><span class="keyword">::</span><span class="default">cast</span><span class="keyword">(new </span><span class="default">X</span><span class="keyword">);<br /></span><span class="default">$x</span><span class="keyword">-&gt;</span><span class="default">f</span><span class="keyword">(); </span><span class="comment">// Your IDE tells 'f() Does nothing'<br /></span><span class="default">?&gt;<br /></span><br />However, when you run the script, you will get an exception.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="40639">  <div class="votes">
    <div id="Vu40639">
    <a href="/manual/vote-note.php?id=40639&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd40639">
    <a href="/manual/vote-note.php?id=40639&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V40639" title="42% like this...">
    -3
    </div>
  </div>
  <a href="#40639" class="name">
  <strong class="user"><em>dimo dot vanchev at bianor dot com</em></strong></a><a class="genanchor" href="#40639"> &para;</a><div class="date" title="2004-03-10 07:02"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom40639">
<div class="phpcode"><code><span class="html">
For some reason the code-fix posted by philip_snyder at hotmail dot com [27-Feb-2004 02:08]<br />didn't work for me neither with long_class_names nor with short_class_names. I'm using PHP v4.3.5 for Linux.<br />Anyway here's what I wrote to solve the long_named_classes problem:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">typecast</span><span class="keyword">(</span><span class="default">$old_object</span><span class="keyword">, </span><span class="default">$new_classname</span><span class="keyword">) {<br />&nbsp; &nbsp; if(</span><span class="default">class_exists</span><span class="keyword">(</span><span class="default">$new_classname</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$old_serialized_object </span><span class="keyword">= </span><span class="default">serialize</span><span class="keyword">(</span><span class="default">$old_object</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$old_object_name_length </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">get_class</span><span class="keyword">(</span><span class="default">$old_object</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$subtring_offset </span><span class="keyword">= </span><span class="default">$old_object_name_length </span><span class="keyword">+ </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$old_object_name_length</span><span class="keyword">) + </span><span class="default">6</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$new_serialized_object&nbsp; </span><span class="keyword">= </span><span class="string">'O:' </span><span class="keyword">. </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$new_classname</span><span class="keyword">) . </span><span class="string">':"' </span><span class="keyword">. </span><span class="default">$new_classname </span><span class="keyword">. </span><span class="string">'":'</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$new_serialized_object </span><span class="keyword">.= </span><span class="default">substr</span><span class="keyword">(</span><span class="default">$old_serialized_object</span><span class="keyword">, </span><span class="default">$subtring_offset</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">unserialize</span><span class="keyword">(</span><span class="default">$new_serialized_object</span><span class="keyword">);<br />&nbsp; &nbsp;&nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; return </span><span class="default">false</span><span class="keyword">;<br />&nbsp; &nbsp;&nbsp; }<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="117994">  <div class="votes">
    <div id="Vu117994">
    <a href="/manual/vote-note.php?id=117994&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd117994">
    <a href="/manual/vote-note.php?id=117994&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V117994" title="40% like this...">
    -3
    </div>
  </div>
  <a href="#117994" class="name">
  <strong class="user"><em>berniev</em></strong></a><a class="genanchor" href="#117994"> &para;</a><div class="date" title="2015-09-15 11:23"><strong>4 years ago</strong></div>
  <div class="text" id="Hcom117994">
<div class="phpcode"><code><span class="html">
May be expected, but not stated ..<br />Casting to the existing (same) type has no effect.<br />$t = 'abc';&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // string 'abc'<br />$u=(array) $t;&nbsp;&nbsp; // array 0 =&gt; string 'abc'&nbsp; &lt;-- now an array<br />$v=(array) $u;&nbsp; // array 0 =&gt; string 'abc'&nbsp; &lt;-- unchanged</span>
</code></div>
  </div>
 </div>
  <div class="note" id="117391">  <div class="votes">
    <div id="Vu117391">
    <a href="/manual/vote-note.php?id=117391&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd117391">
    <a href="/manual/vote-note.php?id=117391&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V117391" title="38% like this...">
    -3
    </div>
  </div>
  <a href="#117391" class="name">
  <strong class="user"><em>davaakhuu at outlook dot com</em></strong></a><a class="genanchor" href="#117391"> &para;</a><div class="date" title="2015-06-03 07:29"><strong>4 years ago</strong></div>
  <div class="text" id="Hcom117391">
<div class="phpcode"><code><span class="html">
Type Juggling&lt;br/&gt;<br />&nbsp;&nbsp; <span class="default">&lt;?php $count </span><span class="keyword">= </span><span class="string">"2 cats"</span><span class="keyword">; </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; Type: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$count</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt;<br />&nbsp;&nbsp; <span class="default">&lt;?php $count </span><span class="keyword">+= </span><span class="default">3</span><span class="keyword">; </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; Type: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$count</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt; <br />&nbsp;&nbsp; <span class="default">&lt;?php $cats </span><span class="keyword">= </span><span class="string">"I have " </span><span class="keyword">. </span><span class="default">$count </span><span class="keyword">. </span><span class="string">"cats."</span><span class="keyword">; </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; Cats: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$cats</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt;<br />&nbsp;&nbsp; &lt;br/&gt;<br />&nbsp;&nbsp; Type Casting&lt;br/&gt;<br />&nbsp;&nbsp; <span class="default">&lt;?php settype</span><span class="keyword">(</span><span class="default">$count</span><span class="keyword">, </span><span class="string">"integer"</span><span class="keyword">); </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; count: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$count</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt;<br /><br />&nbsp;&nbsp; <span class="default">&lt;?php $count2 </span><span class="keyword">= (string)</span><span class="default">$count</span><span class="keyword">; </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; count: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$count</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt;<br />&nbsp;&nbsp; count2: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$count2</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt;<br /><br />&nbsp;&nbsp; <span class="default">&lt;?php $test1 </span><span class="keyword">= </span><span class="default">3</span><span class="keyword">; </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; <span class="default">&lt;?php $test2 </span><span class="keyword">= </span><span class="default">3</span><span class="keyword">; </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; <span class="default">&lt;?php settype</span><span class="keyword">(</span><span class="default">$test1</span><span class="keyword">, </span><span class="string">"string"</span><span class="keyword">); </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; <span class="default">&lt;?php </span><span class="keyword">(string)</span><span class="default">$test2</span><span class="keyword">; </span><span class="default">?&gt;<br /></span>&nbsp;&nbsp; test1: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$test1</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt;<br />&nbsp;&nbsp; test2: <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$test2</span><span class="keyword">); </span><span class="default">?&gt;</span>&lt;br/&gt;</span>
</code></div>
  </div>
 </div>
  <div class="note" id="85627">  <div class="votes">
    <div id="Vu85627">
    <a href="/manual/vote-note.php?id=85627&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd85627">
    <a href="/manual/vote-note.php?id=85627&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V85627" title="37% like this...">
    -6
    </div>
  </div>
  <a href="#85627" class="name">
  <strong class="user"><em>nullhilty at gmail dot com</em></strong></a><a class="genanchor" href="#85627"> &para;</a><div class="date" title="2008-09-09 11:34"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom85627">
<div class="phpcode"><code><span class="html">
Just a little experiment on the (unset) type cast:<br /><br /><span class="default">&lt;?php<br />$var </span><span class="keyword">= </span><span class="default">1</span><span class="keyword">;<br /></span><span class="default">$var_unset </span><span class="keyword">= (unset) </span><span class="default">$var</span><span class="keyword">;<br /></span><span class="default">$var_ref_unset </span><span class="keyword">&amp;= (unset) </span><span class="default">$var</span><span class="keyword">;<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$var_unset</span><span class="keyword">);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$var_ref_unset</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />output:<br />int(1)<br />NULL<br />int(0)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="87399">  <div class="votes">
    <div id="Vu87399">
    <a href="/manual/vote-note.php?id=87399&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd87399">
    <a href="/manual/vote-note.php?id=87399&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V87399" title="26% like this...">
    -7
    </div>
  </div>
  <a href="#87399" class="name">
  <strong class="user"><em>kajsunansis at that gmail</em></strong></a><a class="genanchor" href="#87399"> &para;</a><div class="date" title="2008-12-03 11:18"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom87399">
<div class="phpcode"><code><span class="html">
json_decode users consider this, when casting stdClass to array:<br /><span class="default">&lt;?php<br />$obj </span><span class="keyword">= new </span><span class="default">stdClass</span><span class="keyword">();<br /></span><span class="default">$obj</span><span class="keyword">-&gt;{</span><span class="string">"2"</span><span class="keyword">} = </span><span class="string">"id"</span><span class="keyword">;<br /></span><span class="default">$arr </span><span class="keyword">= (array) </span><span class="default">$obj</span><span class="keyword">;<br /></span><span class="default">$result </span><span class="keyword">= isset(</span><span class="default">$arr</span><span class="keyword">[</span><span class="string">"2"</span><span class="keyword">]) || </span><span class="default">array_key_exists</span><span class="keyword">(</span><span class="default">2</span><span class="keyword">, </span><span class="default">$arr</span><span class="keyword">); </span><span class="comment">// false<br /></span><span class="default">?&gt;<br /></span>..though casting is at least 2x faster than foreach.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="86896">  <div class="votes">
    <div id="Vu86896">
    <a href="/manual/vote-note.php?id=86896&amp;page=language.types.type-juggling&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd86896">
    <a href="/manual/vote-note.php?id=86896&amp;page=language.types.type-juggling&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V86896" title="29% like this...">
    -14
    </div>
  </div>
  <a href="#86896" class="name">
  <strong class="user"><em>Jeffrey</em></strong></a><a class="genanchor" href="#86896"> &para;</a><div class="date" title="2008-11-09 11:34"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom86896">
<div class="phpcode"><code><span class="html">
IMAGINATION REQUIRED...<br /><br />We can be a witness to PHP's 'type-jugglin' in real-time with a simple implementation of a MemoryMap. For the sake our purposes, pretend that this is an empty MemoryMap.<br />+-------+------+------+-------+<br />| index | $var | type | value |<br />+-------+------+------+-------+<br />|&nbsp; &nbsp;&nbsp; 1 |&nbsp; --- | NULL |&nbsp; null |<br />|&nbsp; &nbsp;&nbsp; 2 |&nbsp; --- | NULL |&nbsp; null |<br />|&nbsp; &nbsp;&nbsp; 3 |&nbsp; --- | NULL |&nbsp; null |<br />|&nbsp; &nbsp;&nbsp; 4 |&nbsp; --- | NULL |&nbsp; null |<br />+-------+------+------+-------+<br /><br /><span class="default">&lt;?php<br /></span><span class="comment"># create some variables...<br /></span><span class="default">$a </span><span class="keyword">= </span><span class="default">10</span><span class="keyword">;<br /></span><span class="default">$b </span><span class="keyword">= </span><span class="string">"Hello"</span><span class="keyword">;<br /></span><span class="default">$c </span><span class="keyword">= array(</span><span class="default">55.45</span><span class="keyword">, </span><span class="default">98.65</span><span class="keyword">);<br /></span><span class="comment"># Now look at map...<br /></span><span class="default">?&gt;<br /></span>+-------+-------+---------+--------+<br />| index |&nbsp; $var |&nbsp; &nbsp; type |&nbsp; value |<br />+-------+-------+---------+--------+<br />|&nbsp; &nbsp;&nbsp; 1 |&nbsp; &nbsp; $a | INTEGER |&nbsp; &nbsp;&nbsp; 10 |<br />|&nbsp; &nbsp;&nbsp; 2 |&nbsp; &nbsp; $b |&nbsp; STRING |&nbsp; Hello |<br />|&nbsp; &nbsp;&nbsp; 3 | $c[0] |&nbsp;&nbsp; FLOAT |&nbsp; 55.45 |<br />|&nbsp; &nbsp;&nbsp; 4 | $c[1] |&nbsp;&nbsp; FLOAT |&nbsp; 98.65 |<br />+-------+-------+---------+--------+<br /><span class="default">&lt;?php<br /></span><span class="comment"># Now, change the variable types...<br /></span><span class="default">$a </span><span class="keyword">= </span><span class="string">"Bye"</span><span class="keyword">;<br /></span><span class="default">$b </span><span class="keyword">= </span><span class="default">2</span><span class="keyword">;<br /></span><span class="default">$c</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">] = </span><span class="string">"Buy"</span><span class="keyword">;<br /></span><span class="default">$c</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">] = </span><span class="string">"Now!"</span><span class="keyword">;<br /></span><span class="comment">#Look at map...<br /></span><span class="default">?&gt;<br /></span>+-------+-------+---------+--------+<br />| index |&nbsp; $var |&nbsp; &nbsp; type |&nbsp; value |<br />+-------+-------+---------+--------+<br />|&nbsp; &nbsp;&nbsp; 1 |&nbsp; &nbsp; $a |&nbsp; STRING |&nbsp; &nbsp; Bye | &lt;- used to be INTEGER<br />|&nbsp; &nbsp;&nbsp; 2 |&nbsp; &nbsp; $b | INTEGER |&nbsp; &nbsp; &nbsp; 2 | &lt;- used to be STRING<br />|&nbsp; &nbsp;&nbsp; 3 | $c[0] |&nbsp; STRING |&nbsp; &nbsp; Buy | &lt;- used to be FLOAT<br />|&nbsp; &nbsp;&nbsp; 4 | $c[1] |&nbsp; STRING |&nbsp; Right | &lt;- used to be FLOAT<br />+-------+-------+---------+--------+</span>
</code></div>
  </div>
 </div></div>

 <div class="foot"><a href="/manual/add-note.php?sect=language.types.type-juggling&amp;redirect=https://www.php.net/manual/pt_BR/language.types.type-juggling.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></div>
</section>    </section><!-- layout-content -->
        <aside class='layout-menu'>

        <ul class='parent-menu-list'>
                                    <li>
                <a href="language.types.php">Tipos</a>

                                    <ul class='child-menu-list'>

                                                <li class="">
                            <a href="language.types.intro.php" title="Introdu&ccedil;&atilde;o">Introdu&ccedil;&atilde;o</a>
                        </li>
                                                <li class="">
                            <a href="language.types.boolean.php" title="Booleanos">Booleanos</a>
                        </li>
                                                <li class="">
                            <a href="language.types.integer.php" title="Inteiros">Inteiros</a>
                        </li>
                                                <li class="">
                            <a href="language.types.float.php" title="N&uacute;meros de ponto flutuante">N&uacute;meros de ponto flutuante</a>
                        </li>
                                                <li class="">
                            <a href="language.types.string.php" title="Strings">Strings</a>
                        </li>
                                                <li class="">
                            <a href="language.types.array.php" title="Arrays">Arrays</a>
                        </li>
                                                <li class="">
                            <a href="language.types.iterable.php" title="Iterables">Iterables</a>
                        </li>
                                                <li class="">
                            <a href="language.types.object.php" title="Objetos">Objetos</a>
                        </li>
                                                <li class="">
                            <a href="language.types.resource.php" title="Recursos">Recursos</a>
                        </li>
                                                <li class="">
                            <a href="language.types.null.php" title="NULL">NULL</a>
                        </li>
                                                <li class="">
                            <a href="language.types.callable.php" title="Callbacks / Callables">Callbacks / Callables</a>
                        </li>
                                                <li class="">
                            <a href="language.pseudo-types.php" title="Pseudo-&#8203;tipos e vari&aacute;veis utilizadas nesta documenta&ccedil;&atilde;o">Pseudo-&#8203;tipos e vari&aacute;veis utilizadas nesta documenta&ccedil;&atilde;o</a>
                        </li>
                                                <li class="current">
                            <a href="language.types.type-juggling.php" title="Manipula&ccedil;&atilde;o de tipos">Manipula&ccedil;&atilde;o de tipos</a>
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
