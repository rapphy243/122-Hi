#include "strcompare.h"
#include <cassert>
#include <cctype>

std::string cleanString(std::string str, bool skipSpace) {
    std::string modified = "";
    for (char& c : str) {
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

short strcmp_case_insensitive(std::string str1, std::string str2, bool skipSpace) {
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

int main() {
    // Test cases
    // Test cleanString
    assert(cleanString("TEST", true) == "test");
    assert(cleanString("test", true) == "test");
    assert(cleanString("TesT", true) == "test");
    assert(cleanString("tESt", true) == "test");
    // Might as well test it 
    assert(cleanString("T EST", false) == "t est");
    assert(cleanString("tes t", false) == "tes t");
    assert(cleanString("Te sT", false) == "te st");
    assert(cleanString(" tESt", false) == " test");
    // Test strcmp_case_insensitive
    assert(strcmp_case_insensitive("String one", "String two") == -1);
    assert(strcmp_case_insensitive("String one", "String one") == 0);
    assert(strcmp_case_insensitive("String two", "String one") == 1);
    // Test skip spaces
    assert(strcmp_case_insensitive("my cool string", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive("My Cool String", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive("My Cool String", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive("My Cool String ", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive(" My Cool String", "mycoolstring", true) == 0);
    assert(strcmp_case_insensitive("Another string", "mycoolstring", true) == -1);

    return 0;
}
