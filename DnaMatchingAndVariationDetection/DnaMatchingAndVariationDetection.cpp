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
	char sequence2[17] = "CTGCTGCTCTCCGGGG";

	// Create the necessary Sequence objects.
	Sequence s1, s2;

	// Initialize the Sequence objects.
	s1.Initialize(sequence1);
	s2.Initialize(sequence2, 16);

	// Define search keys.
	const int SEARCH_KEY_SIZE_1 = 3;
	char searchKey1[SEARCH_KEY_SIZE_1 + 1] = "CCC";
	char searchKey2[SEARCH_KEY_SIZE_1 + 1] = "AAA";
	const int SEARCH_KEY_SIZE_2 = 8;
	char searchKey3[SEARCH_KEY_SIZE_2 + 1] = "CTCCGGGG";
	char searchKey4[SEARCH_KEY_SIZE_2 + 1] = "CTGCTGCG";

	// Test sequence 1 (default sequence size) and search functionality.
	cout << "Sequence 1: \""; s1.PrintSequence(); cout << "\"" << endl;
	cout << "    - Size: " << s1.GetSize() << endl;
	cout << "Search Key: " << searchKey1 << endl;
	cout << "    - Keys Found: " << s1.Search(searchKey1, SEARCH_KEY_SIZE_1) << endl;
	cout << "Search Key: " << searchKey2 << endl;
	cout << "    - Keys Found: " << s1.Search(searchKey2, SEARCH_KEY_SIZE_1) << endl << endl;

	// Test sequence 2 (specified sequence size) and search functionality.
	cout << "Sequence 2: \""; s2.PrintSequence(); cout << "\"" << endl;
	cout << "    - Size: " << s2.GetSize() << endl;
	cout << "Search Key: " << searchKey3 << endl;
	cout << "    - Keys Found: " << s2.Search(searchKey3, SEARCH_KEY_SIZE_2) << endl;
	cout << "Search Key: " << searchKey4 << endl;
	cout << "    - Keys Found: " << s2.Search(searchKey4, SEARCH_KEY_SIZE_2) << endl << endl;

	return 0;
}