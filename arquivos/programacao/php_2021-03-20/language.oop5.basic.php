<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="pt_BR">
<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: O b&aacute;sico - Manual </title>

 <link rel="shortcut icon" href="https://www.php.net/favicon.ico">
 <link rel="search" type="application/opensearchdescription+xml" href="http://php.net/phpnetimprovedsearch.src" title="Add PHP.net search">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/releases/feed.php" title="PHP Release feed">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/feed.atom" title="PHP: Hypertext Preprocessor">

 <link rel="canonical" href="https://www.php.net/manual/pt_BR/language.oop5.basic.php">
 <link rel="shorturl" href="https://www.php.net/oop5.basic">
 <link rel="alternate" href="https://www.php.net/oop5.basic" hreflang="x-default">

 <link rel="contents" href="https://www.php.net/manual/pt_BR/index.php">
 <link rel="index" href="https://www.php.net/manual/pt_BR/language.oop5.php">
 <link rel="prev" href="https://www.php.net/manual/pt_BR/oop5.intro.php">
 <link rel="next" href="https://www.php.net/manual/pt_BR/language.oop5.properties.php">

 <link rel="alternate" href="https://www.php.net/manual/en/language.oop5.basic.php" hreflang="en">
 <link rel="alternate" href="https://www.php.net/manual/pt_BR/language.oop5.basic.php" hreflang="pt_BR">
 <link rel="alternate" href="https://www.php.net/manual/zh/language.oop5.basic.php" hreflang="zh">
 <link rel="alternate" href="https://www.php.net/manual/fr/language.oop5.basic.php" hreflang="fr">
 <link rel="alternate" href="https://www.php.net/manual/de/language.oop5.basic.php" hreflang="de">
 <link rel="alternate" href="https://www.php.net/manual/ja/language.oop5.basic.php" hreflang="ja">
 <link rel="alternate" href="https://www.php.net/manual/ro/language.oop5.basic.php" hreflang="ro">
 <link rel="alternate" href="https://www.php.net/manual/ru/language.oop5.basic.php" hreflang="ru">
 <link rel="alternate" href="https://www.php.net/manual/es/language.oop5.basic.php" hreflang="es">
 <link rel="alternate" href="https://www.php.net/manual/tr/language.oop5.basic.php" hreflang="tr">

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

 <base href="https://www.php.net/manual/pt_BR/language.oop5.basic.php">

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
        <a href="language.oop5.properties.php">
          Propriedades &raquo;
        </a>
      </div>
              <div class="prev">
        <a href="oop5.intro.php">
          &laquo; Introdu&ccedil;&atilde;o        </a>
      </div>
          <ul>
            <li><a href='index.php'>Manual do PHP</a></li>      <li><a href='langref.php'>Refer&ecirc;ncia da Linguagem</a></li>      <li><a href='language.oop5.php'>Classes e Objetos</a></li>      </ul>
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
            <option value='en/language.oop5.basic.php'>English</option>
            <option value='pt_BR/language.oop5.basic.php' selected="selected">Brazilian Portuguese</option>
            <option value='zh/language.oop5.basic.php'>Chinese (Simplified)</option>
            <option value='fr/language.oop5.basic.php'>French</option>
            <option value='de/language.oop5.basic.php'>German</option>
            <option value='ja/language.oop5.basic.php'>Japanese</option>
            <option value='ro/language.oop5.basic.php'>Romanian</option>
            <option value='ru/language.oop5.basic.php'>Russian</option>
            <option value='es/language.oop5.basic.php'>Spanish</option>
            <option value='tr/language.oop5.basic.php'>Turkish</option>
            <option value="help-translate.php">Other</option>
          </select>
        </fieldset>
      </form>
    </div>
    <div class="edit-bug">
      <a href="https://edit.php.net/?project=PHP&amp;perm=pt_BR/language.oop5.basic.php">Edit</a>
      <a href="https://bugs.php.net/report.php?bug_type=Documentation+problem&amp;manpage=language.oop5.basic">Report a Bug</a>
    </div>
  </div><div id="language.oop5.basic" class="sect1">
  <h2 class="title">O básico</h2>

  <div class="sect2" id="language.oop5.basic.class">
   <h3 class="title">class</h3>
   <p class="para">
    A definição de uma classe começa com a
    palavra chave <em>class</em>, seguida do nome da classe,
    seguido de um par de colchetes que englobam as definições
    de propriedades e métodos pertecentes à classe.
   </p>
   <p class="para">
    O nome de uma classe tem de ser válido, que não seja
    uma <a href="reserved.php" class="link">palavra reservada do PHP</a>. Um nome de classe válido
    começa com uma letra ou sublinhado, seguido de qualquer sequência de
    letras, números e sublinhados. Como uma expressão regular,
    pode ser expressada assim:
    <em>^[a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*$</em>.
   </p>
   <p class="para">
    Uma classe pode conter suas
    próprias <a href="language.oop5.constants.php" class="link">constantes</a>, <a href="language.oop5.properties.php" class="link">variáveis</a>
    (chamadas de &quot;propriedades&quot;) e funções (chamadas de &quot;métodos&quot;).
   </p>
   <div class="example" id="example-190">
    <p><strong>Exemplo #1 Definição Simples de uma Classe</strong></p>
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br /></span><span style="color: #007700">class&nbsp;</span><span style="color: #0000BB">SimpleClass<br /></span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;declaração&nbsp;de&nbsp;propriedade<br />&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #007700">public&nbsp;</span><span style="color: #0000BB">$var&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'um&nbsp;valor&nbsp;padrão'</span><span style="color: #007700">;<br /><br />&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;declaração&nbsp;de&nbsp;método<br />&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #007700">public&nbsp;function&nbsp;</span><span style="color: #0000BB">displayVar</span><span style="color: #007700">()&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #0000BB">$this</span><span style="color: #007700">-&gt;</span><span style="color: #0000BB">var</span><span style="color: #007700">;<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
    </div>

   </div>
   <p class="para">
    A pseudo-variável <var class="varname"><var class="varname">$this</var></var> está disponível quando um
    método é chamado a partir de um contexto de
    objeto. <var class="varname"><var class="varname">$this</var></var> é uma referência ao objeto
    chamado (normalmente o objeto ao qual o método pertence, mas
    possivelmente outro objeto, se o método é chamado
    <a href="language.oop5.static.php" class="link">estaticamente</a> a partir do contexto
    de um objeto secundário).
   </p>
   <p class="para">
    <div class="example" id="example-191">
     <p><strong>Exemplo #2 Alguns exemplos da pseudo variável <var class="varname"><var class="varname">$this</var></var></strong></p>
     <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br /></span><span style="color: #007700">class&nbsp;</span><span style="color: #0000BB">A<br /></span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;function&nbsp;</span><span style="color: #0000BB">foo</span><span style="color: #007700">()<br />&nbsp;&nbsp;&nbsp;&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if&nbsp;(isset(</span><span style="color: #0000BB">$this</span><span style="color: #007700">))&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #DD0000">'$this&nbsp;está&nbsp;definida&nbsp;('</span><span style="color: #007700">;<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #0000BB">get_class</span><span style="color: #007700">(</span><span style="color: #0000BB">$this</span><span style="color: #007700">);<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #DD0000">")\n"</span><span style="color: #007700">;<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;else&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #DD0000">"\$this&nbsp;não&nbsp;está&nbsp;definida.\n"</span><span style="color: #007700">;<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /><br />class&nbsp;</span><span style="color: #0000BB">B<br /></span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;function&nbsp;</span><span style="color: #0000BB">bar</span><span style="color: #007700">()<br />&nbsp;&nbsp;&nbsp;&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;Nota:&nbsp;a&nbsp;próxima&nbsp;linha&nbsp;pode&nbsp;lançar&nbsp;um&nbsp;warning&nbsp;E_STRICT.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #0000BB">A</span><span style="color: #007700">::</span><span style="color: #0000BB">foo</span><span style="color: #007700">();<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /><br /></span><span style="color: #0000BB">$a&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">A</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">$a</span><span style="color: #007700">-&gt;</span><span style="color: #0000BB">foo</span><span style="color: #007700">();<br /><br /></span><span style="color: #FF8000">//&nbsp;Nota:&nbsp;a&nbsp;próxima&nbsp;linha&nbsp;pode&nbsp;lançar&nbsp;um&nbsp;warning&nbsp;E_STRICT.<br /></span><span style="color: #0000BB">A</span><span style="color: #007700">::</span><span style="color: #0000BB">foo</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">$b&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">B</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">$b</span><span style="color: #007700">-&gt;</span><span style="color: #0000BB">bar</span><span style="color: #007700">();<br /><br /></span><span style="color: #FF8000">//&nbsp;Nota:&nbsp;a&nbsp;próxima&nbsp;linha&nbsp;pode&nbsp;lançar&nbsp;um&nbsp;warning&nbsp;E_STRICT.<br /></span><span style="color: #0000BB">B</span><span style="color: #007700">::</span><span style="color: #0000BB">bar</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
     </div>

     <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
     <div class="example-contents screen">
<div class="cdata"><pre>
$this está definida (A)
$this não está definida.
$this está definida (B)
$this não está definida.
</pre></div>
     </div>
    </div>
   </p>
  </div>

  <div class="sect2" id="language.oop5.basic.new">
   <h3 class="title">new</h3>
   <p class="para">
    Para criar uma instância de uma classe, a instrução <em>new</em> deve
    ser utilizada. Um objeto sempre será criado a não ser que a classe tenha um
    <a href="language.oop5.decon.php" class="link">construtor</a> definido que dispare uma
    <a href="language.exceptions.php" class="link">exceção</a> em caso de erro. Classes
    devem ser definidas antes de instanciadas (e em alguns casos isso é
    obrigatório).
   </p>
   <p class="para">
    Se uma <span class="type"><a href="language.types.string.php" class="type string">string</a></span> contendo o nome da classe é utilizado com
    <em>new</em>, uma nova instância da classe será criada. Se
    a classe estiver dentro de um namespace, o nome completo e qualificado deve ser utilizado
    para fazer isso.
   </p>
   <div class="example" id="example-192">
    <p><strong>Exemplo #3 Criando uma instância</strong></p>
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$instance&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">SimpleClass</span><span style="color: #007700">();<br /><br /></span><span style="color: #FF8000">//&nbsp;Também&nbsp;pode&nbsp;ser&nbsp;feito&nbsp;com&nbsp;uma&nbsp;variável:<br /></span><span style="color: #0000BB">$className&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'SimpleClass'</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$instance&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">$className</span><span style="color: #007700">();&nbsp;</span><span style="color: #FF8000">//&nbsp;new&nbsp;SimpleClass()<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
    </div>

   </div>
   <p class="para">
    No contexto da classe, é possível criar um novo objeto com
    <em>new self</em> e <em>new parent</em>.
   </p>
   <p class="para">
    Ao atribuir uma instância de uma classe já criada, a uma variável nova,
    a variável nova irá acessar a mesma instância do objeto que foi atribuído. Este
    comportamento se mantém ao se passar instâncias a uma função. Uma cópia
    de um objeto criado pode ser feita
    <a href="language.oop5.cloning.php" class="link">clonando</a> o mesmo.
   </p>
   <div class="example" id="example-193">
    <p><strong>Exemplo #4 Atribuição de Objetos</strong></p>
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br /><br />$instance&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">SimpleClass</span><span style="color: #007700">();<br /><br /></span><span style="color: #0000BB">$assigned&nbsp;&nbsp;&nbsp;</span><span style="color: #007700">=&nbsp;&nbsp;</span><span style="color: #0000BB">$instance</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$reference&nbsp;&nbsp;</span><span style="color: #007700">=&amp;&nbsp;</span><span style="color: #0000BB">$instance</span><span style="color: #007700">;<br /><br /></span><span style="color: #0000BB">$instance</span><span style="color: #007700">-&gt;</span><span style="color: #0000BB">var&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'$assigned&nbsp;terá&nbsp;esse&nbsp;valor'</span><span style="color: #007700">;<br /><br /></span><span style="color: #0000BB">$instance&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">null</span><span style="color: #007700">;&nbsp;</span><span style="color: #FF8000">//&nbsp;$instance&nbsp;e&nbsp;$reference&nbsp;tornam-se&nbsp;nulos<br /><br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(</span><span style="color: #0000BB">$instance</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(</span><span style="color: #0000BB">$reference</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(</span><span style="color: #0000BB">$assigned</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
    </div>

    <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
    <div class="example-contents screen">
<div class="cdata"><pre>
NULL
NULL
object(SimpleClass)#1 (1) {
   [&quot;var&quot;]=&gt;
     string(30) &quot;$assigned terá esse valor&quot;
}
</pre></div>
    </div>
   </div>
   <p class="para">
    O PHP 5.3.0 introduziu algumas novas formas de criar instâncias de
    um objeto:
   </p>
   <div class="example" id="example-194">
    <p><strong>Exemplo #5 Criando novos objetos</strong></p>
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br /></span><span style="color: #007700">class&nbsp;</span><span style="color: #0000BB">Test<br /></span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;static&nbsp;public&nbsp;function&nbsp;</span><span style="color: #0000BB">getNew</span><span style="color: #007700">()<br />&nbsp;&nbsp;&nbsp;&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return&nbsp;new&nbsp;static;<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /><br />class&nbsp;</span><span style="color: #0000BB">Child&nbsp;</span><span style="color: #007700">extends&nbsp;</span><span style="color: #0000BB">Test<br /></span><span style="color: #007700">{}<br /><br /></span><span style="color: #0000BB">$obj1&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">Test</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">$obj2&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">$obj1</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(</span><span style="color: #0000BB">$obj1&nbsp;</span><span style="color: #007700">!==&nbsp;</span><span style="color: #0000BB">$obj2</span><span style="color: #007700">);<br /><br /></span><span style="color: #0000BB">$obj3&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">Test</span><span style="color: #007700">::</span><span style="color: #0000BB">getNew</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(</span><span style="color: #0000BB">$obj3&nbsp;</span><span style="color: #007700">instanceof&nbsp;</span><span style="color: #0000BB">Test</span><span style="color: #007700">);<br /><br /></span><span style="color: #0000BB">$obj4&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">Child</span><span style="color: #007700">::</span><span style="color: #0000BB">getNew</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(</span><span style="color: #0000BB">$obj4&nbsp;</span><span style="color: #007700">instanceof&nbsp;</span><span style="color: #0000BB">Child</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
    </div>

    <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
    <div class="example-contents screen">
