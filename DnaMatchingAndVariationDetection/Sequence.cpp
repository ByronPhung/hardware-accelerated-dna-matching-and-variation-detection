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

unsigned int Sequence::GetSize() {
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

unsigned int Sequence::Search(char key[], int keySize) {
	// Track the number of keys found in this search.
	int numKeysFound = 0;

	// Search in increments of the key size.
	for (unsigned int i = 0; i <= size - keySize; i++) {
		// Declare j outside of the next for loop to determine if there was a
		// key match.
		unsigned int j = 0;

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