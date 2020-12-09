#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <map>

std::vector<std::string> Split(const std::string& source, const std::string& delim);

void OpenFile(const std::string& filename, std::vector<std::string>& vals);

void OpenFile(const std::string& filename, std::vector<int>& vals);

void OpenFile(const std::string& filename, std::vector<std::map<std::string, std::string>>& passports);

std::pair<std::string, std::string> CreatePairs(const std::string& source, const std::string& delim);