import os
import subprocess
import time

#os.system("./random_graph/g++ -std=c++11 random_directed_graph.cpp")

for i in range(1000):
	proc = subprocess.Popen(["./random_graph/undirected.out " + str(i)], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('undirected_graphs/' + str(i), 'w') as f:
		f.write(out)
