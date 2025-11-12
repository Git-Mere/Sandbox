#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"


int main() {
    //vector<int> a{ 1,2,5};
    //int test = 6;

    string a{ "abc" };
    string b{ "aea" };

    cout << DP::longestCommonSubsequence(a, b);
    return 0;
}