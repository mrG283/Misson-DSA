class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int x:nums){
            m[x]++;
        }
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]>1){
                result.push_back(nums[i]);
                m[nums[i]]=0;
            }
        }
        return result;

        
    }
};