#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"list.h"
#include"CycledList.h"
#include"doubleCycledList.h"
#include"doubleSidedList.h"

TEST_CASE("List_Test") {
	List<int> l1{0, 5, 6};
	List<int> l2;
	REQUIRE(l1.isEmpty() == false);
	REQUIRE(l2.isEmpty() == true);
	REQUIRE(l1.head() == 0);
	REQUIRE (!(l1.begin() == l1.end()));
	l2.push_start(3);
	REQUIRE(l2.head() == 3);
	l2.push_start(0);
	REQUIRE(l2.head() == 0);
	l2.pop_start();
	REQUIRE(l2.head() == 3);
	l2.pop_start();
	REQUIRE(l2.isEmpty());
	REQUIRE_THROWS_AS(l2.pop_start(), std::out_of_range);
}

TEST_CASE("DoubleSidedList_Test") {
	DoubleSidedList<int> l1;
	DoubleSidedList<int> l2{ 0, 3, 5 };
	REQUIRE(l1.isEmpty() == true);
	REQUIRE(l2.isEmpty() == false);
	REQUIRE(l1.begin() == l1._end());
	REQUIRE_FALSE(l2.begin() == l2._end());
	REQUIRE(l2.head() == 0);
	REQUIRE(l2._end().getCur() == 5);
	REQUIRE_THROWS_AS(l1.pop_start(), std::out_of_range);
	l2.pop_start();
	REQUIRE(l2.head() == 3);
	l2.pop_start();
	REQUIRE(l2.begin() == l2._end());
	l1.push_start(1);
	l1.push_start(4);
	l1.push_back(5);
	REQUIRE(l1.head() == 4);
	REQUIRE(l1._end().getCur() == 5);
	l2.pop_start();
	auto it = l2._end();
	REQUIRE_THROWS_AS(++it, std::invalid_argument);
}

TEST_CASE("CycledList_Test") {
	CycledList<int> l1;
	CycledList<int> l2{ 0, 3};
	REQUIRE(l1.isEmpty() == true);
	REQUIRE(l2.isEmpty() == false);
	REQUIRE(l2.head() == 0);
	REQUIRE_FALSE(l2.begin() == l2._end());
	REQUIRE(l1.begin() == l1._end());
	auto it = l2.begin();
	++it;
	REQUIRE(it.getCur() == 3);
	++it;
	REQUIRE(it.getCur() == 0);
	l2.push_start(5);
	REQUIRE(l2.head() == 5);
	l2.pop_start();
	REQUIRE(l2.head() == 0);
}

TEST_CASE("DoubleCycledList") {
	DoubleSidedCycledList<int> l1;
	DoubleSidedCycledList<int> l2;
	l2.push_start(1);
	REQUIRE(l1.isEmpty());
	REQUIRE_FALSE(l2.isEmpty());
	REQUIRE(l2.head() == 1);
	l2.push_start(3);
	REQUIRE(l2.head() == 3);
	l2.push_back(8);
	REQUIRE(l2._end().getCur() == 8);
	REQUIRE(l1.begin() == l1._end());
	REQUIRE_FALSE(l2.begin() == l2._end());
	auto it = l2.begin();
	++it;
	++it;
	REQUIRE(it == l2._end());
	++it;
	REQUIRE(it == l2.begin());
	REQUIRE_THROWS_AS(l1.pop_start(), std::out_of_range);
	l2.pop_start();
	REQUIRE(l2.head() == 1);
}