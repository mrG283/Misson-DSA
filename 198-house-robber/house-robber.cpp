class Solution {
public:
    int solve(vector<int>&nums,vector<int>&dp,int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int curr=nums[i]+solve(nums,dp,i+2);
        int skip=solve(nums,dp,i+1);
        return dp[i]=max(curr,skip);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,dp,0);
        
    }
};