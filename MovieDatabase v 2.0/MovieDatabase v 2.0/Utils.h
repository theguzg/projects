#pragma once

#include <vector>
#include <string>

/*
Trims leading and trailing spaces from a string.
Input: s - string
Output: a string, with no leading and trailing spaces.
*/
std::string trim(const std::string & s);

/*
Trims leading and trailing spaces from a string.
Input: s - string
Output: a string, with no leading and trailing spaces.
*/
std::vector<std::string> tokenize(const std::string& str, char delimiter);