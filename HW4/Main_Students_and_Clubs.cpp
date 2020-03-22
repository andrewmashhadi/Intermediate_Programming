#include "Students_and_Clubs.h"



int main()
{
	std::string officer_names[OFFICER_ROLES];
	get_officer_names(officer_names);

	std::vector<Student*> officer_ptrs;
	size_t i = 0;

	/* We run this do-while loop to fill officer_ptrs with only uniquely named Student objects. At each 
	iteration of i, this loop tests to make sure that the name of the next student officer has not been 
	used for a previously recorded officer position before adding another student pointer (and creating the corresponding 
	student object) to the officer_ptrs vector.
	*/
	do
	{
		bool rec_already = false;

		/* This loop runs through all the officer names in our string array to push only uniquely named
		new student object pointers into our officer_ptrs vector. It changes the recorded already bool to 
		true if the name of the next officer is the same as any of the previous elements in the officer names 
		array.
		*/
		for (size_t j = 0; j < i; j++)
		{
			/* If the ith named string in the officer_names array is the same as any of the elements before
			it, set rec_already to true.
			*/
			if (officer_names[i] == officer_names[j])
				rec_already = true;
		}
		/* If this rec_already is false, then we have a new unique name, so we push a student pointer to a 
		new student object with this name into our officer_ptrs vector.
		*/
		if (!rec_already)
		{
			officer_ptrs.push_back(new Student(officer_names[i]));
		}
		i++;
	} while (i < OFFICER_ROLES);

	Student* pres_ptr = nullptr;
	Student* vp_ptr = nullptr;
	Student* sec_ptr = nullptr;
	Student* tres_ptr = nullptr;

	/* This for loop searches through each of the uniquely named elements of the officers_ptr and if the 
	name of the kth student object pointer element corresponds to the president, vice-president, secretary,
	or treasurer name, we assign the corressponding officer pointer to it. This is because the assignment 
	instructions say that we have to pass individual pointers to students for each officer in the 
	constructor when we create our student club object, even if they point to the same location.
	*/
	for (size_t k = 0; k < officer_ptrs.size(); k++)
	{
		/* If the kth student object that officer_ptrs points to has the same name as the president, then 
		we set our president pointer to the kth student address in the officer_ptr.
		*/
		if (officer_ptrs[k]->get_name() == officer_names[0])
			pres_ptr = officer_ptrs[k];

		/* If the kth student object that officer_ptrs points to has the same name as the vice-president, 
		then we set our vice-president pointer to the kth student address in the officer_ptr.
		*/
		if (officer_ptrs[k]->get_name() == officer_names[1])
			vp_ptr = officer_ptrs[k];

		/* If the kth student object that officer_ptrs points to has the same name as the secretary, then
		we set our secretary pointer to the kth student address in the officer_ptr.
		*/
		if (officer_ptrs[k]->get_name() == officer_names[2])
			sec_ptr = officer_ptrs[k];

		/* If the kth student object that officer_ptrs points to has the same name as the treasurer, then
		we set our treasurer pointer to the kth student address in the officer_ptr.
		*/
		if (officer_ptrs[k]->get_name() == officer_names[3])
			tres_ptr = officer_ptrs[k];	
	}

	StudentClub Mathletes(pres_ptr, vp_ptr, sec_ptr, tres_ptr, officer_ptrs);
	Mathletes.new_club_members();

	std::cout << "\nMATHLETES( " << Mathletes.number_members() << " total members)" << std::endl;
	Mathletes.print_officers();
	
	return 0;
}
