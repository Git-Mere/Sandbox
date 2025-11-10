#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"


int main() {
    vector<int> a{ 1,2,5};
    int test = 6;
    cout << DP::coinChange3(a, test);
    return 0;
}