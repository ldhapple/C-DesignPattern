#pragma once
#include "Aggregate.h"

class Aggregate;

class Iterator
{
public:
	Iterator(Aggregate* _aggregate)
	{
		aggregate = _aggregate;
	}
	void Next();
	bool HasNext();


private:
	Aggregate * aggregate;
	int index = 0;
};