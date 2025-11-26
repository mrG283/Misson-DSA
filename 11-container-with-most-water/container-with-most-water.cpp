class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int left=0;
        int right=height.size()-1;

        while(left<right){
            int h=min(height[left],height[right]);
            int w=right-left;
            maxwater=max(maxwater,h*w);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }



        }
         return maxwater;
    
    }
      
};