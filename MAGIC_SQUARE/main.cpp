#include <iostream>
#include "Magic_Square.h"
using namespace std;

int main() {
	int size;
	int magic_number;
	Magic_Square square;

	cin >> size;

	magic_number = square(size);

	cout << "Magic Number: " << magic_number << endl;

	cout << square;

	//cout << square.check() << endl;

	return 0;
}