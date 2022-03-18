#include <iostream>
#include <string>
using namespace std;

class Ceo;
class Alba;

class CeoBuilder
{
public:
	virtual void ConstructWorkTime(Ceo* ceo) = 0;
	virtual void ConstructSalary(Ceo* ceo) = 0;
	virtual void ConstructName(Ceo* ceo) = 0;
};

class AlbaBuilder
{
public:
	virtual void ConstructWorkTime(Alba* alba) = 0;
	virtual void ConstructSalary(Alba* alba) = 0;
	virtual void ConstructName(Alba* alba) = 0;
};

class Worker
{
public:
	virtual void ShowInfo() = 0;
	virtual void ConstructWorker() = 0;
	virtual void Show() {}
};

class Ceo : public Worker
{
private:
	Ceo* return_ceo;
protected:
	int workTime;
	int salary;
	string name;
	CeoBuilder* _builder;

public:
	virtual void ShowInfo() override
	{
	}

	virtual void SetSalary(int _salary)
	{
		salary = _salary;
	}

	virtual void SetWorkTime(int _workTime)
	{
		workTime = _workTime;
	}
	
	virtual void SetName(string _name)
	{
		name = _name;
	}

	virtual void SetCeoBuilder(CeoBuilder* _ceoBuilder)
	{
		_builder = _ceoBuilder;
	}
	
	virtual Ceo* GetCeo() = 0;
	
};

class PizzaCeo : public Ceo
{
private:
	PizzaCeo* return_ceo;

public:

	virtual void ShowInfo() override
	{
		cout << "직종: " << name << endl;
		cout << "월급: " << salary << endl;
		cout << "근무시간: " << workTime << endl;
	}

	void Show()
	{
		cout << "Test?" << name;
	}

	virtual void ConstructWorker() override
	{
		return_ceo = new PizzaCeo();
		_builder->ConstructWorkTime(return_ceo);
		_builder->ConstructSalary(return_ceo);
		_builder->ConstructName(return_ceo);
	}
	virtual PizzaCeo* GetCeo()
	{
		return return_ceo;
	}

};

class SaladCeo : public Ceo
{
private:
	SaladCeo* return_ceo;
public:
	virtual void ShowInfo() override
	{
		cout << "직종: " << name << endl;
		cout << "월급: " << salary << endl;
		cout << "근무시간: " << workTime << endl;
	}

	virtual void ConstructWorker()
	{
		return_ceo = new SaladCeo();
		_builder->ConstructWorkTime(return_ceo);
		_builder->ConstructSalary(return_ceo);
		_builder->ConstructName(return_ceo);
	}

	virtual SaladCeo* GetCeo()
	{
		return return_ceo;
	}
};

class Alba : public Worker
{
private:
	Alba* return_alba;
protected:
	int workTime;
	int salary;
	string name;
	AlbaBuilder* _builder;

public:
	virtual void ShowInfo() override
	{

	}

	virtual void SetSalary(int _salary)
	{
		salary = _salary;
	}

	virtual void SetWorkTime(int _workTime)
	{
		workTime = _workTime;
	}

	virtual void SetName(string _name)
	{
		name = _name;
	}

	virtual void SetAlbaBuilder(AlbaBuilder* _albaBuilder)
	{
		_builder = _albaBuilder;
	}

	virtual Alba* GetAlba() = 0;
};

class PizzaAlba : public Alba
{
private:
	PizzaAlba* return_alba;

public:
	virtual void ShowInfo() override
	{
		cout << "직종: " << name << endl;
		cout << "월급: " << salary << endl;
		cout << "근무시간: " << workTime << endl;
	}

	virtual void ConstructWorker() override
	{
		return_alba = new PizzaAlba();
		_builder->ConstructWorkTime(return_alba);
		_builder->ConstructSalary(return_alba);
		_builder->ConstructName(return_alba);
	}
	virtual PizzaAlba* GetAlba()
	{
		return return_alba;
	}


};

class SaladAlba : public Alba
{
private:
	SaladAlba* return_alba;

public:
	virtual void ShowInfo() override
	{
		cout << "직종: " << name << endl;
		cout << "월급: " << salary << endl;
		cout << "근무시간: " << workTime << endl;
	}

