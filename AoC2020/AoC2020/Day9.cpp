#include "Helpers.h"
#include "Day5.h"
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <cmath> 

void uno()
{
    int preambleSize = 25;
    std::vector<int> data;

    //OpenFile("TestData/day9testdata.txt", data);
    OpenFile("TestData/day9input.txt", data);

    int value = 0;
    bool found = false;
    std::set<std::pair<int, int>> prev;

    for (int i = preambleSize; i < data.size(); i++)
    {
        value = data[i];
        int start = i - 1;
        int stop = preambleSize - start;
        for (int j = start; j > std::abs(stop); j--)
        {
            for (int k = j - 1; k >std::abs(stop); k--)
            {
                std::pair<int, int> combo = std::make_pair(
                    data[j],
                    data[k]
                );
                prev.insert(combo);
            }
        }

        for (auto const& p : prev) {
            int sum = p.first + p.second;
            if (data[i] == sum)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            prev.clear();
            found = false;
        }
        else {
            break;
        }

    }

    std::cout << value << std::endl;
}

void Day9()
{
    int num = 507622668;
    //int num = 127;
    int weakness = 0;
    int preambleSize = 5;
    std::vector<int> data;

    //OpenFile("TestData/day9testdata.txt", data);
    OpenFile("TestData/day9input.txt", data);

    // get rid of all the numbers after target
    auto position = std::find(begin(data), end(data), num);
    
    std::vector<int> values(data.size());
    std::copy(begin(data), position, begin(values));
    auto newend = std::remove(begin(values), end(values), 0);
    int logicalSize = newend - begin(values);
    values.erase(newend, end(values));

    bool foundCont = false;
    int start = 0;
    int stop = 0;
    for (int i = 0; i < values.size(); i++)
    {
        int total = 0;
        total += values[i];
        for (int j = i + 1; j < values.size(); j++)
        {
            if (total > num)
            {
                break;
                    
            }
            else if (total == num)
            {
                start = i;
                stop = j-1;
                foundCont = true;
                break;
            }
            total += values[j];

        }

        if (foundCont)
        {
            break;
        }
    }

    std::vector<int> contin;
    for (int i = start; i <= stop; i++)
    {
        contin.push_back(values[i]);
    }

    auto max = std::max_element(begin(contin), end(contin));
    auto min = std::min_element(begin(contin), end(contin));

    int result = *max + *min;
    bool found = false;

    std::cout << result << std::endl;
}