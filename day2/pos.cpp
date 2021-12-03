#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream f;
    std::string line;
    f.open("input.txt");
    std::string dir;
    int mag;
    int idx;
    int aim = 0;
    int depth = 0;
    int pos = 0;
    while (getline(f,line)) {
        idx = line.find(" ");
        dir = line.substr(0, idx);
        mag = std::stoi(line.substr(idx, line.length()));
        if (dir == "forward") {
            pos += mag;
            depth += (aim * mag);
        }
        else {
            if (dir == "up") {
                mag *= -1;
            }
            aim += mag;
        }
    }
    std::cout << pos * depth << std::endl;
    f.close();
    return 0;
}