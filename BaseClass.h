#ifndef BASECLASS_H
#define BASECLASS_H

#include <ostream>
#include <list>
#include <istream>
#include "Property.h"

#define SAVE virtual void RegMembers(std::list<AbstractProperty*> &props) {
#define ENDSAVE }
#define REG_MEMBER(T,V) props.push_back(new Property<T>(&V))

class BaseClass
{
public:
	BaseClass(void) {};

	void save(std::ostream &out)
	{
		std::list<AbstractProperty*> props;
		RegMembers(props);
		for(AbstractProperty* i : props)
		{
			out << i;
			delete i;
			i = nullptr;
		}
	}

	void load(std::istream &in)
	{
		std::list<AbstractProperty*> props;
		RegMembers(props);
		for(AbstractProperty* i : props)
		{
			in >> i;
			delete i;
			i = nullptr;
		}
	}

	virtual void RegMembers(std::list<AbstractProperty*> &props) = 0;
};

#endif