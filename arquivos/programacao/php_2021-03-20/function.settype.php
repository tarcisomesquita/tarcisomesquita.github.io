<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="pt_BR">
<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: settype - Manual </title>

 <link rel="shortcut icon" href="https://www.php.net/favicon.ico">
 <link rel="search" type="application/opensearchdescription+xml" href="http://php.net/phpnetimprovedsearch.src" title="Add PHP.net search">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/releases/feed.php" title="PHP Release feed">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/feed.atom" title="PHP: Hypertext Preprocessor">

 <link rel="canonical" href="https://www.php.net/manual/pt_BR/function.settype.php">
 <link rel="shorturl" href="https://www.php.net/settype">
 <link rel="alternate" href="https://www.php.net/settype" hreflang="x-default">

 <link rel="contents" href="https://www.php.net/manual/pt_BR/index.php">
 <link rel="index" href="https://www.php.net/manual/pt_BR/ref.var.php">
 <link rel="prev" href="https://www.php.net/manual/pt_BR/function.serialize.php">
 <link rel="next" href="https://www.php.net/manual/pt_BR/function.strval.php">

 <link rel="alternate" href="https://www.php.net/manual/en/function.settype.php" hreflang="en">
 <link rel="alternate" href="https://www.php.net/manual/pt_BR/function.settype.php" hreflang="pt_BR">
 <link rel="alternate" href="https://www.php.net/manual/zh/function.settype.php" hreflang="zh">
 <link rel="alternate" href="https://www.php.net/manual/fr/function.settype.php" hreflang="fr">
 <link rel="alternate" href="https://www.php.net/manual/de/function.settype.php" hreflang="de">
 <link rel="alternate" href="https://www.php.net/manual/ja/function.settype.php" hreflang="ja">
 <link rel="alternate" href="https://www.php.net/manual/ro/function.settype.php" hreflang="ro">
 <link rel="alternate" href="https://www.php.net/manual/ru/function.settype.php" hreflang="ru">
 <link rel="alternate" href="https://www.php.net/manual/es/function.settype.php" hreflang="es">
 <link rel="alternate" href="https://www.php.net/manual/tr/function.settype.php" hreflang="tr">

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

 <base href="https://www.php.net/manual/pt_BR/function.settype.php">

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
        <a href="function.strval.php">
          strval &raquo;
        </a>
      </div>
              <div class="prev">
        <a href="function.serialize.php">
          &laquo; serialize        </a>
      </div>
          <ul>
            <li><a href='index.php'>Manual do PHP</a></li>      <li><a href='funcref.php'>Refer&ecirc;ncia das Fun&ccedil;&otilde;es</a></li>      <li><a href='refs.basic.vartype.php'>Vari&aacute;vel e Extens&otilde;es Relacionadas aos Tipos</a></li>      <li><a href='book.var.php'>Manipula&ccedil;&atilde;o de vari&aacute;vel</a></li>      <li><a href='ref.var.php'>Fun&ccedil;&otilde;es para Manipula&ccedil;&atilde;o de vari&aacute;veis</a></li>      </ul>
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
            <option value='en/function.settype.php'>English</option>
            <option value='pt_BR/function.settype.php' selected="selected">Brazilian Portuguese</option>
            <option value='zh/function.settype.php'>Chinese (Simplified)</option>
            <option value='fr/function.settype.php'>French</option>
            <option value='de/function.settype.php'>German</option>
            <option value='ja/function.settype.php'>Japanese</option>
            <option value='ro/function.settype.php'>Romanian</option>
            <option value='ru/function.settype.php'>Russian</option>
            <option value='es/function.settype.php'>Spanish</option>
            <option value='tr/function.settype.php'>Turkish</option>
            <option value="help-translate.php">Other</option>
          </select>
        </fieldset>
      </form>
    </div>
    <div class="edit-bug">
      <a href="https://edit.php.net/?project=PHP&amp;perm=pt_BR/function.settype.php">Edit</a>
      <a href="https://bugs.php.net/report.php?bug_type=Documentation+problem&amp;manpage=function.settype">Report a Bug</a>
    </div>
  </div><div id="function.settype" class="refentry">
   <div class="refnamediv">
    <h1 class="refname">settype</h1>
    <p class="verinfo">(PHP 4, PHP 5, PHP 7)</p><p class="refpurpose"><span class="refname">settype</span> &mdash; <span class="dc-title">Atribui um tipo para a variável</span></p>

   </div>
   
 <div class="refsect1 description" id="refsect1-function.settype-description">
  <h3 class="title">Descrição</h3>
     <div class="methodsynopsis dc-description">
      <span class="methodname"><strong>settype</strong></span>
       ( <span class="methodparam"><span class="type"><a href="language.pseudo-types.php#language.types.mixed" class="type mixed">mixed</a></span> <code class="parameter reference">&$var</code></span>
      , <span class="methodparam"><span class="type">string</span> <code class="parameter">$type</code></span>
      ) : <span class="type">bool</span></div>

    <p class="para rdfs-comment">
     Atribui um tipo para a variável <code class="parameter">var</code> baseado no
     <code class="parameter">type</code>.
    </p>
 </div>


 <div class="refsect1 parameters" id="refsect1-function.settype-parameters">
  <h3 class="title">Parâmetros</h3>
  <p class="para">
   <dl>

    
     <dt>
