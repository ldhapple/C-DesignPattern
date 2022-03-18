#include <iostream>
using namespace std;

class Product
{
public:
	virtual void print() = 0;
};

class Product1 : public Product
{
public:
	void print() override
	{
		cout << "Product 1" << endl;
	}
};

class Product2 : public Product
{
public:
	void print() override
	{
		cout << "Product 2" << endl;
	}
};

class Product3 : public Product
{
public:
	void print() override
	{
		cout << "Product 3" << endl;
	}
};

class Product4 : public Product
{
public:
	void print() override
	{
		cout << "Product 4" << endl;
	}
};

class Creator
{
protected:
	virtual Product* factoryMethod() = 0;
public:
	Product* operation()
	{
		return factoryMethod();
	}
};

class Create1 : public Creator
{
public:
	Product* factoryMethod() override
	{
		return new Product1;
	}
};

class Create2 : public Creator
{
public:
	Product* factoryMethod() override
	{
		return new Product2;
	}
};

class Create3 : public Creator
{
public:
	Product* factoryMethod() override
	{
		return new Product3;
	}
};

class Create4 : public Creator
{
public:
	Product* factoryMethod() override
	{
		return new Product4;
	}
};

int main()
{
	Creator* factory1 = new Create1();
	Creator* factory2 = new Create2();
	Creator* factory3 = new Create3();
	Creator* factory4 = new Create4();

	Product* product = factory1->operation();
	product->print();
	product = factory2->operation();
	product->print();
	product = factory3->operation();
	product->print();
	product = factory4->operation();
	product->print();
	delete product;
	system("pause");
}