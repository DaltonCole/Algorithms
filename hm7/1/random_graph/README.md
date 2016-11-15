# Random directed graph

Generates a random directed graph in a adjacency matrix structure

## Compile

g++ -std=c++11 random_directed_graph.cpp -o directed.out 

## Arguments

### Normal Arguments

* If 2 arguments: arg1 = vertices
* If 3 arguments: arg1 = vertices, arg2 = max_edge
* If 4 arguments: arg1 = vertices, arg2 = max_edge, arg3 = min_edge
* If 5 arguments: arg1 = vertices, arg2 = max_edge, arg3 = min_edge, arg4 = connectivness
* If 6 argumetns: arg1 = vertices, arg2 = max_edge, arg3 = min_edge, arg4 = connectivness, arg5 = srand seed

## Output

Output is the number of verticies followed by the adjacency matrix

NOTE: 999 represents infinity

### Example

```
6
0 	 	999 	 	999 	 	999 	 	8 	 	999 	 	
8 	 	0 	 	999 	 	3 	 	999 	 	999 	 	
999 	 	2 	 	0 	 	999 	 	6 	 	999 	 	
999 	 	999 	 	8 	 	0 	 	999 	 	2 	 	
9 	 	999 	 	8 	 	7 	 	0 	 	999 	 	
999 	 	999 	 	7 	 	999 	 	1 	 	0 
```

# Random undirected graph

Generates a random undirected graph in a adjacency matrix structure

## Compile

g++ -std=c++11 random_undirected_graph.cpp -o undirected.out 

## Arguments

### Normal Arguments

* If 2 arguments: arg1 = vertices
* If 3 arguments: arg1 = vertices, arg2 = max_edge
* If 4 arguments: arg1 = vertices, arg2 = max_edge, arg3 = min_edge
* If 5 arguments: arg1 = vertices, arg2 = max_edge, arg3 = min_edge, arg4 = connectivness
* If 6 argumetns: arg1 = vertices, arg2 = max_edge, arg3 = min_edge, arg4 = connectivness, arg5 = srand seed

### Other Arguments

The code can be changed such that the only argument to the program is a second argument that takes the random seed

## Output

Output is the number of verticies followed by the adjacency matrix

NOTE: 999 represents infinity

### Example

```
6
0 	 	8 	 	999 	 	999 	 	9 	 	999 	 	
8 	 	0 	 	2 	 	3 	 	999 	 	999 	 	
999 	 	2 	 	0 	 	8 	 	8 	 	7 	 	
999 	 	3 	 	8 	 	0 	 	7 	 	2 	 	
9 	 	999 	 	8 	 	7 	 	0 	 	1 	 	
999 	 	999 	 	7 	 	2 	 	1 	 	0 
```