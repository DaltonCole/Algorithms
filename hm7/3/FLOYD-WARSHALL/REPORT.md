Random graphs and results for negative edge graphs are in the random_graphs folder.

To check for negative cycles we could use the following c++ code borrowed from the Bellman-ford algorithm:

```
// Check for negative cycles
for(int i = 0; i < size; i++) {
	for(int j = 0; j < size; j++) {
		if(distance[i][j] != 0 && distance[i][j] != INFINITY) {
			if(distance[i][j] > distance[j][i] + adjacency_matrix[i][j]) {
				cout << "GRAPH HAS A NEGATIVE WEIGHT CYCLE" << endl;
				return;
			}
		}
	}
}
```

Where distance is the final distance matrix and adjacency_matrix is the original adjacency matrix input.