#pragma once
#include "list.h"

template<typename T>
class CycledList : virtual public List<T> {
private: 
	Node* end = nullptr;
protected:
	Node*& getBegin() {
		return beg;
	}
	Node*& getEnd() {
		return end;
	}
public:
	CycledList() = default;
	CycledList(std::initializer_list<T> init) {
		std::vector<T> temp = init;
		std::reverse(temp.begin(), temp.end());
		for (auto &x : temp) {
			push_start(x);
		}
	}

	~CycledList()	override{
		if (end != nullptr) {
			end->_next = nullptr;
 		}
	}

	void push_start(const T& val) override{
		if (beg == nullptr) {
			beg = new Node(val);
			beg->_next = beg;
			end = beg;
		}
		else {
			beg = new Node(val, beg);
			end->_next = beg;
		}
	}

	void pop_start() override {
		if (beg == nullptr) {
			throw std::out_of_range("List is empty");
		}
		auto start = beg;
		if (beg == end) {
			beg = nullptr;
			end = nullptr;
		}
		else {
			beg = beg->_next;
			end = beg;
		}
		start->_next = nullptr;
		delete start;
	}
};