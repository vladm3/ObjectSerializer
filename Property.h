#ifndef PROPERTY_H
#define PROPERTY_H

#include "AbstractProperty.h"

template<typename T>
class Property : public AbstractProperty
{
private:
	T *val;

public:
	Property()
	{
		val = 0;
	}

	Property(T *a)
	{
		val = a;
	}

	virtual void write(std::ostream &out)
	{
		out.write((char*)val, sizeof(T));
	}

	virtual void read(std::istream &in)
	{
		in.read((char*)val, sizeof(T));
	}

	virtual ~Property()
	{
		val = nullptr;
	};
};

#endif