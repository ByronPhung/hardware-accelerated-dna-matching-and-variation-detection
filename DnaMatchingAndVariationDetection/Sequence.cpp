#include "stdafx.h"
#include <iostream>
#include "Sequence.h"

using namespace std;

// Define the default sequence size.
const int DEFAULT_SEQUENCE_SIZE = 32;

//=============================================================================
//  CONSTRUCTOR
//=============================================================================

Sequence::Sequence() {
	// Empty Default Constructor
}

//=============================================================================
//  CLASS MEMBER FUNCTIONS
//=============================================================================

//=============================================================================
//  Name         : Initialize
//  Usage        : sequence.Initialize(inputSequence);
//  Description  : Initializes the Sequence object with the default size and
//                 input sequence.
//  Parameters   : inputSequence		 - Sequence to store
//  Global Data  : DEFAULT_SEQUENCE_SIZE - Default sequence size
//  Return Value : <None>
//==============================================================================

void Sequence::Initialize(char inputSequence[]) {
	// Store the default size and the input sequence.
	size = DEFAULT_SEQUENCE_SIZE;
	StoreSequence(inputSequence);
}

//=============================================================================
//  Name         : Initialize
//  Usage        : sequence.Initialize(inputSequence, inputSize);
//  Description  : Initializes the Sequence object with the input size and
//                 input sequence.
//  Parameters   : inputSequence - Sequence to store
//                 inputSize     - Size of input sequence
//  Global Data  : <None>
//  Return Value : <None>
//==============================================================================

void Sequence::Initialize(char inputSequence[], int inputSize) {
	// Store the input size and the input sequence.
	size = inputSize;
	StoreSequence(inputSequence);
}

//=============================================================================
//  Name         : StoreSequence
//  Usage        : StoreSequence(inputSequence);
//  Description  : Stores the input sequence.
//  Parameters   : inputSequence - Sequence to store
//  Global Data  : <None>
//  Return Value : <None>
//==============================================================================

void Sequence::StoreSequence(char inputSequence[]) {
	// Store the input sequence.
	for (int i = 0; i < size; i++) {
		sequence[i] = inputSequence[i];
	}
}

//=============================================================================
//  Name         : GetSequence
//  Usage        : sequence.GetSequence(sequenceArray);
//  Description  : Returns the sequence to the sequenceArray pointer.
//  Parameters   : sequenceArray - Pointer to sequence array
//  Global Data  : <None>
//  Return Value : <None>
//==============================================================================

void Sequence::GetSequence(char* sequenceArray) {
	// Return the sequence via the sequenceArray pointer.
	for (int i = 0; i < size; i++) {
		sequenceArray[i] = sequence[i];
	}
}

//=============================================================================
//  Name         : PrintSequence
//  Usage        : sequence.PrintSequence();
//  Description  : Prints the stored sequence.
//  Parameters   : <None>
//  Global Data  : <None>
//  Return Value : <None>
//==============================================================================

void Sequence::PrintSequence() {
	for (int i = 0; i < size; i++) {
		cout << sequence[i];
	}
}

//=============================================================================
//  Name         : GetSize
//  Usage        : int size = sequence.GetSize();
//  Description  : Returns the size of the stored sequence.
//  Parameters   : <None>
//  Global Data  : <None>
//  Return Value : Returns the size of the stored sequence.
//==============================================================================

int Sequence::GetSize() {
	return size;
}

//=============================================================================
//  Name         : Search
//  Usage        : int numKeysFound = sequence.Search(key);
//  Description  : Searches the current sequence for the specified key.
//  Parameters   : key - Sequence key to search for.
//  Global Data  : <None>
//  Return Value : Returns the number of keys found.
//==============================================================================

int Sequence::Search(char key[], int keySize) {
	// Track the number of keys found in this search.
	int numKeysFound = 0;

	// Search in increments of the key size.
	for (int i = 0; i <= size - keySize; i++) {
		// Declare j outside of the next for loop to determine if there was a
		// key match.
		int j = 0;

		// Check if the key matches the current keySize-sized sequence word.
		for (j = 0; j < keySize; j++) {
			// If there is no match, then break.
			if (sequence[i + j] != key[j]) {
				break;
			}
		}

		// If the j count is keySize, then increment the number of keys found.
		if (j == keySize) {
			numKeysFound++;
		}
	}

	// Return the number of keys found.
	return numKeysFound;
}

//=============================================================================
//  Name         : Compare
//  Usage        : bool detectedVariations = sequence.Compare(compareSequence);
//  Description  : Compares the input sequence with the current sequence.
//  Parameters   : compareSequence - Sequence to compare current sequence with
//  Global Data  : <None>
//  Return Value : Returns true if there are variations. Otherwise, returns
//                 false.
//==============================================================================

bool Sequence::Compare(Sequence compareSequence) {
	// Track if variations are found.
	bool foundVariations = false;

	// Get the compare sequence.
	char* compareSequenceArray = new char[compareSequence.GetSize()];
	compareSequence.GetSequence(compareSequenceArray);

	// Cycle through each character in the sequences.
	for (int i = 0; i < size; i++) {
		if (sequence[i] != compareSequenceArray[i]) {
			foundVariations = true;
		}
	}

	// Return if variations are found.
	return foundVariations;
}

//=============================================================================
//  Name         : PrintVariations
//  Usage        : sequence.PrintVariations(compareSequence);
//  Description  : Prints the variations between sequence & compareSequence.
//  Parameters   : compareSequence - Sequence to compare current sequence with
//  Global Data  : <None>
//  Return Value : <None>
//==============================================================================

void Sequence::PrintVariations(Sequence compareSequence) {
	// Track when a variation is found so that brackets can be used.
	bool foundVariation = false;

	// Get the compare sequence.
	char* compareSequenceArray = new char[compareSequence.GetSize()];
	compareSequence.GetSequence(compareSequenceArray);
	
	// Cycle through each character in the sequences.
	for (int i = 0; i < size; i++) {
		// If the current character doesn't match, then check if this is part
		// of an ongoing variation.
		if (sequence[i] != compareSequenceArray[i]) {
			// If there is no ongoing variation, then indicate it and start
			// a pair of brackets.
			if (foundVariation == false) {
				foundVariation = true;
				cout << "[";
			}
		}

		// Otherwise, check if an ongoing variation is ending.
		else {
			// If an ongoing variation is ending, then indicate it and complete
			// the pair of brackets.
			if (foundVariation) {
				foundVariation = false;
				cout << "]";
			}
		}

		// Print out the current sequence character.
		cout << compareSequenceArray[i];

		// If this is the last character and there is an ongoing variation,
		// then close the brackets.
		if ((i == size - 1) && foundVariation) {
			cout << "]";
		}
	}
}