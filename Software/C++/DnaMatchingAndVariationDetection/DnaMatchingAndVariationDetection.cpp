#include "stdafx.h"
#include <iostream>
#include "Sequence.h"

using namespace std;

//=============================================================================
//  TEST CASE SWITCHES
//=============================================================================

#define ENABLED 1
#define DISABLED 0

#define TESTCASE_SEQUENCE_CPP_SEARCH_WITHVALIDTHREECHARACTERKEY_WITHDEFAULTSEQUENCESIZE_EXPECTTWOKEYSFOUND ENABLED
#define TESTCASE_SEQUENCE_CPP_SEARCH_WITHINVALIDTHREECHARACTERKEY_WITHDEFAULTSEQUENCESIZE_EXPECTZEROKEYSFOUND ENABLED
#define TESTCASE_SEQUENCE_CPP_SEARCH_WITHVALIDTHREECHARACTERKEY_WITHSPECIFIEDSEQUENCESIZE_EXPECTTHIRTEENKEYSFOUND ENABLED
#define TESTCASE_SEQUENCE_CPP_SEARCH_WITHINVALIDFOURCHARACTERKEY_WITHSPECIFIEDSEQUENCESIZE_EXPECTZEROKEYSFOUND ENABLED
#define TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTSAMECOMPARESEQUENCE_WITHDEFAULTSEQUENCESIZE_EXPECTNOVARIATIONS ENABLED
#define TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTDIFFERENTCOMPARESEQUENCE_WITHDEFAULTSEQUENCESIZE_EXPECTVARIATIONS ENABLED
#define TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTSAMECOMPARESEQUENCE_WITHSPECIFIEDSEQUENCESIZE_EXPECTNOVARIATIONS ENABLED
#define TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTDIFFERENTCOMPARESEQUENCE_WITHSPECIFIEDSEQUENCESIZE_EXPECTVARIATIONS ENABLED

//=============================================================================
//  TEST HELPERS
//=============================================================================

// Sequences
char SEQUENCE_DEFAULT[33] = "ACAAGATGCCATTGTCCCCCGGCCTCCTGCTG";
char SEQUENCE_DEFAULT_VARIATIONS[33] = "ACAAGATGCCATTAGCCCCCGGCCTCCTGCTC";
char SEQUENCE_SPECIFIED[369] = "ACAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGACCTCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGGCGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAATGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAATTACAGACCTGAA";
char SEQUENCE_SPECIFIED_VARIATIONS[369] = "ACAAGCAGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGCCCCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGAAATCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGGCGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAATGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAAAAACAGACCTGAA";

// Sequence Sizes
int SEQUENCE_SIZE_SPECIFIED = 368;

// Search Keys
char SEARCH_KEY_THREE_CHARACTERS_VALID[4] = "TGC";
char SEARCH_KEY_THREE_CHARACTERS_INVALID_DEFAULT[4] = "AAA";
char SEARCH_KEY_FOUR_CHARACTERS_INVALID_LONG[5] = "TTTT";

// Search Key Sizes
int SEARCH_KEY_SIZE_THREE_CHARACTERS = 3;
int SEARCH_KEY_SIZE_FOUR_CHARACTERS = 4;

//=============================================================================
//  TEST CASE PROTOTYPES
//=============================================================================

void TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithDefaultSequenceSize_ExpectTwoKeysFound();
void TestCase_Sequence_cpp_Search_WithInvalidThreeCharacterKey_WithDefaultSequenceSize_ExpectZeroKeysFound();
void TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithSpecifiedSequenceSize_ExpectThirteenKeysFound();
void TestCase_Sequence_cpp_Search_WithInvalidFourCharacterKey_WithSpecifiedSequenceSize_ExpectZeroKeysFound();
void TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithDefaultSequenceSize_ExpectNoVariations();
void TestCase_Sequence_cpp_Compare_AgainstDifferentCompareSequence_WithDefaultSequenceSize_ExpectVariations();
void TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithSpecifiedSequenceSize_ExpectNoVariations();
void TestCase_Sequence_cpp_CompareAgainstDifferentCompareSequence_WithSpecifiedSequenceSize_ExpectVariations();

//=============================================================================
//  MAIN EXECUTION
//=============================================================================

