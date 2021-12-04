#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int oxygen(std::vector<std::string> values) {
    for (int i = 0; i < 12; i++) {
        int zero = 0;
        int one = 0;
        for (auto j : values) {
            if (j[i] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        char dom;
        if (zero > one) {
            dom = '0';
        } else {
            dom = '1';
        }
        for (auto j = values.begin(); j != values.end(); j++) {
            if ((*j)[i] != dom) {
                values.erase(j);
                j--;
            }
        }
    }
    return std::stoi(values[0], nullptr, 2);
}

int co2(std::vector<std::string> values) {
    for (int i = 0; i < 12; i++) {
        int zero = 0;
        int one = 0;
        for (auto j : values) {
            if (j[i] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        char dom;
        if (zero > one) { // this is the only different part
            dom = '1';
        } else {
            dom = '0';
        }
        for (auto j = values.begin(); j != values.end(); j++) {
            if ((*j)[i] != dom) {
                values.erase(j);
                j--;
            }
        }
    }
    return std::stoi(values[0], nullptr, 2);
}

int main() {
    std::ifstream f;
    std::string line;
    std::vector<std::string> values;
    f.open("input.txt");
    while (getline(f, line)) {
        values.push_back(line);
    }    
    f.close();
    int oxy = oxygen(values);
    int co = co2(values);
    std::cout << oxy * co << std::endl;
    return 0;
}