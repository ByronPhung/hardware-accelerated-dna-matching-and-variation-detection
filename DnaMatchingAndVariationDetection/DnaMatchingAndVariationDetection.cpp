// DnaMatchingAndVariationDetection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Sequence.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// Define the sample sequences.
	char sequence1[33] = "ACAAGATGCCATTGTCCCCCGGCCTCCTGCTG";

	// Create the necessary Sequence objects.
	Sequence s1;

	// Initialize the Sequence objects.
	s1.Initialize(sequence1);

	// Define a search key.
	const int SEARCH_KEY_SIZE = 3;
	char searchKey[SEARCH_KEY_SIZE + 1] = "CCC";

	// Test sequence 1 and search functionality.
	cout << "Sequence 1: \""; s1.PrintSequence(); cout << "\"" << endl;
	cout << "    - Size: " << s1.GetSize() << endl;
	cout << "Search Key: " << searchKey << endl;
	cout << "    - Keys Found: " << s1.Search(searchKey, SEARCH_KEY_SIZE) << endl;

	return 0;
}