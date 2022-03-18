#include <iostream>
#include <string>
using namespace std;

class Message
{
private:
	string temp_msg;
public:
	virtual ~Message()
	{

	}

	virtual void show(string msg)
	{

	}

	virtual string getMsg()
	{
		return temp_msg;
	}
	
};

class BasicMessage : public Message
{
private:
	string first_msg;
public:
	virtual void show(string msg) override
	{
		first_msg = msg;
		cout << first_msg;
	}

	virtual string getMsg() override
	{
		return first_msg;
	}
};

class DecorateMessage : public Message
{
private:
	string sec_msg;
protected:
	Message * _baseMsg;
public:
	DecorateMessage(Message* base_msg)
	{
		_baseMsg = base_msg;
	}

	virtual void show(string temp_msg) override
	{
		sec_msg = temp_msg;
		cout << sec_msg;
		_baseMsg->show(_baseMsg->getMsg());
	}

	virtual string getMsg() override
	{
		return sec_msg;
	}
};


class SecDecorateMessage : public DecorateMessage
{
private:
	string third_msg;


	void showMessage(string temp_msg)
	{
		third_msg = temp_msg;
		cout << third_msg;
	}

protected:
	DecorateMessage * _decoMsg;

public:
	SecDecorateMessage(DecorateMessage* deco_msg) : DecorateMessage(deco_msg)
	{
		_decoMsg = deco_msg;
	}

	virtual void show(string temp_msg) override
	{
		DecorateMessage::show(_decoMsg->getMsg());
		showMessage(temp_msg);
	}

	virtual string getMsg() override
	{
		return third_msg;
	}
};


class PrintMessage : public Message
{
private:
	DecorateMessage* secM;

public:
	PrintMessage(DecorateMessage* sec_msg) 
	{
		secM = sec_msg;
	}

	void printMessage()
	{
		secM->show(secM->getMsg());
	}

};

int main()
{
	Message* msg = new BasicMessage();
	msg->show("저는 ");
	cout << endl;

	DecorateMessage* decoMsg = new DecorateMessage(msg);
	decoMsg->show("안녕하세요 ");
	cout << endl;

	DecorateMessage* thirdmsg = new SecDecorateMessage(decoMsg);
	thirdmsg->show("이도현입니다.");
	cout << endl;

	PrintMessage* printer = new PrintMessage(thirdmsg);
	printer->printMessage();
}