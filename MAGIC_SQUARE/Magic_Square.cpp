#include "Magic_Square.h"

int Magic_Square::operator ()(int square_size) {
	if(square_size == 2) {
		cout << "There is no magic square of size 2" << endl;
		return -1;
	}

	size = square_size;

	constant = ((size * ((size * size) + 1)) / 2);

	// Create an empty square of size by size
	square = vector<vector<int> > (size, vector<int>(size, 0));

	if(size % 2 != 0) {
		odd_numbered();
	} else if(size % 4 != 0) {
		singly_even();
	} else {
		doubly_even();
	}

	return constant;
}

void Magic_Square::odd_numbered() {
	int count = 1;				// Current count
	int x = (size / 2);		 	// Middle column
	int y = 0;					// Top row
	int temp_x = x, temp_y = y;	// Go up diagnoally

	// When count is greater than the number of squares, quit
	int end_condition = size * size + 1;
	while(count != end_condition) {
		// If the upper right diagnal is free, take it
		if(square[temp_y][temp_x] == 0) {
			x = temp_x;
			y = temp_y;
			square[y][x] = count;
		} else { // Else, take the square above us
			y += (1 % size);
			square[y][x] = count;
		}
		// Increment temp values to the diagnal of the square just taken
		temp_x = (x + 1) % size;
		temp_y = (y + (size - 1)) % size;

		// Increment count
		count++;
	}

	return;
}

void Magic_Square::singly_even() {
	int max_x = size / 2;
	int max_y = max_x;
	int base_x = 0;
	int base_y = 0;
	int count = 1;

	// ----- Divide the square into four quadrents -----
	//						A | C
	//						-----
	//						D | B

	// A
	singly_even_helper(count, base_x, base_y, max_x, max_y);

	// B
	base_x = max_x;
	base_y = max_y;
	max_x = size;
	max_y = size;
	singly_even_helper(count, base_x, base_y, max_x, max_y);

	// C
	base_y = 0;
	max_y = size / 2;
	singly_even_helper(count, base_x, base_y, max_x, max_y);

	// D
	base_x = 0;
	base_y = size / 2;
	max_x = size / 2;
	max_y = size;
	singly_even_helper(count, base_x, base_y, max_x, max_y);

	// ----- Highlight A -----
	// Swap the upper square of A with the upper square of D (up to but not including middle row and column)
	max_x = (size / 2) / 2;
	for(int i = 0; i < max_x; i++) {
		for(int j = 0; j < max_x; j++) {
			swap(square[j][i], square[j + (size / 2)][i]);
		}
	}

	// ----- Highlight B -----
	// Swap the middle row of A with the middle row of D (skipping the first column and going to and including the exact middle)
	max_y = max_x;
	for(int i = 1; i <= max_x; i++) {
		swap(square[max_y][i], square[max_y + (size / 2)][i]);
	}

	// ----- Highlight C -----
	// Swap the lower square of A with the lower square of D (up to but not including middle row and column)
	base_y = max_y + 1;
	max_y = size / 2;
	for(int i = 0; i < max_x; i++) {
		for(int j = base_y; j < max_y; j++) {
			swap(square[j][i], square[j + (size / 2)][i]);
		}
	}

	// ----- Swap last n columns -----
	// Swap the last n - 1 columns of B with C where n = (4 * size) + 2
	int n = ((size - 2) / 4) - 1;

	for(int i = size - 1; i >= size - n; i--) {
		for(int j = 0; j < size / 2; j++) {
			swap(square[j][i], square[j + (size / 2)][i]);
		}
	}

	return;
}

void Magic_Square::singly_even_helper(int & count, const int base_x, const int base_y, const int max_x, const int max_y) {
	int x = (max_x / 2);				// Middle column
	if(base_x != 0) {x += (max_x / 4);}
	int y = base_y;						// Top row
	int temp_x = x, temp_y = y;			// Go up diagnoally

	// When count is greater than the number of squares, quit
	int end_condition = count + ((size / 2) * (size / 2));
	while(count != end_condition) {
		// If the upper right diagnal is free, take it
		if(square[temp_y][temp_x] == 0) {
			x = temp_x;
			y = temp_y;
			square[y][x] = count;
		} else { // Else, take the square above us
			y = (y + 1) % max_y;
			if(y < base_y) {y += base_y;}
			square[y][x] = count;
		}
		// Increment temp values to the diagnal of the square just taken
		temp_x = (x + 1) % max_x;
		if(temp_x < base_x) {temp_x += base_x;}
		temp_y = (y + (size - 1)) % max_y;
		if(temp_y < base_y) {temp_y += base_y;}

		// Increment count
		count++;
	}

	return;
}

void Magic_Square::doubly_even() {
	int box_size = size / 4;

	int counter = 1;

	// Occupy the squares in each corner and the middle square with its respective number
	// such that the corner squares corner touches the middle square
	/* For example, for a 4x3:
			A--B		1	0	0	4
			-MM-		0	6	7	0
			-MM-		0	10	11	0
			C--D		13	0	0	16
	*/
	for(int i = 0; i < size; i++) {		// i = row, j = column
		for(int j = 0; j < size; j++) {
			if(i < box_size && j < box_size) {										// Top left
				square[i][j] = counter;
			} else if(i < box_size && j > ((size - 1) - box_size)) {				// Top right
				square[i][j] = counter;
			} else if(i > ((size - 1) - box_size) && j < box_size) {				// Bottom left
				square[i][j] = counter;
			} else if(i > ((size - 1) - box_size) && j > ((size - 1) - box_size)) {	// Bottom left
				square[i][j] = counter;
			} else if ((i >= box_size && i <= (size - 1 - box_size)) && (j >= box_size && j <= (size - 1 - box_size))) {	// Middle Square
				square[i][j] = counter;
			}
			counter++;
		}
	}

	// Occupy the rest of the squares in reverse order
	counter = 1;
	for(int i = size - 1; i >= 0; i--) {
		for(int j = size - 1; j >= 0; j--) {
			if(square[i][j] == 0) {
				square[i][j] = counter;
			}
			counter++;
		}
	}

	return;
}

bool Magic_Square::check() {
	int total = 0;

	// Sum each row
	for(int i = 0; i < size; i++) {
		total = 0;
		for(int j = 0; j < size; j++) {
			// square[row][column]
			total += square[i][j];
		}
		if(total != constant) {
			return false;
		}
	}

	// Sum each column
	for(int i = 0; i < size; i++) {
		total = 0;
		for(int j = 0; j < size; j++) {
			// square[row][column]
			total += square[j][i];
		}
		if(total != constant) {
			return false;
		}
	}

	// Sum top left to bottom right diagnal
	total = 0;
	for(int i = 0; i < size; i++) {
		total += square[i][i];
	}
	if(total != constant) {
		return false;
	}

	// Sum bottom left to top right diagnal
	total = 0;
	for(int i = 0; i < size; i++) {
		total += square[(size - 1) - i][i];
	}
	if(total != constant) {
		return false;
	}

	return true;
}

ostream& operator <<(ostream& os, Magic_Square s) {
	for(auto i : s.square) {
		for(auto j : i) {
			os << j << " \t";
		}
		os << endl;
	}
	return os;
}