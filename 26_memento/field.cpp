#include"field.h"

Field::Field()
{
	field.resize(3);
	for (int i = 0; i < field.size(); i++) {
		field[i].resize(3);
	}
}

void Field::reset()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = Empty;
		}
	}
}

Memento * Field::createMemento()
{
	return new Memento(field);
}

void Field::setMemento(Memento* m)
{
	field = m->field;
}

Memento::Memento(std::vector<std::vector<Field::State>> _field) : field(_field)
{
}
