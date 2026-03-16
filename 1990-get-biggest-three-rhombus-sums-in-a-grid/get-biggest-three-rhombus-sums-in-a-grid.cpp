class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int, greater<int>> st;
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                
                st.insert(grid[r][c]);
                
                for(int k = 1; ; k++) {
                    int nr = r + 2*k;
                    int lc = c - k;
                    int rc = c + k;
                    
                    if(nr >= m || lc < 0 || rc >= n) break;
                    
                    int sum = 0;
                    
                    int x = r, y = c;
                    for(int i = 0; i < k; i++) {
                        sum += grid[x][y];
                        x++; y--;
                    }
                    
                    for(int i = 0; i < k; i++) {
                        sum += grid[x][y];
                        x++; y++;
                    }
                    
                    for(int i = 0; i < k; i++) {
                        sum += grid[x][y];
                        x--; y++;
                    }
                    
                    for(int i = 0; i < k; i++) {
                        sum += grid[x][y];
                        x--; y--;
                    }
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> res;
        for(int x : st) {
            res.push_back(x);
            if(res.size() == 3) break;
        }
        
        return res;
    }
};