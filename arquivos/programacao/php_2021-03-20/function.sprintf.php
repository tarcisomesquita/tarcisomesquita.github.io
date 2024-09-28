<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="pt_BR">
<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: sprintf - Manual </title>

 <link rel="shortcut icon" href="https://www.php.net/favicon.ico">
 <link rel="search" type="application/opensearchdescription+xml" href="http://php.net/phpnetimprovedsearch.src" title="Add PHP.net search">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/releases/feed.php" title="PHP Release feed">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/feed.atom" title="PHP: Hypertext Preprocessor">

 <link rel="canonical" href="https://www.php.net/manual/pt_BR/function.sprintf.php">
 <link rel="shorturl" href="https://www.php.net/sprintf">
 <link rel="alternate" href="https://www.php.net/sprintf" hreflang="x-default">

 <link rel="contents" href="https://www.php.net/manual/pt_BR/index.php">
 <link rel="index" href="https://www.php.net/manual/pt_BR/ref.strings.php">
 <link rel="prev" href="https://www.php.net/manual/pt_BR/function.soundex.php">
 <link rel="next" href="https://www.php.net/manual/pt_BR/function.sscanf.php">

 <link rel="alternate" href="https://www.php.net/manual/en/function.sprintf.php" hreflang="en">
 <link rel="alternate" href="https://www.php.net/manual/pt_BR/function.sprintf.php" hreflang="pt_BR">
 <link rel="alternate" href="https://www.php.net/manual/zh/function.sprintf.php" hreflang="zh">
 <link rel="alternate" href="https://www.php.net/manual/fr/function.sprintf.php" hreflang="fr">
 <link rel="alternate" href="https://www.php.net/manual/de/function.sprintf.php" hreflang="de">
 <link rel="alternate" href="https://www.php.net/manual/ja/function.sprintf.php" hreflang="ja">
 <link rel="alternate" href="https://www.php.net/manual/ro/function.sprintf.php" hreflang="ro">
 <link rel="alternate" href="https://www.php.net/manual/ru/function.sprintf.php" hreflang="ru">
 <link rel="alternate" href="https://www.php.net/manual/es/function.sprintf.php" hreflang="es">
 <link rel="alternate" href="https://www.php.net/manual/tr/function.sprintf.php" hreflang="tr">

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

 <base href="https://www.php.net/manual/pt_BR/function.sprintf.php">

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
        <a href="function.sscanf.php">
          sscanf &raquo;
        </a>
      </div>
              <div class="prev">
        <a href="function.soundex.php">
          &laquo; soundex        </a>
      </div>
          <ul>
            <li><a href='index.php'>Manual do PHP</a></li>      <li><a href='funcref.php'>Refer&ecirc;ncia das Fun&ccedil;&otilde;es</a></li>      <li><a href='refs.basic.text.php'>Processamento de Texto</a></li>      <li><a href='book.strings.php'>Strings</a></li>      <li><a href='ref.strings.php'>Fun&ccedil;&otilde;es para String</a></li>      </ul>
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
            <option value='en/function.sprintf.php'>English</option>
            <option value='pt_BR/function.sprintf.php' selected="selected">Brazilian Portuguese</option>
            <option value='zh/function.sprintf.php'>Chinese (Simplified)</option>
            <option value='fr/function.sprintf.php'>French</option>
            <option value='de/function.sprintf.php'>German</option>
            <option value='ja/function.sprintf.php'>Japanese</option>
            <option value='ro/function.sprintf.php'>Romanian</option>
            <option value='ru/function.sprintf.php'>Russian</option>
            <option value='es/function.sprintf.php'>Spanish</option>
            <option value='tr/function.sprintf.php'>Turkish</option>
            <option value="help-translate.php">Other</option>
          </select>
        </fieldset>
      </form>
    </div>
    <div class="edit-bug">
      <a href="https://edit.php.net/?project=PHP&amp;perm=pt_BR/function.sprintf.php">Edit</a>
      <a href="https://bugs.php.net/report.php?bug_type=Documentation+problem&amp;manpage=function.sprintf">Report a Bug</a>
    </div>
  </div><div id="function.sprintf" class="refentry">
 <div class="refnamediv">
  <h1 class="refname">sprintf</h1>
  <p class="verinfo">(PHP 4, PHP 5, PHP 7)</p><p class="refpurpose"><span class="refname">sprintf</span> &mdash; <span class="dc-title">Retorna a string formatada</span></p>

 </div>
 
 <div class="refsect1 description" id="refsect1-function.sprintf-description">
  <h3 class="title">Descrição</h3>
  <div class="methodsynopsis dc-description">
   <span class="methodname"><strong>sprintf</strong></span>
    ( <span class="methodparam"><span class="type">string</span> <code class="parameter">$format</code></span>
   [, <span class="methodparam"><span class="type"><a href="language.pseudo-types.php#language.types.mixed" class="type mixed">mixed</a></span> <code class="parameter">$args</code></span>
   [, <span class="methodparam"><span class="type"><a href="language.pseudo-types.php#language.types.mixed" class="type mixed">mixed</a></span> <code class="parameter">$...</code></span>
  ]] ) : <span class="type">string</span></div>

  <p class="para rdfs-comment">
   Retorna uma string produzida de acordo com a string de formatação
   <code class="parameter">format</code>.
  </p>
 </div>


 <div class="refsect1 parameters" id="refsect1-function.sprintf-parameters">
  <h3 class="title">Parâmetros</h3>
  <p class="para">
   <dl>

    
     <dt>