<code class="parameter">var</code></dt>

     <dd>

      <p class="para">
       A variável a ser convertida.
      </p>
     </dd>

    
    
     <dt>
<code class="parameter">type</code></dt>

     <dd>

    <p class="para">
     Os valores possíveis para <code class="parameter">type</code> são:
     <ul class="itemizedlist">
      <li class="listitem">
       <span class="simpara">
        &quot;boolean&quot; (ou, a partir do PHP 4.2.0, &quot;bool&quot;)
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        &quot;integer&quot; (ou, a partir do PHP 4.2.0, &quot;int&quot;)
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        &quot;float&quot; (somente para versões acima do PHP 4.2.0, para versões antigas use a
        variação depreciada &quot;double&quot;)
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        &quot;string&quot;
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        &quot;array&quot;
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        &quot;object&quot;
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        &quot;null&quot; (a partir do PHP 4.2.0)
       </span>
      </li>
     </ul>
    </p>
     </dd>

    
   </dl>

  </p>
 </div>


 <div class="refsect1 returnvalues" id="refsect1-function.settype-returnvalues">
  <h3 class="title">Valor Retornado</h3>
    <p class="para">
     Retorna <strong><code>TRUE</code></strong> em caso de sucesso ou <strong><code>FALSE</code></strong> em caso de falha.
    </p>
 </div>


 <div class="refsect1 examples" id="refsect1-function.settype-examples">
  <h3 class="title">Exemplos</h3>
    <p class="para">
     <div class="example" id="example-6239">
      <p><strong>Exemplo #1 Exemplo da função <span class="function"><strong>settype()</strong></span></strong></p>
      <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$foo&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">"5bar"</span><span style="color: #007700">;&nbsp;</span><span style="color: #FF8000">//&nbsp;string<br /></span><span style="color: #0000BB">$bar&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">true</span><span style="color: #007700">;&nbsp;&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;boolean<br /><br /></span><span style="color: #0000BB">settype</span><span style="color: #007700">(</span><span style="color: #0000BB">$foo</span><span style="color: #007700">,&nbsp;</span><span style="color: #DD0000">"integer"</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;$foo&nbsp;é&nbsp;agora&nbsp;5&nbsp;&nbsp;&nbsp;(integer)<br /></span><span style="color: #0000BB">settype</span><span style="color: #007700">(</span><span style="color: #0000BB">$bar</span><span style="color: #007700">,&nbsp;</span><span style="color: #DD0000">"string"</span><span style="color: #007700">);&nbsp;&nbsp;</span><span style="color: #FF8000">//&nbsp;$bar&nbsp;é&nbsp;agora&nbsp;"1"&nbsp;(string)<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
      </div>

     </div>
    </p>
 </div>


 <div class="refsect1 notes" id="refsect1-function.settype-notes">
  <h3 class="title">Notas</h3>
  <blockquote class="note"><p><strong class="note">Nota</strong>: 
    <p class="para">
     O valor máximo para &quot;int&quot; é <strong><code>PHP_INT_MAX</code></strong>.
    </p>
   </p></blockquote>
   </div>


 <div class="refsect1 seealso" id="refsect1-function.settype-seealso">
  <h3 class="title">Veja Também</h3>
  <p class="para">
   <ul class="simplelist">
    <li class="member"><span class="function"><a href="function.gettype.php" class="function" rel="rdfs-seeAlso">gettype()</a> - Obt&eacute;m o tipo da vari&aacute;vel</span></li>
    <li class="member"><a href="language.types.type-juggling.php#language.types.typecasting" class="link">conversão de tipos</a></li>
    <li class="member"><a href="language.types.type-juggling.php" class="link">manipulação de tipos</a></li>
   </ul>
  </p>
 </div>


  </div>
<section id="usernotes">
 <div class="head">
  <span class="action"><a href="/manual/add-note.php?sect=function.settype&amp;redirect=https://www.php.net/manual/pt_BR/function.settype.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></span>
  <h3 class="title">User Contributed Notes <span class="count">16 notes</span></h3>
 </div><div id="allnotes">
  <div class="note" id="107683">  <div class="votes">
    <div id="Vu107683">
    <a href="/manual/vote-note.php?id=107683&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd107683">
    <a href="/manual/vote-note.php?id=107683&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V107683" title="73% like this...">
    59
    </div>
  </div>
  <a href="#107683" class="name">
  <strong class="user"><em>Special Notes</em></strong></a><a class="genanchor" href="#107683"> &para;</a><div class="date" title="2012-02-26 12:00"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom107683">
