#include"Bank.h"

void Action::setNext(Action* _next) {
	next = _next;
}
void Action::add(Action* _next) {
	if (next != nullptr) {
		next->add(_next);
	}
	else {
		next = _next;
	}
}

std::string Action::handle(Payment* p) {
	if (next != nullptr) {
		return next->handle(p);
	}
	return "";
}


std::string Fix::handle(Payment* p) {
	std::string res = "Fixed ";
	res += Action::handle(p);
	return res;
}



std::string BankTax::handle(Payment* p){
	std::string res = "";
	if (p->getType() != Preferential && p->getType() != Inner) {
		p->make(p->getSum() * percent / 100.0);
		res += "Bank tax ";
	}
	res += Action::handle(p);
	return res;
}


std::string CountryTax::handle(Payment* p){
	std::string res = "";
	switch (p->getType()) {
	case International:
	case Country:
		p->make(p->getSum() * percent / 100.0);
		res += "Country tax ";
	}
	res += Action::handle(p);
	return res;
}


Bank::Bank() {
	start = new Fix();
	Action* temp = new BankTax();
	temp->setNext(new CountryTax());
	start->setNext(temp);
}

std::string Bank::make(Payment* p) {
	return start->handle(p);
}