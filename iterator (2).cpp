#include "Monster.h"
#include "Aggregate.h"
#include "Iterator.h"

int main()
{
	Aggregate* container = new Aggregate();
	Monster* mon1 = new Monster("������", 10);
	Monster* mon2 = new Monster("�䳢", 5);
	container->AddMonster(mon1);
	container->AddMonster(mon2);

	Iterator* iter = container->iterator();
	while (container->iterator()->HasNext())
	{
		iter->Next();
	}

	system("pause");
}