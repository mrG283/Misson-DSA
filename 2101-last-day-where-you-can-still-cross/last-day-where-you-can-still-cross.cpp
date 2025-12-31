class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        auto canCross = [&](int day) {
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    grid[i][j] = 0;

            for (int i = 0; i < day; i++)
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;

            queue<pair<int,int>> q;
            vector<vector<int>> vis(row, vector<int>(col, 0));

            for (int j = 0; j < col; j++) {
                if (grid[0][j] == 0) {
                    q.push({0, j});
                    vis[0][j] = 1;
                }
            }

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x == row - 1) return true;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                        !vis[nx][ny] && grid[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            return false;
        };

        int l = 1, r = cells.size(), ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canCross(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
