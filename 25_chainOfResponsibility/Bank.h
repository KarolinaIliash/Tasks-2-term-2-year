#pragma once
#include"payment.h"
#include <string>


class Action {
protected:
	Action* next = nullptr;
public:
	void setNext(Action* _next);
	void add(Action* _next);
	virtual std::string handle(Payment* p);
};

class Fix : public Action {
public:
	std::string handle(Payment* p) override;
};

class BankTax : public Action {
	int percent = 5;
public:
	std::string handle(Payment* p) override;
};

class CountryTax : public Action {
	int percent = 3;
public:
	std::string handle(Payment* p) override;
};

class Bank {
	Action* start;
public:
	Bank();
	std::string make(Payment* p);
};