/*
Andrew Mashhadi
ID: 905092387
PIC 10B
Programming Homework #5

Honesty Pledge:

I, Andrew Mashhadi, pledge that this is my own individual work,
which conforms to the guidelines of academic honesty as described
in the course syllabus.
*/



#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <fstream>
#include <iomanip>

class Complex
{
private: 
	double Re;
	double Img;

public:
	/* Default constructor for Complex objects. Sets the real and imaginary member fields equal to zero. */
	Complex();
	/* Constructor with one parameter for Complex objects. Sets the real member equal to the argument passed in,
	and the imaginary part is set to 0. This is because the real numbers are a subset of the complex numbers.
	@param a is the real part of the complex number, so we set Re to this value
	*/
	Complex(double a);

	/* Constructor with two parameters for Complex objects. Sets the real member equal to a, and the imaginary 
	part is set to b. 
	@param a is the real part of the complex number, so we set Re to this value
	@param b is the complex part of the complex number, so we set Img to this value
	*/
	Complex(double a, double b);

	/* Accessor member function to return the real part of this complex number object.
	@return the real part of this complex number object.
	*/
	double get_real() const;

	/* Accessor member function to return the imaginary part of this complex number object.
	@return the imaginary part of this complex number object.
	*/
	double get_imaginary() const;

	/* Overloading addition operator for adding a complex object to another complex object.
	@param obj is the other complex number object we are adding this object to
	@return a complex number object that is the mathematical sum of the two complex numbers. 
	*/
	Complex operator+(const Complex& obj) const;

	/* Overloading subtraction operator for subtracting a complex object by another complex object.
	@param bbj is the other complex number object we are subtracting this object by
	@return a complex number object that is the mathematical difference between two complex numbers.
	*/
	Complex operator-(const Complex& obj) const;

	/* Overloading mulitplication operator for multipying a complex object to another complex object.
	@param obj is the other complex number object we are multiplying this object to
	@return a complex number object that is the mathematical product of the two complex numbers.
	*/
	Complex operator*(const Complex& obj) const;

	/* Overloading division operator for dividing a complex object to another complex object.
	@param obj is the other complex number object we are divding this object by
	@return a complex number object that is the mathematical quotient of the two complex numbers.
	*/
	Complex operator/(const Complex& obj) const;

};

// NON-MEMBER FUNCTION DECLARATIONS

/* This non-member output stream operator overloading is meant to display our complex numbers as shown in the 
homework instructions (a + ib format) whenever we use an output stream operator.
@param out is the output stream object, could be used for displaying to consoles, files, or even stringstreams 
@param c_obj is the complex number object meant to be displayed
@return the same ostream object passed in, incase we want to display multiple times on the same line (multiple '<<' uses)
*/
std::ostream& operator<<(std::ostream& out, const Complex& c_obj);

#endif
