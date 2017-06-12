#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Observer {
public:
	virtual void Update(string) = 0;
	virtual bool is_interested(string) = 0;
	virtual vector<string> get_mags() = 0;
};

class Client1 : public Observer {
private:
	vector<string> getting_mag;
	vector<string> interests;
public:
	Client1(vector<string> inter) {
		interests.resize(inter.size());
		interests = inter;
	}
	vector<string> get_mags() override{
		return getting_mag;
	}
	bool is_interested(string mag) override {
		for (int i = 0; i < interests.size(); i++)
			if (mag == interests[i]) return 1;
		return 0;
	}
	void Update(string mag) override {
		if (is_interested(mag))
			getting_mag.push_back(mag);
	}
};

class Client2 : public Observer {
private:
	vector<string> getting_mag;
	vector<string> interests;
public:
	Client2(vector<string> inter) {
		interests.resize(inter.size());
		interests = inter;
	}
	vector<string> get_mags() override {
		return getting_mag;
	}
	bool is_interested(string mag) override {
		for (int i = 0; i < interests.size(); i++)
			if (mag == interests[i]) return 1;
		return 0;
	}
	void Update(string mag) override {
		if (is_interested(mag))
			getting_mag.push_back(mag);
	}
};

class Subject {//post
private:
	string cur_magaz;
	vector<Observer*> observers;
public:
	Subject() {
		cur_magaz = "";
	}
	void Attach(Observer* obs) {
		for (int i = 0; i < observers.size(); i++)
			if (obs == observers[i]) return;
		observers.push_back(obs);
	};
	void Detach(Observer*obs) {
		for (int i = 0; i < observers.size(); i++)
			if (obs == observers[i]) {
				observers.erase(observers.begin() + i);
				return;
			}
	};
	void Notify() {
		for (int i = 0; i < observers.size(); i++)
			observers[i]->Update(cur_magaz);
	};
	void Add_magaz(string mag) {
		cur_magaz = mag;
		Notify();
	}
	vector<Observer*> get_obs() {
		return observers;
	}
};