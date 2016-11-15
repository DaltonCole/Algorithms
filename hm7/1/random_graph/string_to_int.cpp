#ifndef STRING_TO_INT
#define STRING_TO_INT

#include <iostream>
using namespace std;

int string_to_int(string s) {
	int length = s.length();

	int number = 0;
	int power = 1;

	for(int i = length - 1; i >= 0; i--) {
		switch(s[i]) {
			case '0':
				number += (power*0);
				break;
			case '1':
				number += (power*1);
				break;
			case '2':
				number += (power*2);
				break;
			case '3':
				number += (power*3);
				break;
			case '4':
				number += (power*4);
				break;
			case '5':
				number += (power*5);
				break;
			case '6':
				number += (power*6);
				break;
			case '7':
				number += (power*7);
				break;
			case '8':
				number += (power*8);
				break;
			case '9':
				number += (power*9);
				break;
			case '-':
				number *= -1;
				break;
			default:
				break;
		}
		power *= 10;
	}

	return number;
}

#endif