#include "Helpers.h"
#include "Day5.h"
#include <vector>
#include <map>
#include <algorithm>


void GetSeat(std::string pass, std::vector<int>& seatIds)
{
    int row = 0;
    int col = 0;
    int id = 0;

    double rowLowerBound = 0;
    double rowUpperBound = 127;

    double colLowerBound = 0;
    double colUpperBound = 7;

    std::for_each(begin(pass), end(pass), [&seatIds, &rowUpperBound, &rowLowerBound, &colLowerBound, &colUpperBound](auto letter) {
        if (letter == 'F')
        {
            double newUpperBound = (rowUpperBound - rowLowerBound) / 2;
            rowUpperBound -= newUpperBound;
        }
        else if (letter == 'B')
        {
            double newLowerBound = (rowUpperBound - rowLowerBound) / 2;
            rowLowerBound += newLowerBound;
        }
        else if (letter == 'L')
        {
            double newUpperBound = (colUpperBound - colLowerBound) / 2;
            colUpperBound -= newUpperBound;
        }
        else if (letter == 'R')
        {
            double newLowerBound = (colUpperBound - colLowerBound) / 2;
            colLowerBound += newLowerBound;
        }
        });

    row = std::min(std::ceil(rowLowerBound), std::ceil(rowUpperBound));
    col = std::min(std::ceil(colLowerBound), std::ceil(colUpperBound));
    id = 8 * row + col;
    seatIds.push_back(id);
}

void Day5()
{
    std::vector<std::string> passes;

    OpenFile("TestData/day5input.txt", passes);
    std::vector<int> seatIds;

    for (const auto pass : passes)
    {
        GetSeat(pass, seatIds);
    }

    sort(begin(seatIds), end(seatIds), [](int elem1, int elem2) {return elem1 > elem2; });

    std::cout << "Part 1: " << seatIds[0]<< std::endl;

    auto result = std::adjacent_find(begin(seatIds), end(seatIds), [](const auto& first, const auto& second)
        {
            return abs(first - second) == 2;
        });
    std::cout << "Part 2: " << std::min(*result, *std::next(result)) + 1 << std::endl;
}