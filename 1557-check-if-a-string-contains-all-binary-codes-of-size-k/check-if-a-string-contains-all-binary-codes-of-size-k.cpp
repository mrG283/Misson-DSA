class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int needed = 1 << k;
        vector<bool> seen(needed, false);

        int mask = needed - 1;
        int hash = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {

            hash = ((hash << 1) & mask) | (s[i] - '0');

            if (i >= k - 1 && !seen[hash]) {
                seen[hash] = true;
                count++;

                if (count == needed)
                    return true;
            }
        }

        return false;
    }
};