#pragma once
#include"list.h"

template <typename T>
class DoubleSidedList : virtual public List<T> {
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
	DoubleSidedList() = default;
	DoubleSidedList(std::initializer_list<T> init) {
		for (auto &x : init) {
			push_back(x);
		}
	}

	ListIterator _end() {
		return ListIterator(*this, end);
	}

	virtual void push_back(const T& val) {
		if (end == nullptr) {
			beg = end = new Node(val);
		}
		else {
			end->_next = new Node(val);
			end = end->_next;
		}
	}

	virtual void push_start(const T& val) {
		List<T>::push_start(val);
		if (end == nullptr) {
			end = beg;
		}
	}
	void pop_start() {
		if (end != beg || end == nullptr) {
			List<T>::pop_start();
		}
		else {
			delete beg;
			beg = end = nullptr;
		}
	}
};