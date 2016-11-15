#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void dijkstra();

int main() {
	dijkstra();

	return 0;
}

// Used to store the vertex number and the current cost to get to that vertex
struct Vertex {
	int number;
	int weight;

	Vertex() {
		number = 0;
		weight = 0;
	}

	Vertex(int n, int w) {
		number = n;
		weight = w;
	}

	Vertex & operator = (const Vertex &rhs) {
		number = rhs.number;
		weight = rhs.weight;

		return *this;
	}
};

// Compare function class for organizing the priority queue
class Compare {
	public:
		bool operator() (Vertex a, Vertex b) {
			return (a.weight > b.weight ? true : false);
		}
};


/*
-------------- Dijkstra's Algorithm --------------
INITIALIZE-SINGLE-SOURCE(G,s)
S = NONE
Q = G.V
while Q != 0
	u = EXTRACT-MIN(Q)
	S = S UNION {u}
	for each vertex v in G.Adj[u]
		if v.d > u.d + w(u,v)
			v.d = u.d + w(u,v)
			v.source = u
*/
void dijkstra() {
	int INFINITY = 999; 	// What infinity is (greater than any possible shortest path length)
	int source = 0;			// Source vertex

	// Adjacency_matrix
	vector<vector<pair<int, int> > > adjacency_list;

	// Size of square matrix
	int size;

	// Priority Queue
	priority_queue<Vertex, std::vector<Vertex>, Compare> pq;

	// vertex - Used to store poped element from priority queue
	// vertex2 - Used as place holder to push new elements into the priority queue
	Vertex vertex, vertex2;

	// Vector distances
	vector<int> distances;

	// Path trace
	vector<int> trace;

	// Visited
	vector<bool> visited;

	cin >> size;					// Read in size
	vector<pair<int, int> > column; // Column vector

	int temp; // Temporary holder

	// Initialize vectors
	for(int i = 0; i < size; i++) {
		// Add comlumns to adjacency list
		adjacency_list.push_back(column);
		// Infinite distance from source to destination for all verticies except source to source
		distances.push_back(INFINITY);
		// Initialize trace from i to i
		trace.push_back(i);
		// Initialize visted to false for all vertices
		visited.push_back(false);
	}

	// Set distance from the source to the source to 0
	distances[source] = 0;

	// Read in Adjacency Matrix
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cin >> temp;
			if(temp != 0 && temp != INFINITY) {
				adjacency_list[i].push_back(pair<int, int>(j, temp));
			}
		}
	}

	// Add vertecies to queue
	for(int i = 0; i < size; i++) {
		vertex.number = i;
		vertex.weight = distances[i];
		pq.push(vertex);
	}

	/*
	for(auto i : adjacency_list) {
		for(auto it : i) {
			cout << it.first << " " << it.second << "\t";
		}
		cout << endl;
	}
	*/

/*
	// While pq is not empty
	while(pq.empty() != true) {
		// Pop from priority queue
		vertex = pq.top();
		pq.pop();
		// If we've already visited the vertex, ignore it
		if(visited[vertex.number] == false) {
			// Mark vertex as visited
			visited[vertex.number] = true;
			// For each possible edge
			for(int i = 0; i < adjacency_list[vertex.number].size(); i++) {
				// See if updating the distance would improve the distance
				if(distances[adjacency_list[vertex.number][i]] > distances[vertex.number] + adjacency_list[vertex.number][i]) {
					// Update distance vector
					distances[i] = distances[vertex.number] + adjacency_list[vertex.number][i];
					// Update trace vector
					trace[i] = vertex.number;
					// Add new weight and vertex number to priority queue
					vertex2.weight = distances[i];
					vertex2.number = i;
					pq.push(vertex2);
				}
			}
		}
	}
*/
	while(pq.empty() != true) {
		// Pop from priority queue
		vertex = pq.top();
		pq.pop();
		// If we've already visited the vertex, ignore it
		if(visited[vertex.number] == false) {
			// Mark vertex as visited
			visited[vertex.number] = true;
			// For each possibl edge
			for(int i = 0; i < adjacency_list[vertex.number].size(); i++) { // v is an element of G.adj[u]
				if(visited[adjacency_list[vertex.number][i].first] == false) {
					// See if updating the distance would improve the distance
					if(distances[adjacency_list[vertex.number][i].first] > distances[vertex.number] + adjacency_list[vertex.number][i].second) {
						// Update distance vector
						distances[adjacency_list[vertex.number][i].first] = distances[vertex.number] + adjacency_list[vertex.number][i].second;
						// Update trace vector
						trace[adjacency_list[vertex.number][i].first] = vertex.number;
						// Add new weight and vertex number to priority queue
						vertex2.weight = distances[adjacency_list[vertex.number][i].first];
						vertex2.number = adjacency_list[vertex.number][i].first;
						pq.push(vertex2);
					}
				}
			}
		}
	}


	// Print shortest distance and path
	cout << "Distances:" << endl;
	for(int i = 0; i < size; i++) {
		cout << i << "\t" << distances[i] << endl;
	}

	cout << endl << "Trace:" << endl;
	for(int i = 0; i < size; i++) {
		cout << i << "\t" << trace[i] << endl;
	}

	return;
}