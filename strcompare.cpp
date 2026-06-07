#include "strcompare.h"
#include <cctype>

std::string cleanString(const std::string& str, bool skipSpace) {
    std::string modified = "";
    for (char c : str) {
        if (skipSpace) {
            if (!isspace(c)) {
                modified += tolower(c);
            }
        }
        else {
            modified += tolower(c);
        }
    }
    return modified;
}

short strcmp_case_insensitive(const std::string& str1, const std::string& str2, bool skipSpace) {
    std::string modified1 = cleanString(str1, skipSpace);
    std::string modified2 = cleanString(str2, skipSpace);
    if (modified1 > modified2) {
        return 1;
    }
    else if (modified1 < modified2) {
        return -1;
    }
    return 0;
}
