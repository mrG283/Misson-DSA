class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long max_sum = LLONG_MIN;
        vector<long long> min_prefix(k, LLONG_MAX);
        min_prefix[0] = 0;
        long long current_prefix_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            current_prefix_sum += nums[i];
            int remainder = (i + 1) % k;

            if (min_prefix[remainder] != LLONG_MAX) {
                max_sum = max(max_sum, current_prefix_sum - min_prefix[remainder]);
            }

            min_prefix[remainder] = min(min_prefix[remainder], current_prefix_sum);
        }

        return max_sum == LLONG_MIN ? 0 : max_sum;
    }
};