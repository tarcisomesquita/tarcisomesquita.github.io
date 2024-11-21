"""
"if" assignment_expression ":" suite
("elif" assignment_expression ":" suite)*
["else" ":" suite]

https://docs.python.org/pt-br/3/reference/simple_stmts.html
https://docs.python.org/pt-br/3/reference/expressions.html
https://docs.python.org/pt-br/3/reference/compound_stmts.html
"""

x = int(input("Please enter an integer: "))
if x < 0:
  x = 0
  print('Negative changed to zero')
elif x == 0:
  print('Zero')
elif x == 1:
  print('Single')
else:
  print('More')

