const long long MOD = 1000000007;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1), pref(n+1);
        dp[0] = pref[0] = 1;
        deque<int> mn, mx;
        int l = 0;
        for(int r = 1; r <= n; r++) {
            int x = nums[r-1];
            while(!mn.empty() && nums[mn.back()] >= x) mn.pop_back();
            mn.push_back(r-1);
            while(!mx.empty() && nums[mx.back()] <= x) mx.pop_back();
            mx.push_back(r-1);
            while(nums[mx.front()] - nums[mn.front()] > k) {
                if(mn.front() == l) mn.pop_front();
                if(mx.front() == l) mx.pop_front();
                l++;
            }
            dp[r] = (pref[r-1] - (l ? pref[l-1] : 0) + MOD) % MOD;
            pref[r] = (pref[r-1] + dp[r]) % MOD;
        }
        return (int)dp[n];
    }
};
