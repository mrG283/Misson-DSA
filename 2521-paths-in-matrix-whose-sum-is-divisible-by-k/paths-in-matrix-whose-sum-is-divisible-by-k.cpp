class Solution {
public:
   int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        int start_rem = grid[0][0] % k;
        dp[0][0][start_rem] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int current_val = grid[i][j];
                int val_mod_k = current_val % k;
                
                for (int r = 0; r < k; ++r) {
                   
                    int r_prev = (r - val_mod_k + k) % k;

                   
                    if (i > 0) {
                       
                        int count_from_up = dp[i - 1][j][r_prev];
                        dp[i][j][r] = (dp[i][j][r] + count_from_up) % MOD;
                    }

                  
                    if (j > 0) {
                       
                        int count_from_left = dp[i][j - 1][r_prev];
                        
                        dp[i][j][r] = (dp[i][j][r] + count_from_left) % MOD;
                    }

                   
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
