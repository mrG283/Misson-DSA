class Solution {
public:
    void backtrack(vector<string>&result,int n,string &path,int start,int end){
        if(path.size()==2*n){
            result.push_back(path);
            return;
        }
        if(start<n){
            path.push_back('(');
            backtrack(result,n,path,start+1,end);
            path.pop_back();
        }
        if(start>end){
            path.push_back(')');
            backtrack(result,n,path,start,end+1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string path;
        backtrack(result,n,path,0,0);
        return result;
    }
};