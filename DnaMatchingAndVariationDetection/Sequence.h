class Sequence {
	private:
		unsigned char sequence[1024];
		int size;
		void StoreSequence(char inputSequence[]);

	public:
		Sequence();											  // Default Constructor
		void Initialize(char inputSequence[]);				  // Default Initializer: Takes 1 char array of DNA sequence.
		void Initialize(char inputSequence[], int inputSize); // Overloaded Initializer: Takes 1 char array of DNA sequence AND defined sequence size.
		void PrintSequence();								  // Prints the stored sequence.
		unsigned int GetSize();								  // Determines the size of the current sequence.
		unsigned int Search(char key[], int keySize);		  // Searches the current sequence for the desired key
		bool Compare(Sequence sequence2);					  // Compares current sequence with sequence2 to determine variations.
															  // This is intended for 2 sequences that are "supposed" to be the same or similar.
};