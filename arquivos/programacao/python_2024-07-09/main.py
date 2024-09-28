#!/usr/bin/python3

if __name__ == '__main__':
  print("main")

"""
mkdir pacote
echo 'print(__name__ + ": estou em pacote")' > pacote/__main__.py
python3 -m pacote

Os arquivos __init__.py são necessários para que o Python trate diretórios contendo o arquivo como pacotes
Pode ser apenas um arquivo vazio, mas pode também executar código de inicialização do pacote, ou configurar a variável __all__

import packageName
executes the __init__ script

os nomes dos módulos a serem importados quando a instrução from pacote import * é acionada
__all__ = ["echo", "surround", "reverse"]
"""
