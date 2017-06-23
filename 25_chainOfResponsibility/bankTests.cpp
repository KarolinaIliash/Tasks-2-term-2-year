#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"Bank.h"

TEST_CASE("MakePayments") {
	Bank bank;
	SECTION("International, Country") {//together cause the same logic of taxing should be
		Payment* pI = new Payment(100000, paymentType::International);
		Payment* pC = new Payment(100000, paymentType::Country);
		std::string resI = bank.make(pI);
		std::string resC = bank.make(pC);
		std::string expected = "Fixed Bank tax Country tax ";
		REQUIRE(resI == expected);
		REQUIRE(resC == expected);
		REQUIRE(pI->getSum() == 92150);
		REQUIRE(pC->getSum() == 92150);
 	}
	SECTION("Ordinary") {
		Payment* pO = new Payment(100000, paymentType::Ordinary);
		std::string resO = bank.make(pO);
		std::string expected = "Fixed Bank tax ";
		REQUIRE(resO == expected);
		REQUIRE(pO->getSum() == 95000);
	}
	SECTION("Inner, Preferential") {
		Payment* pI = new Payment(100000, paymentType::Inner);
		Payment* pP = new Payment(100000, paymentType::Preferential);
		std::string resI = bank.make(pI);
		std::string resP = bank.make(pP);
		std::string expected = "Fixed ";
		REQUIRE(resI == expected);
		REQUIRE(resP == expected);
		REQUIRE(pI->getSum() == 100000);
		REQUIRE(pP->getSum() == 100000);
	}
}