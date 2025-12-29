
class Solution {
public:
    unordered_map<string, bool> memo;
    unordered_map<string, vector<char>> mp;

    bool dfs(string bottom) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        vector<string> nexts;
        build(bottom, 0, "", nexts);

        for (auto &n : nexts) {
            if (dfs(n)) return memo[bottom] = true;
        }
        return memo[bottom] = false;
    }

    void build(const string &bottom, int idx, string cur, vector<string> &res) {
        if (idx == bottom.size() - 1) {
            res.push_back(cur);
            return;
        }
        string key;
        key.push_back(bottom[idx]);
        key.push_back(bottom[idx + 1]);
        if (!mp.count(key)) return;
        for (char c : mp[key]) {
            build(bottom, idx + 1, cur + c, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
