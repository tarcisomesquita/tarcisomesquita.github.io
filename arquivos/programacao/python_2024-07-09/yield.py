# não funcionou no python3

def fileSigs():
  sigs = [('jpeg', 'FF D8 FF E0'), ('png', '89 50 4E 47 0D 0A 1A 0A'), ('gif', '47 49 46 38 37 61')]
  for s in sigs:
    yield s

fs = fileSigs()
fs.next()
fs.next()
fs.next()

