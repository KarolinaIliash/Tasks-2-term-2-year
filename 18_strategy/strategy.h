#pragma once
#include<string>

class Behaver {
public:
	virtual std::string Move() = 0;
};

class Fly:public Behaver {
	std::string Move() override{
		return "Flying";
	}
};

class Walk :public Behaver {
	std::string Move() override {
		return "Walking";
	}
};

class MagicFly :public Behaver {
	std::string Move() override {
		return "Magic";
	}
};


