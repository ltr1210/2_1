//
// Created by 刘天睿 on 2022/4/24.
//

#include <string>
#include <map>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include "helper.h"

void wordTrim (std::string &s) {
    for (int i = 0, len = s.size(); i < len; i++)
    {
        if (ispunct(s[i])) {
            s.erase(i--, 1);
            len = s.size();
        } else {
            break;
        }
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (ispunct(s[i])) {
            s.erase(i, 1);
        } else {
            break;
        }
    }
}

void lowercase(std::string& s)
{
    for (auto& ch: s) ch = tolower(ch);
}

std::map<std::string, int> wordMap(std::vector<std::string> words) {
    std::map<std::string, int> all_word;


    for (unsigned int i = 0; i < words.size(); i++) {
        if (valid_word(words.at(i))) {
            if (all_word.find(words.at(i)) == all_word.end()) {
                all_word.insert(std::pair<std::string, int>(words.at(i), 1));
            } else {
                all_word[words.at(i)]++;
            }
        }
    }

    return all_word;
}

std::map<int, std::vector<std::string>> flipMap(const std::map<std::string , int>& orig) {
    std::map<int, std::vector<std::string>> flipped;
    for (const auto& keyValue : orig) {
        const int& flippedKey = keyValue.second;
        const std::string& flippedValue = keyValue.first;
        auto itr = flipped.find(flippedKey);
        //if(flipped.count(flippedKey) > 0)
        if (itr != flipped.end()){ //the key is already there
            //add to the end of the vector that is already there
            itr->second.push_back(flippedValue);
            //flipped.at(flippedKey).push_back(flippedValue);
        }else{
            //create a new key value pair in flipped where the vector contains the right value
            flipped.insert({flippedKey, {flippedValue}});
            //flipped.insert(std::make_pair(flippedKey, std::vector<char>{flippedValue}));
        }
    }
    return flipped;
}

//a, an, and, in, is, it the
bool valid_word (std::string word) {
    std::array<std::string, 7> invalid_word {"a", "an", "and", "in", "is", "it", "the"};
    return find(begin(invalid_word), end(invalid_word), word) == end(invalid_word);
}