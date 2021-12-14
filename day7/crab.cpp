#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream f("input.txt");
    std::string num;
    std::vector<int> nums;
    while (getline(f, num, ',')) {
        int n = stoi(num);
        nums.push_back(n);
    }
    std::sort(nums.begin(), nums.end());
    int med = nums[nums.size()/2];
    int gas = 0;
    for (auto i : nums) gas += abs(med-i);
    std::cout << gas << std::endl;
    return 0;
}