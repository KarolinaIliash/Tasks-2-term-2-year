#pragma once
#pragma once
#include<string>

class Singleton
{
	std::string s = "";
private:
	static Singleton* instance;
	// Конструкторы и оператор присваивания недоступны клиентам
	Singleton() { s = "I'm an existing singleton"; }
	Singleton(const Singleton&);
	Singleton& operator=(Singleton&);
public:
	static Singleton* getInstance();
	std::string GetS() { return s; }
};