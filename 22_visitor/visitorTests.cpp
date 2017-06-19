#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"visitor.h"

TEST_CASE("visitor") {
	Point2d* p2 = new Point2d(3, 4);
	Point3d* p3 = new Point3d(5, -3, 4);
	Visitor* v;
	SECTION("Euclid") {
		v = new Euclid;
		p2->accept(v);
		REQUIRE(p2->getNorm() == 5.);
		p3->accept(v);
		REQUIRE(p3->getNorm() == sqrt(50));
	}
	SECTION("Manhattan") {
		v = new Manhattan;
		p2->accept(v);
		REQUIRE(p2->getNorm() == 7);
		p3->accept(v);
		REQUIRE(p3->getNorm() == 12);
	}
	SECTION("Maximum") {
		v = new Maximum;
		p2->accept(v);
		REQUIRE(p2->getNorm() == 4);
		p3->accept(v);
		REQUIRE(p3->getNorm() == 5);
	}
}