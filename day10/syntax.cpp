#include <stack>
#include <iostream>
#include <fstream>
#include <string>

int score(char &c) {
    switch (c) {
        case ')':
            return 3;
        case ']':
            return 57;
        case '}':
            return 1197;
        case '>':
            return 25137;
        default:
            return 0;
    }
}

int main() {
    std::ifstream f;
    std::string line;
    std::stack<char> s;
    char pairs[4][2] {{'(',')'},{'[',']'},{'<','>'},{'{','}'}};
    int total = 0;
    bool found = false;
    f.open("input.txt");
    while (getline(f, line)) {
        for (auto &i : line) {
            if (found) break;
            found = false;
            // if s.top() is pair of i, pop
            for (auto &j : pairs) {
                // if char is any first in pair
                if (j[0] == i) {
                    s.push(i);
                    break;
                }
                // if char is pair of stack top
                else if (j[1] == i) {
                    if (j[0] == s.top()) {
                        s.pop();
                    }
                    else {
                        total += score(i);
                        found = true;
                    }
                    break;
                }
            }
        }
        found = false;
    }
    std::cout << total << std::endl;
    return 0;
}