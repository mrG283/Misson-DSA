class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int left=0;
        int right=0;
        int maxlength=0;
        while(right<s.size()){
            while(mp.find(s[right])!=mp.end()){
                mp.erase(s[left]);
                left++;
            }
            mp[s[right]]++;
            maxlength=max(maxlength,right-left+1);
            right++;

        }
        return maxlength;

        
    }
};