<div class="phpcode"><code><span class="html">
Note that you can't use this to convert a string 'true' or 'false' to a boolean variable true or false as a string 'false' is a boolean true. The empty string would be false instead...<br /><br /><span class="default">&lt;?php<br />$var </span><span class="keyword">= </span><span class="string">"true"</span><span class="keyword">;<br /></span><span class="default">settype</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">, </span><span class="string">'bool'</span><span class="keyword">);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">); </span><span class="comment">// true<br /><br /></span><span class="default">$var </span><span class="keyword">= </span><span class="string">"false"</span><span class="keyword">;<br /></span><span class="default">settype</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">, </span><span class="string">'bool'</span><span class="keyword">);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">); </span><span class="comment">// true as well!<br /><br /></span><span class="default">$var </span><span class="keyword">= </span><span class="string">""</span><span class="keyword">;<br /></span><span class="default">settype</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">, </span><span class="string">'bool'</span><span class="keyword">);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$var</span><span class="keyword">); </span><span class="comment">// false<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="81595">  <div class="votes">
    <div id="Vu81595">
    <a href="/manual/vote-note.php?id=81595&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd81595">
    <a href="/manual/vote-note.php?id=81595&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V81595" title="73% like this...">
    33
    </div>
  </div>
  <a href="#81595" class="name">
  <strong class="user"><em>robin at barafranca dot com</em></strong></a><a class="genanchor" href="#81595"> &para;</a><div class="date" title="2008-03-05 04:20"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom81595">
<div class="phpcode"><code><span class="html">
Just a quick note, as this caught me out very briefly:<br /><br />settype() returns bool, not the typecasted variable - so:<br /><br />$blah = settype($blah, "int"); // is wrong, changes $blah to 0 or 1<br />settype($blah, "int"); // is correct<br /><br />Hope this helps someone else who makes a mistake.. ;)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="35587">  <div class="votes">
    <div id="Vu35587">
    <a href="/manual/vote-note.php?id=35587&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd35587">
    <a href="/manual/vote-note.php?id=35587&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V35587" title="62% like this...">
    18
    </div>
  </div>
  <a href="#35587" class="name">
  <strong class="user"><em>sdibb at myway dot com</em></strong></a><a class="genanchor" href="#35587"> &para;</a><div class="date" title="2003-09-06 10:03"><strong>16 years ago</strong></div>
  <div class="text" id="Hcom35587">
<div class="phpcode"><code><span class="html">
Using settype is not the best way to convert a string into an integer, since it will strip the string wherever the first non-numeric character begins.&nbsp; The function intval($string) does the same thing.<br /><br />If you're looking for a security check, or to strip non-numeric characters (such as cleaning up phone numbers or ZIP codes),&nbsp; try this instead:<br /><br />&lt;?<br />&nbsp; &nbsp;&nbsp; $number=ereg_replace("[^0-9]","",$number);<br />?&gt;</span>
</code></div>
  </div>
 </div>
  <div class="note" id="55016">  <div class="votes">
    <div id="Vu55016">
    <a href="/manual/vote-note.php?id=55016&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd55016">
    <a href="/manual/vote-note.php?id=55016&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V55016" title="60% like this...">
    7
    </div>
  </div>
  <a href="#55016" class="name">
  <strong class="user"><em>nospamplease at veganismus dot ch</em></strong></a><a class="genanchor" href="#55016"> &para;</a><div class="date" title="2005-07-22 07:38"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom55016">
<div class="phpcode"><code><span class="html">
you must note that this function will not set the type permanently! the next time you set the value of that variable php will change its type as well.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="64195">  <div class="votes">
    <div id="Vu64195">
    <a href="/manual/vote-note.php?id=64195&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd64195">
    <a href="/manual/vote-note.php?id=64195&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V64195" title="52% like this...">
    1
    </div>
  </div>
  <a href="#64195" class="name">
  <strong class="user"><em>ludvig dot ericson gmail.dot com</em></strong></a><a class="genanchor" href="#64195"> &para;</a><div class="date" title="2006-04-09 08:36"><strong>13 years ago</strong></div>
  <div class="text" id="Hcom64195">
<div class="phpcode"><code><span class="html">
To matt:<br />This function accepts a paremeter, which does not imply you using hardcoded stuff, instead you can let the user choose! \o/<br /><br />As a part of a framework or something.<br /><br />Plus, you can probably call this with call_user_func</span>
</code></div>
  </div>
 </div>
  <div class="note" id="124531">  <div class="votes">
    <div id="Vu124531">
    <a href="/manual/vote-note.php?id=124531&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd124531">
    <a href="/manual/vote-note.php?id=124531&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V124531" title="no votes...">
    0
    </div>
  </div>
  <a href="#124531" class="name">
  <strong class="user"><em>geoffsmiths at hotmail dot com</em></strong></a><a class="genanchor" href="#124531"> &para;</a><div class="date" title="2019-12-24 10:23"><strong>16 days ago</strong></div>
  <div class="text" id="Hcom124531">
