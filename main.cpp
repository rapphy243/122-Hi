#include <iostream>
#include <cassert>
#include <string>
#include "strcompare.h"

using namespace std;

void testFunctions() {
    // Test cases
    // Test cleanString
    assert(cleanString("TEST", false) == "test");
    assert(cleanString("test", false) == "test");
    assert(cleanString("TesT", false) == "test");
    assert(cleanString("tESt", false) == "test");
    // Test with spaces strings
    assert(cleanString("T EST", true) == "test");
    assert(cleanString("tes t", true) == "test");
    assert(cleanString("Te sT", true) == "test");
    assert(cleanString(" tESt", true) == "test");
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
    assert(strcmp_case_insensitive("              ", "mycoolstring", true) == -1);
    assert(strcmp_case_insensitive("", "", true) == 0);
    assert(strcmp_case_insensitive("This is a long string", "short string", true) == 1);
}

int main() {
    bool isDebug{false};
    if (!isDebug) {
        string str1{"String one"};
        string str2{"string two"};
        cout << "The comparison of \"" + str1 + "\" and \"" + str2 + "\" returns ";
        cout << strcmp_case_insensitive(str1, str2) << ".\n";
        cout << "The comparison of \"" + str1 + "\" and \"" + str1 + "\" returns ";
        cout << strcmp_case_insensitive(str1, str1) << ".\n";
        cout << "The comparison of \"" + str2 + "\" and \"" + str1 + "\" returns ";
        cout << strcmp_case_insensitive(str2, str1) << ".\n";
    }
    else {
        testFunctions();
    }
    return 0;
}
