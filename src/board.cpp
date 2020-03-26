#include "board.h"
#include <ctime>
#include <cstdlib>

Board::Board(){
	for (int x = 0; x < BOARD_SIZE; ++x) {
		for (int y = 0; y < BOARD_SIZE; ++y) {
			m_squares[x][y] = Square(x * SQUARE_SIZE, y * SQUARE_SIZE, 0);
		}
	}

	//Randomly select two squares to hold initial values
	std::srand(std::time(nullptr));
	int x1 = std::rand() % BOARD_SIZE,
			x2 = std::rand() % BOARD_SIZE,
			y1 = std::rand() % BOARD_SIZE,
			y2 = std::rand() % BOARD_SIZE;
	m_squares[x1][y1].setValue(2);
	m_squares[x2][y2].setValue(2);
}

void Board::draw() const{
	for (const auto& col : m_squares) {
		for (const auto& square : col) {
			square.draw();
		}
	}
}

void Board::swipeLeft(){
	//Combine values
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 0; x < BOARD_SIZE-1; ++x) {
			//Check if empty
			if(m_squares[x][y].getValue() == 0){
				continue;
			}
			for(int i = x + 1; i < BOARD_SIZE; ++i){
				if(m_squares[x][y].getValue() == m_squares[i][y].getValue()){
					m_squares[x][y] *= 2;
					m_squares[i][y].setValue(0);
					x = i+1;
					break;
				}
			}
		}
	}

	// Float values left
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = 1; x < BOARD_SIZE; ++x) {
			if(m_squares[x][y].getValue() != 0){
				for (int i = 0; i < x; ++i) {
					if(m_squares[i][y].getValue() == 0){
						m_squares[i][y].setValue(m_squares[x][y].getValue());
						m_squares[x][y].setValue(0); 
						break;
					}
				}
			}
		}
	}
}


void Board::swipeRight(){
	//Combine values
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = BOARD_SIZE-1; x >= 0; --x) {
			if(m_squares[x][y].getValue() == 0){
				continue;
			}
			for(int i = x - 1; i >= 0; i--){
				if(m_squares[x][y].getValue() == m_squares[i][y].getValue()){
					m_squares[x][y] *= 2;
					m_squares[i][y].setValue(0);
					x = i -1;
					break;
				}
			}
		}
	}

	// Float values right
	for (int y = 0; y < BOARD_SIZE; ++y) {
		for (int x = BOARD_SIZE - 2; x >= 0; --x) {
			if(m_squares[x][y].getValue() != 0){
				for (int i = BOARD_SIZE-1; i > x; --i) {
					if(m_squares[i][y].getValue() == 0){
						m_squares[i][y].setValue(m_squares[x][y].getValue());
						m_squares[x][y].setValue(0); 
						break;
					}
				}
			}
		}
	}
}

void Board::swipeUp(){
	//Combine values
	for (int x = 0; x < BOARD_SIZE; ++x) {
		for (int y = 0; y < BOARD_SIZE-1; ++y) {
			if(m_squares[x][y].getValue() == 0){
				continue;
			}

			for (int i = y+1; i < BOARD_SIZE; ++i) {
				if(m_squares[x][y].getValue() == m_squares[x][i].getValue()){
					m_squares[x][y] *= 2;
					m_squares[x][i].setValue(0);
					y = i + 1;
					break;
				}
			}
		}
	}

	// Float values up
	for (int x = 0; x < BOARD_SIZE; ++x) {
		for (int y = 1; y < BOARD_SIZE; ++y) {
			if(m_squares[x][y].getValue() != 0){
				for (int i = 0; i < y; ++i) {
					if(m_squares[x][i].getValue() == 0){
						m_squares[x][i].setValue(m_squares[x][y].getValue());
						m_squares[x][y].setValue(0); 
						break;
					}
				}
			}
		}
	}
}

void Board::swipeDown(){
	//Combine values
	for (int x = 0; x < BOARD_SIZE; ++x) {
		for (int y = BOARD_SIZE-1; y >= 0; --y) {
			if(m_squares[x][y].getValue() == 0){
				continue;
			}

			for (int i = y - 1; i >= 0; --i) {
				if(m_squares[x][y].getValue() == m_squares[x][i].getValue()){
					m_squares[x][y] *= 2;
					m_squares[x][i].setValue(0);
					y = i - 1;
					break;
				}
			}
		}
	}

	// Float values down
	for (int x = 0; x < BOARD_SIZE; ++x) {
		for (int y = BOARD_SIZE-2; y >= 0; --y) {
			if(m_squares[x][y].getValue() != 0){
				for (int i = BOARD_SIZE-1; i > y; --i) {
					if(m_squares[x][i].getValue() == 0){
						m_squares[x][i].setValue(m_squares[x][y].getValue());
						m_squares[x][y].setValue(0); 
						break;
					}
				}
			}
		}
	}
}

void Board::insertRandom(){
	std::srand(std::time(nullptr));
	int x, y;
	do{
		x = std::rand() % BOARD_SIZE;
		y = std::rand() % BOARD_SIZE;
	}while(m_squares[x][y].getValue() != 0);

	m_squares[x][y].setValue(2);
}

bool Board::hasWinningState() const{
	for(const auto& column: m_squares){
		for (const auto& square : column) {
			if(square.getValue() == 2048)
				return true;
		}
	}
	return false;
}
