#include "File_Prop.h"



iFile_W_Props::iFile_W_Props(const std::string& n) : f_name(n)
{
	file.open(f_name);

	/* If the file failed to open, this while loop will continue to prompt user until the user enters 
	an input file that can be opened properly without any issues.
	*/
	while (file.fail())
	{
		std::string name;
		std::cout << "ERROR: Input file " << f_name << " failed to open. " << std::endl;

		// Resets the fail flag that was triggered by the previous attempt to open the file.
		file.clear();		
		std::cout << "Re-Enter the file name or try another file: ";
		std::getline(std::cin, name);
		f_name = name;
		file.open(f_name);
	}
}

std::string iFile_W_Props::get_name() const
{
	return f_name;
}

// Conversion from std::streamoff to long warning. Must be a long long to avoid data loss.
long long iFile_W_Props::num_chars() 	
{
	/* To use this function along with other functions more than once, we have to either use clear() or we 
	have to close and reopen file after setting off the eof flag.
	*/
	file.clear();					    
	file.seekg(0, std::ios::end);
	return file.tellg();

}

size_t iFile_W_Props::num_words()		
{
	/* To use this function along with other functions more than once, we have to either use clear() or we
	have to close and reopen file after setting off the eof flag.
	*/
	file.clear();						
	file.seekg(0, std::ios::beg);
	std::string dummy_word;
	size_t num_words = 0;
	/* Using the while loop based on the condition that the next word can be read from the file with no error, we
	count each time the loop runs through a new word to get the total words in the file. An error flag will 
	be set off when we try to extract data from the file after the end of the file, and the loop will terminate.
	*/
	while (file >> dummy_word)
		num_words++;
	
	return num_words;
}

size_t iFile_W_Props::num_lines()	
{
	/* To use this function along with other functions more than once, we have to either use clear() or we
	have to close and reopen file after setting off the eof flag.
	*/
	file.clear();					 
	file.seekg(0, std::ios::beg);	 
	std::string dummy_line;
	size_t num_lines = 0;
	
	/* Using the while loop based on the condition that the next line has been read from the file with no error, we
	count each time the loop runs through a new line to get the total lines in the file. An error flag will
	be set off when we try to extract data from the file after the end of the file, and the loop will terminate.
	Getline also considers the end of the file as another dilimeter, so it will stop reading the line appropriately.
	*/
	while (std::getline(file, dummy_line))	
		num_lines++;

	return num_lines;
}

bool iFile_W_Props::operator<(iFile_W_Props& obj)		
{
	/* If the number of lines in this object's input file is less than the number of lines in our parameter's 
	obj's input file, we return true. Otherwise we return false.
	*/
	if (num_lines() < obj.num_lines())	
		return true;
	else
		return false;
}

bool iFile_W_Props::operator>(iFile_W_Props& obj)
{
	/* If the number of lines in this object's input file is more than the number of lines in our parameter's
	obj's input file, we return true. Otherwise we return false.
	*/
	if (num_lines() > obj.num_lines())	
		return true;
	else
		return false;
}

bool iFile_W_Props::operator==(iFile_W_Props& obj)
{
	/* If the number of lines in this object's input file is the same as the number of lines in our parameter's
	obj's input file, we return true. Otherwise we return false.
	*/
	if (num_lines() == obj.num_lines())	
		return true;
	else
		return false;
}

iFile_W_Props::~iFile_W_Props()
{
	file.close();
}

// NON-MEMBER FUNCTION DEFINITION

void print_props(std::ostream& out, iFile_W_Props& in)		
{
	out << "File Name: " << in.get_name() << std::endl;
	out << "Number of characters: " << in.num_chars() << std::endl;
	out << "Number of words: " << in.num_words() << std::endl;
	out << '\n';
}
