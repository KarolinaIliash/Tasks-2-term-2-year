#pragma once
#include"doubleSidedList.h"
#include"CycledList.h"

template<typename T>
class DoubleSidedCycledList : public CycledList<T>, public DoubleSidedList<T> {
public:
	DoubleSidedCycledList() = default;

	bool isEmpty() {
		return List::isEmpty();
	}
	void push_start(const T& val) override{
		CycledList::push_start(val);
		DoubleSidedList::getEnd() = CycledList::getEnd();
	}
	void push_back(const T& val) override{
		DoubleSidedList::push_back(val);
		DoubleSidedList::getEnd()->_next = DoubleSidedList::getBegin();
		CycledList::getEnd() = DoubleSidedList::getEnd();
	}
	void pop_start() override{
		CycledList::pop_start();
		DoubleSidedList::getBegin() = CycledList::getBegin();
	}
};