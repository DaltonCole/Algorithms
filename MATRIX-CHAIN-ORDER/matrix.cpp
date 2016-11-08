#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int MY_INFINITY = 999999999;

void matrix_chain_ordering(vector<int> & p, vector<vector<int> > & m, vector<vector<int> > & s, int n) {
	for(int i = 0; i < n; i++) {
		m[i][i] = 0;
	}

	int j = 0;
	int q = 0;
	for(int l = 1; l < n; l++) {
		for(int i = 0; i < n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = MY_INFINITY;
			for(int k = i; k < j-1; k++) {
				q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j-1] = k;
				}
			}
		}
	}

	return;
}

int main() {
	vector<int> p;
	int temp;

	//p.push_back(0);
	while(cin >> temp) {
		p.push_back(temp);
	}

	int n = p.size() - 1;

	vector<int> temp1(n, 0);
	vector<vector<int> > m(n, temp1);
	vector<int> temp2(n-1, 0);
	vector<vector<int> > s(n-1, temp2); //[1..n-1][2..n]

	matrix_chain_ordering(p, m, s, n);

	for(auto it : m) {
		for(auto it2 : it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(auto it : s) {
		for(auto it2 : it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
	cout << endl;


	return 0;
}