<div class="phpcode"><code><span class="html">
Please note: <br /><br />When using settype to convert indexed arrays to objects, the properties of the typed object will be integers:<br /><br />A brief example:<br /><br />$a = ['1', '2'];<br /><br />settype($a, 'object');<br /><br />var_dump($a);<br /><br />// output<br />object(stdClass)#1 (2) {<br />&nbsp; ["0"]=&gt;<br />&nbsp; string(1) "1"<br />&nbsp; ["1"]=&gt;<br />&nbsp; string(1) "2"<br />}</span>
</code></div>
  </div>
 </div>
  <div class="note" id="121441">  <div class="votes">
    <div id="Vu121441">
    <a href="/manual/vote-note.php?id=121441&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd121441">
    <a href="/manual/vote-note.php?id=121441&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V121441" title="50% like this...">
    0
    </div>
  </div>
  <a href="#121441" class="name">
  <strong class="user"><em>Skayo</em></strong></a><a class="genanchor" href="#121441"> &para;</a><div class="date" title="2017-07-26 08:59"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom121441">
<div class="phpcode"><code><span class="html">
$foo = "1";<br />settype($foo, "bool");<br />var_dump($foo); // Outputs: bool(true)<br /><br />$bar = "0";<br />settype($bar, "bool");<br />var_dump($bar); // Outputs: bool(false)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120142">  <div class="votes">
    <div id="Vu120142">
    <a href="/manual/vote-note.php?id=120142&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120142">
    <a href="/manual/vote-note.php?id=120142&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120142" title="50% like this...">
    0
    </div>
  </div>
  <a href="#120142" class="name">
  <strong class="user"><em>marjune</em></strong></a><a class="genanchor" href="#120142"> &para;</a><div class="date" title="2016-11-10 05:31"><strong>3 years ago</strong></div>
  <div class="text" id="Hcom120142">
<div class="phpcode"><code><span class="html">
any digit except 0 or -0 are considered true in boolean, and any string except '0' or '' are also considered true.<br /><br /><span class="default">&lt;?php<br /><br />$foo </span><span class="keyword">= </span><span class="string">'0'</span><span class="keyword">;<br /></span><span class="default">settype</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">, </span><span class="string">'boolean'</span><span class="keyword">);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">); </span><span class="comment">// false<br /><br /></span><span class="default">$foo </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">;<br /></span><span class="default">settype</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">, </span><span class="string">'boolean'</span><span class="keyword">);<br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">); </span><span class="comment">// false</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="50898">  <div class="votes">
    <div id="Vu50898">
    <a href="/manual/vote-note.php?id=50898&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd50898">
    <a href="/manual/vote-note.php?id=50898&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V50898" title="51% like this...">
    1
    </div>
  </div>
  <a href="#50898" class="name">
  <strong class="user"><em>reinier_deblois at hotmail dot com</em></strong></a><a class="genanchor" href="#50898"> &para;</a><div class="date" title="2005-03-13 09:18"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom50898">
<div class="phpcode"><code><span class="html">
Instead of settype you could use:<br /><span class="default">&lt;?php<br /><br />$int</span><span class="keyword">=</span><span class="default">593</span><span class="keyword">;&nbsp; </span><span class="comment">// $int is a integer<br /><br /></span><span class="default">$int</span><span class="keyword">.=</span><span class="string">""</span><span class="keyword">;&nbsp;&nbsp; </span><span class="comment">// $int is now a string</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="59444">  <div class="votes">
    <div id="Vu59444">
    <a href="/manual/vote-note.php?id=59444&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd59444">
    <a href="/manual/vote-note.php?id=59444&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V59444" title="50% like this...">
    0
    </div>
  </div>
  <a href="#59444" class="name">
  <strong class="user"><em>matt at mattsoft dot net</em></strong></a><a class="genanchor" href="#59444"> &para;</a><div class="date" title="2005-12-06 09:49"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom59444">
<div class="phpcode"><code><span class="html">
using (int) insted of the settype function works out much better for me. I have always used it. I personally don't see where settype would ever come in handy.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="5593">  <div class="votes">
    <div id="Vu5593">
    <a href="/manual/vote-note.php?id=5593&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd5593">
    <a href="/manual/vote-note.php?id=5593&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V5593" title="47% like this...">
    -1
    </div>
  </div>
  <a href="#5593" class="name">
  <strong class="user"><em>ns at canada dot com</em></strong></a><a class="genanchor" href="#5593"> &para;</a><div class="date" title="2000-05-05 04:38"><strong>19 years ago</strong></div>
  <div class="text" id="Hcom5593">