<div class="cdata"><pre>
bool(true)
bool(true)
bool(true)
</pre></div>
    </div>
   </div>
  </div>

  <div class="sect2" id="language.oop5.basic.properties-methods">
   <h3 class="title">Propriedades e métodos</h3>
   <p class="para">
    Propriedades e métodos de classe vivem em &quot;namespaces&quot; separados, de forma que é
    possível ter uma propriedade e método com mesmos nomes. A referência a
    propriedades e métodos tem a mesma notação, e a decisão de se uma propriedade será acessada
    ou uma chamada a um método feita, depende somente do contexto,
    ou seja, se está tentando acessar uma variável ou chamar um método.
   </p>
   <div class="example" id="example-195">
    <p><strong>Exemplo #6 Acesso a propriedade vs. chamar um método</strong></p>
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
class&nbsp;Foo<br />{<br />&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;$bar&nbsp;=&nbsp;'propriedade';<br /><br />&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;function&nbsp;bar()&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return&nbsp;'métod';<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /><br />$obj&nbsp;=&nbsp;new&nbsp;Foo();<br />echo&nbsp;$obj-&gt;bar,&nbsp;PHP_EOL,&nbsp;$obj-&gt;bar(),&nbsp;PHP_EOL;</span>
</code></div>
    </div>

    <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
    <div class="example-contents screen">
<div class="cdata"><pre>
propriedade
método
</pre></div>
    </div>
   </div>
   <p class="para">
    Isto significa que chamar diretamente uma <a href="functions.anonymous.php" class="link">função
    anônima</a> atribuída a uma propriedade não é possível.
    Em vez disso, por exemplo, a propriedade deve primeiro ser atribuída a uma
    variável. A partir do PHP 7.0.0, é possível chamar uma propriedade diretamente
    a colocando entre parênteses.
   </p>
   <div class="example" id="example-196">
    <p><strong>Exemplo #7 Chamando uma função anônima armazenada em uma propriedade</strong></p>
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
class&nbsp;Foo<br />{<br />&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;$bar;<br /><br />&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;function&nbsp;__construct()&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$this-&gt;bar&nbsp;=&nbsp;function()&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return&nbsp;42;<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;};<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /><br />$obj&nbsp;=&nbsp;new&nbsp;Foo();<br /><br />//&nbsp;a&nbsp;partir&nbsp;do&nbsp;PHP&nbsp;5.3.0:<br />$func&nbsp;=&nbsp;$obj-&gt;bar;<br />echo&nbsp;$func(),&nbsp;PHP_EOL;<br /><br />//&nbsp;alternativamente,&nbsp;a&nbsp;partir&nbsp;do&nbsp;PHP&nbsp;7.0.0:<br />echo&nbsp;($obj-&gt;bar)(),&nbsp;PHP_EOL;</span>
</code></div>
    </div>

