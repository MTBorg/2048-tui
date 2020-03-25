#ifndef SQUARE_H
#define SQUARE_H

#include <ncurses.h>

class Square
{
public:
	Square():m_window(nullptr), m_value(0){}
	Square(int x, int y, int value);
	Square& operator=(Square&& s);
	void draw() const;
	inline void setValue(int value){m_value = value;}
	inline int getValue() const{return m_value;}
	inline void operator*=(int n){m_value *= 2;}

	virtual ~Square();

private:
	WINDOW* m_window;
	int m_value;
};

#endif /* ifndef SQUARE_H */
