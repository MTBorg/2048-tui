#ifndef BOARD_H
#define BOARD_H 

#include <array>

#include "square.h"
#include "constants.h"

class Board
{
public:
	Board ();
	void draw() const;
	void swipeLeft();
	void swipeRight();
	void swipeUp();
	void swipeDown();
	void insertRandom();

private:
	std::array<std::array<Square, BOARD_SIZE>, BOARD_SIZE> m_squares;
};

#endif /* ifndef BOARD_H */
