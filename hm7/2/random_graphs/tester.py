import os
import subprocess
import time

number_of_graphs = 1000
total_run_time = 0

# Clear rum_times file before running
open('run_times', 'w').close()

for i in range(number_of_graphs):
	# Get Graph input
	graph_input = ''
	with open('directed_graphs/' + str(i), 'r') as f:
		graph_input = f.read()
	# Start timmer
	start_time = time.time()
	# Run Dijkstra's algorithm from the previously randomly generated directed graph
	proc = subprocess.Popen(["./../a.out"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
	graph_output = proc.communicate(input=str.encode(graph_input))[0].decode('ascii')
	# End timmer
	run_time = time.time() - start_time
	# Write output of graph to file
	with open('SSSP_results/' + str(i), 'w') as f:
		f.write(graph_output)
	# Append run time to run_time file
	with open('run_times', 'a') as f:
		f.write(str(run_time))
		f.write('\n')
	# Add this run time to total run time
	total_run_time += run_time

# Write average run time to file
with open('average_run_time', 'w') as f:
	f.write('Total time: \t \t' + str(total_run_time) + '\n')
	f.write('Number of graphs: \t' + str(number_of_graphs) + '\n')
	f.write('Average run time: \t' + str(total_run_time / number_of_graphs) + '\n')

