#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::fstream f("input.txt");
    std::string line;
    std::string word;
    int total = 0;
    while (getline(f, line)) {
        line = line.substr(61, line.length());
        std::istringstream ss(line);
        while (ss >> word) {
            switch (word.length()) {
                case 2:
                case 3:
                case 4:
                case 7:
                    total++;
            }
        }
    }
    std::cout << total << std::endl;
    return 0;
}