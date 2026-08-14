class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0,maximum=0;
        int n=s.size();
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            maximum=max(maximum,j-i+1);
            j++;
        }
        return maximum;        
    }
};