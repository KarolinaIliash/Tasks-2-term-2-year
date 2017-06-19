#define CATCH_CONFIG_MAIN

#include"catch.hpp"
#include"observe.h"

TEST_CASE("test_subject"){
	Subject sub;
	vector<string> inter(3);
	inter[0] = "Vogue";
	inter[1] = "Men's Health";
	inter[2] = "Mathematic";
	Observer* ob = new Client1(inter);
	vector<string> int2(2);
	int2[0] = "Math";
	int2[1] = "Health";
	Observer* ob1 = new Client1(int2);
	SECTION("Attach") {
		sub.Attach(ob);
		REQUIRE(sub.get_obs()[0] == ob);
		SECTION("lots of addings") {
			SECTION("same") {
				sub.Attach(ob);
				sub.Attach(ob);
				sub.Attach(ob);
				vector<Observer*> test(1);
				test[0] = ob;
				REQUIRE(sub.get_obs() == test);
			}
			SECTION("differnet") {
				sub.Attach(ob);
				sub.Attach(ob);
				sub.Attach(ob1);
				sub.Attach(ob);
				sub.Attach(ob1);
				vector<Observer*> test(2);
				test[0] = ob;
				test[1] = ob1;
				REQUIRE(sub.get_obs() == test);
			}
		}
	}
	SECTION("Detach") {
		SECTION("existed") {
			sub.Attach(ob);
			sub.Detach(ob);
			REQUIRE(sub.get_obs().size() == 0);
		}
		SECTION("free") {
			sub.Detach(ob);
			sub.Detach(ob1);
			REQUIRE(sub.get_obs().size() == 0);
		}
		SECTION("more than one") {
			sub.Attach(ob1);
			sub.Attach(ob);
			sub.Detach(ob);
			vector<Observer*> test(1);
			test[0] = ob1;
			REQUIRE(sub.get_obs() == test);
		}
	}
	SECTION("add_mag") {
		sub.Attach(ob);
		sub.Attach(ob1);
		sub.Add_magaz("Health");
		vector<string> test(1);
		test[0] = "Health";
		REQUIRE(ob->get_mags().size() == 0);
		REQUIRE(ob1->get_mags() == test);
	}
}

TEST_CASE("Observer") {
	Subject sub;
	vector<string> inter(3);
	inter[0] = "Vogue";
	inter[1] = "Men's Health";
	inter[2] = "Mathematic";
	vector<string> int2(2);
	int2[0] = "Math";
	int2[1] = "Health";
	SECTION("client1") {
		Observer* ob = new Client1(inter);
		Observer* ob1 = new Client1(int2);
		SECTION("is_interested") {
			REQUIRE(ob->is_interested("Vogue") == 1);
			REQUIRE(ob->is_interested("N") == 0);
			REQUIRE(ob->is_interested("Math") == 0);
			REQUIRE(ob1->is_interested("Vogue") == 0);
			REQUIRE(ob1->is_interested("Health") == 1);
		}
		SECTION("Update") {
			ob->Update("Math");
			ob->Update("Mathematic");
			vector<string> test(1);
			test[0] = "Mathematic";
			REQUIRE(ob->get_mags() == test);
			ob1->Update("Health");
			ob1->Update("Vogue");
			ob1->Update("Math");
			test.resize(2);
			test[0] = "Health";
			test[1] = "Math";
			REQUIRE(ob1->get_mags() == test);
		}
	}
}