<div class="phpcode"><code><span class="html">
This settype() behaviour seems consistent to me. Quoting two sections from the manual:<br /><br />"When casting from a scalar or a string variable to an array, the variable will become the first element of the array: "<br />&lt;pre&gt;<br />2 $var = 'ciao';<br />3 $arr = (array) $var;<br />4 echo $arr[0];&nbsp; // outputs 'ciao' <br />&lt;/pre&gt;<br /><br />And if (like your code above) you do a settype on an empty variable, you'll end up with a one element array with an empty (not unset!) first element. So appeanding to it will start appending at index 1. As for why reset() doesn't do anything:<br /><br />"When you assign a value to an array variable using empty brackets, the value will be added onto the end of the array."<br /><br />It doesn't matter where the array counter is; values are added at the end, not at the counter.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="87059">  <div class="votes">
    <div id="Vu87059">
    <a href="/manual/vote-note.php?id=87059&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd87059">
    <a href="/manual/vote-note.php?id=87059&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V87059" title="43% like this...">
    -3
    </div>
  </div>
  <a href="#87059" class="name">
  <strong class="user"><em>NWdev</em></strong></a><a class="genanchor" href="#87059"> &para;</a><div class="date" title="2008-11-17 09:38"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom87059">
<div class="phpcode"><code><span class="html">
In trying to convert an array of strings to an array of ints, <br />I attempted to use settype with array_walk.<br /><br /><span class="default">&lt;?php<br /></span><span class="comment">//$numArray is generated by another process<br /></span><span class="default">$numArray </span><span class="keyword">= array(</span><span class="string">'13'</span><span class="keyword">,</span><span class="string">'14'</span><span class="keyword">,</span><span class="string">'33'</span><span class="keyword">);<br /><br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$numArray</span><span class="keyword">);<br /><br /></span><span class="comment">//my conversion function<br /></span><span class="keyword">function </span><span class="default">str_to_int</span><span class="keyword">(</span><span class="default">$val</span><span class="keyword">){<br />&nbsp; </span><span class="comment">//remember: settype($x, 'int') returns boolean (1=success, 0=failure)<br />&nbsp; //--&gt; so return $x to return new value<br />&nbsp; &nbsp; </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$val</span><span class="keyword">,</span><span class="string">'int'</span><span class="keyword">);<br />&nbsp; &nbsp; echo </span><span class="string">"&lt;br /&gt;gettype = "</span><span class="keyword">.</span><span class="default">gettype</span><span class="keyword">(</span><span class="default">$val</span><span class="keyword">).</span><span class="string">"&lt;br /&gt;"</span><span class="keyword">;<br />&nbsp; &nbsp; return </span><span class="default">$val</span><span class="keyword">;<br />}<br /><br /></span><span class="default">array_walk</span><span class="keyword">(</span><span class="default">$numArray</span><span class="keyword">,</span><span class="string">'str_to_int'</span><span class="keyword">);<br /><br /></span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$numArray</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />The var_dumps both return the following:<br /><span class="default">&lt;?php<br /></span><span class="keyword">array(</span><span class="default">3</span><span class="keyword">) { [</span><span class="default">0</span><span class="keyword">]=&gt; </span><span class="default">string</span><span class="keyword">(</span><span class="default">2</span><span class="keyword">) </span><span class="string">"13" </span><span class="keyword">[</span><span class="default">1</span><span class="keyword">]=&gt; </span><span class="default">string</span><span class="keyword">(</span><span class="default">2</span><span class="keyword">) </span><span class="string">"14" </span><span class="keyword">[</span><span class="default">2</span><span class="keyword">]=&gt; </span><span class="default">string</span><span class="keyword">(</span><span class="default">2</span><span class="keyword">) </span><span class="string">"33" </span><span class="keyword">} <br /></span><span class="default">?&gt;<br /></span><br />The gettype echo will show the value as an integer.<br /><br />So it seems that settype($val,'int') makes the conversion, <br />but the function return value remains a string. <br />Since settype returns a boolean, using <br /><span class="default">&lt;?php $val </span><span class="keyword">= </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$val</span><span class="keyword">, </span><span class="string">'int'</span><span class="keyword">); </span><span class="default">?&gt;</span> <br />is not a option.<br /><br />I resolved my array value conversion using this instead:<br /><span class="default">&lt;?php<br />$numArray </span><span class="keyword">= <br />&nbsp; &nbsp; &nbsp; </span><span class="default">array_map</span><span class="keyword">(</span><span class="default">create_function</span><span class="keyword">(</span><span class="string">'$value'</span><span class="keyword">, </span><span class="string">'return (int)$value;'</span><span class="keyword">),</span><span class="default">$numArray</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span>Thanks to the posting here:<br /><a href="http://usrportage.de/archives/" rel="nofollow" target="_blank">http://usrportage.de/archives/</a><br />808-Convert-an-array-of-strings-into-an-array-of-integers.html<br /><br />Perhaps this will save someone else spinning wheels a bit. <br /><br />Also thanks to robin at barafranca dot com for <br />pointing out the boolean return value of settype.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="48028">  <div class="votes">
    <div id="Vu48028">
    <a href="/manual/vote-note.php?id=48028&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd48028">
    <a href="/manual/vote-note.php?id=48028&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V48028" title="41% like this...">
    -4
    </div>
  </div>
  <a href="#48028" class="name">
  <strong class="user"><em>memandeemail at gmail dot com</em></strong></a><a class="genanchor" href="#48028"> &para;</a><div class="date" title="2004-12-09 05:17"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom48028">
