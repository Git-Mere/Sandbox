#include "sliding.window.h"
#include <unordered_map>
#include <limits>

bool HasSubset(std::unordered_map<char, int> a, std::unordered_map<char, int> b, char spe = 0);

bool HasSubset(std::unordered_map<char, int> a, std::unordered_map<char, int> b, char spe) {
    if (spe != 0) {
        a[spe]--;
    }
    for (auto it : b) {
        if (!a.count(it.first) || a[it.first] < it.second) {
            return false;
        }
    }

    return true;
}

std::tuple<int, int> minWindow(std::string const& text, std::string const& required_chars)
{
    std::tuple<int, int> result{0, std::numeric_limits<int>::max()};
    
    std::string tmp = text;
    std::unordered_map<char, int> window;

    std::unordered_map<char, int> possible;
    for (int i = 0; i < required_chars.size(); i++) {
        possible[required_chars[i]]++;
    }

    char* left = &tmp[0];
    char* right = &tmp[0];

    while (*right != 0) {
        window[*right]++;

        while (HasSubset(window, possible, *left)) {
            window[*left]--;
            left++;
        }

        int pos = left - &tmp[0];
        int length = right - left + 1;
        if (length < std::get<1>(result)) {
            if (HasSubset(window, possible)) {
                result = { pos, length };
            }
        }

        ++right;
    }


    return result;
}