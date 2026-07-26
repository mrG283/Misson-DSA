class Solution {
public:
    int solve(string s,vector<int>&dp,int i){
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int onedigit=solve(s,dp,i+1);
        int twodigit=0;
        if(i+1<s.size()){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26){
                twodigit=solve(s,dp,i+2);
            }
        }
        return dp[i]=onedigit+twodigit;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return solve(s,dp,0);
        
    }
};