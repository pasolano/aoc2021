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

void get_digits(std::vector<std::string> &in, std::string *out) {
    std::sort(in.begin(), in.end(), compareLen);
    // identify 1
    out[1] = in[0];
    // identify 7
    out[7] = in[1];
    // identify 4
    out[4] = in[2];
    // identify 8
    out[8] = in[9];
    // collect 6 segs
    std::vector<std::string> six_segs;
    for (int i = 6; i < 9; i++) six_segs.push_back(in[i]);
    // identify 6
    for (auto &i : six_segs) {
        for (auto j : out[1]) {
            if (i.find(j) == std::string::npos) {
                out[6] = i;
                six_segs.erase(std::find(six_segs.begin(), six_segs.end(), i));
                break;
            }
        }
        if (six_segs.size() == 2) break;
    }
    // identify 0
    for (auto &i : six_segs) {
        for (auto j : out[4]) {
            if (i.find(j) == std::string::npos) {
                out[0] = i;
                six_segs.erase(std::find(six_segs.begin(), six_segs.end(), i));
                break;
            }
        }
        if (six_segs.size() == 1) break;
    }
    // identify 9
    out[9] = six_segs[0];
    // collect 5 segs
    std::vector<std::string> five_segs;
    for (int i = 3; i < 6; i++) five_segs.push_back(in[i]);
    // identify 5
    for (auto &i : five_segs) {
        int missing = 0;
        for (auto j : out[9]) {
            if (i.find(j) == std::string::npos) {
                missing++;
            }
        }
        if (missing == 1) {
            out[5] = i;
            five_segs.erase(std::find(five_segs.begin(), five_segs.end(), i));
            break;
        }
    }
    // identify 3
    for (auto &i : five_segs) {
        int shared = 0;
        for (auto j : out[1]) {
            if (i.find(j) != std::string::npos) {
                shared++;
            }
        }
        if (shared == 2) {
            out[3] = i;
            five_segs.erase(std::find(five_segs.begin(), five_segs.end(), i));
            break;
        }
    }
    // identify 2
    out[2] = five_segs[0];
}

int get_digit(std::string &val, std::string *key) {
    if (val.length() == 2) return 1;
    else if (val.length() == 3) return 7;
    else if (val.length() == 4) return 4;
    else if (val.length() == 7) return 8;
    else {
        if (val.length() == 5) {
            std::vector<std::string> five_segs;
            for (int i = 3; i < 6; i++) five_segs.push_back(key[i]);
            for (auto &i : five_segs) {
                int matches = 0;
                for (auto j : i) {
                    if (val.find(j) != std::string::npos) matches++;
                }
                if (matches == 5) {
                    return ((std::find(five_segs.begin(), five_segs.end(), i) - five_segs.begin()) + 3);
                }
            }
        }
        // if 6 segs
        else {
            std::vector<std::string> six_segs;
            for (int i = 6; i < 9; i++) six_segs.push_back(key[i]);
            for (auto &i : six_segs) {
                int matches = 0;
                for (auto j : i) {
                    if (val.find(j) != std::string::npos) matches++;
                }
                if (matches == 6) {
                    return ((std::find(six_segs.begin(), six_segs.end(), i) - six_segs.begin()) + 6);
                }
            }
        }
    }
}

int translate(std::vector<std::string> &disps, std::string *key) {
    int place = 1000;
    int total = 0;
    for (auto &i : disps) {
        total += (place * get_digit(i, key));
        place /= 10;
    }
    return total;
}

int main() {
    std::fstream f("input.txt");
    std::string line;
    std::string word;
    std::vector<std::string> signals;
    std::vector<std::string> displays;
    long total = 0;
    while (getline(f, line)) {
        signals.clear();
        std::istringstream first(line.substr(0,58));
        std::istringstream second(line.substr(61, line.length()));

        while (first >> word) signals.push_back(word);
        while (second >> word) displays.push_back(word);

        std::string digits[10];
        get_digits(signals, digits);
        total += translate(displays, digits);
    }
    
    std::cout << total << std::endl;

    return 0;
}