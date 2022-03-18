#include <iostream>
using namespace std;

class Interface
{
public:
	void virtual operation() = 0;
};

class Adaptee
{
private:
	int num;

public:
	Adaptee();
	virtual ~Adaptee();
	void specificOperation();

};

Adaptee::Adaptee() {}
Adaptee::~Adaptee()
{
	cout << "Adaptee ¼Ò¸ê \n";
}

void Adaptee::specificOperation()
{
	num = 10;
	cout << num << "\n";
}

class Adapter : public Interface
{
private:
	Adaptee instance;
public:
	void virtual operation()
	{
		instance.specificOperation();
	}
};


class Adapter2 : public Interface, public Adaptee
{
public:
	void virtual operation()
	{
		specificOperation();
	}
};

void main()
{
	Interface *adapter = new Adapter();
	adapter->operation();

	Interface *adapter2 = new Adapter2();
	adapter2->operation();

	system("pause");
	delete adapter;
	delete adapter2;
}
