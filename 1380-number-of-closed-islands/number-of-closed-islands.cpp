class Solution {
public:

    bool dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, int n, int m){
        bool closed = true;
        visited[i][j] = 1;
        if (i==0){
            closed = false;
        }
        else{
            if (grid[i-1][j]==0 && !visited[i-1][j]) closed = dfs(grid,visited,i-1,j,n,m) && closed;
        }
        if (j==0){
            closed = false;
        }
        else{
            if (grid[i][j-1]==0 && !visited[i][j-1])closed = dfs(grid,visited,i,j-1,n,m) && closed;
        }
        if (i==(n-1)){
            closed = false;
        }
        else{
            if (grid[i+1][j]==0 && !visited[i+1][j])closed = dfs(grid,visited,i+1,j,n,m) && closed;
        }
        if (j==(m-1)){
            closed = false;
        }
        else{
            if (grid[i][j+1]==0 && !visited[i][j+1])closed = dfs(grid,visited,i,j+1,n,m) && closed;
        }
        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));
        int ans = 0;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m ; j++){
                if (grid[i][j] == 0 && !visited[i][j]){
                    if (dfs(grid,visited,i,j,n,m)){
                        ans++; 
                    }
                }
            }
        }
        return ans;
    }
};