#pragma once
#include <algorithm>
#include<vector>

template <typename T>
class List
{
public:
	class ListIterator;
protected:
	struct Node
	{
		T _elem;
		Node * _next;

		Node(const T& elem, Node* next = nullptr): _elem(elem), _next(next){}
		~Node(){
			delete _next;
		}
	};

	Node* beg = nullptr;
public:
	//class BadList {};
	List() = default;
	List(std::initializer_list<T> init) {
		std::vector<T> temp = init;
		std::reverse(temp.begin(), temp.end());
		for (auto &x : temp) {
			push_start(x);
		}
	}
	virtual ~List() {
		delete beg;
	}
	//virtual void cons(char elem);
	virtual T head() { 
		return beg->_elem; 
	}

	virtual ListIterator _end() {
		return ListIterator(*this);
	}
	
	virtual void pop_start() {
		if (beg == nullptr) {
			throw std::out_of_range("List is empty");
		}
		auto temp = beg;
		beg = beg->_next;
		temp->_next = nullptr;
		delete temp;
	};
	virtual void push_start(const T& elem) {
		beg = new Node(elem, beg);
	};
	virtual bool isEmpty() { return beg == nullptr; }
	//virtual ListIterator iterate();
	virtual ListIterator begin() { return ListIterator(*this, beg); }
	virtual ListIterator end() { return ListIterator(*this); }
};

template<typename T>
class List<T>::ListIterator {
private:
	List<T>& list;
	Node* cur = nullptr;
public:
	ListIterator(List<T>& _list, Node* _cur = nullptr) : list{ _list }, cur(_cur){}

	ListIterator& operator=(const ListIterator& iter) {
		if (&list != &iter.list) {
			throw std::invalid_argument("Different lists");
		}
		cur = iter.cur;
		return *this;
	}

	bool operator==(const ListIterator& iter) {
		if (&list != &iter.list) {
			throw std::invalid_argument("Different lists");
		}
		return cur == iter.cur;
	}

	ListIterator& operator++() {
		if (cur == nullptr) {
			throw std::invalid_argument("Iterator isn't worked");
		}
		cur = cur->_next;
		return *this;
	}

	T& getCur() {
		if (cur == nullptr) {
			throw std::invalid_argument("Iterator isn't worked");
		}
		return cur->_elem;
	}
};