<div class="phpcode"><code><span class="html">
/**<br />&nbsp; &nbsp; * @return bool<br />&nbsp; &nbsp; * @param array[byreference] $values<br />&nbsp; &nbsp; * @desc Convert an array or any value to Escalar Object [not tested in large scale]<br />&nbsp; &nbsp; */<br />&nbsp; &nbsp; function setobject(&amp;$values) {<br />&nbsp; &nbsp; &nbsp; &nbsp; $values = (object) $values;<br />&nbsp; &nbsp; &nbsp; &nbsp; foreach ($values as $tkey =&gt; $val) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if (is_array($val)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; setobject($val);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $values-&gt;$tkey = $val;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; return (bool) $values;<br />&nbsp; &nbsp; }</span>
</code></div>
  </div>
 </div>
  <div class="note" id="58274">  <div class="votes">
    <div id="Vu58274">
    <a href="/manual/vote-note.php?id=58274&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd58274">
    <a href="/manual/vote-note.php?id=58274&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V58274" title="39% like this...">
    -5
    </div>
  </div>
  <a href="#58274" class="name">
  <strong class="user"><em>Michael Benedict</em></strong></a><a class="genanchor" href="#58274"> &para;</a><div class="date" title="2005-10-29 10:55"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom58274">
<div class="phpcode"><code><span class="html">
note that settype() will initialize an undefined variable.&nbsp; Therefore, if you want to preserve type and value, you should wrap the settype() call in a call to isset().<br /><br /><span class="default">&lt;?php<br />settype</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">, </span><span class="string">"integer"</span><span class="keyword">);<br />echo(</span><span class="string">"|</span><span class="default">$foo</span><span class="string">|"</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />prints "|0|", NOT "||".<br /><br />To get the latter, use:<br /><span class="default">&lt;?php<br /></span><span class="keyword">if(isset(</span><span class="default">$foo</span><span class="keyword">)) </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">, </span><span class="string">"integer"</span><span class="keyword">);<br />echo(</span><span class="string">"|</span><span class="default">$foo</span><span class="string">|"</span><span class="keyword">);<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="97421">  <div class="votes">
    <div id="Vu97421">
    <a href="/manual/vote-note.php?id=97421&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd97421">
    <a href="/manual/vote-note.php?id=97421&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V97421" title="35% like this...">
    -5
    </div>
  </div>
  <a href="#97421" class="name">
  <strong class="user"><em>Chris Sullins</em></strong></a><a class="genanchor" href="#97421"> &para;</a><div class="date" title="2010-04-18 11:59"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom97421">
<div class="phpcode"><code><span class="html">
settype() has some really strange, potentially buggy behavior.<br /><br />As noted by Michael Benedict, using settype() on a variable will initialize that variable.&nbsp; What is stranger is that using settype() on an uninitialized variable that you are treating as an array or object will also initialize the variable.&nbsp; So:<br /><br /><span class="default">&lt;?php<br />settype</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">-&gt;</span><span class="default">bar</span><span class="keyword">,</span><span class="string">"integer"</span><span class="keyword">); </span><span class="comment">// stdClass Object ( [test] =&gt; 0 )<br /></span><span class="default">?&gt;<br /></span><br />This works for a chain of any length: $foo-&gt;bar['baz']-&gt;etc<br /><br />Next we look at what happens if $foo is already set.<br /><br /><span class="default">&lt;?php<br />$foo </span><span class="keyword">= </span><span class="default">false</span><span class="keyword">;<br /></span><span class="default">settype</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">-&gt;</span><span class="default">bar</span><span class="keyword">,</span><span class="string">"integer"</span><span class="keyword">); </span><span class="comment">// stdClass Object ( [test] =&gt; 0 )<br /></span><span class="default">?&gt;<br /></span><br />In and of itself, this wouldn't be problematic.&nbsp; It might even make sense.&nbsp; But in all other cases where $foo is defined, even if (boolean) $foo === false, it will throw an error unless $foo-&gt;bar is valid (i.e. $foo is an object already).<br /><br /><span class="default">&lt;?php<br />$foo </span><span class="keyword">= </span><span class="default">true</span><span class="keyword">;<br /></span><span class="default">settype</span><span class="keyword">(</span><span class="default">$foo</span><span class="keyword">-&gt;</span><span class="default">bar</span><span class="keyword">,</span><span class="string">"integer"</span><span class="keyword">); </span><span class="comment">// Notice: Trying to get property of non-object<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="123490">  <div class="votes">
    <div id="Vu123490">
    <a href="/manual/vote-note.php?id=123490&amp;page=function.settype&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd123490">
    <a href="/manual/vote-note.php?id=123490&amp;page=function.settype&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V123490" title="25% like this...">
    -2
    </div>
  </div>
  <a href="#123490" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#123490"> &para;</a><div class="date" title="2019-01-04 01:41"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom123490">