<code class="parameter">format</code></dt>

     <dd>

      <p class="para">
     A string e formatação é composta de zero ou mais diretivas:
     caracteres normais (excluindo <em>%</em>) que são copiados diretamente 
     para o resultado, e <em class="emphasis">especificações de conversão</em>,
     cada um dos quais resulta em obter o seu próprio parâmetro. 
     Isto se aplica para <span class="function"><strong>sprintf()</strong></span>
     e <span class="function"><a href="function.printf.php" class="function">printf()</a></span>.
    </p>
    <p class="para">
     Cada especificação de conversão consiste em um símbolo de porcento
     (<em>%</em>), seguido por um ou mais destes elementos em ordem:
     <ol type="1">
      <li class="listitem">
       <span class="simpara">
         Um opcional <em class="emphasis">sinal especificador</em> que indica
          (- ou +) pode ser usado no número. Por padrão, somente o sinal - é usado
          no número se ele é negativo. Este especificador força números positivos
          a ter o sinal +, foi adicionado no PHP 4.3.0.
         </span>
        </li>
        <li class="listitem">
         <span class="simpara">
        Um <em class="emphasis">especificador de prenchimento</em> opcional que diz
        qual caractere será usado para prencher o resultado para
        o tamanho certo. Isto pode ser um espaço ou
        <em>0</em> (zero character). O padrão é prencher com
        espaços. Um caractere alternativo de prenchimento pode
        ser especificado colocando uma aspa simples (<em>&#039;</em>)
        antes. Veja os exemplos abaixo.
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        Um <em class="emphasis">especificador de alinhamento</em> opcional que diz se o resultado
        deve ser alinhado a esquerda ou a direita.
        O padrão é alinhar a direita; um caractere <em>-</em>
        fará com que seja alinhado a esquerda.
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        Um número opcional, um <em class="emphasis">especificador de tamanho</em>
        que diz quantos caracteres (mínimo) deve resultar desta conversão.
       </span>
      </li>
      <li class="listitem">
       <span class="simpara">
        Um <em class="emphasis">especificador de precisão</em> opcional que diz
        quantos digitos decimais devem ser mostrados para números de ponto flutuante.
        Quando usando este especificador na string, ele age como um
        ponto delimitador, definindo o máximo de caracteres limit para a string.
       </span>
      </li>
      <li class="listitem">
       <p class="para">
        Um <em class="emphasis">especificador de tipo</em> que diz que o argumento deve ser
        tratado como do tipo. Os tipos possivéis são:
        <ul class="simplelist">
         <li class="member">
          <em>%</em> - Um caractere porcento. Não
          é requerido neenhum argumento.
         </li>
         <li class="member">
          <em>b</em> - O argumento é tratado com um inteiro,
          e mostrado como um binário.
         </li>
         <li class="member">
          <em>c</em> - O argumento é tratado como um inteiro,
          e mostrado como o caractere ASCII correspondente.
         </li>
         <li class="member">
          <em>d</em> - O argumento é tratado como um inteiro,
          e mostrado como um número decimal com sinal.
         </li>
         <li class="member">
            <em>e</em> - o argumento é tratado como notação
            científica (e.g. 1.2e+2).
            O especificador de precisão indica o número de dígitos depois do
            ponto decimal desde o PHP 5.2.1. Em versões anteriores, ele pegava
            o número de dígitos significantes (ou menos).
         </li>
           <li class="member">
          <em>u</em> - O argumento é tratado com um inteiro,
          e mostrado como um número decimal sem sinal.
         </li>
         <li class="member">
          <em>f</em> - O argumento é tratado como um float,
          e mostrado como um número de ponto flutuante (do locale).
         </li>
           <li class="member">
            <em>F</em> - o argumento é tratado como um
            float, e mostrado como um número de ponto flutuante (não usado o locale).
            Disponível desde o PHP 4.3.10 e PHP 5.0.3.
           </li>
         <li class="member">
          <em>o</em> - O argumento é tratado com um inteiro,
          e mostrado como un número octal.
         </li>
         <li class="member">
          <em>s</em> - O argumento é tratado e mostrado como
          uma string.
         </li>
         <li class="member">
          <em>x</em> - O argumento é tratado como um inteiro,
          e mostrado como um número hexadecimal
          (com as letras minúsculas).
         </li>
         <li class="member">
          <em>X</em> - O argumento é tratado como um inteiro,
          e mostrado como um número hexadecimal
          (com as letras maiúsculas).
         </li>
        </ul>
       </p>
      </li>
     </ol>
    </p>
    <p class="para">
     A string de formato suporta argumentos com numeração/troca. Aqui está um exemplo:
     <div class="example" id="example-5835">
      <p><strong>Exemplo #1 Troca de argumentos</strong></p>
      <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$format&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'There&nbsp;are&nbsp;%d&nbsp;monkeys&nbsp;in&nbsp;the&nbsp;%s'</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #0000BB">$format</span><span style="color: #007700">,</span><span style="color: #0000BB">$num</span><span style="color: #007700">,</span><span style="color: #0000BB">$location</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
      </div>

     </div>
     Este deve mostrar, &quot;There are 5 monkeys in the tree&quot;. Mas 
     imagine que nós estejamos criando a string de formatação em um arquivo separado,
     normalmente para internacionalizar e rescrevemos como:
     <div class="example" id="example-5836">
      <p><strong>Exemplo #2 Troca de argumentos</strong></p>
      <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$format&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'The&nbsp;%s&nbsp;contains&nbsp;%d&nbsp;monkeys'</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #0000BB">$format</span><span style="color: #007700">,</span><span style="color: #0000BB">$num</span><span style="color: #007700">,</span><span style="color: #0000BB">$location</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
      </div>

     </div>
     Agora nós temos um problema. A ordem dos argumentos
     na string de formatação não combina com os argumentos no código.
     Nós gostariamos de deixar o código como esta e simplesmente
     indicar na string de formatação quais argumentos pertencem aonde.
     Podemos escrever a string de formatação assim:
     <div class="example" id="example-5837">
      <p><strong>Exemplo #3 Troca de argumento</strong></p>
      <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$format&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'The&nbsp;%2$s&nbsp;contains&nbsp;%1$d&nbsp;monkeys'</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #0000BB">$format</span><span style="color: #007700">,</span><span style="color: #0000BB">$num</span><span style="color: #007700">,</span><span style="color: #0000BB">$location</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
      </div>

     </div>
     Um beneficio adicional disto é ue você pode repetir os especificadores de
     conversão sem adicionar mais argumentos em seu código. Por exemplo:
     <div class="example" id="example-5838">
      <p><strong>Exemplo #4 Troca de argumento</strong></p>
      <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$format&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'The&nbsp;%2$s&nbsp;contains&nbsp;%1$d&nbsp;monkeys.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;That\'s&nbsp;a&nbsp;nice&nbsp;%2$s&nbsp;full&nbsp;of&nbsp;%1$d&nbsp;monkeys.'</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #0000BB">$format</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$num</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$location</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
        </div>

       </div>
      </p>
     </dd>

    
    
     <dt>
<code class="parameter">args</code></dt>

     <dd>

      <p class="para">
      </p>
     </dd>

    
    
     <dt>
<code class="parameter">...</code></dt>

     <dd>

      <p class="para">
      </p>
     </dd>

    
   </dl>

  </p>
 </div>


 <div class="refsect1 returnvalues" id="refsect1-function.sprintf-returnvalues">
  <h3 class="title">Valor Retornado</h3>
  <p class="para">
   Retorna a string produzida de acordo com as strings de formatação
   <code class="parameter">format</code>.
  </p>
 </div>


 <div class="refsect1 changelog" id="refsect1-function.sprintf-changelog">
  <h3 class="title">Changelog</h3>
  <p class="para">
   <table class="doctable informaltable">
    
     <thead>
      <tr>
       <th>Versão</th>
       <th>Descrição</th>
      </tr>

     </thead>

     <tbody class="tbody">
      <tr>
       <td>4.0.6</td>
       <td>
        Suporte para argumento numerado/troca foi adicionado
       </td>
      </tr>

     </tbody>
    
   </table>

  </p>
 </div>


 <div class="refsect1 examples" id="refsect1-function.sprintf-examples">
  <h3 class="title">Exemplos</h3>
  <div class="example" id="example-5839">
   <p><strong>Exemplo #5 <span class="function"><a href="function.printf.php" class="function">printf()</a></span>: vários exemplos</strong></p>
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$n&nbsp;</span><span style="color: #007700">=&nbsp;&nbsp;</span><span style="color: #0000BB">43951789</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$u&nbsp;</span><span style="color: #007700">=&nbsp;-</span><span style="color: #0000BB">43951789</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$c&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">65</span><span style="color: #007700">;&nbsp;</span><span style="color: #FF8000">//&nbsp;ASCII&nbsp;65&nbsp;is&nbsp;'A'<br /><br />//&nbsp;notice&nbsp;the&nbsp;double&nbsp;%%,&nbsp;this&nbsp;prints&nbsp;a&nbsp;literal&nbsp;'%'&nbsp;character<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%b&nbsp;=&nbsp;'%b'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;binary&nbsp;representation<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%c&nbsp;=&nbsp;'%c'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$c</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;print&nbsp;the&nbsp;ascii&nbsp;character,&nbsp;same&nbsp;as&nbsp;chr()&nbsp;function<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%d&nbsp;=&nbsp;'%d'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;standard&nbsp;integer&nbsp;representation<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%e&nbsp;=&nbsp;'%e'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;scientific&nbsp;notation<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%u&nbsp;=&nbsp;'%u'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;unsigned&nbsp;integer&nbsp;representation&nbsp;of&nbsp;a&nbsp;positive&nbsp;integer<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%u&nbsp;=&nbsp;'%u'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$u</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;unsigned&nbsp;integer&nbsp;representation&nbsp;of&nbsp;a&nbsp;negative&nbsp;integer<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%f&nbsp;=&nbsp;'%f'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;floating&nbsp;point&nbsp;representation<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%o&nbsp;=&nbsp;'%o'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;octal&nbsp;representation<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%s&nbsp;=&nbsp;'%s'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;string&nbsp;representation<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%x&nbsp;=&nbsp;'%x'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;hexadecimal&nbsp;representation&nbsp;(lower-case)<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%X&nbsp;=&nbsp;'%X'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;hexadecimal&nbsp;representation&nbsp;(upper-case)<br /><br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%+d&nbsp;=&nbsp;'%+d'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$n</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;sign&nbsp;specifier&nbsp;on&nbsp;a&nbsp;positive&nbsp;integer<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%%+d&nbsp;=&nbsp;'%+d'\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$u</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;sign&nbsp;specifier&nbsp;on&nbsp;a&nbsp;negative&nbsp;integer<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

   <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
   <div class="example-contents screen">
<div class="cdata"><pre>
%b = &#039;10100111101010011010101101&#039;
%c = &#039;A&#039;
%d = &#039;43951789&#039;
%e = &#039;4.39518e+7&#039;
%u = &#039;43951789&#039;
%u = &#039;4251015507&#039;
%f = &#039;43951789.000000&#039;
%o = &#039;247523255&#039;
%s = &#039;43951789&#039;
%x = &#039;29ea6ad&#039;
%X = &#039;29EA6AD&#039;
%+d = &#039;+43951789&#039;
%+d = &#039;-43951789&#039;
</pre></div>
   </div>
  </div>
  <div class="example" id="example-5840">
   <p><strong>Exemplo #6 <span class="function"><a href="function.printf.php" class="function">printf()</a></span>: especificadores de string</strong></p>
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$s&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'monkey'</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$t&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #DD0000">'many&nbsp;monkeys'</span><span style="color: #007700">;<br /><br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"[%s]\n"</span><span style="color: #007700">,&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #0000BB">$s</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;standard&nbsp;string&nbsp;output<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"[%10s]\n"</span><span style="color: #007700">,&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #0000BB">$s</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;right-justification&nbsp;with&nbsp;spaces<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"[%-10s]\n"</span><span style="color: #007700">,&nbsp;&nbsp;&nbsp;</span><span style="color: #0000BB">$s</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;left-justification&nbsp;with&nbsp;spaces<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"[%010s]\n"</span><span style="color: #007700">,&nbsp;&nbsp;&nbsp;</span><span style="color: #0000BB">$s</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;zero-padding&nbsp;works&nbsp;on&nbsp;strings&nbsp;too<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"[%'#10s]\n"</span><span style="color: #007700">,&nbsp;&nbsp;</span><span style="color: #0000BB">$s</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;use&nbsp;the&nbsp;custom&nbsp;padding&nbsp;character&nbsp;'#'<br /></span><span style="color: #0000BB">printf</span><span style="color: #007700">(</span><span style="color: #DD0000">"[%10.10s]\n"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$t</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;left-justification&nbsp;but&nbsp;with&nbsp;a&nbsp;cutoff&nbsp;of&nbsp;10&nbsp;characters<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

   <div class="example-contents"><p>O exemplo acima irá imprimir:</p></div>
   <div class="example-contents screen">
<div class="cdata"><pre>
[monkey]
[    monkey]
[monkey    ]
[0000monkey]
[####monkey]
[many monke]
</pre></div>
   </div>
  </div>
     <div class="example" id="example-5841">
      <p><strong>Exemplo #7 <span class="function"><strong>sprintf()</strong></span>: inteiros prenchidos com zero</strong></p>
      <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$isodate&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">sprintf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%04d-%02d-%02d"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$year</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$month</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$day</span><span style="color: #007700">);<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
      </div>

     </div>
     <div class="example" id="example-5842">
      <p><strong>Exemplo #8 <span class="function"><strong>sprintf()</strong></span>: formatando dinheiro</strong></p>
      <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$money1&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">68.75</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$money2&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">54.35</span><span style="color: #007700">;<br /></span><span style="color: #0000BB">$money&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">$money1&nbsp;</span><span style="color: #007700">+&nbsp;</span><span style="color: #0000BB">$money2</span><span style="color: #007700">;<br /></span><span style="color: #FF8000">//&nbsp;echo&nbsp;$money&nbsp;irá&nbsp;mostrar&nbsp;"123.1";<br /></span><span style="color: #0000BB">$formatted&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">sprintf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%01.2f"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$money</span><span style="color: #007700">);<br /></span><span style="color: #FF8000">//&nbsp;echo&nbsp;$formatted&nbsp;irá&nbsp;mostrar&nbsp;"123.10"<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
      </div>

     </div>
  <div class="example" id="example-5843">
   <p><strong>Exemplo #9 <span class="function"><strong>sprintf()</strong></span>: notação científica</strong></p>
   <div class="example-contents">
<div class="phpcode"><code><span style="color: #000000">
<span style="color: #0000BB">&lt;?php<br />$number&nbsp;</span><span style="color: #007700">=&nbsp;</span><span style="color: #0000BB">362525200</span><span style="color: #007700">;<br /><br />echo&nbsp;</span><span style="color: #0000BB">sprintf</span><span style="color: #007700">(</span><span style="color: #DD0000">"%.3e"</span><span style="color: #007700">,&nbsp;</span><span style="color: #0000BB">$number</span><span style="color: #007700">);&nbsp;</span><span style="color: #FF8000">//&nbsp;imprime&nbsp;3.625e+8<br /></span><span style="color: #0000BB">?&gt;</span>
</span>
</code></div>
   </div>

  </div>
 </div>


 <div class="refsect1 seealso" id="refsect1-function.sprintf-seealso">
  <h3 class="title">Veja Também</h3>
  <p class="para">
   <ul class="simplelist">
    <li class="member"><span class="function"><a href="function.printf.php" class="function" rel="rdfs-seeAlso">printf()</a> - Mostra uma string formatada</span></li>
    <li class="member"><span class="function"><a href="function.sscanf.php" class="function" rel="rdfs-seeAlso">sscanf()</a> - Interpreta a entrada de uma string de acordo com um formato</span></li>
    <li class="member"><span class="function"><a href="function.fscanf.php" class="function" rel="rdfs-seeAlso">fscanf()</a> - Interpreta a leitura de um arquivo de acordo com um formato</span></li>
    <li class="member"><span class="function"><a href="function.vsprintf.php" class="function" rel="rdfs-seeAlso">vsprintf()</a> - Retorna uma string formatada</span></li>
    <li class="member"><span class="function"><a href="function.number-format.php" class="function" rel="rdfs-seeAlso">number_format()</a> - Formata um n&uacute;mero com os milhares agrupados</span></li>
   </ul>
  </p>
 </div>

</div>
<section id="usernotes">
 <div class="head">
  <span class="action"><a href="/manual/add-note.php?sect=function.sprintf&amp;redirect=https://www.php.net/manual/pt_BR/function.sprintf.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></span>
  <h3 class="title">User Contributed Notes <span class="count">41 notes</span></h3>
 </div><div id="allnotes">
  <div class="note" id="111201">  <div class="votes">
    <div id="Vu111201">
    <a href="/manual/vote-note.php?id=111201&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd111201">
    <a href="/manual/vote-note.php?id=111201&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V111201" title="73% like this...">
    53
    </div>
  </div>
  <a href="#111201" class="name">
  <strong class="user"><em>Alex R. Gibbs</em></strong></a><a class="genanchor" href="#111201"> &para;</a><div class="date" title="2013-01-25 08:17"><strong>6 years ago</strong></div>
  <div class="text" id="Hcom111201">
<div class="phpcode"><code><span class="html">
1.&nbsp; A plus sign ('+') means put a '+' before positive numbers while a minus sign ('-') means left justify.&nbsp; The documentation incorrectly states that they are interchangeable.&nbsp; They produce unique results that can be combined:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%+4d|%+4d|\n"</span><span class="keyword">,&nbsp;&nbsp; </span><span class="default">1</span><span class="keyword">, -</span><span class="default">1</span><span class="keyword">);<br />echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%-4d|%-4d|\n"</span><span class="keyword">,&nbsp;&nbsp; </span><span class="default">1</span><span class="keyword">, -</span><span class="default">1</span><span class="keyword">);<br />echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%+-4d|%+-4d|\n"</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">, -</span><span class="default">1</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />outputs:<br /><br />|&nbsp; +1|&nbsp; -1|<br />|1&nbsp;&nbsp; |-1&nbsp; |<br />|+1&nbsp; |-1&nbsp; |<br /><br />2.&nbsp; Padding with a '0' is different than padding with other characters.&nbsp; Zeros will only be added at the front of a number, after any sign.&nbsp; Other characters will be added before the sign, or after the number:<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%04d|\n"</span><span class="keyword">,&nbsp;&nbsp; -</span><span class="default">2</span><span class="keyword">);<br />echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%':4d|\n"</span><span class="keyword">,&nbsp; -</span><span class="default">2</span><span class="keyword">);<br />echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%-':4d|\n"</span><span class="keyword">, -</span><span class="default">2</span><span class="keyword">);<br /><br /></span><span class="comment">// Specifying both "-" and "0" creates a conflict with unexpected results:<br /></span><span class="keyword">echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%-04d|\n"</span><span class="keyword">,&nbsp; -</span><span class="default">2</span><span class="keyword">);<br /><br /></span><span class="comment">// Padding with other digits behaves like other non-zero characters:<br /></span><span class="keyword">echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%-'14d|\n"</span><span class="keyword">, -</span><span class="default">2</span><span class="keyword">);<br />echo </span><span class="default">sprintf </span><span class="keyword">(</span><span class="string">"|%-'04d|\n"</span><span class="keyword">, -</span><span class="default">2</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />outputs:<br /><br />|-002|<br />|::-2|<br />|-2::|<br />|-2&nbsp; |<br />|-211|<br />|-2&nbsp; |</span>
</code></div>
  </div>
 </div>
  <div class="note" id="88218">  <div class="votes">
    <div id="Vu88218">
    <a href="/manual/vote-note.php?id=88218&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd88218">
    <a href="/manual/vote-note.php?id=88218&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V88218" title="81% like this...">
    44
    </div>
  </div>
  <a href="#88218" class="name">
  <strong class="user"><em>remy dot damour at -please-no-spam-laposte dot net</em></strong></a><a class="genanchor" href="#88218"> &para;</a><div class="date" title="2009-01-15 11:15"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom88218">
<div class="phpcode"><code><span class="html">
With printf() and sprintf() functions, escape character is not backslash '\' but rather '%'.<br /><br />Ie. to print '%' character you need to escape it with itself:<br /><span class="default">&lt;?php<br />printf</span><span class="keyword">(</span><span class="string">'%%%s%%'</span><span class="keyword">, </span><span class="string">'koko'</span><span class="keyword">); </span><span class="comment">#output: '%koko%'<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="122361">  <div class="votes">
    <div id="Vu122361">
    <a href="/manual/vote-note.php?id=122361&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd122361">
    <a href="/manual/vote-note.php?id=122361&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V122361" title="100% like this...">
    3
    </div>
  </div>
  <a href="#122361" class="name">
  <strong class="user"><em>thavarajan at gmail dot com</em></strong></a><a class="genanchor" href="#122361"> &para;</a><div class="date" title="2018-02-06 10:06"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom122361">
<div class="phpcode"><code><span class="html">
<span class="default">&lt;?php <br /></span><span class="keyword">echo </span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">"%+08d"</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">). </span><span class="string">"&lt;Br&gt;"</span><span class="keyword">;<br />echo </span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">"%+07d"</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">). </span><span class="string">"&lt;Br&gt;"</span><span class="keyword">;<br />echo </span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">"%+06d"</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">). </span><span class="string">"&lt;Br&gt;"</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span><br />Will produce an output<br />+0000000<br />+000000<br />+00000</span>
</code></div>
  </div>
 </div>
  <div class="note" id="116776">  <div class="votes">
    <div id="Vu116776">
    <a href="/manual/vote-note.php?id=116776&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd116776">
    <a href="/manual/vote-note.php?id=116776&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V116776" title="82% like this...">
    19
    </div>
  </div>
  <a href="#116776" class="name">
  <strong class="user"><em>kontakt at myseosolution dot de</em></strong></a><a class="genanchor" href="#116776"> &para;</a><div class="date" title="2015-02-26 10:34"><strong>4 years ago</strong></div>
  <div class="text" id="Hcom116776">
