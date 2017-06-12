#pragma once
#include<string>
#include<iostream>
using namespace std;



class Empty_Burger {
private:
	int cost;
	string order;
public:
	Empty_Burger() { cost = 0; order = "Basic"; }
	virtual int get_cost() { return cost; }
        virtual string get_order() { return order; }
};

class Bun : public Empty_Burger {//only bread, it's for free=) -- decorator
private:
	Empty_Burger* burger;
public:
	Bun(Empty_Burger* b) { burger = b; }
	virtual int get_cost() override {
		return burger->get_cost();
	}
	virtual string get_order() override {
		return burger->get_order();
	}
};


class Meat : public Bun {
private:
	int cost;
	//Empty_burger* burger
public:
	//Meat(Empty_Burger* b) { burger = b; }
	Meat(Empty_Burger* b) : Bun(b) { cost = 15; }
	virtual int get_cost() override {
		return Bun::get_cost() + cost;
	}
	virtual string get_order() override {
		return Bun::get_order() + " + meat";
	}
};

class Cheese : public Bun {
private:
	//Empty_Burger* burger;
	int cost;
public:
	Cheese(Empty_Burger* b) : Bun(b) { cost = 10; }
	virtual int get_cost() override {
		return Bun::get_cost() + cost;
	}
	virtual string get_order() override {
		return Bun::get_order() + " + cheese";
	}
};

class Salad : public Bun {
private:
	//Empty_Burger* burger;
	int cost;
public:
	Salad(Empty_Burger* b) : Bun(b) { cost = 5; }
	virtual int get_cost() override {
		return Bun::get_cost() + cost;
	}
	virtual string get_order() override {
		return Bun::get_order() + " + salad";
	}
};

class Tomato : public Bun {
private:
	//Empty_Burger* burger;
	int cost;
public:
	Tomato(Empty_Burger* b) :Bun(b) { cost = 5; }
	virtual int get_cost() override {
		return Bun::get_cost() + cost;
	}
	virtual string get_order() override {
		return Bun::get_order() + " + tomatoes";
	}
};

class Sauce : public Bun {
private:
	//Empty_Burger* burger;
	int cost;
public:
	Sauce(Empty_Burger* b) :Bun(b) { cost = 5; }
	virtual int get_cost() override {
		return Bun::get_cost() + cost;
	}
	virtual string get_order() override {
		return Bun::get_order() + " + sauce";
	}
};


class Check {
public:
	bool check_number(char* a);// checking numbers which was entered if it's integer > 0 or not
};
