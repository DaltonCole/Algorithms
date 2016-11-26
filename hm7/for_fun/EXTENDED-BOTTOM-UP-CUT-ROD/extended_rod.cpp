#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int MY_INFINITY = 999999999;

void extended_bottum_up_cut_rod(unordered_map<int, int> & prices, int n, unordered_map<int, int> & r, unordered_map<int, int> & s) {
	r[0] = 0;
	int q;
	for(int j = 1; j <= n; j++) {
		q = -MY_INFINITY;
		for(int i = 1; i <= j; i++) {
			if(q < prices[i] + r[j-i]) {
				q = prices[i] + r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	return;
}

void print_cut_rod_solution(unordered_map<int, int> & prices, int n, unordered_map<int, int> & r, unordered_map<int, int> & s) {
	while(n > 0) {
		cout << s[n] << ": " << r[n] << endl;
		n -= s[n];
	}

	return;
}

int main() {
	int temp;
	int index = 1;
	int n;				// Length of rod
	unordered_map<int, int> price;	// Initial rod prices
	unordered_map<int, int> r;
	unordered_map<int, int> s;

	cin >> n;

	price[0] = 0;
	while(cin >> temp) {
		price[index] = temp;
		index++;
	}

	extended_bottum_up_cut_rod(price, n, r, s);
	print_cut_rod_solution(price, n, r, s);
	for(int i = 0; i < 10; i++) {
		cout << r[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < 10; i++) {
		cout << s[i] << " ";
	}
	cout << endl;


	return 0;
}