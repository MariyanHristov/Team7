#include "ComplexNum.h"

ComplexNum::ComplexNum()
{
	real = imaginary = 0;
}

ComplexNum::ComplexNum(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

ComplexNum& ComplexNum::operator+=(const ComplexNum& other)
{
	real += other.real;
	imaginary += other.imaginary;

	return *this;
}

ComplexNum& ComplexNum::operator-=(const ComplexNum& other)
{
	real -= other.real;
	imaginary -= other.imaginary;

	return *this;
}

ComplexNum& ComplexNum::operator*=(const ComplexNum& other)
{
	double oldReal = real;
	real = real * other.real - imaginary * other.imaginary;
	imaginary = oldReal * other.imaginary + imaginary * other.real;
	return *this;
}

ComplexNum& ComplexNum::operator/=(const ComplexNum& other)
{
	Complex conjugated = other.getConjugated(); //взимаме комплексно спрегнатата на другата дроб (b)

	Complex otherCopy(other);// копираме другата (b), за да не я промяняме.

	//Умножаваме двете по комплексно спрегнатата.
	*this *= conjugated;
	otherCopy *= conjugated; //Тук трябва да остане само реална част.

	if (otherCopy.real != 0)
	{
		real /= otherCopy.real;
		imaginary /= otherCopy.real;
	}

	return *this;
}

ComplexNum operator+(ComplexNum& first, const ComplexNum& second)
{
	ComplexNum temp(first);
	temp += second;
	return temp;
}

ComplexNum operator-(ComplexNum& first, const ComplexNum& second)
{

	ComplexNum temp(first);
	temp -= second;
	return temp;
}

ComplexNum operator*(ComplexNum& first, const ComplexNum& second)
{
	ComplexNum temp(first);
	temp *= second;
	return temp;
}

ComplexNum operator/(ComplexNum& first, const ComplexNum& second)
{
	ComplexNum temp(first);
	temp /= second;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const ComplexNum& complexNum)
{
	if (complexNum.imaginary > 0)
		os << complexNum.real << "+" << complexNum.imaginary << "*i";
	else if (complexNum.imaginary < 0)
		os << complexNum.real << complexNum.imaginary << "*i";
	else
		os << complexNum.real;
	return os;
}

std::istream& operator>>(std::istream& is, ComplexNum& complexNum)
{
	is >> complexNum.real >> complexNum.imaginary;
	return is;
}

Complex Complex::getConjugated() const
{
	Complex result(*this);
	result.imaginary *= -1;

	return result;
}
