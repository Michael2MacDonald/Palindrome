/**
 * Michael MacDonald
 * 9/19/2022
 * 
 * Takes a string input, removes all non-alphabetic characters,
 * converts to lower case, and returns if the resulting string is a palindrome!
 * 
 * Max 80 character input!
 * 
 */


#include <iostream>
#include <cstring>

int main() {

	char* input = (char*)malloc(80);
	char* output = (char*)malloc(80);

	for (int i=0; i<80; i++) {
		input[i] = '\0';
		output[i] = '\0';
	}

	std::cout << "Type a phrase or word to check:\n";
	/* Windows uses a pair of CR and LF characters to terminate lines.
	 * UNIX (Including Linux and FreeBSD) uses an LF character only.
	 * OS X also uses a single LF character.
	 * We will use LF as the delimiting character.
	 * The CR character on windows will be removed automatically later on */
	std::cin.getline(input, 80, '\n'); // If the line is over 80 characters it will only return us with the first 80
	
	// Filter
	while (true) {
		static int i = 0;
		// Only upper, lower, and NULL
		if ( ((int)input[i] >= 1 && (int)input[i] <= 64) || ((int)input[i] >= 91 && (int)input[i] <= 96) || ((int)input[i] >= 123 && (int)input[i] <= 127) ) {
			for (int j=i; (j+1)<80; j++) { input[j] = input[j+1]; } // Shift
			input[79] = '\0'; // Ending is now NULL
			// Must not increment after shifting because the current index has a new character we still need to check
		} else {
			// Make lower
			if ( ((int)input[i] >= 65) && ((int)input[i] <= 90) ) {
				// Don't you love some good ascii math? I know I do!
				input[i] = (char)((int)input[i] + 32); // To lower
			}

		 	if (i++ >= 80) { break; } // Increment and check if we are done
		}
	}

	// Get length
	int length = 0;
	for (int i=0; input[i] != '\0' && i<80; i++) { length = i; }

	// Debugging: https://xkcd.com/1722/
	//std::cout << "length: " << length << "\n";

	// Reverse
	for (int i=0; i<=length; i++) { output[length-i] = input[i]; }

	// Check
	bool palindrome = true;
	for (int i=0; i<=length; i++) {
		if (input[i] != output[i]) { palindrome = false; break; }
	}
	
	// Return results to the user
	if (palindrome) {
		std::cout << input << " is a palindrome!\n";
	} else {
		std::cout << input << " is not a palindrome! " << input << " != " << output << "!\n";
	}

	return 0;

}




