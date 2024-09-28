#!/usr/bin/python3
"""
A. Realizar o print uma mensagem de boas-vindas que apareça o seu nome;
B. Deve-se criar uma lista vazia com o nome de lista_colaboradores e a variável id_global com valor inicial igual a 0;
C. Deve-se criar uma função chamada cadastrar_colaborador(id) em que:
	a. Pergunta nome, setor, pagamento do colaborador;
	b. Armazena o id (este é fornecido via parâmetro da função), nome, setor, salário dentro de um dicionário;
	c. Copiar o dicionário dentro para dentro da da lista_colaboradores;
D. Deve-se criar uma função chamada consultar_colaborador() em que:
	a. Deve-se pergunta qual opção deseja (1. Consultar Todos / 2. Consultar por Id / 3. Consultar por Setor / 4. Retornar ao menu) e   realizar o print "Opção inválida" se entrar com valor diferente de 1, 2, 3 ou 4:
		i. Se Consultar Todos, apresentar todos os colaboradores com todos os seus dados cadastrados;
		ii. Se Consultar por Id, apresentar o colaborador específico com todos os seus dados cadastrados;
		iii. Se Consultar por Setor, apresentar todos os colaboradores do setor específico com todos os seus dados cadastrados;
		iv. Se Retornar ao menu, deve-se retornar ao menu principal
E. Deve-se criar uma função chamada remover_colaborador() em que:
	a. Deve-se pergunta pelo id do colaborador a ser removido;
	b. Remover o colaborador da lista_colaboradores;
F. Deve-se criar uma estrutura de menu no main em que:
	a. Deve-se pergunta qual opção deseja (1. Cadastrar Colaborador / 2. Consultar Colaborador / 3. Remover Colaborador / 4. Encerrar Programa) e realizar o print “Opção inválida" se entrar com valor diferente de 1, 2, 3 ou 4 :
		i. Se Cadastrar Colaborador, acrescentar em um a variavel id_ global e chamar a função cadastrar_colaborador(id_ global);
		ii. Se Consultar Colaborador, chamar função consultar_colaborador();
		iii. Se Remover Colaborador, chamar função remover_colaborador();
		iv. Se Encerrar Programa, sair do menu (e com isso acabar a execução do código);
G. Deve-se utilizar lista de dicionários (uma lista contento dicionários dentro);
H. Deve-se fazer comentários no código;
I. Deve-se colocar na apresentação de saída de console o cadastro de 3 colaboradores (sendo 2 deles no mesmo setor);
J. Deve-se colocar na apresentação de saída de console a consulta de todos os colaboradores;
K. Deve-se colocar na apresentação de saída de console a consulta por código de um dos colaboradores;
L. Deve-se colocar na apresentação de saída de console a consulta por setor em que 2 colaboradores façam parte;
M. Deve-se colocar na apresentação de saída de console a remoção de um dos colaboradores e na sequência a consulta de todos os colaboradores;
"""

# Requisito C
def cadastrar_colaborador(id):
	# Requisito C.a
	nome = input('Digite o nome do colaborador: ')
	setor = input('Digite o nome do setor: ')
	while True:
		try:
			pagamento = float(input('Digite o valor do pagamento: R$').replace(',','.'))
			break
		except ValueError:
			print('ERRO: não entendi o número digitado.')
		except:
			print('ERRO: algo imprevisto, aconteceu.')
			continue
	
	# Requisito C.b
	funcionario = {'id':id, 'nome':nome, 'setor':setor, 'salario':pagamento}
	
	# Requisito C.c e Requisito G
	lista_colaboradores.insert(id, funcionario)


# Requisito D
def consultar_colaborador():
	while True:
		# Requisito D.a
		print(100 * '*')
		print('{}'.format('MENU CONSULTAR COLABORADOR'.center(100,'-')), end='')
		print("""
Qual opção deseja?
1. Consultar Todos
2. Consultar por Id
3. Consultar por Setor
4. Retornar ao menu
""", end='')
		while True:
			opcao = input('>> ')
			
			if opcao in '1234':
				break
			else:
				print('Opção inválida')
		
		# Requisito D.a.i
		if opcao == '1':
			for i in range(0,len(lista_colaboradores)):
				print(100 * '-')
				for chave in lista_colaboradores[i]:
					print('{}: {}'.format(chave, lista_colaboradores[i][chave]))
		elif opcao == '2':
			while True:
				try:
					id = int(input('Digite o id do colaborador: '))
					break
				except ValueError:
					print('ERRO: não entendi o número digitado.')
				except:
					print('ERRO: algo imprevisto, aconteceu.')
					continue
			
			for i in range(0,len(lista_colaboradores)):
				if lista_colaboradores[i]['id'] == id:
					print(100 * '-')
					for chave in lista_colaboradores[i]:
						print('{}: {}'.format(chave, lista_colaboradores[i][chave]))
		
		elif opcao == '3':
			setor = input('Digite o setor: ')
			
			for i in range(0,len(lista_colaboradores)):
				if lista_colaboradores[i]['setor'] == setor:
					print(100 * '-')
					for chave in lista_colaboradores[i]:
						print('{}: {}'.format(chave, lista_colaboradores[i][chave]))
		
		elif opcao == '4':
			break


# Requisito E
def remover_colaborador():
	while True:
		try:
			# Requisito E.a
			id = int(input('Digite o id do colaborador: '))
			break
		except ValueError:
			print('ERRO: não entendi o número digitado.')
		except:
			print('ERRO: algo imprevisto, aconteceu.')
			continue
	
	# Requisito E.b
	del lista_colaboradores[id]


# main
# Requisito A
print('\nBem-vindo ao Controle de Colaboradores de Tarciso Mesquita de Oliveira')

# Requisito B
lista_colaboradores = []
id_global = 0

while True:
	# Requisito F
	print(100 * '*')
	print('{}'.format('MENU PRINCIPAL'.center(100,'-')), end='')
	# Requisito F.a
	print("""
Escolha a opção desejada:
1) Cadastrar Colaborador
2) Consultar Colaborador
3) Remover Colaborador
4) Encerrar Programa""")
	
	while True:
		opcao = input('>> ')
		
		if opcao in '1234':
			break
		else:
			print('Opção inválida')
	
	if opcao == '1':
		# Requisito F.a.i
		id_global += 1
		cadastrar_colaborador(id_global)
	elif opcao == '2':
		# Requisito F.a.ii
		consultar_colaborador()
	elif opcao == '3':
		# Requisito F.a.iii
		remover_colaborador()
	if opcao == '4':
		# Requisito F.a.iv
		break

# Requisito H: comentarios
