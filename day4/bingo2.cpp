#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

// marks board with "-1" where "num" appears
// if row of "-1" found, return true as this board won
// else, return false
bool process_board(std::vector<std::vector<int>> &board, int num) {
    // check rows
    for (auto row = board.begin(); row != board.end(); row++) {
        int matches = 0;
        for (int i = 0; i < (*row).size(); i++) {
            if ((*row)[i] == num)
                (*row)[i] = -1;
            if ((*row)[i] == -1)
                matches++;
        }
        if (matches == board[0].size()) {
            return true;
        }
    }
    // check columns
    for (int i = 0; i < board[0].size(); i++) {
        int matches = 0;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][i] == -1)
                matches++;
        }
        if (matches == board[0].size())
            return true;
    }
    return false;
}

// split string "line" using "delim"
// push split string into vector "target"
// note: string must contain numbers and delims only
template<typename T>
void split_into(std::vector<T> &target, std::string line, std::string delim) {
    int start = 0;
    int end = line.find(delim);
    while (end != -1) {
        target.push_back(std::stoi(line.substr(start, end - start)));
        start = end + delim.size();
        end = line.find(delim, start);
    }
    target.push_back(std::stoi(line.substr(start, end - start)));
}

template<typename T>
void split_whitespace(std::vector<T> &target, std::string line) {
    std::istringstream iss(line); 
    for(std::string s; iss >> s; ) 
        target.push_back(std::stoi(s));
}

int sum_unmarked(std::vector<std::vector<int>> &board) {
    int sum = 0;
    for (auto row = board.begin(); row != board.end(); row++) {
        for (auto num : *row) {
            if (num != -1)
                sum += num;
        }
    }
    return sum;
}

int main() {
    // pack called bingo numbers into vector "nums"
    // pack bingo boards into vector "boards"
    std::vector<int> nums;
    std::ifstream f;
    std::string line;
    bool first_run = true;
    int line_counter = 0;
    std::vector<std::vector<std::vector<int>>> boards;
    std::vector<std::vector<int>> board;
    f.open("input.txt");
    while (getline(f, line)) {
        if (line.size() <= 1 )
            continue;
        if (first_run) {
            split_into(nums, line, ",");
            first_run = false;
        } else {            
            std::vector<int> row;
            split_whitespace(row, line);
            board.push_back(row);
            line_counter++;
            if (line_counter == 5) {
                boards.push_back(board);
                line_counter = 0;
                board.clear();
            }
        }
    }
    f.close();

    // call each number until board wins
    int sum = 0;
    bool done = false;
    for (auto num : nums) {
        for (auto b = boards.begin(); b != boards.end();) {
            if (process_board(*b, num)) {
                if (boards.size() == 1) {
                    sum = sum_unmarked(*b);
                    std::cout << sum * num << std::endl;
                    done = true;
                    break;
                }
                b = boards.erase(b);
            }
            else {
                b++;
            }
        }
        if (done)
            break;
    }
    return 0;
}