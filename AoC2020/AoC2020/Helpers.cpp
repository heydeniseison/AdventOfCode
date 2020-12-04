#include<iostream>
#include<fstream>
#include<string>
#include <vector>

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