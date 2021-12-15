#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

bool compareLen(const std::string& a, const std::string& b) {
    return (a.length() < b.length()); 
}

void get_digits(std::vector<std::string> &in, std::vector<int> &out) {
    std::sort(in.begin(), in.end(), compareLen);
    for (auto &i : in) {
        switch
    }
}

int main() {
    std::fstream f("input.txt");
    std::string line;
    std::string word;
    std::vector<std::string> signals;
    std::vector<int> segs;
    while (getline(f, line)) {
        signals.clear();
        segs.clear();
        std::istringstream first(line.substr(0,58));
        std::istringstream second(line.substr(61, line.length()));

        while (first >> word) signals.push_back(word);

        get_digits(signals, digits);

    }
    // std::string word;
    // int total = 0;
    // while (getline(f, line)) {
    //     line = line.substr(61, line.length());
    //     std::istringstream ss(line);
    //     while (ss >> word) {
    //         switch (word.length()) {
    //             case 2:
    //             case 3:
    //             case 4:
    //             case 7:
    //                 total++;
    //         }
    //     }
    // }
    // std::cout << total << std::endl;
    return 0;
}