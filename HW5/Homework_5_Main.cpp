#include "ComplexVector.h"


int main()
{
	Complex a_1(2, 4), b_1(3, 5), c_1(-1, -3), d_1(8, 10);
	Complex a_2(-10, 3.5), b_2(4, 7.3), c_2(2, -8), d_2(10, -142);
	std::vector<Complex> first = { a_1, b_1, c_1, d_1 };
	std::vector<Complex> second = { a_2, b_2, c_2, d_2 };
	ComplexVector v_1(first);
	ComplexVector v_2(second);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << std::setw(11) << " v1 = " << v_1 << std::endl;
	std::cout << std::setw(11) << " v2 = " << v_2 << std::endl;
	std::cout << std::setw(11) << " v1 + v2 = " << (v_1 + v_2) << std::endl;
	std::cout << std::setw(11) << " v1 - v2 = " << (v_1 - v_2) << std::endl;
	std::cout << std::setw(11) << " v1 * v2 = " << (v_1 * v_2) << std::endl;
	std::cout << std::setw(11) << " v1 / v2 = " << (v_1 / v_2) << std::endl;

	std::cout << "\n\nWriting Complex Sequence to File ...";
	std::ofstream out;
	out.open("ComplexSequence.txt");
	/* If the ofstream file, out, fails to open, notify the user and then end the program by returning 1 
	from the main. This may happen if we are not given access to open the "ComplexSequence.txt" file.
	*/
	if (out.fail())
	{
		std::cout << "ERROR: Output file \"ComplexSequence.txt\" failed to open." << std::endl;
		return 1;
	}
	std::vector<Complex> seq_vect = recursive_fun(6);
	ComplexVector CV_first_six(seq_vect);
	out << CV_first_six << std::endl;
	std::cout << "Done" << std::endl;
	out.close();

	return 0;
}
