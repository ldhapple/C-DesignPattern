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
		cout << "레벨업은 1번, 강화는 2번, 점수획득은 3번입니다" << endl;
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

		cout << "점수: " << _score << endl;
		cout << "레벨: " << _level << endl;
		cout << "강화: " << _reinforce << endl;

		if (_score >= 100)
		{
			cout << "업적1 달성!!" << endl;
		}

		if (_level >= 3)
		{
			cout << "업적2 달성!!" << endl;
		}

		if (_reinforce >= 10)
		{
			cout << "업적3 달성!!" << endl;
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