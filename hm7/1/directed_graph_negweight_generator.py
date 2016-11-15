import os
import subprocess
import time

#os.system("./random_graph/g++ -std=c++11 random_directed_graph.cpp")

for i in range(1000):
	command = "./random_graph/./negWeightDirected.out 6 9 -9 40 " + str(i)
	proc = subprocess.Popen([command], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('directed_graphs_negweight/' + str(i), 'w') as f:
		f.write(out)
