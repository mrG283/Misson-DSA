class Solution {
public:
    int longestValidParentheses(string s) {
        int count=0,max_valid=0,mult=0, count2=0,max_valid2=0,mult2=0,n=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') count++;
            else count--;
            if(s[n-i-1]==')') count2++;
            else count2--;
            if(s[i]==')') mult++;
            if(s[n-i-1]=='(') mult2++;
            if(count2<0){
                mult2=0;
                count2=0;
            }
            if(count2==0) max_valid2=max(max_valid2,mult2*2);
            if(count<0){
                mult=0;
                count=0;
            }
            if(count==0) max_valid=max(max_valid,mult*2);
        }
        return max(max_valid,max_valid2);
    }
};