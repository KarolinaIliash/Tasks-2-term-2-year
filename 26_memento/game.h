#pragma once
#include"field.h"

class Game {
	Field field;
	Memento* prevField = nullptr;
	Field::State current = Field::State::X;
	Field::State winner = Field::State::Empty;

	bool isPlaying = false;

public:

	~Game();

	bool isGame() { return isPlaying; }
	Field::State getCur() { return current; }
	Field::State getWin() { return winner; }
	Field::State getElem(int row, int col) { return field.getElem(row, col); }

	bool Move(int row, int col);

	bool Back();

	bool checkEnd();

	bool startGame();

	void restartGame();

	//for tests
	bool isEqualFields(Field f) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (getElem(i, j) != f.getElem(i, j)) {
					return false;
				}
			}
		}
		return true;
	}
};