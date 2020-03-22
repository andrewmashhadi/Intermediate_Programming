#include "ComplexVector.h"


ComplexVector::ComplexVector(const std::vector<Complex>& v) : c_vect(v) { }

Complex ComplexVector::operator[](size_t n) const
{
	return c_vect[n];
}

size_t ComplexVector::get_size() const
{
	return c_vect.size();
}


ComplexVector ComplexVector::operator+(const ComplexVector& obj) const
{
	std::vector<Complex> temp;
	// If the complex vectors being added are not the same size, notify the user and return an empty vector.
	if (c_vect.size() != (obj.c_vect).size())
	{
		std::cout << "\nERROR: Cannot add complex vector's term by term if they are of different sizes.";
		std::cout << "\n(The sum of these two vectors will be now an empty vector)" << std::endl;
		return ComplexVector(temp);
	}

	/* This loop is meant to run through the complex vectors being added, so we can add each complex object element 
	term by term. 
	*/
	for (size_t i = 0; i < c_vect.size(); ++i)
	{
		// Could also use (obj.c_vect)[i] but we make use of our overloaded [] here instead. 
		temp.push_back(c_vect[i] + obj[i]);
	}
	
	ComplexVector CV(temp);
	return CV;

}

ComplexVector ComplexVector::operator-(const ComplexVector& obj) const
{
	std::vector<Complex> temp;
	// If the complex vectors being subtracted are not the same size, notify the user and return an empty vector.
	if (c_vect.size() != (obj.c_vect).size())
	{
		std::cout << "\nERROR: Cannot subtract complex vector's term by term if they are of different sizes.";
		std::cout << "\n(The difference of these two vectors will now be an empty vector)" << std::endl;
		return ComplexVector(temp);
	}

	/* This loop is meant to run through the complex vectors being subtracted, so we can subtract each complex object element
	term by term. 
	*/
	for (size_t i = 0; i < c_vect.size(); ++i)
	{
		// Could also use (obj.c_vect)[i] but we make use of our overloaded [] here instead. 
		temp.push_back(c_vect[i] - obj[i]);
	}

	ComplexVector CV(temp);
	return CV;

}

ComplexVector ComplexVector::operator*(const ComplexVector& obj) const
{
	std::vector<Complex> temp;
	// If the vectors being mulitplied are not the same size, notify the user and return an empty vector.
	if (c_vect.size() != (obj.c_vect).size())
	{
		std::cout << "\nERROR: Cannot multiply complex vector's term by term if they are of different sizes.";
		std::cout << "\n(The product of these two vectors will now be an empty vector)" << std::endl;
		return ComplexVector(temp);
	}

	/* This loop is meant to run through the complex vectors being multiplied, so we can multiply each complex object element
	term by term. 
	*/
	for (size_t i = 0; i < c_vect.size(); ++i)
	{
		// Could also use (obj.c_vect)[i] but we make use of our overloaded [] here instead. 
		temp.push_back(c_vect[i] * obj[i]);
	}

	ComplexVector CV(temp);
	return CV;

}

ComplexVector ComplexVector::operator/(const ComplexVector& obj) const
{
	std::vector<Complex> temp;
	// If the vectors being divided are not the same size, notify the user and return an empty vector.
	if (c_vect.size() != (obj.c_vect).size())
	{
		std::cout << "\nERROR: Cannot divide complex vector's term by term if they are of different sizes.";
		std::cout << "\n(The quotient of these two vectors will now be an empty vector)" << std::endl;
		return ComplexVector(temp);
	}

	/* This loop is meant to run through the complex vectors being divided, so we can divide each complex object element
	term by term. 
	*/
	for (size_t i = 0; i < c_vect.size(); ++i)
	{
		// Could also use (obj.c_vect)[i] but we make use of our overloaded [] here instead. 
		temp.push_back(c_vect[i] / obj[i]);
	}

	ComplexVector CV(temp);
	return CV;

}

// NON-MEMBER FUNCTIONS DEFINITION

std::ostream& operator<<(std::ostream& out, const ComplexVector& obj)
{
	out << '{';

	/* If the complex vector to be displayed has any elements, we display them. The complex vector could have
	no elements if we have divided by zero.
	*/
	if (obj.get_size() != 0)
	{
		out << obj[0];

		// For loop is used to display the rest of the complex number object in the complex vector object, obj.
		for (size_t j = 1; j < obj.get_size(); ++j)
		{
			out << ", " << obj[j];
		}
	}
	out << '}';

	return out;
}


std::vector<Complex> recursive_fun(int n)
{
	std::vector<Complex> vect;

	/* Our stopping condition (base case) is when n equals 1. We return a one element vector with complex number
	1+i, which is the first element of the sequence given in the instructions.
	*/
	if (n == 1)
	{
		Complex temp_fn(1, 1);
		vect.push_back(temp_fn);
		return vect;
	}
	vect = recursive_fun(n - 1);
	Complex num(2 * (static_cast<double>(n) - 1), 3 * (static_cast<double>(n) - 1));
	Complex den(7, 5 * (static_cast<double>(n) - 1)* (static_cast<double>(n) - 1));
	Complex temp_fn = (num / den) * vect.back();
	vect.push_back(temp_fn);
	return vect;
}
