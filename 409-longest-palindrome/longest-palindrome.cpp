class Solution {
public:
   
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        int length=0;
        bool odd=false;
        for(auto a:m){
            if(a.second%2==0){
                length+=a.second;
            }
            else{
                length+=(a.second-1);
                odd=true;
            }
        }
        if(odd){
            length++;
        }
        return length;
        
     
        
        
    }
};