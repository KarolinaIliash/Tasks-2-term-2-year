#include "singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance() {
	if (!instance)
		instance = new Singleton();
	return instance;
}