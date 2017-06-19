#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"compose.h"

TEST_CASE("Without brackets") {
	double result = 0;
	std::string expr;
	bool isCorrect;
	SECTION("One action") {
		expr = "2+4";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 6.);
		expr = "5-3";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 2.);
		expr = "11-19.5";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == -8.5);
		expr = "3*8";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 24.);
		expr = "33/11";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 3.);
		expr = "-19/2";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == -9.5);
	}
	SECTION("Two actions"){
		expr = "2+7-3";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 6.);
		expr = "3-4*5";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == -17.);
		expr = "14/7*5";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 10.);
	}
	SECTION("Three and more actions") {
		expr = "2+5*6-33/11+2";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 31.);
		expr = "-3+5-7*9+4*3";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == -49.);
		expr = "3*4-5/2";
		isCorrect = Run(expr, result);
		REQUIRE(isCorrect == true);
		REQUIRE(result == 9.5);
	}
	SECTION("With brackets") {
		SECTION("One action") {
			expr = "(100/20)";
			isCorrect = Run(expr, result);
			REQUIRE(isCorrect == true);
			REQUIRE(result == 5.);
			expr = "(2-19)";
			isCorrect = Run(expr, result);
			REQUIRE(isCorrect == true);
			REQUIRE(result == -17.);
		}
		SECTION("More actions") {
			expr = "((5*7/5+3*8/2)-9*0)";
			isCorrect = Run(expr, result);
			REQUIRE(isCorrect == true);
			REQUIRE(result == 19.);
			expr = "(1*19*3*4/6+12/(5-3*4/2))";
			isCorrect = Run(expr, result);
			REQUIRE(isCorrect == true);
			REQUIRE(result == 26.);
		}
	}
}

TEST_CASE("Invalid expression") {
	double result = 0;
	std::string expr;
	bool isCorrect;
	expr = "()";
	isCorrect = Run(expr, result);
	REQUIRE(isCorrect == false);
	expr = "-3*(5";
	isCorrect = Run(expr, result);
	REQUIRE(isCorrect == false);
	expr = "+7/3(";
	isCorrect = Run(expr, result);
	REQUIRE(isCorrect == false);
}