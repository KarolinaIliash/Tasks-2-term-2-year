#include "stdafx.h"
#include "CppUnitTest.h"
#include "../18_strategy/strategy.h"
#include"../18_strategy/characters.h"
#include"catch.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CASE("strategy"){
	Behaver* temp;
	SECTION("Walk") {
		temp = new Walk();
		REQUIRE(temp->Move() == "Walking");
	}
	SECTION("Fly") {
		temp = new Fly();
		REQUIRE(temp->Move() == "Flying");
	}
	SECTION("Magic") {
		temp = new MagicFly();
		REQUIRE(temp->Move() == "Magic");
	}
}

TEST_CASE("characters") {
	Character* character;
	SECTION("Elf") {
		character = new Elf();
		REQUIRE(character->Walking() == "Walking");
		REQUIRE(character->Flying() == "I can't fly");
		REQUIRE(character->MagicFlying() == "Magic");
	}
	SECTION("Orc") {
		character = new Orc();
		REQUIRE(character->Walking() == "Walking");
		REQUIRE(character->Flying() == "I can't fly");
		REQUIRE(character->MagicFlying() == "Magic");
	}
	SECTION("Pegas") {
		character = new Pegas();
		REQUIRE(character->Walking() == "Walking");
		REQUIRE(character->Flying() == "Flying");
		REQUIRE(character->MagicFlying() == "Magic");
	}
	SECTION("Harpy") {
		character = new Harpy();
		REQUIRE(character->Walking() == "Walking");
		REQUIRE(character->Flying() == "Flying");
		REQUIRE(character->MagicFlying() == "Magic");
	}
}