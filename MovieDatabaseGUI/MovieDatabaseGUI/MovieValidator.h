#pragma once
#include <string>
#include "Movie.h"
#include <vector>
#include <stdio.h>

class MovieException
{
private:
	std::vector<std::string> errors;

public:
	MovieException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const { return this->errors; }

};

class MovieValidator
{
public:
	MovieValidator() {}
	static void validate(const Movie & m);
};
