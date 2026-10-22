class Solution {
public:
    int backtrack(vector<int>&nums,int start,int end){

        int prev1=0;
        int prev2=0;
        for(int i=start;i<=end;i++){
            int take=prev2+nums[i];
            int skip=prev1;
            int curr=max(take,skip);
            prev2=prev1;
            prev1=curr;

        }
        return prev1;

    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){    
            return nums[0];
        }
        int c1=backtrack(nums,0,n-2);
        int c2=backtrack(nums,1,n-1);

        return max(c1,c2);
    }
};