class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        int r = rows - 1;
        int c = 0;

        while (r >= 0 && c < cols) {
            if (grid[r][c] < 0) {
                count += cols - c;
                r--;
            } else {
                c++;
            }
        }

        return count;
    }
};
