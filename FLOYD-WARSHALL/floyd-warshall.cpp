#include <iostream>
#include <vector>
using namespace std;

void floyd_warshall();

int main() {
	floyd_warshall();

	return 0;
}

void floyd_warshall() {
	int INFINITY = 999; 	// What infinity is (greater than any possible shortest path length)
	int INITIAL_VERTEX = 1; // Do verticies start at 0 or 1? Used for path output

	// Distance matrix (d)
	vector<vector<int> > distance;

	// Path matrix (pi)
	vector<vector<int> > path;

	// Size of square matrix
	int size;


	cin >> size;		// Read in size
	vector<int> column; // Column vector

	// Initialize matrices
	for(int i = 0; i < size; i++) {
		column.push_back(0);
	}

	for(int i = 0; i < size; i++) {
		distance.push_back(column);
		path.push_back(column);
	}

	// Read in Adjacency Matrix
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cin >> distance[i][j];
		}
	}

	// Set initial path matrix
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			// If distance matrix has 0 or infinity, then there is no edge going from i to j
			if(distance[i][j] == 0 || distance[i][j] == INFINITY) {
				path[i][j] = -INFINITY;

			} else {
				// Else, there is a path to j from i (i + 1 if first vertex is 1)
				path[i][j] = i + INITIAL_VERTEX;
			}
		}
	}

	/*
	-------------- Floyd-Warshall Algorithm --------------
	Floyd-Warshall(W):
	n = W.rows
	D = W
	for k = 1 to n
		for i = 1 to n
			for j = 1 to n
				d[i][j] = min(d[i][j], d[i][k] + d[k][j])
	return D
	*/
	for(int k = 0; k < size; k++) {
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(distance[i][k] + distance[k][j] < distance[i][j]) {
					distance[i][j] = distance[i][k] + distance[k][j]; 	// Update distance matrix with shorter path
					path[i][j] = path[k][j];							// Update path matrix
				}
			}
		}
	}

	// Print distance matrix
	cout << "Distance Matrix:" << endl;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << distance[i][j] << "\t";
		}
		cout << endl;
	}

	// Print path matrix
	cout << endl << "Path Matrix:" << endl;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << path[i][j] << "\t";
		}
		cout << endl;
	}

	return;
}