	virtual void ConstructWorker() override
	{
		return_alba = new SaladAlba();
		_builder->ConstructWorkTime(return_alba);
		_builder->ConstructSalary(return_alba);
		_builder->ConstructName(return_alba);
	}
	virtual SaladAlba* GetAlba()
	{
		return return_alba;
	}
};

class Factory
{
public:
	virtual Worker* CreatePizzaWorker() = 0;
	virtual Worker* CreateSaladWorker() = 0;
};


class CeoFactory : public Factory
{
public:
	virtual Ceo* CreatePizzaWorker() override
	{
		return new PizzaCeo;
	}

	virtual Ceo* CreateSaladWorker() override
	{
		return new SaladCeo;
	}
};

class AlbaFactory : public Factory
{
public:
	virtual Alba* CreatePizzaWorker() override
	{
		return new PizzaAlba;
	}

	virtual Alba* CreateSaladWorker() override
	{
		return new SaladAlba;
	}
};


class PizzaCeoBuilder : public CeoBuilder
{
private:
	int workTime = 5;
	int salary = 7000000;
	string name = "PizzaCeo";

public:
	virtual void ConstructWorkTime(Ceo* _pizzaCeo) override
	{
		_pizzaCeo->SetWorkTime(workTime);
	}

	virtual void ConstructSalary(Ceo* _pizzaCeo) override
	{
		_pizzaCeo->SetSalary(salary);
	}

	virtual void ConstructName(Ceo* _pizzaCeo) override
	{
		_pizzaCeo->SetName(name);
	}

};

class SaladCeoBuilder : public CeoBuilder
{
private:
	int workTime = 7;
	int salary = 4500000;
	string name = "SaladCeo";

public:
	virtual void ConstructWorkTime(Ceo* _pizzaCeo) override
	{
		_pizzaCeo->SetWorkTime(workTime);
	}

	virtual void ConstructSalary(Ceo* _pizzaCeo) override
	{
		_pizzaCeo->SetSalary(salary);
	}

	virtual void ConstructName(Ceo* _pizzaCeo) override
	{
		_pizzaCeo->SetName(name);
	}

};


class PizzaAlbaBuilder : public AlbaBuilder
{
private:
	int workTime = 10;
	int salary = 1700000;
	string name = "PizzaAlba";

public:
	virtual void ConstructWorkTime(Alba* _pizzaAlba) override
	{
		_pizzaAlba->SetWorkTime(workTime);
	}

	virtual void ConstructSalary(Alba* _pizzaAlba) override
	{
		_pizzaAlba->SetSalary(salary);
	}

	virtual void ConstructName(Alba* _pizzaAlba) override
	{
		_pizzaAlba->SetName(name);
	}
	
};

class SaladAlbaBuilder : public AlbaBuilder
{
private:
	int workTime = 8;
	int salary = 1250000;
	string name = "SaladAlba";

public:
	virtual void ConstructWorkTime(Alba* _saladAlba) override
	{
		_saladAlba->SetWorkTime(workTime);
	}

	virtual void ConstructSalary(Alba* _saladAlba) override
	{
		_saladAlba->SetSalary(salary);
	}

	virtual void ConstructName(Alba* _saladAlba) override
	{
		_saladAlba->SetName(name);
	}

};


int main()
{
	Factory* ceoFac = new CeoFactory();
	Worker* saladCeo = ceoFac->CreateSaladWorker();
	Worker* pizzaCeo = ceoFac->CreatePizzaWorker();

	Factory* albaFac = new AlbaFactory();
	Worker* pizzaAlba = albaFac->CreatePizzaWorker();
	Worker* saladAlba = albaFac->CreateSaladWorker();


	Ceo* ceo = new PizzaCeo();
	PizzaCeoBuilder * pizzaCeoBuilder = new PizzaCeoBuilder();
	ceo->SetCeoBuilder(pizzaCeoBuilder);
	ceo->ConstructWorker();
	pizzaCeo = ceo->GetCeo();
	pizzaCeo->ShowInfo(); //Ceo의 ShowInfo()->PizzaCeo의 ShowInfo() OK
	cout << endl;

	SaladAlbaBuilder * saladAlbaBuilder = new SaladAlbaBuilder();
	Alba* alba = new SaladAlba();
	alba->SetAlbaBuilder(saladAlbaBuilder);
	alba->ConstructWorker();
	saladAlba = alba->GetAlba();
	saladAlba->ShowInfo();


	system("pause");
}