#pragma once
#include<string>
#include<vector>

class Element {
	friend class Builder;
private:
	std::string tag;
	std::string text;
	std::vector<Element> elements;
	int indentAm = 4;
public:
	Element(std::string _tag, std::string _text="") : tag(_tag), text(_text){}

	std::string toString(int indent = 0);

	static Builder build(std::string name);
};


class Builder {
private:
	Element start;
public:
	Builder(std::string name) : start(name){}
	std::string toString() {
		return start.toString();
	}
	Builder& add(std::string tag, std::string text);
};