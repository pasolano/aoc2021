#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream f;
    std::string line;
    int last_val = 1000000;
    int total = 0;
    int curr;
    
    int frame_1;
    int frame_2;
    std::vector<int> frame;
    f.open("input.txt");
    while (getline(f,line)) {
        curr = std::stoi(line);
        frame.insert(frame.begin(), curr); // add to front of vector
        if (frame.size() > 3) {
            // if frame greater than last, total++
            frame_2 = frame[0] + frame[1] + frame[2];
            frame_1 = frame[1] + frame[2] + frame[3];
            if (frame_2 > frame_1) {
                total++;
            }
            frame.pop_back();
        }
    }
    std::cout << total << std::endl;
    f.close();
    return 0;
}