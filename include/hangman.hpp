#include <string>
#include <fstream>

int count_words(std::ifstream &ifs);
int random_int(int ub);
std::string get_random_word(int word_index, std::ifstream &ifs);
void log_chars(bool *chars, std::string guess_word);
bool is_char_in_guess(bool *chars, bool *guessed_chars, char curr_guess);
std::string get_blanked_guess(std::string guess_word, bool *guessed_chars);
