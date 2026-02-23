class Solution {
public:
    vector<string>result;
    void backtrack(string &s,int index,string &path){
        if(index==s.size()){
            result.push_back(path);
            return;
        }
        if(isdigit(s[index])){
            path.push_back(s[index]);
            backtrack(s,index+1,path);
            path.pop_back();
        }
        else{
            path.push_back(tolower(s[index]));
            backtrack(s,index+1,path);
            path.pop_back();
            path.push_back(toupper(s[index]));
            backtrack(s,index+1,path);
            path.pop_back();
        }

    }
    vector<string> letterCasePermutation(string s) {
        string path="";
        backtrack(s,0,path);
        return result;
        
    }
};