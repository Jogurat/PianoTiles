#ifndef __HELPERFUNS_H__
#define __HELPERFUNS_H__

#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <regex>

//komentar za testiranje git-a
std::map<char, std::pair<std::string, int>> createInputMap(std::string filePath);
int commonDiv(int a, int b);

#endif