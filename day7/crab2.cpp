#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

int tri_num(int num, std::vector<int> &nums) {
    long gas = 0;
    for (auto i : nums) {
            int val = abs(num-i);
            while (val > 0) {
                gas += val;
                val--;
            }
        }
    return gas;
}

int main() {
    std::ifstream f("input.txt");
    std::string num;
    std::vector<int> nums;
    int total = 0;
    while (getline(f, num, ',')) {
        int n = stoi(num);
        nums.push_back(n);
        total += n;
    }
    
    int avg = std::lround((float) total/nums.size());
    long gas = tri_num(avg, nums);
    int curr = avg + 1;
    while (gas > tri_num(curr, nums)) {
        gas = tri_num(curr, nums);
        curr++;
    }
    curr = avg - 1;
    while (gas > tri_num(curr, nums)) {
        gas = tri_num(curr, nums);
        curr--;
    }
    std::cout << gas << std::endl;
    return 0;
}