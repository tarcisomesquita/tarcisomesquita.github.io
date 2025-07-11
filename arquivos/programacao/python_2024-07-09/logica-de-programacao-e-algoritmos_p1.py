#!/usr/bin/python3

"""
A. Realizar o print uma mensagem de boas-vindas que apareça o seu nome;
B. Deve-se entrar com o valor unitário e quantidade do produto;
C. Deve-se retornar o valor total sem desconto e o valor total com desconto;
D. Deve-se utilizar as estruturas if, elif e else (todas elas);
E. Deve-se fazer comentários no código;
F. Deve-se colocar na apresentação de saída de console um pedido recebendo desconto;  
"""

# Requisito A
print('\nBem-vindo ao Atacadão! (Tarciso Mesquita de Oliveira)\n')

# Requisito B
# O tratamento de erros de entrada, não fazia parte dos requisitos.
valor = float(input('Digite o valor do produto: R$'))
quantidade = int(input('Digite a quantide de produto: '))

# Requisito C: parte 1
# A saída formatada para dinheiro, não fazia parte dos requisitos.
print('\nTotal SEM desconto: R${}'.format(quantidade * valor))

# Requisito D
if quantidade >= 2000:
	valor *= (1 - 0.15)
elif quantidade >= 1000:
	valor *= (1 - 0.10)
elif quantidade >= 200:
	valor *= (1 - 0.05)
else:
	valor *= (1 - 0.00)

# Requisito C: parte 2
# O alinhamento, não fazia parte dos requisitos.
print('Total COM desconto: R${}'.format(quantidade * valor))

# Requisito E é comentários, então já foi atendido

# Requisito F: colocar na apresentação de saída de console um pedido recebendo desconto
print('\nSe comprar 2000 produtos pagará R${}\n'.format(2000 * valor))
