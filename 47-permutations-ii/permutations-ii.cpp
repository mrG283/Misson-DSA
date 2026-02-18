class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& result,vector<int>&path,vector<bool>&used){
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            if(i<nums.size()-1 &&nums[i]==nums[i+1]&& !used[i+1]){
                continue;
            }
            used[i]=true;
            path.push_back(nums[i]);

            backtrack(nums,result,path,used);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>path;
        vector<bool>used(nums.size(),false);
        backtrack(nums,result,path,used);
        return result;
        
    }
};