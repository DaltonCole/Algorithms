# Dijkstra's Algorithm

Dijkstra's Algorithm computes Singe-Source-Shortest-Paths

# Compile

g++ -std=c++11 dijkstra.cpp

# Input
*  Size of Adjacency Matrix
*  Adjacency Matrix

## Example
```
5
0 	10 	999 5 	999
999	0 	1 	2 	999
999 999 0 	999 4
999 3 	9 	0 	2
7 	999 6 	999 0
```

*  Note, 999 = infinity

# Output
*  Distance 
*  Path

## Example
```
Distances:
0	0
1	8
2	9
3	5
4	7

Trace:
0	0
1	3
2	1
3	0
4	3	
```