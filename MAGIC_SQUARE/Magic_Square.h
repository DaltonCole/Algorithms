//////////////////////////////////////////////////////////////////////
/// @file Magic_Square.h
/// @author Dalton Cole, CS5200 assignment 9
/// @brief Class declaration of Magic_Square
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class Magic_Square
/// @brief Creates a magic square for any size not equal to 2
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn int Magic_Square::operator ()(int square_size)
/// @brief Creates a magic square and stores it in square
/// @post square now contains the magic square and constant contains the
///		magic constant
/// @param square_size is the desired width of the square
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn ostream& operator <<(ostream& os, Magic_Square s)
/// @brief Outputs the magic square
/// @pre The function operator should be ran first
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool Magic_Square::check()
/// @brief Checks to make sure that square is a magic square
/// @pre Function operator should be called previously
/// @post Returns true of square is a magic square
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void Magic_Square::odd_numbered()
/// @brief Calculates the magic square of odd sized squares
/// @pre square and size must be initiated
/// @post square now contains the magic square
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void Magic_Square::singly_even()
/// @brief Calculates the magic square of even sized squares that are
/// 	not divisable by 4
/// @pre square and size must be initiated
/// @post square now contains the magic square
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void Magic_Square::singly_even()
/// @brief Calculates the magic square of even sized squares that are
/// 	not divisable by 4
/// @pre square and size must be initiated
/// @post square now contains the magic square
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void Magic_Square::singly_even_helper(int & count, const int 
///		base_x, const int base_y, const int max_x, const int max_y)
/// @brief Populates each quadrent of the magic swuare
/// @post square contains an almost magic square
//////////////////////////////////////////////////////////////////////

#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Magic_Square;

ostream& operator<<(ostream& os, Magic_Square s);

class Magic_Square {
	public:
		int operator ()(int square_size);
		friend ostream& operator <<(ostream& os, Magic_Square s);

		bool check();

	private:
		void odd_numbered();
		void singly_even();
		void singly_even_helper(int & count, const int base_x, const int base_y, const int max_x, const int max_y);
		void doubly_even();

		vector<vector<int> > square;	// Contains the magic square
		int size;						// Size of square
		int constant;					// Magic constant
};

#endif