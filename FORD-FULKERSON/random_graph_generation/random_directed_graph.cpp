#include <iostream>
#include <vector>
#include <ctime>		// time()
#include <random>		// rand()
#include <limits>		// Infinity
#include <string>		// stoi() - String to int
#include <algorithm>
#include "string_to_int.cpp"
using namespace std;

int main(int argc, char* argv[]) {
	srand (time(NULL));		// Random seed

	int vertices = 6;		// Number of vertices
	int r = vertices;		// Row
	int c = vertices;		// Column
	int max_edge = 9;		// Maximum edge weight
	int min_edge = 1;		// Minimum edge weight
	int connectivness = 40;	// Percent chance that two nodes will be connected
	int random_number;
	int MY_INFINITY = 0; 	//numeric_limits<int>::max();
	int int_temp;

	// If 2 arguments: arg1 = vertices
	// If 3 arguments: arg1 = vertices, arg2 = max_edge
	// If 4 arguments: arg1 = vertices, arg2 = max_edge, arg3 = min_edge
	// If 5 arguments: arg1 = vertices, arg2 = max_edge, arg3 = min_edge, arg4 = connectivness
	// If 6 argumetns: arg1 = vertices, arg2 = max_edge, arg3 = min_edge, arg4 = connectivness, arg5 = srand seed
	if(argc == 2) {
		vertices = string_to_int(argv[1]);
	}  else if(argc == 3) {
		vertices = string_to_int(argv[1]);
		max_edge = string_to_int(argv[2]);
	} else if(argc == 4) {
		vertices = string_to_int(argv[1]);
		max_edge = string_to_int(argv[2]);
		min_edge = string_to_int(argv[3]);
	} else if(argc == 5) {
		vertices = string_to_int(argv[1]);
		max_edge = string_to_int(argv[2]);
		min_edge = string_to_int(argv[3]);
		connectivness = string_to_int(argv[4]);
	}  else if(argc == 6) {
		vertices = string_to_int(argv[1]);
		max_edge = string_to_int(argv[2]);
		min_edge = string_to_int(argv[3]);
		connectivness = string_to_int(argv[4]);
		srand (string_to_int(argv[5]));			// ---- If we don't want to use time as a random seed ----
	}

	// Reset row and column count
	r = vertices;
	c = vertices;

	// Create Adjacency Matrix
	vector<int> temp(c, MY_INFINITY);
	vector<vector<int> > adjacency_matrix(r, temp);	// a[r][c]

	// Vector to make sure graph is connected
	vector<int> connected(vertices, 0);

	// Populate Adjacency Matrix
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(i == j) {
				adjacency_matrix[i][j] = 0;
				continue;
			}
			random_number = (rand() % 100);		// Percent change of edge existing
			if(random_number < connectivness) {
				adjacency_matrix[i][j] = (rand() % (abs(max_edge) + abs(min_edge))) + min_edge;
			}
		}
	}

	// Put every vertex into its own set
	for(int i = 0; i < r; i++) {
		connected[i] = i;
	}

	// See which vertex is in which subraph
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(i == j) {
				continue;
			}
			// If there is an edge going from i to j
			if(adjacency_matrix[i][j] != MY_INFINITY) {
				// Add vertex j to i's subgraph
				int_temp = connected[j];
				for(auto & it : connected) {
					if(it == int_temp) {
						it = connected[i];
					}
				}
			}
		}
	}

	// Vector a and b representing u -> v or u <- v
	vector<int> start;
	vector<int> end;
	// For each vertex
	for(int i = 0; i < vertices - 1; i++) {
		// If connected[i] and i+1 are not in the same subgraph, connect the two
		if(connected[i] != connected[i+1]) {
			// For each vertex, add verticies in subgraph a to start and subgraph b to end
			for(int j = 0; j < vertices; j++) {
				if(connected[j] == connected[i]) {
					start.push_back(j);
				} else if(connected[j] == connected[i+1]) {
					end.push_back(j);
				}
			}

			// Generate a random number to see if a vertex from a will point to b or vice versa
			random_number = rand() % 2;
			if(random_number == 0) {
				// Add edge to a vertex in subgraph a to a vertex in subgraph b
				adjacency_matrix[start[rand() % start.size()]][end[rand() % end.size()]] = (rand() % max_edge) + min_edge;
			} else {
				// Add edge to a vertex in subgraph b to a vertex in subgraph a
				adjacency_matrix[end[rand() % end.size()]][start[rand() % start.size()]] = (rand() % max_edge) + min_edge;
			}

			// Change connected vector such that subgraph a and b are in the same subgraph
			int_temp = connected[i];
			for(auto & it : connected) {
				if(it == int_temp) {
					it = connected[i+1];
				}
			}
			// Clear start and end vectors
			start.clear();
			end.clear();
		}
	}

	cout << vertices << endl;

	// Create random source and sink
	int temp1, temp2;
	temp1 = rand() % vertices;
	temp2 = rand() % vertices;
	while(temp2 == temp1) {
		temp2 = rand() % vertices;
	}

	cout << temp1 << " \t" << temp2 << endl;

	// Print Adjacency Matrix
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++) {
			cout << adjacency_matrix[j][i] << " \t \t";
		}
		cout << endl;
	}

	return 0;
}