int _tmain(int argc, _TCHAR* argv[])
{
#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHVALIDTHREECHARACTERKEY_WITHDEFAULTSEQUENCESIZE_EXPECTTWOKEYSFOUND)
	TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithDefaultSequenceSize_ExpectTwoKeysFound();
#endif

#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHINVALIDTHREECHARACTERKEY_WITHDEFAULTSEQUENCESIZE_EXPECTZEROKEYSFOUND)
	TestCase_Sequence_cpp_Search_WithInvalidThreeCharacterKey_WithDefaultSequenceSize_ExpectZeroKeysFound();
#endif

#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHVALIDTHREECHARACTERKEY_WITHSPECIFIEDSEQUENCESIZE_EXPECTTHIRTEENKEYSFOUND)
	TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithSpecifiedSequenceSize_ExpectThirteenKeysFound();
#endif

#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHINVALIDFOURCHARACTERKEY_WITHSPECIFIEDSEQUENCESIZE_EXPECTZEROKEYSFOUND)
	TestCase_Sequence_cpp_Search_WithInvalidFourCharacterKey_WithSpecifiedSequenceSize_ExpectZeroKeysFound();
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTSAMECOMPARESEQUENCE_WITHDEFAULTSEQUENCESIZE_EXPECTNOVARIATIONS)
	TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithDefaultSequenceSize_ExpectNoVariations();
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTDIFFERENTCOMPARESEQUENCE_WITHDEFAULTSEQUENCESIZE_EXPECTVARIATIONS)
	TestCase_Sequence_cpp_Compare_AgainstDifferentCompareSequence_WithDefaultSequenceSize_ExpectVariations();
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTSAMECOMPARESEQUENCE_WITHSPECIFIEDSEQUENCESIZE_EXPECTNOVARIATIONS)
	TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithSpecifiedSequenceSize_ExpectNoVariations();
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTDIFFERENTCOMPARESEQUENCE_WITHSPECIFIEDSEQUENCESIZE_EXPECTVARIATIONS)
	TestCase_Sequence_cpp_CompareAgainstDifferentCompareSequence_WithSpecifiedSequenceSize_ExpectVariations();
#endif

	return 0;
}

#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHVALIDTHREECHARACTERKEY_WITHDEFAULTSEQUENCESIZE_EXPECTTWOKEYSFOUND)
void TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithDefaultSequenceSize_ExpectTwoKeysFound()
{
	cout << "BEGIN TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithDefaultSequenceSize_ExpectTwoKeysFound" << endl << endl;

	// Initialization
	Sequence sequence;
	sequence.Initialize(SEQUENCE_DEFAULT);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << endl;

	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "search key = " << SEARCH_KEY_THREE_CHARACTERS_VALID << endl;
	cout << endl;

	// Expected Output
	int expectedKeysFound = 2;
	cout << "// Expected Output" << endl;
	cout << "keys found: " << expectedKeysFound << endl;
	cout << endl;

	// Actual Output
	int actualKeysFound = sequence.Search(SEARCH_KEY_THREE_CHARACTERS_VALID, SEARCH_KEY_SIZE_THREE_CHARACTERS);
	cout << "// Actual Output" << endl;
	cout << "keys found: " << actualKeysFound << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualKeysFound == expectedKeysFound)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithDefaultSequenceSize_ExpectTwoKeysFound" << endl << endl;
}
#endif

#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHINVALIDTHREECHARACTERKEY_WITHDEFAULTSEQUENCESIZE_EXPECTZEROKEYSFOUND)
void TestCase_Sequence_cpp_Search_WithInvalidThreeCharacterKey_WithDefaultSequenceSize_ExpectZeroKeysFound()
{
	cout << "BEGIN TestCase_Sequence_cpp_Search_WithInvalidThreeCharacterKey_WithDefaultSequenceSize_ExpectZeroKeysFound" << endl << endl;

	// Initialization
	Sequence sequence;
	sequence.Initialize(SEQUENCE_DEFAULT);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << endl;

	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "search key = " << SEARCH_KEY_THREE_CHARACTERS_INVALID_DEFAULT << endl;
	cout << endl;

	// Expected Output
	int expectedKeysFound = 0;
	cout << "// Expected Output" << endl;
	cout << "keys found: " << expectedKeysFound << endl;
	cout << endl;

	// Actual Output
	int actualKeysFound = sequence.Search(SEARCH_KEY_THREE_CHARACTERS_INVALID_DEFAULT, SEARCH_KEY_SIZE_THREE_CHARACTERS);
	cout << "// Actual Output" << endl;
	cout << "keys found: " << actualKeysFound << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualKeysFound == expectedKeysFound)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_Search_WithInvalidThreeCharacterKey_WithDefaultSequenceSize_ExpectZeroKeysFound" << endl << endl;
}
#endif

