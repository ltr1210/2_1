#ifndef HELPER_H
#define HELPER_H

#include <unordered_map>

void wordTrim (std::string &s);
void lowercase(std::string& s);
std::map<std::string, int> wordMap(std::vector<std::string> words);
std::map<int, std::vector<std::string>> flipMap(const std::map<std::string , int>& orig);
bool valid_word (std::string word);

#endif //HELPER_H