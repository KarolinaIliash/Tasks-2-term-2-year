#include"decorator.h"

/*int main() {
	Empty_Burger* burg = new Bun(new Empty_Burger);
	cout << "Menu:\n1.Meat - 15 grn\n2.Cheese - 10 grn\n3.Tomatoes - 5 grn\n4.Salad - 5 grn\n5.Sauce - 5 grn\n";
	cout << "Enter your wishes with numbers of components.\nIf you want to finish - enter anyone other number\n";
	int answer = 1;
	char check_answ[10];
	Check check;
	while (answer > 0 && answer < 6) {
		cout << "Choose next component\n";
		cin >> check_answ;
		if (check.check_number(check_answ))
			answer = atoi(check_answ);
		else break;
		switch (answer) {
		case 1:
			burg = new Meat(burg);
			break;
		case 2:
			burg = new Cheese(burg);
			break;
		case 3:
			burg = new Tomato(burg);
			break;
		case 4:
			burg = new Salad(burg);
			break;
		case 5:
			burg = new Sauce(burg);
			break;
		default: break;
			break;
		}
	}
	//burg = new Cheese(new Meat(new Cheese(burg)));
	//printf("%d","%s", burg->get_cost(), "grn");
	//printf("%s", burg->get_order());
	cout << "Your order: " <<burg->get_order() <<"\nIt costs " <<  burg->get_cost() << " grn\n";
	system("pause");
}*/