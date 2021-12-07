#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

bool in_range(int num, std::vector<int> &range) {
    if (range[0] > range[1])
        std::swap(range[0], range[1]);
    return range[0] <= num && range[1] >= num;
}

// return where two lines intersect
// return {-1} if they don't as null value
// note: lines have to be parallel to the x or y-axis
std::vector<int> find_intersection(std::vector<std::vector<int>> &line1, std::vector<std::vector<int>> &line2) { // TODO doesn't allow parallel lines that collide (lines that are parallel but on the same line) and only allows one point of collision (lines on same line have multiple points)
    std::vector<int> range1;
    std::vector<int> range2;
    // make sure lines aren't parallel
    if (line1[0][0] != line1[1][0] && line2[0][1] != line2[1][1]) { // |-
        // check if segments share a range
        range1 = {line2[0][0], line2[1][0]};
        range2 = {line1[0][1], line1[1][1]};
        if (in_range(line1[0][0], range1) && in_range(line2[0][1], range2))
            return {line1[0][0], line2[0][1]};
    }
    if (line1[0][1] != line1[1][1] && line2[0][0] != line2[1][0]) { // -|
        // check if segments share a range
        range1 = {line2[0][1], line2[1][1]};
        range2 = {line1[0][0], line1[0][1]};
        if (in_range(line1[0][1], range1) && in_range(line2[0][0], range2))
            return {line2[0][0], line1[0][1]};
    }
    return {-1};
}

template <typename T>
void split_to_two(std::vector<std::vector<std::string>> &target, std::string &to_split, std::string &delim) {
    size_t pos = to_split.find(delim);
    std::string token;
    std::vector<std::string> two;
    token = to_split.substr(0, pos);
    two.push_back(token);
    to_split.erase(0, pos + delim.length());
    two.push_back(to_split);
    target.push_back(two);
}
void split_to_two(std::vector<std::vector<int>> &target, std::string &to_split, std::string &delim) {
    size_t pos = to_split.find(delim);
    std::string token;
    std::vector<int> two;
    token = to_split.substr(0, pos);
    two.push_back(std::stoi(token));
    to_split.erase(0, pos + delim.length());
    two.push_back(std::stoi(to_split));
    target.push_back(two);
}

int main() {
    // pack input
    std::vector<std::vector<std::vector<int>>> segs; 
    std::string line;
    std::ifstream f;
    std::vector<std::vector<int>> seg;
    f.open("test.txt");
    while (getline(f, line)) {
        if (line.length() == 0) continue;
        std::vector<std::vector<std::string>> temp;
        std::string delim = " -> ";
        split_to_two<std::string>(temp, line, delim); // get start and end of segment
        delim = ",";
        for (auto i : temp) {
            seg.clear();
            for (auto j : i) {
                split_to_two(seg, j, delim);
            }
            segs.push_back(seg);
        }
    }
    f.close();

    // calculate intersections
    std::map<std::string, int> collisions;
    std::vector<int> point;
    std::string coll_str;
    int total_colls = 0;
    for (auto seg = segs.begin(); seg != segs.end(); seg++) {
        // compare to all later segments
        std::vector<std::vector<std::vector<int>>>::iterator iter = seg;
        iter++;
        for (; iter != segs.end(); iter++) {
            point = find_intersection(*seg, *iter);
            if (point[0] != -1) {
                // add to map with count of collisions
                coll_str = std::to_string(point[0]) + "," + std::to_string(point[1]);
                // check if key exists
                if (collisions.find(coll_str) == collisions.end()) { // not found
                    collisions[coll_str] = 1;
                }
                else { // found
                    if (collisions[coll_str] >= 2)
                        total_colls++;
                    else
                        collisions[coll_str]++;
                }
            }
        }
    }
    // std::cout << total_colls << std::endl;
    std::vector<std::vector<int>> new_line = {{0,1},{0,1}};
    auto p = find_intersection(new_line, new_line);
    std::cout << point[0] << ", " << point[1] << std::endl;
    return 0;
}