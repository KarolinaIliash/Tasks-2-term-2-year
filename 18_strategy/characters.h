#pragma once
#include"strategy.h"
#include<memory>

static std::shared_ptr<Behaver> walk;
static std::shared_ptr<Behaver> fly;
static std::shared_ptr<Behaver> magic;

class Character {
private:
	Behaver* movers;
	
public:
	
	Character() {
		if(walk == nullptr) walk = std::make_shared<Walk>();
		if(fly == nullptr) fly = std::make_shared<Fly>();
		if(magic == nullptr) magic = std::make_shared<MagicFly>();
	}
	virtual std::string Walking() = 0;
	virtual std::string Flying() = 0;
	virtual std::string MagicFlying() = 0;
};

class Orc :public Character {
private:
	std::shared_ptr<Behaver> mover;
public:
	std::string Walking() override {
		mover = walk;
		return mover->Move();
	}
	std::string Flying() override {
		return "I can't fly";
	}
	std::string MagicFlying() override {
		mover = magic;
		return mover->Move();
	}
};

class Elf :public Character {
private:
	std::shared_ptr<Behaver> mover;
public:
	std::string Walking() override {
		mover = walk;
		return mover->Move();
	}
	std::string Flying() override {
		return "I can't fly";
	}
	std::string MagicFlying() override {
		mover = magic;
		return mover->Move();
	}
};


class Pegas :public Character {
private:
	std::shared_ptr<Behaver> mover;
public:
	std::string Walking() override {
		mover = walk;
		return mover->Move();
	}
	std::string Flying() override {
		mover = fly;
		return mover->Move();
	}
	std::string MagicFlying() override {
		mover = magic;
		return mover->Move();
	}
};

class Harpy:public Character {
private:
	std::shared_ptr<Behaver> mover;
public:
	std::string Walking() override {
		mover = walk;
		return mover->Move();
	}
	std::string Flying() override {
		mover = fly;
		return mover->Move();
	}
	std::string MagicFlying() override {
		mover = magic;
		return mover->Move();
	}
};
