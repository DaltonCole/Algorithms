#include "FORD-FULKERSON.h"

bool Ford_Fulkerson::BFS() {
	// Clear old parent
	parent = vector<int>(size, -1);

	// We have not visted anything yet
	vector<bool> visited(size, false);

	// Create q for BFS
	queue<int> q;

	// Add source to q and visted
	q.push(s);
	visited[s] = true;
	// S originated from nothing
	parent[s] = -1;

	// Temporary vertex to contain the current vertex
	int vertex;

	// While there is an edge to be checked
	while(q.empty() == false) {
		// pop front vertex
		vertex = q.front();
		q.pop();

		// For each vertex
		for(int i = 0; i < size; i++) {
			// If we have not visited it and there is an edge
			if(visited[i] == false && residual_graph[vertex][i] > 0) {
				q.push(i);
				parent[i] = vertex;
				visited[i] = true;
				if(visited[t] == true) {
					break;
				}
			}
		}
	}

	return (visited[t] == true);
}

int Ford_Fulkerson::operator () () {
	// Max flow
	int max_flow = 0;
	int temp;

	// Path flow
	int path_flow;

	while(BFS() == true) {
		

		// Set current path_flow to infinity
		path_flow = INT_MAX;

		// Go through the path from end to begining
		for(int i = t; i != s; i = parent[i]) {
			// Take the min current from all edges in path
			path_flow = min(path_flow, residual_graph[parent[i]][i]);
		}

		// Go through the path from end to begining
		for(int i = t; i != s; i = parent[i]) {
			residual_graph[parent[i]][i] -= path_flow;
			residual_graph[i][parent[i]] += path_flow;
		}

		max_flow += path_flow;
	}

	return max_flow;
}


istream& operator >> (istream& is, Ford_Fulkerson& g) {
	cin >> g.size;	// Read in size
	cin >> g.s >> g.t;	// Read in source and sink nodes

	vector<int> temp(g.size, 0);
	vector<vector<int> > graph(g.size, temp);

	for(int i = 0; i < g.size; i++) {
		for(int j = 0; j < g.size; j++) {
			is >> graph[i][j];
		}
	}

	g.graph = graph;
	g.residual_graph = graph;

	return is;
}

/*
vector<vector<int> > graph;
vector<vector<int> > residual_graph;
vector<int> parent;
int size;
int s;
int t;
*/