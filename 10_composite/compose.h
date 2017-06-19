#pragma once
#include<string>
#include <stdexcept>

class Expression {
public:
	virtual double calculate() = 0;
};

class Constant : public Expression {
	double value;
public:
	Constant(double v) : value(v){}
	double calculate() override{ return value; }
};

class Add:public Expression {
	Expression* left;
	Expression* right;
public:
	Add(Expression* l, Expression* r) :left(l), right(r){}
	double calculate() { return left->calculate() + right->calculate(); }
};

class Subtract:public Expression {
	Expression* left;
	Expression* right;
public:
	Subtract(Expression* l, Expression* r) :left(l), right(r) {}
	double calculate() { return left->calculate() - right->calculate(); }
};

class Multiply :public Expression {
	Expression* left;
	Expression* right;
public:
	Multiply(Expression* l, Expression* r) :left(l), right(r) {}
	double calculate() { return left->calculate() * right->calculate(); }
};

class Divide :public Expression {
	Expression* left;
	Expression* right;
public:
	Divide(Expression* l, Expression* r) :left(l), right(r) {}
	double calculate() { return left->calculate() / right->calculate(); }
};

Expression* Parse(std::string s);

int GetPriority(char symb);

bool Run(std::string s, double& result);