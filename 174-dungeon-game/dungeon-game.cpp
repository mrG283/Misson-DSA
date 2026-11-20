class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&dungeon){
        int m=dungeon.size();
        int n=dungeon[0].size();
        if(i>=m || j>=n){
            return INT_MAX;
        }
        if(i==m-1 && j==n-1){
            return max(1,1-dungeon[i][j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=solve(i+1,j,dp,dungeon);
        int right=solve(i,j+1,dp,dungeon);
        int minimum=min(down,right);
        return dp[i][j]=max(1,minimum-dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,dp,dungeon);
        
    }
};