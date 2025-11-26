class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int val=target-num;
            if(mpp.find(val)!=mpp.end()){
                return {mpp[val],i};
                
            }
            mpp[num]=i;

        }
        return {-1,1};
        
    }    
};