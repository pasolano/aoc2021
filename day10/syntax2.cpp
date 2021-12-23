#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

// lazy code not based on indices to reuse code
int score(char &c) {
    switch (c) {
        case ')':
            return 1;
        case ']':
            return 2;
        case '}':
            return 3;
        case '>':
            return 4;
        default:
            return 0;
    }
}

int main() {
    std::ifstream f;
    std::string line;
    std::stack<char> s;
    char pairs[4][2] {{'(',')'},{'[',']'},{'<','>'},{'{','}'}};
    bool skip = false;
    std::vector<long> scores;
    f.open("input.txt");
    while (getline(f, line)) {
        s = std::stack<char>();
        for (auto &i : line) {
            if (skip) break;
            skip = false;
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
                        skip = true;
                    }
                    break;
                }
            }
        }
        long sum = 0;
        if (!skip) {
            while (!s.empty()) {
                for (auto &pair : pairs) {
                    if (s.top() == pair[0]) {
                        sum *= 5;
                        sum += score(pair[1]);
                        s.pop();
                        break;
                    }
                }
            }
        }
        if (sum > 0) scores.push_back(sum);
        skip = false;
    }
    std::sort(scores.begin(), scores.end());

    std::cout << scores[std::ceil(scores.size()/2)] << std::endl;
    return 0;
}