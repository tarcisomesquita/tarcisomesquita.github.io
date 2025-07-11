#arquivo = open('arquivo.txt', 'wt+') # cria o arquivo
#arquivo = open('arquivo.txt', 'at') # append
#arquivo.write('{};{}\n'.format(nomeJogo, nomeVideoGame));
arquivo = open('file.py', 'rt') # lê
print(arquivo.readline()) # lista uma linha
print(arquivo.read()) # lista todo o conteúdo do arquivo
arquivo.close()

print("\n", " = =" * 25, "\n")

import os
file = "file.py"
fp = open(file, "r+")
contents = fp.read(os.path.getsize(file))
newContent = contents.replace("thisWord", "thatWord")
print(newContent)
fp.seek(0)
#fp.truncate()
#fp.write(newContent)
fp.close()

print("\n", " = =" * 25, "\n")

out_file = open('teste_lixo.txt', 'w+')
out_file.write('Hello output!')
data = ['falken', 124, 'joshua']
out_file.writelines(str(data))
out_file.flush()
out_file.close()

print ("cat teste_lixo.txt; rm teste_lixo.txt")
