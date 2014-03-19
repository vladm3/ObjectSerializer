#ifndef POINT_H
#define POINT_H

#include "BaseClass.h"

class Point: public BaseClass
{
public:
	Point(int x=0, float y=0)
	{
		m_x = x;
		m_y = y;
	}

	int m_x;
	float m_y;

	SAVE {
		REG_MEMBER(int, m_x);
		REG_MEMBER(float, m_y);
	} ENDSAVE
};

#endif