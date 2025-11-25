#include <fstream>
#include <limits>
#include <iostream>
#include <cstring> // strlen
#include "sliding.window.h"

std::string createStringFromFile(char const* filename)
{
    std::ifstream file(filename);
    if (not file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::string content((std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));
    return content;
}

void testfile(char const* filename, char const* required_chars)
{
    std::cout << "Looking for chars \"" << required_chars << "\"\n";

    std::string str = createStringFromFile(filename);
    auto [start, length] = minWindow(str, required_chars);
    if (length != std::numeric_limits<int>::max()) {
        std::cout << "Min window substring: \"" << str.substr(start, length) << "\"\n";
        std::cout << "Start pos: " << start << ", length: " << length << "\n";
        if (length == strlen(required_chars)) {
            std::cout << "Optimal solution found - substring is a permutation of required chars\n";
        }
    }
    else {
        std::cout << "No valid window found\n";
    }
}

void test0() // no duplicates in required_chars
{
    //                  01234567890123
    std::string text = "ADOBECODEBANC";
    //                  ------  0, 6          first window with all chars - record (current best)
    //                  -------- 0, 10        second window with all chars - longer than best, skip
    //                       ------ 5, 6      third window with all chars - same as best, skip
    //                           ----- 9, 4   fourth window with all chars - shorter, update best - answer
    std::string required_chars = "ABC"; // no duplicates

    auto [start, length] = minWindow(text, required_chars);
    if (length != std::numeric_limits<int>::max()) {
        std::cout << "Min window substring: " << text.substr(start, length) << "\n";
        std::cout << "Start pos: " << start << ", length: " << length << "\n";
    }
    else {
        std::cout << "No valid window found\n";
    }
}

void test1() // no duplicates in required_chars
{
    //                            111111111112222
    //                  0123456789012345678901234
    std::string text = "A--B--C--D--A-B-C-D-ABCD";

    //start positions and lengths of all windows containing all required chars:
    //A--B--C--D
    //start 0, length 10
    //B--C--D--A
    //start 3, length 10
    //C--D--A-B
    //start 6, length 9
    //D--A-B-C
    //start 9, length 8
    //A-B-C-D
    //start 12, length 7
    //B-C-D-A
    //start 14, length 7
    //C-D-AB
    //start 16, length 6
    //D-ABC
    //start 18, length 5
    //ABCD
    //start 20, length 4
    std::string required_chars = "ABCD"; // no duplicates

    auto [start, length] = minWindow(text, required_chars);
    if (length != std::numeric_limits<int>::max()) {
        std::cout << "Min window substring: " << text.substr(start, length) << "\n";
        std::cout << "Start pos: " << start << ", length: " << length << "\n";
    }
    else {
        std::cout << "No valid window found\n";
    }
}

void test2()
{
    testfile("in0.txt", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void test3()
{
    testfile("in1.txt", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void test4()
{
    testfile("in2.txt", "CODE");
}

void test5()
{
    testfile("in2.txt", "SWITCH");
}

void test6()
{
    testfile("in2.txt", "BINARY");
}

void test7()
{
    testfile("pi.1000.digits.txt", "0123456789");
}

// tests with repeated chars in required_chars - extra credit
void test8()
{
    //                  01234567890123
    std::string text = "ABAAAAABAAAB";
    //                   -------    1, 7  - best so far
    //                   --------   1, 8  - longer - skip
    //                   ---------  1, 9  - longer - skip
    //                   ---------- 1, 10 - longer - skip
    //                        ----- 7, 5  - has all chars - shorter - update best

    std::string required_chars = "AABB";

    auto [start, length] = minWindow(text, required_chars);
    if (length != std::numeric_limits<int>::max()) {
        std::cout << "Min window substring: " << text.substr(start, length) << "\n";
        std::cout << "Start pos: " << start << ", length: " << length << "\n";
    }
    else {
        std::cout << "No valid window found\n";
    }
}

void test9()
{
    testfile("pi.1000.digits.txt", "00112233445566778899");
}

void test10()
{
    testfile("pi.1000.digits.txt", "000111222333444555666777888999");
}

void test11()
{
    testfile("the.raven.txt", "albatros");
}

void test12()
{
    testfile("the.raven.txt", "nightingale");
}

void (*pTests[])() = { test0, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12 };


#include <cstdlib> // sscanf, etc
int main(int argc, char* argv[])
{

    test0();
    //int testNum = 0;
    //if (argc > 1) {
    //    testNum = std::sscanf(argv[1], "%d", &testNum) == 1 ? testNum : 0;
    //}
    //pTests[testNum]();

    return 0;
}
