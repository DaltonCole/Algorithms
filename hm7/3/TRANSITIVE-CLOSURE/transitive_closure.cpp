#include <iostream>
#include <vector>
using namespace std;

void transitive_closure();

int main() {
	transitive_closure();

	return 0;
}

/*
-------------- TRANSITIVE-CLOSURE Algorithm --------------
n = |G.V|
Let T0 = t[i][j]0 be a enw nxn matrix
for i = 1 to n
	for j = 1 to n
		if i == j or (i,j) is an element of G.E
			t[i][j]0 = 1
		else
			t[i][j]0 = 0
for k = 1 to n
	Let Tk = t[i][j]k be a enw nxn matrix
	for i = 1 to n
		for j = 1 to n
			t[i][j]k = t[i][j] OR (t[i][k] AND t[k][j])
return t[i][k]j
*/
void transitive_closure() {
	int INFINITY = 999; 	// What infinity is (greater than any possible shortest path length)
	int INITIAL_VERTEX = 1; // Do verticies start at 0 or 1? Used for path output


	vector<vector<int> > adjacency_matrix;

	vector<vector<int> > previous_closure;
	vector<vector<int> > current_closure;

	// Size of square matrix
	int size;


	cin >> size;		// Read in size
	vector<int> column; // Column vector

	// Initialize matrices
	for(int i = 0; i < size; i++) {
		column.push_back(0);
	}

	for(int i = 0; i < size; i++) {
		adjacency_matrix.push_back(column);
		previous_closure.push_back(column);
		current_closure.push_back(column);
	}

	// Read in Adjacency Matrix
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cin >> adjacency_matrix[i][j];
		}
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i == j || (adjacency_matrix[i][j] != 0 && adjacency_matrix[i][j] != INFINITY)) {
				previous_closure[i][j] = 1;
			} else {
				previous_closure[i][j] = 0;
			}
		}
	}


	for(int k = 0; k < size; k++) {
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				current_closure[i][j] = previous_closure[i][j] | (previous_closure[i][k] & previous_closure[k][j]);
			}
		}
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				previous_closure[i][j] = current_closure[i][j];
			}
		}
	}

	// Print transitive closure
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << current_closure[i][j] << "\t";
		}
		cout << endl;
	}


	return;
}