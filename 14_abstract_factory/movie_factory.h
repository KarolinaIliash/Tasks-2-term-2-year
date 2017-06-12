#pragma once
#include<iostream>
#include<string>

using namespace std;

enum class LANG {
	English,
	Ukrainian,
	Germany,
	Spanish,
	French
};

class movie {
private:
	string name;
	LANG language;
	LANG subs;
public:
	movie(string film) {
		language = LANG::English;
		subs = LANG::English;
		name = film;
	};
	void new_language(LANG new_language) {
		language = new_language;
	};
	void new_subs(LANG new_subs) {
		subs = new_subs;
	};
	string get_name() {
		return this->name;
	}
	LANG get_lang() {
		return this->language;
	}
	LANG get_subs() {
		return this->subs;
	}
};

class movie_factory {
private:
	LANG language;
	LANG subs;
public:
	movie_factory() {
		language = LANG::English;
		subs = LANG::English;
	};
	virtual void set_language(movie& film) {
		film.new_language(language);
	};
	virtual void set_subs(movie& film) {
		film.new_subs(subs);
	};
	virtual movie* create(string film) {
		movie* mov = new movie(film);
		set_language(*mov);
		set_subs(*mov);
		return mov;

	};
};

class English_factory : public movie_factory {
private:
	LANG language;
	LANG subs;
public:
	English_factory() {
		language = LANG::English;
		subs = LANG::English;
	};
	virtual void set_language(movie& film) override {
		film.new_language(language);
	}
	virtual void set_subs(movie& film) override {
		film.new_subs(subs);
	};
};

class French_factory : public movie_factory {
private:
	LANG language;
	LANG subs;
public:
	French_factory() {
		language = LANG::French;
		subs = LANG::French;
	};
	virtual void set_language(movie& film) override {
		film.new_language(language);
	}
	virtual void set_subs(movie& film) override {
		film.new_subs(subs);
	};
};

class Ukrainian_factory : public movie_factory {
private:
	LANG language;
	LANG subs;
public:
	Ukrainian_factory() {
		language = LANG::Ukrainian;
		subs = LANG::Ukrainian;
	};
	virtual void set_language(movie& film) override {
		film.new_language(language);
	}
	virtual void set_subs(movie& film) override {
		film.new_subs(subs);
	};
};

class Germany_factory : public movie_factory {
private:
	LANG language;
	LANG subs;
public:
	Germany_factory() {
		language = LANG::Germany;
		subs = LANG::Germany;
	};
	virtual void set_language(movie& film) override {
		film.new_language(language);
	}
	virtual void set_subs(movie& film) override {
		film.new_subs(subs);
	};
};

class Spanish_factory : public movie_factory {
private:
	LANG language;
	LANG subs;
public:
	Spanish_factory() {
		language = LANG::Spanish;
		subs = LANG::Spanish;
	};
	virtual void set_language(movie& film) override {
		film.new_language(language);
	}
	virtual void set_subs(movie& film) override {
		film.new_subs(subs);
	};
};

