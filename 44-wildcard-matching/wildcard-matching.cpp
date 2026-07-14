class Solution {
public:
vector<vector<int>>dp;
    bool solve(string & s,string & p,int i,int j){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(j==p.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==s.size()){
            for(int x=j;x<p.size();x++){
                if(p[x]!='*'){
                    return false;
                }
                
            }
            return true;
        }
        if(p[j]==s[i] || p[j]=='?'){
            return dp[i][j]=solve(s,p,i+1,j+1);
        }
        if(p[j]=='*'){
            return dp[i][j]=(solve(s,p,i,j+1) || solve(s,p,i+1,j));
        }
        return dp[i][j]=false;


    }
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0);
    }
};