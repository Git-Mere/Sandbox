#include "Control_Header.h"

int Array::maxProfit(vector<int>& prices) {
    int profit = 0;
    int buy_price = prices[0];
    for (int i = 0; i < prices.size(); i++) {
        if (buy_price > prices[i]) {
            buy_price = prices[i];
        }
        profit = std::max(profit, prices[i] - buy_price);

    }

    return profit;
}