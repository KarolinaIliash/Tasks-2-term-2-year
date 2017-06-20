#pragma once
#include<string>

enum class Type {
	Bacillus, Spirochete, Coccus, Vibrio
};

class Bacteria {
	std::string name;
	Type type;
public:
	Bacteria(std::string _name, Type _type) : name(_name), type(_type){}
	Type GetType() const { return type; }
	std::string GetName() const{ return name; }
	std::string GetTypeName()const {
		switch (type) {
		case Type::Bacillus: return "Bacillus";
		case Type::Coccus: return "Coccus";
		case Type::Spirochete: return "Spirochete";
		case Type::Vibrio: return "Vibrio";
		}
	}
	std::string FullBacteria() { return name + " " + GetTypeName(); }
	bool operator==(const Bacteria& b) {
		return name == b.GetName() && type == b.GetType();
	}
	bool operator<(const Bacteria& b) const{
		return name < b.GetName() && GetTypeName() < b.GetTypeName();
	}
};

