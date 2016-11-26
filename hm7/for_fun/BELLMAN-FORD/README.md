# Bellman-Ford's Algorithm

Bellman-Ford's Algorithm computes Singe-Source-Shortest-Paths

# Input
*  Size of Adjacency Matrix
*  Adjacency Matrix

## Example
```
5
0	6	999	7	999
999	0	5	8	-4
999	-2	0	999	999
999	999	-3	0	9
2	999	7	999	0
```

*  Note, 999 = infinity

# Output
*  Distance 
*  Path

## Example
```
Distances:
0	0
1	2
2	4
3	7
4	-2

Trace:
0	0
1	2
2	3
3	0
4	1	
```