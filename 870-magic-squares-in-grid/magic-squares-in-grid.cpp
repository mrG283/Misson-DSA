class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                bool used[10] = {};
                bool ok = true;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int v = grid[i + x][j + y];
                        if (v < 1 || v > 9 || used[v]) {
                            ok = false;
                            break;
                        }
                        used[v] = true;
                    }
                    if (!ok) break;
                }
                if (!ok) continue;
                int s = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                for (int x = 0; x < 3; x++) {
                    int r = 0, c = 0;
                    for (int y = 0; y < 3; y++) {
                        r += grid[i + x][j + y];
                        c += grid[i + y][j + x];
                    }
                    if (r != s || c != s) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != s) continue;
                if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != s) continue;
                ans++;
            }
        }
        return ans;
    }
};
