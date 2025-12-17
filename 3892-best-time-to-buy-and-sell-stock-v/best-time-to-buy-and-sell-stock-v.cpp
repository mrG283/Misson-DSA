class Solution {
public:
    long long maximumProfit(const std::vector<int>& prices, int k) {
        if (prices.empty() || prices.size() < 2 || k == 0) {
            return 0;
        }

        std::vector<long long> sell(k + 1);
        std::vector<long long> buy(k + 1);
        std::vector<long long> shortS(k + 1);

        const long long INITIAL_MIN_VALUE = std::numeric_limits<long long>::min() / 2;

        std::fill(sell.begin(), sell.end(), INITIAL_MIN_VALUE);
        std::fill(buy.begin(), buy.end(), INITIAL_MIN_VALUE);
        std::fill(shortS.begin(), shortS.end(), INITIAL_MIN_VALUE);

        sell[0] = 0;

        for (int p_int : prices) {
            long long p = p_int;

            std::vector<long long> nextSell = sell;
            std::vector<long long> nextBuy = buy;
            std::vector<long long> nextShort = shortS;

            for (int j = 1; j <= k; j++) {
                nextBuy[j] = std::max(buy[j], sell[j - 1] - p);
                nextShort[j] = std::max(shortS[j], sell[j - 1] + p);
                nextSell[j] = std::max(sell[j], std::max(buy[j] + p, shortS[j] - p));
            }

            sell = nextSell;
            buy = nextBuy;
            shortS = nextShort;
        }

        long long maxProfit = 0;
        for (long long s : sell) {
            maxProfit = std::max(maxProfit, s);
        }

        return maxProfit;
    }
};
