class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        int n = events.size();
        vector<int> suffixMax(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (events[m][0] > events[i][1]) r = m;
                else l = m + 1;
            }
            ans = max(ans, events[i][2] + suffixMax[l]);
        }
        
        return ans;
    }
};
