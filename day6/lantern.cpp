#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

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
    f.open("input.txt");
    std::getline(f, line);
    f.close();
    std::map<int, long> count;
    for (int i = 0; i < 9; i++) {
        count[i] = 0;
    }

    std::vector<int> fish;
    split_to_int(line, fish);
    for (auto i : fish) count[i]++;
    for (int day = 0; day < 256; day++) {
        long zeroes = count[0];
        for (int i = 1; i < 9; i++) {
            count[i-1] = count[i];
        }
        count[6] += zeroes;
        count[8] = zeroes;
    }

    long total = count[0];
    for (int i = 1; i < 9; i++) total += count[i];
    std::cout << total << std::endl;
    return 0;
}