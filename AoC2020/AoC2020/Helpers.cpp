#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::string> Split(const std::string& source, const std::string& delim)
{
    std::vector<std::string> parts;
    size_t prev = 0;
    for (size_t next = source.find(delim); next != std::string::npos; next = source.find(delim, prev))
    {
        parts.push_back(source.substr(prev, next - prev));
        prev = next + delim.size();
    }
    parts.push_back(source.substr(prev));
    return parts;
}

std::pair<std::string, std::string> CreatePairs(const std::string& source, const std::string& delim)
{
    auto index = source.find(delim);
    std::pair<std::string, std::string> kv;
    if (index != std::string::npos)
    {
        kv = std::make_pair(
            source.substr(0, index),
            source.substr(index + 1)
        );
    }
    return kv;
}

void CreateMap(std::map<std::string, std::string>& kv, const std::string& source, const std::string& delim)
{
    size_t prev = 0;
    for (size_t nextDelim1 = source.find(delim); nextDelim1 != std::string::npos; nextDelim1 = source.find(delim, prev))
    {
        std::string key = (source.substr(prev, nextDelim1 - prev));
        size_t nextDelim2 = source.find(' ', nextDelim1 + 1);
        std::string value;
        if (nextDelim2 != std::string::npos)
        {
            value = source.substr(nextDelim1 + 1, nextDelim2 - (nextDelim1 + 1));
            prev = nextDelim2 + delim.size();
            kv.emplace(key, value);
        }
        else {
            value = source.substr(nextDelim1 + 1);
            kv.emplace(key, value);

            break;
        }
    }
}

void OpenFile(const std::string& filename, std::vector<std::string>& vals)
{
    std::ifstream File;
    File.open(filename);

    std::string line;
    while (std::getline(File, line))
    {
        vals.push_back(line);
    }
    File.close();
}

void OpenFile(const std::string& filename, std::vector<int>& vals)
{
    std::ifstream File;
    File.open(filename);

    int num;
    while (File >> num)
    {
        vals.push_back(num);
    }
    File.close();
}

void OpenFile(const std::string& filename, std::vector<std::map<std::string, std::string>>& passports)
{
    std::ifstream File;
    File.open(filename);

    std::string line;
    bool isNewPassport = false;
    std::map<std::string, std::string> passport;
    while (std::getline(File, line))
    {
        if (line.empty()) {
            isNewPassport = true;
            passports.push_back(passport);
        }

        if (isNewPassport)
        {
            passport.clear();
            isNewPassport = false;
        }

        CreateMap(passport, line, ":");

    }
    File.close();
}