#pragma once
#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"singleton.h"

TEST_CASE("singleton") {
	Singleton* s = Singleton::getInstance();
	REQUIRE(s != nullptr);
	REQUIRE(s->GetS() == "I'm an existing singleton");
}