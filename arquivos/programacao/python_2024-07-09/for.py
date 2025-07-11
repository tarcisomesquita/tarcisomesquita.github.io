"""
"for" target_list "in" starred_list ":" suite
["else" ":" suite]

https://docs.python.org/pt-br/3/reference/simple_stmts.html
https://docs.python.org/pt-br/3/reference/expressions.html
https://docs.python.org/pt-br/3/reference/compound_stmts.html
"""

for letter in 'PYTHON':
  print(letter)

for i in range(0, 10, 3):
  print(i)

lists = [[] for i in range(3)]
lists[0].append(3)
lists[1].append(5)
lists[2].append(7)
[[3], [5], [7]]

words = ['cat', 'window', 'defenestrate']
for w in words:
  print(w, len(w))

a = ['Mary', 'had', 'a', 'little', 'lamb']
for i in range(len(a)):
  print(i, a[i])

numbers = [5, 25, 35]
for i, x in enumerate(numbers):
  print('Item', i, 'from the list is:', x)

grades = {90:'A', 80:'B', 70:'C'} # dictionary
for key in grades:
  print(key, grades[key])

for (key, value) in grades.items():
  print(key, value)