    <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
    <div class="example-contents screen">
<div class="cdata"><pre>
42
</pre></div>
    </div>
   </div>
  </div>

  <div class="sect2" id="language.oop5.basic.extends">
   <h3 class="title">extends</h3>
   <p class="para">
    Uma classe pode herdar métodos e propriedades de outra classe usando a
    palavra-chave <em>extends</em> na declaração
    da classe. Não é possível herdar múltiplas classes; uma
    classe só pode herdar uma classe base.
   </p>
   <p class="para">
    Os métodos e propriedades herdados podem ser sobrescritos
    redeclarando-os com o mesmo nome definido na classe
    base. Entretanto, se o método foi definido na classe base
    como <a href="language.oop5.final.php" class="link">final</a> esse método
    não poderá ser sobrescrito. É possível acessar os métodos sobrescritos
    ou propriedades estáticas referenciado-os
    com <a href="language.oop5.paamayim-nekudotayim.php" class="link">parent::</a>.
  </p>
   <p class="para">
    Ao sobrescrever métodos, a assinatura de parâmetros deve permanecer a mesma ou
    o PHP gerará um erro de nível <strong><code>E_STRICT</code></strong>. Isto não se
    aplica ao construtor, que permite a sobrescrita com parâmetros
    diferentes.
   </p>
   <div class="example" id="example-197">
    <p><strong>Exemplo #8 Herança da Classe Simples</strong></p>
    <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br /></span><span style="color: #007700">class&nbsp;</span><span style="color: #0000BB">ExtendClass&nbsp;</span><span style="color: #007700">extends&nbsp;</span><span style="color: #0000BB">SimpleClass<br /></span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;Redefine&nbsp;o&nbsp;método&nbsp;pai<br />&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #007700">function&nbsp;</span><span style="color: #0000BB">displayVar</span><span style="color: #007700">()<br />&nbsp;&nbsp;&nbsp;&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #DD0000">"Classe&nbsp;Herdeira\n"</span><span style="color: #007700">;<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #0000BB">parent</span><span style="color: #007700">::</span><span style="color: #0000BB">displayVar</span><span style="color: #007700">();<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /><br /></span><span style="color: #0000BB">$extended&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">ExtendClass</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">$extended</span><span style="color: #007700">-&gt;</span><span style="color: #0000BB">displayVar</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
    </div>

    <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
    <div class="example-contents screen">
<div class="cdata"><pre>
Classe Herdeira
um valor padrão
</pre></div>
    </div>
   </div>
  </div>

  <div class="sect2" id="language.oop5.basic.class.class">
   <h3 class="title">::class</h3>

   <p class="para">
    Desde o PHP 5.5, a palavra-chave <em>class</em> também pode ser utilizada para resolução
    de nome de classes. Pode-se obter uma string contendo o nome completo e qualificado
    da classe <em>ClassName</em> utilizando
    <em>ClassName::class</em>. Isso é particularmente útil em classes com
    <a href="language.namespaces.php" class="link">namespaces</a>.
   </p>
   <p class="para">
    <div class="example" id="example-198">
     <p><strong>Exemplo #9 Resolução de nome da classe</strong></p>
     <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br /></span><span style="color: #007700">namespace&nbsp;</span><span style="color: #0000BB">NS&nbsp;</span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;class&nbsp;</span><span style="color: #0000BB">ClassName&nbsp;</span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br /><br />&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #0000BB">ClassName</span><span style="color: #007700">::class;<br />}<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
     </div>

