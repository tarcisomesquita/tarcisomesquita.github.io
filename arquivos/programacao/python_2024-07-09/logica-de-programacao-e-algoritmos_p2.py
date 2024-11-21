#!/usr/bin/python3
"""
A. Realizar o print uma mensagem de boas-vindas que apareça o seu nome;
B. Deve-se entrar com o sabor (tr/pr/es) e o número de bolas de sorvete desejado (1/2/3);
C. Deve-se executar o print da mensagem de "Quantidade de Bolas de Sorvete Inválida". Se o usuário entrar com a quantidade de bolas de sorvete diferente de 1, 2 e 3 repetir a partir do item B;
D. Deve-se executar o print da mensagem de "Sabor de Sorvete Inválido" se o usuário entrar com um sabor diferente de tr (tradicional), pr (premium) e es (especial). Printar: e repetir a partir do item B;
E. Deve-se perguntar se o cliente quer pedir mais alguma coisa. Se sim repetir a partir do item B, senão encerrar o programa printando o valor total;
F. Deve-se utilizar as estruturas de while, break, continue (todas elas);
G. Deve-se fazer comentários no código;
H. Deve-se colocar na apresentação de saída de console um pedido no qual o usuário errou ao digitar o sabor do sorvete;
I. Deve-se colocar na apresentação de saída de console um pedido no qual o usuário errou ao digitar o número de bolas de sorvete;
J. Deve-se colocar na apresentação de saída de console um pedido com duas opções sabores diferentes com quantidade de bolas diferentes;
"""

# Requisito A
print('\nBem-vindo à sorveteria Kbom! (Tarciso Mesquita de Oliveira)\n')

# Início da tabela de valores # Requisito G
print('┌' + 81 * '─' + '┐')

print('│{}│'.format('Cardápio'.center(81)))

print('├' + 13 * '─' + '┬' + 24 * '─' + '┬' + 20 * '─' + '┬' + 21 * '─' + '┤')

print('│ Nº DE BOLAS │ Sabor Tradicional (tr) │ Sabor Premium (pr) │ Sabor Especial (es) │')

print('├' + 13 * '─' + '┼' + 24 * '─' + '┼' + 20 * '─' + '┼' + 21 * '─' + '┤')

print('│{0}│{1}│{2}│{3}│'.format('1'.center(13), 'R$  6,00'.center(24), 'R$  7,00'.center(20), 'R$  8,00'.center(21)))
print('│{0}│{1}│{2}│{3}│'.format('2'.center(13), 'R$ 11,00'.center(24), 'R$ 13,00'.center(20), 'R$ 15,00'.center(21)))
print('│{0}│{1}│{2}│{3}│'.format('3'.center(13), 'R$ 15,00'.center(24), 'R$ 18,00'.center(20), 'R$ 21,00'.center(21)))

print('└' + 13 * '─' + '┴' + 24 * '─' + '┴' + 20 * '─' + '┴' + 21 * '─' + '┘\n')
# Final da tabela de valores

valores = {
'tr': [6, 11, 15],
'pr': [7, 13, 18],
'es': [8, 15, 21]
}

total = 0
numeroDigitado = ''
erroSabor = 'NÃO HOUVE ERRO DE DIGITAÇÃO'
erroNumeroBolas = 'NÃO HOUVE ERRO DE DIGITAÇÃO'

# Requisito F
while True:
	try:
		# Requisito B
		sabor = input('Qual sabor? (tr/pr/es): ')
		
		# Requisito D 
		if sabor != 'tr' and sabor != 'pr' and sabor != 'es':  
			print('Sabor de Sorvete Inválido.\n')
			erroSabor = sabor
			continue
		
		numeroDigitado = input('Qual quantide de bolas? (1/2/3): ')
		numeroBolas = int(numeroDigitado)
		
		# Requisito C
		if numeroBolas > 3 or numeroBolas < 1:  
			print('Quantidade de Bolas de Sorvete Inválida.\n')
			erroNumeroBolas = numeroDigitado
			continue
		
		total += valores[sabor][numeroBolas - 1]
		# Mostrar o valor de cada pedido, não é requisito. 
		
		# Requisito E
		if (input('Deseja mais algum sorvete? (S/outra tecla): ').upper() == 'S'):
			print('')
			continue
		else:
			print('\nValor total a ser pago: R${0:.02f}\n'.format(total))
			break
	
	except KeyboardInterrupt:
		break
	except ValueError:
		print('A entrada não foi um número inteiro.\n')
		erroNumeroBolas = numeroDigitado
	except:
		print('Ocorreu um erro não previsto.\n')
		continue

print('Erros ocorridos durante o pedido:')
# Requisito H
print('Sabor de sorvete: "{}"'.format(erroSabor))

# Requisito I
print('Número de bolas: "{}"'.format(erroNumeroBolas))


# Requisito J
print('\nPara finalizar, sugerimos o pedido de 2 bolas tradicionais mais 1 especial por apenas R$19,00!\n');
