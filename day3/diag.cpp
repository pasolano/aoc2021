#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::ifstream f;
    std::string line;
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
    std::string gamma = "";
    std::string epsilon = "";
    for (auto &i : new_strings) {
        int zero = 0;
        int one = 0;
        for (auto &j : i) {
            if (j == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (zero > one) { // couldve done subtraction with max value but in a rush
            gamma += '0';
            epsilon += '1';
        } else {
            gamma += '1';
            epsilon += '0';
        }
    }
    int fin_g = stoi(gamma, 0, 2);
    int fin_e = stoi(epsilon, 0, 2);
    std::cout << fin_g * fin_e << std::endl;
    f.close();
    return 0;
}