     <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
     <div class="example-contents screen">
<div class="cdata"><pre>
NS\ClassName
</pre></div>
     </div>
    </div>
   </p>
   <blockquote class="note"><p><strong class="note">Nota</strong>: 
    <p class="para">A resolução de nomes de classe através de <em>::class</em> é uma
     transformação em tempo de compilação. Significando que a string com nome
     é criada antes que o autoloading tenha acontecido. Como consequência, os nomes de classe
     são expandidos mesmo que a classe não exista. Neste caso, nenhum erro
     será emitido.
    </p>
   </p></blockquote>
  </div>
 </div>
<section id="usernotes">
 <div class="head">
  <span class="action"><a href="/manual/add-note.php?sect=language.oop5.basic&amp;redirect=https://www.php.net/manual/pt_BR/language.oop5.basic.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></span>
  <h3 class="title">User Contributed Notes <span class="count">19 notes</span></h3>
 </div><div id="allnotes">
  <div class="note" id="79856">  <div class="votes">
    <div id="Vu79856">
    <a href="/manual/vote-note.php?id=79856&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd79856">
    <a href="/manual/vote-note.php?id=79856&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V79856" title="74% like this...">
    528
    </div>
  </div>
  <a href="#79856" class="name">
  <strong class="user"><em>aaron at thatone dot com</em></strong></a><a class="genanchor" href="#79856"> &para;</a><div class="date" title="2007-12-15 06:46"><strong>12 years ago</strong></div>
  <div class="text" id="Hcom79856">
<div class="phpcode"><code><span class="html">
I was confused at first about object assignment, because it's not quite the same as normal assignment or assignment by reference. But I think I've figured out what's going on.<br /><br />First, think of variables in PHP as data slots. Each one is a name that points to a data slot that can hold a value that is one of the basic data types: a number, a string, a boolean, etc. When you create a reference, you are making a second name that points at the same data slot. When you assign one variable to another, you are copying the contents of one data slot to another data slot.<br /><br />Now, the trick is that object instances are not like the basic data types. They cannot be held in the data slots directly. Instead, an object's "handle" goes in the data slot. This is an identifier that points at one particular instance of an obect. So, the object handle, although not directly visible to the programmer, is one of the basic datatypes. <br /><br />What makes this tricky is that when you take a variable which holds an object handle, and you assign it to another variable, that other variable gets a copy of the same object handle. This means that both variables can change the state of the same object instance. But they are not references, so if one of the variables is assigned a new value, it does not affect the other variable.<br /><br /><span class="default">&lt;?php<br /></span><span class="comment">// Assignment of an object<br /></span><span class="keyword">Class </span><span class="default">Object</span><span class="keyword">{<br />&nbsp;&nbsp; public </span><span class="default">$foo</span><span class="keyword">=</span><span class="string">"bar"</span><span class="keyword">;<br />};<br /><br /></span><span class="default">$objectVar </span><span class="keyword">= new </span><span class="default">Object</span><span class="keyword">();<br /></span><span class="default">$reference </span><span class="keyword">=&amp; </span><span class="default">$objectVar</span><span class="keyword">;<br /></span><span class="default">$assignment </span><span class="keyword">= </span><span class="default">$objectVar<br /><br /></span><span class="comment">//<br />// $objectVar ---&gt;+---------+<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |(handle1)----+<br />// $reference ---&gt;+---------+&nbsp;&nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; +---------+&nbsp;&nbsp; |<br />// $assignment --&gt;|(handle1)----+<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; +---------+&nbsp;&nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; v<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Object(1):foo="bar"<br />//<br /></span><span class="default">?&gt;<br /></span><br />$assignment has a different data slot from $objectVar, but its data slot holds a handle to the same object. This makes it behave in some ways like a reference. If you use the variable $objectVar to change the state of the Object instance, those changes also show up under $assignment, because it is pointing at that same Object instance.<br /><br /><span class="default">&lt;?php<br />$objectVar</span><span class="keyword">-&gt;</span><span class="default">foo </span><span class="keyword">= </span><span class="string">"qux"</span><span class="keyword">;<br /></span><span class="default">print_r</span><span class="keyword">( </span><span class="default">$objectVar </span><span class="keyword">);<br /></span><span class="default">print_r</span><span class="keyword">( </span><span class="default">$reference </span><span class="keyword">);<br /></span><span class="default">print_r</span><span class="keyword">( </span><span class="default">$assignment </span><span class="keyword">);<br /><br /></span><span class="comment">//<br />// $objectVar ---&gt;+---------+<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |(handle1)----+<br />// $reference ---&gt;+---------+&nbsp;&nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; +---------+&nbsp;&nbsp; |<br />// $assignment --&gt;|(handle1)----+<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; +---------+&nbsp;&nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; v<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Object(1):foo="qux"<br />//<br /></span><span class="default">?&gt;<br /></span><br />But it is not exactly the same as a reference. If you null out $objectVar, you replace the handle in its data slot with NULL. This means that $reference, which points at the same data slot, will also be NULL. But $assignment, which is a different data slot, will still hold its copy of the handle to the Object instance, so it will not be NULL.<br /><br /><span class="default">&lt;?php<br />$objectVar </span><span class="keyword">= </span><span class="default">null</span><span class="keyword">;<br /></span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$objectVar</span><span class="keyword">);<br /></span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$reference</span><span class="keyword">);<br /></span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$assignment</span><span class="keyword">);<br /><br /></span><span class="comment">//<br />// $objectVar ---&gt;+---------+<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |&nbsp; NULL&nbsp;&nbsp; | <br />// $reference ---&gt;+---------+<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; <br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; +---------+<br />// $assignment --&gt;|(handle1)----+<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; +---------+&nbsp;&nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; v<br />//&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Object(1):foo="qux"<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="100314">  <div class="votes">
    <div id="Vu100314">
    <a href="/manual/vote-note.php?id=100314&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd100314">
    <a href="/manual/vote-note.php?id=100314&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V100314" title="63% like this...">
    114
    </div>
  </div>
  <a href="#100314" class="name">
  <strong class="user"><em>Doug</em></strong></a><a class="genanchor" href="#100314"> &para;</a><div class="date" title="2010-10-07 07:29"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom100314">
<div class="phpcode"><code><span class="html">
What is the difference between&nbsp; $this&nbsp; and&nbsp; self ?<br /><br />Inside a class definition, $this refers to the current object, while&nbsp; self&nbsp; refers to the current class.<br /><br />It is necessary to refer to a class element using&nbsp; self ,<br />and refer to an object element using&nbsp; $this .<br />Note also how an object variable must be preceded by a keyword in its definition.<br /><br />The following example illustrates a few cases:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Classy </span><span class="keyword">{<br /><br />const&nbsp; &nbsp; &nbsp;&nbsp; </span><span class="default">STAT </span><span class="keyword">= </span><span class="string">'S' </span><span class="keyword">; </span><span class="comment">// no dollar sign for constants (they are always static)<br /></span><span class="keyword">static&nbsp; &nbsp;&nbsp; </span><span class="default">$stat </span><span class="keyword">= </span><span class="string">'Static' </span><span class="keyword">;<br />public&nbsp; &nbsp;&nbsp; </span><span class="default">$publ </span><span class="keyword">= </span><span class="string">'Public' </span><span class="keyword">;<br />private&nbsp; &nbsp; </span><span class="default">$priv </span><span class="keyword">= </span><span class="string">'Private' </span><span class="keyword">;<br />protected&nbsp; </span><span class="default">$prot </span><span class="keyword">= </span><span class="string">'Protected' </span><span class="keyword">;<br /><br />function </span><span class="default">__construct</span><span class="keyword">( ){&nbsp; }<br /><br />public function </span><span class="default">showMe</span><span class="keyword">( ){<br />&nbsp; &nbsp; print </span><span class="string">'&lt;br&gt; self::STAT: '&nbsp; </span><span class="keyword">.&nbsp; </span><span class="default">self</span><span class="keyword">::</span><span class="default">STAT </span><span class="keyword">; </span><span class="comment">// refer to a (static) constant like this<br />&nbsp; &nbsp; </span><span class="keyword">print </span><span class="string">'&lt;br&gt; self::$stat: ' </span><span class="keyword">. </span><span class="default">self</span><span class="keyword">::</span><span class="default">$stat </span><span class="keyword">; </span><span class="comment">// static variable<br />&nbsp; &nbsp; </span><span class="keyword">print </span><span class="string">'&lt;br&gt;$this-&gt;stat: '&nbsp; </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">stat </span><span class="keyword">; </span><span class="comment">// legal, but not what you might think: empty result<br />&nbsp; &nbsp; </span><span class="keyword">print </span><span class="string">'&lt;br&gt;$this-&gt;publ: '&nbsp; </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">publ </span><span class="keyword">; </span><span class="comment">// refer to an object variable like this<br />&nbsp; &nbsp; </span><span class="keyword">print </span><span class="string">'&lt;br&gt;' </span><span class="keyword">;<br />}<br />}<br /></span><span class="default">$me </span><span class="keyword">= new </span><span class="default">Classy</span><span class="keyword">( ) ;<br /></span><span class="default">$me</span><span class="keyword">-&gt;</span><span class="default">showMe</span><span class="keyword">( ) ;<br /><br /></span><span class="comment">/* Produces this output:<br />self::STAT: S<br />self::$stat: Static<br />$this-&gt;stat:<br />$this-&gt;publ: Public<br />*/<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120909">  <div class="votes">
    <div id="Vu120909">
    <a href="/manual/vote-note.php?id=120909&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120909">
    <a href="/manual/vote-note.php?id=120909&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120909" title="66% like this...">
    24
    </div>
  </div>
  <a href="#120909" class="name">
  <strong class="user"><em>kStarbe at gmail point com</em></strong></a><a class="genanchor" href="#120909"> &para;</a><div class="date" title="2017-03-30 07:36"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom120909">
<div class="phpcode"><code><span class="html">
You start using :: in second example although the static concept has not been explained. This is not easy to discover when you are starting from the basics.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="85220">  <div class="votes">
    <div id="Vu85220">
    <a href="/manual/vote-note.php?id=85220&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd85220">
    <a href="/manual/vote-note.php?id=85220&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V85220" title="61% like this...">
    54
    </div>
  </div>
  <a href="#85220" class="name">
  <strong class="user"><em>wbcarts at juno dot com</em></strong></a><a class="genanchor" href="#85220"> &para;</a><div class="date" title="2008-08-20 06:11"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom85220">
<div class="phpcode"><code><span class="html">
CLASSES and OBJECTS that represent the "Ideal World"<br /><br />Wouldn't it be great to get the lawn mowed by saying $son-&gt;mowLawn()? Assuming the function mowLawn() is defined, and you have a son that doesn't throw errors, the lawn will be mowed. <br /><br />In the following example; let objects of type Line3D measure their own length in 3-dimensional space. Why should I or PHP have to provide another method from outside this class to calculate length, when the class itself holds all the neccessary data and has the education to make the calculation for itself?<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="comment">/*<br /> * Point3D.php<br /> *<br /> * Represents one locaton or position in 3-dimensional space<br /> * using an (x, y, z) coordinate system.<br /> */<br /></span><span class="keyword">class </span><span class="default">Point3D<br /></span><span class="keyword">{<br />&nbsp; &nbsp; public </span><span class="default">$x</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$y</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$z</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// the x coordinate of this Point.<br /><br />&nbsp; &nbsp; /*<br />&nbsp; &nbsp;&nbsp; * use the x and y variables inherited from Point.php.<br />&nbsp; &nbsp;&nbsp; */<br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">__construct</span><span class="keyword">(</span><span class="default">$xCoord</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">, </span><span class="default">$yCoord</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">, </span><span class="default">$zCoord</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">x </span><span class="keyword">= </span><span class="default">$xCoord</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">y </span><span class="keyword">= </span><span class="default">$yCoord</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">z </span><span class="keyword">= </span><span class="default">$zCoord</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="comment">/*<br />&nbsp; &nbsp;&nbsp; * the (String) representation of this Point as "Point3D(x, y, z)".<br />&nbsp; &nbsp;&nbsp; */<br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">__toString</span><span class="keyword">()<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="string">'Point3D(x=' </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">x </span><span class="keyword">. </span><span class="string">', y=' </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">y </span><span class="keyword">. </span><span class="string">', z=' </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">z </span><span class="keyword">. </span><span class="string">')'</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />}<br /><br /></span><span class="comment">/*<br /> * Line3D.php<br /> *<br /> * Represents one Line in 3-dimensional space using two Point3D objects.<br /> */<br /></span><span class="keyword">class </span><span class="default">Line3D<br /></span><span class="keyword">{<br />&nbsp; &nbsp; </span><span class="default">$start</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$end</span><span class="keyword">;<br /><br />&nbsp; &nbsp; public function </span><span class="default">__construct</span><span class="keyword">(</span><span class="default">$xCoord1</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">, </span><span class="default">$yCoord1</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">, </span><span class="default">$zCoord1</span><span class="keyword">=</span><span class="default">0</span><span class="keyword">, </span><span class="default">$xCoord2</span><span class="keyword">=</span><span class="default">1</span><span class="keyword">, </span><span class="default">$yCoord2</span><span class="keyword">=</span><span class="default">1</span><span class="keyword">, </span><span class="default">$zCoord2</span><span class="keyword">=</span><span class="default">1</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">start </span><span class="keyword">= new </span><span class="default">Point3D</span><span class="keyword">(</span><span class="default">$xCoord1</span><span class="keyword">, </span><span class="default">$yCoord1</span><span class="keyword">, </span><span class="default">$zCoord1</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">end </span><span class="keyword">= new </span><span class="default">Point3D</span><span class="keyword">(</span><span class="default">$xCoord2</span><span class="keyword">, </span><span class="default">$yCoord2</span><span class="keyword">, </span><span class="default">$zCoord2</span><span class="keyword">);<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="comment">/*<br />&nbsp; &nbsp;&nbsp; * calculate the length of this Line in 3-dimensional space.<br />&nbsp; &nbsp;&nbsp; */ <br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">getLength</span><span class="keyword">()<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">sqrt</span><span class="keyword">(<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">pow</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">start</span><span class="keyword">-&gt;</span><span class="default">x </span><span class="keyword">- </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">end</span><span class="keyword">-&gt;</span><span class="default">x</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">) +<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">pow</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">start</span><span class="keyword">-&gt;</span><span class="default">y </span><span class="keyword">- </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">end</span><span class="keyword">-&gt;</span><span class="default">y</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">) +<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">pow</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">start</span><span class="keyword">-&gt;</span><span class="default">z </span><span class="keyword">- </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">end</span><span class="keyword">-&gt;</span><span class="default">z</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; );<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="comment">/*<br />&nbsp; &nbsp;&nbsp; * The (String) representation of this Line as "Line3D[start, end, length]".<br />&nbsp; &nbsp;&nbsp; */<br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">__toString</span><span class="keyword">()<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="string">'Line3D[start=' </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">start </span><span class="keyword">.<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">', end=' </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">end </span><span class="keyword">.<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">', length=' </span><span class="keyword">. </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">getLength</span><span class="keyword">() . </span><span class="string">']'</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />}<br /><br /></span><span class="comment">/*<br /> * create and display objects of type Line3D.<br /> */<br /></span><span class="keyword">echo </span><span class="string">'&lt;p&gt;' </span><span class="keyword">. (new </span><span class="default">Line3D</span><span class="keyword">()) . </span><span class="string">"&lt;/p&gt;\n"</span><span class="keyword">;<br />echo </span><span class="string">'&lt;p&gt;' </span><span class="keyword">. (new </span><span class="default">Line3D</span><span class="keyword">(</span><span class="default">0</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">100</span><span class="keyword">, </span><span class="default">100</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">)) . </span><span class="string">"&lt;/p&gt;\n"</span><span class="keyword">;<br />echo </span><span class="string">'&lt;p&gt;' </span><span class="keyword">. (new </span><span class="default">Line3D</span><span class="keyword">(</span><span class="default">0</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">, </span><span class="default">100</span><span class="keyword">, </span><span class="default">100</span><span class="keyword">, </span><span class="default">100</span><span class="keyword">)) . </span><span class="string">"&lt;/p&gt;\n"</span><span class="keyword">;<br /><br /></span><span class="default">?&gt;<br /></span><br />&nbsp; &lt;--&nbsp; The results look like this&nbsp; --&gt;<br /><br />Line3D[start=Point3D(x=0, y=0, z=0), end=Point3D(x=1, y=1, z=1), length=1.73205080757]<br /><br />Line3D[start=Point3D(x=0, y=0, z=0), end=Point3D(x=100, y=100, z=0), length=141.421356237]<br /><br />Line3D[start=Point3D(x=0, y=0, z=0), end=Point3D(x=100, y=100, z=100), length=173.205080757]<br /><br />My absolute favorite thing about OOP is that "good" objects keep themselves in check. I mean really, it's the exact same thing in reality... like, if you hire a plumber to fix your kitchen sink, wouldn't you expect him to figure out the best plan of attack? Wouldn't he dislike the fact that you want to control the whole job? Wouldn't you expect him to not give you additional problems? And for god's sake, it is too much to ask that he cleans up before he leaves?<br /><br />I say, design your classes well, so they can do their jobs uninterrupted... who like bad news? And, if your classes and objects are well defined, educated, and have all the necessary data to work on (like the examples above do), you won't have to micro-manage the whole program from outside of the class. In other words... create an object, and LET IT RIP!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="92123">  <div class="votes">
    <div id="Vu92123">
    <a href="/manual/vote-note.php?id=92123&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd92123">
    <a href="/manual/vote-note.php?id=92123&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V92123" title="61% like this...">
    32
    </div>
  </div>
  <a href="#92123" class="name">
  <strong class="user"><em>Notes on stdClass</em></strong></a><a class="genanchor" href="#92123"> &para;</a><div class="date" title="2009-07-09 03:26"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom92123">
<div class="phpcode"><code><span class="html">
stdClass is the default PHP object. stdClass has no properties, methods or parent. It does not support magic methods, and implements no interfaces.<br /><br />When you cast a scalar or array as Object, you get an instance of stdClass. You can use stdClass whenever you need a generic object instance.<br /><span class="default">&lt;?php<br /></span><span class="comment">// ways of creating stdClass instances<br /></span><span class="default">$x </span><span class="keyword">= new </span><span class="default">stdClass</span><span class="keyword">;<br /></span><span class="default">$y </span><span class="keyword">= (object) </span><span class="default">null</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// same as above<br /></span><span class="default">$z </span><span class="keyword">= (object) </span><span class="string">'a'</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// creates property 'scalar' = 'a'<br /></span><span class="default">$a </span><span class="keyword">= (object) array(</span><span class="string">'property1' </span><span class="keyword">=&gt; </span><span class="default">1</span><span class="keyword">, </span><span class="string">'property2' </span><span class="keyword">=&gt; </span><span class="string">'b'</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />stdClass is NOT a base class! PHP classes do not automatically inherit from any class. All classes are standalone, unless they explicitly extend another class. PHP differs from many object-oriented languages in this respect.<br /><span class="default">&lt;?php<br /></span><span class="comment">// CTest does not derive from stdClass<br /></span><span class="keyword">class </span><span class="default">CTest </span><span class="keyword">{<br />&nbsp; &nbsp; public </span><span class="default">$property1</span><span class="keyword">;<br />}<br /></span><span class="default">$t </span><span class="keyword">= new </span><span class="default">CTest</span><span class="keyword">;<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$t </span><span class="keyword">instanceof </span><span class="default">stdClass</span><span class="keyword">);&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// false<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">is_subclass_of</span><span class="keyword">(</span><span class="default">$t</span><span class="keyword">, </span><span class="string">'stdClass'</span><span class="keyword">));&nbsp; &nbsp; </span><span class="comment">// false<br /></span><span class="keyword">echo </span><span class="default">get_class</span><span class="keyword">(</span><span class="default">$t</span><span class="keyword">) . </span><span class="string">"\n"</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// 'CTest'<br /></span><span class="keyword">echo </span><span class="default">get_parent_class</span><span class="keyword">(</span><span class="default">$t</span><span class="keyword">) . </span><span class="string">"\n"</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// false (no parent)<br /></span><span class="default">?&gt;<br /></span><br />You cannot define a class named 'stdClass' in your code. That name is already used by the system. You can define a class named 'Object'.<br /><br />You could define a class that extends stdClass, but you would get no benefit, as stdClass does nothing.<br /><br />(tested on PHP 5.2.8)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="122293">  <div class="votes">
    <div id="Vu122293">
    <a href="/manual/vote-note.php?id=122293&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd122293">
    <a href="/manual/vote-note.php?id=122293&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V122293" title="60% like this...">
    7
    </div>
  </div>
  <a href="#122293" class="name">
  <strong class="user"><em>Hayley Watson</em></strong></a><a class="genanchor" href="#122293"> &para;</a><div class="date" title="2018-01-21 10:52"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom122293">
<div class="phpcode"><code><span class="html">
Class names are case-insensitive:<br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Foo</span><span class="keyword">{}<br />class </span><span class="default">foo</span><span class="keyword">{} </span><span class="comment">//Fatal error.<br /></span><span class="default">?&gt;<br /></span><br />Any casing can be used to refer to the class<br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">bAr</span><span class="keyword">{}<br /></span><span class="default">$t </span><span class="keyword">= new </span><span class="default">Bar</span><span class="keyword">();<br /></span><span class="default">$u </span><span class="keyword">= new </span><span class="default">bar</span><span class="keyword">();<br />echo (</span><span class="default">$t </span><span class="keyword">instanceof </span><span class="default">$u</span><span class="keyword">) ? </span><span class="string">"true" </span><span class="keyword">: </span><span class="string">"false"</span><span class="keyword">; </span><span class="comment">// "true"<br /></span><span class="keyword">echo (</span><span class="default">$t </span><span class="keyword">instanceof </span><span class="default">BAR</span><span class="keyword">) ? </span><span class="string">"true" </span><span class="keyword">: </span><span class="string">"false"</span><span class="keyword">; </span><span class="comment">// "true"<br /></span><span class="keyword">echo </span><span class="default">is_a</span><span class="keyword">(</span><span class="default">$u</span><span class="keyword">, </span><span class="string">'baR'</span><span class="keyword">) ? </span><span class="string">"true" </span><span class="keyword">: </span><span class="string">"false"</span><span class="keyword">; </span><span class="comment">// "true"<br /></span><span class="default">?&gt;<br /></span><br />But the case used when the class was defined is preserved as "canonical":<br /><span class="default">&lt;?php<br /></span><span class="keyword">echo </span><span class="default">get_class</span><span class="keyword">(</span><span class="default">$t</span><span class="keyword">); </span><span class="comment">// "bAr"<br /></span><span class="default">?&gt;<br /></span><br />And, as always, "case-insensitivity" only applies to ASCII.<br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">пасха</span><span class="keyword">{}<br />class </span><span class="default">Пасха</span><span class="keyword">{} </span><span class="comment">// valid<br /></span><span class="default">$p </span><span class="keyword">= new </span><span class="default">ПАСХА</span><span class="keyword">(); </span><span class="comment">// Uncaught warning.<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="106262">  <div class="votes">
    <div id="Vu106262">
    <a href="/manual/vote-note.php?id=106262&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd106262">
    <a href="/manual/vote-note.php?id=106262&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V106262" title="57% like this...">
    31
    </div>
  </div>
  <a href="#106262" class="name">
  <strong class="user"><em>Manish Gupta</em></strong></a><a class="genanchor" href="#106262"> &para;</a><div class="date" title="2011-10-22 10:07"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom106262">
<div class="phpcode"><code><span class="html">
Some thing that may be obvious to the seasoned PHP programmer, but may surprise someone coming over from C++:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Foo<br /></span><span class="keyword">{<br /></span><span class="default">$bar </span><span class="keyword">= </span><span class="string">'Hi There'</span><span class="keyword">;<br /><br />public function Print(){<br />&nbsp; &nbsp; echo </span><span class="default">$bar</span><span class="keyword">;<br />}<br />}<br /></span><span class="default">?&gt;<br /></span><br />Gives an error saying Print used undefined variable. One has to explicitly use (notice the use of <span class="default">&lt;?php $this</span><span class="keyword">-&gt;</span><span class="default">bar ?&gt;</span>):<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Foo<br /></span><span class="keyword">{<br /></span><span class="default">$bar </span><span class="keyword">= </span><span class="string">'Hi There'</span><span class="keyword">;<br /><br />public function Print(){<br />&nbsp; &nbsp; echo </span><span class="default">this</span><span class="keyword">-&gt;</span><span class="default">$bar</span><span class="keyword">;<br />}<br />}<br /></span><span class="default">?&gt;<br /></span><br /> <span class="default">&lt;?php </span><span class="keyword">echo </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">bar</span><span class="keyword">; </span><span class="default">?&gt;</span> refers to the class member, while using $bar means using an uninitialized variable in the local context of the member function.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="122844">  <div class="votes">
    <div id="Vu122844">
    <a href="/manual/vote-note.php?id=122844&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd122844">
    <a href="/manual/vote-note.php?id=122844&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V122844" title="57% like this...">
    3
    </div>
  </div>
  <a href="#122844" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#122844"> &para;</a><div class="date" title="2018-06-15 05:05"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom122844">
<div class="phpcode"><code><span class="html">
At first I was also confused by the assignment vs referencing but here's how I was finally able to get my head around it. This is another example which is somewhat similar to one of the comments but can be helpful to those who did not understand the first example. Imagine object instances as rooms where you can store and manipulate your properties and functions.&nbsp; The variable that contains the object simply holds 'a key' to this room and thus access to the object. When you assign this variable to another new variable, what you are doing is you're making a copy of the key and giving it to this new variable. That means these two variable now have access to the same 'room' (object) and can thus get in and manipulate the values. However, when you create a reference, what you doing is you're making the variables SHARE the same key. They both have access to the room. If one of the variable is given a new key, then the key that they are sharing is replaced and they now share a new different key. This does not affect the other variable with a copy of the old key...that variable still has access to the first room</span>
</code></div>
  </div>
 </div>
  <div class="note" id="92958">  <div class="votes">
    <div id="Vu92958">
    <a href="/manual/vote-note.php?id=92958&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd92958">
    <a href="/manual/vote-note.php?id=92958&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V92958" title="57% like this...">
    16
    </div>
  </div>
  <a href="#92958" class="name">
  <strong class="user"><em>moty66 at gmail dot com</em></strong></a><a class="genanchor" href="#92958"> &para;</a><div class="date" title="2009-08-16 07:59"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom92958">
<div class="phpcode"><code><span class="html">
I hope that this will help to understand how to work with static variables inside a class<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">class </span><span class="default">a </span><span class="keyword">{<br /><br />&nbsp; &nbsp; public static </span><span class="default">$foo </span><span class="keyword">= </span><span class="string">'I am foo'</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$bar </span><span class="keyword">= </span><span class="string">'I am bar'</span><span class="keyword">;<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; public static function </span><span class="default">getFoo</span><span class="keyword">() { echo </span><span class="default">self</span><span class="keyword">::</span><span class="default">$foo</span><span class="keyword">;&nbsp; &nbsp; }<br />&nbsp; &nbsp; public static function </span><span class="default">setFoo</span><span class="keyword">() { </span><span class="default">self</span><span class="keyword">::</span><span class="default">$foo </span><span class="keyword">= </span><span class="string">'I am a new foo'</span><span class="keyword">; }<br />&nbsp; &nbsp; public function </span><span class="default">getBar</span><span class="keyword">() { echo </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">bar</span><span class="keyword">;&nbsp; &nbsp; }&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <br />}<br /><br /></span><span class="default">$ob </span><span class="keyword">= new </span><span class="default">a</span><span class="keyword">();<br /></span><span class="default">a</span><span class="keyword">::</span><span class="default">getFoo</span><span class="keyword">();&nbsp; &nbsp;&nbsp; </span><span class="comment">// output: I am foo&nbsp; &nbsp; <br /></span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">getFoo</span><span class="keyword">();&nbsp; &nbsp; </span><span class="comment">// output: I am foo<br />//a::getBar();&nbsp; &nbsp;&nbsp; // fatal error: using $this not in object context<br /></span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">getBar</span><span class="keyword">();&nbsp; &nbsp; </span><span class="comment">// output: I am bar<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // If you keep $bar non static this will work<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; // but if bar was static, then var_dump($this-&gt;bar) will output null <br /><br />// unset($ob);<br /></span><span class="default">a</span><span class="keyword">::</span><span class="default">setFoo</span><span class="keyword">();&nbsp; &nbsp; </span><span class="comment">// The same effect as if you called $ob-&gt;setFoo(); because $foo is static<br /></span><span class="default">$ob </span><span class="keyword">= new </span><span class="default">a</span><span class="keyword">();&nbsp; &nbsp;&nbsp; </span><span class="comment">// This will have no effects on $foo<br /></span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">getFoo</span><span class="keyword">();&nbsp; &nbsp; </span><span class="comment">// output: I am a new foo <br /><br /></span><span class="default">?&gt;<br /></span><br />Regards<br />Motaz Abuthiab</span>
</code></div>
  </div>
 </div>
  <div class="note" id="123493">  <div class="votes">
    <div id="Vu123493">
    <a href="/manual/vote-note.php?id=123493&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd123493">
    <a href="/manual/vote-note.php?id=123493&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V123493" title="55% like this...">
    1
    </div>
  </div>
  <a href="#123493" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#123493"> &para;</a><div class="date" title="2019-01-05 10:45"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom123493">
<div class="phpcode"><code><span class="html">
Note that $this cannot be reassigned, because most instance functions would not work. So this code throws a fatal error :<br /><span class="default">&lt;?php<br />&nbsp; &nbsp; </span><span class="keyword">class </span><span class="default">Foo </span><span class="keyword">{<br />&nbsp; &nbsp; &nbsp; &nbsp; function </span><span class="default">reassign</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// This line triggers an E_ERROR<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this </span><span class="keyword">= new </span><span class="default">Foo</span><span class="keyword">();<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="default">$example </span><span class="keyword">= new </span><span class="default">Foo</span><span class="keyword">();<br />&nbsp; &nbsp; </span><span class="default">$example</span><span class="keyword">-&gt;</span><span class="default">reassign</span><span class="keyword">();<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="86235">  <div class="votes">
    <div id="Vu86235">
    <a href="/manual/vote-note.php?id=86235&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd86235">
    <a href="/manual/vote-note.php?id=86235&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V86235" title="56% like this...">
    17
    </div>
  </div>
  <a href="#86235" class="name">
  <strong class="user"><em>Jeffrey</em></strong></a><a class="genanchor" href="#86235"> &para;</a><div class="date" title="2008-10-08 03:49"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom86235">
<div class="phpcode"><code><span class="html">
A PHP Class can be used for several things, but at the most basic level, you'll use classes to "organize and deal with like-minded data". Here's what I mean by "organizing like-minded data". First, start with unorganized data.<br /><br /><span class="default">&lt;?php<br />$customer_name</span><span class="keyword">;<br /></span><span class="default">$item_name</span><span class="keyword">;<br /></span><span class="default">$item_price</span><span class="keyword">;<br /></span><span class="default">$customer_address</span><span class="keyword">;<br /></span><span class="default">$item_qty</span><span class="keyword">;<br /></span><span class="default">$item_total</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span><br />Now to organize the data into PHP classes:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Customer </span><span class="keyword">{<br />&nbsp; </span><span class="default">$name</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// same as $customer_name<br />&nbsp; </span><span class="default">$address</span><span class="keyword">;&nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// same as $customer_address<br /></span><span class="keyword">}<br /><br />class </span><span class="default">Item </span><span class="keyword">{<br />&nbsp; </span><span class="default">$name</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// same as $item_name<br />&nbsp; </span><span class="default">$price</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// same as $item_price<br />&nbsp; </span><span class="default">$qty</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// same as $item_qty<br />&nbsp; </span><span class="default">$total</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// same as $item_total<br /></span><span class="keyword">}<br /></span><span class="default">?&gt;<br /></span><br />Now here's what I mean by "dealing" with the data. Note: The data is already organized, so that in itself makes writing new functions extremely easy.<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Customer </span><span class="keyword">{<br />&nbsp; public </span><span class="default">$name</span><span class="keyword">, </span><span class="default">$address</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// the data for this class...<br /><br />&nbsp; // function to deal with user-input / validation<br />&nbsp; // function to build string for output<br />&nbsp; // function to write -&gt; database<br />&nbsp; // function to&nbsp; read &lt;- database<br />&nbsp; // etc, etc<br /></span><span class="keyword">}<br /><br />class </span><span class="default">Item </span><span class="keyword">{<br />&nbsp; public </span><span class="default">$name</span><span class="keyword">, </span><span class="default">$price</span><span class="keyword">, </span><span class="default">$qty</span><span class="keyword">, </span><span class="default">$total</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// the data for this class...<br /><br />&nbsp; // function to calculate total<br />&nbsp; // function to format numbers<br />&nbsp; // function to deal with user-input / validation<br />&nbsp; // function to build string for output<br />&nbsp; // function to write -&gt; database<br />&nbsp; // function to&nbsp; read &lt;- database<br />&nbsp; // etc, etc<br /></span><span class="keyword">}<br /></span><span class="default">?&gt;<br /></span><br />Imagination that each function you write only calls the bits of data in that class. Some functions may access all the data, while other functions may only access one piece of data. If each function revolves around the data inside, then you have created a good class.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120595">  <div class="votes">
    <div id="Vu120595">
    <a href="/manual/vote-note.php?id=120595&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120595">
    <a href="/manual/vote-note.php?id=120595&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120595" title="55% like this...">
    3
    </div>
  </div>
  <a href="#120595" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#120595"> &para;</a><div class="date" title="2017-02-04 09:59"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom120595">
<div class="phpcode"><code><span class="html">
Understanding what does $this exactly do:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">toop </span><span class="keyword">{<br />&nbsp; &nbsp; public </span><span class="default">$i </span><span class="keyword">= </span><span class="string">"1234"</span><span class="keyword">;<br />&nbsp; &nbsp; public function </span><span class="default">setv</span><span class="keyword">(</span><span class="default">$a</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">i </span><span class="keyword">= </span><span class="default">$a</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; public function </span><span class="default">returnthis</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$this</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />}<br /></span><span class="default">$ob </span><span class="keyword">= new </span><span class="default">toop</span><span class="keyword">();<br /></span><span class="default">$ob1 </span><span class="keyword">= new </span><span class="default">toop</span><span class="keyword">();<br /></span><span class="default">$obthis </span><span class="keyword">= </span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">returnthis</span><span class="keyword">();<br />echo </span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">i</span><span class="keyword">.</span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">setv</span><span class="keyword">(</span><span class="string">"\$ob set"</span><span class="keyword">);<br />echo </span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">i</span><span class="keyword">.</span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="default">$obthis</span><span class="keyword">-&gt;</span><span class="default">setv</span><span class="keyword">(</span><span class="string">"\$obthis set"</span><span class="keyword">);<br />echo </span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">i</span><span class="keyword">.</span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="default">$ob1</span><span class="keyword">-&gt;</span><span class="default">setv</span><span class="keyword">(</span><span class="string">'$ob1 set'</span><span class="keyword">);<br />echo </span><span class="default">$ob</span><span class="keyword">-&gt;</span><span class="default">i</span><span class="keyword">.</span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span><br />This will output:<br /><br />1234<br />$ob set<br />$obthis set<br />$obthis set</span>
</code></div>
  </div>
 </div>
  <div class="note" id="92204">  <div class="votes">
    <div id="Vu92204">
    <a href="/manual/vote-note.php?id=92204&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd92204">
    <a href="/manual/vote-note.php?id=92204&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V92204" title="54% like this...">
    7
    </div>
  </div>
  <a href="#92204" class="name">
  <strong class="user"><em>the_french_cow at hotmail dot com</em></strong></a><a class="genanchor" href="#92204"> &para;</a><div class="date" title="2009-07-14 06:54"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom92204">
<div class="phpcode"><code><span class="html">
For those of us who are new to inheritance, private functions are not visible in an inherited class. Consider: <br /><br /><span class="default">&lt;?php<br />&nbsp; &nbsp; </span><span class="keyword">class </span><span class="default">A </span><span class="keyword">{<br />&nbsp; &nbsp; &nbsp; &nbsp; protected function </span><span class="default">func1</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo(</span><span class="string">"I'm func1 in A!&lt;br/&gt;"</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; private function </span><span class="default">func2</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo(</span><span class="string">"I'm func2 in A!&lt;br/&gt;"</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; class </span><span class="default">B </span><span class="keyword">extends </span><span class="default">A </span><span class="keyword">{<br />&nbsp; &nbsp; &nbsp; &nbsp; public function </span><span class="default">func3</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo(</span><span class="string">"I'm func3 in B!&lt;br/&gt;"</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">func1</span><span class="keyword">();<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">func2</span><span class="keyword">();&nbsp; </span><span class="comment">// Call to private function from extended class results in a fatal error<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">}<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="default">$b </span><span class="keyword">= new </span><span class="default">B</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$b</span><span class="keyword">-&gt;</span><span class="default">func3</span><span class="keyword">();&nbsp; </span><span class="comment">// Ends in a fatal error<br /><br />// OR<br /><br />&nbsp; &nbsp; </span><span class="default">$b</span><span class="keyword">-&gt;</span><span class="default">func1</span><span class="keyword">();&nbsp; </span><span class="comment">// Call to protected function from outside world results in a fatal error<br /></span><span class="default">?&gt;<br /></span><br />If you want a function to be accessible in class B but not to the outside world, it must be declared as protected.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="102275">  <div class="votes">
    <div id="Vu102275">
    <a href="/manual/vote-note.php?id=102275&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd102275">
    <a href="/manual/vote-note.php?id=102275&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V102275" title="53% like this...">
    15
    </div>
  </div>
  <a href="#102275" class="name">
  <strong class="user"><em>Marcus</em></strong></a><a class="genanchor" href="#102275"> &para;</a><div class="date" title="2011-02-05 11:00"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom102275">
<div class="phpcode"><code><span class="html">
Here's another simple example.<br /><br /><span class="default">&lt;?php<br /></span><span class="comment">// PHP 5<br /><br />// class definition<br /></span><span class="keyword">class </span><span class="default">Bear </span><span class="keyword">{<br />&nbsp; &nbsp; </span><span class="comment">// define properties<br />&nbsp; &nbsp; </span><span class="keyword">public </span><span class="default">$name</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$weight</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$age</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$sex</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$colour</span><span class="keyword">;<br /><br />&nbsp; &nbsp; </span><span class="comment">// constructor<br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">__construct</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">age </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">weight </span><span class="keyword">= </span><span class="default">100</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="comment">// define methods<br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">eat</span><span class="keyword">(</span><span class="default">$units</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; echo </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">name</span><span class="keyword">.</span><span class="string">" is eating "</span><span class="keyword">.</span><span class="default">$units</span><span class="keyword">.</span><span class="string">" units of food... "</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">weight </span><span class="keyword">+= </span><span class="default">$units</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; public function </span><span class="default">run</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; echo </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">name</span><span class="keyword">.</span><span class="string">" is running... "</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; public function </span><span class="default">kill</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; echo </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">name</span><span class="keyword">.</span><span class="string">" is killing prey... "</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; public function </span><span class="default">sleep</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; echo </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">name</span><span class="keyword">.</span><span class="string">" is sleeping... "</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />}<br /><br /></span><span class="comment">// extended class definition<br /></span><span class="keyword">class </span><span class="default">PolarBear </span><span class="keyword">extends </span><span class="default">Bear </span><span class="keyword">{<br /><br />&nbsp; &nbsp; </span><span class="comment">// constructor<br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">__construct</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">parent</span><span class="keyword">::</span><span class="default">__construct</span><span class="keyword">();<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">colour </span><span class="keyword">= </span><span class="string">"white"</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">weight </span><span class="keyword">= </span><span class="default">600</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="comment">// define methods<br />&nbsp; &nbsp; </span><span class="keyword">public function </span><span class="default">swim</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; echo </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">name</span><span class="keyword">.</span><span class="string">" is swimming... "</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />}<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="121416">  <div class="votes">
    <div id="Vu121416">
    <a href="/manual/vote-note.php?id=121416&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd121416">
    <a href="/manual/vote-note.php?id=121416&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V121416" title="51% like this...">
    1
    </div>
  </div>
  <a href="#121416" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#121416"> &para;</a><div class="date" title="2017-07-22 11:02"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom121416">
<div class="phpcode"><code><span class="html">
Perhaps the note about ::class expansion during compile time is not entirely clear. Here's an example to demonstrate what happens when using ::class on non-existent classes:<br /><span class="default">&lt;?php<br /><br />var_dump</span><span class="keyword">(</span><span class="default">ExampleAbc</span><span class="keyword">::class);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">NS</span><span class="keyword">\</span><span class="default">Service</span><span class="keyword">\</span><span class="default">ExampleAbc</span><span class="keyword">::class);<br /><br /></span><span class="comment">// Outputs:<br />// string(10) "ExampleAbc"<br />// string(21) "NS\Service\ExampleAbc"<br />// No error is issued.<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="82652">  <div class="votes">
    <div id="Vu82652">
    <a href="/manual/vote-note.php?id=82652&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd82652">
    <a href="/manual/vote-note.php?id=82652&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V82652" title="52% like this...">
    6
    </div>
  </div>
  <a href="#82652" class="name">
  <strong class="user"><em>info at youwanttoremovethisvakantiebaas dot nl</em></strong></a><a class="genanchor" href="#82652"> &para;</a><div class="date" title="2008-04-20 03:40"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom82652">
<div class="phpcode"><code><span class="html">
if you do this<br /><span class="default">&lt;?php<br /><br />$x </span><span class="keyword">= new </span><span class="default">b</span><span class="keyword">();<br /><br />class </span><span class="default">b </span><span class="keyword">extends </span><span class="default">a </span><span class="keyword">{}<br /><br />class </span><span class="default">a </span><span class="keyword">{ }<br /><br /></span><span class="default">?&gt;<br /></span>PHP will tell you "class b not found", because you've defined class b before a. However, the error tells you something different.... Got me a little confused :)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="121428">  <div class="votes">
    <div id="Vu121428">
    <a href="/manual/vote-note.php?id=121428&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd121428">
    <a href="/manual/vote-note.php?id=121428&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V121428" title="34% like this...">
    -15
    </div>
  </div>
  <a href="#121428" class="name">
  <strong class="user"><em>nagabhushan1995 at gmail dot com</em></strong></a><a class="genanchor" href="#121428"> &para;</a><div class="date" title="2017-07-25 09:24"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom121428">
<div class="phpcode"><code><span class="html">
Object handles in PHP are kind of Java References (not C++ references : references are aliases in C++).</span>
</code></div>
  </div>
 </div>
  <div class="note" id="121518">  <div class="votes">
    <div id="Vu121518">
    <a href="/manual/vote-note.php?id=121518&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd121518">
    <a href="/manual/vote-note.php?id=121518&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V121518" title="32% like this...">
    -11
    </div>
  </div>
  <a href="#121518" class="name">
  <strong class="user"><em>Hayley Watson</em></strong></a><a class="genanchor" href="#121518"> &para;</a><div class="date" title="2017-08-13 06:31"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom121518">
<div class="phpcode"><code><span class="html">
Unless the function's parameter is marked as pass by reference using "&amp;", arguments to it are passed by value. This goes for objects same as everything else. The fact is every object has its own unique identity, and the "value" of an object IS the object itself. And not, for example, anything to do with the values of any of its properties: modifying an object's properties doesn't change the object's identity (and hence its value) any more than your identity changes when you take your socks off. So when an object is passed (by value) to a function, and its properties are modified, THAT object's properties get modified.<br /><br />The "&amp;" modifier only matters if a new value is assigned to the parameter variable. If the modifier is used, then whatever was passed in the parameter is also replaced, if it's not, then it isn't. Again, this behaviour is the same whether it's an object or something else.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="121429">  <div class="votes">
    <div id="Vu121429">
    <a href="/manual/vote-note.php?id=121429&amp;page=language.oop5.basic&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd121429">
    <a href="/manual/vote-note.php?id=121429&amp;page=language.oop5.basic&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V121429" title="18% like this...">
    -31
    </div>
  </div>
  <a href="#121429" class="name">
  <strong class="user"><em>nagabhushan1995 at gmail dot com</em></strong></a><a class="genanchor" href="#121429"> &para;</a><div class="date" title="2017-07-25 09:25"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom121429">
<div class="phpcode"><code><span class="html">
Object handles in PHP are kind of Java References (not C++ references : references are aliases in C++).</span>
</code></div>
  </div>
 </div></div>

 <div class="foot"><a href="/manual/add-note.php?sect=language.oop5.basic&amp;redirect=https://www.php.net/manual/pt_BR/language.oop5.basic.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></div>
</section>    </section><!-- layout-content -->
        <aside class='layout-menu'>

        <ul class='parent-menu-list'>
                                    <li>
                <a href="language.oop5.php">Classes e Objetos</a>

                                    <ul class='child-menu-list'>

                                                <li class="">
                            <a href="oop5.intro.php" title="Introdu&ccedil;&atilde;o">Introdu&ccedil;&atilde;o</a>
                        </li>
                                                <li class="current">
                            <a href="language.oop5.basic.php" title="O b&aacute;sico">O b&aacute;sico</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.properties.php" title="Propriedades">Propriedades</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.constants.php" title="Constantes do Objeto">Constantes do Objeto</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.autoload.php" title="Autoloading Classes">Autoloading Classes</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.decon.php" title="Construtores e Destrutores">Construtores e Destrutores</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.visibility.php" title="Visibilidade">Visibilidade</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.inheritance.php" title="Heran&ccedil;a de Objetos=">Heran&ccedil;a de Objetos=</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.paamayim-nekudotayim.php" title="Operador de Resolu&ccedil;&atilde;o de Escopo (::)">Operador de Resolu&ccedil;&atilde;o de Escopo (::)</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.static.php" title="Palavra-&#8203;Chave 'static'">Palavra-&#8203;Chave 'static'</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.abstract.php" title="Abstra&ccedil;&atilde;o de Classes">Abstra&ccedil;&atilde;o de Classes</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.interfaces.php" title="Interfaces de Objetos">Interfaces de Objetos</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.traits.php" title="Traits">Traits</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.anonymous.php" title="Classes an&ocirc;nimas">Classes an&ocirc;nimas</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.overloading.php" title="Sobrecarga">Sobrecarga</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.iterations.php" title="Itera&ccedil;&atilde;o de Objetos">Itera&ccedil;&atilde;o de Objetos</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.magic.php" title="M&eacute;todos M&aacute;gicos">M&eacute;todos M&aacute;gicos</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.final.php" title="final">final</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.cloning.php" title="Clonando objetos">Clonando objetos</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.object-comparison.php" title="Comparando objetos">Comparando objetos</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.typehinting.php" title="Type Hinting">Type Hinting</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.late-static-bindings.php" title="Late Static Bindings">Late Static Bindings</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.references.php" title="Objetos e Refer&ecirc;ncias">Objetos e Refer&ecirc;ncias</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.serialization.php" title="Serializa&ccedil;&atilde;o de Objetos -&#8203; objetos em sess&atilde;o">Serializa&ccedil;&atilde;o de Objetos -&#8203; objetos em sess&atilde;o</a>
                        </li>
                                                <li class="">
                            <a href="language.oop5.changelog.php" title="Log de modifica&ccedil;&otilde;es da POO">Log de modifica&ccedil;&otilde;es da POO</a>
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
