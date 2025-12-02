
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> yMap;
        for (const auto& point : points) {
            yMap[point[1]]++;
        }

        long long totalTrapezoids = 0;
        long long currentPairsSum = 0;
        const int MOD = 1e9 + 7;

        for (auto const& [y, count] : yMap) {
            if (count < 2) continue;

            long long pairsOnLine = (1LL * count * (count - 1)) / 2;
            pairsOnLine %= MOD;

            totalTrapezoids = (totalTrapezoids + (pairsOnLine * currentPairsSum) % MOD) % MOD;
            currentPairsSum = (currentPairsSum + pairsOnLine) % MOD;
        }

        return totalTrapezoids;
    }
};