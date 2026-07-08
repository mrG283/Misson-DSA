class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& num1, vector<int>& num2, int k) {
        vector<vector<int>>ans;
        if(num1.empty()|| num2.empty()){
            return ans;
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        for(int i=0;i<num1.size();i++){
            q.push({num1[i]+num2[0],i,0});
        }
        while(k-- && !q.empty()){
            auto[sum,i,j]=q.top();
            ans.push_back({num1[i],num2[j]});
            q.pop();
            if(j+1<num2.size()){
                q.push({num1[i]+num2[j+1],i,j+1});

            }
        }
        return ans;

        
    }
};