class Solution {
public:
    unordered_map<int,int> mp;

    int numSquares(int x) {
        if (x == 0) return 0;

        if (mp.count(x)) return mp[x];

        int ans = INT_MAX;

        for (int k = 1; k * k <= x; k++) {
            ans = min(ans, 1 + numSquares(x - k*k));
        }

        mp[x] = ans;
        return ans;
    }
};