<div class="phpcode"><code><span class="html">
If you attempt to convert the special $this variable from an instance method (only in classes) :<br />* PHP will silently return TRUE and leave $this unchanged if the type was 'bool', 'array', 'object' or 'NULL'<br />* PHP will generate an E_NOTICE if the type was 'int', 'float' or 'double', and $this will not be casted<br />* PHP will throw a catchable fatal error when the type is 'string' and the class does not define the __toString() method<br />Unless the new variable type passed as the second argument is invalid, settype() will return TRUE. In all cases the object will remain unchanged.<br /><span class="default">&lt;?php<br />&nbsp; &nbsp; </span><span class="comment">// This was tested with PHP 7.2<br />&nbsp; &nbsp; </span><span class="keyword">class </span><span class="default">Foo </span><span class="keyword">{<br />&nbsp; &nbsp; &nbsp; &nbsp; function </span><span class="default">test</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'Type'</span><span class="keyword">, </span><span class="string">'Succeed?'</span><span class="keyword">, </span><span class="string">'Converted'</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// settype() should throw a fatal error, as $this cannot be re-assigned<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'bool'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'bool'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="default">TRUE</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'int'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'int'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="default">TRUE</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'float'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'float'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'array'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'array'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="default">TRUE</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'object'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'object'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="default">TRUE</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'unknowntype'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'unknowntype'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="default">TRUE</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'NULL'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'NULL'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="default">TRUE</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%-20s %-20s %s\n"</span><span class="keyword">, </span><span class="string">'string'</span><span class="keyword">, </span><span class="default">settype</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="string">'string'</span><span class="keyword">), </span><span class="default">print_r</span><span class="keyword">(</span><span class="default">$this</span><span class="keyword">, </span><span class="default">TRUE</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; </span><span class="default">$a </span><span class="keyword">= new </span><span class="default">Foo</span><span class="keyword">();<br />&nbsp; &nbsp; </span><span class="default">$a</span><span class="keyword">-&gt;</span><span class="default">test</span><span class="keyword">();<br /></span><span class="default">?&gt;<br /></span>Here is the result :<br />Type&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; Succeed?&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; Converted<br />bool&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; 1&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Foo Object<br />(<br />)<br /><br />Notice: Object of class Foo could not be converted to int in C:\php\examples\oop-settype-this.php on line 9<br /><br />int&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 1&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Foo Object<br />(<br />)<br /><br />Notice: Object of class Foo could not be converted to float in C:\php\examples\oop-settype-this.php on line 10<br /><br />float&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 1&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Foo Object<br />(<br />)<br /><br />array&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 1&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Foo Object<br />(<br />)<br /><br />object&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; 1&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Foo Object<br />(<br />)<br /><br />Warning: settype(): Invalid type in C:\php\examples\oop-settype-this.php on line 14<br /><br />unknowntype&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; Foo Object<br />(<br />)<br /><br />NULL&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; 1&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Foo Object<br />(<br />)<br /><br />Catchable fatal error: Object of class Foo could not be converted to string in C:\php\examples\oop-settype-this.php on line 15<br /><br />If the class Foo implements __toString() :<br /><span class="default">&lt;?php<br />&nbsp; &nbsp; </span><span class="keyword">class </span><span class="default">Foo </span><span class="keyword">{<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// ...<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">function </span><span class="default">__toString</span><span class="keyword">() {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="string">'Foo object is awesome!'</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// ...<br />&nbsp; &nbsp; </span><span class="keyword">}<br /></span><span class="default">?&gt;<br /></span>So the first code snippet will not generate an E_RECOVERABLE_ERROR, but instead print the same string as for the other types, and not look at the one returned by the __toString() method.<br /><br />Hope this helps !&nbsp; :)</span>
</code></div>
  </div>
 </div></div>

 <div class="foot"><a href="/manual/add-note.php?sect=function.settype&amp;redirect=https://www.php.net/manual/pt_BR/function.settype.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></div>
