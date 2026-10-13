class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>s=nums;
        
        int left=0;
        int right=s.size()-1;
        long long sum=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]<0){
                s[i]=s[i]*-1;
            }
            
        }
      
        sort(s.begin(),s.end());
        //   for(int i=0;i<s.size();i++){
        //     cout<<s[i]<<" ";
        // }
        // if(count==s.size()){
        //     if(s.size()%2!=0){
        //         sum+=(nums[left]*nums[left]);
        //         left++;
        //         while(left<right){
        //             int x=((nums[left]*nums[left])-(nums[right]*nums[right]));
        //             sum+=x;
        //             left++;
        //             right--;

        //         }

        //     }
        //     else{
        //         while(left<right){
        //             int x=((nums[left]*nums[left])-(nums[right]*nums[right]));
        //             sum+=x;
        //             right--;
        //             left++;

        //         }
        //     }
        //     return sum<0 ? sum*-1:sum ;
            

        // }
        if(s.size()%2!=0){
            sum+=(s[right]*s[right]);
            right--;
            while(left<right){
                int x=((s[right]*s[right])-(s[left]*s[left]));
                sum+=x;
                // cout<<sum<<" ";
                right--;
                left++;

            }

        }
        else{
            while(left<right){
                int x=((s[right]*s[right])-(s[left]*s[left]));
                sum+=x;
                right--;
                left++;

            }
        }
        return sum<0 ? sum*-1:sum ;
        
        
    }
};