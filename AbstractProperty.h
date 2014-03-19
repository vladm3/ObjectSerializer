#ifndef ABSTRACTPROPERTY_H
#define ABSTRACTPROPERTY_H

#include <ostream>
#include <istream>

class AbstractProperty
{
public:
	AbstractProperty() {};

	virtual ~AbstractProperty() {}

	virtual void write(std::ostream &out) = 0;

	virtual void read(std::istream &in) = 0;

	friend std::ostream &operator<<(std::ostream &out, AbstractProperty *a)
	{
		a->write(out);
		return out;
	}

	friend std::istream &operator>>(std::istream &in, AbstractProperty *a)
	{
		a->read(in);
		return in;
	}
};

#endif