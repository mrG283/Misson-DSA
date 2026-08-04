class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        int width=0;
        stack<int>st;
        int n=heights.size();
        for(int i=0;i<=heights.size();i++){
            int curr;
            if(i==n){
                curr=0;
            }
            else{
                curr=heights[i];
            }
            while(!st.empty() && heights[st.top()]>curr){
                int height=heights[st.top()];
                st.pop();
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                int area=width*height;
                maxarea=max(area,maxarea);

            }
            st.push(i);
        }
        return maxarea;
        
    }
};