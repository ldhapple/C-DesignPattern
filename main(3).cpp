#include <iostream>
#include <map>
using namespace std;

class Box
{
public:
	virtual void Open() = 0;
};

class ABox : public Box
{
public:
	void Open() override
	{
		cout << "ABox Open" << endl;
	}
};

class BBox : public Box
{
public:
	void Open() override
	{
		cout << "BBox Open" << endl;
	}
};

class CBox : public Box
{
public:
	void Open() override
	{
		cout << "CBox Open" << endl;
	}
};

class DBox : public Box
{
public:
	void Open() override
	{
		cout << "DBox Open" << endl;
	}
};

class Factory
{
protected:
	virtual Box* Create(char Box) = 0;
public:
	Box* CreateBox(char Box)
	{
		return Create(Box);
	}
};


class BoxFactory : public Factory
{
public:
	Box* Create(char Box) override
	{
		switch (Box)
		{
		case 'A':
			return new ABox;
			break;

		case 'B':
			return new BBox;
			break;

		case 'C':
			return new CBox;
			break;

		case 'D':
			return new DBox;
			break;
		}
	}
};


int main()
{
	Factory* bf = new BoxFactory();
	Box* newBox = bf->CreateBox('A');
	newBox->Open();
	newBox = bf->CreateBox('B');
	newBox->Open();

	system("pause");
}