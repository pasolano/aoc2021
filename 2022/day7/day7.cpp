#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

class Directory
{
    public:
        Directory* parent;
        unordered_map<string, Directory> contents;
        bool dir;
        unsigned int file_size; 

        Directory(bool is_dir = true)
        {
            dir = is_dir;
        }
};

class Filesystem
{
    public:
        Directory* root_dir;
        Directory* curr_dir;
};

void exec_cmd(Filesystem& fs, string second_token, istringstream& iss)
{
    if (second_token == "cd")
    {
        string third_token;
        iss >> third_token;
        if (third_token == "..")
        {
            fs.curr_dir = fs.curr_dir->parent;
        }
        else if (third_token == "/")
        {
            while (fs.curr_dir->parent)
                {
                    fs.curr_dir = fs.curr_dir->parent;
                }
        }
        else
        {
            fs.curr_dir = &(fs.curr_dir->contents[third_token]);
        }
    }
}

unsigned long long dir_score(Directory const& d)
{
    if (d.dir)
    {
        unsigned long long total = 0;
        for (auto const& [key, val] : d.contents)
        {
            total += dir_score(val);
        }
        return total;
    }
    else
    {
        return d.file_size;
    }
    
    return 0;
}

int main()
{
    std::cout << "hello world" << std::endl;

    Filesystem fs = Filesystem();
    fs.curr_dir = new Directory(true);
    fs.root_dir = fs.curr_dir;

    string line;
    while(getline(cin, line))
    {
        if (line[line.length() - 1] == '\n') {
            line.erase(line.length() - 1);
        }
        istringstream iss(line);
        string first_token;
        string second_token;
        iss >> first_token >> second_token;

        // string is command
        if (first_token == "$")
        {
            exec_cmd(fs, second_token, iss);
        }
        
        // string is directory
        else if (first_token == "dir")
        {
            // create dir if not made
            if (fs.curr_dir->contents.find(second_token) == fs.curr_dir->contents.end())
            {
                fs.curr_dir->contents[second_token] = Directory(true);
            }
        }

        // string is file
        else
        {
            string third_token;
            iss >> third_token;
            if (fs.curr_dir->contents.find(third_token) == fs.curr_dir->contents.end())
            {
                Directory f = Directory(false);
                f.file_size = stoi(second_token);
                fs.curr_dir->contents[third_token] = f;
            }
        }
    }

    cout << "hello" << endl;
    cout <<  dir_score(*(fs.root_dir)) << endl;

    return 0;
}
