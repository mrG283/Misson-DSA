class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while (true) {
            bool ok = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;

            int idx = 0;
            int minSum = nums[0] + nums[1];
            for (int i = 1; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }
        return ops;
    }
};
