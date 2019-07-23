#include "Validator.h"
#include "stdafx.h"

using namespace std;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }
{
}

void MovieValidator::validate(const Movie & m)
{
	vector<string> errors;
	if (m.getTitle().size() < 1)
		errors.push_back("The movie title must not be blank!\n");
	if (!isupper(m.getTitle()[0]))
		errors.push_back("The title of the movie bust begin with a capital letter!\n");

	if (m.getGenre().size() < 1)
		errors.push_back("The movie genre must not be blank!\n");

	// search for "www" or "http" at the beginning of the source string
	size_t posWww = m.getTrailer().find("www");
	size_t posHttp = m.getTrailer().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw MovieException(errors);

}
