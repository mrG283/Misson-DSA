class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1) == 0) {
                ans[i] = -1;
            } else {
                int t = 0;
                int x = nums[i];
                while (x & 1) {
                    t++;
                    x >>= 1;
                }
                ans[i] = nums[i] - (1 << (t - 1));
            }
        }
        return ans;
    }
};
