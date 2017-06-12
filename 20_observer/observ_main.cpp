#include"observe.h"
#include<conio.h>

int main() {
	Subject sub;
	vector<string> inter(3);
	inter[0] = "Vogue";
	inter[1] = "Men's Health";
	inter[2] = "Mathematic";
	Observer* ob = new Client1(inter);
	vector<string> int2(2);
	int2[0] = "Math";
	int2[1] = "Health";
	Observer* ob1 = new Client2(int2);
	sub.Attach(ob);
	sub.Attach(ob1);
	string magazine;
	do {
		cout << "Enter the name of new magazine\n";
		cin >> magazine;
		sub.Add_magaz(magazine);
		cout << "Magazins  of Client1:\n";
		for (int i = 0; i < ob->get_mags().size(); i++)
			cout << ob->get_mags()[i] << " ";
		cout << "\nMagazins of Client2:\n";
		for (int i = 0; i < ob1->get_mags().size(); i++)
			cout << ob1->get_mags()[i] << " ";
		cout << endl;
	} while (_getch() != 27);
}