#include "Helpers.h"

#include <vector>

int TotalTrees(std::vector<std::string>& vals, int right, int down)
{
    int totalTrees = 0;

    int height = vals.size();
    int width = vals[0].length();
    int col;
    int row = 0;
    for (int i = 0; i < height; i++)
    {
        col = (right * i) % width;
        if (vals[row][col] == '#')
        {
            totalTrees += 1;
        }
        row += down;
        if (row >= height) {
            break;
        }

    }
    return totalTrees;
}

long int Part1(std::vector<std::string> vals)
{
    return TotalTrees(vals, 3, 1);
}

long long int Part2(std::vector<std::string>& vals)
{
    std::vector<std::vector<int>> slopes = { {1,1}, {3,1}, {5,1}, {7,1}, {1,2} };
    long long int total = 1;
    for (int i = 0; i < slopes.size(); i++) {
        int right = slopes[i][0];
        int down = slopes[i][1];
        int treesFound = TotalTrees(vals, right, down);
        total *= treesFound;
    }

    return total;
}

void Day3() 
{
    std::vector<std::string> vals;
    OpenFile("TestData/day3input.txt", vals);

    std::cout << "Part 1: " << Part1(vals) << std::endl;
    std::cout << "Part 2: " << Part2(vals) << std::endl;
}