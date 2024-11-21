
"" python3 -m json.tool < some.json 
cat Q42.json | python -m json.tool | pygmentize -l
""

import sys
import json
from pygments import highlight, lexers, formatters

formatted_json = json.dumps(json.loads(sys.argv[1]), indent=4)
colorful_json = highlight(unicode(formatted_json, 'UTF-8'), lexers.JsonLexer(), formatters.TerminalFormatter())
print(colorful_json)
