#include <iostream>
#include <vector>
using namespace std;

class Subject;

class Observer
{
public:
	virtual ~Observer() {}
	virtual void update(Subject&) {}
};

class Subject
{
public:
	virtual ~Subject() {}
	void AddObserver(Observer& ob)
	{
		observe_ui.push_back(&ob);
	}
	void RemoveObserver()
	{
		observe_ui.clear();
	}

	void NotifyObservers()
	{
		for (auto* o : observe_ui)
		{
			o->update(*this);
		}
	}

private:
	vector<Observer*> observe_ui;
};



class Player : public Subject
{
private:
	int score;
	int level;
	int reinforce;
	
public:
	void SetValue()
	{
		int val;
		cout << "�������� 1��, ��ȭ�� 2��, ����ȹ���� 3���Դϴ�" << endl;
		cin >> val;
		switch (val)
		{
		case 1:
			LevelUp();
			this->NotifyObservers();
			break;

		case 2:
			Reinforce();
			this->NotifyObservers();
			break;

		case 3:
			AddScore();
			this->NotifyObservers();
			break;
		}
	}

	void LevelUp() { level += 2; }
	void Reinforce() { reinforce += 5; }
	void AddScore() { score += 50; }

	int GetLevel() { return level; }
	int GetReinforce() { return reinforce; }
	int GetScore() { return score; }
};

class UI : public Observer
{
private:
	Player& _player;
public:
	 UI(Player& p) : _player(p){ _player.AddObserver(*this); }
	~UI() { _player.RemoveObserver(); }

	void update(Player& player)
	{
		_player = player;
	}

	void notify()
	{
		int _score;
		int _level;
		int _reinforce;
		_score = _player.GetScore();
		_level = _player.GetLevel();
		_reinforce = _player.GetReinforce();

		cout << "����: " << _score << endl;
		cout << "����: " << _level << endl;
		cout << "��ȭ: " << _reinforce << endl;

		if (_score >= 100)
		{
			cout << "����1 �޼�!!" << endl;
		}

		if (_level >= 3)
		{
			cout << "����2 �޼�!!" << endl;
		}

		if (_reinforce >= 10)
		{
			cout << "����3 �޼�!!" << endl;
		}
	}
};

int main()
{
	Player player;

	UI* ui = new UI(player);
	
	while (1)
	{
		player.SetValue();
		ui->notify();
	}
	

	system("pause");
}