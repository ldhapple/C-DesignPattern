#pragma once
#include "Monster.h"
#include "Iterator.h"

class Iterator;

class Aggregate
{
public:
	Aggregate()
	{
	}

	void AddMonster(Monster* mon);
	int getLength();
	Monster* getMonster(int _index);
	Iterator* iterator();
	
private:
	int last = 0;
	Monster * monsters[];

};