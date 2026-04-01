class Solution {
public:
    
    void backtrack(vector<vector<int>>&grid,vector<vector<int>>&visited,int &count,int i,int j,int m,int n){
        if(i>=m||j>=n||i<0||j<0||grid[i][j]==0||visited[i][j]==1){
            return;
        }
        if(grid[i][j]==1 && visited[i][j]==0){
            count++;
            visited[i][j]=1;
        }
        backtrack(grid,visited,count,i+1,j,m,n);
        backtrack(grid,visited,count,i,j+1,m,n);
        backtrack(grid,visited,count,i-1,j,m,n);
        backtrack(grid,visited,count,i,j-1,m,n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int maximum=0;
        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    backtrack(grid,visited,count,i,j,m,n);
                    
                    maximum=max(maximum,count);
                    
                   
                    count=0;
                }
            }
        }
        return maximum;
        
    }
};