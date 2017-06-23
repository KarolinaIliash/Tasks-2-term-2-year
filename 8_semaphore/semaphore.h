#pragma once
#include<mutex>
#include<condition_variable>

class Semaphore {
	std::mutex mtx;
	std::condition_variable cv;
	int count = 0;
public:
	Semaphore(int _count): count(_count) {}
	void wait();
	void signal();
};