class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0,start=0,end=0;
        int n=s.size();
        while(i<s.size()){
            while(i<n && s[i]==' '){
            i++;
            }
            if(i>=n)break;
            start=i;
            while(i<n && s[i]!=' ')i++;
            end=i-1;
            reverse(s.begin()+start,s.begin()+end+1);

        }
        string result="";
        i=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i>=n)break;
            if(!result.empty())result+=" ";
            while(i<n && s[i]!=' '){
                result+=s[i++];
            }
        }
        return result;
        
        

        
    }
};