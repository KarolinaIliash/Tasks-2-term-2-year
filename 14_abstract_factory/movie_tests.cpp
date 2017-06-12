#define CATCH_CONFIG_MAIN
#include"catch.hpp"

#include"movie_factory.h"

TEST_CASE("test lang & subs") {
	movie* film;// = new movie("");
	SECTION("movie_factory") {
		movie_factory* mov = new movie_factory();
	//	mov->set_language(*film);
	//	mov->set_subs(*film);
		film = mov->create("");
		REQUIRE(film->get_lang() == LANG::English);
		REQUIRE(film->get_subs() == LANG::English);
		SECTION("add_spanish") {
			mov = new Spanish_factory();
			film = mov->create("");
			REQUIRE(film->get_lang() == LANG::Spanish);
			REQUIRE(film->get_subs() == LANG::Spanish);
		}
	}
	SECTION("English") {
		movie_factory* mov = new English_factory();
		film = mov->create("");
		REQUIRE(film->get_lang() == LANG::English);
		REQUIRE(film->get_subs() == LANG::English);
	}
	SECTION("French") {
		movie_factory* mov = new French_factory();
		film = mov->create("");
		REQUIRE(film->get_lang() == LANG::French);
		REQUIRE(film->get_subs() == LANG::French);
	}
	SECTION("Spanish") {
		movie_factory* mov = new Spanish_factory();
		film = mov->create("");
		REQUIRE(film->get_lang() == LANG::Spanish);
		REQUIRE(film->get_subs() == LANG::Spanish);
	}
	SECTION("Ukrainian") {
		movie_factory* mov = new Ukrainian_factory();
		film = mov->create("");
		REQUIRE(film->get_lang() == LANG::Ukrainian);
		REQUIRE(film->get_subs() == LANG::Ukrainian);
	}
	SECTION("Germany") {
		movie_factory* mov = new Germany_factory();
		film = mov->create("");
		REQUIRE(film->get_lang() == LANG::Germany);
		REQUIRE(film->get_subs() == LANG::Germany);
	}
}