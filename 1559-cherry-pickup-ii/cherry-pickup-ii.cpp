class Solution {
public:
    int solve(int i,int j1,int j2,int m,int n,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1==n || j2<0 || j2==n){
            return INT_MIN;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        if(i==m-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }

        }
        
        int cherry=0;
        if(j1==j2){
            cherry+=grid[i][j1];
        }
        else{
            cherry+=(grid[i][j1]+grid[i][j2]);
        }
        int maxi=INT_MIN;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int val=solve(i+1,j1+x,j2+y,m,n,grid,dp);
                maxi=max(val,maxi);

            }
        }
            

        
        return dp[i][j1][j2]=cherry+maxi;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(0,0,n-1,m,n,grid,dp);
        
    }
};