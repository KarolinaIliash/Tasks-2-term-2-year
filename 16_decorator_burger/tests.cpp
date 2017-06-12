#define CATCH_CONFIG_MAIN
//#include "C:\Users\Администратор\Documents\Visual Studio 2015\Projects\Catch-master\include\catch.hpp"
#include"catch.hpp"
#include"decorator.h"

TEST_CASE("get_cost") {
	SECTION("Burger_parts") {
		Empty_Burger* burg = new Bun(new Empty_Burger);
		REQUIRE(burg->get_cost() == 0);

		SECTION("Meat") {
			burg = new Meat(burg);
			REQUIRE(burg->get_cost() == 15);
			SECTION("Meat and cheese") {
				burg = new Cheese(burg);
				REQUIRE(burg->get_cost() == 25);
			}
			SECTION("Double meat") {
				burg = new Meat(burg);
				REQUIRE(burg->get_cost() == 30);
			}
		}
		SECTION("Tomatoes") {
			burg = new Tomato(burg);
			REQUIRE(burg->get_cost() == 5);
		}
		SECTION("Cheese") {
			burg = new Cheese(burg);
			REQUIRE(burg->get_cost() == 10);
		}
		SECTION("Salad") {
			burg = new Salad(burg);
			REQUIRE(burg->get_cost() == 5);
		}
		SECTION("Sauce") {
			burg = new Sauce(burg);
			REQUIRE(burg->get_cost() == 5);
		}
	}
}

TEST_CASE("get_order") {
	SECTION("Burger_parts") {
		Empty_Burger* burg = new Bun(new Empty_Burger);
		REQUIRE(burg->get_order() == "Basic");
		SECTION("Meat") {
			burg = new Meat(burg);
			REQUIRE(burg->get_order() == "Basic + meat");
			SECTION("Double meat") {
				burg = new Meat(burg);
				REQUIRE(burg->get_order() == "Basic + meat + meat");
			}
			SECTION("Meat and cheese") {
				burg = new Cheese(burg);
				REQUIRE(burg->get_order() == "Basic + meat + cheese");
			}
		}
		SECTION("Cheese") {
			burg = new Cheese(burg);
			REQUIRE(burg->get_order() == "Basic + cheese");
		}
		SECTION("Salad") {
			burg = new Salad(burg);
			REQUIRE(burg->get_order() == "Basic + salad");
		}
		SECTION("Sauce") {
			burg = new Sauce(burg);
			REQUIRE(burg->get_order() == "Basic + sauce");
		}
		SECTION("Tomatoe") {
			burg = new Tomato(burg);
			REQUIRE(burg->get_order() == "Basic + tomatoes");
		}
	}
}

