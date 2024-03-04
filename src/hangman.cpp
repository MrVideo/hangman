#include "../include/hangman.hpp"
#include <sstream>

int count_words(std::ifstream &ifs) {
    ifs.clear();
    ifs.seekg(0);

    return std::count(std::istreambuf_iterator<char>(ifs),
                      std::istreambuf_iterator<char>(), '\n');
}

int random_int(int ub) {
	return std::rand() % ub;
}

std::string get_random_word(int word_index, std::ifstream &ifs) {
	ifs.clear();
	ifs.seekg(0);

	for (int i = 0; i < word_index; i++) {
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::string guess_word;
	std::getline(ifs, guess_word);

	return guess_word;
}

void log_chars(bool *chars, std::string guess_word) {
	for (char c : guess_word) {
		chars[c - 'a'] = true;
	}
}

bool is_char_in_guess(bool *chars, bool *guessed_chars, char curr_guess) {
	if (chars[curr_guess - 'a']) {
		guessed_chars[curr_guess - 'a'] = true;
		return true;
	}

	return false;
}

std::string get_blanked_guess(std::string guess_word, bool *guessed_chars) {
	std::stringstream ss;

	for (char c : guess_word) {
		if (guessed_chars[c - 'a']) {
			ss << c;
		} else {
			ss << '_';
		}
	}
	
	return ss.str();
}
