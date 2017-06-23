#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include <vector>

#include "pool.h"

int foo(int a, int b) {
	return a * b;
}

int be(int a, int b) {
	return a+b;
}

TEST_CASE("pool") {
	SECTION("2 times") {
		ThreadPool pool(4);
		auto result1 = pool.enqueue(be, 1, 2);
		auto result2 = pool.enqueue(foo, 1, 2);

		REQUIRE(result1.get() == 3);
		REQUIRE(result2.get() == 2);
	}
	SECTION("more") {
		ThreadPool pool(4);
		std::vector<std::future<int>> results;
		for (int i = 0; i < 8; i++) {
			results.emplace_back(pool.enqueue(foo, 1, i));
		}
		std::vector<int> get(8);
		std::vector<int> expected(8);
		for (int i = 0; i < 8; i++) {
			get[i] = results[i].get();
			expected[i] = i;
		}
		REQUIRE(get == expected);
	}
}