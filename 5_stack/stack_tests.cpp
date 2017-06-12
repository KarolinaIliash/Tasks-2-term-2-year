#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include"Stack.h"

TEST_CASE("Stack") {
	SECTION("ConstructorTest") {
		Stack<int> stack(7);
		REQUIRE(stack.get_size() == 7);
		REQUIRE(stack.get_top() == -1);
		Stack<int> stack2;
		REQUIRE(stack2.get_size() == 100);
		REQUIRE(stack2.get_top() == -1);
	}
	SECTION("PushTest") {
		SECTION("WithoutException") {
			Stack<int> stack;
			stack.push(34);
			stack.push(2);
			stack.push(1);
			std::unique_ptr<int[]> stack_array = (stack.get_array());
			REQUIRE(stack_array[0] == 34);
			REQUIRE(stack_array[1] == 2);
			REQUIRE(stack_array[2] == 1);
			REQUIRE(stack.get_top() == 2);
		}
		SECTION("WithException") {
			Stack<int> stack(2);
			stack.push(25);
			stack.push(2);
			bool is_exception = 0;
			std::string what_exception;
			try {
				stack.push(2);
			}
			catch (const std::out_of_range& exc) {
				is_exception = 1;
				what_exception = exc.what();
			}
			REQUIRE(is_exception);
			REQUIRE(what_exception == "Stack is full");
			is_exception = 0;
			what_exception = "";
			try {
				stack.push(10);
			}
			catch (const std::out_of_range& exc) {
				is_exception = 1;
				what_exception = exc.what();
			}
			REQUIRE(is_exception);
			REQUIRE(what_exception == "Stack is full");
			std::unique_ptr<int[]> stack_array = (stack.get_array());
			REQUIRE(stack_array[0] == 25);
			REQUIRE(stack_array[1] == 2);
			REQUIRE(stack.get_top() == 1);
		}
	}
	SECTION("PopTest") {
		SECTION("WithoutException") {
			Stack<int> stack;
			stack.push(25);
			stack.push(2);
			stack.pop();
			std::unique_ptr<int[]> stack_array = (stack.get_array());
			REQUIRE(stack_array[0] == 25);
			REQUIRE(stack.get_top() == 0);
			stack.pop();
			stack_array = (stack.get_array());
			REQUIRE(stack.get_top() == -1);
		}
		SECTION("WithException") {
			Stack<int> stack;
			std::string what_exception;
			bool is_exception = 0;
			try {
				stack.pop();
			}
			catch (const std::out_of_range& exception) {
				is_exception = 1;
				what_exception = exception.what();
			}
			REQUIRE(is_exception == 1);
			REQUIRE(what_exception == "Stack is empty");
			REQUIRE(stack.get_top() == -1);
		}
	}
	SECTION("ReadTest") {
		SECTION("WithoutException") {
			Stack<int> stack;
			stack.push(25);
			REQUIRE(stack.read() == 25);
			stack.push(2);
			REQUIRE(stack.read() == 2);
			stack.push(0);
			REQUIRE(stack.read() == 0);
		}
		SECTION("WithException") {
			Stack<int> stack;
			bool is_exception = 0;
			std::string what_exception;
			try {
				stack.read();
			}
			catch (const std::out_of_range& exception) {
				is_exception = 1;
				what_exception = exception.what();
			}
			REQUIRE(is_exception == 1);
			REQUIRE(what_exception == "Stack is empty");
			REQUIRE(stack.get_top() == -1);
		}
	}
}
