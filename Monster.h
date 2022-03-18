#pragma once
#include <string>
#include <iostream>
using namespace std;
class Monster
{
public:
	Monster(string _name, int _hp)
	{
		name = _name;
		hp = _hp;
	}

	void PrintData();

private:
	string name;
	int hp;
};