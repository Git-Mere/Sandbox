#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"

void print_subsequence(std::vector<unsigned> const& answer, std::vector<int> const& sequence) {
    for (unsigned i = 0; i < answer.size(); ++i) {
        std::cout << sequence[answer[i]] << " ";
    }
    std::cout << std::endl;
}

std::vector<unsigned>
longest_increasing_subsequence(std::vector<int> const& sequence) {
    //allocated/reserve table, init all to 0 - including init case
    //value, index
    std::vector<std::pair<int, int>> dp(sequence.size(), { 1, 0 });
    //main logic
    int size = sequence.size();
    for (int i = 1; i < size; i++) {
        int max_dp = dp[i].first;
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i] && dp[j].first >= max_dp) {
                max_dp = dp[j].first + 1;
            }
        }
        dp[i] = { max_dp, i };
    }


    sort(dp.begin(), dp.end());
    int length = (*std::max_element(dp.begin(), dp.end())).first;
    //reconstruct subsequence
    std::vector<unsigned> answer(length, 0); //vector of indices corresponding to the LIS
    //....
    answer[length - 1] = dp.back().second;

    for (int i = size - 1; i >= 0; i--) {
        if (answer.front() != 0) {
            break;
        }
        if (dp[i].first != length) {
            if (dp[i].second < answer[length - 1]) {
                length--;
                answer[length - 1] = dp[i].second;
            }
        }
    }


    return answer;
}

void test0() {
    //4 1 3 1 5 0
    std::vector<int> sequence;
    sequence.push_back(4); sequence.push_back(1); sequence.push_back(3);
    sequence.push_back(1); sequence.push_back(5); sequence.push_back(0);

    std::vector<unsigned> answer = longest_increasing_subsequence(sequence);
    std::cout << "Subsequence size " << answer.size() << std::endl;
    print_subsequence(answer, sequence);
}





int main() {
    vector<int> a{ 4,1,3,1,5,0 };

    test0();
    return 0;
}