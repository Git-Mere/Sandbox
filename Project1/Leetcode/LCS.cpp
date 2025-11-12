#include "Dynamic Programming.h"

int DP::longestCommonSubsequence(string text1, string text2)
{
    int size1 = text1.size() + 1;
    int size2 = text2.size() + 1;

    vector<vector<int>> data;
    for (int i = 0; i < size1; i++) {
        vector<int> a(size2, 0);
        data.push_back(a);
    }

    for (int i = 1; i < size1; i++) {
        for (int j = 1; j < size2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                data[i][j] = 1 + data[i - 1][j - 1];
            }
            else {
                data[i][j] = max(data[i - 1][j], data[i][j - 1]);
            }

        }
    }

    return data[size1 - 1][size2 - 1];
}