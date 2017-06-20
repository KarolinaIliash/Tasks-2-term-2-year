#pragma once
#include<iostream>
#include<string>
#include<vector>

class Participant;

class Chat {
	std::vector<Participant*> parts;
public:
	void Send(std::string message, Participant* from);
	void AddParticipant(Participant* p);
};


class Participant {
	Chat* mediator;
protected:
	std::string lastMessage = "";
public:
	Participant(Chat* _m) :mediator(_m) { mediator->AddParticipant(this); }
	virtual void Send(std::string message) {
		mediator->Send(message, this);
	};
	virtual void Receive(std::string message, Participant* from) = 0;
	std::string GetLastMessage() { return lastMessage; }
	virtual std::string GetName() = 0;
};

class Human: public Participant {
	std::string name;
public:
	Human(Chat*m, std::string _name):Participant(m), name(_name){}
	void Receive(std::string message, Participant* from) override {
		lastMessage = "I'm human " + name + " and I received a message: " + message + " from " + from->GetName();
	}
	std::string GetName() { return name; }
};

class Bot : public Participant {
public:
	Bot(Chat*m) :Participant(m) {}
	void Receive(std::string message, Participant* from) override {
		lastMessage = "I'm bot and I received a message: " + message + " from " + from->GetName();
	}
	std::string GetName() { return "bot"; }
};


