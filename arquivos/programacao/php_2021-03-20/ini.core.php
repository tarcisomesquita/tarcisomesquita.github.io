<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: Description of core php.ini directives - Manual </title>

 <link rel="shortcut icon" href="https://www.php.net/favicon.ico">
 <link rel="search" type="application/opensearchdescription+xml" href="http://php.net/phpnetimprovedsearch.src" title="Add PHP.net search">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/releases/feed.php" title="PHP Release feed">
 <link rel="alternate" type="application/atom+xml" href="https://www.php.net/feed.atom" title="PHP: Hypertext Preprocessor">

 <link rel="canonical" href="https://www.php.net/manual/en/ini.core.php">
 <link rel="shorturl" href="https://www.php.net/manual/en/ini.core.php">
 <link rel="alternate" href="https://www.php.net/manual/en/ini.core.php" hreflang="x-default">

 <link rel="contents" href="https://www.php.net/manual/en/index.php">
 <link rel="index" href="https://www.php.net/manual/en/ini.php">
 <link rel="prev" href="https://www.php.net/manual/en/ini.sections.php">
 <link rel="next" href="https://www.php.net/manual/en/extensions.php">

 <link rel="alternate" href="https://www.php.net/manual/en/ini.core.php" hreflang="en">
 <link rel="alternate" href="https://www.php.net/manual/pt_BR/ini.core.php" hreflang="pt_BR">
 <link rel="alternate" href="https://www.php.net/manual/zh/ini.core.php" hreflang="zh">
 <link rel="alternate" href="https://www.php.net/manual/fr/ini.core.php" hreflang="fr">
 <link rel="alternate" href="https://www.php.net/manual/de/ini.core.php" hreflang="de">
 <link rel="alternate" href="https://www.php.net/manual/ja/ini.core.php" hreflang="ja">
 <link rel="alternate" href="https://www.php.net/manual/ro/ini.core.php" hreflang="ro">
 <link rel="alternate" href="https://www.php.net/manual/ru/ini.core.php" hreflang="ru">
 <link rel="alternate" href="https://www.php.net/manual/es/ini.core.php" hreflang="es">
 <link rel="alternate" href="https://www.php.net/manual/tr/ini.core.php" hreflang="tr">

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

 <base href="https://www.php.net/manual/en/ini.core.php">

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
        <a href="extensions.php">
          Extension List/Categorization &raquo;
        </a>
      </div>
              <div class="prev">
        <a href="ini.sections.php">
          &laquo; List of php.ini sections        </a>
      </div>
          <ul>
            <li><a href='index.php'>PHP Manual</a></li>      <li><a href='appendices.php'>Appendices</a></li>      <li><a href='ini.php'>php.ini directives</a></li>      </ul>
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
            <option value='en/ini.core.php' selected="selected">English</option>
            <option value='pt_BR/ini.core.php'>Brazilian Portuguese</option>
            <option value='zh/ini.core.php'>Chinese (Simplified)</option>
            <option value='fr/ini.core.php'>French</option>
            <option value='de/ini.core.php'>German</option>
            <option value='ja/ini.core.php'>Japanese</option>
            <option value='ro/ini.core.php'>Romanian</option>
            <option value='ru/ini.core.php'>Russian</option>
            <option value='es/ini.core.php'>Spanish</option>
            <option value='tr/ini.core.php'>Turkish</option>
            <option value="help-translate.php">Other</option>
          </select>
        </fieldset>
      </form>
    </div>
    <div class="edit-bug">
      <a href="https://edit.php.net/?project=PHP&amp;perm=en/ini.core.php">Edit</a>
      <a href="https://bugs.php.net/report.php?bug_type=Documentation+problem&amp;manpage=ini.core">Report a Bug</a>
    </div>
  </div><div id="ini.core" class="section">
  <h2 class="title">Description of core <var class="filename">php.ini</var> directives</h2>
  <p class="para">
   This list includes the core <var class="filename">php.ini</var> directives you can set to
   configure your PHP setup. Directives handled by extensions are listed
   and detailed at the extension documentation pages respectively;
   Information on the session directives for example can be found at the
   <a href="session.configuration.php" class="link">sessions page</a>.
  </p>
  <blockquote class="note"><p><strong class="note">Note</strong>: 
   <p class="para">
    The defaults listed here are used when <var class="filename">php.ini</var> is not loaded; the values for the production and development <var class="filename">php.ini</var> may vary.
   </p>
  </p></blockquote>
  <div class="section" id="ini.sect.language-options">
   <h2 class="title">Language Options</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>Language and Misc Configuration Options</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.short-open-tag" class="link">short_open_tag</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.asp-tags" class="link">asp_tags</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Removed in PHP 7.0.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.precision" class="link">precision</a></td>
        <td>&quot;14&quot;</td>
        <td>PHP_INI_ALL</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.serialize-precision" class="link">serialize_precision</a></td>
        <td>&quot;-1&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>
         Before PHP 5.3.6, the default value was 100.
         Before PHP 7.1.0, the default value was 17.
        </td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.y2k-compliance" class="link">y2k_compliance</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>Removed in PHP 5.4.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.allow-call-time-pass-reference" class="link">allow_call_time_pass_reference</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Removed in PHP 5.4.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.disable-functions" class="link">disable_functions</a></td>
        <td>&quot;&quot;</td>
        <td>PHP_INI_SYSTEM only</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.disable-classes" class="link">disable_classes</a></td>
        <td>&quot;&quot;</td>
        <td><var class="filename">php.ini</var> only</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.exit-on-timeout" class="link">exit_on_timeout</a></td>
        <td>&quot;&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>Available since PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.expose-php" class="link">expose_php</a></td>
        <td>&quot;1&quot;</td>
        <td><var class="filename">php.ini</var> only</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.hard-timeout" class="link">hard_timeout</a></td>
        <td>&quot;2&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 7.1.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend.multibyte" class="link">zend.multibyte</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>Available since PHP 5.4.0</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend.script-encoding" class="link">zend.script_encoding</a></td>
        <td>NULL</td>
        <td>PHP_INI_ALL</td>
        <td>Available since PHP 5.4.0</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend.detect-unicode" class="link">zend.detect-unicode</a></td>
        <td>NULL</td>
        <td>PHP_INI_ALL</td>
        <td>Available since PHP 5.4.0</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend.signal-check" class="link">zend.signal_check</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.4.0</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend.assertions" class="link">zend.assertions</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_ALL with restrictions</td>
        <td>Available since PHP 7.0.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend.ze1-compatibility-mode" class="link">zend.ze1_compatibility_mode</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>Removed in PHP 5.3.0</td>
       </tr>

       <tr>
        <td>detect_unicode</td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>Available since PHP 5.1.0. Renamed to <a href="ini.core.php#ini.zend.detect-unicode" class="link">zend.detect-unicode</a> from PHP 5.4.0.</td>
       </tr>

      </tbody>
     
    </table>

   </p>
   
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   
   <p class="para">
    <dl>

     
      <dt id="ini.short-open-tag">
       <code class="parameter">short_open_tag</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Tells PHP whether the short form (<strong class="userinput"><code>&lt;? ?&gt;</code></strong>)
        of PHP&#039;s open tag should be allowed.  If you want to use PHP in
        combination with XML, you can disable this option in order to
        use <strong class="userinput"><code>&lt;?xml ?&gt;</code></strong> inline.  Otherwise, you
        can print it with PHP, for example: <strong class="userinput"><code>&lt;?php echo &#039;&lt;?xml
        version=&quot;1.0&quot;?&gt;&#039;; ?&gt;</code></strong>.  Also, if disabled, you must use the
        long form of the PHP open tag (<strong class="userinput"><code>&lt;?php ?&gt;</code></strong>).
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         This directive also affected the shorthand 
         <strong class="userinput"><code>&lt;?=</code></strong> before PHP 5.4.0,
         which is identical to <strong class="userinput"><code>&lt;? echo</code></strong>.  Use of this
         shortcut required <code class="systemitem systemitem">short_open_tag</code>
         to be on.
         Since PHP 5.4.0, <strong class="userinput"><code>&lt;?=</code></strong> is always available.
        </p>
       </p></blockquote>
      </dd>

     
     
     
      <dt id="ini.asp-tags">
       <code class="parameter">asp_tags</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <span class="simpara">
        Enables the use of ASP-like &lt;% %&gt; tags in addition to
        the usual &lt;?php ?&gt; tags. This includes the
        variable-value printing shorthand of &lt;%= $value %&gt;. For
        more information, see <a href="language.basic-syntax.phpmode.php" class="link">Escaping from HTML</a>.
       </span>
       <p class="para">
        <table class="doctable table">
         <caption><strong>Changelog for <em>asp_tags</em></strong></caption>
         
          <thead>
           <tr>
            <th>Version</th>
            <th>Description</th>
           </tr>

          </thead>

          <tbody class="tbody">
           <tr>
            <td>7.0.0</td>
            <td>
             Removed from PHP.
            </td>
           </tr>

          </tbody>
         
        </table>

       </p>
      </dd>

     
     
     
      <dt id="ini.precision">
       <code class="parameter">precision</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <span class="simpara">
        The number of significant digits displayed in floating point numbers.
        <em>-1</em> means that an enhanced algorithm for rounding 
        such numbers will be used.
       </span>
      </dd>

     

     
      <dt id="ini.serialize-precision">
       <code class="parameter">serialize_precision</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <span class="simpara">
        The number of significant digits stored while serializing floating point numbers.
        <em>-1</em> means that an enhanced algorithm for rounding 
        such numbers will be used.
      </span>
      </dd>

     
     
     
      <dt id="ini.y2k-compliance">
       <code class="parameter">y2k_compliance</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <span class="simpara">
        Enforce year 2000 compliance (will cause problems with non-compliant browsers)
       </span>
      </dd>

     
     
     
     
      <dt id="ini.allow-call-time-pass-reference">
       <code class="parameter">allow_call_time_pass_reference</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Whether to warn when arguments are passed by reference at function call time. 
        The encouraged method of specifying which arguments should be passed by 
        reference is in the function  declaration. You&#039;re encouraged to try and turn 
        this option Off and make sure your scripts work properly with it in order to 
        ensure they will work with future versions of the language (you will receive 
        a warning each time you use this feature).
       </p>
       <p class="para">
        Passing arguments by reference at function call time was deprecated for
        code-cleanliness reasons. A function can modify its arguments in an 
        undocumented way if it didn&#039;t declare that the argument shall be passed by
        reference. To prevent side-effects it&#039;s better to specify which
        arguments are passed by reference in the function declaration only.
       </p>
       <p class="para">
        See also <a href="language.references.php" class="link">References Explained</a>.
       </p>
       <p class="para">
        <table class="doctable table">
         <caption><strong>Changelog for <em>allow_call_time_pass_reference</em></strong></caption>
         
          <thead>
           <tr>
            <th>Version</th>
            <th>Description</th>
           </tr>

          </thead>

          <tbody class="tbody">
           <tr>
            <td>5.4.0</td>
            <td>
             Removed from PHP.
            </td>
           </tr>

           <tr>
            <td>5.3.0</td>
            <td>
             Emits an <strong><code>E_DEPRECATED</code></strong> level error.
            </td>
           </tr>

           <tr>
            <td>5.0.0</td>
            <td>
             Deprecated, and generates an <strong><code>E_COMPILE_WARNING</code></strong> level error.
            </td>
           </tr>

          </tbody>
         
        </table>

       </p>
      </dd>

     
     
     
      <dt id="ini.expose-php">
       <code class="parameter">expose_php</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Exposes to the world that PHP is installed on the server, which includes the
        PHP version within the HTTP header (e.g., X-Powered-By: PHP/5.3.7).
        Prior to PHP 5.5.0 the PHP logo guids are also exposed, thus appending them
        to the URL of your PHP script would display the appropriate logo
        (e.g., <a href="https://www.php.net/?=PHPE9568F34-D428-11d2-A769-00AA001ACF42" class="link external">&raquo;&nbsp;https://www.php.net/?=PHPE9568F34-D428-11d2-A769-00AA001ACF42</a>).
        This also affected the output of <span class="function"><a href="function.phpinfo.php" class="function">phpinfo()</a></span>, as when disabled, the PHP logo
        and credits information would not be displayed.
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         Since PHP 5.5.0 these guids and the <span class="function"><a href="function.php-logo-guid.php" class="function">php_logo_guid()</a></span> function
         have been removed from PHP and the guids are replaced with data URIs instead.
         Thus accessing the PHP logo via appending the guid to the URL no longer works.
         Similarly, turning <code class="parameter">expose_php</code> off will not affect
         seeing the PHP logo in <span class="function"><a href="function.phpinfo.php" class="function">phpinfo()</a></span>.
        </p>
       </p></blockquote>
       <p class="para">       
        See also <span class="function"><a href="function.php-logo-guid.php" class="function">php_logo_guid()</a></span> and <span class="function"><a href="function.phpcredits.php" class="function">phpcredits()</a></span>.
       </p>
      </dd>

     
     
     
      <dt id="ini.disable-functions">
       <code class="parameter">disable_functions</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        This directive allows you to disable certain functions for 
        <a href="security.php" class="link">security</a> reasons. It takes 
        on a comma-delimited list of function names. disable_functions
        is not affected by <a href="ini.sect.safe-mode.php#ini.safe-mode" class="link">Safe Mode</a>.
       </p>
       <p class="para">
        Only <a href="functions.internal.php" class="link">internal functions</a> can
        be disabled using this directive. <a href="functions.user-defined.php" class="link">User-defined functions</a>
        are unaffected.
       </p>
       <p class="para">
        This directive must be set in <var class="filename">php.ini</var> For example, you 
        cannot set this in <var class="filename">httpd.conf</var>.
       </p>
      </dd>

     
     
     
      <dt id="ini.disable-classes">
       <code class="parameter">disable_classes</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <span class="simpara">
        This directive allows you to disable certain classes for
        <a href="security.php" class="link">security</a> reasons.  It takes
        on a comma-delimited list of class names.  disable_classes
        is not affected by <a href="ini.sect.safe-mode.php#ini.safe-mode" class="link">Safe Mode</a>.
       </span>
       <span class="simpara">
        This directive must be set in <var class="filename">php.ini</var>  For example, you
        cannot set this in <var class="filename">httpd.conf</var>.
       </span>
      </dd>

     

     
      <dt id="ini.zend.assertions">
       <code class="parameter">zend.assertions</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <span class="simpara">
        When set to <em>1</em>, assertion code will be generated and
        executed (development mode). When set to <em>0</em>,
        assertion code will be generated but it will be skipped (not executed)
        at runtime. When set to <em>-1</em>, assertion code will not
        be generated, making the assertions zero-cost (production mode). 
       </span>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         If a process is started in production mode, <a href="ini.core.php#ini.zend.assertions" class="link">zend.assertions</a>
         cannot be changed at runtime, since the code for assertions was not generated.
        </p>
        <p class="para">
         If a process is started in development mode, <a href="ini.core.php#ini.zend.assertions" class="link">zend.assertions</a>
         cannot be set to <em>-1</em> at runtime.
        </p>
       </p></blockquote>
      </dd>

     
     
     
      <dt id="ini.zend.ze1-compatibility-mode">
       <code class="parameter">zend.ze1_compatibility_mode</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Enable compatibility mode with Zend Engine 1 (PHP 4).  It affects
        the cloning, casting (objects with no properties cast to <strong><code>FALSE</code></strong> or 0), and <a href="language.oop5.object-comparison.php" class="link">comparing of objects</a>.
        In this mode, objects are passed by value instead of reference by
        default.
       </p>
       <p class="para">
        See also the section titled
        <a href="migration5.php" class="link">Migrating from PHP 4 to PHP 5</a>.
       </p>
       <div class="warning"><strong class="warning">Warning</strong>
        <p class="simpara">This feature has been <em class="emphasis">DEPRECATED</em> and <em class="emphasis">REMOVED</em>
         as of PHP 5.3.0.
        </p>
       </div>
      </dd>

     
     
     
      <dt id="ini.hard-timeout">
       <code class="parameter">hard_timeout</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <p class="para">
       </p>
      </dd>

     
     
     
      <dt id="ini.zend.multibyte">
       <code class="parameter">zend.multibyte</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Enables parsing of source files in multibyte encodings. Enabling zend.multibyte 
        is required to use character encodings like SJIS, BIG5, etc that contain special
        characters in multibyte string data. ISO-8859-1 compatible encodings like UTF-8, 
        EUC, etc do not require this option.
       </p>
       <p class="para">
        Enabling zend.multibyte requires the mbstring extension to be available.
       </p>
      </dd>

     
     
     
      <dt id="ini.zend.script-encoding">
       <code class="parameter">zend.script_encoding</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        This value will be used unless a
        <a href="control-structures.declare.php#control-structures.declare.encoding" class="link">declare(encoding=...)</a>
        directive appears at the top of the script. When ISO-8859-1 incompatible encoding
        is used, both zend.multibyte and zend.script_encoding must be used.
       </p>
       <p class="para">
        Literal strings will be transliterated from zend.script_enconding to
        mbstring.internal_encoding, as if
        <span class="function"><a href="function.mb-convert-encoding.php" class="function">mb_convert_encoding()</a></span> would have been called.
       </p>
      </dd>

     

     
      <dt id="ini.zend.detect-unicode">
       <code class="parameter">zend.detect_unicode</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Check for BOM (Byte Order Mark) and see if the file contains valid
        multibyte characters.
        This detection is performed before processing of
        <span class="function"><a href="function.halt-compiler.php" class="function">__halt_compiler()</a></span>.
        Available only in Zend Multibyte mode.
       </p>
      </dd>

     
     
     
      <dt id="ini.zend.signal-check">
       <code class="parameter">zend.signal_check</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        To check for replaced signal handlers on shutdown.
       </p>
      </dd>

     
     
     
      <dt id="ini.exit-on-timeout">
       <code class="parameter">exit_on_timeout</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        This is an Apache1 mod_php-only directive that forces an Apache child to exit if a PHP execution timeout occurred.
        Such a timeout causes an internal longjmp() call in Apache1 which can leave some extensions in an inconsistent
        state. By terminating the process any outstanding locks or memory will be cleaned up.
       </p>
      </dd>

     
     
    </dl>

   </p>
  </div>
  
  <div class="section" id="ini.sect.resource-limits">
   <h2 class="title">Resource Limits</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>Resource Limits</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.memory-limit" class="link">memory_limit</a></td>
        <td>&quot;128M&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>&quot;8M&quot; before PHP 5.2.0, &quot;16M&quot; in PHP 5.2.0</td>
       </tr>

      </tbody>
     
    </table>

   </p>
   
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   
   <p class="para">
    <dl>

     
      <dt id="ini.memory-limit">
       <code class="parameter">memory_limit</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <p class="para">
        This sets the maximum amount of memory in bytes that a script
        is allowed to allocate.  This helps prevent poorly written
        scripts for eating up all available memory on a server. Note that
        to have no memory limit, set this directive to <em>-1</em>.
       </p>
       <p class="para">
        Prior to PHP 5.2.1, in order to use this directive it had to
        be enabled at compile time by using
        <strong class="option configure">--enable-memory-limit</strong>
 in the
        configure line. This compile-time flag was also required to define
        the functions <span class="function"><a href="function.memory-get-usage.php" class="function">memory_get_usage()</a></span> and
        <span class="function"><a href="function.memory-get-peak-usage.php" class="function">memory_get_peak_usage()</a></span> prior to 5.2.1.
       </p>
       
       <span class="simpara">When an <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span> is used, the
value is measured in bytes. Shorthand notation, as described
in <a href="faq.using.php#faq.using.shorthandbytes" class="link">this FAQ</a>, may also be used.
</span>
       
      </dd>

     
    </dl>

   </p>
   <p class="para">
    See also: <a href="info.configuration.php#ini.max-execution-time" class="link">max_execution_time</a>.
   </p>
  </div>
  
  <div class="section" id="ini.sect.performance">
   <h2 class="title">Performance Tuning</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>Performance Tuning</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.realpath-cache-size" class="link">realpath_cache_size</a></td>
        <td>&quot;4M&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.1.0. Prior to PHP 7.0.16 and 7.1.2, the default was <em>&quot;16K&quot;</em></td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.realpath-cache-ttl" class="link">realpath_cache_ttl</a></td>
        <td>&quot;120&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.1.0.</td>
       </tr>

      </tbody>
     
    </table>

    <blockquote class="note"><p><strong class="note">Note</strong>: 
     <p class="para">
      Using <a href="ini.core.php#ini.open-basedir" class="link">open_basedir</a> will
      <em class="emphasis">disable</em> the realpath cache.
     </p>
    </p></blockquote>
   </p>
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   <p class="para">
    <dl>

     
      <dt id="ini.realpath-cache-size">
       <code class="parameter">realpath_cache_size</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <p class="para">
        Determines the size of the realpath cache to be used by PHP. This
        value should be increased on systems where PHP opens many files, to
        reflect the quantity of the file operations performed.
       </p>
       <p class="para">
        The size represents the total number of bytes in the path strings
        stored, plus the size of the data associated with the cache entry. This
        means that in order to store longer paths in the cache, the cache size
        must be larger. This value does not directly control the number of
        distinct paths that can be cached.
       </p>
       <p class="para">
        The size required for the cache entry data is system dependent.
       </p>
      </dd>

     
     
      <dt id="ini.realpath-cache-ttl">
       <code class="parameter">realpath_cache_ttl</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <p class="para">
        Duration of time (in seconds) for which to cache realpath information
        for a given file or directory. For systems with rarely changing files,
        consider increasing the value.
       </p>
      </dd>

     
    </dl>

   </p>
  </div>
  
  <div class="section" id="ini.sect.data-handling">
   <h2 class="title">Data Handling</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>Data Handling Configuration Options</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.arg-separator.output" class="link">arg_separator.output</a></td>
        <td>&quot;&amp;&quot;</td>
        <td>PHP_INI_ALL</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.arg-separator.input" class="link">arg_separator.input</a></td>
        <td>&quot;&amp;&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.variables-order" class="link">variables_order</a></td>
        <td>&quot;EGPCS&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>PHP_INI_ALL in PHP &lt;= 5.0.5.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.request-order" class="link">request_order</a></td>
        <td>&quot;&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Available since PHP 5.3.0</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.auto-globals-jit" class="link">auto_globals_jit</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Available since PHP 5.0.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.register-globals" class="link">register_globals</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Removed in PHP 5.4.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.register-argc-argv" class="link">register_argc_argv</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.register-long-arrays" class="link">register_long_arrays</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Deprecated in PHP 5.3.0. Removed in PHP 5.4.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.enable-post-data-reading" class="link">enable_post_data_reading</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Available since PHP 5.4.0</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.post-max-size" class="link">post_max_size</a></td>
        <td>&quot;8M&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.auto-prepend-file" class="link">auto_prepend_file</a></td>
        <td>NULL</td>
        <td>PHP_INI_PERDIR</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.auto-append-file" class="link">auto_append_file</a></td>
        <td>NULL</td>
        <td>PHP_INI_PERDIR</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.default-mimetype" class="link">default_mimetype</a></td>
        <td>&quot;text/html&quot;</td>
        <td>PHP_INI_ALL</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.default-charset" class="link">default_charset</a></td>
        <td>&quot;UTF-8&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>Defaults to &quot;UTF-8&quot; since PHP &gt;= 5.6.0; empty for PHP &lt; 5.6.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.always-populate-raw-post-data" class="link">always_populate_raw_post_data</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td>Removed in PHP 7.0.0.</td>
       </tr>

      </tbody>
     
    </table>

   </p>
   
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   
   <p class="para">
    <dl>

     
      <dt id="ini.arg-separator.output">
       <code class="parameter">arg_separator.output</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        The separator used in PHP generated URLs to separate arguments.
       </p>
      </dd>

     
     
     
      <dt id="ini.arg-separator.input">
       <code class="parameter">arg_separator.input</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        List of separator(s) used by PHP to parse input URLs into variables.
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         Every character in this directive is considered as separator!
        </p>
       </p></blockquote>
      </dd>

     
     
     
      <dt id="ini.variables-order">
       <code class="parameter">variables_order</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Sets the order of the EGPCS (<em>E</em>nvironment,
        <em>G</em>et, <em>P</em>ost,
        <em>C</em>ookie, and <em>S</em>erver) variable
        parsing. For example, if variables_order
        is set to <em>&quot;SP&quot;</em> then PHP will create the
        <a href="language.variables.predefined.php" class="link">superglobals</a> <var class="varname"><var class="varname"><a href="reserved.variables.server.php" class="classname">$_SERVER</a></var></var> and
        <var class="varname"><var class="varname"><a href="reserved.variables.post.php" class="classname">$_POST</a></var></var>, but not create
        <var class="varname"><var class="varname"><a href="reserved.variables.environment.php" class="classname">$_ENV</a></var></var>, <var class="varname"><var class="varname"><a href="reserved.variables.get.php" class="classname">$_GET</a></var></var>, and
        <var class="varname"><var class="varname"><a href="reserved.variables.cookies.php" class="classname">$_COOKIE</a></var></var>.  Setting to &quot;&quot; means no
        <a href="language.variables.predefined.php" class="link">superglobals</a> will be set.
       </p>
       <p class="para">
        If the deprecated
        <a href="ini.core.php#ini.register-globals" class="link">register_globals</a>
        directive is on, then variables_order also
        configures the order the <em>ENV</em>,
        <em>GET</em>, <em>POST</em>,
        <em>COOKIE</em> and <em>SERVER</em> variables
        are populated in global scope. So for example if variables_order
        is set to <em>&quot;EGPCS&quot;</em>, register_globals is enabled,
        and both <var class="varname"><var class="varname"><a href="reserved.variables.get.php" class="classname">$_GET['action']</a></var></var> and
        <var class="varname"><var class="varname"><a href="reserved.variables.post.php" class="classname">$_POST['action']</a></var></var> are set, then
        <var class="varname"><var class="varname">$action</var></var> will contain the value of
        <var class="varname"><var class="varname"><a href="reserved.variables.post.php" class="classname">$_POST['action']</a></var></var> as <em>P</em> comes
        after <em>G</em> in our example directive value.
       </p>
       <div class="warning"><strong class="warning">Warning</strong>
        <p class="para">
         In both the CGI and FastCGI SAPIs,
         <var class="varname"><var class="varname"><a href="reserved.variables.server.php" class="classname">$_SERVER</a></var></var> is
         also populated by values from the environment; <em>S</em>
         is always equivalent to <em>ES</em> regardless of the
         placement of <em>E</em> elsewhere in this directive.
        </p>
       </div>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         The content and order of
         <var class="varname"><var class="varname"><a href="reserved.variables.request.php" class="classname">$_REQUEST</a></var></var> is also
         affected by this directive.
        </p>
       </p></blockquote>
      </dd>

     
     
     
      <dt id="ini.request-order">
       <code class="parameter">request_order</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        This directive describes the order in which PHP registers GET, POST
        and Cookie variables into the _REQUEST array. Registration is done
        from left to right, newer values override older values.
       </p>
       <p class="para">
        If this directive is not set, <a href="ini.core.php#ini.variables-order" class="link">variables_order</a> is used for
        <var class="varname"><var class="varname"><a href="reserved.variables.request.php" class="classname">$_REQUEST</a></var></var> contents.
       </p>
       <p class="para">
        Note that the default distribution <var class="filename">php.ini</var> files does not contain 
        the <em>&#039;C&#039;</em> for cookies, due to security concerns.
       </p>
      </dd>

     
     
     
      <dt id="ini.auto-globals-jit">
       <code class="parameter">auto_globals_jit</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        When enabled, the SERVER, REQUEST, and ENV variables are created when they&#039;re
        first used (Just In Time) instead of when the script starts. If these
        variables are not used within a script, having this directive on will
        result in a performance gain.
       </p>
       <p class="para">
        The PHP directives
        <a href="ini.core.php#ini.register-globals" class="link">register_globals</a>,
        <a href="ini.core.php#ini.register-long-arrays" class="link">register_long_arrays</a>,
        and <a href="ini.core.php#ini.register-argc-argv" class="link">register_argc_argv</a>
        must be disabled for this directive to have any affect. Since PHP
        5.1.3 it is not necessary to have <a href="ini.core.php#ini.register-argc-argv" class="link">register_argc_argv</a> disabled.
       </p>
       <div class="warning"><strong class="warning">Warning</strong>
        <p class="para">
         Usage of SERVER, REQUEST, and ENV variables is checked during the compile time
         so using them through e.g. <a href="language.variables.variable.php" class="link">variable variables</a> will
         not cause their initialization.
        </p>
       </div>
      </dd>

     
     
     
      <dt id="ini.register-globals">
       <code class="parameter">register_globals</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Whether or not to register the EGPCS (Environment, GET,
        POST, Cookie, Server) variables as global variables.
       </p>
       <p class="para">
        As of <a href="https://www.php.net/releases/4_2_0.php" class="link external">&raquo;&nbsp;PHP 4.2.0</a>,
        this directive defaults to <em class="emphasis">off</em>.
       </p>
       <p class="para">
        Please read the security chapter on
        <a href="security.globals.php" class="link">Using register_globals</a>
        for related information.
       </p>
       <p class="para">
        Please note that <code class="systemitem systemitem">register_globals</code>
        cannot be set at runtime (<span class="function"><a href="function.ini-set.php" class="function">ini_set()</a></span>). Although, you can
        use <var class="filename">.htaccess</var> if your host allows it as described
        above. An example <var class="filename">.htaccess</var> entry:
        <strong class="userinput"><code>php_flag register_globals off</code></strong>.
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         <code class="systemitem systemitem">register_globals</code> is affected
         by the <a href="ini.core.php#ini.variables-order" class="link">variables_order</a>
         directive.
        </p>
       </p></blockquote>
       <div class="warning"><strong class="warning">Warning</strong><p class="simpara">This feature has been
<em class="emphasis">DEPRECATED</em> as of PHP 5.3.0 and <em class="emphasis">REMOVED</em>
as of PHP 5.4.0.</p></div>
      </dd>

     
     
     
      <dt id="ini.register-argc-argv">
       <code class="parameter">register_argc_argv</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <span class="simpara">
        Tells PHP whether to declare the argv &amp; argc variables
        (that would contain the GET information).
       </span>
       <span class="simpara">
        See also <a href="features.commandline.php" class="link">command line</a>.
       </span>
      </dd>

     
     
     
      <dt id="ini.register-long-arrays">
       <code class="parameter">register_long_arrays</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <span class="simpara">
        Tells PHP whether or not to register the deprecated long
        <var class="varname"><var class="varname">$HTTP_*_VARS</var></var> type
        <a href="language.variables.predefined.php" class="link">predefined
         variables</a>.  When On (default), long predefined PHP
        variables like <var class="varname"><var class="varname">$HTTP_GET_VARS</var></var> will be defined.
        If you&#039;re not using them, it&#039;s recommended to turn them off,
        for performance reasons.  Instead, use the superglobal arrays,
        like <var class="varname"><var class="varname"><a href="reserved.variables.get.php" class="classname">$_GET</a></var></var>.
       </span>
       <span class="simpara">
        This directive became available in PHP 5.0.0.
       </span>
       <div class="warning"><strong class="warning">Warning</strong><p class="simpara">This feature has been
<em class="emphasis">DEPRECATED</em> as of PHP 5.3.0 and <em class="emphasis">REMOVED</em>
as of PHP 5.4.0.</p></div>
      </dd>

     
     
     
      <dt id="ini.enable-post-data-reading">
       <code class="parameter">enable_post_data_reading</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <span class="simpara">
        Disabling this option causes <var class="varname"><var class="varname"><a href="reserved.variables.post.php" class="classname">$_POST</a></var></var> and
        <var class="varname"><var class="varname"><a href="reserved.variables.files.php" class="classname">$_FILES</a></var></var> <em class="emphasis">not</em> to be populated.
        The only way to read postdata will then be through the
        <a href="wrappers.php.php" class="link">php://input</a> stream wrapper.
        This can be useful to proxy requests or to process
        the POST data in a memory efficient fashion.
       </span>
      </dd>

     

     
      <dt id="ini.post-max-size">
       <code class="parameter">post_max_size</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <span class="simpara">
        Sets max size of post data allowed. This setting also affects
        file upload. To upload large files, this value must be larger
        than <a href="ini.core.php#ini.upload-max-filesize" class="link">upload_max_filesize</a>.
       </span>
       <span class="simpara">
        Generally speaking,
        <a href="ini.core.php#ini.memory-limit" class="link">memory_limit</a> should be
        larger than <code class="parameter">post_max_size</code>.
       </span>
       
       <span class="simpara">When an <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span> is used, the
value is measured in bytes. Shorthand notation, as described
in <a href="faq.using.php#faq.using.shorthandbytes" class="link">this FAQ</a>, may also be used.
</span>
       
       <span class="simpara">
        If the size of post data is greater than post_max_size, the
        <var class="varname"><var class="varname"><a href="reserved.variables.post.php" class="classname">$_POST</a></var></var> and <var class="varname"><var class="varname"><a href="reserved.variables.files.php" class="classname">$_FILES</a></var></var>
        <a href="language.variables.superglobals.php" class="link">superglobals</a>
        are empty. This can be tracked in various ways, e.g. by passing the
        <var class="varname"><var class="varname"><a href="reserved.variables.get.php" class="classname">$_GET</a></var></var> variable to the script processing the data,
        i.e. <em>&lt;form action=&quot;edit.php?processed=1&quot;&gt;</em>,
        and then checking if <var class="varname"><var class="varname"><a href="reserved.variables.get.php" class="classname">$_GET['processed']</a></var></var> is set.
       </span>
       <p class="para">
        <blockquote class="note"><p><strong class="note">Note</strong>: 
         <p class="para">
          PHP allows shortcuts for byte values, including K (kilo), M (mega) 
          and G (giga). PHP will do the conversions automatically if you 
          use any of these. Be careful not to exceed the 32 bit signed integer 
          limit (if you&#039;re using 32bit versions) as it will cause your script 
          to fail.
         </p>
        </p></blockquote>
       </p>
       <p class="para">
        <table class="doctable table">
         <caption><strong>Changelog for <em>post_max_size</em></strong></caption>
         
          <thead>
           <tr>
            <th>Version</th>
            <th>Description</th>
           </tr>

          </thead>

          <tbody class="tbody">
           <tr>
            <td>5.3.4</td>
            <td>
             <code class="parameter">post_max_size</code> = 0 will not disable the limit when the content
             type is application/x-www-form-urlencoded or is not registered with PHP.
            </td>
           </tr>

           <tr>
            <td>5.3.2 , 5.2.12</td>
            <td>
             Allow unlimited post size by setting <code class="parameter">post_max_size</code> to 0.
            </td>
           </tr>

          </tbody>
         
        </table>

       </p>
      </dd>

     

     
      <dt id="ini.auto-prepend-file">
       <code class="parameter">auto_prepend_file</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Specifies the name of a file that is automatically parsed
        before the main file.  The file is included as if it was
        called with the <span class="function"><a href="function.require.php" class="function">require</a></span> function, so
        <a href="ini.core.php#ini.include-path" class="link">include_path</a> is used.</p>
       <p class="para">
        The special value <em>none</em>
        disables auto-prepending.
       </p>
      </dd>

     
     
     
      <dt id="ini.auto-append-file">
       <code class="parameter">auto_append_file</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Specifies the name of a file that is automatically parsed
        after the main file.  The file is included as if it was
        called with the <span class="function"><a href="function.require.php" class="function">require</a></span> function, so
        <a href="ini.core.php#ini.include-path" class="link">include_path</a> is used.</p>
       <p class="para">
        The special value <em>none</em>
        disables auto-appending.
        <blockquote class="note"><p><strong class="note">Note</strong>: 
         <span class="simpara">
          If the script is terminated with <span class="function"><a href="function.exit.php" class="function">exit()</a></span>,
          auto-append will <em class="emphasis">not</em> occur.</span>
        </p></blockquote>
       </p>
      </dd>

     
     
     
      <dt id="ini.default-mimetype">
       <code class="parameter">default_mimetype</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        By default, PHP will output a media type using the Content-Type header.
        To disable this, simply set it to be empty.
       </p>
       <p class="para">
        PHP&#039;s built-in default media type is set to text/html.
       </p>
      </dd>

     
     
     
      <dt id="ini.default-charset">
       <code class="parameter">default_charset</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        In PHP 5.6 onwards, &quot;UTF-8&quot; is the default value and its value is used
        as the default character encoding for
        <span class="function"><a href="function.htmlentities.php" class="function">htmlentities()</a></span>,
        <span class="function"><a href="function.html-entity-decode.php" class="function">html_entity_decode()</a></span> and
        <span class="function"><a href="function.htmlspecialchars.php" class="function">htmlspecialchars()</a></span> if the
        <code class="parameter">encoding</code> parameter is omitted. The value of
        <code class="parameter">default_charset</code> will also be used to set the
        default character set for <a href="book.iconv.php" class="link">iconv</a>
        functions if the
        <a href="iconv.configuration.php#ini.iconv.input-encoding" class="link"><code class="parameter">iconv.input_encoding</code></a>,
        <a href="iconv.configuration.php#ini.iconv.output-encoding" class="link"><code class="parameter">iconv.output_encoding</code></a> and
        <a href="iconv.configuration.php#ini.iconv.internal-encoding" class="link"><code class="parameter">iconv.internal_encoding</code></a>
        configuration options are unset, and for
        <a href="book.mbstring.php" class="link">mbstring</a> functions if the
        <a href="mbstring.configuration.php#ini.mbstring.http-input" class="link"><code class="parameter">mbstring.http_input</code></a>
        <a href="mbstring.configuration.php#ini.mbstring.http-output" class="link"><code class="parameter">mbstring.http_output</code></a>
        <a href="mbstring.configuration.php#ini.mbstring.internal-encoding" class="link"><code class="parameter">mbstring.internal_encoding</code></a>
        configuration option is unset.
       </p>
       <p class="para">
        All versions of PHP will use this value as the charset within the
        default Content-Type header sent by PHP if the header isn&#039;t overridden
        by a call to <span class="function"><a href="function.header.php" class="function">header()</a></span>.
       </p>
       <p class="para">
        Setting <code class="parameter">default_charset</code> to an empty value is
        not recommended.
       </p>
      </dd>

     
     
     
      <dt id="ini.input-encoding">
       <code class="parameter">input_encoding</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Available from PHP 5.6.0. This setting is used for multibyte modules
        such as mbstring and iconv. Default is empty.
       </p>
      </dd>

     
     
     
      <dt id="ini.output-encoding">
       <code class="parameter">output_encoding</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Available from PHP 5.6.0. This setting is used for multibyte modules
        such as mbstring and iconv. Default is empty.
       </p>
      </dd>

     
      
     
      <dt id="ini.internal-encoding">
       <code class="parameter">internal_encoding</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Available from PHP 5.6.0. This setting is used for multibyte modules
        such as mbstring and iconv. Default is empty. If empty,
        <a href="ini.core.php#ini.default-charset" class="link">default_charset</a> is used.
       </p>
      </dd>

     
      
     
      <dt id="ini.always-populate-raw-post-data">
       <code class="parameter">always_populate_raw_post_data</code>
       <span class="type"><a href="language.pseudo-types.php#language.types.mixed" class="type mixed">mixed</a></span>
      </dt>

      <dd>

       <div class="warning"><strong class="warning">Warning</strong><p class="simpara">This feature was
<em class="emphasis">DEPRECATED</em> in PHP 5.6.0, and
<em class="emphasis">REMOVED</em> as of PHP 7.0.0.</p></div>
       <p class="para">
        If set to <strong><code>TRUE</code></strong>, PHP will always populate the
        <var class="varname"><var class="varname"><a href="reserved.variables.httprawpostdata.php" class="classname">$HTTP_RAW_POST_DATA</a></var></var> containing the raw POST data.
        Otherwise, the variable is populated only when the MIME type of the
        data is unrecognised.
       </p>
       <p class="para">
        The preferred method for accessing raw POST data is
        <a href="wrappers.php.php" class="link">php://input</a>, and
        <var class="varname"><var class="varname"><a href="reserved.variables.httprawpostdata.php" class="classname">$HTTP_RAW_POST_DATA</a></var></var> is deprecated in PHP 5.6.0
        onwards. Setting <code class="parameter">always_populate_raw_post_data</code>
        to <em>-1</em> will opt into the new behaviour that will be
        implemented in a future version of PHP, in which
        <var class="varname"><var class="varname"><a href="reserved.variables.httprawpostdata.php" class="classname">$HTTP_RAW_POST_DATA</a></var></var> is never defined.
       </p>
       <p class="para">
        Regardless of the setting, <var class="varname"><var class="varname"><a href="reserved.variables.httprawpostdata.php" class="classname">$HTTP_RAW_POST_DATA</a></var></var> is
        not available with <em>enctype=&quot;multipart/form-data&quot;</em>.
       </p>
      </dd>

     
     
    </dl>

   </p>
   <p class="para">
    See also: <a href="info.configuration.php#ini.magic-quotes-gpc" class="link">magic_quotes_gpc</a>,
    <a href="info.configuration.php#ini.magic-quotes-runtime" class="link">magic_quotes_runtime</a>,
    and
    <a href="sybase.configuration.php#ini.magic-quotes-sybase" class="link">magic_quotes_sybase</a>.
   </p>
  </div>
  
  <div class="section" id="ini.sect.path-directory">
   <h2 class="title">Paths and Directories</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>Paths and Directories Configuration Options</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.include-path" class="link">include_path</a></td>
        <td>&quot;.;/path/to/php/pear&quot;</td>
        <td>PHP_INI_ALL</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.open-basedir" class="link">open_basedir</a></td>
        <td>NULL</td>
        <td>PHP_INI_ALL</td>
        <td>PHP_INI_SYSTEM in PHP &lt; 5.3.0</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.doc-root" class="link">doc_root</a></td>
        <td>NULL</td>
        <td>PHP_INI_SYSTEM</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.user-dir" class="link">user_dir</a></td>
        <td>NULL</td>
        <td>PHP_INI_SYSTEM</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.user-ini.cache-ttl" class="link">user_ini.cache_ttl</a></td>
        <td>&quot;300&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.user-ini.filename" class="link">user_ini.filename</a></td>
        <td>&quot;.user.ini&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.extension-dir" class="link">extension_dir</a></td>
        <td>&quot;/path/to/php&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.extension" class="link">extension</a></td>
        <td>NULL</td>
        <td><var class="filename">php.ini</var> only</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend-extension" class="link">zend_extension</a></td>
        <td>NULL</td>
        <td><var class="filename">php.ini</var> only</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend-extension-debug" class="link">zend_extension_debug</a></td>
        <td>NULL</td>
        <td><var class="filename">php.ini</var> only</td>
        <td>Available before PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend-extension-debug-ts" class="link">zend_extension_debug_ts</a></td>
        <td>NULL</td>
        <td><var class="filename">php.ini</var> only</td>
        <td>Available before PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.zend-extension-ts" class="link">zend_extension_ts</a></td>
        <td>NULL</td>
        <td><var class="filename">php.ini</var> only</td>
        <td>Available before PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.cgi.check-shebang-line" class="link">cgi.check_shebang_line</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.2.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.cgi.discard-path" class="link">cgi.discard_path</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.cgi.fix-pathinfo" class="link">cgi.fix_pathinfo</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>PHP_INI_ALL prior to PHP 5.2.1.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.cgi.force-redirect" class="link">cgi.force_redirect</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>PHP_INI_ALL prior to PHP 5.2.1.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.cgi.nph" class="link">cgi.nph</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.3.0.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.cgi.redirect-status-env" class="link">cgi.redirect_status_env</a></td>
        <td>NULL</td>
        <td>PHP_INI_SYSTEM</td>
        <td>PHP_INI_ALL prior to PHP 5.2.1.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.cgi.rfc2616-headers" class="link">cgi.rfc2616_headers</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_ALL</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.fastcgi.impersonate" class="link">fastcgi.impersonate</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>PHP_INI_ALL prior to PHP 5.2.1.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.fastcgi.logging" class="link">fastcgi.logging</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>PHP_INI_ALL prior to PHP 5.2.1.</td>
       </tr>

      </tbody>
     
    </table>

   </p>
   
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   
   <p class="para">
    <dl>

     
      <dt id="ini.include-path">
       <code class="parameter">include_path</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Specifies a list of directories where the
        <span class="function"><a href="function.require.php" class="function">require</a></span>, <span class="function"><a href="function.include.php" class="function">include</a></span>,
        <span class="function"><a href="function.fopen.php" class="function">fopen()</a></span>, <span class="function"><a href="function.file.php" class="function">file()</a></span>,
        <span class="function"><a href="function.readfile.php" class="function">readfile()</a></span> and <span class="function"><a href="function.file-get-contents.php" class="function">file_get_contents()</a></span>
        functions look for files.  The format is like the system&#039;s
        <var class="envar">PATH</var> environment variable: a list of directories
        separated with a colon in Unix or semicolon in Windows.
       </p>
       <p class="para">
        PHP considers each entry in the include path separately when looking for
        files to include. It will check the first path, and if it doesn&#039;t find
        it, check the next path, until it either locates the included file or
        returns with a 
        <a href="" class="link">warning</a>
        or an <a href="" class="link">error</a>. 
        You may modify or set your include path at runtime using
        <span class="function"><a href="function.set-include-path.php" class="function">set_include_path()</a></span>.
       </p>
       <p class="para">
        <div class="example" id="example-6902">
         <p><strong>Example #1 Unix include_path</strong></p>
         <div class="example-contents">
<div class="php.inicode"><pre class="php.inicode">include_path=&quot;.:/php/includes&quot;</pre>
</div>
         </div>

        </div>
       </p>
       <p class="para">
        <div class="example" id="example-6903">
         <p><strong>Example #2 Windows include_path</strong></p>
         <div class="example-contents">
<div class="php.inicode"><pre class="php.inicode">include_path=&quot;.;c:\php\includes&quot;</pre>
</div>
         </div>

        </div>
       </p>
       <p class="para">
        Using a <em>.</em> in the include path allows for
        relative includes as it means the current directory.  However,
        it is more efficient to explicitly use <em>include
        &#039;./file&#039;</em> than having PHP always check the current
        directory for every include.
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         <em>ENV</em> variables are also accessible in .ini files.
         As such it is possible to reference the home directory using
         <em>${LOGIN}</em> and <em>${USER}</em>.
        </p>
        <p class="para">
         Environment variables may vary between Server APIs as those environments
         may be different.
        </p>       
       </p></blockquote>
       <p class="para">
        <div class="example" id="example-6904">
         <p><strong>Example #3 Unix include_path using ${USER} env variable</strong></p>
         <div class="example-contents">
<div class="php.inicode"><pre class="php.inicode">include_path = &quot;.:${USER}/pear/php&quot;</pre>
</div>
         </div>

        </div>
       </p>
      </dd>

     
     
     
      <dt id="ini.open-basedir">
       <code class="parameter">open_basedir</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Limit the files that can be accessed by PHP to the specified
        directory-tree, including the file itself.  This directive 
        is <em class="emphasis">NOT</em> affected by whether Safe Mode is 
        turned On or Off.
       </p>
       <p class="para">
        When a script tries to access the filesystem, for example using 
        <span class="function"><a href="function.include.php" class="function">include</a></span>, or <span class="function"><a href="function.fopen.php" class="function">fopen()</a></span>, the location of the file 
        is checked.
        When the file is outside the specified directory-tree, PHP will refuse to access it. 
        All symbolic links are resolved, so it&#039;s not possible to avoid this restriction
        with a symlink. If the file doesn&#039;t exist then the symlink couldn&#039;t be
        resolved and the filename is compared to (a resolved) <strong class="option unknown">open_basedir</strong>
.
       </p>
       <p class="para">
        <strong class="option unknown">open_basedir</strong>
 can affect more than just filesystem functions; for example 
        if <em>MySQL</em> is configured to use <em>mysqlnd</em> drivers,
        <em>LOAD DATA INFILE</em> will be affected by <strong class="option unknown">open_basedir</strong>
.
        Much of the extended functionality of PHP uses <em>open_basedir</em> in this way.
       </p>
       <p class="para">
        The special value <code class="systemitem systemitem">.</code>
        indicates that the working directory of the script will be used as the
        base-directory. This is, however, a little dangerous as the working directory
        of the script can easily be changed with <span class="function"><a href="function.chdir.php" class="function">chdir()</a></span>.
       </p>
       <p class="para">
        In <var class="filename">httpd.conf</var>, <strong class="option unknown">open_basedir</strong>
 can be turned off
        (e.g. for some virtual hosts)
        <a href="configuration.changes.php#configuration.changes.apache" class="link">the same way</a> as
        any other configuration directive with &quot;<em>php_admin_value open_basedir
        none</em>&quot;.
       </p>
       <p class="para">
        Under Windows, separate the directories with a semicolon. On all
        other systems, separate the directories with a colon. As an Apache
        module, <strong class="option unknown">open_basedir</strong>
 paths from parent directories are now
        automatically inherited.
       </p>
       <p class="para">
        The restriction specified with <strong class="option unknown">open_basedir</strong>
 is a
        directory name since PHP 5.2.16 and 5.3.4. Previous versions used it
        as a prefix. This means that &quot;<em>open_basedir
        = /dir/incl</em>&quot; also allowed access to &quot;<em>/dir/include</em>&quot; and
        &quot;<em>/dir/incls</em>&quot; if they exist. When you want to restrict access
        to only the specified directory, end with a slash. For example:
        <em>open_basedir = /dir/incl/</em>
       </p>
       <p class="para">
        The default is to allow all files to be opened.
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         As of PHP 5.3.0 open_basedir can be tightened at run-time. This means
         that if open_basedir is set to <em>/www/</em> in <var class="filename">php.ini</var>
         a script can tighten the configuration to
         <em>/www/tmp/</em> at run-time with
         <span class="function"><a href="function.ini-set.php" class="function">ini_set()</a></span>. When listing several directories, you
         can use the <strong><code>PATH_SEPARATOR</code></strong> constant as a separator
         regardless of the operating system.
        </p>
       </p></blockquote>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         Using open_basedir will set <a href="ini.core.php#ini.realpath-cache-size" class="link">realpath_cache_size</a>
         to <em>0</em> and thus <em class="emphasis">disable</em> the realpath cache.
        </p>
       </p></blockquote>
      </dd>

     
     
     
      <dt id="ini.doc-root">
       <code class="parameter">doc_root</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        PHP&#039;s &quot;root directory&quot; on the server. Only used if
        non-empty. If PHP is configured with <a href="ini.sect.safe-mode.php#ini.safe-mode" class="link">safe mode</a>, no files outside
        this directory are served.
        If PHP was not compiled with FORCE_REDIRECT, you <em class="emphasis">should
        </em> set doc_root if you are running PHP as a CGI under any web
        server (other than IIS). The alternative is to use the
        <a href="ini.core.php#ini.cgi.force-redirect" class="link">
         cgi.force_redirect</a> configuration below.
       </p>
      </dd>

     
     
     
      <dt id="ini.user-ini.cache-ttl">
       <code class="parameter">user_ini.cache_ttl</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <p class="para">
       </p>
      </dd>

     
     
     
      <dt id="ini.user-ini.filename">
       <code class="parameter">user_ini.filename</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
       </p>
      </dd>

     
     
     
      <dt id="ini.user-dir">
       <code class="parameter">user_dir</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        The base name of the directory used on a user&#039;s home directory for PHP
        files, for example <var class="filename">public_html
        </var>.
       </p>
      </dd>

     
     
     
      <dt id="ini.extension-dir">
       <code class="parameter">extension_dir</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        In what directory PHP should look for dynamically loadable
        extensions. See also: <a href="info.configuration.php#ini.enable-dl" class="link">enable_dl</a>,
        and <span class="function"><a href="function.dl.php" class="function">dl()</a></span>.
       </p>
      </dd>

     
     
     
      <dt id="ini.extension">
       <code class="parameter">extension</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Which dynamically loadable extensions to load when PHP starts up.
       </p>
      </dd>

     
     
     
      <dt id="ini.zend-extension">
       <code class="parameter">zend_extension</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Name of dynamically loadable Zend extension (for example
        <a href="book.apd.php" class="link">APD</a>) to load when PHP starts up.
       </p>
      </dd>

     
     
     
      <dt id="ini.zend-extension-debug">
       <code class="parameter">zend_extension_debug</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Variant of <a href="ini.core.php#ini.zend-extension" class="link">zend_extension</a>
        for extensions compiled with debug info prior to PHP 5.3.0.
       </p>
      </dd>

     
     
     
      <dt id="ini.zend-extension-debug-ts">
       <code class="parameter">zend_extension_debug_ts</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Variant of <a href="ini.core.php#ini.zend-extension" class="link">zend_extension</a>
        for extensions compiled with debug info and thread safety prior to PHP
        5.3.0.
       </p>
      </dd>

     
     
     
      <dt id="ini.zend-extension-ts">
       <code class="parameter">zend_extension_ts</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        Variant of <a href="ini.core.php#ini.zend-extension" class="link">zend_extension</a>
        for extensions compiled with thread safety prior to PHP 5.3.0.
       </p>
      </dd>

     
     
     
      <dt id="ini.cgi.check-shebang-line">
       <code class="parameter">cgi.check_shebang_line</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Controls whether <acronym title="Common Gateway Interface">CGI</acronym> PHP checks for line starting
        with <em>#!</em> (shebang) at the top of the running script.
        This line might be needed if the script support running both as
        stand-alone script and via PHP <acronym title="Common Gateway Interface">CGI</acronym>. PHP in
        <acronym title="Common Gateway Interface">CGI</acronym> mode skips this line and ignores its content if
        this directive is turned on.
       </p>
      </dd>

     
     
     
      <dt id="ini.cgi.discard-path">
       <code class="parameter">cgi.discard_path</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        If this is enabled, the PHP CGI binary can safely be placed outside of
        the web tree and people will not be able to circumvent .htaccess security.
       </p>
      </dd>

     
     
     
      <dt id="ini.cgi.fix-pathinfo">
       <code class="parameter">cgi.fix_pathinfo</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Provides <em class="emphasis">real</em> <em>PATH_INFO</em>/
        <em>PATH_TRANSLATED</em> support for <acronym title="Common Gateway Interface">CGI</acronym>.
        PHP&#039;s previous behaviour was to set <em>PATH_TRANSLATED</em>
        to <em>SCRIPT_FILENAME</em>, and to not grok what <em>
        PATH_INFO</em> is. For more information on
        <em>PATH_INFO</em>, see the <acronym title="Common Gateway Interface">CGI</acronym> specs.
        Setting this to <em>1</em> will cause PHP
        <acronym title="Common Gateway Interface">CGI</acronym> to fix its paths to conform to the spec. A
        setting of zero causes PHP to behave as before. It is turned on by
        default. You should fix your scripts to use
        <em>SCRIPT_FILENAME</em> rather than
        <em>PATH_TRANSLATED</em>.
       </p>
      </dd>

     
     
     
      <dt id="ini.cgi.force-redirect">
       <code class="parameter">cgi.force_redirect</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        cgi.force_redirect is necessary to provide security running PHP as a
        <acronym title="Common Gateway Interface">CGI</acronym> under most web servers. Left undefined, PHP
        turns this on by default. You can turn it off <em class="emphasis">at your own
        risk</em>.
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         Windows Users: When using IIS this option <em class="emphasis">must</em>
         be turned off. For OmniHTTPD or Xitami the same applies.
        </p>
       </p></blockquote>
      </dd>

     
     
     
      <dt id="ini.cgi.nph">
       <code class="parameter">cgi.nph</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        If cgi.nph is enabled it will force cgi to always sent Status: 200 with
        every request.
        </p>
      </dd>

     
     
     
      <dt id="ini.cgi.redirect-status-env">
       <code class="parameter">cgi.redirect_status_env</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        If cgi.force_redirect is turned on, and you are not running under
        Apache or Netscape (iPlanet) web servers, you <em class="emphasis">may</em>
        need to set an environment variable name that PHP will look for to
        know it is OK to continue execution.
       </p>
       <blockquote class="note"><p><strong class="note">Note</strong>: 
        <p class="para">
         Setting this variable <em class="emphasis">may</em> cause security issues,
         <em class="emphasis">know what you are doing first</em>.
        </p>
       </p></blockquote>
      </dd>

     
     
     
      <dt id="ini.cgi.rfc2616-headers">
       <code class="parameter">cgi.rfc2616_headers</code>
       <span class="type"><a href="language.types.integer.php" class="type int">int</a></span>
      </dt>

      <dd>

      <p class="para">
        Tells PHP what type of headers to use when sending HTTP response
        code. If it&#039;s set to 0, PHP sends a <a href="http://www.faqs.org/rfcs/rfc3875" class="link external">&raquo;&nbsp;RFC 3875</a> 
        &quot;Status:&quot; header that is supported by Apache and other web servers. When this option 
        is set to 1, PHP will send <a href="http://www.faqs.org/rfcs/rfc2616" class="link external">&raquo;&nbsp;RFC 2616</a> compliant
        headers.  
       </p>
       <p class="para">
        If this option is enabled, and you are running PHP in a CGI environment (e.g. PHP-FPM)
        you should not use standard RFC 2616 style HTTP status response headers, you should 
        instead use their RFC 3875 equivalent e.g. instead of header(&quot;HTTP/1.0 404 Not found&quot;); 
        you should use header(&quot;Status: 404 Not Found&quot;);
       </p>
       <p class="para">
        Leave it set to 0 unless you know what you&#039;re doing.
       </p>
      </dd>

     
     
     
      <dt id="ini.fastcgi.impersonate">
       <code class="parameter">fastcgi.impersonate</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        FastCGI under IIS (on WINNT based OS) supports the ability to impersonate
        security tokens of the calling client. This allows IIS to define the
        security context that the request runs under. mod_fastcgi under Apache
        does not currently support this feature (03/17/2002)
        Set to 1 if running under IIS. Default is zero.
       </p>
      </dd>

     
     
     
      <dt id="ini.fastcgi.logging">
       <code class="parameter">fastcgi.logging</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Turns on SAPI logging when using FastCGI. Default is 
        to enable logging.
       </p>
      </dd>

     
     
    </dl>

   </p>
  </div>
  
  <div class="section" id="ini.sect.file-uploads">
   <h2 class="title">File Uploads</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>File Uploads Configuration Options</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.file-uploads" class="link">file_uploads</a></td>
        <td>&quot;1&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.upload-tmp-dir" class="link">upload_tmp_dir</a></td>
        <td>NULL</td>
        <td>PHP_INI_SYSTEM</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="info.configuration.php#ini.max-input-nesting-level" class="link">max_input_nesting_level</a></td>
        <td>64</td>
        <td>PHP_INI_PERDIR</td>
        <td>Available since PHP 5.3.9.</td>
       </tr>

       <tr>
        <td><a href="info.configuration.php#ini.max-input-vars" class="link">max_input_vars</a></td>
        <td>1000</td>
        <td>PHP_INI_PERDIR</td>
        <td>Available since PHP 5.3.9.</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.upload-max-filesize" class="link">upload_max_filesize</a></td>
        <td>&quot;2M&quot;</td>
        <td>PHP_INI_PERDIR</td>
        <td class="empty">&nbsp;</td>
       </tr>

       <tr>
        <td><a href="ini.core.php#ini.max-file-uploads" class="link">max_file_uploads</a></td>
        <td>20</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Available since PHP 5.2.12.</td>
       </tr>

      </tbody>
     
    </table>

   </p>
   
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   
   <p class="para">
    <dl>

     
      <dt id="ini.file-uploads">
       <code class="parameter">file_uploads</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        Whether or not to allow HTTP
        <a href="features.file-upload.php" class="link">file uploads</a>. See also the
        <a href="ini.core.php#ini.upload-max-filesize" class="link">upload_max_filesize</a>,
        <a href="ini.core.php#ini.upload-tmp-dir" class="link">upload_tmp_dir</a>, and
        <a href="ini.core.php#ini.post-max-size" class="link">post_max_size</a> directives.
       </p>
      </dd>

     
     
     
      <dt id="ini.upload-tmp-dir">
       <code class="parameter">upload_tmp_dir</code>
       <span class="type"><a href="language.types.string.php" class="type string">string</a></span>
      </dt>

      <dd>

       <p class="para">
        The temporary directory used for storing files when doing
        file upload. Must be writable by whatever user PHP
        is running as. If not specified PHP will use the system&#039;s default.
       </p>
       <p class="para">
        If the directory specified here is not writable, PHP falls back to 
        the system default temporary directory. If 
        <a href="ini.core.php#ini.open-basedir" class="link">open_basedir</a> is on, then 
        the system default directory must be allowed for an upload to 
        succeed.
       </p>
      </dd>

     
     
     
      <dt id="ini.upload-max-filesize">
       <code class="parameter">upload_max_filesize</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <p class="para">
        The maximum size of an uploaded file.
       </p>
       
       <span class="simpara">When an <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span> is used, the
value is measured in bytes. Shorthand notation, as described
in <a href="faq.using.php#faq.using.shorthandbytes" class="link">this FAQ</a>, may also be used.
</span>
       
      </dd>

     
     
     
      <dt id="ini.max-file-uploads">
       <code class="parameter">max_file_uploads</code>
       <span class="type"><a href="language.types.integer.php" class="type integer">integer</a></span>
      </dt>

      <dd>

       <p class="para">
        The maximum number of files allowed to be uploaded simultaneously.
        Starting with PHP 5.3.4, upload fields left blank on submission do not
        count towards this limit.
       </p>
      </dd>

     
    </dl>

   </p>
  </div>
  
  <div class="section" id="ini.sect.sql-general">
   <h2 class="title">General SQL</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>General SQL Configuration Options</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.sql.safe-mode" class="link">sql.safe_mode</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_SYSTEM</td>
        <td>Removed in PHP 7.2.0</td>
       </tr>

      </tbody>
     
    </table>

   </p>
   
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   
   <p class="para">
    <dl>

     
      <dt id="ini.sql.safe-mode">
       <code class="parameter">sql.safe_mode</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        If turned on, database connection functions that specify default values
        will use those values in place of any user-supplied arguments. For details
        on the default values, see the documentation for the relevant connection
        functions.
       </p>
       <div class="warning"><strong class="warning">Warning</strong>
        <p class="simpara">
         This feature has been <em class="emphasis">REMOVED</em> as of PHP 7.2.0.
        </p>
       </div>
      </dd>

     
    </dl>

   </p>
  </div>
  
  <div class="section" id="ini.sect.windows">
   <h2 class="title">Windows Specific</h2>
   <p class="para">
    <table class="doctable table">
     <caption><strong>Windows Specific Configuration Options</strong></caption>
     
      <thead>
       <tr>
        <th>Name</th>
        <th>Default</th>
        <th>Changeable</th>
        <th>Changelog</th>
       </tr>

      </thead>

      <tbody class="tbody">
       <tr>
        <td><a href="ini.core.php#ini.windows-show-crt-warning" class="link">windows.show_crt_warning</a></td>
        <td>&quot;0&quot;</td>
        <td>PHP_INI_ALL</td>
        <td>Available since PHP 5.4.0.</td>
       </tr>

      </tbody>
     
    </table>

   </p>
   
   <p class="para">Here&#039;s a short explanation of
the configuration directives.</p>
   
   <p class="para">
    <dl>

     
      <dt id="ini.windows-show-crt-warning">
       <code class="parameter">windows.show_crt_warning</code>
       <span class="type"><a href="language.types.boolean.php" class="type boolean">boolean</a></span>
      </dt>

      <dd>

       <p class="para">
        This directive shows the Windows CRT warnings when enabled. These
        warnings were displayed by default until PHP 5.4.0.
       </p>
      </dd>

     
    </dl>

   </p>
  </div>
  
 </div>
<section id="usernotes">
 <div class="head">
  <span class="action"><a href="/manual/add-note.php?sect=ini.core&amp;redirect=https://www.php.net/manual/en/ini.core.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></span>
  <h3 class="title">User Contributed Notes <span class="count">16 notes</span></h3>
 </div><div id="allnotes">
  <div class="note" id="56431">  <div class="votes">
    <div id="Vu56431">
    <a href="/manual/vote-note.php?id=56431&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd56431">
    <a href="/manual/vote-note.php?id=56431&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V56431" title="64% like this...">
    24
    </div>
  </div>
  <a href="#56431" class="name">
  <strong class="user"><em>csg at DEL_THISdiatom dot de</em></strong></a><a class="genanchor" href="#56431"> &para;</a><div class="date" title="2005-09-02 02:55"><strong>14 years ago</strong></div>
  <div class="text" id="Hcom56431">
<div class="phpcode"><code><span class="html">
Starting with PHP 4.4.0 (at least PHP version 4.3.10 did have old, documented behaviour) interpretation of value of "session.save_path" did change in conjunction with "save_mode" and "open_basedir" enabled.<br /><br />Documented ( <a href="http://de.php.net/manual/en/ref.session.php#ini.session.save-path" rel="nofollow" target="_blank">http://de.php.net/manual/en/ref.session.php#ini.session.save-path</a> ):<br />&nbsp; Values of "session.save_path" should or may be&nbsp; **without**&nbsp; ending slash.<br />&nbsp; For instance:<br /><span class="default">&lt;?php<br />&nbsp; </span><span class="comment">// Valid only&nbsp; *before* PHP 4.4.0:<br />&nbsp; </span><span class="default">ini_set</span><span class="keyword">( </span><span class="string">"session.save_path"</span><span class="keyword">, </span><span class="string">"/var/httpd/kunde/phptmp" </span><span class="keyword">);<br /></span><span class="default">?&gt;</span> will mean:<br />&nbsp; The directory "/var/httpd/kunde/phptmp/" will be used to write data and therefore must be writable by the web server.<br /><br />Starting with PHP 4.4.0 the server complains that "/var/httpd/kunde/" is not writable.<br />Solution: Add an ending slash in call of ini_set (or probably whereever you set "session.save_path"), e.g.:<br /><span class="default">&lt;?php<br />&nbsp; </span><span class="comment">// Note the slash on ".....phptmp/":<br />&nbsp; </span><span class="default">ini_set</span><span class="keyword">( </span><span class="string">"session.save_path"</span><span class="keyword">, </span><span class="string">"/var/httpd/kunde/phptmp/" </span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />Hope, that does help someone.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="118942">  <div class="votes">
    <div id="Vu118942">
    <a href="/manual/vote-note.php?id=118942&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd118942">
    <a href="/manual/vote-note.php?id=118942&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V118942" title="54% like this...">
    4
    </div>
  </div>
  <a href="#118942" class="name">
  <strong class="user"><em>dougal at gunters dot org</em></strong></a><a class="genanchor" href="#118942"> &para;</a><div class="date" title="2016-03-03 05:11"><strong>3 years ago</strong></div>
  <div class="text" id="Hcom118942">
<div class="phpcode"><code><span class="html">
It appears that if you use both the 'include_path' directives and 'open_basedir', that file searches will hit the include path *first*, before local files. But if 'open_basedir' is not in use, then local files are found first. For example, suppose you have code in '/var/www/myfile.php' which does:<br /><br /><span class="default">&lt;?php<br />&nbsp; </span><span class="keyword">require_once(</span><span class="string">'config.php'</span><span class="keyword">);<br /></span><span class="default">?&gt;<br /></span><br />Further, assume that there is a local file '/var/www/config.php', and there is also a file '/var/local/php/config.php'.<br /><br />Next, if your php.ini has:<br /><br />&nbsp; include_path = /var/local/php/<br /><br />Normally, this would look for '/var/www/config.php' first, and if not found, then it would try '/var/local/php/config.php'.<br /><br />But if you also have this in php.ini:<br /><br />&nbsp; open_basedir = /var/www/:/var/local/php/<br /><br />Then the require would reverse the order of the search, and load '/var/local/php/config.php', even when the local 'config.php' file exists.<br /><br />Furthermore, if include_path contains directories not in open_basedir, you can end up with a fatal error. For example, change the directive to:<br /><br />&nbsp; open_basedir = /var/www/:/var/local/includes/php/<br /><br />Now the require will first find '/var/local/php/config.php' from the include_path, try to include it, but be unable to because of the open_basedir restrictions.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="101755">  <div class="votes">
    <div id="Vu101755">
    <a href="/manual/vote-note.php?id=101755&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd101755">
    <a href="/manual/vote-note.php?id=101755&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V101755" title="52% like this...">
    4
    </div>
  </div>
  <a href="#101755" class="name">
  <strong class="user"><em>rlammers at linuxmail dot org</em></strong></a><a class="genanchor" href="#101755"> &para;</a><div class="date" title="2011-01-09 04:23"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom101755">
<div class="phpcode"><code><span class="html">
This is a possible solution for a problem which seems to be a php-ini-problem but is not.<br /><br />If a $_POST is used with large fields e.g. textarea's with more than 120kb characters php returns a blank screen, even if the max_post_size is 8M.<br /><br />This problem may be caused by an apache-module SecFilter.<br /><br />Adding the following lines to the .htaccess solves the problem.<br />SecFilterEngine Off<br />SecFilterScanPOST Off<br /><br />I know this is not a php-issue, but i'm still posting it here since it looks like it is a php-problem and I did not find any sites or forums offering this solution.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="113729">  <div class="votes">
    <div id="Vu113729">
    <a href="/manual/vote-note.php?id=113729&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd113729">
    <a href="/manual/vote-note.php?id=113729&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V113729" title="50% like this...">
    1
    </div>
  </div>
  <a href="#113729" class="name">
  <strong class="user"><em>txyoji at yahoo dot com</em></strong></a><a class="genanchor" href="#113729"> &para;</a><div class="date" title="2013-11-21 08:24"><strong>6 years ago</strong></div>
  <div class="text" id="Hcom113729">
<div class="phpcode"><code><span class="html">
If you enable "open_basedir" option, it will disable the realpath_cache. This can be a significant performance hit.<br /><br /><a href="https://bugs.php.net/bug.php?id=53263" rel="nofollow" target="_blank">https://bugs.php.net/bug.php?id=53263</a></span>
</code></div>
  </div>
 </div>
  <div class="note" id="120054">  <div class="votes">
    <div id="Vu120054">
    <a href="/manual/vote-note.php?id=120054&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120054">
    <a href="/manual/vote-note.php?id=120054&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120054" title="50% like this...">
    0
    </div>
  </div>
  <a href="#120054" class="name">
  <strong class="user"><em>fernandobasso dot br at gmail dot com</em></strong></a><a class="genanchor" href="#120054"> &para;</a><div class="date" title="2016-10-17 08:06"><strong>3 years ago</strong></div>
  <div class="text" id="Hcom120054">
<div class="phpcode"><code><span class="html">
This might help in case someone happens to maintain old applications with a charset other than utf-8.<br /><br />According to the docs, you can override the default charset if you use `header()`.<br /><br />Suppose php.ini sets the default_charset to "UTF-8", but you need a legacy charset, like ISO-8859-1.<br /><br />Still,<br /><br /><span class="default">&lt;?php header</span><span class="keyword">(</span><span class="string">'Content-Type: text/html; Charset=ISO-8859-1'</span><span class="keyword">); </span><span class="default">?&gt;<br /></span><br />would not override the charset, just add it as well and the result<br />was a response header like (note the two charsets):<br /><br />&nbsp; &nbsp; Content-Type:"text/html; Charset=ISO-8859-1;charset=UTF-8"<br /><br />I found it strange the default one as `charset` with a lowercase `c`<br />as opposed to my custom charset with an uppercase `C`.<br /><br />What solved was to _override_ the charset using all lowercase letters<br />as well for the word “charset”:<br /><br /><span class="default">&lt;?php header</span><span class="keyword">(</span><span class="string">'content-type: text/html; charset=ISO-8859-1'</span><span class="keyword">); </span><span class="default">?&gt;<br /></span><br />Then, the double charset from the response headers disappeared, and only the single, custom charset remained.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="102853">  <div class="votes">
    <div id="Vu102853">
    <a href="/manual/vote-note.php?id=102853&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd102853">
    <a href="/manual/vote-note.php?id=102853&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V102853" title="48% like this...">
    -2
    </div>
  </div>
  <a href="#102853" class="name">
  <strong class="user"><em>AntonioK</em></strong></a><a class="genanchor" href="#102853"> &para;</a><div class="date" title="2011-03-10 05:29"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom102853">
<div class="phpcode"><code><span class="html">
Note that there is no way to disable eval() work by using disable_functions directive, because eval() is a language construct and not a function.<br /><br />Many people advise to disable such potentially-insecure functions like system(), exec(), passthru(), eval() and so on in php.ini when not running in safe mode, but eval() would still work even it listed in disable_functions.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="66801">  <div class="votes">
    <div id="Vu66801">
    <a href="/manual/vote-note.php?id=66801&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd66801">
    <a href="/manual/vote-note.php?id=66801&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V66801" title="48% like this...">
    -2
    </div>
  </div>
  <a href="#66801" class="name">
  <strong class="user"><em>leo at korfu dot cz</em></strong></a><a class="genanchor" href="#66801"> &para;</a><div class="date" title="2006-05-29 03:45"><strong>13 years ago</strong></div>
  <div class="text" id="Hcom66801">
<div class="phpcode"><code><span class="html">
"If the size of post data is greater than post_max_size..."<br /><br />It seems that a more elegant way is comparison between post_max_size and $_SERVER['CONTENT_LENGTH']. Please note that the latter includes not only size of uploaded file plus post data but also multipart sequences. Leo</span>
</code></div>
  </div>
 </div>
  <div class="note" id="89768">  <div class="votes">
    <div id="Vu89768">
    <a href="/manual/vote-note.php?id=89768&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd89768">
    <a href="/manual/vote-note.php?id=89768&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V89768" title="47% like this...">
    -3
    </div>
  </div>
  <a href="#89768" class="name">
  <strong class="user"><em>mrok at mrok dot com</em></strong></a><a class="genanchor" href="#89768"> &para;</a><div class="date" title="2009-03-22 08:29"><strong>10 years ago</strong></div>
  <div class="text" id="Hcom89768">
<div class="phpcode"><code><span class="html">
Note that on some Unix systems (i.e. PHP 5.1.6 on Centos 5.2) include_path in php.ini should NOT be quoted.<br /><br />For example, instead of<br /><br /> include_path='.:/usr/share/php'<br /><br />use<br /><br /> include_path=.:/usr/share/php<br /><br />Using quotes does not cause any error message, but all of your require_once() directives will fail (indicating that file could not be opened) - unless full path to target file is provided.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="96143">  <div class="votes">
    <div id="Vu96143">
    <a href="/manual/vote-note.php?id=96143&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd96143">
    <a href="/manual/vote-note.php?id=96143&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V96143" title="46% like this...">
    -3
    </div>
  </div>
  <a href="#96143" class="name">
  <strong class="user"><em>amolitor at molitor-design dot com</em></strong></a><a class="genanchor" href="#96143"> &para;</a><div class="date" title="2010-02-10 03:23"><strong>9 years ago</strong></div>
  <div class="text" id="Hcom96143">
<div class="phpcode"><code><span class="html">
Amusingly, the include_path logically includes the current directory of the running file as the last entry all the time anyways, so part of the business about shoving "." into the include_path is spurious -- it's "there" on the end all the time, at least in the 5.2.12 source (see main/fopen_wrappers.c around line 503).<br /><br />This one had me goin' for a while.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="108489">  <div class="votes">
    <div id="Vu108489">
    <a href="/manual/vote-note.php?id=108489&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd108489">
    <a href="/manual/vote-note.php?id=108489&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V108489" title="42% like this...">
    -6
    </div>
  </div>
  <a href="#108489" class="name">
  <strong class="user"><em>iko at vision dot sk</em></strong></a><a class="genanchor" href="#108489"> &para;</a><div class="date" title="2012-05-01 08:49"><strong>7 years ago</strong></div>
  <div class="text" id="Hcom108489">
<div class="phpcode"><code><span class="html">
auto_globals_jit setting is also affecting $_REQUEST superglobal in 5.3 It is not explicitly stated in documentation.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="120542">  <div class="votes">
    <div id="Vu120542">
    <a href="/manual/vote-note.php?id=120542&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd120542">
    <a href="/manual/vote-note.php?id=120542&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V120542" title="38% like this...">
    -6
    </div>
  </div>
  <a href="#120542" class="name">
  <strong class="user"><em>Adam</em></strong></a><a class="genanchor" href="#120542"> &para;</a><div class="date" title="2017-01-27 02:51"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom120542">
<div class="phpcode"><code><span class="html">
Remember that `open_basedir` restriction does not affect exec functions. As long as you do not disable exec functions (see `disable_functions`, users will be able to use `exec("/bin/cat [...]")` to access sensitive world readable files.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="106549">  <div class="votes">
    <div id="Vu106549">
    <a href="/manual/vote-note.php?id=106549&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd106549">
    <a href="/manual/vote-note.php?id=106549&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V106549" title="39% like this...">
    -8
    </div>
  </div>
  <a href="#106549" class="name">
  <strong class="user"><em>kghbln</em></strong></a><a class="genanchor" href="#106549"> &para;</a><div class="date" title="2011-11-17 03:09"><strong>8 years ago</strong></div>
  <div class="text" id="Hcom106549">
<div class="phpcode"><code><span class="html">
Adding multiple directories to open_basedir:<br /><br />open_basedir = "/var/www/htdocs/:/var/www/tmp/" adds both paths /var/www/htdocs/ and /var/www/tmp/. Do not forget the trailing slash, otherwise the last directory will be considered as a prefix (&lt; 5.3.4).<br /><br />On Windows you use ; as the seperator.</span>
</code></div>
  </div>
 </div>
  <div class="note" id="123507">  <div class="votes">
    <div id="Vu123507">
    <a href="/manual/vote-note.php?id=123507&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd123507">
    <a href="/manual/vote-note.php?id=123507&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V123507" title="30% like this...">
    -4
    </div>
  </div>
  <a href="#123507" class="name">
  <strong class="user"><em>alaa morad</em></strong></a><a class="genanchor" href="#123507"> &para;</a><div class="date" title="2019-01-09 08:16"><strong>11 months ago</strong></div>
  <div class="text" id="Hcom123507">
<div class="phpcode"><code><span class="html">
add enctype="multipart/form-data" to your &lt;form&gt; tag or it will not upload any file even if file_uploads=on<br />ex:<br />&lt;form method="POST" action="upload. php" enctype="multipart/form-data"&gt;<br />// form contents<br />&lt;/form&gt;</span>
</code></div>
  </div>
 </div>
  <div class="note" id="112135">  <div class="votes">
    <div id="Vu112135">
    <a href="/manual/vote-note.php?id=112135&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd112135">
    <a href="/manual/vote-note.php?id=112135&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V112135" title="33% like this...">
    -17
    </div>
  </div>
  <a href="#112135" class="name">
  <strong class="user"><em>michael dot buergi at gmx dot net</em></strong></a><a class="genanchor" href="#112135"> &para;</a><div class="date" title="2013-05-08 06:18"><strong>6 years ago</strong></div>
  <div class="text" id="Hcom112135">
<div class="phpcode"><code><span class="html">
the ini-setting "detect_unicode" is indeed "zend.detect_unicode" (according to the phpinfo of my 5.4.4)</span>
</code></div>
  </div>
 </div>
  <div class="note" id="121569">  <div class="votes">
    <div id="Vu121569">
    <a href="/manual/vote-note.php?id=121569&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd121569">
    <a href="/manual/vote-note.php?id=121569&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V121569" title="25% like this...">
    -13
    </div>
  </div>
  <a href="#121569" class="name">
  <strong class="user"><em>abc500x500 at gmail dot com</em></strong></a><a class="genanchor" href="#121569"> &para;</a><div class="date" title="2017-08-26 08:10"><strong>2 years ago</strong></div>
  <div class="text" id="Hcom121569">
<div class="phpcode"><code><span class="html">
Please illuminate this:<br />memory_limit=128mb meaning which?<br /><br />1-per script only then if in a moment 1000 user request php script maximum only 128mb of server ram use6 by script.<br />2-per script + per user if in a moment 1000 user request a php script about 1000*128mb=128gb ram use by script.<br />Thanks</span>
</code></div>
  </div>
 </div>
  <div class="note" id="124115">  <div class="votes">
    <div id="Vu124115">
    <a href="/manual/vote-note.php?id=124115&amp;page=ini.core&amp;vote=up" title="Vote up!" class="usernotes-voteu">up</a>
    </div>
    <div id="Vd124115">
    <a href="/manual/vote-note.php?id=124115&amp;page=ini.core&amp;vote=down" title="Vote down!" class="usernotes-voted">down</a>
    </div>
    <div class="tally" id="V124115" title="0% like this...">
    -3
    </div>
  </div>
  <a href="#124115" class="name">
  <strong class="user"><em>diamondeagle at webmail dot co dot za</em></strong></a><a class="genanchor" href="#124115"> &para;</a><div class="date" title="2019-08-15 11:14"><strong>4 months ago</strong></div>
  <div class="text" id="Hcom124115">
<div class="phpcode"><code><span class="html">
Note regarding the upload_tmp_dir setting and UNC Paths:<br /><br />When using PHP on Windows OS and IIS FastCGI, if you need to use a UNC path to a folder on a network drive for the upload_tmp_dir setting then you must use three \ characters at the front of the UNC path. <br /><br />Windows and PHP use the first slash as an escape character, so if you only use two slashes then it passes a UNC path with just one backslash. That is not valid for UNC paths and you many experience problems when uploading files, such as errors saying that "PHP is missing a temporary folder".<br /><br />Correct:<br />upload_tmp_dir = "\\\path\to\your\folder"<br /><br />Incorrect:<br />upload_tmp_dir = "\\path\to\your\folder"</span>
</code></div>
  </div>
 </div></div>

 <div class="foot"><a href="/manual/add-note.php?sect=ini.core&amp;redirect=https://www.php.net/manual/en/ini.core.php"><img src='/images/notes-add@2x.png' alt='add a note' width='12' height='12'> <small>add a note</small></a></div>
</section>    </section><!-- layout-content -->
        <aside class='layout-menu'>

        <ul class='parent-menu-list'>
                                    <li>
                <a href="ini.php">php.ini directives</a>

                                    <ul class='child-menu-list'>

                                                <li class="">
                            <a href="ini.list.php" title="List of php.ini directives">List of php.ini directives</a>
                        </li>
                                                <li class="">
                            <a href="ini.sections.php" title="List of php.ini sections">List of php.ini sections</a>
                        </li>
                                                <li class="current">
                            <a href="ini.core.php" title="Description of core php.ini directives">Description of core php.ini directives</a>
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
