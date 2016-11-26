#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cut_rod(vector<int> & price, int n) {
	if(n == 0) {
		return 0;
	}
	int q = -999999;

	for(int i = 1; i <= n; i++) {
		q = max(q, price[i] + cut_rod(price, n - i));
	}
	return q;
}

int main() {
	int temp;
	int n;				// Length of rod
	vector<int> price;	// Initial rod prices

	cin >> n;

	price.push_back(0);
	while(cin >> temp) {
		price.push_back(temp);
	}

	cout << cut_rod(price, n) << endl;

	return 0;
}