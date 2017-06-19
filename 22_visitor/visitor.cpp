#include"visitor.h"

void Euclid::visit(Point2d* p) {
	p->setNorm(sqrt(p->getX()*p->getX() + p->getY()*p->getY()));
}
void Euclid::visit(Point3d* p) {
	p->setNorm(sqrt(p->getX()*p->getX() + p->getY()*p->getY() + p->getZ()*p->getZ()));
}

void Manhattan::visit(Point2d* p){
	p->setNorm(fabs(p->getX()) + fabs(p->getY()));
}
void Manhattan::visit(Point3d* p){
	p->setNorm(fabs(p->getX()) + fabs(p->getY()) + fabs(p->getZ()));
}

void Maximum::visit(Point2d* p) {
	if (fabs(p->getX()) > fabs(p->getY())) p->setNorm(fabs(p->getX()));
	else p->setNorm(fabs(p->getY()));
}
void Maximum::visit(Point3d* p) {
	if (fabs(p->getX()) > fabs(p->getY())) {
		if (fabs(p->getX()) > fabs(p->getZ())) p->setNorm(fabs(p->getX()));
		else p->setNorm(fabs(p->getZ()));
	}
	else p->setNorm(fabs(p->getY()));
}