#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHVALIDTHREECHARACTERKEY_WITHSPECIFIEDSEQUENCESIZE_EXPECTTHIRTEENKEYSFOUND)
void TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithSpecifiedSequenceSize_ExpectThirteenKeysFound()
{
	cout << "BEGIN TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithSpecifiedSequenceSize_ExpectThirteenKeysFound" << endl << endl;

	// Initialization
	Sequence sequence;
	sequence.Initialize(SEQUENCE_SPECIFIED, SEQUENCE_SIZE_SPECIFIED);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << endl;

	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "search key = " << SEARCH_KEY_THREE_CHARACTERS_VALID << endl;
	cout << endl;

	// Expected Output
	int expectedKeysFound = 13;
	cout << "// Expected Output" << endl;
	cout << "keys found: " << expectedKeysFound << endl;
	cout << endl;

	// Actual Output
	int actualKeysFound = sequence.Search(SEARCH_KEY_THREE_CHARACTERS_VALID, SEARCH_KEY_SIZE_THREE_CHARACTERS);
	cout << "// Actual Output" << endl;
	cout << "keys found: " << actualKeysFound << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualKeysFound == expectedKeysFound)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_Search_WithValidThreeCharacterKey_WithSpecifiedSequenceSize_ExpectThirteenKeysFound" << endl << endl;
}
#endif

