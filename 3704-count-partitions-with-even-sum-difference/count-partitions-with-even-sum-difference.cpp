class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long total = 0;
        for (int x : nums) total += x;

        long long sum1 = 0;
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            sum1 += nums[i];
            long long right = total - sum1;

            if ((sum1 % 2) == (right % 2)) {
                count++;
            }
        }
        return count;
    }
};
