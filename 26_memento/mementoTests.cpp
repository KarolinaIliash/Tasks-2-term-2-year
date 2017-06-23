#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"game.h"

TEST_CASE("game") {
	SECTION("restart game") {
		Game game;
		game.restartGame();
		Field f;
		REQUIRE(game.isEqualFields(f));
		game.Move(1, 0);
		game.Move(2, 2);
		REQUIRE_FALSE(game.isEqualFields(f));
		game.restartGame();
		REQUIRE(game.isEqualFields(f));
	}
	SECTION("start game") {
		Game game;
		REQUIRE(game.getCur() == Field::State::X);
		REQUIRE(game.startGame());
		REQUIRE_FALSE(game.startGame());
		REQUIRE(game.getCur() == Field::State::X);
	}
	SECTION("memory prev field") {
		Game game;
		game.startGame();
		REQUIRE_FALSE(game.Back());
		Field f;
		REQUIRE(game.isEqualFields(f));
		REQUIRE(game.Move(1, 0));
		f.setElem(1, 0, Field::State::X);
		REQUIRE(game.isEqualFields(f));
		f.setElem(1, 0, Field::State::Empty);
		REQUIRE(game.Back());
		REQUIRE(game.isEqualFields(f));
		REQUIRE_FALSE(game.Back());
	}
	SECTION("check end") {
		Game game;
		game.startGame();
		REQUIRE_FALSE(game.checkEnd());
		game.Move(0, 0);
		REQUIRE_FALSE(game.checkEnd());
		game.Move(1, 1);
		REQUIRE(game.getWin() == Field::State::Empty);
		REQUIRE_FALSE(game.checkEnd());
		game.Move(0, 1);
		REQUIRE_FALSE(game.checkEnd());
		game.Move(1, 2);
		REQUIRE_FALSE(game.checkEnd());
		game.Move(0, 2);
		REQUIRE(game.checkEnd());
		REQUIRE(game.getWin() == Field::State::X);
	}
}

