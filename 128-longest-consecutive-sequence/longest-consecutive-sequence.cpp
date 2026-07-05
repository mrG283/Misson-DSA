class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        for(int num:s){
           
            if(s.find(num-1)==s.end()){
                long long curr=num;
                int length=1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    length++;
                }
                longest=max(length,longest);

            }
        }
        return longest;
        
        
    }
};