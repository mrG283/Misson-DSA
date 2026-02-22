class Solution {
public:
    void backtrack(vector<vector<int>>&result,vector<int>&path,int start,int k,int n){
        if(path.size()==k){
            result.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++){
            path.push_back(i);
            backtrack(result,path,i+1,k,n);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>path;
        backtrack(result,path,1,k,n);
        return result;
        
    }
};