This report is to showcase that Dijkstra's SSSP algorithm does not work with negative weight graphs.

Say we have the following input:

```
5
0	-1	7	999	999
999	0	999	999	999
999	-10	0	999	2
999	-99	999	0	999
999	999	999	3	0
```

Dijkstra's algorithm yields the following result:

```
Distances:
0	0
1	-1
2	7
3	12
4	9

Trace:
0	0
1	0
2	0
3	4
4	2
```

However, the correct output would be: 

```
Distances:
0	0
1	-87
2	7
3	12
4	9

Trace:
0	0
1	3
2	0
3	4
4	2
```