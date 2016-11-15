# Floyd-Warshall Algorithm

The Floyd-Warshall Algorithm computes All-Pairs-Shortest-Paths

# Input
*  Size of Adjacency Matrix
*  Adjacency Matrix

## Example
```
5
0 	3 	8 	999 -4
999 0 	999 1 	7
999 4 	0 	999 999 
2 	999 -5 	0 	999
999 999 999 6 	0
```

*  Note, 999 = infinity

# Output
*  Distance Matrix
*  Path Matrix

## Example
```
Distance Matrix:
0	1	-3	2	-4	
3	0	-4	1	-1	
7	4	0	5	3	
2	-1	-5	0	-2	
8	5	1	6	0	

Path Matrix:
-999	3	4	5	1	
4	-999	4	2	1	
4	3	-999	2	1	
4	3	4	-999	1	
4	3	4	5	-999	
```