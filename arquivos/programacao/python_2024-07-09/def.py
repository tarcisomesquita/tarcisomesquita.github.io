def soma(x = 0, y = 0, z = 0):
	"""
	Retorna a soma de três números.
	Todos os parâmetros são opcionais.
	
	:parâmetro x: valor numérico (opcional)
	:parâmetro y: valor numérico (opcional)
	:parâmetro z: valor numérico (opcional)
	:return: número
	"""

"""
funcdef                   ::=  [decorators] "def" funcname "(" [parameter_list] ")"
                               ["->" expression] ":" suite
decorators                ::=  decorator+
decorator                 ::=  "@" assignment_expression NEWLINE
parameter_list            ::=  defparameter ("," defparameter)* "," "/" ["," [parameter_list_no_posonly]]
                                 | parameter_list_no_posonly
parameter_list_no_posonly ::=  defparameter ("," defparameter)* ["," [parameter_list_starargs]]
                               | parameter_list_starargs
parameter_list_starargs   ::=  "*" [parameter] ("," defparameter)* ["," ["**" parameter [","]]]
                               | "**" parameter [","]
parameter                 ::=  identifier [":" expression]
defparameter              ::=  parameter ["=" expression]
funcname                  ::=  identifier

https://docs.python.org/pt-br/3/reference/simple_stmts.html
https://docs.python.org/pt-br/3/reference/compound_stmts.html
https://docs.python.org/pt-br/3/reference/expressions.html

https://docs.python.org/pt-br/3/library/functions.html
"""

	return x + y + z

print(soma(3,2))
help(soma)

print("\n", " = =" * 25, "\n")

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

res = lambda x, y: x + y
print(res(3, 5))

print("\n", " = =" * 25, "\n")

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# variável global versus local
ovos = 12

def t1():
	ovos = 6
	print(ovos)


t1()
print(ovos)

def t2():
	global ovos
	ovos = 2

t2()
print(ovos)

print("\n", " = =" * 25, "\n")

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

def fun_nome(x, y): return 2*y + x;

# troquei a ordem dos parâmetros
print(fun_nome(y = 3, x = 1))

print("\n", " = =" * 25, "\n")

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# função como argumento
def imprime(num, func):
	if func(num):
		print('par')
	else:
		print('impar')

def par(x):
	return x % 2 == 0

imprime(5, par)

print("\n", " = =" * 25, "\n")

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# contém parâmetros com valores default
def ask_ok(prompt, retries=4, reminder='Please try again!'):
  while True:
    ok = input(prompt)
    if ok in ('y', 'ye', 'yes'):
      return True
    
    if ok in ('n', 'no', 'nop', 'nope'):
      return False
    
    retries = retries - 1
    if retries < 0:
      raise ValueError('invalid user response')
    
    print(reminder)


ask_ok('Do you really want to quit? ') # only the mandatory argument

ask_ok('OK to overwrite the file? ', 2, 'Come on, only yes or no!') # giving all arguments

print("\n", " = =" * 25, "\n")

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


def cheeseshop(kind, *arguments, **keywords):
    print("-- Do you have any", kind, "?")
    print("-- I'm sorry, we're all out of", kind)
    for arg in arguments:
        print(arg)
    print("-" * 40)
    for kw in keywords:
        print(kw, ":", keywords[kw])

cheeseshop("Limburger", "It's very runny, sir.",
           "It's really very, VERY runny, sir.",
           shopkeeper="Michael Palin",
           client="John Cleese",
           sketch="Cheese Shop Sketch")

