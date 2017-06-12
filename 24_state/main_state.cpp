/*#include"state.h"
#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	Request request;
	cout << "Possible:\n1 - Examine\n2 - Postpone\n3 - Accept\n4 - Refuse\n5 - Broke\n6 - Get answer\n";
	int answer;
	bool isDone = 0;
	do {
		cin >> answer;
		switch (answer) {
		case 1: 
			isDone = request.Examine();
			break;
		case 2:
			isDone = request.Postpone();
			break;
		case 3:
			isDone = request.Accept();
			break;
		case 4:
			isDone = request.Refuse();
			break;
		case 5:
			isDone = request.Broke();
			break;
		case 6:
			cout << request.SendAnswer()<< endl;
			break;
		}
		if (answer > 0 && answer < 6) {
			if (isDone) {
				cout << "It's ok\n";
			}
			else {
				cout << "You can't do such action with this request\n";
			}
		}
	} while (_getch() != 27);
}*/