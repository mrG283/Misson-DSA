class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto a:mp){
            ans.push_back(a.second);
        }
        return ans;
        
    }
};