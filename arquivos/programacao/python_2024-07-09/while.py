"""
"while" assignment_expression ":" suite
["else" ":" suite]

https://docs.python.org/pt-br/3/reference/simple_stmts.html
https://docs.python.org/pt-br/3/reference/compound_stmts.html
https://docs.python.org/pt-br/3/reference/expressions.html
"""

x = 4
while x > 0:
  print(x)
  x = x - 1

s = ''
while not s:
  s = input('Digite seu nome: ')

