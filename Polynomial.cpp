#include "Polynomial.h"

//Term

int Term::getCoef() const
{
	return coef;
}

int Term::getExp() const
{
	return exp;
}

//Polynomial

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial)
{
	int terms = polynomial.terms;
	int coef, exp;

	if (terms == 0)
	{
		os << 0;
		return os;
	}

	for (int i = 0; i < terms; i += 1)
	{
		coef = polynomial.termArr[i].getCoef();
		exp = polynomial.termArr[i].getExp();

		if (exp == 0)
		{
			os << coef;
			continue;
		}
		if (coef == -1) os << "-";
		else if (coef != 1) os << coef;
		if (exp == 1) os << "x";
		else os << "x^" << exp;
		if (i < terms - 1) os << " + ";
	}
	return os;
}

Polynomial::Polynomial()
{
	capacity = 4;
	terms = 0;
	termArr = new Term[capacity];
}

Polynomial::Polynomial(const Polynomial &other)
{
	capacity = other.capacity;
	terms = other.terms;
	termArr = new Term[capacity];
	for (int i = 0; i < terms; i += 1)
	{
		termArr[i] = other.termArr[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] termArr;
}

void Polynomial::resize()
{
	capacity *= 2;
	Term *newArr = new Term[capacity];
	for (int i = 0; i < terms; i += 1)
	{
		newArr[i] = termArr[i];
	}
	delete[] termArr;
	termArr = newArr;
}

void Polynomial::addTerm(int coef, int exp)
{
	if (coef == 0) return;
	if (capacity == terms) resize();
	termArr[terms].coef = coef;
	termArr[terms].exp = exp;
	terms += 1;
}

void Polynomial::setTerm()
{
	int coef, exp;

	do {
		std::cin >> coef >> exp;
		addTerm(coef, exp);
	} while (exp);
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
	if (this == &other) return *this;
	delete[] termArr;
	capacity = other.capacity;
	terms = other.terms;
	termArr = new Term[capacity];
	for (int i = 0; i < terms; i += 1)
	{
		termArr[i] = other.termArr[i];
	}
	return *this;
}

const Polynomial Polynomial::operator+(const Polynomial &other) const
{
	Polynomial result;
	int i = 0, j = 0, condition;

	while (true)
	{
		if (i < terms)
		{
			if (j < other.terms)
			{
				condition = termArr[i].exp - other.termArr[j].exp;
				if (condition > 0)
				{
					result.addTerm(termArr[i].coef, termArr[i].exp);
					i += 1;
				}
				else if (condition < 0)
				{
					result.addTerm(other.termArr[j].coef, other.termArr[j].exp);
					j += 1;
				}
				else
				{
					result.addTerm(termArr[i].coef + other.termArr[j].coef, termArr[i].exp);
					i += 1;
					j += 1;
				}
			}
			else
			{
				result.addTerm(termArr[i].coef, termArr[i].exp);
				i += 1;
			}
		}
		else if (j < other.terms)
		{
			result.addTerm(other.termArr[j].coef, other.termArr[j].exp);
			j += 1;
		}
		else
		{
			break;
		}
	}

	return result;
}

const Polynomial Polynomial::operator*(const Polynomial &other) const
{
	Polynomial result;

	for (int i = 0; i < terms; i += 1)
	{
		Polynomial middle;
		for (int j = 0; j < other.terms; j += 1)
		{
			middle.addTerm(termArr[i].coef * other.termArr[j].coef, termArr[i].exp + other.termArr[j].exp);
		}
		result = result + middle;
	}

	return result;
}
