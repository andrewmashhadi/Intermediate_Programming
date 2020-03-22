#include "File_Prop.h"



int main()
{
	std::string f1_name, f2_name;

	std::cout << "Enter the name of file 1: ";
	std::getline(std::cin, f1_name);
	iFile_W_Props infile_n1(f1_name);

	std::cout << "Enter the name of file 2: ";
	std::getline(std::cin, f2_name);
	iFile_W_Props infile_n2(f2_name);

	std::ofstream outfile;
	outfile.open("Properties.txt");

	/* If the output file "Properties.txt" fails to open (for example we may not be given permission), then we 
	tell the user there was an error and end the program right away.
	*/
	if (outfile.fail())
	{
		std::cout << "ERROR: Output file \"Properties.txt\" failed to open.\n" << std::endl;
		return 1;
	}

	print_props(outfile, infile_n1);
	print_props(outfile, infile_n2);
	
	/* Using our overloaded boolean operators from our iFile_W_Props class, we compare the number of lines in 
	each iFile_W_Props object's input file */

	// If the file in the infile_n1 object has less lines than the file in the infile_n2 object, we display the result.
	if (infile_n1 < infile_n2)
		outfile << "The file named \"" << infile_n1.get_name() << "\" has less lines than \"" << infile_n2.get_name() << "\"." << std::endl;

	// Otherwise if the file in the infile_n1 object has more lines than the file in the infile_n2 object, we display the result.
	else if (infile_n1 > infile_n2)
		outfile << "The file named \"" << infile_n1.get_name() << "\" has more lines than \"" << infile_n2.get_name() << "\"." << std::endl;

	// If the file in the infile_n1 object has the same number of lines as the file in the infile_n2 object, we display the result.
	else if (infile_n1 == infile_n2)
		outfile << "The file named \"" << infile_n1.get_name() << "\" has the same number of lines as \"" << infile_n2.get_name() << "\"." << std::endl;

	outfile.close();

	return 0;

}