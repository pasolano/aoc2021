#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::ifstream f;
    std::vector<std::string> new_strings;
    bool first_run = true;
    f.open("input.txt");
    while (getline(f,line)) {
        if (first_run) {
            for (auto &i : line) {
                std::vector<int> vect;
                new_strings.push_back("");
            }
            first_run = false;
        }
        for (int i = 0; i < line.length(); i++) {
            new_strings[i] += line[i];
        }
    }
    int zero = 0;
    int one = 0;
    for (auto &i : new_strings) {
        zero = 0;
        one = 0;
        for (auto &j : i) {
            if (j == '0') {
                zero++;
            } else {
                one++;
            }
        }
        // remove position from all strings and remove all strings that have unfavorable bit
    }
    f.close();
    return 0;
}