#include "Complex.h"


Complex::Complex():Re(0),Img(0) { }

Complex::Complex(double a):Re(a),Img(0) { }

Complex::Complex(double a, double b): Re(a), Img(b) { }

double Complex::get_real() const
{
	return Re;
}

double Complex::get_imaginary() const
{
	return Img;
}

Complex Complex::operator+(const Complex& obj) const
{
	double temp_a = this->Re + obj.Re;
	double temp_b = this->Img + obj.Img;
	Complex temp(temp_a, temp_b);
	return temp;
}

Complex Complex::operator-(const Complex& obj) const
{
	double temp_a = this->Re - obj.Re;
	double temp_b = this->Img - obj.Img;
	Complex temp(temp_a, temp_b);
	return temp;
}

Complex Complex::operator*(const Complex& obj) const
{
	double temp_a = (this->Re) * (obj.Re) - (this->Img) * (obj.Img);
	double temp_b = (this->Img) * (obj.Re) + (this->Re) * (obj.Img);
	Complex temp(temp_a, temp_b);
	return temp;
}

Complex Complex::operator/(const Complex& obj) const
{
	/* If there is an attempt to divide by zero, we notify the user of the error and return a complex 
	number object with a zero in the real part and a zero in the imaginary part.
	*/
	if (obj.Re == 0 && obj.Img == 0)
	{
		std::cout << " ERROR: Not allowed to divide by zero. ";
		return Complex();
	}
	double temp_a = ((this->Re) * (obj.Re) + (this->Img) * (obj.Img)) / ((obj.Re * obj.Re) + (obj.Img * obj.Img));
	double temp_b = ((this->Img) * (obj.Re) - (this->Re) * (obj.Img)) / ((obj.Re * obj.Re) + (obj.Img * obj.Img));
	Complex temp(temp_a, temp_b);
	return temp;
}

// NON-MEMBER FUNCTION DEFINITIONS

std::ostream& operator<<(std::ostream& out, const Complex& c_obj) 
{
	out << std::setw(5) << c_obj.get_real();
	/* If the object we want to display has a negative imaginary member variable, we print a minus sign before
	displaying the imaginary part and when we display the imaginary part, we display its absolute value since 
	we already displayed it as a negative. Otherwise, it is postive (or 0), and we display it with the '+' sign as is.
	*/
	if (c_obj.get_imaginary() < 0)
		out << " -" << std::setw(5) << -(c_obj.get_imaginary()) << "i ";
	else
		out << " +" << std::setw(5) << c_obj.get_imaginary() << "i ";

	return out;
}

