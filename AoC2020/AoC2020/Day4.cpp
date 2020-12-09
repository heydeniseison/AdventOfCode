#include "Helpers.h"

#include <vector>
#include <map>
#include <algorithm>
#include <regex>

std::vector<std::string> keys{ "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };

bool isValidPassport(std::map<std::string, std::string>& passport)
{
    bool allof = std::all_of(begin(keys), end(keys), [&passport](auto key) {
        return passport.count(key) > 0;
    });
    return allof;
}

bool isValidPassport2(std::map<std::string, std::string>& passport)
{
    bool allof = std::all_of(begin(keys), end(keys), [&passport](auto key) {
        if (passport.count(key) == 0)
        {
            return false;
        }
        auto field = passport.find(key);
        auto val = *field;
        if (val.first == "byr")
        {
            int year = stoi(val.second);
            if (year >= 1920 && year <= 2002)
            {
                return true;
            }
            return false;
        }
        if (val.first == "iyr")
        {
            int year = stoi(val.second);
            if (year >= 2010 && year <= 2020)
            {
                return true;
            }
            return false;
        }
        if (val.first == "eyr")
        {
            int year = stoi(val.second);
            if (year >= 2020 && year <= 2030)
            {
                return true;
            }
            return false;
        }
        if (val.first == "hgt")
        {
            std::string cm = "cm";
            std::string in = "in";
            std::string meas;

            std::string measurement = val.second;
            std::size_t found = measurement.find(cm);
            if (found != std::string::npos)
            {
                meas = cm;
            }
            else {
                found = measurement.find(in);
                if (found == std::string::npos)
                {
                    return false;
                }
                meas = in;
            }

            std::vector<std::string> height = Split(val.second, meas);
            int num = stoi(height[0]);
            if (meas == cm)
            {
                if (num >= 150 && num <= 193)
                {
                    return true;
                }
            }
            else
            {
                if (num >= 59 && num <= 76)
                {
                    return true;
                }
            }

            return false;
        }
        if (val.first == "hcl")
        {
            std::regex hcl("#([0-9a-f]{6})");
            bool const validHairColor = std::regex_match(val.second, hcl);
            if (validHairColor)
            {
                return true;
            }
            return false;
        }
        if (val.first == "ecl")
        {
            std::vector <std::string> eyeColor{ "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
            for (const auto color : eyeColor)
            {
                if (color == val.second)
                {
                    return true;
                }
            }
            return false;

        }
        if (val.first == "pid")
        {
            std::regex pid("\\d{9}");
            bool const validPid = std::regex_match(val.second, pid);
            if (validPid)
            {
                return true;
            }
            return false;
        }

    });
    return allof;
}

int Part1(std::vector<std::map<std::string, std::string>> passports)
{
    int validPassports = 0;

    int count = std::count_if(begin(passports), end(passports), isValidPassport);
    validPassports += count;

    return validPassports;
}

int Part2(std::vector<std::map<std::string, std::string>> passports)
{
    int validPassports = 0;

    int count = std::count_if(begin(passports), end(passports), isValidPassport2);
    validPassports += count;

    return validPassports;
}
void Day4()
{
    std::vector<std::map<std::string, std::string>> passports;

    //OpenFile("TestData/day4testdata.txt", passports);
    OpenFile("TestData/day4input.txt", passports);
    //std::cout << "Part 1: " << Part1(passports) << std::endl;
    std::cout << "Part 2: " << Part2(passports) << std::endl;
}