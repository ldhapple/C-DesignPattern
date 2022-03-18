#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component
{
public:
	virtual void list() const = 0;
	virtual ~Component() {}
};

class Data
{
public:
	Data(string _name, string _data) : name(_name), data(_data){}

	string getData()
	{
		return data;
	}

	string getName()
	{
		return name;
	}

private:
	string data = "";
	string name = "";
};

class File : public Component
{
public:
	File(Data* data) : data_(data) {}

	~File()
	{
		delete data_;
	}

	virtual void list() const
	{
		cout << "파일이름: " << data_->getName() << endl;
	}

private:
	Data* data_;
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

	void add(Component* obj)
	{
		list_->push_back(obj);
	}

	virtual void list() const
	{
		cout << name << ":" << endl;

		for (vector<Component*>::const_iterator iter = list_->begin(); iter != list_->end(); ++iter)
		{
			(*iter)->list();
		}
	}

private:
	vector<Component*>* list_;
	string name;
};

int main()
{
	Data* data1 = new Data("파일1", "딱따구리");
	Data* data2 = new Data("파일2", "앵무새");
	Data* data3 = new Data("파일3", "독수리");

	File* file1 = new File(data1);
	File* file2 = new File(data2);
	File* file3 = new File(data3);

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
