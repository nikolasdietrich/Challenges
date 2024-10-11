#include <assert.h>
#include "solution.cpp"
#include <iostream>

int main()
{
    assert(lcs("", "") == "");
    assert(lcs("abc", "") == "");
    assert(lcs("", "abc") == "");
    assert(lcs("a", "b") == "");
    assert(lcs("a", "a") == "a");
    assert(lcs("abc", "ac") == "ac");
    assert(lcs("abcdef", "abc") == "abc");
    assert(lcs("abcdef", "acf") == "acf");
    assert(lcs("anothertest", "notatest") == "nottest");
    assert(lcs("132535365", "123456789") == "12356");
    assert(lcs("nothardlythefinaltest", "zzzfinallyzzz") == "final");
    assert(lcs("abcdefghijklmnopq", "apcdefghijklmnobq") == "acdefghijklmnoq");
    std::cout << "All tests finished succesfully" << std::endl;
}