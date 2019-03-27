#pragma once
#include <iostream>

//Term

class Term
{
	friend class Polynomial;
private:
	int coef, exp;

public:
	int getCoef() const;
	int getExp() const;
};

//Polynomial

class Polynomial
{
	friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial);
private:
	Term *termArr;
	int capacity;
	int terms;

public:
	Polynomial();
	Polynomial(const Polynomial &other);
	~Polynomial();
	void resize();
	void addTerm(int coef, int exp);
	void setTerm();
	Polynomial &operator=(const Polynomial &other);
	const Polynomial operator+(const Polynomial &other) const;
	const Polynomial operator*(const Polynomial &other) const;
};
