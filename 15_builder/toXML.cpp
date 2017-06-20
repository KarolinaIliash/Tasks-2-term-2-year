#include"toXML.h"

#pragma once
#include<fstream>
#include<sstream>
#include"builder.h"

int Hash(std::string s) {
	int result = 0;
	for (int i = 0; i < s.size(); i++) {
		result += s[i];
	}
	return result;
}

void toXML(std::string filename) {
	std::ifstream input(filename + ".txt");
	std::string line;
	auto art = Element::build("article");
	std::getline(input, line);
	art.add("title", line);
	std::getline(input, line);
	art.add("author", line);
	std::string body;
	while (std::getline(input, line)) {
		body += line + '\n';
	}
	body.resize(body.length() - line.length() - 2);
	line.erase(line.begin(), line.begin() + 3);
	input.close();
	art.add("body", body).add("hash", line);
	int hash;
	std::stringstream(line) >> hash;
	if (hash != Hash(body)) {
		return;
	}
	std::ofstream output(filename + ".xml");
	output << art.toString();
	output.close();
}