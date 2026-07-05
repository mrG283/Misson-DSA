class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr=0, count=0,left=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(m.count(curr-k)) count+=m[curr-k];
            /**while(left<=i && curr>k){
                curr-=nums[left];
                left++;
            }**/
            m[curr]++;
        }
        return count;
    }
};