<div class="phpcode"><code><span class="html">
There are already some comments on using sprintf to force leading leading zeros but the examples only include integers. I needed leading zeros on floating point numbers and was surprised that it didn't work as expected.<br /><br />Example:<br /><span class="default">&lt;?php<br />sprintf</span><span class="keyword">(</span><span class="string">'%02d'</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />This will result in 01. However, trying the same for a float with precision doesn't work:<br /><br /><span class="default">&lt;?php<br />sprintf</span><span class="keyword">(</span><span class="string">'%02.2f'</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />Yields 1.00. <br /><br />This threw me a little off. To get the desired result, one needs to add the precision (2) and the length of the decimal seperator "." (1). So the correct pattern would be<br /><br /><span class="default">&lt;?php<br />sprintf</span><span class="keyword">(</span><span class="string">'%05.2f'</span><span class="keyword">, </span><span class="default">1</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />Output: 01.00<br /><br />Please see <a href="http://stackoverflow.com/a/28739819/413531" rel="nofollow" target="_blank">http://stackoverflow.com/a/28739819/413531</a> for a more detailed explanation.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="103755">  <div class="votes">
    <div id="Vu103755">
    <a href="/manual/vote-note.php?id=103755&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd103755">
    <a href="/manual/vote-note.php?id=103755&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V103755" title="84% like this...">
    9
    </div>
  </div>
  <a href="#103755" class="name">
  <strong class="user"><em>timo dot frenay at gmail dot com</em></strong></a><a class="genanchor" href="#103755"> &para;</a><div class="date" title="2011-05-02 05:38"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom103755">
<div class="phpcode"><code><span class="html">
Here is how to print a floating point number with 16 significant digits regardless of magnitude:<br /><br /><span class="default">&lt;?php<br />&nbsp; &nbsp; $result </span><span class="keyword">= </span><span class="default">sprintf</span><span class="keyword">(</span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">'%%.%dF'</span><span class="keyword">, </span><span class="default">max</span><span class="keyword">(</span><span class="default">15 </span><span class="keyword">- </span><span class="default">floor</span><span class="keyword">(</span><span class="default">log10</span><span class="keyword">(</span><span class="default">$value</span><span class="keyword">)), </span><span class="default">0</span><span class="keyword">)), </span><span class="default">$value</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />This works more reliably than doing something like sprintf('%.15F', $value) as the latter may cut off significant digits for very small numbers, or prints bogus digits (meaning extra digits beyond what can reliably be represented in a floating point number) for very large numbers.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="92157">  <div class="votes">
    <div id="Vu92157">
    <a href="/manual/vote-note.php?id=92157&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd92157">
    <a href="/manual/vote-note.php?id=92157&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V92157" title="75% like this...">
    10
    </div>
  </div>
  <a href="#92157" class="name">
  <strong class="user"><em>jfgrissom at gmail dot com</em></strong></a><a class="genanchor" href="#92157"> &para;</a><div class="date" title="2009-07-11 09:51"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom92157">
<div class="phpcode"><code><span class="html">
I had a nightmare trying to find the two's complement of a 32 bit number.<br /><br />I got this from <a href="http://www.webmasterworld.com/forum88/13334.htm" rel="nofollow" target="_blank">http://www.webmasterworld.com/forum88/13334.htm</a> (credit where credit is due... =P&nbsp; )<br /><br />Quote: ...find out the 2's complement of any number, which is -(pow(2, n) - N) where n is the number of bits and N is the number for which to find out its 2's complement.<br /><br />This worked magic for me... previously I was trying to use<br /><br />sprintf ("%b",$32BitDecimal);<br />But it always returned 10000000000000000000000 when the $32BitDecimal value got above 2,000,000,000.<br /><br />This -(pow(2, n) - N)<br />Worked remarkably well and was very accurate.<br /><br />Hope this helps someone fighting with two's complement in PHP.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="42224">  <div class="votes">
    <div id="Vu42224">
    <a href="/manual/vote-note.php?id=42224&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd42224">
    <a href="/manual/vote-note.php?id=42224&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V42224" title="73% like this...">
    9
    </div>
  </div>
  <a href="#42224" class="name">
  <strong class="user"><em>php at sharpdreams dot com</em></strong></a><a class="genanchor" href="#42224"> &para;</a><div class="date" title="2004-05-08 02:13"><strong>15 years ago</strong></div>
  <div class="text" id="Hcom42224">
<div class="phpcode"><code><span class="html">
Note that when using the argument swapping, you MUST number every argument, otherwise sprintf gets confused. This only happens if you use number arguments first, then switch to a non-numbered, and then back to a numbered one.<br /><br /><span class="default">&lt;?php<br />$sql </span><span class="keyword">= </span><span class="default">sprintf</span><span class="keyword">( </span><span class="string">"select * from %1\$s left join %2\$s on( %1\$s.id = %2\$s.midpoint ) where %1\$s.name like '%%%s%%' and %2\$s.tagname is not null"</span><span class="keyword">, </span><span class="string">"table1"</span><span class="keyword">, </span><span class="string">"table2"</span><span class="keyword">, </span><span class="string">"bob" </span><span class="keyword">);<br /></span><span class="comment">// Wont work:<br />// Sprintf will complain about not enough arguments.<br /></span><span class="default">$sql </span><span class="keyword">= </span><span class="default">sprintf</span><span class="keyword">( </span><span class="string">"select * from %1\$s left join %2\$s on( %1\$s.id = %2\$s.midpoint ) where %1\$s.name like '%%%3\$s%%' and %2\$s.tagname is not null"</span><span class="keyword">, </span><span class="string">"table1"</span><span class="keyword">, </span><span class="string">"table2"</span><span class="keyword">, </span><span class="string">"bob" </span><span class="keyword">);<br /></span><span class="comment">// Will work: note the %3\$s<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="115088">  <div class="votes">
    <div id="Vu115088">
    <a href="/manual/vote-note.php?id=115088&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd115088">
    <a href="/manual/vote-note.php?id=115088&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V115088" title="71% like this...">
    6
    </div>
  </div>
  <a href="#115088" class="name">
  <strong class="user"><em>john at jbwalker dot com</em></strong></a><a class="genanchor" href="#115088"> &para;</a><div class="date" title="2014-05-24 12:24"><strong>5 years ago</strong></div>
  <div class="text" id="Hcom115088">
<div class="phpcode"><code><span class="html">
I couldn't find what should be a WARNING in the documentation above, that if you have more specifiers than variables to match them sprintf returns NOTHING. This fact, IMHO, should also be noted under return values.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="25243">  <div class="votes">
    <div id="Vu25243">
    <a href="/manual/vote-note.php?id=25243&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd25243">
    <a href="/manual/vote-note.php?id=25243&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V25243" title="75% like this...">
    4
    </div>
  </div>
  <a href="#25243" class="name">
  <strong class="user"><em>no dot email dot address at example dot com</em></strong></a><a class="genanchor" href="#25243"> &para;</a><div class="date" title="2002-09-16 06:29"><strong>17 years ago</strong></div>
  <div class="text" id="Hcom25243">
<div class="phpcode"><code><span class="html">
Using argument swapping in sprintf() with gettext: Let's say you've written the following script:<br /><br /><span class="default">&lt;?php<br />$var </span><span class="keyword">= </span><span class="default">sprintf</span><span class="keyword">(</span><span class="default">gettext</span><span class="keyword">(</span><span class="string">"The %2\$s contains %1\$d monkeys"</span><span class="keyword">), </span><span class="default">2</span><span class="keyword">, </span><span class="string">"cage"</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />Now you run xgettext in order to generate a .po file. The .po file will then look like this:<br /><br />#: file.php:9<br />#, ycp-format<br />msgid "The %2\\$s contains %1\\$d monkeys"<br />msgstr ""<br /><br />Notice how an extra backslash has been added by xgettext.<br /><br />Once you've translated the string, you must remove all backslashes from the ID string as well as the translation, so the po file will look like this:<br /><br />#: file.php:9<br />#, ycp-format<br />msgid "The %2$s contains %1$d monkeys"<br />msgstr "Der er %1$d aber i %2$s"<br /><br />Now run msgfmt to generate the .mo file, restart Apache to remove the gettext cache if necessary, and you're off.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="89020">  <div class="votes">
    <div id="Vu89020">
    <a href="/manual/vote-note.php?id=89020&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd89020">
    <a href="/manual/vote-note.php?id=89020&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V89020" title="70% like this...">
    8
    </div>
  </div>
  <a href="#89020" class="name">
  <strong class="user"><em>viktor at textalk dot com</em></strong></a><a class="genanchor" href="#89020"> &para;</a><div class="date" title="2009-02-18 08:16"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom89020">
<div class="phpcode"><code><span class="html">
A more complete and working version of mb_sprintf and mb_vsprintf. It should work with any "ASCII preserving" encoding such as UTF-8 and all the ISO-8859 charsets. It handles sign, padding, alignment, width and precision. Argument swapping is not handled.<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">if (!</span><span class="default">function_exists</span><span class="keyword">(</span><span class="string">'mb_sprintf'</span><span class="keyword">)) {<br />&nbsp; function </span><span class="default">mb_sprintf</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$argv </span><span class="keyword">= </span><span class="default">func_get_args</span><span class="keyword">() ;<br />&nbsp; &nbsp; &nbsp; </span><span class="default">array_shift</span><span class="keyword">(</span><span class="default">$argv</span><span class="keyword">) ;<br />&nbsp; &nbsp; &nbsp; return </span><span class="default">mb_vsprintf</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">$argv</span><span class="keyword">) ;<br />&nbsp; }<br />}<br />if (!</span><span class="default">function_exists</span><span class="keyword">(</span><span class="string">'mb_vsprintf'</span><span class="keyword">)) {<br />&nbsp; </span><span class="comment">/**<br />&nbsp;&nbsp; * Works with all encodings in format and arguments.<br />&nbsp;&nbsp; * Supported: Sign, padding, alignment, width and precision.<br />&nbsp;&nbsp; * Not supported: Argument swapping.<br />&nbsp;&nbsp; */<br />&nbsp; </span><span class="keyword">function </span><span class="default">mb_vsprintf</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">$argv</span><span class="keyword">, </span><span class="default">$encoding</span><span class="keyword">=</span><span class="default">null</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; if (</span><span class="default">is_null</span><span class="keyword">(</span><span class="default">$encoding</span><span class="keyword">))<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$encoding </span><span class="keyword">= </span><span class="default">mb_internal_encoding</span><span class="keyword">();<br /><br />&nbsp; &nbsp; &nbsp; </span><span class="comment">// Use UTF-8 in the format so we can use the u flag in preg_split<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$format </span><span class="keyword">= </span><span class="default">mb_convert_encoding</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="string">'UTF-8'</span><span class="keyword">, </span><span class="default">$encoding</span><span class="keyword">);<br /><br />&nbsp; &nbsp; &nbsp; </span><span class="default">$newformat </span><span class="keyword">= </span><span class="string">""</span><span class="keyword">; </span><span class="comment">// build a new format in UTF-8<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$newargv </span><span class="keyword">= array(); </span><span class="comment">// unhandled args in unchanged encoding<br /><br />&nbsp; &nbsp; &nbsp; </span><span class="keyword">while (</span><span class="default">$format </span><span class="keyword">!== </span><span class="string">""</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// Split the format in two parts: $pre and $post by the first %-directive<br />&nbsp; &nbsp; &nbsp; &nbsp; // We get also the matched groups<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">list (</span><span class="default">$pre</span><span class="keyword">, </span><span class="default">$sign</span><span class="keyword">, </span><span class="default">$filler</span><span class="keyword">, </span><span class="default">$align</span><span class="keyword">, </span><span class="default">$size</span><span class="keyword">, </span><span class="default">$precision</span><span class="keyword">, </span><span class="default">$type</span><span class="keyword">, </span><span class="default">$post</span><span class="keyword">) =<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">preg_split</span><span class="keyword">(</span><span class="string">"!\%(\+?)('.|[0 ]|)(-?)([1-9][0-9]*|)(\.[1-9][0-9]*|)([%a-zA-Z])!u"</span><span class="keyword">,<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="default">$format</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">, </span><span class="default">PREG_SPLIT_DELIM_CAPTURE</span><span class="keyword">) ;<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$newformat </span><span class="keyword">.= </span><span class="default">mb_convert_encoding</span><span class="keyword">(</span><span class="default">$pre</span><span class="keyword">, </span><span class="default">$encoding</span><span class="keyword">, </span><span class="string">'UTF-8'</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$type </span><span class="keyword">== </span><span class="string">''</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// didn't match. do nothing. this is the last iteration.<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">}<br />&nbsp; &nbsp; &nbsp; &nbsp; elseif (</span><span class="default">$type </span><span class="keyword">== </span><span class="string">'%'</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// an escaped %<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$newformat </span><span class="keyword">.= </span><span class="string">'%%'</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; elseif (</span><span class="default">$type </span><span class="keyword">== </span><span class="string">'s'</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg </span><span class="keyword">= </span><span class="default">array_shift</span><span class="keyword">(</span><span class="default">$argv</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg </span><span class="keyword">= </span><span class="default">mb_convert_encoding</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">, </span><span class="string">'UTF-8'</span><span class="keyword">, </span><span class="default">$encoding</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$padding_pre </span><span class="keyword">= </span><span class="string">''</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$padding_post </span><span class="keyword">= </span><span class="string">''</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// truncate $arg<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">if (</span><span class="default">$precision </span><span class="keyword">!== </span><span class="string">''</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$precision </span><span class="keyword">= </span><span class="default">intval</span><span class="keyword">(</span><span class="default">substr</span><span class="keyword">(</span><span class="default">$precision</span><span class="keyword">,</span><span class="default">1</span><span class="keyword">));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$precision </span><span class="keyword">&gt; </span><span class="default">0 </span><span class="keyword">&amp;&amp; </span><span class="default">mb_strlen</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">,</span><span class="default">$encoding</span><span class="keyword">) &gt; </span><span class="default">$precision</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg </span><span class="keyword">= </span><span class="default">mb_substr</span><span class="keyword">(</span><span class="default">$precision</span><span class="keyword">,</span><span class="default">0</span><span class="keyword">,</span><span class="default">$precision</span><span class="keyword">,</span><span class="default">$encoding</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// define padding<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">if (</span><span class="default">$size </span><span class="keyword">&gt; </span><span class="default">0</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arglen </span><span class="keyword">= </span><span class="default">mb_strlen</span><span class="keyword">(</span><span class="default">$arg</span><span class="keyword">, </span><span class="default">$encoding</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$arglen </span><span class="keyword">&lt; </span><span class="default">$size</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if(</span><span class="default">$filler</span><span class="keyword">===</span><span class="string">''</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$filler </span><span class="keyword">= </span><span class="string">' '</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if (</span><span class="default">$align </span><span class="keyword">== </span><span class="string">'-'</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$padding_post </span><span class="keyword">= </span><span class="default">str_repeat</span><span class="keyword">(</span><span class="default">$filler</span><span class="keyword">, </span><span class="default">$size </span><span class="keyword">- </span><span class="default">$arglen</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; else<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$padding_pre </span><span class="keyword">= </span><span class="default">str_repeat</span><span class="keyword">(</span><span class="default">$filler</span><span class="keyword">, </span><span class="default">$size </span><span class="keyword">- </span><span class="default">$arglen</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// escape % and pass it forward<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$newformat </span><span class="keyword">.= </span><span class="default">$padding_pre </span><span class="keyword">. </span><span class="default">str_replace</span><span class="keyword">(</span><span class="string">'%'</span><span class="keyword">, </span><span class="string">'%%'</span><span class="keyword">, </span><span class="default">$arg</span><span class="keyword">) . </span><span class="default">$padding_post</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; else {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// another type, pass forward<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$newformat </span><span class="keyword">.= </span><span class="string">"%</span><span class="default">$sign$filler$align$size$precision$type</span><span class="string">"</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$newargv</span><span class="keyword">[] = </span><span class="default">array_shift</span><span class="keyword">(</span><span class="default">$argv</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$format </span><span class="keyword">= </span><span class="default">strval</span><span class="keyword">(</span><span class="default">$post</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; </span><span class="comment">// Convert new format back from UTF-8 to the original encoding<br />&nbsp; &nbsp; &nbsp; </span><span class="default">$newformat </span><span class="keyword">= </span><span class="default">mb_convert_encoding</span><span class="keyword">(</span><span class="default">$newformat</span><span class="keyword">, </span><span class="default">$encoding</span><span class="keyword">, </span><span class="string">'UTF-8'</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; return </span><span class="default">vsprintf</span><span class="keyword">(</span><span class="default">$newformat</span><span class="keyword">, </span><span class="default">$newargv</span><span class="keyword">);<br />&nbsp; }<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="93156">  <div class="votes">
    <div id="Vu93156">
    <a href="/manual/vote-note.php?id=93156&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd93156">
    <a href="/manual/vote-note.php?id=93156&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V93156" title="63% like this...">
    15
    </div>
  </div>
  <a href="#93156" class="name">
  <strong class="user"><em>Jay Gilford</em></strong></a><a class="genanchor" href="#93156"> &para;</a><div class="date" title="2009-08-25 05:13"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom93156">
<div class="phpcode"><code><span class="html">
I created this function a while back to save on having to combine mysql_real_escape_string onto all the params passed into a sprintf. it works literally the same as the sprintf other than that it doesn't require you to escape your inputs. Hope its of some use to people<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">mressf</span><span class="keyword">()<br />{<br />&nbsp; &nbsp; </span><span class="default">$args </span><span class="keyword">= </span><span class="default">func_get_args</span><span class="keyword">();<br />&nbsp; &nbsp; if (</span><span class="default">count</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">) &lt; </span><span class="default">2</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">false</span><span class="keyword">;<br />&nbsp; &nbsp; </span><span class="default">$query </span><span class="keyword">= </span><span class="default">array_shift</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$args </span><span class="keyword">= </span><span class="default">array_map</span><span class="keyword">(</span><span class="string">'mysql_real_escape_string'</span><span class="keyword">, </span><span class="default">$args</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">array_unshift</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">, </span><span class="default">$query</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$query </span><span class="keyword">= </span><span class="default">call_user_func_array</span><span class="keyword">(</span><span class="string">'sprintf'</span><span class="keyword">, </span><span class="default">$args</span><span class="keyword">);<br />&nbsp; &nbsp; return </span><span class="default">$query</span><span class="keyword">;<br />}<br /></span><span class="default">?&gt;<br /></span><br />Regards<br />Jay<br />Jaygilford.com</span>
</code></div>
  </div>
 </div>
  <div class="note" id="53923">  <div class="votes">
    <div id="Vu53923">
    <a href="/manual/vote-note.php?id=53923&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd53923">
    <a href="/manual/vote-note.php?id=53923&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V53923" title="71% like this...">
    6
    </div>
  </div>
  <a href="#53923" class="name">
  <strong class="user"><em>david at rayninfo dot co dot uk</em></strong></a><a class="genanchor" href="#53923"> &para;</a><div class="date" title="2005-06-16 11:33"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom53923">
<div class="phpcode"><code><span class="html">
Using sprintf to force leading leading zeros<br /><br />foreach (range(1, 10) as $v) {echo "&lt;br&gt;tag_".sprintf("%02d",$v);}<br /><br />displays<br />tag_01<br />tag_02<br />tag_03<br />.. etc</span>
</code></div>
  </div>
 </div>
  <div class="note" id="52451">  <div class="votes">
    <div id="Vu52451">
    <a href="/manual/vote-note.php?id=52451&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd52451">
    <a href="/manual/vote-note.php?id=52451&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V52451" title="66% like this...">
    8
    </div>
  </div>
  <a href="#52451" class="name">
  <strong class="user"><em>Pacogliss</em></strong></a><a class="genanchor" href="#52451"> &para;</a><div class="date" title="2005-05-02 12:08"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom52451">
<div class="phpcode"><code><span class="html">
Just a reminder for beginners : example 6 'printf("[%10s]\n",&nbsp; &nbsp; $s);' only works (that is, shows out the spaces) if you put the html '&lt;pre&gt;&lt;/pre&gt;' tags ( head-scraping time saver ;-).</span>
</code></div>
  </div>
 </div>
  <div class="note" id="99732">  <div class="votes">
    <div id="Vu99732">
    <a href="/manual/vote-note.php?id=99732&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd99732">
    <a href="/manual/vote-note.php?id=99732&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V99732" title="66% like this...">
    6
    </div>
  </div>
  <a href="#99732" class="name">
  <strong class="user"><em>dwieeb at gmail dot com</em></strong></a><a class="genanchor" href="#99732"> &para;</a><div class="date" title="2010-09-01 11:54"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom99732">
<div class="phpcode"><code><span class="html">
If you use the default padding specifier (a space) and then print it to HTML, you will notice that HTML does not display the multiple spaces correctly. This is because any sequence of white-space is treated as a single space.<br /><br />To overcome this, I wrote a simple function that replaces all the spaces in the string returned by sprintf() with the character entity reference "&amp;nbsp;" to achieve non-breaking space in strings returned by sprintf()<br /><br /><span class="default">&lt;?php<br /></span><span class="comment">//Here is the function:<br /></span><span class="keyword">function </span><span class="default">sprintf_nbsp</span><span class="keyword">() {<br />&nbsp;&nbsp; </span><span class="default">$args </span><span class="keyword">= </span><span class="default">func_get_args</span><span class="keyword">();<br />&nbsp;&nbsp; return </span><span class="default">str_replace</span><span class="keyword">(</span><span class="string">' '</span><span class="keyword">, </span><span class="string">'&amp;nbsp;'</span><span class="keyword">, </span><span class="default">vsprintf</span><span class="keyword">(</span><span class="default">array_shift</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">), </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">)));<br />}<br /><br /></span><span class="comment">//Usage (exactly like sprintf):<br /></span><span class="default">$format </span><span class="keyword">= </span><span class="string">'The %d monkeys are attacking the [%10s]!'</span><span class="keyword">;<br /></span><span class="default">$str </span><span class="keyword">= </span><span class="default">sprintf_nbsp</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">15</span><span class="keyword">, </span><span class="string">'zoo'</span><span class="keyword">);<br />echo </span><span class="default">$str</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span><br />The above example will output:<br />The 15 monkeys are attacking the [&nbsp; &nbsp; &nbsp;&nbsp; zoo]!<br /><br /><span class="default">&lt;?php<br /></span><span class="comment">//The variation that prints the string instead of returning it:<br /></span><span class="keyword">function </span><span class="default">printf_nbsp</span><span class="keyword">() {<br />&nbsp;&nbsp; </span><span class="default">$args </span><span class="keyword">= </span><span class="default">func_get_args</span><span class="keyword">();<br />&nbsp;&nbsp; echo </span><span class="default">str_replace</span><span class="keyword">(</span><span class="string">' '</span><span class="keyword">, </span><span class="string">'&amp;nbsp;'</span><span class="keyword">, </span><span class="default">vsprintf</span><span class="keyword">(</span><span class="default">array_shift</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">), </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">)));<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="105468">  <div class="votes">
    <div id="Vu105468">
    <a href="/manual/vote-note.php?id=105468&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd105468">
    <a href="/manual/vote-note.php?id=105468&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V105468" title="66% like this...">
    4
    </div>
  </div>
  <a href="#105468" class="name">
  <strong class="user"><em>krzysiek dot 333 at gmail dot com - zryty dot hekko dot pl</em></strong></a><a class="genanchor" href="#105468"> &para;</a><div class="date" title="2011-08-20 12:48"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom105468">
<div class="phpcode"><code><span class="html">
Encoding and decoding IP adress to format: 1A2B3C4D (mysql column: char(8) )<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">encode_ip</span><span class="keyword">(</span><span class="default">$dotquad_ip</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="default">$ip_sep </span><span class="keyword">= </span><span class="default">explode</span><span class="keyword">(</span><span class="string">'.'</span><span class="keyword">, </span><span class="default">$dotquad_ip</span><span class="keyword">);<br />&nbsp; &nbsp; return </span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">'%02x%02x%02x%02x'</span><span class="keyword">, </span><span class="default">$ip_sep</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">], </span><span class="default">$ip_sep</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">], </span><span class="default">$ip_sep</span><span class="keyword">[</span><span class="default">2</span><span class="keyword">], </span><span class="default">$ip_sep</span><span class="keyword">[</span><span class="default">3</span><span class="keyword">]);<br />}<br /><br />function </span><span class="default">decode_ip</span><span class="keyword">(</span><span class="default">$int_ip</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="default">$hexipbang </span><span class="keyword">= </span><span class="default">explode</span><span class="keyword">(</span><span class="string">'.'</span><span class="keyword">, </span><span class="default">chunk_split</span><span class="keyword">(</span><span class="default">$int_ip</span><span class="keyword">, </span><span class="default">2</span><span class="keyword">, </span><span class="string">'.'</span><span class="keyword">));<br />&nbsp; &nbsp; return </span><span class="default">hexdec</span><span class="keyword">(</span><span class="default">$hexipbang</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">]). </span><span class="string">'.' </span><span class="keyword">. </span><span class="default">hexdec</span><span class="keyword">(</span><span class="default">$hexipbang</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">]) . </span><span class="string">'.' </span><span class="keyword">. </span><span class="default">hexdec</span><span class="keyword">(</span><span class="default">$hexipbang</span><span class="keyword">[</span><span class="default">2</span><span class="keyword">]) . </span><span class="string">'.' </span><span class="keyword">. </span><span class="default">hexdec</span><span class="keyword">(</span><span class="default">$hexipbang</span><span class="keyword">[</span><span class="default">3</span><span class="keyword">]);<br />}<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="102205">  <div class="votes">
    <div id="Vu102205">
    <a href="/manual/vote-note.php?id=102205&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd102205">
    <a href="/manual/vote-note.php?id=102205&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V102205" title="66% like this...">
    4
    </div>
  </div>
  <a href="#102205" class="name">
  <strong class="user"><em>carmageddon at gmail dot com</em></strong></a><a class="genanchor" href="#102205"> &para;</a><div class="date" title="2011-02-02 06:38"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom102205">
