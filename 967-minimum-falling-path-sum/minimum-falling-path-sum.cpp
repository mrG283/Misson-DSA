class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int n=matrix.size();
        if(j<0 || j>=n){
            return INT_MAX;
        }
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=-2){
            return dp[i][j];
        }
        int d=solve(i+1,j,matrix,dp);
        int dl=solve(i+1,j-1,matrix,dp);
        int dr=solve(i+1,j+1,matrix,dp);

        return dp[i][j]=matrix[i][j]+min(d,min(dl,dr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-2));
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,solve(0,j,matrix,dp));
        }
        return ans;
        
    }
};