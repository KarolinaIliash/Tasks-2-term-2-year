#pragma once
#include<math.h>

class Point2d;
class Point3d;

class Visitor {
public:
	virtual void visit(Point2d*) = 0;
	virtual void visit(Point3d*) = 0;
};

class Euclid :public Visitor {
public:
	void visit(Point2d* p) override;
	void visit(Point3d* p) override;
};

class Manhattan :public Visitor {
public:
	void visit(Point2d* p) override;
	void visit(Point3d* p) override;
};

class Maximum :public Visitor {
public:
	void visit(Point2d* p) override;
	void visit(Point3d* p) override;
};

class Point {
private:
	double norm = 0;
public:
	virtual void accept(Visitor* v) = 0;
	double getNorm() { return norm; }
	void setNorm(double norm) { this->norm = norm; }
};

class Point2d :public Point {
private:
	double x;
	double y;
public:
	Point2d(double _x, double _y) :x(_x), y(_y) {}
	void accept(Visitor* v) override {
		v->visit(this);
	}
	double getX() { return x; }
	double getY() { return y; }
};

class Point3d :public Point {
private:
	double x;
	double y;
	double z;
public:
	Point3d(double _x, double _y, double _z) :x(_x), y(_y), z(_z) {}
	void accept(Visitor* v) override {
		v->visit(this);
	}
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
};