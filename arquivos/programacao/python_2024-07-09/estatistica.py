import time
problemSize = 10000000
print("%12s%16s" % ("Problem Size", "Seconds"))
for count in range(5):
  start = time.time()
  # The start of the algorithm
  work = 1
  for x in range(problemSize):
    work += 1
    work -= 1
  # The end of the algorithm
  elapsed = time.time() - start
  print("%12d%16.3f" % (problemSize, elapsed))
  problemSize *= 2


"""
Máquina: Física
Problem Size         Seconds
    10000000           1.583
    20000000           3.175
    40000000           6.349
    80000000          12.686
   160000000          25.384
"""

