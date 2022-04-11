#pragma once
#include <string>
#include <sstream>
using namespace std;
class Fraction
{
public:
	class Pair
	{
	private:
		int first;
		int second;
	public:
		int getFirst() { return first; }
		int getSecond() { return second; }

		void setFirst(int value) { first = value; }
		void setSecond(int value) { second = value; }

		Pair();
		Pair(const int, const int);
		Pair(const Pair&);
		Pair& operator ++ ();
		Pair& operator -- ();
		Pair operator ++ (int);
		Pair operator -- (int);
	};
	Pair pair;
public:
	Fraction();
	Fraction(const int name, const int age);
	Fraction(const Fraction& m);

	friend bool Less(Fraction x, Fraction y);
	friend bool NLess(Fraction x, Fraction y);
	friend bool Great(Fraction x, Fraction y);
	friend bool NGreat(Fraction x, Fraction y);
	friend bool Equal(Fraction x, Fraction y);
	friend bool NEqual(Fraction x, Fraction y);

	Fraction& operator = (Fraction& s);
	friend ostream& operator << (ostream&, Fraction&);
	friend istream& operator >> (istream&, Fraction&);

	operator string ();
};