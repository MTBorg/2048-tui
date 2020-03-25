#include "square.h"
#include "constants.h"
#include <string>

Square::Square(int x, int y, int value): m_value(value){
	m_window = newwin(SQUARE_SIZE, SQUARE_SIZE, y, x);
	box(m_window, 0, 0);
}

Square& Square::operator=(Square&& s){
	this->m_window = s.m_window;
	this->m_value = s.m_value;
	s.m_window = nullptr;

	return *this;
}

void Square::draw() const{
	werase(m_window);
	box(m_window, 0, 0);
	mvwprintw(m_window, SQUARE_SIZE / 2, SQUARE_SIZE / 2, m_value == 0 ? "    " : std::to_string(m_value).c_str());
	wrefresh(m_window);
}

Square::~Square(){
	if(m_window != nullptr)
		delwin(m_window);
}
