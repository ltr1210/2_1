#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "helper.h"

int main(int argc, char** argv) {
    std::string file_name;
    int num;
    std::vector<std::string> words;
    std::string word;

    std::map<std::string, int> all_word;
    std::map<int, std::string> output;

    if (argc == 3) {
        file_name = argv[1];
        num = strtol(argv[2],&argv[2],10);
    } else if (argc == 2) {
        file_name = argv[1];
        num = 10;
    } else {
        std::cout << "Invalid arguments" << std::endl;
        return 1;
    }
    //std::cout << file_name << std::endl;
    std::ifstream input(file_name);

    if (!input) {
        std::cout << "Invalid reading from the file" << std::endl;
        return 1;
    }

    while (input >> word) {
        //std::cout << word << std::endl;
        wordTrim(word);
        lowercase(word);

        words.push_back(word);
       // std::cout << word << std::endl;
    }
    all_word = wordMap(words);
    std::map<int, std::vector<std::string>> flipped(flipMap(all_word));

    //1.) These words appeared 78 times: {shake}


    int line = 1;
    for (auto keyValue = flipped.rbegin(); keyValue != flipped.rend(); keyValue++) {
        std::cout << line << ".) These words appeared " << keyValue->first << " times: {";

        std::string delimiter = "";
        for (const auto& dupKey : keyValue->second) {
            std::cout << delimiter << dupKey;
            delimiter = ", ";
        }
        std::cout << "}" << std::endl;
        if (line == num) {
            break;
        }
        line++;
    }



    return 0;
}