<div class="phpcode"><code><span class="html">
If you want to convert a decimal (integer) number into constant length binary number in lets say 9 bits, use this:<br /><br />$binary = sprintf('%08b', $number );<br /><br />for example: <br /><span class="default">&lt;?php<br />$bin </span><span class="keyword">= </span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">'%08b'</span><span class="keyword">,</span><span class="default">511 </span><span class="keyword">);<br />echo </span><span class="default">$bin</span><span class="keyword">.</span><span class="string">"\n"</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span><br />would output 111111111<br />And 2 would output 00000010<br /><br />I know the leading zeros are useful to me, perhaps they are to someone else too.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="51990">  <div class="votes">
    <div id="Vu51990">
    <a href="/manual/vote-note.php?id=51990&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd51990">
    <a href="/manual/vote-note.php?id=51990&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V51990" title="65% like this...">
    7
    </div>
  </div>
  <a href="#51990" class="name">
  <strong class="user"><em>christian at wenz dot org</em></strong></a><a class="genanchor" href="#51990"> &para;</a><div class="date" title="2005-04-18 12:20"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom51990">
<div class="phpcode"><code><span class="html">
@ henke dot andersson at comhem dot se: Use vprintf()/vsprintf() for that.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="114849">  <div class="votes">
    <div id="Vu114849">
    <a href="/manual/vote-note.php?id=114849&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd114849">
    <a href="/manual/vote-note.php?id=114849&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V114849" title="66% like this...">
    3
    </div>
  </div>
  <a href="#114849" class="name">
  <strong class="user"><em>hdimac at gmail dot com</em></strong></a><a class="genanchor" href="#114849"> &para;</a><div class="date" title="2014-04-14 04:00"><strong>5 years ago</strong></div>
  <div class="text" id="Hcom114849">
<div class="phpcode"><code><span class="html">
In the examples, is being shown printf, but it should say sprintf, which is the function being explained... just a simple edition mistake.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="88761">  <div class="votes">
    <div id="Vu88761">
    <a href="/manual/vote-note.php?id=88761&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd88761">
    <a href="/manual/vote-note.php?id=88761&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V88761" title="66% like this...">
    4
    </div>
  </div>
  <a href="#88761" class="name">
  <strong class="user"><em>splogamurugan at gmail dot com</em></strong></a><a class="genanchor" href="#88761"> &para;</a><div class="date" title="2009-02-06 05:59"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom88761">
<div class="phpcode"><code><span class="html">
$format = 'There are %1$d monkeys in the %s and %s ';<br />printf($format, 100, 'Chennai', 'Bangalore'); <br /><br />Expecting to output<br />"There are 100 monkeys in the Chennai and bangalore"<br /><br />But, this will output <br />"There are 100 monkeys in the 100 and Chennai"<br /><br />Because, the second and Third specifiers takes 1rst and 2nd arguments. Because it is not assigned with any arguments.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="108947">  <div class="votes">
    <div id="Vu108947">
    <a href="/manual/vote-note.php?id=108947&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd108947">
    <a href="/manual/vote-note.php?id=108947&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V108947" title="63% like this...">
    5
    </div>
  </div>
  <a href="#108947" class="name">
  <strong class="user"><em>Hayley Watson</em></strong></a><a class="genanchor" href="#108947"> &para;</a><div class="date" title="2012-06-07 11:21"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom108947">
<div class="phpcode"><code><span class="html">
If you use argument numbering, then format specifications with the same number get the same argument; this can save repeating the argument in the function call.<br /><br /><span class="default">&lt;?php<br /><br />$pattern </span><span class="keyword">= </span><span class="string">'%1$s %1$\'#10s %1$s!'</span><span class="keyword">;<br /><br /></span><span class="default">printf</span><span class="keyword">(</span><span class="default">$pattern</span><span class="keyword">, </span><span class="string">"badgers"</span><span class="keyword">);<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="25094">  <div class="votes">
    <div id="Vu25094">
    <a href="/manual/vote-note.php?id=25094&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd25094">
    <a href="/manual/vote-note.php?id=25094&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V25094" title="66% like this...">
    3
    </div>
  </div>
  <a href="#25094" class="name">
  <strong class="user"><em>abiltcliffe at bigfoot.com</em></strong></a><a class="genanchor" href="#25094"> &para;</a><div class="date" title="2002-09-10 11:01"><strong>17 years ago</strong></div>
  <div class="text" id="Hcom25094">
<div class="phpcode"><code><span class="html">
To jrust at rustyparts.com, note that if you're using a double-quoted string and *don't* escape the dollar sign with a backslash, $s and $d will be interpreted as variable references. The backslash isn't part of the format specifier itself but you do need to include it when you write the format string (unless you use single quotes).</span>
</code></div>
  </div>
 </div>
  <div class="note" id="86068">  <div class="votes">
    <div id="Vu86068">
    <a href="/manual/vote-note.php?id=86068&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd86068">
    <a href="/manual/vote-note.php?id=86068&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V86068" title="66% like this...">
    1
    </div>
  </div>
  <a href="#86068" class="name">
  <strong class="user"><em>php at mikeboers dot com</em></strong></a><a class="genanchor" href="#86068"> &para;</a><div class="date" title="2008-10-01 01:42"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom86068">
