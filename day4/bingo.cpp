#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

bool process_board(std::vector<std::vector<int>>* board, int num) {
    return false;
}

int main() {
    std::vector<int> nums;
    std::ifstream f;
    std::string line;
    bool first_run = true;
    f.open("input.txt");
    while (getline(f, line)) {
        if (first_run) { // split on ","
            while (std::find(line.begin(), line.end(), ',') != line.end()) {
                std::cout << line.find(',') << std::endl;
                std::string token = line.substr(0, line.find(','));
                line.erase(0, line.find(',') + 1);
                nums.push_back(stoi(token));
            }
            first_run = false;
        } else {
            // make sure modifying string above didnt cause issues with getline
            if (line != "") { // check that blank lines don't have any sneaky characters
                ; // pack grids here
            }
        }
    }
    f.close();
    return 0;
}