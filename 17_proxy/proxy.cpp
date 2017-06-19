#include"proxy.h"


std::string Company::GetInfoEmployees() {
	std::vector<Employee*> emps = contacts->getEmployees();
	std::string info;
	for (auto& e : emps) {
		info += e->AllInfo() + '\n';
	}
	return info;
}

void RealContacts::ReadFile() {
	std::ifstream fin(filename);
	std::string name;
	std::string position;
	int salary;
	while (fin >> name) {
		fin >> position;
		fin >> salary;
		Employee* e = new Employee(name, salary, position);
		employees.push_back(e);
	}
	fin.close();
	NeedToRead = false;
}