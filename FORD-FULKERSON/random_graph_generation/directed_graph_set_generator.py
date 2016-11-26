import os
import subprocess
import time

for i in range(100):
	command = "./a.out 10 20 0 " + str(i + 20) + " " + str(i)
	proc = subprocess.Popen([command], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('graphs/10/' + str(i), 'w') as f:
		f.write(out)

for i in range(100):
	command = "./a.out 20 20 0 " + str(i + 20) + " " + str(i)
	proc = subprocess.Popen([command], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('graphs/20/' + str(i), 'w') as f:
		f.write(out)

for i in range(100):
	command = "./a.out 30 20 0 " + str(i + 20) + " " + str(i)
	proc = subprocess.Popen([command], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('graphs/30/' + str(i), 'w') as f:
		f.write(out)

for i in range(100):
	command = "./a.out 40 20 0 " + str(i + 20) + " " + str(i)
	proc = subprocess.Popen([command], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('graphs/40/' + str(i), 'w') as f:
		f.write(out)

for i in range(100):
	command = "./a.out 50 20 0 " + str(i + 20) + " " + str(i)
	proc = subprocess.Popen([command], stdout=subprocess.PIPE, shell=True)
	out = proc.communicate()[0].decode('ascii')
	with open('graphs/50/' + str(i), 'w') as f:
		f.write(out)
