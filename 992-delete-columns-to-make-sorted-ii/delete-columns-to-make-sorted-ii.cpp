class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int deletions = 0;
        vector<bool> isSorted(n - 1, false);
        
        for (int col = 0; col < m; ++col) {
            bool deleteThisCol = false;
            for (int i = 0; i < n - 1; ++i) {
                if (!isSorted[i] && strs[i][col] > strs[i + 1][col]) {
                    deleteThisCol = true;
                    break;
                }
            }
            
            if (deleteThisCol) {
                deletions++;
            } else {
                for (int i = 0; i < n - 1; ++i) {
                    if (strs[i][col] < strs[i + 1][col]) {
                        isSorted[i] = true;
                    }
                }
            }
        }
        
        return deletions;
    }
};