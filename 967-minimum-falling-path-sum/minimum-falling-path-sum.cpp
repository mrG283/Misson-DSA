class Solution {
    int solve(int i , int j, vector<vector<int>>&m, vector<vector<int>>&dp){
        if(i==m.size() || j == m[0].size() || j < 0) return INT_MAX;
        if(i == m.size()-1 && j>=0 && j<m[0].size()) return m[i][j]; 
        if(dp[i][j]!=-101) return dp[i][j];
        int b = solve( i+1, j, m,dp);
        int lb = solve(i+1, j-1, m,dp);
        int rb = solve(i+1, j+1, m,dp);
        return dp[i][j] = m[i][j] + min(b,min(lb, rb));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -101));
        int ans = INT_MAX;
        for(int j = 0; j<matrix[0].size(); j++){
            ans = min (ans, solve(0, j, matrix, dp));
        }
        return ans;
    }
};