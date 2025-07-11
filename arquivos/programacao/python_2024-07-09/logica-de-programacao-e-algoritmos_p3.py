#!/usr/bin/python3
"""
A. Realizar o print uma mensagem de boas-vindas que apareça o seu nome;
B. Deve-se criar uma função chamada cachorro_peso() em que:
	a. Pergunta o peso do cachorro;
	b. Retorna o valor base com base no peso;
	c. Repete a pergunta do item B.a se peso for igual ou acima 50kg;
	d. Repete a pergunta do item B.a se digitar um valor não numérico;
C. Deve-se criar uma função chamada cachorro_pelo() em que:;
	a. Pergunta o pelo do cachorro;
	b. Retorna o multiplicador com base nos itens descritos no enunciado;
	c. Repete a pergunta do item C.a se digitar uma opção diferente de: c/m/l;
D. Deve-se criar uma função chamada cachorro_extra() em que:
	a. Pergunta pelo serviço adicional;
	b. Acumular o valor extra de cada adicional;
	c. Repetir a pergunta item D.a enquanto não se digitar opção de: "não querer mais nada (0)";
	d. Quando digitar o adicional não querer mais nada (0) retornar o valor extra;
E. Deve-se calcular o total a pagar na parte do main conforme descrito no enunciado;
F. Deve-se utilizar try/except;
G. Deve-se fazer comentários no código;
H. Deve-se colocar na apresentação de saída de console um pedido no qual o usuário digitou um valor não numérico para o peso;
I. Deve-se colocar na apresentação de console um pedido no qual o usuário digitou um valor acima 50 para o peso;
J. Deve-se colocar na apresentação de console um pedido no qual o peso e o tipo de pelo sejam válidos e com mais 2 extras;
"""

# Requisito B
def cachorro_peso():
	global erroPesoValueError
	global erroPeso50
	
	erroPesoValueError = 'NÃO HOUVE ERRO DE DIGITAÇÃO'
	erroPeso50 = 'NÃO HOUVE ERRO DE DIGITAÇÃO'
	
	while True:
		# Requisito F
		try:
			# Requisito B.a
			pesoDigitado = input('Digite o peso do cachorro em kg: ')
			peso = float(pesoDigitado.replace(',', '.'))
			
			# Peso não pode ser nulo ou negativo, mas não era um requisito # Requisito G
			if peso <= 0:
				print('ERRO: o peso não pode ser menor ou igual a zero.\n')
				#erroPeso = pesoDigitado
				continue
			
			# Requisito B.c
			elif peso >= 50:
				print('ERRO: o peso não pode ser maior ou igual a 50 kg.\n')
				erroPeso50 = pesoDigitado
				continue
			
			# Requisito B.b
			if peso < 3:
				return 40
			elif peso >= 3 and peso < 10:
				return 50
			elif peso >= 10 and peso < 30:
				return 60
			elif peso >= 30 and peso < 50:
				return 70
		
		# Requisito B.d
		except ValueError:
			print('ERRO: não entendi o número digitado.\n')
			erroPesoValueError = pesoDigitado
			continue
		except KeyboardInterrupt:
			return 0.0
		except:
			print('ERRO: algo imprevisto, aconteceu.\n')
			continue
	
	return 0.0 # Apenas por segurança. Nunca executado!

# Requisito C
def cachorro_pelo():
	global erroPelo # = 'NÃO HOUVE ERRO DE DIGITAÇÃO'
	
	while True:
		try:
			# Requisito C.a
			pelo = input('O pelo está curto, médio ou longo? (c/m/l): ')
			
			# Requisito C.c
			if pelo != 'c' and pelo != 'm' and pelo != 'l':
				print('ERRO: o pelo pode ser apenas curto (c), médio (m) ou longo (l).\n')
				erroPelo = pelo
				continue
			
			# Requisito C.b
			if pelo == 'c':
				return 1.0
			elif pelo == 'm':
				return 1.5
			elif pelo == 'l':
				return 2.0
		
		except KeyboardInterrupt:
			return 0.0
		except:
			print('ERRO: algo imprevisto, aconteceu.\n')
			continue
	
	return 0.0 # Apenas por segurança. Nunca executado!

# Requisito D
def cachorro_extra():
	extras = 0.0
	escolhidas = []
	
	while True:
		try:
			opcao = int(input("""
Deseja adicionar mais algum serviço?
1 - Cortar as unhas   - R$ 10,00
2 - Escovar os dentes - R$ 12,00
3 - Limpar as orelhas - R$ 15,00
0 - Não desejo mais nada\n: """))
			
			if opcao < 0 or opcao > 3:
				print('ERRO: Deve digitar um número inteiro de 0 a 3.')
				continue
			
			jaEscolheu = False
			for opt in escolhidas:
				if opcao == opt:
					print('ERRO: Já escolheu esta opção.')
					jaEscolheu = True
			
			if jaEscolheu:
				continue
			
			# Requisito B.b
			if opcao == 0:
				return extras
			elif opcao == 1:
				escolhidas.append(opcao)
				extras += 10.00
				continue
			elif opcao == 2:
				escolhidas.append(opcao)
				extras += 12.00
				continue
			elif opcao == 3:
				escolhidas.append(opcao)
				extras += 15.00
				continue
		
		except ValueError:
			print('ERRO: não entendi o número digitado.')
			continue
		except KeyboardInterrupt:
			return 0.0
		except:
			print('ERRO: algo imprevisto, aconteceu.')
			continue
	
	return 0.0 # Apenas por segurança. Nunca executado!


# main
# Requisito A
print('\nBem-vindo ao petshop Mdog! (Tarciso Mesquita de Oliveira)\n')

# Requisito J
print('Exemplo: para cachorro com 20 kg e pelo médio (m), mais cortar unhas e limpar orelhas, custo: R$115.00\n')

base = cachorro_peso()
multiplicador = cachorro_pelo()
extra = cachorro_extra()

# Requisito E
total = base * multiplicador + extra

# Mostrar o total, não estava especificado nos requisitos
#print('\ntotal:{0:.02f} = base:{1:.02f} * multiplicador:{2:.02f} + extra:{3:.02f}'.format(total,base,multiplicador,extra))

print('\nTotal a pagar (R$): {0:.02f}\n'.format(total))


print('Erros ocorridos:')

# Requisito H
print('Valor não numérico para peso: "{}"'.format(erroPesoValueError))

# Requisito I
print('Valor acima de 50: "{}"\n'.format(erroPeso50))
