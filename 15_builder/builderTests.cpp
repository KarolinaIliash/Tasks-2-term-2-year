#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"toXML.h"

TEST_CASE("toxml") {
	auto art = Element::build("article");
	SECTION("empty article") {
		std::string s = art.toString();
		REQUIRE(s == "<article>\n<\\article>\n");
	}
	SECTION("from string") {
		art.add("body", "body");
		std::string s = art.toString();
		REQUIRE(s == "<article>\n    <body>\n        body\n    <\\body>\n<\\article>\n");
	}
	SECTION("hash") {
		std::string s = "abv";
		REQUIRE(Hash(s) == int('a') + int('b') + int('v'));
	}
}
