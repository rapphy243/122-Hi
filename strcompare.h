#ifndef STRCOMPARE_H
#define STRCOMPARE_H

#include <string>

std::string cleanString(const std::string& str, bool skipSpace);

short strcmp_case_insensitive(const std::string& str1, const std::string& str2, bool skipSpace = false);

#endif
