class Solution {
public:
    void backtrack(vector<int>candidates,vector<vector<int>>& result,vector<int>& path,int target,int index){
        if(target==0){
            result.push_back(path);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target)break;
            path.push_back(candidates[i]);
            backtrack(candidates,result,path,target-candidates[i],i+1);
            path.pop_back();

            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>path;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,result,path,target,0);
        return result;
        
    }
};