#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"proxy.h"

TEST_CASE("proxy") {
	std::string filename = "employees.txt";
	Company company("A", "B", filename);
	SECTION("only company info") {
		std::string name = company.GetCompanyName();
		REQUIRE(name == "A");
		REQUIRE(company.IsRealContactExisted() == false);
		std::string address = company.GetCompanyAddress();
		REQUIRE(address == "B");
		REQUIRE(company.IsRealContactExisted() == false);
	}
	SECTION("should read employees") {
		std::string info = company.GetInfoEmployees();
		REQUIRE(company.IsRealContactExisted() == true);
		REQUIRE(info ==
			"Name: AAA Position: A Salary: 2400 \nName: BBB Position: B Salary: 3200 \n");
	}
}