#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include<thread>
#include<vector>
#include<iostream>
#include"semaphore.h"

void add(int i, std::vector<int>& v, Semaphore &s) {
	s.wait();
	v.push_back(i);
	s.signal();
}

TEST_CASE("Semaphore") {
	int threadnum = 10;
	std::vector<std::thread> threads(threadnum);
	std::vector<int> result(0);
	Semaphore sem(threadnum);
	for (int i = 0; i < threadnum; i++) {
		threads[i] = std::thread(add, i, std::ref(result), std::ref(sem));
		threads[i].join();
	}
	std::vector<int> expected(threadnum);
	for (int i = 0; i < threadnum; i++) {
		expected[i] = i;
	}
	
	REQUIRE(result == expected);
}