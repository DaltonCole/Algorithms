import os
import subprocess
import time

# 10
number_of_graphs = 100
total_run_time = 0

# Clear rum_times file before running
open('10/run_times', 'w').close()

for i in range(number_of_graphs):
	# Get Graph input
	graph_input = ''
	with open('../random_graph_generation/graphs/10/' + str(i), 'r') as f:
		graph_input = f.read()
	# Start timmer
	start_time = time.time()
	# Run FORD_FULKERSON algorithm from the previously randomly generated directed graph
	proc = subprocess.Popen(["./../a.out"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
	graph_output = proc.communicate(input=str.encode(graph_input))[0].decode('ascii')
	# End timmer
	run_time = time.time() - start_time
	# Write output of graph to file
	with open('10/results/' + str(i), 'w') as f:
		f.write(graph_output)
	# Append run time to run_time file
	with open('10/run_times', 'a') as f:
		f.write(str(run_time))
		f.write('\n')
	# Add this run time to total run time
	total_run_time += run_time

# Write average run time to file
with open('10/average_run_time', 'w') as f:
	f.write('Total time: \t \t' + str(total_run_time) + '\n')
	f.write('Number of graphs: \t' + str(number_of_graphs) + '\n')
	f.write('Average run time: \t' + str(total_run_time / number_of_graphs) + '\n')


# 20
number_of_graphs = 100
total_run_time = 0

# Clear rum_times file before running
open('20/run_times', 'w').close()

for i in range(number_of_graphs):
	# Get Graph input
	graph_input = ''
	with open('../random_graph_generation/graphs/20/' + str(i), 'r') as f:
		graph_input = f.read()
	# Start timmer
	start_time = time.time()
	# Run FORD_FULKERSON algorithm from the previously randomly generated directed graph
	proc = subprocess.Popen(["./../a.out"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
	graph_output = proc.communicate(input=str.encode(graph_input))[0].decode('ascii')
	# End timmer
	run_time = time.time() - start_time
	# Write output of graph to file
	with open('20/results/' + str(i), 'w') as f:
		f.write(graph_output)
	# Append run time to run_time file
	with open('20/run_times', 'a') as f:
		f.write(str(run_time))
		f.write('\n')
	# Add this run time to total run time
	total_run_time += run_time

# Write average run time to file
with open('20/average_run_time', 'w') as f:
	f.write('Total time: \t \t' + str(total_run_time) + '\n')
	f.write('Number of graphs: \t' + str(number_of_graphs) + '\n')
	f.write('Average run time: \t' + str(total_run_time / number_of_graphs) + '\n')


# 30
number_of_graphs = 100
total_run_time = 0

# Clear rum_times file before running
open('30/run_times', 'w').close()

for i in range(number_of_graphs):
	# Get Graph input
	graph_input = ''
	with open('../random_graph_generation/graphs/30/' + str(i), 'r') as f:
		graph_input = f.read()
	# Start timmer
	start_time = time.time()
	# Run FORD_FULKERSON algorithm from the previously randomly generated directed graph
	proc = subprocess.Popen(["./../a.out"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
	graph_output = proc.communicate(input=str.encode(graph_input))[0].decode('ascii')
	# End timmer
	run_time = time.time() - start_time
	# Write output of graph to file
	with open('30/results/' + str(i), 'w') as f:
		f.write(graph_output)
	# Append run time to run_time file
	with open('30/run_times', 'a') as f:
		f.write(str(run_time))
		f.write('\n')
	# Add this run time to total run time
	total_run_time += run_time

# Write average run time to file
with open('30/average_run_time', 'w') as f:
	f.write('Total time: \t \t' + str(total_run_time) + '\n')
	f.write('Number of graphs: \t' + str(number_of_graphs) + '\n')
	f.write('Average run time: \t' + str(total_run_time / number_of_graphs) + '\n')


# 40
number_of_graphs = 100
total_run_time = 0

# Clear rum_times file before running
open('40/run_times', 'w').close()

for i in range(number_of_graphs):
	# Get Graph input
	graph_input = ''
	with open('../random_graph_generation/graphs/40/' + str(i), 'r') as f:
		graph_input = f.read()
	# Start timmer
	start_time = time.time()
	# Run FORD_FULKERSON algorithm from the previously randomly generated directed graph
	proc = subprocess.Popen(["./../a.out"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
	graph_output = proc.communicate(input=str.encode(graph_input))[0].decode('ascii')
	# End timmer
	run_time = time.time() - start_time
	# Write output of graph to file
	with open('40/results/' + str(i), 'w') as f:
		f.write(graph_output)
	# Append run time to run_time file
	with open('40/run_times', 'a') as f:
		f.write(str(run_time))
		f.write('\n')
	# Add this run time to total run time
	total_run_time += run_time

# Write average run time to file
with open('40/average_run_time', 'w') as f:
	f.write('Total time: \t \t' + str(total_run_time) + '\n')
	f.write('Number of graphs: \t' + str(number_of_graphs) + '\n')
	f.write('Average run time: \t' + str(total_run_time / number_of_graphs) + '\n')



# 50
number_of_graphs = 100
total_run_time = 0

# Clear rum_times file before running
open('50/run_times', 'w').close()

for i in range(number_of_graphs):
	# Get Graph input
	graph_input = ''
	with open('../random_graph_generation/graphs/50/' + str(i), 'r') as f:
		graph_input = f.read()
	# Start timmer
	start_time = time.time()
	# Run FORD_FULKERSON algorithm from the previously randomly generated directed graph
	proc = subprocess.Popen(["./../a.out"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
	graph_output = proc.communicate(input=str.encode(graph_input))[0].decode('ascii')
	# End timmer
	run_time = time.time() - start_time
	# Write output of graph to file
	with open('50/results/' + str(i), 'w') as f:
		f.write(graph_output)
	# Append run time to run_time file
	with open('50/run_times', 'a') as f:
		f.write(str(run_time))
		f.write('\n')
	# Add this run time to total run time
	total_run_time += run_time

# Write average run time to file
with open('50/average_run_time', 'w') as f:
	f.write('Total time: \t \t' + str(total_run_time) + '\n')
	f.write('Number of graphs: \t' + str(number_of_graphs) + '\n')
	f.write('Average run time: \t' + str(total_run_time / number_of_graphs) + '\n')