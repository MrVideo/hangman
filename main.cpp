#include <fstream>
#include <iostream>

#include "include/hangman.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage:\n\t hangman inputfile.txt" << std::endl;
		return 1;
	}

	srand(time(NULL));

    std::ifstream ifs{argv[1]};

    if (!ifs) {
        std::cerr << "Something went wrong while reading from file\n";
        return 1;
    }

	int guess_index = random_int(count_words(ifs));
	std::string guess_word = get_random_word(guess_index, ifs);

	bool chars[26] = {};
	bool guessed_chars[26] = {};

	log_chars(chars, guess_word);

	int tries = 6;

	std::cout << "Word length: " << guess_word.length() << "\n";

	bool exited = 0;

	while (tries > 0) {
		std::string curr_guess;

		std::cout << "Enter your guess: ";	
		if (!(std::cin >> curr_guess)) {
			exited = 1;
			break;
		}
		
		if (is_char_in_guess(chars, guessed_chars, curr_guess[0])) {
			std::cout << "Correct guess!\n";
		} else {
			std::cout << "That character is not in the word...\n";
			tries--;
		}

		std::string blanked_guess = get_blanked_guess(guess_word, guessed_chars);

		if (blanked_guess != guess_word && tries > 0) {
			std::cout << "Current guess: " << blanked_guess << "\n";
			std::cout << "Remaining tries: " << tries << "\n";
		} else {
			break;
		}
	}


	if (!exited) {
		std::cout << "The word was: " << guess_word << "\n";

		if (tries > 0) {
			std::cout << "Congrats!" << std::endl;
		} else {
			std::cout << "F." << std::endl;
		}
	} else {
		std::cout << "\nExited. See you next time!" << std::endl;
	}

    return 0;
}
