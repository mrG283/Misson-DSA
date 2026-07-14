class Solution {
public:
    vector<vector<int>>res;
    void backtrack(int start,vector<int>curr,int k,int n){
        if(curr.size()==k && n==0){
            res.push_back(curr);
            return;
        }
        if(n<0 || curr.size()==k){
            return;
        }
        for(int i=start;i<=9;i++){
            curr.push_back(i);
            backtrack(i+1,curr,k,n-i);
            curr.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        backtrack(1,curr,k,n);
        return res;


        
    }
};