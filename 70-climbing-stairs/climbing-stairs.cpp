class Solution {
public:
    int backtrack(vector<int>&dp,int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=backtrack(dp,n-1)+backtrack(dp,n-2);

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return backtrack(dp,n);
        
    }
};