#include "Helpers.h"
#include "Day5.h"
#include <vector>
#include <map>
#include <algorithm>


void Part1()
{
    int ip = 1;
    int acc = 0;
    std::vector<std::string> data;
    std::vector<bool> hasBeenVisited(622);

    //OpenFile("TestData/day8testdata.txt", data);
    OpenFile("TestData/day8input.txt", data);

    std::pair<std::string, std::string> hack;
    std::vector<std::pair<std::string, std::string>> instructions;
    instructions.push_back(hack);
    for (auto const line : data)
    {
        std::pair<std::string, std::string> instruction = CreatePairs(line, " ");
        instructions.push_back(instruction);
    }

    for (int i = 1; i < instructions.size(); i++)
    {
        if (hasBeenVisited[ip])
        {
            break;
        }
        else {
            hasBeenVisited[ip] = true;
        }
        int num = stoi(instructions[ip].second);
        if (instructions[ip].first == "acc")
        {
            acc += num;
            ip += 1;
        }
        else if (instructions[ip].first == "jmp")
        {
            ip += num;
        }
        else
        {
            ip += 1;
        }
    }
}
void Day8()
{
    std::vector<std::string> data;
    bool hasTerminatedCorrectly{ false };

    OpenFile("TestData/day8testdata.txt", data);
    //OpenFile("TestData/day8input.txt", data);

    std::pair<std::string, std::string> hack;
    std::vector<std::pair<std::string, std::string>> instructions;
    instructions.push_back(hack);
    for (auto const line : data)
    {
        std::pair<std::string, std::string> instruction = CreatePairs(line, " ");
        instructions.push_back(instruction);
    }

    std::vector<bool> hasBeenSwitched(10);

    int ip = 1;
    int acc = 0;
    while (hasTerminatedCorrectly == false)
    {
        ip = 1;
        acc = 0;
        bool tryingOneOut{ false };
        //std::vector<bool> hasBeenVisited(622);
        std::vector<bool> hasBeenVisited(10);

        std::string prevString;
        int index = 0;
        for (int i = 1; i < instructions.size(); i++)
        {
            if (hasBeenVisited[ip])
            {
                hasBeenSwitched[ip] = true;
                instructions[index].first = prevString;
                tryingOneOut = false;
                break;
            }
            else {
                hasBeenVisited[ip] = true;
            }
            int num = stoi(instructions[ip].second);
            if (instructions[ip].first == "acc")
            {
                acc += num;
                ip += 1;
            }
            else if (instructions[ip].first == "jmp")
            {
                if (tryingOneOut == false && hasBeenSwitched[ip] == false)
                {
                    prevString = instructions[ip].first;
                    instructions[ip].first = "nop";
                    index = ip;
                    ip += 1;
                    tryingOneOut = true;
                }
                else {
                    ip += num;
                }
               
            }
            else if (instructions[ip].first == "nop" && tryingOneOut == false && hasBeenSwitched[ip] == false)
            {
                prevString = instructions[ip].first;
                instructions[ip].first = "jmp";
                index = ip;
                ip += num;
                tryingOneOut = true;
            }
            else {
                ip += 1;
            }

            if (i <= instructions.size() - 1)
            {
                hasTerminatedCorrectly = true;
            }
        }

    }
    

    std::cout << acc << std::endl;

}