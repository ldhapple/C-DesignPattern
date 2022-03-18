#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AiTier
{
public:
	virtual string changeTier() const = 0;
};

class AiTier1 : public AiTier
{
public:
	virtual string changeTier() const override
	{
		return "AITeir1";
	}
};

class AiTier2 : public AiTier
{
public:
	virtual string changeTier() const override
	{
		return "AITeir2";
	}
};

class Monster
{
public:
	Monster(const AiTier& _ai_tier) : ai_tier(_ai_tier) {}
	void Attack()
	{
		cout << ai_tier.changeTier() << "ATTACK!" << endl;
	}
	
protected:
	const AiTier& ai_tier;
};

int main()
{
	vector<Monster> monsters
	{ Monster{AiTier1{}}, Monster{AiTier2{}} };

	for (auto& monster : monsters)
	{
		monster.Attack();
	}

	int tier;
	cout << "Monster의 티어를 입력하세요" << endl;
	cin >> tier;

	Monster* monster2;
	switch (tier)
	{
	case 1:
		monster2 = new Monster{ AiTier1{} };
		monster2->Attack();
		break;

	case 2:
		monster2 = new Monster{ AiTier2{} };
		monster2->Attack();
		break;
	}
}