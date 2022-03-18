#include <iostream>

using namespace std;

class Npc
{
public:
	int hp;
	string name;

	Npc()
	{
		hp = 0;
		name = "";
	}

	virtual ~Npc() {}
};

class NpcKnight : public Npc
{

};

class NpcMiner : public Npc
{

};

class IAdapter
{
public:
	virtual void SetDamage() = 0;
};

class AdaptNpc : public IAdapter, public Npc
{
public:
	int damage;
	virtual void SetDamage() override;
};

void AdaptNpc::SetDamage()
{
	damage = 2;
}

class AdaptNpcKnight : public IAdapter, public AdaptNpc
{
public:
	int damage;
	virtual void SetDamage() override;
};

void AdaptNpcKnight::SetDamage()
{
	damage = 10;
}

class AdaptNpcMiner : public IAdapter, public AdaptNpc
{
public:
	int damage;
	virtual void SetDamage() override;
};

void AdaptNpcMiner::SetDamage()
{
	damage = 1;
}

class INpcGroupControl
{
public:
	virtual void addNpcData(int hp, int damage) = 0;
};

class NpcGroup : public INpcGroupControl
{
private:
	int _totalHp;
	int _totalDamage;

public:
	NpcGroup()
	{
		_totalHp = 0;
		_totalDamage = 0;
	}

	~NpcGroup()
	{
		_totalHp = 0;
		_totalDamage = 0;
	}

	virtual void addNpcData(int hp, int damage) override;
};

void NpcGroup::addNpcData(int hp, int damage)
{
	_totalHp += hp;
	_totalDamage += damage;
}

class ProxyNpcGroup : public INpcGroupControl, public NpcGroup
{
private:
	NpcGroup * tempNg = new NpcGroup();
	int _tempHp;
	int _tempDamage;

public:
	ProxyNpcGroup()
	{
		_tempHp = 0;
		_tempDamage = 0;
	}

	~ProxyNpcGroup()
	{
		_tempHp = 0;
		_tempDamage = 0;
		delete tempNg;
	}

	virtual void addNpcData(int hp, int damage) override;
	void apply();
};

void ProxyNpcGroup::addNpcData(int hp, int damage)
{
	_tempHp += hp;
	_tempDamage += damage;
}

void ProxyNpcGroup::apply()
{
	tempNg->addNpcData(_tempHp, _tempDamage);
}

class NpcFactory
{
public:

	AdaptNpc* CreateAdaptNpc()
	{
		return new AdaptNpc;
	}

	AdaptNpc* CreateAdaptKnight()
	{
		return new AdaptNpcKnight;
	}

	AdaptNpc* CreateAdaptMiner()
	{
		return new AdaptNpcMiner;
	}
};

int main()
{
	//조건1,3
	NpcGroup* ng = new NpcGroup();
	AdaptNpc* npc = new AdaptNpc();
	npc->SetDamage();
	ng->addNpcData(npc->hp, npc->damage);
	


	//조건4
	ProxyNpcGroup* pNg = new ProxyNpcGroup();
	pNg->addNpcData(10, 4);
	pNg->addNpcData(20, 3);
	pNg->apply();
	delete pNg;


	//조건5
	NpcFactory* npcFac = new NpcFactory();
	AdaptNpc* npc2 = npcFac->CreateAdaptNpc();
	npc2->SetDamage();
	AdaptNpc* npc3 = npcFac->CreateAdaptKnight();
	npc3->SetDamage();

	ng->addNpcData(npc2->hp, npc3->damage);
	
	
	



}