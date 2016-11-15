import os
import subprocess
import time

for i in range(1000):
	proc = subprocess.Popen(["./random_graph/directed.out " + str(i)], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('directed_graphs/' + str(i), 'w') as f:
		f.write(out)
