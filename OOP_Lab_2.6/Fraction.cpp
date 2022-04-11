#include "Fraction.h"
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

Fraction::Fraction()
	: pair()
{}
Fraction::Fraction(const int first, const int second)
	: pair(first, second)
{}
Fraction::Fraction(const Fraction& m)
	: pair(m.pair)
{}

Fraction& Fraction::operator = (Fraction& s)
{
	pair.setFirst(s.pair.getFirst());
	pair.setSecond(s.pair.getSecond());
	return *this;
}

ostream& operator << (ostream& out, Fraction& s)
{
	out << string(s);
	return out;
}
istream& operator >> (istream& in, Fraction& s)
{
	int x, y;
	Fraction a;
	cout << "Ціла частина числа: "; cin >> x;
	do {
		cout << "Дробова частина числа: "; cin >> y;
	} while (y < 0);
	s.pair.setFirst(x);
	s.pair.setSecond(y);
	return in;
}

bool Less(Fraction a, Fraction b) {
	return (a.pair.getFirst() < b.pair.getFirst()) || (a.pair.getFirst() == b.pair.getFirst() && a.pair.getSecond() < b.pair.getSecond());
}
bool NLess(Fraction a, Fraction b) { return !Less(a, b); }
bool Great(Fraction a, Fraction b) {
	return (a.pair.getFirst() > b.pair.getFirst()) || (a.pair.getFirst() == b.pair.getFirst() && a.pair.getSecond() > b.pair.getSecond());
}
bool NGreat(Fraction a, Fraction b) { return !Great(a, b); }
bool Equal(Fraction a, Fraction b) {
	return a.pair.getFirst() == b.pair.getFirst() && a.pair.getSecond() == b.pair.getSecond();
}
bool NEqual(Fraction a, Fraction b) { return !Equal(a, b); }

Fraction::operator string () {
	stringstream ss;
	ss << "Число: " << pair.getFirst() << "." << pair.getSecond() << endl;
	return ss.str();
}

Fraction::Pair::Pair()
{
	setFirst(0);
	setSecond(0);
}
Fraction::Pair::Pair(const int first, const int second)
{
	setFirst(first);
	setSecond(second);
}
Fraction::Pair::Pair(const Pair& m)
{
	setFirst(m.first);
	setSecond(m.second);
}
Fraction::Pair & Fraction::Pair::operator ++ () {
	++first;
	return *this;
}
Fraction::Pair& Fraction::Pair::operator -- () {
	--first;
	return *this;
}
Fraction::Pair Fraction::Pair::operator ++ (int)
{
	Pair s(*this);
	first++;
	return s;
}
Fraction::Pair Fraction::Pair::operator -- (int)
{
	Pair s(*this);
	first--;
	return s;
}