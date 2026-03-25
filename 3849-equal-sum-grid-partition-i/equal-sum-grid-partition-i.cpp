class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum = 0;

        for (auto &row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }

        
        if (totalSum % 2 != 0) return false;

       
        long long topSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                topSum += grid[i][j];
            }

            if (topSum == totalSum - topSum) return true;
        }

        
        long long leftSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                leftSum += grid[i][j];
            }

            if (leftSum == totalSum - leftSum) return true;
        }

        return false;
    }
};