#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"

int main() {
    vector<int> days{ 1, 4, 6, 7, 8, 20 };
    vector<int> costs{ 2, 7, 15 };

    DP::mincostTickets(days, costs);

    return 0;
}