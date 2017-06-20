#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"container.h"
#include"set.h"
#include"list.h"
#include"vector.h"


TEST_CASE("container") {
	SECTION("vector") {
		Vector<int> v;
		REQUIRE(v.isEmpty() == true);
		REQUIRE(v.find(0) == nullptr);
		v.insert(11);
		v.insert(15);
		REQUIRE(*v.find(11) == 11);
		REQUIRE(v.find(5) == nullptr);
		REQUIRE(*v.find(15) == 15);
		v.erase(15);
		REQUIRE(v.find(15) == nullptr);
		REQUIRE(v.count(15) == 0);
		REQUIRE(v.count(11) == 1);
		REQUIRE(v.size() == 1);
	}
	SECTION("list") {
		List<char> l;
		REQUIRE(l.isEmpty() == true);
		REQUIRE(l.find('a') == nullptr);
		l.insert('a');
		l.insert('a');
		l.insert('b');
		l.insert('r');
		REQUIRE(l.size() == 4);
		REQUIRE(*l.find('r') == 'r');
		REQUIRE(l.find('m') == nullptr);
		REQUIRE(l.count('a') == 2);
		l.erase('b');
		REQUIRE(l.count('b') == 0);
		REQUIRE(l.find('b') == nullptr);
		REQUIRE(l.size() == 3);
	}
	SECTION("set") {
		Set<int, Vector> set;
		REQUIRE(set.isEmpty() == true);
		REQUIRE(set.find(8) == nullptr);
		set.insert(3);
		set.insert(3);
		set.insert(5);
		REQUIRE(set.size() == 2);
		REQUIRE(set.find(9) == nullptr);
		REQUIRE(set.count(3) == 1);
		REQUIRE(*set.find(5) == 5);
		REQUIRE(set.isEmpty() == false);
		set.erase(3);
		set.erase(6);
		REQUIRE(set.size() == 1);
		REQUIRE(set.find(3) == nullptr);
	}
}