<div class="phpcode"><code><span class="html">
And continuing on the same theme of a key-based sprintf...<br /><br />I'm roughly (I can see a couple cases where it comes out wierd) copying the syntax of Python's string formatting with a dictionary. The improvement over the several past attempts is that this one still respects all of the formating options, as you can see in my example.<br /><br />And the error handling is really crappy (just an echo). I just threw this together so do with it what you will. =]<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">sprintf_array</span><span class="keyword">(</span><span class="default">$string</span><span class="keyword">, </span><span class="default">$array</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="default">$keys&nbsp; &nbsp; </span><span class="keyword">= </span><span class="default">array_keys</span><span class="keyword">(</span><span class="default">$array</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$keysmap </span><span class="keyword">= </span><span class="default">array_flip</span><span class="keyword">(</span><span class="default">$keys</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">$values&nbsp; </span><span class="keyword">= </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$array</span><span class="keyword">);<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; while (</span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">'/%\(([a-zA-Z0-9_ -]+)\)/'</span><span class="keyword">, </span><span class="default">$string</span><span class="keyword">, </span><span class="default">$m</span><span class="keyword">))<br />&nbsp; &nbsp; {&nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; if (!isset(</span><span class="default">$keysmap</span><span class="keyword">[</span><span class="default">$m</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">]]))<br />&nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo </span><span class="string">"No key </span><span class="default">$m</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">]</span><span class="string">\n"</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">false</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$string </span><span class="keyword">= </span><span class="default">str_replace</span><span class="keyword">(</span><span class="default">$m</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">], </span><span class="string">'%' </span><span class="keyword">. (</span><span class="default">$keysmap</span><span class="keyword">[</span><span class="default">$m</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">]] + </span><span class="default">1</span><span class="keyword">) . </span><span class="string">'$'</span><span class="keyword">, </span><span class="default">$string</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="default">array_unshift</span><span class="keyword">(</span><span class="default">$values</span><span class="keyword">, </span><span class="default">$string</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">var_dump</span><span class="keyword">(</span><span class="default">$values</span><span class="keyword">);<br />&nbsp; &nbsp; return </span><span class="default">call_user_func_array</span><span class="keyword">(</span><span class="string">'sprintf'</span><span class="keyword">, </span><span class="default">$values</span><span class="keyword">);<br />}<br /><br />echo </span><span class="default">sprintf_array</span><span class="keyword">(</span><span class="string">'4 digit padded number: %(num)04d '</span><span class="keyword">, array(</span><span class="string">'num' </span><span class="keyword">=&gt; </span><span class="default">42</span><span class="keyword">));<br /><br /></span><span class="default">?&gt;<br /></span><br />Cheers!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="94608">  <div class="votes">
    <div id="Vu94608">
    <a href="/manual/vote-note.php?id=94608&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd94608">
    <a href="/manual/vote-note.php?id=94608&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V94608" title="62% like this...">
    4
    </div>
  </div>
  <a href="#94608" class="name">
  <strong class="user"><em>nate at frickenate dot com</em></strong></a><a class="genanchor" href="#94608"> &para;</a><div class="date" title="2009-11-13 11:45"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom94608">
<div class="phpcode"><code><span class="html">
Here's a clean, working version of functions to allow using named arguments instead of numeric ones. ex: instead of sprintf('%1$s', 'Joe');, we can use sprintf('%name$s', array('name' =&gt; 'Joe'));. I've provided 2 different versions: the first uses the php-like syntax (ex: %name$s), while the second uses the python syntax (ex: %(name)s).<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="comment">/**<br /> * version of sprintf for cases where named arguments are desired (php syntax)<br /> *<br /> * with sprintf: sprintf('second: %2$s ; first: %1$s', '1st', '2nd');<br /> *<br /> * with sprintfn: sprintfn('second: %second$s ; first: %first$s', array(<br /> *&nbsp; 'first' =&gt; '1st',<br /> *&nbsp; 'second'=&gt; '2nd'<br /> * ));<br /> *<br /> * @param string $format sprintf format string, with any number of named arguments<br /> * @param array $args array of [ 'arg_name' =&gt; 'arg value', ... ] replacements to be made<br /> * @return string|false result of sprintf call, or bool false on error<br /> */<br /></span><span class="keyword">function </span><span class="default">sprintfn </span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, array </span><span class="default">$args </span><span class="keyword">= array()) {<br />&nbsp; &nbsp; </span><span class="comment">// map of argument names to their corresponding sprintf numeric argument value<br />&nbsp; &nbsp; </span><span class="default">$arg_nums </span><span class="keyword">= </span><span class="default">array_slice</span><span class="keyword">(</span><span class="default">array_flip</span><span class="keyword">(</span><span class="default">array_keys</span><span class="keyword">(array(</span><span class="default">0 </span><span class="keyword">=&gt; </span><span class="default">0</span><span class="keyword">) + </span><span class="default">$args</span><span class="keyword">)), </span><span class="default">1</span><span class="keyword">);<br /><br />&nbsp; &nbsp; </span><span class="comment">// find the next named argument. each search starts at the end of the previous replacement.<br />&nbsp; &nbsp; </span><span class="keyword">for (</span><span class="default">$pos </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">'/(?&lt;=%)([a-zA-Z_]\w*)(?=\$)/'</span><span class="keyword">, </span><span class="default">$format</span><span class="keyword">, </span><span class="default">$match</span><span class="keyword">, </span><span class="default">PREG_OFFSET_CAPTURE</span><span class="keyword">, </span><span class="default">$pos</span><span class="keyword">);) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg_pos </span><span class="keyword">= </span><span class="default">$match</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">][</span><span class="default">1</span><span class="keyword">];<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg_len </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$match</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">]);<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg_key </span><span class="keyword">= </span><span class="default">$match</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">];<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// programmer did not supply a value for the named argument found in the format string<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">if (! </span><span class="default">array_key_exists</span><span class="keyword">(</span><span class="default">$arg_key</span><span class="keyword">, </span><span class="default">$arg_nums</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">user_error</span><span class="keyword">(</span><span class="string">"sprintfn(): Missing argument '</span><span class="keyword">${</span><span class="default">arg_key</span><span class="keyword">}</span><span class="string">'"</span><span class="keyword">, </span><span class="default">E_USER_WARNING</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">false</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// replace the named argument with the corresponding numeric one<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$format </span><span class="keyword">= </span><span class="default">substr_replace</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">$replace </span><span class="keyword">= </span><span class="default">$arg_nums</span><span class="keyword">[</span><span class="default">$arg_key</span><span class="keyword">], </span><span class="default">$arg_pos</span><span class="keyword">, </span><span class="default">$arg_len</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$pos </span><span class="keyword">= </span><span class="default">$arg_pos </span><span class="keyword">+ </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$replace</span><span class="keyword">); </span><span class="comment">// skip to end of replacement for next iteration<br />&nbsp; &nbsp; </span><span class="keyword">}<br /><br />&nbsp; &nbsp; return </span><span class="default">vsprintf</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">));<br />}<br /><br /></span><span class="comment">/**<br /> * version of sprintf for cases where named arguments are desired (python syntax)<br /> *<br /> * with sprintf: sprintf('second: %2$s ; first: %1$s', '1st', '2nd');<br /> *<br /> * with sprintfn: sprintfn('second: %(second)s ; first: %(first)s', array(<br /> *&nbsp; 'first' =&gt; '1st',<br /> *&nbsp; 'second'=&gt; '2nd'<br /> * ));<br /> *<br /> * @param string $format sprintf format string, with any number of named arguments<br /> * @param array $args array of [ 'arg_name' =&gt; 'arg value', ... ] replacements to be made<br /> * @return string|false result of sprintf call, or bool false on error<br /> */<br /></span><span class="keyword">function </span><span class="default">sprintfn </span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, array </span><span class="default">$args </span><span class="keyword">= array()) {<br />&nbsp; &nbsp; </span><span class="comment">// map of argument names to their corresponding sprintf numeric argument value<br />&nbsp; &nbsp; </span><span class="default">$arg_nums </span><span class="keyword">= </span><span class="default">array_slice</span><span class="keyword">(</span><span class="default">array_flip</span><span class="keyword">(</span><span class="default">array_keys</span><span class="keyword">(array(</span><span class="default">0 </span><span class="keyword">=&gt; </span><span class="default">0</span><span class="keyword">) + </span><span class="default">$args</span><span class="keyword">)), </span><span class="default">1</span><span class="keyword">);<br /><br />&nbsp; &nbsp; </span><span class="comment">// find the next named argument. each search starts at the end of the previous replacement.<br />&nbsp; &nbsp; </span><span class="keyword">for (</span><span class="default">$pos </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">'/(?&lt;=%)\(([a-zA-Z_]\w*)\)/'</span><span class="keyword">, </span><span class="default">$format</span><span class="keyword">, </span><span class="default">$match</span><span class="keyword">, </span><span class="default">PREG_OFFSET_CAPTURE</span><span class="keyword">, </span><span class="default">$pos</span><span class="keyword">);) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg_pos </span><span class="keyword">= </span><span class="default">$match</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">][</span><span class="default">1</span><span class="keyword">];<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg_len </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$match</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">]);<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$arg_key </span><span class="keyword">= </span><span class="default">$match</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">];<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// programmer did not supply a value for the named argument found in the format string<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">if (! </span><span class="default">array_key_exists</span><span class="keyword">(</span><span class="default">$arg_key</span><span class="keyword">, </span><span class="default">$arg_nums</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">user_error</span><span class="keyword">(</span><span class="string">"sprintfn(): Missing argument '</span><span class="keyword">${</span><span class="default">arg_key</span><span class="keyword">}</span><span class="string">'"</span><span class="keyword">, </span><span class="default">E_USER_WARNING</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">false</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// replace the named argument with the corresponding numeric one<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$format </span><span class="keyword">= </span><span class="default">substr_replace</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">$replace </span><span class="keyword">= </span><span class="default">$arg_nums</span><span class="keyword">[</span><span class="default">$arg_key</span><span class="keyword">] . </span><span class="string">'$'</span><span class="keyword">, </span><span class="default">$arg_pos</span><span class="keyword">, </span><span class="default">$arg_len</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$pos </span><span class="keyword">= </span><span class="default">$arg_pos </span><span class="keyword">+ </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$replace</span><span class="keyword">); </span><span class="comment">// skip to end of replacement for next iteration<br />&nbsp; &nbsp; </span><span class="keyword">}<br /><br />&nbsp; &nbsp; return </span><span class="default">vsprintf</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$args</span><span class="keyword">));<br />}<br /><br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="53372">  <div class="votes">
    <div id="Vu53372">
    <a href="/manual/vote-note.php?id=53372&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd53372">
    <a href="/manual/vote-note.php?id=53372&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V53372" title="63% like this...">
    3
    </div>
  </div>
  <a href="#53372" class="name">
  <strong class="user"><em>ian dot w dot davis at gmail dot com</em></strong></a><a class="genanchor" href="#53372"> &para;</a><div class="date" title="2005-05-30 07:03"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom53372">
<div class="phpcode"><code><span class="html">
Just to elaborate on downright's point about different meanings for %f, it appears the behavior changed significantly as of 4.3.7, rather than just being different on different platforms. Previously, the width specifier gave the number of characters allowed BEFORE the decimal. Now, the width specifier gives the TOTAL number of characters. (This is in line with the semantics of printf() in other languages.) See bugs #28633 and #29286 for more details.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="81706">  <div class="votes">
    <div id="Vu81706">
    <a href="/manual/vote-note.php?id=81706&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd81706">
    <a href="/manual/vote-note.php?id=81706&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V81706" title="58% like this...">
    6
    </div>
  </div>
  <a href="#81706" class="name">
  <strong class="user"><em>matt</em></strong></a><a class="genanchor" href="#81706"> &para;</a><div class="date" title="2008-03-10 09:13"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom81706">
<div class="phpcode"><code><span class="html">
Was looking for a assoc way of using sprintf but couldnt find one, probably wasnt looking hard enough so came up with this. Very very simple indeed...<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">sprintf2</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">=</span><span class="string">''</span><span class="keyword">, </span><span class="default">$vars</span><span class="keyword">=array(), </span><span class="default">$char</span><span class="keyword">=</span><span class="string">'%'</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; if (!</span><span class="default">$str</span><span class="keyword">) return </span><span class="string">''</span><span class="keyword">;<br />&nbsp; &nbsp; if (</span><span class="default">count</span><span class="keyword">(</span><span class="default">$vars</span><span class="keyword">) &gt; </span><span class="default">0</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; foreach (</span><span class="default">$vars </span><span class="keyword">as </span><span class="default">$k </span><span class="keyword">=&gt; </span><span class="default">$v</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$str </span><span class="keyword">= </span><span class="default">str_replace</span><span class="keyword">(</span><span class="default">$char </span><span class="keyword">. </span><span class="default">$k</span><span class="keyword">, </span><span class="default">$v</span><span class="keyword">, </span><span class="default">$str</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; return </span><span class="default">$str</span><span class="keyword">;<br />}<br /><br />echo </span><span class="default">sprintf2</span><span class="keyword">(</span><span class="string">'Hello %your_name my name is %my_name! I am %my_age, how old are you? I like %object!'</span><span class="keyword">, array(<br />&nbsp; &nbsp; </span><span class="string">'your_name' </span><span class="keyword">=&gt; </span><span class="string">'Ben'</span><span class="keyword">,<br />&nbsp; &nbsp; </span><span class="string">'my_name' </span><span class="keyword">=&gt; </span><span class="string">'Matt'</span><span class="keyword">,<br />&nbsp; &nbsp; </span><span class="string">'my_age' </span><span class="keyword">=&gt; </span><span class="string">'21'</span><span class="keyword">,<br />&nbsp; &nbsp; </span><span class="string">'object' </span><span class="keyword">=&gt; </span><span class="string">'food'<br /></span><span class="keyword">));<br /><br /></span><span class="comment">// Hello Ben my name is Matt! I am 21, how old are you? I like food!<br /><br /></span><span class="default">?&gt;<br /></span><br />Looks nice anyway :)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="22881">  <div class="votes">
    <div id="Vu22881">
    <a href="/manual/vote-note.php?id=22881&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd22881">
    <a href="/manual/vote-note.php?id=22881&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V22881" title="62% like this...">
    2
    </div>
  </div>
  <a href="#22881" class="name">
  <strong class="user"><em>Andrew dot Wright at spamsux dot atnf dot csiro dot au</em></strong></a><a class="genanchor" href="#22881"> &para;</a><div class="date" title="2002-07-03 02:22"><strong>17 years ago</strong></div>
  <div class="text" id="Hcom22881">
<div class="phpcode"><code><span class="html">
An error in my last example:<br />$b = sprintf("%30.s", $a);<br />will only add enough spaces before $a to pad the spaces + strlen($a) to 30 places.<br /><br />My method of centering fixed text in a 72 character width space is:<br /><br />$a = "Some string here";<br />$lwidth = 36; // 72/2<br />$b = sprintf("%".($lwidth + round(strlen($a)/2)).".s", $a);</span>
</code></div>
  </div>
 </div>
  <div class="note" id="93552">  <div class="votes">
    <div id="Vu93552">
    <a href="/manual/vote-note.php?id=93552&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd93552">
    <a href="/manual/vote-note.php?id=93552&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V93552" title="60% like this...">
    2
    </div>
  </div>
  <a href="#93552" class="name">
  <strong class="user"><em>Astone</em></strong></a><a class="genanchor" href="#93552"> &para;</a><div class="date" title="2009-09-15 11:41"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom93552">
<div class="phpcode"><code><span class="html">
When you're using Google translator, you have to 'escape' the 'conversion specifications' by putting &lt;span class="notranslate"&gt;&lt;/span&gt; around them.<br /><br />Like this:<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">getGoogleTranslation</span><span class="keyword">(</span><span class="default">$sString</span><span class="keyword">, </span><span class="default">$bEscapeParams </span><span class="keyword">= </span><span class="default">true</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="comment">// "escape" sprintf paramerters<br />&nbsp; &nbsp; </span><span class="keyword">if (</span><span class="default">$bEscapeParams</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$sPatern </span><span class="keyword">= </span><span class="string">'/(?:%%|%(?:[0-9]+\$)?[+-]?(?:[ 0]|\'.)?-?[0-9]*(?:\.[0-9]+)?[bcdeufFosxX])/'</span><span class="keyword">;&nbsp; &nbsp; &nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$sEscapeString </span><span class="keyword">= </span><span class="string">'&lt;span class="notranslate"&gt;$0&lt;/span&gt;'</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$sString </span><span class="keyword">= </span><span class="default">preg_replace</span><span class="keyword">(</span><span class="default">$sPatern</span><span class="keyword">, </span><span class="default">$sEscapeString</span><span class="keyword">, </span><span class="default">$sString</span><span class="keyword">);<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; </span><span class="comment">// Compose data array (English to Dutch)<br />&nbsp; &nbsp; </span><span class="default">$aData </span><span class="keyword">= array(<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">'v'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'1.0'</span><span class="keyword">,<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">'q'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="default">$sString</span><span class="keyword">,<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="string">'langpair'&nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'en|nl'</span><span class="keyword">,<br />&nbsp; &nbsp; );<br /><br />&nbsp; &nbsp; </span><span class="comment">// Initialize connection<br />&nbsp; &nbsp; </span><span class="default">$rService </span><span class="keyword">= </span><span class="default">curl_init</span><span class="keyword">();<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="comment">// Connection settings<br />&nbsp; &nbsp; </span><span class="default">curl_setopt</span><span class="keyword">(</span><span class="default">$rService</span><span class="keyword">, </span><span class="default">CURLOPT_URL</span><span class="keyword">, </span><span class="string">'<a href="http://ajax.googleapis.com/ajax/services/language/translate" rel="nofollow" target="_blank">http://ajax.googleapis.com/ajax/services/language/translate</a>'</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">curl_setopt</span><span class="keyword">(</span><span class="default">$rService</span><span class="keyword">, </span><span class="default">CURLOPT_RETURNTRANSFER</span><span class="keyword">, </span><span class="default">true</span><span class="keyword">);<br />&nbsp; &nbsp; </span><span class="default">curl_setopt</span><span class="keyword">(</span><span class="default">$rService</span><span class="keyword">, </span><span class="default">CURLOPT_POSTFIELDS</span><span class="keyword">, </span><span class="default">$aData</span><span class="keyword">);<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="comment">// Execute request<br />&nbsp; &nbsp; </span><span class="default">$sResponse </span><span class="keyword">= </span><span class="default">curl_exec</span><span class="keyword">(</span><span class="default">$rService</span><span class="keyword">);<br /><br />&nbsp; &nbsp; </span><span class="comment">// Close connection<br />&nbsp; &nbsp; </span><span class="default">curl_close</span><span class="keyword">(</span><span class="default">$rService</span><span class="keyword">);<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="comment">// Extract text from JSON response<br />&nbsp; &nbsp; </span><span class="default">$oResponse </span><span class="keyword">= </span><span class="default">json_decode</span><span class="keyword">(</span><span class="default">$sResponse</span><span class="keyword">);<br />&nbsp; &nbsp; if (isset(</span><span class="default">$oResponse</span><span class="keyword">-&gt;</span><span class="default">responseData</span><span class="keyword">-&gt;</span><span class="default">translatedText</span><span class="keyword">))<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$sTranslation </span><span class="keyword">= </span><span class="default">$oResponse</span><span class="keyword">-&gt;</span><span class="default">responseData</span><span class="keyword">-&gt;</span><span class="default">translatedText</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; else<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="comment">// If some error occured, use the original string<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$sTranslation </span><span class="keyword">= </span><span class="default">$sString</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="comment">// Replace "notranslate" tags<br />&nbsp; &nbsp; </span><span class="keyword">if (</span><span class="default">$bEscapeParams</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$sEscapePatern </span><span class="keyword">= </span><span class="string">'/&lt;span class="notranslate"&gt;([^&lt;]*)&lt;\/span&gt;/'</span><span class="keyword">;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$sTranslation </span><span class="keyword">= </span><span class="default">preg_replace</span><span class="keyword">(</span><span class="default">$sEscapePatern</span><span class="keyword">, </span><span class="string">'$1'</span><span class="keyword">, </span><span class="default">$sTranslation</span><span class="keyword">);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; </span><span class="comment">// Return result<br />&nbsp; &nbsp; </span><span class="keyword">return </span><span class="default">$sTranslation</span><span class="keyword">;<br />}<br /><br /></span><span class="default">?&gt;<br /></span><br />Thanks to MelTraX for defining the RegExp!</span>
</code></div>
  </div>
 </div>
  <div class="note" id="83779">  <div class="votes">
    <div id="Vu83779">
    <a href="/manual/vote-note.php?id=83779&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd83779">
    <a href="/manual/vote-note.php?id=83779&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V83779" title="57% like this...">
    3
    </div>
  </div>
  <a href="#83779" class="name">
  <strong class="user"><em>jaimthorn at yahoo dot com</em></strong></a><a class="genanchor" href="#83779"> &para;</a><div class="date" title="2008-06-11 07:01"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom83779">
<div class="phpcode"><code><span class="html">
I needed a piece of code similar to the one Matt posted below, on the 10th of March, 2008.&nbsp; However, I wasn't completely satisfied with Matt's code (sorry, Matt!&nbsp; No offense intended!), because<br /><br />1) I don't like to initialize variables when it's not really needed, and<br />2) it contains two bugs.<br /><br />What are the bugs?<br /><br />First, Matt's code tests for count($vars) &gt; 0, but if $var == "Hello world!", then count($var) == 1, but the foreach() will crash because $var has to be an array.&nbsp; So instead, my code tests for is_array($var).<br /><br />Second, if a key in $vars is a prefix of any of the later keys in the array (like 'object' is the beginning of 'objective') then the str_replace messes things up.&nbsp; This is no big deal if your keys are hard-coded and you can make sure the keys don't interfere, but in my code the keys are variable.&nbsp; So I decided to first sort the array on a decreasing length of the key.<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">cmp</span><span class="keyword">(</span><span class="default">$a</span><span class="keyword">, </span><span class="default">$b</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; return </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$b</span><span class="keyword">) - </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$a</span><span class="keyword">);<br />}<br /><br />function </span><span class="default">sprintf2</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">, </span><span class="default">$vars</span><span class="keyword">, </span><span class="default">$char </span><span class="keyword">= </span><span class="string">'%'</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; if(</span><span class="default">is_array</span><span class="keyword">(</span><span class="default">$vars</span><span class="keyword">))<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">uksort</span><span class="keyword">(</span><span class="default">$vars</span><span class="keyword">, </span><span class="string">"cmp"</span><span class="keyword">);<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; foreach(</span><span class="default">$vars </span><span class="keyword">as </span><span class="default">$k </span><span class="keyword">=&gt; </span><span class="default">$v</span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$str </span><span class="keyword">= </span><span class="default">str_replace</span><span class="keyword">(</span><span class="default">$char </span><span class="keyword">. </span><span class="default">$k</span><span class="keyword">, </span><span class="default">$v</span><span class="keyword">, </span><span class="default">$str</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br /><br />&nbsp; &nbsp; return </span><span class="default">$str</span><span class="keyword">;<br />}<br /><br />echo </span><span class="default">sprintf2</span><span class="keyword">( </span><span class="string">'Hello %your_name, my name is %my_name! I am %my_age, how old are you? I like %object and I want to %objective_in_life!'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">, array( </span><span class="string">'your_name'&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">=&gt; </span><span class="string">'Matt'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'my_name'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">=&gt; </span><span class="string">'Jim'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'my_age'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'old'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'object'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'women'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'objective_in_life' </span><span class="keyword">=&gt; </span><span class="string">'write code'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; );<br /><br /></span><span class="default">?&gt;<br /></span><br />If possible, and if you're willing, you can also embed the key fields in the text between percent-signs, rather than prefixing the keys with one.&nbsp; Sorting is no longer necessary, and the execution time is less than half of the code above:<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">sprintf3</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">, </span><span class="default">$vars</span><span class="keyword">, </span><span class="default">$char </span><span class="keyword">= </span><span class="string">'%'</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; </span><span class="default">$tmp </span><span class="keyword">= array();<br />&nbsp; &nbsp; foreach(</span><span class="default">$vars </span><span class="keyword">as </span><span class="default">$k </span><span class="keyword">=&gt; </span><span class="default">$v</span><span class="keyword">)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$tmp</span><span class="keyword">[</span><span class="default">$char </span><span class="keyword">. </span><span class="default">$k </span><span class="keyword">. </span><span class="default">$char</span><span class="keyword">] = </span><span class="default">$v</span><span class="keyword">;<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; return </span><span class="default">str_replace</span><span class="keyword">(</span><span class="default">array_keys</span><span class="keyword">(</span><span class="default">$tmp</span><span class="keyword">), </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$tmp</span><span class="keyword">), </span><span class="default">$str</span><span class="keyword">);<br />}<br /><br />echo </span><span class="default">sprintf3</span><span class="keyword">( </span><span class="string">'Hello %your_name%, my name is %my_name%! I am %my_age%, how old are you? I like %object% and I want to %objective_in_life%!'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">, array( </span><span class="string">'your_name'&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">=&gt; </span><span class="string">'Matt'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'my_name'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">=&gt; </span><span class="string">'Jim'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'my_age'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'old'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'object'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'women'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'objective_in_life' </span><span class="keyword">=&gt; </span><span class="string">'write code'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; );<br /></span><span class="default">?&gt;<br /></span><br />If you're willing to embed the keys in the text, you may also be willing to embed the keys themselves in percent signs, thus shaving off another 30% of the execution time:<br /><br /><span class="default">&lt;?php<br /><br /></span><span class="keyword">function </span><span class="default">sprintf4</span><span class="keyword">(</span><span class="default">$str</span><span class="keyword">, </span><span class="default">$vars</span><span class="keyword">)<br />{<br />&nbsp; &nbsp; return </span><span class="default">str_replace</span><span class="keyword">(</span><span class="default">array_keys</span><span class="keyword">(</span><span class="default">$vars</span><span class="keyword">), </span><span class="default">array_values</span><span class="keyword">(</span><span class="default">$vars</span><span class="keyword">), </span><span class="default">$str</span><span class="keyword">);<br />}<br /><br />echo </span><span class="default">sprintf4</span><span class="keyword">( </span><span class="string">'Hello %your_name%, my name is %my_name%! I am %my_age%, how old are you? I like %object% and I want to %objective_in_life%!'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">, array( </span><span class="string">'%your_name%'&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">=&gt; </span><span class="string">'Matt'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'%my_name%'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; </span><span class="keyword">=&gt; </span><span class="string">'Jim'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'%my_age%'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'old'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'%object%'&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">=&gt; </span><span class="string">'women'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">, </span><span class="string">'%objective_in_life%' </span><span class="keyword">=&gt; </span><span class="string">'write code'<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="keyword">)<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; );<br /></span><span class="default">?&gt;<br /></span><br />Of course, by now the sprintf function is no longer something you'd want to write to mum and dad about...</span>
</code></div>
  </div>
 </div>
  <div class="note" id="99714">  <div class="votes">
    <div id="Vu99714">
    <a href="/manual/vote-note.php?id=99714&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd99714">
    <a href="/manual/vote-note.php?id=99714&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V99714" title="55% like this...">
    1
    </div>
  </div>
  <a href="#99714" class="name">
  <strong class="user"><em>geertdd at gmail dot com</em></strong></a><a class="genanchor" href="#99714"> &para;</a><div class="date" title="2010-09-01 12:53"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom99714">
<div class="phpcode"><code><span class="html">
Note that when using a sign specifier, the number zero is considered positive and a "+" sign will be prepended to it.<br /><br /><span class="default">&lt;?php<br />printf</span><span class="keyword">(</span><span class="string">'%+d'</span><span class="keyword">, </span><span class="default">0</span><span class="keyword">); </span><span class="comment">// +0<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="92124">  <div class="votes">
    <div id="Vu92124">
    <a href="/manual/vote-note.php?id=92124&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd92124">
    <a href="/manual/vote-note.php?id=92124&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V92124" title="54% like this...">
    2
    </div>
  </div>
  <a href="#92124" class="name">
  <strong class="user"><em>John Walker</em></strong></a><a class="genanchor" href="#92124"> &para;</a><div class="date" title="2009-07-09 05:56"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom92124">
<div class="phpcode"><code><span class="html">
To add to other notes below about floating point problems, I noted that %f and %F will apparently output a maximum precision of 6 as a default so you have to specify 1.15f (eg) if you need more.<br /><br />In my case, the input (from MySQL) was a string with 15 digits of precision that was displayed with 6. Likely what happens is that the rounding occurs in the conversion to a float before it is displayed. Displaying it as 1.15f (or in my case, %s) shows the correct number.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="49254">  <div class="votes">
    <div id="Vu49254">
    <a href="/manual/vote-note.php?id=49254&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd49254">
    <a href="/manual/vote-note.php?id=49254&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V49254" title="54% like this...">
    1
    </div>
  </div>
  <a href="#49254" class="name">
  <strong class="user"><em>jrpozo at conclase dot net</em></strong></a><a class="genanchor" href="#49254"> &para;</a><div class="date" title="2005-01-21 07:13"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom49254">
<div class="phpcode"><code><span class="html">
Be careful if you use the %f modifier to round decimal numbers as it (starting from 4.3.10) will no longer produce a float number if you set certain locales, so you can't accumulate the result. For example:<br /><br />setlocale(LC_ALL, 'es_ES');<br />echo(sprintf("%.2f", 13.332) + sprintf("%.2f", 14.446))<br /><br />gives 27 instead of 27.78, so use %F instead.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="80344">  <div class="votes">
    <div id="Vu80344">
    <a href="/manual/vote-note.php?id=80344&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd80344">
    <a href="/manual/vote-note.php?id=80344&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V80344" title="53% like this...">
    1
    </div>
  </div>
  <a href="#80344" class="name">
  <strong class="user"><em>scott dot gardner at mac dot com</em></strong></a><a class="genanchor" href="#80344"> &para;</a><div class="date" title="2008-01-10 01:22"><strong>11 years ago</strong></div>
  <div class="text" id="Hcom80344">
<div class="phpcode"><code><span class="html">
In the last example of Example#6, there is an error regarding the output.<br /><br />printf("[%10.10s]\n", $t); // left-justification but with a cutoff of 10 characters<br /><br />This outputs right-justified.<br /><br />In order to output left-justified:<br /><br />printf("[%-10.10s]\n", $t);</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120407">  <div class="votes">
    <div id="Vu120407">
    <a href="/manual/vote-note.php?id=120407&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120407">
    <a href="/manual/vote-note.php?id=120407&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120407" title="100% like this...">
    1
    </div>
  </div>
  <a href="#120407" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#120407"> &para;</a><div class="date" title="2017-01-03 10:02"><strong>3 years ago</strong></div>
  <div class="text" id="Hcom120407">
<div class="phpcode"><code><span class="html">
Be cafeful while trying to refactor longer strings with repeated placeholders like <br /><br />&nbsp; &nbsp; sprintf("Hi %s. Your name is %s", $name, $name);<br /><br />to use argument numbering:<br /><br />&nbsp;&nbsp; sprintf("Hi %1$s. Your name is %1$s", $name);<br /><br />This will nuke you at **runtime**, because of `$s` thing being handled as variable. If you got no $s for substitution, notice will be thrown. <br /><br />The solution is to use single quotes to prevent variable substitution in string:<br /><br />&nbsp;&nbsp; sprintf('Hi %1$s. Your name is %1$s', $name);<br /><br />If you need variable substitution, then you'd need to split your string to keep it in single quotes:<br /><br />&nbsp;&nbsp; sprintf("Hi " . '%1$s' . ". Your {$variable} is " . '%1$s', $name);</span>
</code></div>
  </div>
 </div>
  <div class="note" id="124412">  <div class="votes">
    <div id="Vu124412">
    <a href="/manual/vote-note.php?id=124412&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd124412">
    <a href="/manual/vote-note.php?id=124412&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V124412" title="no votes...">
    0
    </div>
  </div>
  <a href="#124412" class="name">
  <strong class="user"><em>Anderson</em></strong></a><a class="genanchor" href="#124412"> &para;</a><div class="date" title="2019-11-18 09:23"><strong>1 month ago</strong></div>
  <div class="text" id="Hcom124412">
<div class="phpcode"><code><span class="html">
The old "monkey" example which helped me a lot has sadly disappeared.<br /><br />I'll Re-post it in comment as a memory.<br /><br /><span class="default">&lt;?php<br />$n </span><span class="keyword">=&nbsp; </span><span class="default">43951789</span><span class="keyword">;<br /></span><span class="default">$u </span><span class="keyword">= -</span><span class="default">43951789</span><span class="keyword">;<br /></span><span class="default">$c </span><span class="keyword">= </span><span class="default">65</span><span class="keyword">; </span><span class="comment">// ASCII 65 is 'A'<br /><br />// notice the double %%, this prints a literal '%' character<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%b = '%b'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// binary representation<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%c = '%c'\n"</span><span class="keyword">, </span><span class="default">$c</span><span class="keyword">); </span><span class="comment">// print the ascii character, same as chr() function<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%d = '%d'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// standard integer representation<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%e = '%e'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// scientific notation<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%u = '%u'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// unsigned integer representation of a positive integer<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%u = '%u'\n"</span><span class="keyword">, </span><span class="default">$u</span><span class="keyword">); </span><span class="comment">// unsigned integer representation of a negative integer<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%f = '%f'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// floating point representation<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%o = '%o'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// octal representation<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%s = '%s'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// string representation<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%x = '%x'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// hexadecimal representation (lower-case)<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%X = '%X'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// hexadecimal representation (upper-case)<br /><br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%+d = '%+d'\n"</span><span class="keyword">, </span><span class="default">$n</span><span class="keyword">); </span><span class="comment">// sign specifier on a positive integer<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"%%+d = '%+d'\n"</span><span class="keyword">, </span><span class="default">$u</span><span class="keyword">); </span><span class="comment">// sign specifier on a negative integer<br /><br />/*<br />%b = '10100111101010011010101101'<br />%c = 'A'<br />%d = '43951789'<br />%e = '4.395179e+7'<br />%u = '43951789'<br />%u = '18446744073665599827'<br />%f = '43951789.000000'<br />%o = '247523255'<br />%s = '43951789'<br />%x = '29ea6ad'<br />%X = '29EA6AD'<br />%+d = '+43951789'<br />%+d = '-43951789'<br />*/<br /><br /></span><span class="default">$s </span><span class="keyword">= </span><span class="string">'monkey'</span><span class="keyword">;<br /></span><span class="default">$t </span><span class="keyword">= </span><span class="string">'many monkeys'</span><span class="keyword">;<br /><br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"[%s]\n"</span><span class="keyword">,&nbsp; &nbsp; &nbsp; </span><span class="default">$s</span><span class="keyword">); </span><span class="comment">// standard string output<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"[%10s]\n"</span><span class="keyword">,&nbsp; &nbsp; </span><span class="default">$s</span><span class="keyword">); </span><span class="comment">// right-justification with spaces<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"[%-10s]\n"</span><span class="keyword">,&nbsp;&nbsp; </span><span class="default">$s</span><span class="keyword">); </span><span class="comment">// left-justification with spaces<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"[%010s]\n"</span><span class="keyword">,&nbsp;&nbsp; </span><span class="default">$s</span><span class="keyword">); </span><span class="comment">// zero-padding works on strings too<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"[%'#10s]\n"</span><span class="keyword">,&nbsp; </span><span class="default">$s</span><span class="keyword">); </span><span class="comment">// use the custom padding character '#'<br /></span><span class="default">printf</span><span class="keyword">(</span><span class="string">"[%10.10s]\n"</span><span class="keyword">, </span><span class="default">$t</span><span class="keyword">); </span><span class="comment">// left-justification but with a cutoff of 10 characters<br /><br />/*<br />[monkey]<br />[&nbsp; &nbsp; monkey]<br />[monkey&nbsp; &nbsp; ]<br />[0000monkey]<br />[####monkey]<br />[many monke]<br />*/<br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120670">  <div class="votes">
    <div id="Vu120670">
    <a href="/manual/vote-note.php?id=120670&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120670">
    <a href="/manual/vote-note.php?id=120670&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120670" title="50% like this...">
    0
    </div>
  </div>
  <a href="#120670" class="name">
  <strong class="user"><em>Nathan Alan</em></strong></a><a class="genanchor" href="#120670"> &para;</a><div class="date" title="2017-02-19 11:03"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom120670">
<div class="phpcode"><code><span class="html">
Just wanted to add that to get the remaining text from the string, you need to add the following as a variable in your scanf<br /><br />%[ -~]<br /><br />Example:<br /><br />sscanf($sql, "[%d,%d]%[ -~]", $sheet_id, $column, $remaining_sql);</span>
</code></div>
  </div>
 </div>
  <div class="note" id="118191">  <div class="votes">
    <div id="Vu118191">
    <a href="/manual/vote-note.php?id=118191&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd118191">
    <a href="/manual/vote-note.php?id=118191&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V118191" title="50% like this...">
    0
    </div>
  </div>
  <a href="#118191" class="name">
  <strong class="user"><em>Sam Bull</em></strong></a><a class="genanchor" href="#118191"> &para;</a><div class="date" title="2015-10-23 02:35"><strong>4 years ago</strong></div>
  <div class="text" id="Hcom118191">
<div class="phpcode"><code><span class="html">
Fix for sprintfn function for named arguments (<a href="http://php.net/manual/en/function.sprintf.php#94608" rel="nofollow" target="_blank">http://php.net/manual/en/function.sprintf.php#94608</a>):<br /><br />Change the first line from:<br />&nbsp; $arg_nums = array_slice(array_flip(array_keys(array(0 =&gt; 0) + $args)), 1);<br />to:<br />&nbsp; $arg_nums = array_keys($args);<br />&nbsp; array_unshift($arg_nums, 0);<br />&nbsp; $arg_nums = array_flip(array_slice($arg_nums, 1, NULL, true));</span>
</code></div>
  </div>
 </div>
  <div class="note" id="117054">  <div class="votes">
    <div id="Vu117054">
    <a href="/manual/vote-note.php?id=117054&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd117054">
    <a href="/manual/vote-note.php?id=117054&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V117054" title="50% like this...">
    0
    </div>
  </div>
  <a href="#117054" class="name">
  <strong class="user"><em>nmmm at nmmm dot nu</em></strong></a><a class="genanchor" href="#117054"> &para;</a><div class="date" title="2015-04-08 07:31"><strong>4 years ago</strong></div>
  <div class="text" id="Hcom117054">
<div class="phpcode"><code><span class="html">
php printf and sprintf not seems to support star "*" formatting.<br /><br />here is an example:<br /><br />printf("%*d\n",3,5);<br /><br />this will print just "d" instead of "&lt;two spaces&gt;5"</span>
</code></div>
  </div>
 </div>
  <div class="note" id="123431">  <div class="votes">
    <div id="Vu123431">
    <a href="/manual/vote-note.php?id=123431&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd123431">
    <a href="/manual/vote-note.php?id=123431&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V123431" title="0% like this...">
    -1
    </div>
  </div>
  <a href="#123431" class="name">
  <strong class="user"><em>Anonymous</em></strong></a><a class="genanchor" href="#123431"> &para;</a><div class="date" title="2018-12-13 02:26"><strong>1 year ago</strong></div>
  <div class="text" id="Hcom123431">
<div class="phpcode"><code><span class="html">
I have written a wrapper for sprintf. Add a new %S&nbsp; (upper case s) where the number indicates the number of characters and not bytes.<br />This is useful for formatting utf-8 strings.<br /><br /><span class="default">&lt;?php<br /></span><span class="keyword">function </span><span class="default">SacSprintf</span><span class="keyword">( </span><span class="default">$format</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$argv </span><span class="keyword">= </span><span class="default">func_get_args</span><span class="keyword">() ;<br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">array_shift</span><span class="keyword">(</span><span class="default">$argv</span><span class="keyword">) ;<br /><br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$offset </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; <br />&nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; <br />&nbsp; &nbsp; &nbsp; &nbsp; while( </span><span class="default">preg_match</span><span class="keyword">(</span><span class="string">"^A%[+-]*[.]*([0-9.]*)([a-z])^Ai"</span><span class="keyword">, </span><span class="default">$format</span><span class="keyword">, </span><span class="default">$match</span><span class="keyword">, </span><span class="default">PREG_OFFSET_CAPTURE</span><span class="keyword">, </span><span class="default">$offset</span><span class="keyword">)) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if( </span><span class="default">$match</span><span class="keyword">[</span><span class="default">2</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">] == </span><span class="string">'S'</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if( </span><span class="default">$match</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">] != </span><span class="string">''</span><span class="keyword">) {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$t1 </span><span class="keyword">= </span><span class="default">explode</span><span class="keyword">(</span><span class="string">'.'</span><span class="keyword">, </span><span class="default">$match</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">]);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$t1</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">] = </span><span class="default">intval</span><span class="keyword">(</span><span class="default">$t1</span><span class="keyword">[</span><span class="default">0</span><span class="keyword">]) + </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$argv</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">]) - </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">utf8_decode</span><span class="keyword">(</span><span class="default">$argv</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">]));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$l1 </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$match</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">]);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$t2 </span><span class="keyword">= </span><span class="default">implode</span><span class="keyword">(</span><span class="string">'.'</span><span class="keyword">, </span><span class="default">$t1</span><span class="keyword">);<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$l2 </span><span class="keyword">= </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$t2</span><span class="keyword">) - </span><span class="default">$l1</span><span class="keyword">; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$format </span><span class="keyword">= </span><span class="default">substr_replace</span><span class="keyword">( </span><span class="default">$format</span><span class="keyword">, </span><span class="default">$t2</span><span class="keyword">, </span><span class="default">$match</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">][</span><span class="default">1</span><span class="keyword">], </span><span class="default">strlen</span><span class="keyword">(</span><span class="default">$match</span><span class="keyword">[</span><span class="default">1</span><span class="keyword">][</span><span class="default">0</span><span class="keyword">]));<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$offset </span><span class="keyword">+= </span><span class="default">$l2</span><span class="keyword">; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$match</span><span class="keyword">[</span><span class="default">2</span><span class="keyword">][</span><span class="default">1</span><span class="keyword">] += </span><span class="default">$l2</span><span class="keyword">; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$format</span><span class="keyword">[</span><span class="default">$match</span><span class="keyword">[</span><span class="default">2</span><span class="keyword">][</span><span class="default">1</span><span class="keyword">]] = </span><span class="string">'s'</span><span class="keyword">; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$offset </span><span class="keyword">+= </span><span class="default">$match</span><span class="keyword">[</span><span class="default">2</span><span class="keyword">][</span><span class="default">1</span><span class="keyword">];<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span><span class="default">$i</span><span class="keyword">++;<br />&nbsp; &nbsp; &nbsp; &nbsp; }&nbsp; &nbsp; <br />&nbsp; &nbsp; &nbsp; &nbsp; return </span><span class="default">vsprintf</span><span class="keyword">(</span><span class="default">$format</span><span class="keyword">, </span><span class="default">$argv</span><span class="keyword">) ;<br />}<br /><br />echo </span><span class="string">"&lt;pre&gt;\n"</span><span class="keyword">;<br />echo </span><span class="string">"&nbsp; &nbsp; &nbsp; 1234567890123456789012345678901234567890\n"</span><span class="keyword">;<br />echo </span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">"Hola, %-20s is my name\n"</span><span class="keyword">, </span><span class="string">"José Luis jiménez"</span><span class="keyword">);<br />echo </span><span class="default">SacSprintf</span><span class="keyword">(</span><span class="string">"Hola, %-20S is my name\n"</span><span class="keyword">, </span><span class="string">"José Luis jiménez"</span><span class="keyword">);<br />echo </span><span class="string">"&lt;/pre&gt;\n"</span><span class="keyword">;<br /></span><span class="default">?&gt;<br /></span><br />The output will be:<br />&nbsp; &nbsp; &nbsp; 1234567890123456789012345678901234567890<br />Hola, José Luis jiménez&nbsp; is my name<br />Hola, José Luis jiménez&nbsp; &nbsp; is my name</span>
</code></div>
  </div>
 </div>
  <div class="note" id="114002">  <div class="votes">
    <div id="Vu114002">
    <a href="/manual/vote-note.php?id=114002&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd114002">
    <a href="/manual/vote-note.php?id=114002&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V114002" title="50% like this...">
    0
    </div>
  </div>
  <a href="#114002" class="name">
  <strong class="user"><em>ivan at php dot net</em></strong></a><a class="genanchor" href="#114002"> &para;</a><div class="date" title="2013-12-28 08:13"><strong>6 years ago</strong></div>
  <div class="text" id="Hcom114002">
