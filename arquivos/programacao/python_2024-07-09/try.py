#excessão: usuário entrou um dado num formato diferente
#https://docs.python.org/pt-br/3/library/exceptions.html#bltin-execeptions

while True:
	try:
		x = int(input('Digite um número inteiro: '))
	except ValueError:
		print('A entrada não foi um número inteiro')
	except:
		print('Erro não previsto')
	else:
		print(x)
	finally:
		print("executará sempre")
