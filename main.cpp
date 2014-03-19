#include "Point.h"
#include <fstream>
#include <iostream>

int main()
{
	Point p(5,6.65);
	std::fstream f("test.txt", std::fstream::out);

	std::cout << "BEFORE SAVE: " << p.m_x << ";" << p.m_y << std::endl;

	p.save(f);
	f.close();

	p.m_x = p.m_y = 0;
	std::cout << "DATA CHANGED. NOW COORDINATES ARE: " << p.m_x << ";" << p.m_y << std::endl;

	f.open("test.txt", std::fstream::in);
	p.load(f);

	std::cout << "AFTER LOAD: " << p.m_x << ";" << p.m_y << std::endl;
}