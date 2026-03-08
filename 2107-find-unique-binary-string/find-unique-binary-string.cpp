class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result(n, '0');

        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '0')
                result[i] = '1';
            else
                result[i] = '0';
        }

        return result;
    }
};