</section>    </section><!-- layout-content -->
        <aside class='layout-menu'>

        <ul class='parent-menu-list'>
                                    <li>
                <a href="ref.var.php">Fun&ccedil;&otilde;es para Manipula&ccedil;&atilde;o de vari&aacute;veis</a>

                                    <ul class='child-menu-list'>

                                                <li class="">
                            <a href="function.boolval.php" title="boolval">boolval</a>
                        </li>
                                                <li class="">
                            <a href="function.debug-zval-dump.php" title="debug_&#8203;zval_&#8203;dump">debug_&#8203;zval_&#8203;dump</a>
                        </li>
                                                <li class="">
                            <a href="function.doubleval.php" title="doubleval">doubleval</a>
                        </li>
                                                <li class="">
                            <a href="function.empty.php" title="empty">empty</a>
                        </li>
                                                <li class="">
                            <a href="function.floatval.php" title="floatval">floatval</a>
                        </li>
                                                <li class="">
                            <a href="function.get-defined-vars.php" title="get_&#8203;defined_&#8203;vars">get_&#8203;defined_&#8203;vars</a>
                        </li>
                                                <li class="">
                            <a href="function.get-resource-type.php" title="get_&#8203;resource_&#8203;type">get_&#8203;resource_&#8203;type</a>
                        </li>
                                                <li class="">
                            <a href="function.gettype.php" title="gettype">gettype</a>
                        </li>
                                                <li class="">
                            <a href="function.intval.php" title="intval">intval</a>
                        </li>
                                                <li class="">
                            <a href="function.is-array.php" title="is_&#8203;array">is_&#8203;array</a>
                        </li>
                                                <li class="">
                            <a href="function.is-bool.php" title="is_&#8203;bool">is_&#8203;bool</a>
                        </li>
                                                <li class="">
                            <a href="function.is-callable.php" title="is_&#8203;callable">is_&#8203;callable</a>
                        </li>
                                                <li class="">
                            <a href="function.is-countable.php" title="is_&#8203;countable">is_&#8203;countable</a>
                        </li>
                                                <li class="">
                            <a href="function.is-double.php" title="is_&#8203;double">is_&#8203;double</a>
                        </li>
                                                <li class="">
                            <a href="function.is-float.php" title="is_&#8203;float">is_&#8203;float</a>
                        </li>
                                                <li class="">
                            <a href="function.is-int.php" title="is_&#8203;int">is_&#8203;int</a>
                        </li>
                                                <li class="">
                            <a href="function.is-integer.php" title="is_&#8203;integer">is_&#8203;integer</a>
                        </li>
                                                <li class="">
                            <a href="function.is-iterable.php" title="is_&#8203;iterable">is_&#8203;iterable</a>
                        </li>
                                                <li class="">
                            <a href="function.is-long.php" title="is_&#8203;long">is_&#8203;long</a>
                        </li>
                                                <li class="">
                            <a href="function.is-null.php" title="is_&#8203;null">is_&#8203;null</a>
                        </li>
                                                <li class="">
                            <a href="function.is-numeric.php" title="is_&#8203;numeric">is_&#8203;numeric</a>
                        </li>
                                                <li class="">
                            <a href="function.is-object.php" title="is_&#8203;object">is_&#8203;object</a>
                        </li>
                                                <li class="">
                            <a href="function.is-real.php" title="is_&#8203;real">is_&#8203;real</a>
                        </li>
                                                <li class="">
                            <a href="function.is-resource.php" title="is_&#8203;resource">is_&#8203;resource</a>
                        </li>
                                                <li class="">
                            <a href="function.is-scalar.php" title="is_&#8203;scalar">is_&#8203;scalar</a>
                        </li>
                                                <li class="">
                            <a href="function.is-string.php" title="is_&#8203;string">is_&#8203;string</a>
                        </li>
                                                <li class="">
                            <a href="function.isset.php" title="isset">isset</a>
                        </li>
                                                <li class="">
                            <a href="function.print-r.php" title="print_&#8203;r">print_&#8203;r</a>
                        </li>
                                                <li class="">
                            <a href="function.serialize.php" title="serialize">serialize</a>
                        </li>
                                                <li class="current">
                            <a href="function.settype.php" title="settype">settype</a>
                        </li>
                                                <li class="">
                            <a href="function.strval.php" title="strval">strval</a>
                        </li>
                                                <li class="">
                            <a href="function.unserialize.php" title="unserialize">unserialize</a>
                        </li>
                                                <li class="">
                            <a href="function.unset.php" title="unset">unset</a>
                        </li>
                                                <li class="">
                            <a href="function.var-dump.php" title="var_&#8203;dump">var_&#8203;dump</a>
                        </li>
                                                <li class="">
                            <a href="function.var-export.php" title="var_&#8203;export">var_&#8203;export</a>
                        </li>
                        
                    </ul>
                
            </li>
                        
                        <li>
                <span class="header">Deprecated</span>
                <ul class="child-menu-list">
                                    <li class="">
                        <a href="function.import-request-variables.php" title="import_&#8203;request_&#8203;variables">import_&#8203;request_&#8203;variables</a>
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
