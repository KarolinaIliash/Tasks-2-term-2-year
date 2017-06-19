#pragma once
#include<string>
#include<fstream>
#include<vector>


class Employee;

class Contacts {
public:
	virtual std::vector<Employee*> getEmployees() = 0;

	virtual bool IsRealContactExisted() = 0; //only for testing
};

class RealContacts :public Contacts {
	std::string filename;
	std::vector<Employee*> employees;
	bool NeedToRead = true;
public:
	RealContacts(std::string _filename) :filename(_filename) {}
	std::vector<Employee*> getEmployees() override {
		if (NeedToRead) ReadFile();
		return employees;
	}
	bool IsRealContactExisted() { return true; }//testing
private:
	void ReadFile();
};

class ProxyContacts :public Contacts {
	std::string filename;
	RealContacts* contacts;
public:
	ProxyContacts(std::string _filename) :filename(_filename) { contacts = nullptr; }
	std::vector<Employee*> getEmployees() override {
		if (contacts == nullptr) contacts = new RealContacts(filename);
		return contacts->getEmployees();
	}
	bool IsRealContactExisted() { return contacts != nullptr; }//only for testing
	~ProxyContacts() { delete contacts; }
};




class Employee {
	std::string name;
	int salary;
	std::string position;
public:
	Employee(std::string _name, int _salary, std::string _position) :name(_name),
		salary(_salary), position(_position) {}
	std::string getName() { return name; }
	std::string getPosition() { return position; }
	double getSalary() { return salary; }
	std::string AllInfo() { return "Name: " + name + " Position: " + position + " Salary: " + std::to_string(salary) + " "; }
};

class Company {
private:
	std::string name;
	std::string address;
	Contacts* contacts;
public:
	Company(std::string _name, std::string _address, std::string filename) :
		name(_name), address(_address) {
		contacts = new ProxyContacts(filename);
	}
	std::string GetInfoEmployees();
	std::string GetCompanyName() { return name; }
	std::string GetCompanyAddress() { return address; }
	bool IsRealContactExisted() { return contacts->IsRealContactExisted(); }
	~Company() { delete contacts; }
};