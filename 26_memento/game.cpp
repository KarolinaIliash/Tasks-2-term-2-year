#include"game.h"

Game::~Game()
{
	if (prevField != nullptr) {
		delete prevField;
	}
}

bool Game::Move(int row, int col)
{
	if (!isPlaying || field.getElem(row, col) != Field::State::Empty) { return false; }
	if (prevField != nullptr) { delete prevField; }

	prevField = field.createMemento();

	field.setElem(row, col, current);
	if (checkEnd()) {
		isPlaying = false;
		winner = current;
	}
	else {
		if (current == Field::State::O) { current = Field::State::X; }
		else { current = Field::State::O; }
	}
	return true;
}

bool Game::Back()
{
	if (isPlaying == false || prevField == nullptr) return false;
	field.setMemento(prevField);
	delete prevField;
	prevField = nullptr;
	if (current == Field::State::O) { current = Field::State::X; }
	else { current = Field::State::O; }
	return true;
}

bool Game::checkEnd()
{
	//rows
	for (int i = 0; i < 3; i++) {
		if (field.getElem(i, 0) != 0 && field.getElem(i, 0) == field.getElem(i, 1) &&
			field.getElem(i, 0) == field.getElem(i, 2)) {
			return true;
		}
	}

	//columns
	for (int i = 0; i < 3; i++) {
		if (field.getElem(0, i) != 0 && field.getElem(0, i) == field.getElem(1, i) &&
			field.getElem(0, i) == field.getElem(2, i)) {
			return true;
		}
	}

	//diagmain

	if(field.getElem(0, 0) != 0 && field.getElem(0, 0) == field.getElem(1,1) &&
		field.getElem(0, 0) == field.getElem(2, 2)) {
		return true;
	}

	if(field.getElem(0, 2) != 0 && field.getElem(0, 2) == field.getElem(1,1) &&
		field.getElem(0, 2) == field.getElem(2, 0)) {
		return true;
	}

	//is full
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (field.getElem(i, j) == 0) { return false; }
		}
	}

	return true;
}

bool Game::startGame()
{
	if (isPlaying) { return false; }
	restartGame();
	return true;
}

void Game::restartGame()
{
	isPlaying = true;
	winner = Field::State::Empty;
	field.reset();
	if (prevField != nullptr) {
		delete prevField;
		prevField = nullptr;
	}
}
