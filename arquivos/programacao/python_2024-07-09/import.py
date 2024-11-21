import math
print(math.sqrt(9))

import math as m
print(m.sqrt(9))

from math import sqrt
print(sqrt(9))

"""
veja main.py

echo.py

from echo import main, echo
from echo import *

from echo import echo as eco

import echo, sys

dir(echo)
['__builtins__', '__cached__', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'echo', 'main', 'shlex', 'sys']

python3 -c 'import builtins; print(dir(builtins))'

python3 -c 'import sys; print(sys.builtin_module_names)'
python3 -c 'import echo; import sys; print(sys.path)'
sys.path.append('/home/guest/modules')

"""
