class Solution {
public:
    int longestValidParentheses(string s) {
        int count=0,max_valid=0,mult=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') count++;
            else count--;
            if(s[i]==')') mult++;
            if(count<0){
                mult=0;
                count=0;
            }
            if(count==0) max_valid=max(max_valid,mult*2);
        }
        int count2=0,max_valid2=0,mult2=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')') count2++;
            else count2--;
            if(s[i]=='(') mult2++;
            if(count2<0){
                mult2=0;
                count2=0;
            }
            if(count2==0) max_valid2=max(max_valid2,mult2*2);
        }
        return max(max_valid,max_valid2);
    }
};