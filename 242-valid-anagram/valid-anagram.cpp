class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        for(int c:s){
            count[c-'a']++;
        }
        for(int b:t){
            count[b-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
        
    }
};