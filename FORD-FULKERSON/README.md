# FORD FULKERSON

## Description

The Ford Fulkerson algorithm is used to find the max-flow for a connected, directed graph

## Compile

c++ -std=c++11 *.cpp

## Input

An adjacency matrix is required as input. 
The first line of input is the number of vertices
The second line of input is the source and the sink vertices
This is followed by an adjacency matrix

### Example

```
10
7 	5
0 	 	6 	 	13 	 	18 	 	17 	 	7 	 	13 	 	9 	 	10 	 	10 	 	
0 	 	0 	 	7 	 	8 	 	11 	 	8 	 	11 	 	1 	 	16 	 	3 	 	
7 	 	2 	 	0 	 	2 	 	16 	 	13 	 	9 	 	7 	 	18 	 	18 	 	
1 	 	19 	 	9 	 	0 	 	19 	 	2 	 	1 	 	19 	 	17 	 	6 	 	
13 	 	3 	 	6 	 	11 	 	0 	 	9 	 	14 	 	13 	 	8 	 	17 	 	
7 	 	14 	 	6 	 	19 	 	2 	 	0 	 	4 	 	10 	 	3 	 	10 	 	
18 	 	2 	 	0 	 	11 	 	3 	 	1 	 	0 	 	18 	 	12 	 	18 	 	
17 	 	9 	 	2 	 	16 	 	11 	 	13 	 	14 	 	0 	 	1 	 	10 	 	
13 	 	5 	 	18 	 	18 	 	19 	 	10 	 	5 	 	11 	 	0 	 	18 	 	
11 	 	3 	 	7 	 	13 	 	13 	 	2 	 	2 	 	5 	 	5 	 	0 	 	
```

## Output

The max-flow is outputed

### Example

```
65
```

## TABLE

This contains the average run times and a graph displaying the average run times for nodes = 10, 20, 30, 40, 50

## Other Directories

### random_graph_generation/

This directory contains the program to randonly generate graphs and a python script to create them in bulk.

This directory also contains 100 graphs with 10 nodes, 20 nodes, ..., 50 nodes.

### data/

This directory contains a script to run the Ford Fulkerson algorithm on the previously generated graphs and calculate the run times.