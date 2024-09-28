#!/usr/bin/python3

import sys
import shlex

def echo(phrase: str) -> None:
  print(phrase)

def main() -> int:
  echo(shlex.join(sys.argv[1:]))
  return 0

if __name__ == '__main__':
  sys.exit(main())
