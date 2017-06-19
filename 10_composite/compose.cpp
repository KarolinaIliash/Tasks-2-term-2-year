#include"compose.h"

int GetPriority(char symb) {
	switch(symb) {
		case '+':
		case '-':return 1;
		case '*':
		case '/': return 2;
		default: return -1;
	}
}

Expression* Parse(std::string s) {
	if (s[0] == '(' && s[s.size() - 1] == ')')
		return Parse(s.substr(1, s.size() - 2));

	int brackets = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (GetPriority(s[i]) == 1 && !brackets) {
			if (s[i] == '+') {
				if (i == s.size() - 1) return new Add(Parse("0"), Parse(s.substr(0, s.size() - 1)));
				return new Add(Parse(s.substr(0, i)),Parse(s.substr(i + 1, s.size() -1)));
			}
			if (s[i] == '-') {
				if (i == 0) return new Subtract(Parse("0"), Parse(s.substr(1, s.size() - 1)));
				return new Subtract(Parse(s.substr(0, i)), Parse(s.substr(i + 1, s.size()-1)));
			}
		}
		if (s[i] == '(') brackets++;
		else if (s[i] == ')') brackets--;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (GetPriority(s[i]) == 2 && !brackets && i!=0) {
			if (s[i] == '*') {
				return new Multiply(Parse(s.substr(0, i)), Parse(s.substr(i + 1, s.size()-1)));
			}
			if (s[i] == '/') {
				return new Divide(Parse(s.substr(0, i)), Parse(s.substr(i + 1, s.size()-1)));
			}
		}
		if (s[i] == '(') brackets++;
		else if (s[i] == ')') brackets--;
	}

	if (brackets) throw(std::invalid_argument("Invalid expression"));

	return new Constant(std::stod(s));
}

bool Run(std::string s, double& result) {
	try {
		result = Parse(s)->calculate();
		return true;
	}
	catch (const std::invalid_argument& message) {
		return false;
	}
}