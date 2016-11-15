# Transitive Closure Algorithm

The Floyd-Warshall Algorithm computes All-Pairs-Shortest-Paths

# Compile

g++ -std=c++11 transitive_closure.cpp

# Input
*  Size of Adjacency Matrix
*  Matrix with 1's for connected edges and on the diagnal, and 0 everywhere there is not an edge

## Example
```
4
1 0 0 0
0 1 1 1
0 1 1 0
1 0 1 1
```

# Output
*  Transitive Closure matrix

## Example
```
1	0	0	0	
1	1	1	1	
1	1	1	1	
1	1	1	1
```