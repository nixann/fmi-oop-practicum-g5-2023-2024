#include <iostream>
#include <cassert>

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

class Rational {
private:
	int numerator;
	int denominator;
	void simplify();

public:
	Rational(int numerator, int denominator);

	void print() const;

	Rational add(const Rational& rhs);

	Rational subtract(const Rational& rhs);

	Rational multiply(const Rational& rhs);

	Rational divide(const Rational& rhs);
};

Rational::Rational(int numerator, int denominator) {
	assert(denominator != 0);
	this->numerator = numerator;
	this->denominator = denominator;

  this->simplify();
}

void Rational::simplify(){
	int a = this->numerator;
	int b = this->denominator;

  int gcd_for_rat = gcd(this->numerator, this->denominator);

	this->numerator /= gcd_for_rat;
	this->denominator /= gcd_for_rat;
}


void Rational::print() const {
	std::cout << numerator << "/" << denominator << std::endl;
}

Rational Rational::add(const Rational& rhs) {
	return Rational(this->numerator * rhs.denominator + rhs.numerator * this->denominator, this->denominator * rhs.denominator);
}

Rational Rational::subtract(const Rational& rhs) {
	return Rational(this->numerator * rhs.denominator - rhs.numerator * this->denominator, this->denominator * rhs.denominator);
}

Rational Rational::multiply(const Rational& rhs) {
	return Rational(this->numerator * rhs.numerator, this->denominator * rhs.denominator);
}

Rational Rational::divide(const Rational& rhs) {
	return Rational(this->numerator * rhs.denominator, this->denominator * rhs.numerator);
}

int main() {
  return 0;
}
