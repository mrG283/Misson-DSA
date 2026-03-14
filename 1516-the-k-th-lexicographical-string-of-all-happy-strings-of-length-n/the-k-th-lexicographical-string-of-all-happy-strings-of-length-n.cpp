class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";
        
        string res = "";
        vector<char> chars = {'a','b','c'};
        
        for (int i = 0; i < n; i++) {
            for (char c : chars) {
                if (!res.empty() && res.back() == c) continue;
                
                int remaining = n - i - 1;
                int count = 1 << remaining;
                
                if (k > count) {
                    k -= count;
                } else {
                    res.push_back(c);
                    break;
                }
            }
        }
        
        return res;
    }
};