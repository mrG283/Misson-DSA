class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left =0;
        int right=nums.size()-1;
        int maxpairsum=0;
        while(left<right){
            int sum=nums[left]+nums[right];
            maxpairsum=max(maxpairsum,sum);
            left++;
            right--;
        }
        return maxpairsum;
    }
};
