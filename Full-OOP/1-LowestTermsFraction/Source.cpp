#include<iostream>
#include "Fraction.h"

static int greatestCommonDivisor(const int &a, const int &b) {
	int divisorCand = a < b ? a : b;

	// NOTE: there is a better algorithm for gcd, but we're trying to keep things simple
	while ((a % divisorCand != 0) || (b % divisorCand != 0)) {
		divisorCand--;
	}

	return divisorCand;
}

static int leastCommonMultiple(const int &a, const int &b) {
	return (a * b) / greatestCommonDivisor(a, b);
}

class LowestTermsFraction : public Fraction {
public:
	LowestTermsFraction(int nominator, int denominator) :
		Fraction(nominator / greatestCommonDivisor(nominator, denominator),
			denominator / greatestCommonDivisor(nominator, denominator)) {
	}

	LowestTermsFraction() :
		Fraction()
	{
	}
	friend std::ostream& operator<<(std::ostream& stream, const LowestTermsFraction &fraction);
	friend std::istream& operator>>(std::istream& stream, LowestTermsFraction &fraction);


	friend LowestTermsFraction operator*(const LowestTermsFraction &a, const LowestTermsFraction &b);
	friend LowestTermsFraction operator*(const LowestTermsFraction &a, const int &b);

	friend LowestTermsFraction operator/(const LowestTermsFraction &a, const LowestTermsFraction &b);
	friend LowestTermsFraction operator/(const LowestTermsFraction &a, const int &b);

	friend void operator*=(LowestTermsFraction &a, const LowestTermsFraction &b);
	friend void operator*=(LowestTermsFraction &a, const int &b);
	
	friend void operator/=(LowestTermsFraction &a, const LowestTermsFraction &b);
	friend void operator/=(LowestTermsFraction &a, const int &b);
	
	friend LowestTermsFraction operator+(const LowestTermsFraction &a, const LowestTermsFraction &b);

	LowestTermsFraction getReciprocal();
};

LowestTermsFraction operator/(const LowestTermsFraction &a, const LowestTermsFraction &b)
{
	return LowestTermsFraction(a.nominator * b.denominator, a.denominator * b.nominator);
}

LowestTermsFraction operator/(const LowestTermsFraction &a, const int &b)
{
	return LowestTermsFraction(a.nominator * 1, a.denominator * b);
}

LowestTermsFraction operator*(const LowestTermsFraction &a, const LowestTermsFraction &b)
{
	return LowestTermsFraction(a.nominator * b.nominator, a.denominator * b.denominator);
}

LowestTermsFraction operator*(const LowestTermsFraction &a, const int &b)
{
	return LowestTermsFraction(a.nominator * b, a.denominator * 1 );
}

void operator/=(LowestTermsFraction &a, const LowestTermsFraction &b)
{
	a.nominator *= b.denominator;
	a.denominator *= b.nominator;
	LowestTermsFraction tempA(a.nominator, a.denominator);
	a = tempA;
}

void operator*=(LowestTermsFraction &a, const LowestTermsFraction &b)
{
	a.nominator *= b.nominator;
	a.denominator *= b.denominator;
}

void operator*=(LowestTermsFraction &a, const int &b)
{
	a.nominator = (a.nominator * b);
}

void operator/=(LowestTermsFraction &a, const int &b)
{
	a.nominator *= 1;
	a.denominator *= b;
	LowestTermsFraction tempA(a.nominator, a.denominator);
	a = tempA;
}

LowestTermsFraction operator+(const LowestTermsFraction &a, const LowestTermsFraction &b) {
	int lcm = leastCommonMultiple(a.denominator, b.denominator);

	return LowestTermsFraction(a.nominator * (lcm / a.denominator) + b.nominator * (lcm / b.denominator), lcm);
}

std::ostream& operator<<(std::ostream& stream, const LowestTermsFraction &fraction) {
	if (fraction.nominator == 0 && fraction.denominator == 0) {
		stream << "NaN";
	}
	else {
		stream << fraction.nominator << "/" << fraction.denominator;
	}

	return stream;
}

std::istream& operator>>(std::istream& stream, LowestTermsFraction &fraction) {
	
	LowestTermsFraction temp;

	stream >> temp.nominator;
	char slash;
	stream >> slash;
	stream >> temp.denominator;

	fraction.nominator = temp.nominator  / greatestCommonDivisor(temp.nominator, temp.denominator);
	fraction.denominator = temp.denominator / greatestCommonDivisor(temp.nominator, temp.denominator);

	return stream;
}

LowestTermsFraction LowestTermsFraction::getReciprocal()
{
	LowestTermsFraction temp;
	temp.nominator = this->denominator;
	temp.denominator = this->nominator;

	return temp;
}

int main() {
	LowestTermsFraction a, b;

	std::cin >> a >> b;

	a *= 3;

	a /= 3;

	a *= b;

	a /= b;

	LowestTermsFraction multBy3 = a * 3;

	LowestTermsFraction multByB = a * b;

	LowestTermsFraction divBy3 = a / 3;

	LowestTermsFraction divByB = a / b;

	LowestTermsFraction reciprocalA = a.getReciprocal();

	std::cout << a << std::endl << b<< std::endl << multBy3 << std::endl << multByB << std::endl << divBy3 << std::endl << divByB << std::endl;
	return 0;
}
