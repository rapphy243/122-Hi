#ifndef STRCOMPARE_H
#define STRCOMPARE_H

#include <string>

std::string cleanString(std::string str, bool skipSpace);

short strcmp_case_insensitive(std::string string1, std::string string2, bool skipSpace = false);

#endif
