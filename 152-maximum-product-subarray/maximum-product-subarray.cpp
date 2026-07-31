class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1,suff=1;
        int result=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pref*=nums[i];
            suff*=nums[nums.size()-1-i];
            result=max({result,pref,suff});
            if(pref==0){
                pref=1;
            }
            if(suff==0){
                suff=1;
            }
        }
        return result;
    }
};