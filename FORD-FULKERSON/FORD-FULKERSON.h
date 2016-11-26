#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H


#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

class Ford_Fulkerson;

istream& operator >> (istream& is, Ford_Fulkerson& g);

class Ford_Fulkerson {
	public:
		Ford_Fulkerson() {};
		bool BFS();
		int operator () ();

		friend istream& operator >> (istream& is, Ford_Fulkerson& g);

	private:
		vector<vector<int> > graph;
		vector<vector<int> > residual_graph;
		vector<int> parent;
		int size;
		int s;
		int t;
};

#endif