<div class="phpcode"><code><span class="html">
There is a minor issue in a code of mb_vsprintf function from viktor at textalk dot com.<br /><br />In "truncate $arg" section the following line:<br />&nbsp; $arg = mb_substr($precision,0,$precision,$encoding);<br />needs to be replaced with:<br />&nbsp; $arg = mb_substr($arg,0,$precision,$encoding);</span>
</code></div>
  </div>
 </div>
  <div class="note" id="110326">  <div class="votes">
    <div id="Vu110326">
    <a href="/manual/vote-note.php?id=110326&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd110326">
    <a href="/manual/vote-note.php?id=110326&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V110326" title="50% like this...">
    0
    </div>
  </div>
  <a href="#110326" class="name">
  <strong class="user"><em>ignat dot scheglovskiy at gmail dot com</em></strong></a><a class="genanchor" href="#110326"> &para;</a><div class="date" title="2012-10-10 08:47"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom110326">
<div class="phpcode"><code><span class="html">
Here is an example how alignment, padding and precision specifier can be used to print formatted list of items:<br /><br /><span class="default">&lt;?php<br /><br />$out </span><span class="keyword">= </span><span class="string">"The Books\n"</span><span class="keyword">;<br /></span><span class="default">$books </span><span class="keyword">= array(</span><span class="string">"Book 1"</span><span class="keyword">, </span><span class="string">"Book 2"</span><span class="keyword">, </span><span class="string">"Book 3"</span><span class="keyword">);<br /></span><span class="default">$pages </span><span class="keyword">= array(</span><span class="string">"123 pages "</span><span class="keyword">, </span><span class="string">"234 pages"</span><span class="keyword">, </span><span class="string">"345 pages"</span><span class="keyword">);<br />for (</span><span class="default">$i </span><span class="keyword">= </span><span class="default">0</span><span class="keyword">; </span><span class="default">$i </span><span class="keyword">&lt; </span><span class="default">count</span><span class="keyword">(</span><span class="default">$books</span><span class="keyword">); </span><span class="default">$i</span><span class="keyword">++) {<br />&nbsp; &nbsp; </span><span class="default">$out </span><span class="keyword">.= </span><span class="default">sprintf</span><span class="keyword">(</span><span class="string">"%'.-20s%'.7.4s\n"</span><span class="keyword">, </span><span class="default">$books</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">], </span><span class="default">$pages</span><span class="keyword">[</span><span class="default">$i</span><span class="keyword">]);<br />}<br />echo </span><span class="default">$out</span><span class="keyword">;<br /><br /></span><span class="comment">// Outputs:<br />// <br />// The Books<br />// Book 1.................123 <br />// Book 2.................234 <br />// Book 3.................345 <br /></span><span class="default">?&gt;</span>
</span>
</code></div>
  </div>
 </div>
  <div class="note" id="77659">  <div class="votes">
    <div id="Vu77659">
    <a href="/manual/vote-note.php?id=77659&amp;page=function.sprintf&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd77659">
    <a href="/manual/vote-note.php?id=77659&amp;page=function.sprintf&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V77659" title="42% like this...">
    -1
    </div>
  </div>
  <a href="#77659" class="name">
  <strong class="user"><em>me at umarfarooq dot net</em></strong></a><a class="genanchor" href="#77659"> &para;</a><div class="date" title="2007-09-06 11:29"><strong>12 years ago</strong></div>
  <div class="text" id="Hcom77659">
<div class="phpcode"><code><span class="html">
/**<br />This function returns a formated&nbsp; string with the legnth you specify<br />@string holds the string which you want to format<br />@len holds the length you want to format <br />**/<br />function formatString($string, $len)<br />{<br />&nbsp; &nbsp; if (strlen($string) &lt; $len)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; $addchar=($len - strlen($string)) ;<br />&nbsp; &nbsp; &nbsp; &nbsp; for ($i = 0; $i &lt; $addchar; $i++) <br />&nbsp; &nbsp; &nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; $string=sprintf("$string%s", "0");<br />&nbsp; &nbsp; &nbsp; &nbsp; }<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; if (strlen($string) &gt; $len)<br />&nbsp; &nbsp; {<br />&nbsp; &nbsp; &nbsp; &nbsp; $string=substr($string,0,$len);<br />&nbsp; &nbsp; }<br />&nbsp; &nbsp; <br />&nbsp; &nbsp; return $string;&nbsp; &nbsp; <br />}</span>
</code></div>
  </div>
 </div></div>

 <div class="foot"><a href="/manual/add-note.php?sect=function.sprintf&amp;redirect=https://www.php.net/manual/pt_BR/function.sprintf.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></div>
</section>    </section><!-- layout-content -->
        <aside class='layout-menu'>

        <ul class='parent-menu-list'>
                                    <li>
                <a href="ref.strings.php">Fun&ccedil;&otilde;es para String</a>

                                    <ul class='child-menu-list'>

                                                <li class="">
                            <a href="function.addcslashes.php" title="addcslashes">addcslashes</a>
                        </li>
                                                <li class="">
                            <a href="function.addslashes.php" title="addslashes">addslashes</a>
                        </li>
                                                <li class="">
                            <a href="function.bin2hex.php" title="bin2hex">bin2hex</a>
                        </li>
                                                <li class="">
                            <a href="function.chop.php" title="chop">chop</a>
                        </li>
                                                <li class="">
                            <a href="function.chr.php" title="chr">chr</a>
                        </li>
                                                <li class="">
                            <a href="function.chunk-split.php" title="chunk_&#8203;split">chunk_&#8203;split</a>
                        </li>
                                                <li class="">
                            <a href="function.convert-cyr-string.php" title="convert_&#8203;cyr_&#8203;string">convert_&#8203;cyr_&#8203;string</a>
                        </li>
                                                <li class="">
                            <a href="function.convert-uudecode.php" title="convert_&#8203;uudecode">convert_&#8203;uudecode</a>
                        </li>
                                                <li class="">
                            <a href="function.convert-uuencode.php" title="convert_&#8203;uuencode">convert_&#8203;uuencode</a>
                        </li>
                                                <li class="">
                            <a href="function.count-chars.php" title="count_&#8203;chars">count_&#8203;chars</a>
                        </li>
                                                <li class="">
                            <a href="function.crc32.php" title="crc32">crc32</a>
                        </li>
                                                <li class="">
                            <a href="function.crypt.php" title="crypt">crypt</a>
                        </li>
                                                <li class="">
                            <a href="function.echo.php" title="echo">echo</a>
                        </li>
                                                <li class="">
                            <a href="function.explode.php" title="explode">explode</a>
                        </li>
                                                <li class="">
                            <a href="function.fprintf.php" title="fprintf">fprintf</a>
                        </li>
                                                <li class="">
                            <a href="function.get-html-translation-table.php" title="get_&#8203;html_&#8203;translation_&#8203;table">get_&#8203;html_&#8203;translation_&#8203;table</a>
                        </li>
                                                <li class="">
                            <a href="function.hebrev.php" title="hebrev">hebrev</a>
                        </li>
                                                <li class="">
                            <a href="function.hebrevc.php" title="hebrevc">hebrevc</a>
                        </li>
                                                <li class="">
                            <a href="function.hex2bin.php" title="hex2bin">hex2bin</a>
                        </li>
                                                <li class="">
                            <a href="function.html-entity-decode.php" title="html_&#8203;entity_&#8203;decode">html_&#8203;entity_&#8203;decode</a>
                        </li>
                                                <li class="">
                            <a href="function.htmlentities.php" title="htmlentities">htmlentities</a>
                        </li>
                                                <li class="">
                            <a href="function.htmlspecialchars-decode.php" title="htmlspecialchars_&#8203;decode">htmlspecialchars_&#8203;decode</a>
                        </li>
                                                <li class="">
                            <a href="function.htmlspecialchars.php" title="htmlspecialchars">htmlspecialchars</a>
                        </li>
                                                <li class="">
                            <a href="function.implode.php" title="implode">implode</a>
                        </li>
                                                <li class="">
                            <a href="function.join.php" title="join">join</a>
                        </li>
                                                <li class="">
                            <a href="function.lcfirst.php" title="lcfirst">lcfirst</a>
                        </li>
                                                <li class="">
                            <a href="function.levenshtein.php" title="levenshtein">levenshtein</a>
                        </li>
                                                <li class="">
                            <a href="function.localeconv.php" title="localeconv">localeconv</a>
                        </li>
                                                <li class="">
                            <a href="function.ltrim.php" title="ltrim">ltrim</a>
                        </li>
                                                <li class="">
                            <a href="function.md5-file.php" title="md5_&#8203;file">md5_&#8203;file</a>
                        </li>
                                                <li class="">
                            <a href="function.md5.php" title="md5">md5</a>
                        </li>
                                                <li class="">
                            <a href="function.metaphone.php" title="metaphone">metaphone</a>
                        </li>
                                                <li class="">
                            <a href="function.money-format.php" title="money_&#8203;format">money_&#8203;format</a>
                        </li>
                                                <li class="">
                            <a href="function.nl-langinfo.php" title="nl_&#8203;langinfo">nl_&#8203;langinfo</a>
                        </li>
                                                <li class="">
                            <a href="function.nl2br.php" title="nl2br">nl2br</a>
                        </li>
                                                <li class="">
                            <a href="function.number-format.php" title="number_&#8203;format">number_&#8203;format</a>
                        </li>
                                                <li class="">
                            <a href="function.ord.php" title="ord">ord</a>
                        </li>
                                                <li class="">
                            <a href="function.parse-str.php" title="parse_&#8203;str">parse_&#8203;str</a>
                        </li>
                                                <li class="">
                            <a href="function.print.php" title="print">print</a>
                        </li>
                                                <li class="">
                            <a href="function.printf.php" title="printf">printf</a>
                        </li>
                                                <li class="">
                            <a href="function.quoted-printable-decode.php" title="quoted_&#8203;printable_&#8203;decode">quoted_&#8203;printable_&#8203;decode</a>
                        </li>
                                                <li class="">
                            <a href="function.quoted-printable-encode.php" title="quoted_&#8203;printable_&#8203;encode">quoted_&#8203;printable_&#8203;encode</a>
                        </li>
                                                <li class="">
                            <a href="function.quotemeta.php" title="quotemeta">quotemeta</a>
                        </li>
                                                <li class="">
                            <a href="function.rtrim.php" title="rtrim">rtrim</a>
                        </li>
                                                <li class="">
                            <a href="function.setlocale.php" title="setlocale">setlocale</a>
                        </li>
                                                <li class="">
                            <a href="function.sha1-file.php" title="sha1_&#8203;file">sha1_&#8203;file</a>
                        </li>
                                                <li class="">
                            <a href="function.sha1.php" title="sha1">sha1</a>
                        </li>
                                                <li class="">
                            <a href="function.similar-text.php" title="similar_&#8203;text">similar_&#8203;text</a>
                        </li>
                                                <li class="">
                            <a href="function.soundex.php" title="soundex">soundex</a>
                        </li>
                                                <li class="current">
                            <a href="function.sprintf.php" title="sprintf">sprintf</a>
                        </li>
                                                <li class="">
                            <a href="function.sscanf.php" title="sscanf">sscanf</a>
                        </li>
                                                <li class="">
                            <a href="function.str-getcsv.php" title="str_&#8203;getcsv">str_&#8203;getcsv</a>
                        </li>
                                                <li class="">
                            <a href="function.str-ireplace.php" title="str_&#8203;ireplace">str_&#8203;ireplace</a>
                        </li>
                                                <li class="">
                            <a href="function.str-pad.php" title="str_&#8203;pad">str_&#8203;pad</a>
                        </li>
                                                <li class="">
                            <a href="function.str-repeat.php" title="str_&#8203;repeat">str_&#8203;repeat</a>
                        </li>
                                                <li class="">
                            <a href="function.str-replace.php" title="str_&#8203;replace">str_&#8203;replace</a>
                        </li>
                                                <li class="">
                            <a href="function.str-rot13.php" title="str_&#8203;rot13">str_&#8203;rot13</a>
                        </li>
                                                <li class="">
                            <a href="function.str-shuffle.php" title="str_&#8203;shuffle">str_&#8203;shuffle</a>
                        </li>
                                                <li class="">
                            <a href="function.str-split.php" title="str_&#8203;split">str_&#8203;split</a>
                        </li>
                                                <li class="">
                            <a href="function.str-word-count.php" title="str_&#8203;word_&#8203;count">str_&#8203;word_&#8203;count</a>
                        </li>
                                                <li class="">
                            <a href="function.strcasecmp.php" title="strcasecmp">strcasecmp</a>
                        </li>
                                                <li class="">
                            <a href="function.strchr.php" title="strchr">strchr</a>
                        </li>
                                                <li class="">
                            <a href="function.strcmp.php" title="strcmp">strcmp</a>
                        </li>
                                                <li class="">
                            <a href="function.strcoll.php" title="strcoll">strcoll</a>
                        </li>
                                                <li class="">
                            <a href="function.strcspn.php" title="strcspn">strcspn</a>
                        </li>
                                                <li class="">
                            <a href="function.strip-tags.php" title="strip_&#8203;tags">strip_&#8203;tags</a>
                        </li>
                                                <li class="">
                            <a href="function.stripcslashes.php" title="stripcslashes">stripcslashes</a>
                        </li>
                                                <li class="">
                            <a href="function.stripos.php" title="stripos">stripos</a>
                        </li>
                                                <li class="">
                            <a href="function.stripslashes.php" title="stripslashes">stripslashes</a>
                        </li>
                                                <li class="">
                            <a href="function.stristr.php" title="stristr">stristr</a>
                        </li>
                                                <li class="">
                            <a href="function.strlen.php" title="strlen">strlen</a>
                        </li>
                                                <li class="">
                            <a href="function.strnatcasecmp.php" title="strnatcasecmp">strnatcasecmp</a>
                        </li>
                                                <li class="">
                            <a href="function.strnatcmp.php" title="strnatcmp">strnatcmp</a>
                        </li>
                                                <li class="">
                            <a href="function.strncasecmp.php" title="strncasecmp">strncasecmp</a>
                        </li>
                                                <li class="">
                            <a href="function.strncmp.php" title="strncmp">strncmp</a>
                        </li>
                                                <li class="">
                            <a href="function.strpbrk.php" title="strpbrk">strpbrk</a>
                        </li>
                                                <li class="">
                            <a href="function.strpos.php" title="strpos">strpos</a>
                        </li>
                                                <li class="">
                            <a href="function.strrchr.php" title="strrchr">strrchr</a>
                        </li>
                                                <li class="">
                            <a href="function.strrev.php" title="strrev">strrev</a>
                        </li>
                                                <li class="">
                            <a href="function.strripos.php" title="strripos">strripos</a>
                        </li>
                                                <li class="">
                            <a href="function.strrpos.php" title="strrpos">strrpos</a>
                        </li>
                                                <li class="">
                            <a href="function.strspn.php" title="strspn">strspn</a>
                        </li>
                                                <li class="">
                            <a href="function.strstr.php" title="strstr">strstr</a>
                        </li>
                                                <li class="">
                            <a href="function.strtok.php" title="strtok">strtok</a>
                        </li>
                                                <li class="">
                            <a href="function.strtolower.php" title="strtolower">strtolower</a>
                        </li>
                                                <li class="">
                            <a href="function.strtoupper.php" title="strtoupper">strtoupper</a>
                        </li>
                                                <li class="">
                            <a href="function.strtr.php" title="strtr">strtr</a>
                        </li>
                                                <li class="">
                            <a href="function.substr-compare.php" title="substr_&#8203;compare">substr_&#8203;compare</a>
                        </li>
                                                <li class="">
                            <a href="function.substr-count.php" title="substr_&#8203;count">substr_&#8203;count</a>
                        </li>
                                                <li class="">
                            <a href="function.substr-replace.php" title="substr_&#8203;replace">substr_&#8203;replace</a>
                        </li>
                                                <li class="">
                            <a href="function.substr.php" title="substr">substr</a>
                        </li>
                                                <li class="">
                            <a href="function.trim.php" title="trim">trim</a>
                        </li>
                                                <li class="">
                            <a href="function.ucfirst.php" title="ucfirst">ucfirst</a>
                        </li>
                                                <li class="">
                            <a href="function.ucwords.php" title="ucwords">ucwords</a>
                        </li>
                                                <li class="">
                            <a href="function.vfprintf.php" title="vfprintf">vfprintf</a>
                        </li>
                                                <li class="">
                            <a href="function.vprintf.php" title="vprintf">vprintf</a>
                        </li>
                                                <li class="">
                            <a href="function.vsprintf.php" title="vsprintf">vsprintf</a>
                        </li>
                                                <li class="">
                            <a href="function.wordwrap.php" title="wordwrap">wordwrap</a>
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
