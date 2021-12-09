#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>

void split_to_int(std::string &input, std::vector<int> &target) {
    std::string::size_type found = 0;
    while (found != std::string::npos) {
        found = input.find(',');
        std::string res = input.substr(0,found);
        target.push_back(std::stoi(res));
        input.erase(0, found + 1);
    }
}

int main() {
    std::ifstream f;
    std::string line;
    f.open("test.txt");
    std::getline(f, line);
    f.close();
    std::vector<int> fish;
    split_to_int(line, fish);
    for (int day = 0; day < 256; day++) {
        int len = fish.size(); // get length before adding baby fish
        for (int i = 0; i < len; i++) {
            if (fish[i] == 0) {
                fish[i] = 6;
                fish.push_back(8);
            }
            else
                fish[i]--;
        }
    }
    std::cout << fish.size() << std::endl;
    return 0;
}