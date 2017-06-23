#pragma once
#include<vector>

class Memento;

class Field {
public:
	enum State {
		Empty, X, O
	};

private:
	std::vector<std::vector<State>> field;
public:
	Field();
	State getElem(int row, int col) {
		return field[row][col];
	}

	void setElem(int row, int col, State el) {
		field[row][col] = el;
	}

	void reset();

	Memento* createMemento();
	void setMemento(Memento* m);


};

class Memento {
	friend class Field;
	std::vector<std::vector<Field::State>> field;
	Memento(std::vector<std::vector<Field::State>> _field);
};