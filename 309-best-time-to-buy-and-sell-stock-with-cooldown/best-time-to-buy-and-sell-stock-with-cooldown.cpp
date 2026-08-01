class Solution {
public:
    int solve(int i,int s,vector<int>& prices,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][s]!=-1){
            return dp[i][s];
        }
        if(s){
            int buy=-prices[i]+solve(i+1,0,prices,dp);
            int skip=solve(i+1,1,prices,dp);
            return dp[i][s]=max(buy,skip);
        }
        else{
            int sell=+prices[i]+solve(i+2,1,prices,dp);
            int notsell=solve(i+1,0,prices,dp);
            return dp[i][s]=max(sell,notsell);
        }

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);

        
    }
};