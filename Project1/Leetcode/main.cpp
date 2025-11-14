#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"


int main() {
    vector<string> a{ "apple","pen" };
    string s = "applepenapple";

    cout << DP::wordBreak(s, a);
    return 0;
}