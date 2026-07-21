class Solution {
public:
    void combination(int n,int k,vector<vector<int>>&result,vector<int>&path,int index){
        if(path.size()==k){
            result.push_back(path);
            return;
        }
        for(int i=index;i<=n;i++){
            path.push_back(i);
            combination(n,k,result,path,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>path;

        combination(n,k,result,path,1);
        return result;
        
    }
};