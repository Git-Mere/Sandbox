#include "Dynamic Programming.h"

bool DP::wordBreak(string s, vector<string>& wordDict) {
    sort(wordDict.begin(), wordDict.end(), [](const auto& a, const auto& b) {
        return a.size() > b.size();
        });


    string tmp = s;

    for (int j = 0; j < wordDict.size(); j++) {
        int pos = tmp.find(wordDict[j]);
        if (pos == 0) {
            tmp.erase(pos, wordDict[j].size());
            j = -1;
        }
    }


    if (tmp.empty()) {
        return true;
    }
    return false;
}