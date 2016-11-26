#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int MY_INFINITY = 999999999;

int memorized_cut_rod_aux(unordered_map<int, int> & price, int n, unordered_map<int, int> & aux) {
	int q = 0;
	if(aux[n] >= 0) {
		return aux[n];
	}
	if(n == 0) {
		q = 0;
	} else {
		q = -MY_INFINITY;
		for(int i = 1; i <= n; i++) {
			q = max(q, price[i] + memorized_cut_rod_aux(price, n-i, aux));
		}
	}
	aux[n] = q;
	return q;
}

int memorized_cut_rod(unordered_map<int, int> & price, int n) {
	unordered_map<int, int> aux;
	for(int i = 0; i <= n; i++) {
		aux[i] = -MY_INFINITY;
	}
	return memorized_cut_rod_aux(price, n, aux);
} 

int main() {
	int temp;
	int index = 1;
	int n;				// Length of rod
	unordered_map<int, int> price;	// Initial rod prices

	cin >> n;

	price[0] = 0;
	while(cin >> temp) {
		price[index] = temp;
		index++;
	}

	cout << memorized_cut_rod(price, n) << endl;

	return 0;
}