#if (TESTCASE_SEQUENCE_CPP_SEARCH_WITHINVALIDFOURCHARACTERKEY_WITHSPECIFIEDSEQUENCESIZE_EXPECTZEROKEYSFOUND)
void TestCase_Sequence_cpp_Search_WithInvalidFourCharacterKey_WithSpecifiedSequenceSize_ExpectZeroKeysFound()
{
	cout << "BEGIN TestCase_Sequence_cpp_Search_WithInvalidFourCharacterKey_WithSpecifiedSequenceSize_ExpectZeroKeysFound" << endl << endl;

	// Initialization
	Sequence sequence;
	sequence.Initialize(SEQUENCE_SPECIFIED, SEQUENCE_SIZE_SPECIFIED);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << endl;

	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "search key = " << SEARCH_KEY_FOUR_CHARACTERS_INVALID_LONG << endl;
	cout << endl;

	// Expected Output
	int expectedKeysFound = 0;
	cout << "// Expected Output" << endl;
	cout << "keys found: " << expectedKeysFound << endl;
	cout << endl;

	// Actual Output
	int actualKeysFound = sequence.Search(SEARCH_KEY_FOUR_CHARACTERS_INVALID_LONG, SEARCH_KEY_SIZE_FOUR_CHARACTERS);
	cout << "// Actual Output" << endl;
	cout << "keys found: " << actualKeysFound << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualKeysFound == expectedKeysFound)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_Search_WithInvalidFourCharacterKey_WithSpecifiedSequenceSize_ExpectZeroKeysFound" << endl << endl;
}
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTSAMECOMPARESEQUENCE_WITHDEFAULTSEQUENCESIZE_EXPECTNOVARIATIONS)
void TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithDefaultSequenceSize_ExpectNoVariations()
{
	cout << "BEGIN TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithDefaultSequenceSize_ExpectNoVariations" << endl << endl;

	// Initialization
	Sequence sequence;
	sequence.Initialize(SEQUENCE_DEFAULT);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << "compareSequence = "; sequence.PrintSequence(); cout << endl;
	cout << endl;
	
	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "print variations (variations marked by brackets) = "; sequence.PrintVariations(sequence); cout << endl;
	cout << endl;

	// Expected Output
	bool expectedVariations = false;
	cout << "// Expected Output" << endl;
	cout << "variations = " << (expectedVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Actual Output
	bool actualVariations = sequence.Compare(sequence);
	cout << "// Actual Output" << endl;
	cout << "variations = " << (actualVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualVariations == expectedVariations)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithDefaultSequenceSize_ExpectNoVariations" << endl << endl;
}
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTDIFFERENTCOMPARESEQUENCE_WITHDEFAULTSEQUENCESIZE_EXPECTVARIATIONS)
void TestCase_Sequence_cpp_Compare_AgainstDifferentCompareSequence_WithDefaultSequenceSize_ExpectVariations()
{
	cout << "BEGIN TestCase_Sequence_cpp_Compare_AgainstDifferentCompareSequence_WithDefaultSequenceSize_ExpectVariations" << endl << endl;

	// Initialization
	Sequence sequence, compareSequence;
	sequence.Initialize(SEQUENCE_DEFAULT);
	compareSequence.Initialize(SEQUENCE_DEFAULT_VARIATIONS);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << "compareSequence = "; compareSequence.PrintSequence(); cout << endl;
	cout << endl;

	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "print variations (variations marked by brackets) = "; sequence.PrintVariations(compareSequence); cout << endl;
	cout << endl;

	// Expected Output
	bool expectedVariations = true;
	cout << "// Expected Output" << endl;
	cout << "variations = " << (expectedVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Actual Output
	bool actualVariations = sequence.Compare(compareSequence);
	cout << "// Actual Output" << endl;
	cout << "variations = " << (actualVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualVariations == expectedVariations)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_Compare_AgainstDifferentCompareSequence_WithDefaultSequenceSize_ExpectVariations" << endl << endl;
}
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTSAMECOMPARESEQUENCE_WITHSPECIFIEDSEQUENCESIZE_EXPECTNOVARIATIONS)
void TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithSpecifiedSequenceSize_ExpectNoVariations()
{
	cout << "BEGIN TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithSpecifiedSequenceSize_ExpectNoVariations" << endl << endl;

	// Initialization
	Sequence sequence;
	sequence.Initialize(SEQUENCE_SPECIFIED, SEQUENCE_SIZE_SPECIFIED);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << "compareSequence = "; sequence.PrintSequence(); cout << endl;
	cout << endl;

	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "print variations (variations marked by brackets) = "; sequence.PrintVariations(sequence); cout << endl;
	cout << endl;

	// Expected Output
	bool expectedVariations = false;
	cout << "// Expected Output" << endl;
	cout << "variations = " << (expectedVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Actual Output
	bool actualVariations = sequence.Compare(sequence);
	cout << "// Actual Output" << endl;
	cout << "variations = " << (actualVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualVariations == expectedVariations)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_Compare_AgainstSameCompareSequence_WithSpecifiedSequenceSize_ExpectNoVariations" << endl << endl;
}
#endif

#if (TESTCASE_SEQUENCE_CPP_COMPARE_AGAINSTDIFFERENTCOMPARESEQUENCE_WITHSPECIFIEDSEQUENCESIZE_EXPECTVARIATIONS)
void TestCase_Sequence_cpp_CompareAgainstDifferentCompareSequence_WithSpecifiedSequenceSize_ExpectVariations()
{
	cout << "BEGIN TestCase_Sequence_cpp_CompareAgainstDifferentCompareSequence_WithSpecifiedSequenceSize_ExpectVariations" << endl << endl;

	// Initialization
	Sequence sequence, compareSequence;
	sequence.Initialize(SEQUENCE_SPECIFIED, SEQUENCE_SIZE_SPECIFIED);
	compareSequence.Initialize(SEQUENCE_SPECIFIED_VARIATIONS, SEQUENCE_SIZE_SPECIFIED);
	cout << "// Initialization" << endl;
	cout << "sequence = "; sequence.PrintSequence(); cout << endl;
	cout << "compareSequence = "; compareSequence.PrintSequence(); cout << endl;
	cout << endl;

	// Test Implementation
	cout << "// Test Implementation" << endl;
	cout << "print variations (variations marked by brackets) = "; sequence.PrintVariations(compareSequence); cout << endl;
	cout << endl;

	// Expected Output
	bool expectedVariations = true;
	cout << "// Expected Output" << endl;
	cout << "variations = " << (expectedVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Actual Output
	bool actualVariations = sequence.Compare(compareSequence);
	cout << "// Actual Output" << endl;
	cout << "variations = " << (actualVariations ? "TRUE" : "FALSE") << endl;
	cout << endl;

	// Test Case Status
	cout << "// Test Case Status" << endl;
	cout << "status = ";
	if (actualVariations == expectedVariations)
	{
		cout << "PASS";
	}

	else
	{
		cout << "FAIL";
	}
	cout << endl;

	cout << endl << "END TestCase_Sequence_cpp_CompareAgainstDifferentCompareSequence_WithSpecifiedSequenceSize_ExpectVariations" << endl << endl;
}
#endif