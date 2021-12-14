#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

int main() {
    std::ifstream f("test.txt");
    std::string num;
    std::vector<int> nums;
    int total = 0;
    while (getline(f, num, ',')) {
        int n = stoi(num);
        nums.push_back(n);
        total += n;
    }
    
    int avg = std::lround((float) total/nums.size());
    int gas = 0;
    for (auto i : nums) {
        int val = abs(avg-i);
        while (val > 0) {
            gas += val;
            val--;
        }
    }
    std::cout << gas << std::endl;
    return 0;
}