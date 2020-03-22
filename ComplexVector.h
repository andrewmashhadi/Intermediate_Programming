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



#ifndef COMPLEX_VECTOR_H
#define COMPLEX_VECTOR_H

#include "Complex.h"
#include <vector>


class ComplexVector
{
private:
	std::vector<Complex> c_vect;
public:
	/* The only constructor for our complex vector object. It accepts a vector of complex number objects, and sets
	the vector member field equal to it.
	@param v is a vector of Complex objects that c_vect will be set to.
	*/
	ComplexVector(const std::vector<Complex>& v);

	/* We overload the brackets to make this complex vector object to be more like a standard vector. This will act as
	our accessor member function that returns the value of the nth element of our vector of complex object member field.
	@param n is the index of which complex number we want to access from c_vect
	@return a copy of the complex number object that is the nth element of our c_vect. Notice it is not a referenced
	return, so it is not possible to modify the nth element in the c_vect like we can with regular vector brackets.
	*/
	Complex operator[](size_t n) const;	

	/* Accessor member function meant to return the length of our vector of complex objects, c_vect.
	@return the size of c_zect
	*/
	size_t get_size() const;

	/* Overloading addition operator for adding a complex vector object to another complex object. We will add
	the ith complex number object of this complex vector to the ith complex number object of obj's complex vector,
	to create a new ComplexVector with the ith term as the sum of the ith terms from the two vectors being added. (term by term)
	@param obj is the other complex vector object we are adding this object to
	@return a complex vector object that is the term by term sum of the two complex vectors being added
	*/
	ComplexVector operator+(const ComplexVector& obj) const;

	/* Overloading subtraction operator for subtracting a complex vector object from another complex object. We will subtract
	the ith complex number object of this complex vector by the ith complex number object of obj's complex vector,
	to create a new ComplexVector with the ith term as the difference of the ith terms of the two vectors being subtracting. (term by term)
	@param obj is the other complex vector object we are subtracting this object by
	@return a complex vector object that is the term by term difference of the two complex vectors being subtracted
	*/
	ComplexVector operator-(const ComplexVector& obj) const;

	/* Overloading multiplication operator for multiplying the complex vector object to another complex object. We will multiply
	the ith complex number object of this complex vector to the ith complex number object of obj's complex vector,
	to create a new ComplexVector with the ith term as the product of the ith terms of the two vectors being multiplied. (term by term)
	@param obj is the other complex vector object we are multiplying this object to
	@return a complex vector object that is the term by term product of the two complex vectors being multiplied
	*/
	ComplexVector operator*(const ComplexVector& obj) const;

	/* Overloading division operator for dividing a complex vector object from another complex object. We will divide
	the ith complex number object of this complex vector by the ith complex number object of obj's complex vector,
	to create a new ComplexVector with the ith term as the quotient of the ith terms of the two vectors being divided (term by term)
	@param obj is the other complex vector object we are dividing this object by
	@return a complex vector object that is the term by term quotient of the two complex vectors being divided
	*/
	ComplexVector operator/(const ComplexVector& obj) const;

};

// NON-MEMBER FUNCTION DECLARATIONS

/* This non-member output stream operator overloading is meant to display our complex vector as shown in the
homework instructions ({ z_1, z_2, z_3 }  format) whenever we use an output stream operator with a complex vector.
@param out is the output stream object, could be used for displaying to consoles, files, or even stringstreams
@param obj is the complex vector object meant to be displayed
@return the same ostream object passed in, incase we want to dipslay multiple times on the same line (multiple '<<' uses)
*/
std::ostream& operator<<(std::ostream& out, const ComplexVector& obj);

/* This is the recursive function meant to compute the values of the recursive sequence given to us in the
homework instructions. It will store the values for every element of the sequence that is less than or equal to n inside a vector and 
will return that vector. 
@param the nth element of the recursive sequence given to us on the homeowork.
@return the vector of complex objects that contains each value of the recursive sequence from 1 to n. 
*/
std::vector<Complex> recursive_fun(int n);

#endif
