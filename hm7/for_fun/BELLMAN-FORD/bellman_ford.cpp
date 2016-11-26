#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bellman_ford();

int main() {
	bellman_ford();

	return 0;
}

/*
-------------- BELLMAN-FORD(G, w, s) --------------
Initialize-Single-Source(G,s)
for i = 1 to |G.V| - 1
	for each edge (u,v) in G.E
		Relax(u,v,w)
for each edge (u,v) in G.E
	if v.d > u.d + w(u,v)
		return False
return True

-------------- RELAX(u,v,w) --------------
if v.d > u.d + w(u,v)
	v.d = u.d + w(u,v)
	v.source = u

-------------- Initialize-Single-Source(G,s) --------------
for each vertex v in G.V
	v.d = INFINITY
	v.source = NIL
source.d = 0
*/
void bellman_ford() {
	int INFINITY = 999; 	// What infinity is (greater than any possible shortest path length)
	int SOURCE = 0;			// Source vertex

	// Size of square matrix
	int size;

	// Distance vector
	vector<int> distance;

	// Path trace 
	vector<int> trace; 

	cin >> size;	// Read in size

	// Adjacency_matrix
	vector<int> column(size, 0);
	vector<vector<int> > adjacency_matrix(size, column);

	// Initialize vectors
	for(int i = 0; i < size; i++) {
		// Initialize distance vector
		distance.push_back(INFINITY);
		// Initialize trace vector
		trace.push_back(INFINITY);
	}

	// Set distance to source to 0
	distance[SOURCE] = 0;
	// Set route from source to source
	trace[SOURCE] = SOURCE;

	// Read in Adjacency Matrix
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cin >> adjacency_matrix[i][j];
		}
	}

	// For |Vertex| - 1
	for(int i = 0; i < size - 1; i++) {
		// For each edge
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				// If edge exists
				if(adjacency_matrix[i][j] != 0 && adjacency_matrix[i][j] != INFINITY) {
					// If there is a shorter distance
					if(distance[j] > distance[i] + adjacency_matrix[i][j]) {
						// Update distance
						distance[j] = distance[i] + adjacency_matrix[i][j];
						// Update route
						trace[j] = i;
					}
				}
			}
		}
	}

	// Check for negative cycles
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(adjacency_matrix[i][j] != 0 && adjacency_matrix[i][j] != INFINITY) {
				if(distance[j] > distance[i] + adjacency_matrix[i][j]) {
					cout << "GRAPH HAS A NEGATIVE WEIGHT CYCLE" << endl;
					return;
				}
			}
		}
	}

	// Print shortest distance and path
	cout << "Distances:" << endl;
	for(int i = 0; i < size; i++) {
		cout << i << "\t" << distance[i] << endl;
	}

	cout << endl << "Trace:" << endl;
	for(int i = 0; i < size; i++) {
		cout << i << "\t" << trace[i] << endl;
	}

	return;
}