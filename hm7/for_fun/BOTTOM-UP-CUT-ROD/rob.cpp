#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int MY_INFINITY = 999999999;

int bottum_up_cut_rod(unordered_map<int, int> & prices, int n) {
	unordered_map<int, int> r;
	r[0] = 0;
	int q;
	for(int j = 1; j <= n; j++) {
		q = -MY_INFINITY;
		for(int i = 1; i <= j; i++) {
			q = max(q, prices[i] + r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
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

	cout << bottum_up_cut_rod(price, n) << endl;

	return 0;
}