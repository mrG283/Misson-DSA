class Solution {
public:
    bool checkString(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b' && count==0){
                count++;
            }
            if(count==1 && s[i]=='a'){
                return false;
            }

            
        }
        return true;
        
    }
};