#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component
{
public:
	virtual void list() const = 0;
	virtual ~Component() {}
	virtual void printName() {}
	virtual string getType()
	{
		return type;
	}

protected:
	string type;
};

class File : public Component
{
public:
	File(string _name, string _data) : name(_name), data(_data) {}

	~File()
	{
	}

	virtual void list() const
	{
		cout << "������: " << data << endl;
	}

	virtual void printName() override
	{
		cout << "�����̸�: " << name << endl;
	}


private:
	string data = "";
	string name = "";
	string type = "file";
};

class Directory : public Component
{
public:
	Directory(string _name) : name(_name)
	{
		list_ = new vector<Component*>();
	}

	~Directory()
	{
		for (vector<Component*>::const_iterator iter = list_->begin(); iter != list_->end(); ++iter)
		{
			delete (*iter);
		}

		list_->clear();

		delete list_;
	}

	bool operator==(Component* com)
	{
		if (this->getType() == com->getType())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void add(Component* obj)
	{
		list_->push_back(obj);
	}

	virtual void list() const
	{
		cout << name << ":" << endl;
		for (vector<Component*>::const_iterator iter = list_->begin(); iter != list_->end(); ++iter)
		{
			if ((*iter) == this)
			{
				(*iter)->list();
			}
			else
			{
				(*iter)->printName();
				if ((*iter + 1) == this)
				{
					(*iter + 1)->list();
				}

			}

		}
	}

private:
	vector<Component*>* list_;
	string name;
	string type = "directory";
};

int main()
{
	File* file1 = new File("����1", "��������");
	File* file2 = new File("����2", "�޹���");
	File* file3 = new File("����3", "������");

	Directory* directory1 = new Directory("Directory1");
	Directory* directory2 = new Directory("Directory2");

	directory1->add(file1);
	directory1->add(file3);
	directory2->add(file2);
	directory2->add(file3);
	directory1->add(directory2);

	directory1->list();

	cout << "file1->list()= ";
	file1->list();

	delete directory1;
}
