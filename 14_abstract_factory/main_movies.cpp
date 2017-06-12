#include"movie_factory.h"

/*int main() {
	cout << "Enter the name of the movie\n";
	string movie_name;
	cin >> movie_name;
	cout << "Enter the language of the movie\n1 - English\n2 - Ukrainian\n3 - Germany\n4 - Spanish\n5 - French\n";
	short int lang_numb;
	cin >> lang_numb;
	movie* film = new movie(movie_name);
	movie_factory* MOVIE = new English_factory;
	switch (lang_numb) {
	case 1:
		MOVIE = new English_factory();
		break;
	case 2:
		MOVIE = new Ukrainian_factory();
		break;
	case 3:
		MOVIE = new Germany_factory();
		break;
	case 4:
		MOVIE = new Spanish_factory();
		break;
	case 5:
		MOVIE = new French_factory();
		break;
	default:
		MOVIE = new movie_factory();
	}
	MOVIE->set_language(*film);
	MOVIE->set_subs(*film);
	cout << "Result\nName of movie - " << film->get_name() << endl;
	cout << "Language of movie - ";// << film->get_lang() << endl;
	switch (film->get_lang()) {
	case LANG::English:
		cout << "English\n";
		break;
	case LANG::Ukrainian:
		cout << "Ukrainian\n";
		break;
	case LANG::Germany:
		cout << "Germany\n";
		break;
	case LANG::Spanish:
		cout << "Spanish\n";
		break;
	case LANG::French:
		cout << "French\n";
		break;
	}
	cout << "Subs of movie - ";
	switch (film->get_subs()) {
	case LANG::English:
		cout << "English\n";
		break;
	case LANG::Ukrainian:
		cout << "Ukrainian\n";
		break;
	case LANG::Germany:
		cout << "Germany\n";
		break;
	case LANG::Spanish:
		cout << "Spanish\n";
		break;
	case LANG::French:
		cout << "French\n";
		break;
	}
	system("pause");
}*/