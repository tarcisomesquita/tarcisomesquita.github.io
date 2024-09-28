<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="pt_BR">
<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: Objetos - Manual </title>

 <link rel="shortcut icon" href="https://www.php.net/favicon.ico">
 <link rel="search" type="application/opensearchdescription+xml" href="http://php.net/phpnetimprovedsearch.src" title="Add PHP.net search">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/releases/feed.php" title="PHP Release feed">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/feed.atom" title="PHP: Hypertext Preprocessor">

 <link rel="canonical" href="https://www.php.net/manual/pt_BR/language.types.object.php">
 <link rel="shorturl" href="https://www.php.net/types.object">
 <link rel="alternate" href="https://www.php.net/types.object" hreflang="x-default">

 <link rel="contents" href="https://www.php.net/manual/pt_BR/index.php">
 <link rel="index" href="https://www.php.net/manual/pt_BR/language.types.php">
 <link rel="prev" href="https://www.php.net/manual/pt_BR/language.types.iterable.php">
 <link rel="next" href="https://www.php.net/manual/pt_BR/language.types.resource.php">

 <link rel="alternate" href="https://www.php.net/manual/en/language.types.object.php" hreflang="en">
 <link rel="alternate" href="https://www.php.net/manual/pt_BR/language.types.object.php" hreflang="pt_BR">
 <link rel="alternate" href="https://www.php.net/manual/zh/language.types.object.php" hreflang="zh">
 <link rel="alternate" href="https://www.php.net/manual/fr/language.types.object.php" hreflang="fr">
 <link rel="alternate" href="https://www.php.net/manual/de/language.types.object.php" hreflang="de">
 <link rel="alternate" href="https://www.php.net/manual/ja/language.types.object.php" hreflang="ja">
 <link rel="alternate" href="https://www.php.net/manual/ro/language.types.object.php" hreflang="ro">
 <link rel="alternate" href="https://www.php.net/manual/ru/language.types.object.php" hreflang="ru">
 <link rel="alternate" href="https://www.php.net/manual/es/language.types.object.php" hreflang="es">
 <link rel="alternate" href="https://www.php.net/manual/tr/language.types.object.php" hreflang="tr">

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

 <base href="https://www.php.net/manual/pt_BR/language.types.object.php">

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
        <a href="language.types.resource.php">
          Recursos &raquo;
        </a>
      </div>
              <div class="prev">
        <a href="language.types.iterable.php">
          &laquo; Iterables        </a>
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
            <option value='en/language.types.object.php'>English</option>
            <option value='pt_BR/language.types.object.php' selected="selected">Brazilian Portuguese</option>
            <option value='zh/language.types.object.php'>Chinese (Simplified)</option>
            <option value='fr/language.types.object.php'>French</option>
            <option value='de/language.types.object.php'>German</option>
            <option value='ja/language.types.object.php'>Japanese</option>
            <option value='ro/language.types.object.php'>Romanian</option>
            <option value='ru/language.types.object.php'>Russian</option>
            <option value='es/language.types.object.php'>Spanish</option>
            <option value='tr/language.types.object.php'>Turkish</option>
            <option value="help-translate.php">Other</option>
          </select>
        </fieldset>
      </form>
    </div>
    <div class="edit-bug">
      <a href="https://edit.php.net/?project=PHP&amp;perm=pt_BR/language.types.object.php">Edit</a>
      <a href="https://bugs.php.net/report.php?bug_type=Documentation+problem&amp;manpage=language.types.object">Report a Bug</a>
    </div>
  </div><div id="language.types.object" class="sect1">
 <h2 class="title">Objetos</h2>

 <div class="sect2" id="language.types.object.init">
  <h3 class="title">Inicialização de objetos</h3>

  <p class="para">
   Para criar um novo <span class="type"><span class="type objeto">objeto</span></span>, utilize a instrução <em>new</em>
   para instanciar uma classe:
  </p>

  <div class="informalexample">
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br /></span><span style="color: #007700">class&nbsp;</span><span style="color: #0000BB">foo<br /></span><span style="color: #007700">{<br />&nbsp;&nbsp;&nbsp;&nbsp;function&nbsp;</span><span style="color: #0000BB">do_foo</span><span style="color: #007700">()<br />&nbsp;&nbsp;&nbsp;&nbsp;{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #DD0000">"Doing&nbsp;foo."</span><span style="color: #007700">;<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}<br /><br /></span><span style="color: #0000BB">$bar&nbsp;</span><span style="color: #007700">=&nbsp;new&nbsp;</span><span style="color: #0000BB">foo</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$bar</span><span style="color: #007700">-&gt;</span><span style="color: #0000BB">do_foo</span><span style="color: #007700">();<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>

  <p class="simpara">
   Para uma discussão completa, veja o capítulo
   <a href="language.oop5.php" class="link">Classes e Objetos</a>.
  </p>

 </div>

 <div class="sect2" id="language.types.object.casting">
  <h3 class="title">Convertendo para objetos</h3>

  <p class="para">
   Se um <span class="type"><span class="type objeto">objeto</span></span> é convertido para um <span class="type"><span class="type objeto">objeto</span></span>, ele não é
   modificado. Se um valor de qualquer outro tipo é convertido para um
   <span class="type"><span class="type objeto">objeto</span></span>, uma nova instância da classe interna <em>stdClass</em>
   é criada. Se o valor for <strong><code>NULL</code></strong>, a nova instância será vazia.
   Um <span class="type"><a href="language.types.array.php" class="type array">array</a></span> é convertido para um <span class="type"><span class="type objeto">objeto</span></span> com as propriedades
   nomeadas pelas chaves e os valores correspondentes, com exceção de chaves numéricas
   que ficarão inacessíveis a menos que sejam iteradas.
  </p>

  <div class="informalexample">
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$obj&nbsp;</span><span style="color: #007700">=&nbsp;(object)&nbsp;array(</span><span style="color: #DD0000">'1'&nbsp;</span><span style="color: #007700">=&gt;&nbsp;</span><span style="color: #DD0000">'foo'</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(isset(</span><span style="color: #0000BB">$obj</span><span style="color: #007700">-&gt;{</span><span style="color: #DD0000">'1'</span><span style="color: #007700">}));&nbsp;</span><span style="color: #FF8000">//&nbsp;exibe&nbsp;'bool(true)'&nbsp;a&nbsp;partir&nbsp;do&nbsp;PHP&nbsp;7.2.0;&nbsp;antes&nbsp;exibia&nbsp;'bool(false)'<br /></span><span style="color: #0000BB">var_dump</span><span style="color: #007700">(</span><span style="color: #0000BB">key</span><span style="color: #007700">(</span><span style="color: #0000BB">$obj</span><span style="color: #007700">));&nbsp;</span><span style="color: #FF8000">//&nbsp;exibe&nbsp;'string(1)&nbsp;"1"'&nbsp;a&nbsp;partir&nbsp;do&nbsp;PHP&nbsp;7.2.0;&nbsp;antes&nbsp;exibia&nbsp;'int(1)'<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>

  <p class="para">
   Para qualquer outro valor, uma propriedade chamada
   <em>scalar</em> conterá o valor.
  </p>

  <div class="informalexample">
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$obj&nbsp;</span><span style="color: #007700">=&nbsp;(object)&nbsp;</span><span style="color: #DD0000">'ciao'</span><span style="color: #007700">;<br />echo&nbsp;</span><span style="color: #0000BB">$obj</span><span style="color: #007700">-&gt;</span><span style="color: #0000BB">scalar</span><span style="color: #007700">;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;exibe&nbsp;'ciao'<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>

 </div>
</div>
<section id="usernotes">
 <div class="head">
  <span class="action"><a href="/manual/add-note.php?sect=language.types.object&amp;redirect=https://www.php.net/manual/pt_BR/language.types.object.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></span>
  <h3 class="title">User Contributed Notes <span class="count">27 notes</span></h3>
 </div><div id="allnotes">
  <div class="note" id="107071">  <div class="votes">
    <div id="Vu107071">
    <a href="/manual/vote-note.php?id=107071&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd107071">
    <a href="/manual/vote-note.php?id=107071&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V107071" title="75% like this...">
    484
    </div>
  </div>
  <a href="#107071" class="name">
  <strong class="user"><em>helpful at stranger dot com</em></strong></a><a class="genanchor" href="#107071"> &para;</a><div class="date" title="2012-01-04 01:15"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom107071">
<div class="phpcode"><code><span class="html">
By far the easiest and correct way to instantiate an empty generic php object that you can then modify for whatever purpose you choose:<br /><br /><span class="default">&lt;?php $genericObject </span><span class="keyword">= new </span><span class="default">stdClass</span><span class="keyword">(); </span><span class="default">?&gt;<br /></span><br />I had the most difficult time finding this, hopefully it will help someone else!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="118679">  <div class="votes">
    <div id="Vu118679">
    <a href="/manual/vote-note.php?id=118679&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd118679">
    <a href="/manual/vote-note.php?id=118679&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V118679" title="73% like this...">
    190
    </div>
  </div>
  <a href="#118679" class="name">
  <strong class="user"><em>Anthony</em></strong></a><a class="genanchor" href="#118679"> &para;</a><div class="date" title="2016-01-18 10:36"><strong>3 years ago</strong></div>
  <div class="text" id="Hcom118679">
<div class="phpcode"><code><span class="html">
In PHP 7 there are a few ways to create an empty object:<br /><br /><span class="default">&lt;?php<br />$obj1 </span><span class="keyword">= new \</span><span class="default">stdClass</span><span class="keyword">; </span><span class="comment">// Instantiate stdClass object<br /></span><span class="default">$obj2 </span><span class="keyword">= new class{}; </span><span class="comment">// Instantiate anonymous class<br /></span><span class="default">$obj3 </span><span class="keyword">= (object)[]; </span><span class="comment">// Cast empty array to object<br /><br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$obj1</span><span class="keyword">); </span><span class="comment">// object(stdClass)#1 (0) {}<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$obj2</span><span class="keyword">); </span><span class="comment">// object(class@anonymous)#2 (0) {}<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$obj3</span><span class="keyword">); </span><span class="comment">// object(stdClass)#3 (0) {}<br /></span><span class="default">?&gt;<br /></span><br />$obj1 and $obj3 are the same type, but $obj1 !== $obj3. Also, all three will json_encode() to a simple JS object {}:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">echo </span><span class="default">json_encode</span><span class="keyword">([<br />&nbsp; &nbsp; new \</span><span class="default">stdClass</span><span class="keyword">,<br />&nbsp; &nbsp; new class{},<br />&nbsp; &nbsp; (object)[],<br />]);<br /></span><span class="default">?&gt;<br /></span><br />Outputs: [{},{},{}]</span>
</code></div>
  </div>
 </div>
  <div class="note" id="121856">  <div class="votes">
    <div id="Vu121856">
    <a href="/manual/vote-note.php?id=121856&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd121856">
    <a href="/manual/vote-note.php?id=121856&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V121856" title="62% like this...">
    4
    </div>
  </div>
  <a href="#121856" class="name">
  <strong class="user"><em>aditycse at gmail dot com</em></strong></a><a class="genanchor" href="#121856"> &para;</a><div class="date" title="2017-11-10 04:00"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom121856">
<div class="phpcode"><code><span class="html">
<span class="default">&lt;?php<br /><br /></span><span class="comment">/**<br /> * Used for checking empty objects/array<br /> * @uses How to check empty objects and array in php code<br /> * @author Aditya Mehrotra&lt;aditycse@gmail.com&gt;<br /> */<br /><br />/**<br /> * Empty class<br /> */<br /></span><span class="keyword">class </span><span class="default">EmptyClass </span><span class="keyword">{<br />&nbsp; &nbsp; <br />}<br /><br /></span><span class="default">$obj </span><span class="keyword">= new </span><span class="default">stdClass</span><span class="keyword">();<br /></span><span class="comment">//or any other class empty object <br /></span><span class="default">$emptyClassObj </span><span class="keyword">= new </span><span class="default">EmptyClass</span><span class="keyword">();<br /></span><span class="default">$array </span><span class="keyword">= array();<br /><br />if (empty(</span><span class="default">$array</span><span class="keyword">)) {<br />&nbsp; &nbsp; echo </span><span class="string">'array is empty'</span><span class="keyword">; </span><span class="comment">//expected result<br /></span><span class="keyword">} else {<br />&nbsp; &nbsp; echo </span><span class="string">'array is not empty'</span><span class="keyword">; </span><span class="comment">//unexpected result<br /></span><span class="keyword">}<br />echo </span><span class="string">"&lt;br&gt;"</span><span class="keyword">;<br /><br />if (empty(</span><span class="default">$obj</span><span class="keyword">)) {<br />&nbsp; &nbsp; echo </span><span class="string">'object is empty'</span><span class="keyword">; </span><span class="comment">//expected result<br /></span><span class="keyword">} else {<br />&nbsp; &nbsp; echo </span><span class="string">'object is not empty'</span><span class="keyword">; </span><span class="comment">//unexpected result<br /></span><span class="keyword">}<br />echo </span><span class="string">"&lt;br&gt;"</span><span class="keyword">;<br /><br />if (empty(</span><span class="default">$emptyClassObj</span><span class="keyword">)) {<br />&nbsp; &nbsp; echo </span><span class="string">'EmptyClass is empty'</span><span class="keyword">; </span><span class="comment">//expected result<br /></span><span class="keyword">} else {<br />&nbsp; &nbsp; echo </span><span class="string">'EmptyClass is not empty'</span><span class="keyword">; </span><span class="comment">//unexpected result<br /></span><span class="keyword">}<br />echo </span><span class="string">"&lt;br&gt;"</span><span class="keyword">;<br /><br /></span><span class="comment">//Result SET 1<br />//array is empty&nbsp; &nbsp; &nbsp; =&gt; expected result<br />//object is not empty =&gt; ouch what happened<br />//EmptyClass is not empty =&gt; ouch what happened<br /><br />/**<br /> * So what we do for checking empty object<br /> * @solution use any known property or check property count<br /> * Or you can use below method<br /> * Count function will not return 0 in empty object<br /> */<br /><br />//Below line print "Object count:1"<br /></span><span class="keyword">echo </span><span class="string">'Object count:' </span><span class="keyword">. </span><span class="default">count</span><span class="keyword">(</span><span class="default">$obj</span><span class="keyword">);<br /><br />echo </span><span class="string">"&lt;br&gt;"</span><span class="keyword">;<br /><br /></span><span class="comment">/**<br /> * This function is used to get object item counts<br /> * @function getCount<br /> * @access public<br /> * @param object|array $var<br /> * @return integer<br /> */<br /></span><span class="keyword">function </span><span class="default">getCount</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">) {<br />&nbsp; &nbsp; </span><span class="default">$count </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">;<br />&nbsp; &nbsp; if (</span><span class="default">is_array</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">) || </span><span class="default">is_object</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; foreach (</span><span class="default">$var </span><span class="keyword">as </span><span class="default">$value</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$count</span><span class="keyword">++;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; unset(</span><span class="default">$value</span><span class="keyword">);<br />&nbsp; &nbsp; return </span><span class="default">$count</span><span class="keyword">;<br />}<br /><br /></span><span class="comment">//Running code again with new logic<br /></span><span class="keyword">if (</span><span class="default">getCount</span><span class="keyword">(</span><span class="default">$array</span><span class="keyword">) === </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; echo </span><span class="string">'array is empty'</span><span class="keyword">; </span><span class="comment">//expected result<br /></span><span class="keyword">} else {<br />&nbsp; &nbsp; echo </span><span class="string">'array is not empty'</span><span class="keyword">; </span><span class="comment">//unexpected result<br /></span><span class="keyword">}<br />echo </span><span class="string">"&lt;br&gt;"</span><span class="keyword">;<br /><br />if (</span><span class="default">getCount</span><span class="keyword">(</span><span class="default">$obj</span><span class="keyword">) === </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; echo </span><span class="string">'object is empty'</span><span class="keyword">; </span><span class="comment">//expected result<br /></span><span class="keyword">} else {<br />&nbsp; &nbsp; echo </span><span class="string">'object is not empty'</span><span class="keyword">; </span><span class="comment">//unexpected result<br /></span><span class="keyword">}<br /><br />echo </span><span class="string">"&lt;br&gt;"</span><span class="keyword">;<br /><br />if (</span><span class="default">getCount</span><span class="keyword">(</span><span class="default">$emptyClassObj</span><span class="keyword">) === </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; echo </span><span class="string">'EmptyClass is empty'</span><span class="keyword">; </span><span class="comment">//expected result<br /></span><span class="keyword">} else {<br />&nbsp; &nbsp; echo </span><span class="string">'EmptyClass is not empty'</span><span class="keyword">; </span><span class="comment">//unexpected result<br /></span><span class="keyword">}<br /><br /></span><span class="comment">//Result SET 2<br />//array is empty&nbsp; &nbsp; =&gt; expected result&nbsp; ##everything is all right<br />//object is empty&nbsp;&nbsp; =&gt; expected result&nbsp; ##everything is all right<br />//EmptyClass is empty&nbsp;&nbsp; =&gt; expected result&nbsp; ##everything is all right</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="117149">  <div class="votes">
    <div id="Vu117149">
    <a href="/manual/vote-note.php?id=117149&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd117149">
    <a href="/manual/vote-note.php?id=117149&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V117149" title="59% like this...">
    37
    </div>
  </div>
  <a href="#117149" class="name">
  <strong class="user"><em>twitter/matt2000</em></strong></a><a class="genanchor" href="#117149"> &para;</a><div class="date" title="2015-04-21 09:28"><strong>4 years ago</strong></div>
  <div class="text" id="Hcom117149">
<div class="phpcode"><code><span class="html">
As of PHP 5.4, we can create stdClass objects with some properties and values using the more beautiful form:<br /><br /><span class="default">&lt;?php<br />&nbsp; $object </span><span class="keyword">= (object) [<br />&nbsp; &nbsp; </span><span class="string">'propertyOne' </span><span class="keyword">=&gt; </span><span class="string">'foo'</span><span class="keyword">,<br />&nbsp; &nbsp; </span><span class="string">'propertyTwo' </span><span class="keyword">=&gt; </span><span class="default">42</span><span class="keyword">,<br />&nbsp; ];<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="114442">  <div class="votes">
    <div id="Vu114442">
    <a href="/manual/vote-note.php?id=114442&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd114442">
    <a href="/manual/vote-note.php?id=114442&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V114442" title="57% like this...">
    40
    </div>
  </div>
  <a href="#114442" class="name">
  <strong class="user"><em>Ashley Dambra</em></strong></a><a class="genanchor" href="#114442"> &para;</a><div class="date" title="2014-02-21 06:38"><strong>5 years ago</strong></div>
  <div class="text" id="Hcom114442">
<div class="phpcode"><code><span class="html">
Here a new updated version of 'stdObject' class. It's very useful when extends to controller on MVC design pattern, user can create it's own class.<br /><br />Hope it help you.<br /><br /> <span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">stdObject </span><span class="keyword">{<br />&nbsp; &nbsp; public function </span><span class="default">__construct</span><span class="keyword">(array </span><span class="default">$arguments </span><span class="keyword">= array()) {<br />&nbsp; &nbsp; &nbsp; &nbsp; if (!empty(</span><span class="default">$arguments</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; foreach (</span><span class="default">$arguments </span><span class="keyword">as </span><span class="default">$property </span><span class="keyword">=&gt; </span><span class="default">$argument</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;{</span><span class="default">$property</span><span class="keyword">} = </span><span class="default">$argument</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; public function </span><span class="default">__call</span><span class="keyword">(</span><span class="default">$method</span><span class="keyword">, </span><span class="default">$arguments</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arguments </span><span class="keyword">= </span><span class="default">array_merge</span><span class="keyword">(array(</span><span class="string">"stdObject" </span><span class="keyword">=&gt; </span><span class="default">$this</span><span class="keyword">), </span><span class="default">$arguments</span><span class="keyword">); </span><span class="comment">// Note: method argument 0 will always referred to the main class ($this).<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">if (isset(</span><span class="default">$this</span><span class="keyword">-&gt;{</span><span class="default">$method</span><span class="keyword">}) &amp;&amp; </span><span class="default">is_callable</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">-&gt;{</span><span class="default">$method</span><span class="keyword">})) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">call_user_func_array</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">-&gt;{</span><span class="default">$method</span><span class="keyword">}, </span><span class="default">$arguments</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; throw new </span><span class="default">Exception</span><span class="keyword">(</span><span class="string">"Fatal error: Call to undefined method stdObject::</span><span class="keyword">{</span><span class="default">$method</span><span class="keyword">}</span><span class="string">()"</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />}<br /><br /></span><span class="comment">// Usage.<br /><br /></span><span class="default">$obj </span><span class="keyword">= new </span><span class="default">stdObject</span><span class="keyword">();<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">name </span><span class="keyword">= </span><span class="string">"Nick"</span><span class="keyword">;<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">surname </span><span class="keyword">= </span><span class="string">"Doe"</span><span class="keyword">;<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">age </span><span class="keyword">= </span><span class="default">20</span><span class="keyword">;<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">adresse </span><span class="keyword">= </span><span class="default">null</span><span class="keyword">;<br /><br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">getInfo </span><span class="keyword">= function(</span><span class="default">$stdObject</span><span class="keyword">) { </span><span class="comment">// $stdObject referred to this object (stdObject).<br />&nbsp; &nbsp; </span><span class="keyword">echo </span><span class="default">$stdObject</span><span class="keyword">-&gt;</span><span class="default">name </span><span class="keyword">. </span><span class="string">" " </span><span class="keyword">. </span><span class="default">$stdObject</span><span class="keyword">-&gt;</span><span class="default">surname </span><span class="keyword">. </span><span class="string">" have " </span><span class="keyword">. </span><span class="default">$stdObject</span><span class="keyword">-&gt;</span><span class="default">age </span><span class="keyword">. </span><span class="string">" yrs old. And live in " </span><span class="keyword">. </span><span class="default">$stdObject</span><span class="keyword">-&gt;</span><span class="default">adresse</span><span class="keyword">;<br />};<br /><br /></span><span class="default">$func </span><span class="keyword">= </span><span class="string">"setAge"</span><span class="keyword">;<br /></span><span class="default">$obj</span><span class="keyword">-&gt;{</span><span class="default">$func</span><span class="keyword">} = function(</span><span class="default">$stdObject</span><span class="keyword">, </span><span class="default">$age</span><span class="keyword">) { </span><span class="comment">// $age is the first parameter passed when calling this method.<br />&nbsp; &nbsp; </span><span class="default">$stdObject</span><span class="keyword">-&gt;</span><span class="default">age </span><span class="keyword">= </span><span class="default">$age</span><span class="keyword">;<br />};<br /><br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">setAge</span><span class="keyword">(</span><span class="default">24</span><span class="keyword">); </span><span class="comment">// Parameter value 24 is passing to the $age argument in method 'setAge()'.<br /><br />// Create dynamic method. Here i'm generating getter and setter dynimically<br />// Beware: Method name are case sensitive.<br /></span><span class="keyword">foreach (</span><span class="default">$obj </span><span class="keyword">as </span><span class="default">$func_name </span><span class="keyword">=&gt; </span><span class="default">$value</span><span class="keyword">) {<br />&nbsp; &nbsp; if (!</span><span class="default">$value </span><span class="keyword">instanceOf </span><span class="default">Closure</span><span class="keyword">) {<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$obj</span><span class="keyword">-&gt;{</span><span class="string">"set" </span><span class="keyword">. </span><span class="default">ucfirst</span><span class="keyword">(</span><span class="default">$func_name</span><span class="keyword">)} = function(</span><span class="default">$stdObject</span><span class="keyword">, </span><span class="default">$value</span><span class="keyword">) use (</span><span class="default">$func_name</span><span class="keyword">) {&nbsp; </span><span class="comment">// Note: you can also use keyword 'use' to bind parent variables.<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$stdObject</span><span class="keyword">-&gt;{</span><span class="default">$func_name</span><span class="keyword">} = </span><span class="default">$value</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; };<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$obj</span><span class="keyword">-&gt;{</span><span class="string">"get" </span><span class="keyword">. </span><span class="default">ucfirst</span><span class="keyword">(</span><span class="default">$func_name</span><span class="keyword">)} = function(</span><span class="default">$stdObject</span><span class="keyword">) use (</span><span class="default">$func_name</span><span class="keyword">) {&nbsp; </span><span class="comment">// Note: you can also use keyword 'use' to bind parent variables.<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">return </span><span class="default">$stdObject</span><span class="keyword">-&gt;{</span><span class="default">$func_name</span><span class="keyword">};<br />&nbsp; &nbsp; &nbsp; &nbsp; };<br /><br />&nbsp; &nbsp; }<br />}<br /><br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">setName</span><span class="keyword">(</span><span class="string">"John"</span><span class="keyword">);<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">setAdresse</span><span class="keyword">(</span><span class="string">"Boston"</span><span class="keyword">);<br /><br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">getInfo</span><span class="keyword">();<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="118979">  <div class="votes">
    <div id="Vu118979">
    <a href="/manual/vote-note.php?id=118979&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd118979">
    <a href="/manual/vote-note.php?id=118979&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V118979" title="56% like this...">
    14
    </div>
  </div>
  <a href="#118979" class="name">
  <strong class="user"><em>developer dot amankr at gmail dot com  (Aman  Kuma)</em></strong></a><a class="genanchor" href="#118979"> &para;</a><div class="date" title="2016-03-11 10:27"><strong>3 years ago</strong></div>
  <div class="text" id="Hcom118979">
<div class="phpcode"><code><span class="html">
&lt;!--Example shows how to convert array to stdClass Object and how to access its value for display --&gt;<br /><span class="default">&lt;?php <br />$num </span><span class="keyword">= array(</span><span class="string">"Garha"</span><span class="keyword">,</span><span class="string">"sitamarhi"</span><span class="keyword">,</span><span class="string">"canada"</span><span class="keyword">,</span><span class="string">"patna"</span><span class="keyword">); </span><span class="comment">//create an array<br /></span><span class="default">$obj </span><span class="keyword">= (object)</span><span class="default">$num</span><span class="keyword">; </span><span class="comment">//change array to stdClass object <br /><br /></span><span class="keyword">echo </span><span class="string">"&lt;pre&gt;"</span><span class="keyword">;<br /></span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$obj</span><span class="keyword">); </span><span class="comment">//stdClass Object created by casting of array <br /><br /></span><span class="default">$newobj </span><span class="keyword">= new </span><span class="default">stdClass</span><span class="keyword">();</span><span class="comment">//create a new <br /></span><span class="default">$newobj</span><span class="keyword">-&gt;</span><span class="default">name </span><span class="keyword">= </span><span class="string">"India"</span><span class="keyword">;<br /></span><span class="default">$newobj</span><span class="keyword">-&gt;</span><span class="default">work </span><span class="keyword">= </span><span class="string">"Development"</span><span class="keyword">;<br /></span><span class="default">$newobj</span><span class="keyword">-&gt;</span><span class="default">address</span><span class="keyword">=</span><span class="string">"patna"</span><span class="keyword">;<br /><br /></span><span class="default">$new </span><span class="keyword">= (array)</span><span class="default">$newobj</span><span class="keyword">;</span><span class="comment">//convert stdClass to array<br /></span><span class="keyword">echo </span><span class="string">"&lt;pre&gt;"</span><span class="keyword">;<br /></span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$new</span><span class="keyword">); </span><span class="comment">//print new object<br /><br />##How deals with Associative Array<br /><br /></span><span class="default">$test </span><span class="keyword">= [</span><span class="default">Details</span><span class="keyword">=&gt;[</span><span class="string">'name'</span><span class="keyword">,</span><span class="string">'roll number'</span><span class="keyword">,</span><span class="string">'college'</span><span class="keyword">,</span><span class="string">'mobile'</span><span class="keyword">],</span><span class="default">values</span><span class="keyword">=&gt;[</span><span class="string">'Naman Kumar'</span><span class="keyword">,</span><span class="string">'100790310868'</span><span class="keyword">,</span><span class="string">'Pune college'</span><span class="keyword">,</span><span class="string">'9988707202'</span><span class="keyword">]];<br /></span><span class="default">$val </span><span class="keyword">= </span><span class="default">json_decode</span><span class="keyword">(</span><span class="default">json_encode</span><span class="keyword">(</span><span class="default">$test</span><span class="keyword">),</span><span class="default">false</span><span class="keyword">);</span><span class="comment">//convert array into stdClass object<br /><br /></span><span class="keyword">echo </span><span class="string">"&lt;pre&gt;"</span><span class="keyword">;<br /></span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$val</span><span class="keyword">);<br /><br />echo ((</span><span class="default">is_array</span><span class="keyword">(</span><span class="default">$val</span><span class="keyword">) == </span><span class="default">true </span><span class="keyword">?&nbsp; </span><span class="default">1 </span><span class="keyword">: </span><span class="default">0 </span><span class="keyword">) == </span><span class="default">1 </span><span class="keyword">? </span><span class="string">"array" </span><span class="keyword">: </span><span class="string">"not an array" </span><span class="keyword">).</span><span class="string">"&lt;/br&gt;"</span><span class="keyword">; </span><span class="comment">// check whether it is array or not<br /></span><span class="keyword">echo ((</span><span class="default">is_object</span><span class="keyword">(</span><span class="default">$val</span><span class="keyword">) == </span><span class="default">true </span><span class="keyword">?&nbsp; </span><span class="default">1 </span><span class="keyword">: </span><span class="default">0 </span><span class="keyword">) == </span><span class="default">1 </span><span class="keyword">? </span><span class="string">"object" </span><span class="keyword">: </span><span class="string">"not an object" </span><span class="keyword">);</span><span class="comment">//check whether it is object or not <br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="90447">  <div class="votes">
    <div id="Vu90447">
    <a href="/manual/vote-note.php?id=90447&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd90447">
    <a href="/manual/vote-note.php?id=90447&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V90447" title="53% like this...">
    10
    </div>
  </div>
  <a href="#90447" class="name">
  <strong class="user"><em>cFreed at orange dot fr</em></strong></a><a class="genanchor" href="#90447"> &para;</a><div class="date" title="2009-04-22 06:21"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom90447">
<div class="phpcode"><code><span class="html">
CAUTION:<br />"Arrays convert to an object with properties named by keys, and corresponding values".<br /><br />This is ALWAYS true, which means that even numeric keys are accepted when converting.<br />But the resulting properties cannot be accessed, since they don't match the variables naming rules.<br /><br />So this:<br /><span class="default">&lt;?php<br />$x </span><span class="keyword">= (object) array(</span><span class="string">'a'</span><span class="keyword">=&gt;</span><span class="string">'A'</span><span class="keyword">, </span><span class="string">'b'</span><span class="keyword">=&gt;</span><span class="string">'B'</span><span class="keyword">, </span><span class="string">'C'</span><span class="keyword">);<br />echo </span><span class="string">'&lt;pre&gt;'</span><span class="keyword">.</span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">, </span><span class="default">true</span><span class="keyword">).</span><span class="string">'&lt;/pre&gt;'</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span>works and displays:<br />stdClass Object<br />(<br />&nbsp; &nbsp; [a] =&gt; A<br />&nbsp; &nbsp; [b] =&gt; B<br />&nbsp; &nbsp; [0] =&gt; C<br />)<br /><br />But this:<br /><span class="default">&lt;?php<br /></span><span class="keyword">echo </span><span class="string">'&lt;br /&gt;'</span><span class="keyword">.</span><span class="default">$x</span><span class="keyword">-&gt;</span><span class="default">a</span><span class="keyword">;<br />echo </span><span class="string">'&lt;br /&gt;'</span><span class="keyword">.</span><span class="default">$x</span><span class="keyword">-&gt;</span><span class="default">b</span><span class="keyword">;<br />echo </span><span class="string">'&lt;br /&gt;'</span><span class="keyword">.</span><span class="default">$x</span><span class="keyword">-&gt;{</span><span class="default">0</span><span class="keyword">}; </span><span class="comment"># (don't use $x-&gt;0, which is obviously a syntax error)<br /></span><span class="default">?&gt;<br /></span>fails and displays:<br />A<br />B<br />Notice: Undefined property: stdClass::$0 in...</span>
</code></div>
  </div>
 </div>
  <div class="note" id="95211">  <div class="votes">
    <div id="Vu95211">
    <a href="/manual/vote-note.php?id=95211&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd95211">
    <a href="/manual/vote-note.php?id=95211&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V95211" title="52% like this...">
    9
    </div>
  </div>
  <a href="#95211" class="name">
  <strong class="user"><em>mailto dot aurelian at gmail dot com</em></strong></a><a class="genanchor" href="#95211"> &para;</a><div class="date" title="2009-12-18 09:56"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom95211">
<div class="phpcode"><code><span class="html">
You can create [recursive] objects with something like:<br /><span class="default">&lt;?php<br />&nbsp; $literalObjectDeclared </span><span class="keyword">= (object) array(<br />&nbsp; &nbsp;&nbsp; </span><span class="string">'foo' </span><span class="keyword">=&gt; (object) array(<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">'bar' </span><span class="keyword">=&gt; </span><span class="string">'baz'</span><span class="keyword">,<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">'pax' </span><span class="keyword">=&gt; </span><span class="string">'vax'<br />&nbsp; &nbsp; &nbsp; </span><span class="keyword">),<br />&nbsp; &nbsp; &nbsp; </span><span class="string">'moo' </span><span class="keyword">=&gt; </span><span class="string">'ui'<br />&nbsp;&nbsp; </span><span class="keyword">);<br />print </span><span class="default">$literalObjectDeclared</span><span class="keyword">-&gt;</span><span class="default">foo</span><span class="keyword">-&gt;</span><span class="default">bar</span><span class="keyword">; </span><span class="comment">// outputs "baz"!<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120494">  <div class="votes">
    <div id="Vu120494">
    <a href="/manual/vote-note.php?id=120494&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120494">
    <a href="/manual/vote-note.php?id=120494&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120494" title="51% like this...">
    1
    </div>
  </div>
  <a href="#120494" class="name">
  <strong class="user"><em>Walter Tross</em></strong></a><a class="genanchor" href="#120494"> &para;</a><div class="date" title="2017-01-20 04:50"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom120494">
<div class="phpcode"><code><span class="html">
If you need to force json_encode() to produce an object even when an array is empty or does not have successive 0-based numeric indices, you can simply convert the array to an object. JSON_FORCE_OBJECT does the same with ALL arrays, which might not be what you want.<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">echo </span><span class="default">json_encode</span><span class="keyword">([[]]), </span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="comment">// output: [[]]<br /><br /></span><span class="keyword">echo </span><span class="default">json_encode</span><span class="keyword">([[]], </span><span class="default">JSON_FORCE_OBJECT</span><span class="keyword">), </span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="comment">// output: {"0":{}}<br /><br /></span><span class="keyword">echo </span><span class="default">json_encode</span><span class="keyword">([(object)[]]), </span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="comment">// output: [{}]<br /><br /></span><span class="keyword">echo </span><span class="default">json_encode</span><span class="keyword">([</span><span class="default">0</span><span class="keyword">=&gt;</span><span class="string">"a"</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">=&gt;</span><span class="string">"b"</span><span class="keyword">, </span><span class="default">9</span><span class="keyword">=&gt;</span><span class="string">"c"</span><span class="keyword">]), </span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="comment">// output: {"0":"a","1":"b","9":"c"}<br /><br /></span><span class="keyword">echo </span><span class="default">json_encode</span><span class="keyword">([</span><span class="default">0</span><span class="keyword">=&gt;</span><span class="string">"a"</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">=&gt;</span><span class="string">"b"</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">=&gt;</span><span class="string">"c"</span><span class="keyword">]), </span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="comment">// output: ["a","b","c"]<br /><br /></span><span class="keyword">echo </span><span class="default">json_encode</span><span class="keyword">((object)[</span><span class="default">0</span><span class="keyword">=&gt;</span><span class="string">"a"</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">=&gt;</span><span class="string">"b"</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">=&gt;</span><span class="string">"c"</span><span class="keyword">]), </span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="comment">// output: {"0":"a","1":"b","2":"c"}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120574">  <div class="votes">
    <div id="Vu120574">
    <a href="/manual/vote-note.php?id=120574&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120574">
    <a href="/manual/vote-note.php?id=120574&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120574" title="51% like this...">
    1
    </div>
  </div>
  <a href="#120574" class="name">
  <strong class="user"><em>brian dot weber1337 at gmail dot com</em></strong></a><a class="genanchor" href="#120574"> &para;</a><div class="date" title="2017-02-02 10:24"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom120574">
<div class="phpcode"><code><span class="html">
In PHP 5+, objects are passed by reference. This has got me into trouble in the past when I've tried to make arrays of objects.<br />For example, I once wrote something like the following code, thinking that I'd get an array of distinct objects. However, this is wrong. This code will create an array of multiple references to the same object.<br /><br /><span class="default">&lt;?php<br />&nbsp; </span><span class="keyword">class </span><span class="default">myNumber<br />&nbsp; </span><span class="keyword">{<br />&nbsp; &nbsp; public </span><span class="default">$value</span><span class="keyword">;<br />&nbsp; }<br /><br />&nbsp; </span><span class="default">$arrayOfMyNumbers </span><span class="keyword">= array();<br />&nbsp; </span><span class="default">$arrayItem </span><span class="keyword">= new </span><span class="default">myNumber</span><span class="keyword">();<br />&nbsp; for( </span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">&lt;</span><span class="default">3</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">++ ) {<br />&nbsp; &nbsp; </span><span class="default">$arrayItem</span><span class="keyword">-&gt;</span><span class="default">value </span><span class="keyword">= </span><span class="default">$i</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$arrayOfMyNumbers</span><span class="keyword">[] = </span><span class="default">$arrayItem</span><span class="keyword">;<br />&nbsp; }<br /><br />&nbsp; </span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$arrayOfMyNumbers</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />output:<br />array(3) {<br />&nbsp; [0]=&gt;<br />&nbsp; object(myNumber)#1 (1) {<br />&nbsp; &nbsp; ["value"]=&gt;<br />&nbsp; &nbsp; int(4)<br />&nbsp; }<br />&nbsp; [1]=&gt;<br />&nbsp; object(myNumber)#1 (1) {<br />&nbsp; &nbsp; ["value"]=&gt;<br />&nbsp; &nbsp; int(4)<br />&nbsp; }<br />&nbsp; [2]=&gt;<br />&nbsp; object(myNumber)#1 (1) {<br />&nbsp; &nbsp; ["value"]=&gt;<br />&nbsp; &nbsp; int(4)<br />&nbsp; }<br />}<br /><br />notice that the value at each index in the array is the same. That is because the array is just 3 references to the same object, but we change the property of this object every time the for loop runs. This isn't very useful. Instead, I've changed the code below so that it will create an array with three distinct references to three distinct objects. (if you're having a hard time understanding references, think of this as an array of objects, and that this is just the syntax you have to use.)<br /><br /><span class="default">&lt;?php<br />&nbsp; </span><span class="keyword">class </span><span class="default">myNumber<br />&nbsp; </span><span class="keyword">{<br />&nbsp; &nbsp; public </span><span class="default">$value</span><span class="keyword">;<br />&nbsp; }<br /><br />&nbsp; </span><span class="default">$arrayOfMyNumbers </span><span class="keyword">= array();<br />&nbsp; for( </span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">&lt;</span><span class="default">3</span><span class="keyword">; </span><span class="default">$i</span><span class="keyword">++ ) {<br />&nbsp; &nbsp; </span><span class="default">$arrayItem </span><span class="keyword">= new </span><span class="default">myNumber</span><span class="keyword">();<br />&nbsp; &nbsp; </span><span class="default">$arrayItem</span><span class="keyword">-&gt;</span><span class="default">value </span><span class="keyword">= </span><span class="default">$i</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$arrayOfMyNumbers</span><span class="keyword">[] = </span><span class="default">$arrayItem</span><span class="keyword">;<br />&nbsp; }<br />&nbsp; <br />&nbsp; </span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$arrayOfMyNumbers</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />output:<br />array(3) {<br />&nbsp; [0]=&gt;<br />&nbsp; object(myNumber)#1 (1) {<br />&nbsp; &nbsp; ["value"]=&gt;<br />&nbsp; &nbsp; int(0)<br />&nbsp; }<br />&nbsp; [1]=&gt;<br />&nbsp; object(myNumber)#2 (1) {<br />&nbsp; &nbsp; ["value"]=&gt;<br />&nbsp; &nbsp; int(1)<br />&nbsp; }<br />&nbsp; [2]=&gt;<br />&nbsp; object(myNumber)#3 (1) {<br />&nbsp; &nbsp; ["value"]=&gt;<br />&nbsp; &nbsp; int(2)<br />&nbsp; }<br />}<br /><br />Notice how the creation of a new object ("$arrayItem = new myNumber();") must happen every time the for loop runs for this to work.<br />This took me forever to figure out, so I hope this helps someone else.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="85237">  <div class="votes">
    <div id="Vu85237">
    <a href="/manual/vote-note.php?id=85237&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd85237">
    <a href="/manual/vote-note.php?id=85237&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V85237" title="52% like this...">
    7
    </div>
  </div>
  <a href="#85237" class="name">
  <strong class="user"><em>Mithras</em></strong></a><a class="genanchor" href="#85237"> &para;</a><div class="date" title="2008-08-21 06:54"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom85237">
<div class="phpcode"><code><span class="html">
In response to harmor: if an array contains another array as a value, you can recursively convert all arrays with:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">arrayToObject</span><span class="keyword">( </span><span class="default">$array </span><span class="keyword">){<br />&nbsp; foreach( </span><span class="default">$array </span><span class="keyword">as </span><span class="default">$key </span><span class="keyword">=&gt; </span><span class="default">$value </span><span class="keyword">){<br />&nbsp; &nbsp; if( </span><span class="default">is_array</span><span class="keyword">( </span><span class="default">$value </span><span class="keyword">) ) </span><span class="default">$array</span><span class="keyword">[ </span><span class="default">$key </span><span class="keyword">] = </span><span class="default">arrayToObject</span><span class="keyword">( </span><span class="default">$value </span><span class="keyword">);<br />&nbsp; }<br />&nbsp; return (object) </span><span class="default">$array</span><span class="keyword">;<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="107755">  <div class="votes">
    <div id="Vu107755">
    <a href="/manual/vote-note.php?id=107755&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd107755">
    <a href="/manual/vote-note.php?id=107755&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V107755" title="50% like this...">
    3
    </div>
  </div>
  <a href="#107755" class="name">
  <strong class="user"><em>qeremy [atta] gmail [dotta] com</em></strong></a><a class="genanchor" href="#107755"> &para;</a><div class="date" title="2012-03-02 12:41"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom107755">
<div class="phpcode"><code><span class="html">
Do you remember some JavaScript implementations?<br /><br />// var timestamp = (new Date).getTime();<br /><br />Now it's possible with PHP 5.4.*;<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">class </span><span class="default">Foo<br /></span><span class="keyword">{<br />&nbsp; &nbsp; public </span><span class="default">$a </span><span class="keyword">= </span><span class="string">"I'm a!"</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$b </span><span class="keyword">= </span><span class="string">"I'm b!"</span><span class="keyword">;<br />&nbsp; &nbsp; public </span><span class="default">$c</span><span class="keyword">;<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; public function </span><span class="default">getB</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">b</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; public function </span><span class="default">setC</span><span class="keyword">(</span><span class="default">$c</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">c </span><span class="keyword">= </span><span class="default">$c</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$this</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; public function </span><span class="default">getC</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">c</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />}<br /><br />print (new </span><span class="default">Foo</span><span class="keyword">)-&gt;</span><span class="default">a</span><span class="keyword">;&nbsp; &nbsp; &nbsp; </span><span class="comment">// I'm a!<br /></span><span class="keyword">print (new </span><span class="default">Foo</span><span class="keyword">)-&gt;</span><span class="default">getB</span><span class="keyword">(); </span><span class="comment">// I'm b!<br /></span><span class="default">?&gt;<br /></span><br />or<br /><br /><span class="default">&lt;?php<br /></span><span class="comment">// $_GET["c"] = "I'm c!";<br /></span><span class="keyword">print (new </span><span class="default">Foo</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp;&nbsp; -&gt;</span><span class="default">setC</span><span class="keyword">(</span><span class="default">$_GET</span><span class="keyword">[</span><span class="string">"c"</span><span class="keyword">])<br />&nbsp; &nbsp; &nbsp;&nbsp; -&gt;</span><span class="default">getC</span><span class="keyword">(); </span><span class="comment">// I'm c!<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="75278">  <div class="votes">
    <div id="Vu75278">
    <a href="/manual/vote-note.php?id=75278&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd75278">
    <a href="/manual/vote-note.php?id=75278&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V75278" title="50% like this...">
    4
    </div>
  </div>
  <a href="#75278" class="name">
  <strong class="user"><em>gabe at fijiwebdesign dot com</em></strong></a><a class="genanchor" href="#75278"> &para;</a><div class="date" title="2007-05-21 09:25"><strong>12 years ago</strong></div>
  <div class="text" id="Hcom75278">
<div class="phpcode"><code><span class="html">
In response to sirbinam.<br />You cannot call a function or method before it exists. In your example, the global instance of stdout is just being passed around to differnet references (pointers). It however exists in the "dump" function scope via the global keyword. <br /><br />The code below works fine and illustrates that "stdout" has been defined before its instantiation. <br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">class </span><span class="default">profiler</span><span class="keyword">{<br />&nbsp; function </span><span class="default">profiler</span><span class="keyword">(){<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">starttime </span><span class="keyword">= </span><span class="default">microtime</span><span class="keyword">();<br />&nbsp; }<br /><br />&nbsp; function </span><span class="default">dump</span><span class="keyword">(){<br />&nbsp; &nbsp; global </span><span class="default">$stdout</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">endtime </span><span class="keyword">= </span><span class="default">microtime</span><span class="keyword">();<br />&nbsp; &nbsp; </span><span class="default">$duration </span><span class="keyword">= </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">endtime </span><span class="keyword">- </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">starttime</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$stdout</span><span class="keyword">-&gt;</span><span class="default">write</span><span class="keyword">(</span><span class="default">$duration</span><span class="keyword">);<br />&nbsp; }<br />}<br /><br />class </span><span class="default">stdout</span><span class="keyword">{<br />&nbsp; function </span><span class="default">write</span><span class="keyword">(</span><span class="default">$msg</span><span class="keyword">){<br />&nbsp; &nbsp; echo </span><span class="default">$msg</span><span class="keyword">;<br />&nbsp; }<br />}<br /><br /></span><span class="default">$stdout </span><span class="keyword">=&amp; new </span><span class="default">stdout</span><span class="keyword">();<br /></span><span class="default">$profiler </span><span class="keyword">=&amp; new </span><span class="default">profiler</span><span class="keyword">();<br /></span><span class="default">$profiler</span><span class="keyword">-&gt;</span><span class="default">dump</span><span class="keyword">();<br /><br /></span><span class="default">?&gt;<br /></span><br />All classes and functions declarations within a scope exist even before the php execution reaches them. It does not matter if you have your classes defined on the first or last line, as long as they are in the same scope as where they are called and are not in a conditional statement that has not been evaluated yet.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="122542">  <div class="votes">
    <div id="Vu122542">
    <a href="/manual/vote-note.php?id=122542&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd122542">
    <a href="/manual/vote-note.php?id=122542&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V122542" title="47% like this...">
    -1
    </div>
  </div>
  <a href="#122542" class="name">
  <strong class="user"><em>dr dot mustafa dot darwish at gmail dot com</em></strong></a><a class="genanchor" href="#122542"> &para;</a><div class="date" title="2018-03-25 12:14"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom122542">
<div class="phpcode"><code><span class="html">
in php 7.2 this code works despite documentation said it gives false<br /><br /><span class="default">&lt;?php<br />$obj </span><span class="keyword">= (object) array(</span><span class="string">'1' </span><span class="keyword">=&gt; </span><span class="string">'foo'</span><span class="keyword">);<br /><br /></span><span class="comment">//output foo<br /></span><span class="keyword">echo </span><span class="default">$obj</span><span class="keyword">-&gt;{</span><span class="string">'1'</span><span class="keyword">};<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="50041">  <div class="votes">
    <div id="Vu50041">
    <a href="/manual/vote-note.php?id=50041&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd50041">
    <a href="/manual/vote-note.php?id=50041&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V50041" title="50% like this...">
    0
    </div>
  </div>
  <a href="#50041" class="name">
  <strong class="user"><em>mortoray at ecircle-ag dot com</em></strong></a><a class="genanchor" href="#50041"> &para;</a><div class="date" title="2005-02-16 02:07"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom50041">
<div class="phpcode"><code><span class="html">
If you use new to create items in an array, you may not get the results you want since the parameters to array will be copies of the original and not references.<br /><br />By Example:<br />class Store {<br />&nbsp; &nbsp; var $item = 3;<br />}<br /><br />&nbsp; &nbsp; $a = array( new Store() );<br />&nbsp; &nbsp; $b = $a;<br />&nbsp; &nbsp; $a[0]-&gt;item = 2;<br />&nbsp; &nbsp; print( "|" . $b[0]-&gt;item . "| &lt;br&gt;" );&nbsp;&nbsp; //shows 3<br /><br />&nbsp; &nbsp; $a = array();<br />&nbsp; &nbsp; $a[] =&amp; new Store();<br />&nbsp; &nbsp; $b = $a;<br />&nbsp; &nbsp; $a[0]-&gt;item = 2;<br />&nbsp; &nbsp; print( "|" . $b[0]-&gt;item . "| &lt;br&gt;" );&nbsp;&nbsp; //shows 2<br /><br />This is extremely important if you intend on passing arrays of classes to functions and expect them to always use the same object instance!<br /><br />Note: The following syntax is desired (or maybe even the default notation should translate as this):<br />&nbsp;&nbsp; $a = array( &amp;new Store() );</span>
</code></div>
  </div>
 </div>
  <div class="note" id="114017">  <div class="votes">
    <div id="Vu114017">
    <a href="/manual/vote-note.php?id=114017&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd114017">
    <a href="/manual/vote-note.php?id=114017&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V114017" title="47% like this...">
    -2
    </div>
  </div>
  <a href="#114017" class="name">
  <strong class="user"><em>wyattstorch42 at outlook dot com</em></strong></a><a class="genanchor" href="#114017"> &para;</a><div class="date" title="2013-12-31 05:07"><strong>6 years ago</strong></div>
  <div class="text" id="Hcom114017">
<div class="phpcode"><code><span class="html">
If you call var_export() on an instance of stdClass, it attempts to export it using ::__set_state(), which, for some reason, is not implemented in stdClass.<br /><br />However, casting an associative array to an object usually produces the same effect (at least, it does in my case). So I wrote an improved_var_export() function to convert instances of stdClass to (object) array () calls. If you choose to export objects of any other class, I'd advise you to implement ::__set_state().<br /><br /><span class="default">&lt;?php<br /></span><span class="comment">/**<br /> * An implementation of var_export() that is compatible with instances<br /> * of stdClass.<br /> * @param mixed $variable The variable you want to export<br /> * @param bool $return If used and set to true, improved_var_export()<br /> *&nbsp; &nbsp;&nbsp; will return the variable representation instead of outputting it.<br /> * @return mixed|null Returns the variable representation when the<br /> *&nbsp; &nbsp;&nbsp; return parameter is used and evaluates to TRUE. Otherwise, this<br /> *&nbsp; &nbsp;&nbsp; function will return NULL.<br /> */<br /></span><span class="keyword">function </span><span class="default">improved_var_export </span><span class="keyword">(</span><span class="default">$variable</span><span class="keyword">, </span><span class="default">$return </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">) {<br />&nbsp; &nbsp; if (</span><span class="default">$variable </span><span class="keyword">instanceof </span><span class="default">stdClass</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$result </span><span class="keyword">= </span><span class="string">'(object) '</span><span class="keyword">.</span><span class="default">improved_var_export</span><span class="keyword">(</span><span class="default">get_object_vars</span><span class="keyword">(</span><span class="default">$variable</span><span class="keyword">), </span><span class="default">true</span><span class="keyword">);<br />&nbsp; &nbsp; } else if (</span><span class="default">is_array</span><span class="keyword">(</span><span class="default">$variable</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$array </span><span class="keyword">= array ();<br />&nbsp; &nbsp; &nbsp; &nbsp; foreach (</span><span class="default">$variable </span><span class="keyword">as </span><span class="default">$key </span><span class="keyword">=&gt; </span><span class="default">$value</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$array</span><span class="keyword">[] = </span><span class="default">var_export</span><span class="keyword">(</span><span class="default">$key</span><span class="keyword">, </span><span class="default">true</span><span class="keyword">).</span><span class="string">' =&gt; '</span><span class="keyword">.</span><span class="default">improved_var_export</span><span class="keyword">(</span><span class="default">$value</span><span class="keyword">, </span><span class="default">true</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$result </span><span class="keyword">= </span><span class="string">'array ('</span><span class="keyword">.</span><span class="default">implode</span><span class="keyword">(</span><span class="string">', '</span><span class="keyword">, </span><span class="default">$array</span><span class="keyword">).</span><span class="string">')'</span><span class="keyword">;<br />&nbsp; &nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$result </span><span class="keyword">= </span><span class="default">var_export</span><span class="keyword">(</span><span class="default">$variable</span><span class="keyword">, </span><span class="default">true</span><span class="keyword">);<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; if (!</span><span class="default">$return</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; print </span><span class="default">$result</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">null</span><span class="keyword">;<br />&nbsp; &nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">$result</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />}<br /><br /></span><span class="comment">// Example usage:<br /></span><span class="default">$obj </span><span class="keyword">= new </span><span class="default">stdClass</span><span class="keyword">;<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">test </span><span class="keyword">= </span><span class="string">'abc'</span><span class="keyword">;<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">other </span><span class="keyword">= </span><span class="default">6.2</span><span class="keyword">;<br /></span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">arr </span><span class="keyword">= array (</span><span class="default">1</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">, </span><span class="default">3</span><span class="keyword">);<br /><br /></span><span class="default">improved_var_export</span><span class="keyword">((object) array (<br />&nbsp; &nbsp; </span><span class="string">'prop1' </span><span class="keyword">=&gt; </span><span class="default">true</span><span class="keyword">,<br />&nbsp; &nbsp; </span><span class="string">'prop2' </span><span class="keyword">=&gt; </span><span class="default">$obj</span><span class="keyword">,<br />&nbsp; &nbsp; </span><span class="string">'assocArray' </span><span class="keyword">=&gt; array (<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">'apple' </span><span class="keyword">=&gt; </span><span class="string">'good'</span><span class="keyword">,<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">'orange' </span><span class="keyword">=&gt; </span><span class="string">'great'<br />&nbsp; &nbsp; </span><span class="keyword">)<br />));<br /><br /></span><span class="comment">/* Output:<br />(object) array ('prop1' =&gt; true, 'prop2' =&gt; (object) array ('test' =&gt; 'abc', 'other' =&gt; 6.2, 'arr' =&gt; array (0 =&gt; 1, 1 =&gt; 2, 2 =&gt; 3)), 'assocArray' =&gt; array ('apple' =&gt; 'good', 'orange' =&gt; 'great'))<br />*/<br /></span><span class="default">?&gt;<br /></span><br />Note: This function spits out a single line of code, which is useful to save in a cache file to include/eval. It isn't formatted for readability. If you want to print a readable version for debugging purposes, then I would suggest print_r() or var_dump().</span>
</code></div>
  </div>
 </div>
  <div class="note" id="68998">  <div class="votes">
    <div id="Vu68998">
    <a href="/manual/vote-note.php?id=68998&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd68998">
    <a href="/manual/vote-note.php?id=68998&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V68998" title="47% like this...">
    -3
    </div>
  </div>
  <a href="#68998" class="name">
  <strong class="user"><em>ludvig dot ericson at gmail dot com</em></strong></a><a class="genanchor" href="#68998"> &para;</a><div class="date" title="2006-08-18 03:35"><strong>13 years ago</strong></div>
  <div class="text" id="Hcom68998">
<div class="phpcode"><code><span class="html">
In reply to the usort thing, you can access a property of an object dynamically by:<br /><span class="default">&lt;?php<br />$obj </span><span class="keyword">= (object)array(</span><span class="string">"Test" </span><span class="keyword">=&gt; </span><span class="string">"bar"</span><span class="keyword">)<br /></span><span class="default">$var </span><span class="keyword">= </span><span class="string">"Test"</span><span class="keyword">;<br />echo </span><span class="default">$obj</span><span class="keyword">-&gt;</span><span class="default">$var</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span>This will output "bar", and do notice I call on -&gt;$var and not just -&gt;var.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="35258">  <div class="votes">
    <div id="Vu35258">
    <a href="/manual/vote-note.php?id=35258&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd35258">
    <a href="/manual/vote-note.php?id=35258&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V35258" title="48% like this...">
    -3
    </div>
  </div>
  <a href="#35258" class="name">
  <strong class="user"><em>info at keltoi-web dot com</em></strong></a><a class="genanchor" href="#35258"> &para;</a><div class="date" title="2003-08-25 02:26"><strong>16 years ago</strong></div>
  <div class="text" id="Hcom35258">
<div class="phpcode"><code><span class="html">
PHP supports recursive type definitions as far as I've tried. The class below (a _very_ simple tree) is an example:<br /><br />class Tree {<br /><br />var $_value = null;<br />var $_children = array();<br /><br />function Tree ($value) {<br />&nbsp; $this-&gt;_value = $value;<br />}<br /><br />function addChild ($value) {<br />&nbsp; $aux_node = new Tree ($value);<br />&nbsp; $this-&gt;_children [] = $aux_node;<br />&nbsp; return $aux_node; <br />}<br />}<br /><br />As you can see, in addChild we reference Tree again...<br /><br />However, you must be careful about references. See the chapter "References explained" for more details.<br /><br />Hope this helps.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="122576">  <div class="votes">
    <div id="Vu122576">
    <a href="/manual/vote-note.php?id=122576&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd122576">
    <a href="/manual/vote-note.php?id=122576&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V122576" title="43% like this...">
    -3
    </div>
  </div>
  <a href="#122576" class="name">
  <strong class="user"><em>Luis</em></strong></a><a class="genanchor" href="#122576"> &para;</a><div class="date" title="2018-04-02 09:17"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom122576">
<div class="phpcode"><code><span class="html">
another way to instantiate an empty generic php object:<br /><br /><span class="default">&lt;?php $dataObj </span><span class="keyword">= </span><span class="default">json_decode</span><span class="keyword">(</span><span class="string">'{}'</span><span class="keyword">); </span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="50770">  <div class="votes">
    <div id="Vu50770">
    <a href="/manual/vote-note.php?id=50770&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd50770">
    <a href="/manual/vote-note.php?id=50770&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V50770" title="46% like this...">
    -5
    </div>
  </div>
  <a href="#50770" class="name">
  <strong class="user"><em>iblun at gmx dot net</em></strong></a><a class="genanchor" href="#50770"> &para;</a><div class="date" title="2005-03-09 05:08"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom50770">
<div class="phpcode"><code><span class="html">
To sort an array, that contains an object, after one fieldname inside the object, im using this function:<br /><br />function objectSort($objectarray, $field)<br />{<br />&nbsp; &nbsp; for ($a=0;$a &lt; (count($objectarray)); $a++)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; for ($b=0;$b &lt; (count($objectarray)); $b++)<br />&nbsp; &nbsp; &nbsp; &nbsp; {&nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if ($objectarray[$a]-&gt;$field &lt; $objectarray[$b]-&gt;$field)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $temp = $objectarray[$a];<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $objectarray[$a] = $objectarray[$b];<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $objectarray[$b] = $temp;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; return $objectarray;<br />}</span>
</code></div>
  </div>
 </div>
  <div class="note" id="101288">  <div class="votes">
    <div id="Vu101288">
    <a href="/manual/vote-note.php?id=101288&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd101288">
    <a href="/manual/vote-note.php?id=101288&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V101288" title="44% like this...">
    -11
    </div>
  </div>
  <a href="#101288" class="name">
  <strong class="user"><em>Cosmitar: mhherrera31 at hotmail</em></strong></a><a class="genanchor" href="#101288"> &para;</a><div class="date" title="2010-12-07 10:47"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom101288">
<div class="phpcode"><code><span class="html">
i would like to share a curious behavior on casted objects. Casting an object from a class with private/protected attributes results a stdClass with a private/protected attribute for get.<br />Example:<br /><span class="default">&lt;?PHP<br /></span><span class="keyword">class </span><span class="default">Foo</span><span class="keyword">{<br /> private </span><span class="default">$priv </span><span class="keyword">= </span><span class="default">1</span><span class="keyword">;<br /> public </span><span class="default">$pub </span><span class="keyword">= </span><span class="default">2</span><span class="keyword">;<br /> public function </span><span class="default">getSimple</span><span class="keyword">(){<br />&nbsp; return (object)(array) </span><span class="default">$this</span><span class="keyword">; </span><span class="comment">//the array cast is to force a stdClass result<br /> </span><span class="keyword">}<br />}<br /></span><span class="default">$bar </span><span class="keyword">= new </span><span class="default">Foo</span><span class="keyword">();<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$bar</span><span class="keyword">-&gt;</span><span class="default">getSimple</span><span class="keyword">();</span><span class="comment">// output: object(stdClass)#3 (2) { ["priv:private"]=&gt; int(1) ["pub"]=&gt; int(2) }<br /><br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$bar</span><span class="keyword">-&gt;</span><span class="default">getSimple</span><span class="keyword">()-&gt;</span><span class="default">priv</span><span class="keyword">);</span><span class="comment">// output: NULL, not a Fatal Error<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$bar</span><span class="keyword">-&gt;</span><span class="default">getSimple</span><span class="keyword">()-&gt;</span><span class="default">pub</span><span class="keyword">);</span><span class="comment">// output: int(2)<br /><br /></span><span class="default">$barSimple </span><span class="keyword">= </span><span class="default">$bar</span><span class="keyword">-&gt;</span><span class="default">getSimple</span><span class="keyword">();<br /></span><span class="default">$barSimple</span><span class="keyword">-&gt;</span><span class="default">priv </span><span class="keyword">= </span><span class="default">10</span><span class="keyword">;<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$barSimple</span><span class="keyword">-&gt;</span><span class="default">priv</span><span class="keyword">);</span><span class="comment">// output: int(10)<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="92379">  <div class="votes">
    <div id="Vu92379">
    <a href="/manual/vote-note.php?id=92379&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd92379">
    <a href="/manual/vote-note.php?id=92379&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V92379" title="43% like this...">
    -10
    </div>
  </div>
  <a href="#92379" class="name">
  <strong class="user"><em>spidgorny at gmail dot com</em></strong></a><a class="genanchor" href="#92379"> &para;</a><div class="date" title="2009-07-22 01:58"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom92379">
<div class="phpcode"><code><span class="html">
If having<br /><br />class BugDetails extends Bug<br /><br />you want to cast an object of a Bug to BugDetails like this<br /><span class="default">&lt;?php<br />&nbsp; &nbsp; $clone </span><span class="keyword">= (</span><span class="default">BugDetails</span><span class="keyword">) clone </span><span class="default">$this</span><span class="keyword">;<br /></span><span class="comment">// OR<br />&nbsp; &nbsp; </span><span class="default">$clone </span><span class="keyword">= (</span><span class="default">BugDetails</span><span class="keyword">) </span><span class="default">$bug</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span>which doesn't work in PHP, you have two options:<br />1. Copying all (including private) properties manually (you could also use get_object_vars(), but this is shorter):<br /><span class="default">&lt;?php<br />&nbsp; &nbsp; $clone </span><span class="keyword">= new </span><span class="default">BugDetails</span><span class="keyword">();<br />&nbsp; &nbsp; foreach (</span><span class="default">$this </span><span class="keyword">as </span><span class="default">$key </span><span class="keyword">=&gt; </span><span class="default">$val</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$clone</span><span class="keyword">-&gt;</span><span class="default">$key </span><span class="keyword">= </span><span class="default">$val</span><span class="keyword">;<br />&nbsp; &nbsp; }<br /></span><span class="default">?&gt;<br /></span>2. Serialize an object Bug, manipulate the resulting string so that it has BugDetails inside and unserialize it.<br />See here: <a href="http://blog.adaniels.nl/articles/a-dark-corner-of-php-class-casting/" rel="nofollow" target="_blank">http://blog.adaniels.nl/articles/a-dark-corner-of-php-class-casting/</a><br /><br />Spent two hours looking for more elegant solution, that's my findings.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="95489">  <div class="votes">
    <div id="Vu95489">
    <a href="/manual/vote-note.php?id=95489&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd95489">
    <a href="/manual/vote-note.php?id=95489&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V95489" title="43% like this...">
    -12
    </div>
  </div>
  <a href="#95489" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#95489"> &para;</a><div class="date" title="2010-01-05 02:10"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom95489">
<div class="phpcode"><code><span class="html">
Initialization, Instantiation and Instances are terms that can be confusing at first. Let's try to sort it out starting with this simple class definition.<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">class </span><span class="default">User<br /></span><span class="keyword">{<br />&nbsp; public </span><span class="default">$first_name</span><span class="keyword">;<br />&nbsp; public </span><span class="default">$last_name</span><span class="keyword">;<br /><br />&nbsp; public function </span><span class="default">__toString</span><span class="keyword">()<br />&nbsp; {<br />&nbsp; &nbsp; return </span><span class="string">"User [first='</span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">first_name</span><span class="string">', last='</span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">last_name</span><span class="string">']"</span><span class="keyword">;<br />&nbsp; }<br />}<br /><br /></span><span class="default">?&gt;<br /></span><br />Now create several INSTANCES of User by INSTANTIATING the User class above.<br /><br /><span class="default">&lt;?php<br />$user_1 </span><span class="keyword">= new </span><span class="default">User</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// $user_1 is an INSTANCE of User<br /></span><span class="default">$user_2 </span><span class="keyword">= new </span><span class="default">User</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// $user_2 is an INSTANCE of User<br /></span><span class="keyword">echo </span><span class="default">$user_1 </span><span class="keyword">. </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;&nbsp; &nbsp;&nbsp; </span><span class="comment">// User [first='', last='']<br /></span><span class="keyword">echo </span><span class="default">$user_2 </span><span class="keyword">. </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;&nbsp; &nbsp;&nbsp; </span><span class="comment">// User [first='', last='']<br /></span><span class="default">?&gt;<br /></span><br />Here we have (2) two INSTANCES of User, but each instance was only INSTANTIATED once - when we used the 'new' operator.<br /><br />And now looking at the printed output, you can see there are no values for their first or last names. This means that the objects themselves have NOT been INITIALIZED. To remedy this situation, rewrite the class definition by adding a __construct() method.<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">class </span><span class="default">User<br /></span><span class="keyword">{<br />&nbsp; public </span><span class="default">$first_name</span><span class="keyword">;<br />&nbsp; public </span><span class="default">$last_name</span><span class="keyword">;<br /><br />&nbsp; public function </span><span class="default">__construct</span><span class="keyword">(</span><span class="default">$first</span><span class="keyword">, </span><span class="default">$last</span><span class="keyword">)&nbsp; &nbsp; </span><span class="comment">// Require first and last names when INSTANTIATING<br />&nbsp; </span><span class="keyword">{<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">first_name </span><span class="keyword">= </span><span class="default">$first</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// INITIALIZE $first_name;<br />&nbsp; &nbsp; </span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">last_name </span><span class="keyword">= </span><span class="default">$last</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="comment">// INITIALIZE $last_name;<br />&nbsp; </span><span class="keyword">}<br /><br />&nbsp; public function </span><span class="default">__toString</span><span class="keyword">()<br />&nbsp; {<br />&nbsp; &nbsp; return </span><span class="string">"User [first='</span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">first_name</span><span class="string">', last='</span><span class="default">$this</span><span class="keyword">-&gt;</span><span class="default">last_name</span><span class="string">']"</span><span class="keyword">;<br />&nbsp; }<br />}<br /><br /></span><span class="default">?&gt;<br /></span><br />Now try it again.<br /><br /><span class="default">&lt;?php<br />$user_1 </span><span class="keyword">= new </span><span class="default">User</span><span class="keyword">(</span><span class="string">'John'</span><span class="keyword">, </span><span class="string">'Doe'</span><span class="keyword">);&nbsp; &nbsp; &nbsp; </span><span class="comment">// $user_i is an INSTANCE of User&nbsp; <br /></span><span class="default">$user_2 </span><span class="keyword">= new </span><span class="default">User</span><span class="keyword">(</span><span class="string">'Jane'</span><span class="keyword">, </span><span class="string">'Doe'</span><span class="keyword">);&nbsp; &nbsp; &nbsp; </span><span class="comment">// $user_2 is an INSTANCE of User<br /></span><span class="keyword">echo </span><span class="default">$user_1 </span><span class="keyword">. </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// prints: User [first='John', last='Doe']<br /></span><span class="keyword">echo </span><span class="default">$user_2 </span><span class="keyword">. </span><span class="string">'&lt;br&gt;'</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// prints: User [first='Jane', last='Doe']<br /></span><span class="default">?&gt;<br /></span><br />The __construct() method is called automatically by PHP when it sees the 'new' operator. Our __construct() method above requires the first and last names to be passed in as arguments and uses them to INITIALIZE objects when INSTANTIATING new INSTANCES.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="119252">  <div class="votes">
    <div id="Vu119252">
    <a href="/manual/vote-note.php?id=119252&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd119252">
    <a href="/manual/vote-note.php?id=119252&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V119252" title="40% like this...">
    -8
    </div>
  </div>
  <a href="#119252" class="name">
  <strong class="user"><em>solly dot ucko at google dot com</em></strong></a><a class="genanchor" href="#119252"> &para;</a><div class="date" title="2016-04-27 05:09"><strong>3 years ago</strong></div>
  <div class="text" id="Hcom119252">
<div class="phpcode"><code><span class="html">
To create an object with values, in javascript you would use `{key: value}`. In PHP you use `[key=&gt;value]`.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="59128">  <div class="votes">
    <div id="Vu59128">
    <a href="/manual/vote-note.php?id=59128&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd59128">
    <a href="/manual/vote-note.php?id=59128&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V59128" title="42% like this...">
    -10
    </div>
  </div>
  <a href="#59128" class="name">
  <strong class="user"><em>Trevor Blackbird &gt; yurab.com</em></strong></a><a class="genanchor" href="#59128"> &para;</a><div class="date" title="2005-11-26 09:33"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom59128">
<div class="phpcode"><code><span class="html">
You can create a new object using the built-in stdClass or by using type-casting:<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="comment">// This is the proper way<br /></span><span class="default">$object1 </span><span class="keyword">= new </span><span class="default">stdClass</span><span class="keyword">();<br /><br /></span><span class="comment">// This works too<br /></span><span class="default">$object2 </span><span class="keyword">= (object) </span><span class="default">NULL</span><span class="keyword">;<br /><br /></span><span class="comment">// This will create an object from an array<br /></span><span class="default">$monkey_array </span><span class="keyword">= array(</span><span class="string">'title'</span><span class="keyword">=&gt;</span><span class="string">'Spider Monkey'</span><span class="keyword">, </span><span class="string">'src'</span><span class="keyword">=&gt;</span><span class="string">'monkey.jpg'</span><span class="keyword">);<br /></span><span class="default">$monkey_object </span><span class="keyword">= (object) </span><span class="default">$monkey_array</span><span class="keyword">;<br />print </span><span class="default">$monkey_object</span><span class="keyword">-&gt;</span><span class="default">title </span><span class="keyword">. </span><span class="string">' ' </span><span class="keyword">. </span><span class="default">$monkey_object</span><span class="keyword">-&gt;</span><span class="default">src</span><span class="keyword">;<br /><br /></span><span class="comment">// You can type-cast in the middle of an expression<br /></span><span class="keyword">function </span><span class="default">customHTML</span><span class="keyword">(</span><span class="default">$some_object</span><span class="keyword">) {<br /></span><span class="comment">// this function expects an object as the argument and returns some output<br /></span><span class="keyword">}<br />print </span><span class="string">'&lt;p&gt;Writing some output ' </span><span class="keyword">. </span><span class="default">customHTML</span><span class="keyword">( (object) array(</span><span class="string">'rows'</span><span class="keyword">=&gt;</span><span class="default">3</span><span class="keyword">, </span><span class="string">'cols'</span><span class="keyword">=&gt;</span><span class="default">4</span><span class="keyword">) );<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="85440">  <div class="votes">
    <div id="Vu85440">
    <a href="/manual/vote-note.php?id=85440&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd85440">
    <a href="/manual/vote-note.php?id=85440&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V85440" title="40% like this...">
    -15
    </div>
  </div>
  <a href="#85440" class="name">
  <strong class="user"><em>Isaac Z. Schlueter i at foohack dot com</em></strong></a><a class="genanchor" href="#85440"> &para;</a><div class="date" title="2008-08-30 05:31"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom85440">
<div class="phpcode"><code><span class="html">
In response to Harmor and Mithras,&nbsp; you can use the json functions to convert multi-dimensional arrays to objects very reliably.<br /><br />Also, note that just using (object)$x doesn't allow you to access properties inline.&nbsp; For example, this is invalid:<br /><br /><span class="default">&lt;?php<br />$x </span><span class="keyword">= array(</span><span class="string">"foo"</span><span class="keyword">=&gt;</span><span class="string">"bar"</span><span class="keyword">);<br />echo ((object)</span><span class="default">$x</span><span class="keyword">)-&gt;</span><span class="default">foo</span><span class="keyword">; </span><span class="comment">// PHP Parse error, unexpected T_OBJECT_OPERATOR<br /></span><span class="default">?&gt;<br /></span><br />However, this function will let you do that, and will also handle multi-dimensional arrays without any hassle.<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">to_object </span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">) {<br />&nbsp; &nbsp; return (</span><span class="default">is_object</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">) || </span><span class="default">is_array</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">)) ? </span><span class="default">json_decode</span><span class="keyword">(</span><span class="default">json_encode</span><span class="keyword">(</span><span class="default">$x</span><span class="keyword">)) : (object) </span><span class="default">$x</span><span class="keyword">;<br />}<br /><br />echo </span><span class="default">to_object</span><span class="keyword">( array(</span><span class="string">"foo"</span><span class="keyword">=&gt;</span><span class="string">"bar"</span><span class="keyword">) )-&gt;</span><span class="default">foo</span><span class="keyword">; </span><span class="comment">// "bar"<br /></span><span class="default">?&gt;<br /></span><br />Note that *numeric* arrays will not be converted to objects using this method.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="114428">  <div class="votes">
    <div id="Vu114428">
    <a href="/manual/vote-note.php?id=114428&amp;page=language.types.object&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd114428">
    <a href="/manual/vote-note.php?id=114428&amp;page=language.types.object&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V114428" title="33% like this...">
    -16
    </div>
  </div>
  <a href="#114428" class="name">
  <strong class="user"><em>Ashley Dambra</em></strong></a><a class="genanchor" href="#114428"> &para;</a><div class="date" title="2014-02-19 06:51"><strong>5 years ago</strong></div>
  <div class="text" id="Hcom114428">
<div class="phpcode"><code><span class="html">
Class like stdClass but with the possibility to add and execute function.<br /><br />class stdObject {<br />&nbsp; &nbsp; public function __construct(array $arguments = array()) {<br />&nbsp; &nbsp; &nbsp; &nbsp; if (!empty($arguments)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; foreach ($arguments as $property =&gt; $argument) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if ($argument instanceOf Closure) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $this-&gt;{$property} = $argument;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $this-&gt;{$property} = $argument;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; public function __call($method, $arguments) {<br />&nbsp; &nbsp; &nbsp; &nbsp; if (isset($this-&gt;{$method}) &amp;&amp; is_callable($this-&gt;{$method})) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return call_user_func_array($this-&gt;{$method}, $arguments);<br />&nbsp; &nbsp; &nbsp; &nbsp; } else {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; throw new Exception("Fatal error: Call to undefined method stdObject::{$method}()");<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />}</span>
</code></div>
  </div>
 </div></div>

 <div class="foot"><a href="/manual/add-note.php?sect=language.types.object&amp;redirect=https://www.php.net/manual/pt_BR/language.types.object.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></div>
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
                                                <li class="current">
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
                                                <li class="">
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
