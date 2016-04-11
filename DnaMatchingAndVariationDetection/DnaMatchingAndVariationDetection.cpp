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
	char sequence3[33] = "ACAAGATGCCATTAGCCCCCGGCCTCCTGCTC";
	char sequence4[369] = "ACAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGACCTCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGGCGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAATGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAATTACAGACCTGAA";
	char sequence5[369] = "ACAAGCAGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGCCCCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGAAATCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGGCGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAATGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAAAAACAGACCTGAA";

	// Create the necessary Sequence objects.
	Sequence s1, s2, s3, s4, s5;

	// Initialize the Sequence objects.
	s1.Initialize(sequence1);
	s2.Initialize(sequence2, 16);
	s3.Initialize(sequence3);
	s4.Initialize(sequence4, 368);
	s5.Initialize(sequence5, 368);

	// Define search keys.
	const int SEARCH_KEY_SIZE_1 = 3;
	char searchKey1[SEARCH_KEY_SIZE_1 + 1] = "CCC";
	char searchKey2[SEARCH_KEY_SIZE_1 + 1] = "AAA";
	const int SEARCH_KEY_SIZE_2 = 8;
	char searchKey3[SEARCH_KEY_SIZE_2 + 1] = "CTCCGGGG";
	char searchKey4[SEARCH_KEY_SIZE_2 + 1] = "CTGCTGCG";
	const int SEARCH_KEY_SIZE_3 = 16;
	char searchKey5[SEARCH_KEY_SIZE_3 + 1] = "ACAAGATGCCATTGTC";
	char searchKey6[SEARCH_KEY_SIZE_3 + 1] = "AAAAAAAAAAAAAAAA";

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

	// Test sequence 1 (default sequence size) and compare functionality.
	cout << "Sequence 1: \""; s1.PrintSequence(); cout << "\"" << endl;
	cout << "    - Size: " << s1.GetSize() << endl;
	cout << "Compared with Sequence 1: \""; s1.PrintSequence(); cout << "\"" << endl;
	cout << "    - Variations: " << (s1.Compare(s1) ? "TRUE" : "FALSE") << endl;
	if (s1.Compare(s1)) {
		cout << "                  "; s1.PrintVariations(s1); cout << endl;
	}
	cout << "Compared with Sequence 3: \""; s3.PrintSequence(); cout << "\"" << endl;
	cout << "    - Variations: " << (s1.Compare(s3) ? "TRUE" : "FALSE") << endl;
	if (s1.Compare(s3)) {
		cout << "                  "; s1.PrintVariations(s3); cout << endl << endl;
	}

	// Test sequence 4 (large sequence size) and search functionality.
	cout << "Sequence 4: \""; s4.PrintSequence(); cout << "\"" << endl;
	cout << "    - Size: " << s4.GetSize() << endl;
	cout << "Search Key: " << searchKey5 << endl;
	cout << "    - Keys Found: " << s4.Search(searchKey5, SEARCH_KEY_SIZE_3) << endl;
	cout << "Search Key: " << searchKey6 << endl;
	cout << "    - Keys Found: " << s4.Search(searchKey6, SEARCH_KEY_SIZE_3) << endl << endl;

	// Test sequence 4 (large sequence size) and compare functionality.
	cout << "Sequence 4: \""; s4.PrintSequence(); cout << "\"" << endl;
	cout << "    - Size: " << s4.GetSize() << endl;
	cout << "Compared with Sequence 4: \""; s4.PrintSequence(); cout << "\"" << endl;
	cout << "    - Variations: " << (s1.Compare(s4) ? "TRUE" : "FALSE") << endl;
	if (s4.Compare(s4)) {
		cout << "                  "; s4.PrintVariations(s4); cout << endl;
	}
	cout << "Compared with Sequence 5: \""; s5.PrintSequence(); cout << "\"" << endl;
	cout << "    - Variations: " << (s4.Compare(s5) ? "TRUE" : "FALSE") << endl;
	if (s4.Compare(s5)) {
		cout << "                  "; s4.PrintVariations(s5); cout << endl << endl;
	}

	return 0;
}