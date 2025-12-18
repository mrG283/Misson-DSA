class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int h = k / 2;

        vector<long long> prefOrig(n + 1, 0), prefPrice(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefOrig[i + 1] = prefOrig[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }

        long long ans = prefOrig[n];

        for (int l = 0; l + k <= n; l++) {
            int m = l + h;
            int r = l + k;

            long long origSegment = prefOrig[r] - prefOrig[l];
            long long newSegment = prefPrice[r] - prefPrice[m];

            long long total = prefOrig[n] - origSegment + newSegment;
            ans = max(ans, total);
        }

        return ans;
    }
};
