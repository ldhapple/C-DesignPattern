#include "Iterator.h"

void Iterator::Next()
{
	aggregate->getMonster(index)->PrintData();
	index++;
}
bool Iterator::HasNext()
{
	if (index < aggregate->getLength())
	{
		return true;
	}

	else
	{
		return false;
	}
}