class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long total = 0;
        for (int a : apple) total += a;
        sort(capacity.begin(), capacity.end(), greater<int>());
        long long cur = 0;
        int cnt = 0;
        for (int c : capacity) {
            cur += c;
            cnt++;
            if (cur >= total) return cnt;
        }
        return cnt;
    }
};
