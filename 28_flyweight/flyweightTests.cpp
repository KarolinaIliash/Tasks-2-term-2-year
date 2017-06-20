#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include "bacteriaFactory.h"

TEST_CASE("bact") {
	std::string name = "Bacillus larvae";
	Type type = Type::Bacillus;
	SECTION("bacteria") {
		Bacteria b(name, type);
		REQUIRE(b.GetName() == name);
		REQUIRE(b.GetType() == type);
		REQUIRE(b.GetTypeName() == "Bacillus");
		REQUIRE(b.FullBacteria() == "Bacillus larvae Bacillus");
	}
	SECTION("factory") {
		BacteriaFactory fact;
		auto& b1 = fact.GetBacteria(name, type, 14);
		auto& b2 = fact.GetBacteria("Diplococci", Type::Coccus, 14);
		REQUIRE(&b1 != &b2);
		auto& b3 = fact.GetBacteria(name, type, 44);
		auto& b4 = fact.GetBacteria("Diplococci", Type::Coccus, 3);
		REQUIRE(&b1 == &b3);
		REQUIRE(&b2 == &b4);
	}
}