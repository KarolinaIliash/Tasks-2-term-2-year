#include "builder.h"

std::string Element::toString(int indent)
{
	
	std::string s(indentAm * indent, ' ');
	s += '<' + tag + '>' + '\n';
	if (text.size() > 0) {
		std::string i(indentAm * (indent + 1), ' ');
		s += i + text + '\n';
	}
	for (int i = 0; i < elements.size(); i++) {
		s += elements[i].toString(indent + 1);
	}
	std::string i(indentAm*indent, ' ');
	s +=  i + "<\\" + tag + '>' + '\n';
	return s;
}

Builder Element::build(std::string name)
{
	return Builder(name);
}

Builder& Builder::add(std::string tag, std::string text)
{
	start.elements.push_back(Element(tag, text));
	return *this;
}
