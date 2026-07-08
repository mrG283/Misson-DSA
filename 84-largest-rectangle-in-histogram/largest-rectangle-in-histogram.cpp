class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;
        stack<int>st;

        for(int i=0;i<=heights.size();i++){
           while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
            int h=st.top();
            st.pop();
            int width;
            if(st.empty()){
                width=i;
            }
            else{
                width=i-st.top()-1;
            }
            maxarea=max(maxarea,heights[h]*width);
           }
           st.push(i);
        }
        return maxarea;
        
    }
};