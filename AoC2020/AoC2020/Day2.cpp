#include <vector>
#include "Helpers.h"

int Part1(std::vector<std::string>& vals)
{
    int count = 0;
    for (int i = 0; i < vals.size(); i++)
    {
        std::vector<std::string> parts = Split(vals[i], " ");

        // get min and max
        std::vector<std::string> limits = Split(parts[0], "-");
        int min = std::stoi(limits[0]);
        int max = std::stoi(limits[1]);

        // get letter password needs and remove colon
        const std::string letter = parts[1].substr(0, parts[1].size() - 1);
        const char* char_arr = &letter[0];

        const std::string password = parts[2];
        // search for letter. if it doesnt meet min and max then its bad
        int n = std::count(password.begin(), password.end(), char_arr[0]);
        if (n >= min && n <= max)
        {
            count ++;
        }

        parts.clear();
        limits.clear();
    }
    return count;
}

int Part2(std::vector<std::string>& vals)
{
    int count = 0;
    for (int i = 0; i < vals.size(); i++)
    {
        std::vector<std::string> parts = Split(vals[i], " ");

        // get min and max
        std::vector<std::string> limits = Split(parts[0], "-");
        int min = std::stoi(limits[0]);
        int max = std::stoi(limits[1]);

        // get letter password needs and remove colon
        const std::string letter = parts[1].substr(0, parts[1].size() - 1);
        const char* char_arr = &letter[0];
        const std::string password = parts[2];

        const char pos1 = password.at(min - 1);
        const char pos2 = password.at(max - 1);
        if ((pos1 == char_arr[0] && pos2 != char_arr[0]) ^ (pos1 != char_arr[0] && pos2 == char_arr[0]))
        {
            count++;
        }

        parts.clear();
        limits.clear();
    }

    return count;
}

void Day2() {
    std::vector<std::string> vals;
    OpenFile("TestData/day2input.txt", vals);

    std::cout << "Part 1: " << Part1(vals) << std::endl;
    std::cout << "Part 2: " << Part2(vals) << std::endl;
}
