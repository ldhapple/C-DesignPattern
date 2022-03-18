#include "Aggregate.h"

void Aggregate::AddMonster(Monster* mon)
{
	monsters[last] = mon;
	last++;
}

int Aggregate::getLength()
{
	return last;
}

Monster* Aggregate::getMonster(int _index)
{
	return monsters[_index];
}

Iterator* Aggregate::iterator()
{
	return new Iterator(this);
}