class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        

        if (i < 0 || j < 0 || i >= n || j >= m) return 1;
        
       
        if (grid[i][j] == 0) return 1;
        
 
        if (vis[i][j]) return 0;
        
        vis[i][j] = true;
        
        int perimeter = 0;
        
      
        perimeter += dfs(grid, i + 1, j, vis);
        perimeter += dfs(grid, i - 1, j, vis);
        perimeter += dfs(grid, i, j + 1, vis);
        perimeter += dfs(grid, i, j - 1, vis);
        
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j, vis);
                }
            }
        }
        
        return 0;
    }
};