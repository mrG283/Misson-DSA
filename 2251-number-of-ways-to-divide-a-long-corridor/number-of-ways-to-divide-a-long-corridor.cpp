class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1000000007;
        int total = 0;
        for (char c : corridor) if (c == 'S') total++;
        if (total == 0 || total % 2) return 0;

        long long ans = 1;
        int seats = 0;
        int plants = 0;
        bool first = true;

        for (char c : corridor) {
            if (c == 'S') {
                seats++;
                if (seats == 2) {
                    if (!first) ans = ans * (plants + 1) % MOD;
                    first = false;
                    seats = 0;
                    plants = 0;
                }
            } else {
                if (!first && seats == 0) plants++;
            }
        }
        return ans;
    }
};
