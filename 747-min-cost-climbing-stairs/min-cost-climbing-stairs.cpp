class Solution {
public:
    int costly(vector<int>&cost,vector<int>&dp,int idx){
        if(idx==0){
            
            return dp[0]=cost[0];
        }
        if(idx==1){
            return dp[1]=cost[1];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        dp[idx]=(cost[idx]+min(costly(cost,dp,idx-1),costly(cost,dp,idx-2)));
        return min(dp[idx],dp[idx-1]);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==2){
            return min(cost[0],cost[1]);
        }
        vector<int>dp(cost.size()+1,-1);

        return costly(cost,dp,cost.size()-1);
        
    }
};