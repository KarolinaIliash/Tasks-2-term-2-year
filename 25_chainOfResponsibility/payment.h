#pragma once

enum paymentType{
	Ordinary, Preferential, Country, International, Inner
};

class Payment {
	double sum;
	paymentType type;
public:
	Payment(double _sum, paymentType _type) : sum(_sum), type(_type){}
	void setSum(double _sum) { sum = _sum; }
	double getSum(){ return sum; }
	paymentType getType() { return type; }

	void make(double tax) { sum -= tax; }
};

