class Solution {
public:
    bool dfs(int node,vector<int>&state,vector<vector<int>>&graph){
        if(state[node]==1) return false;
        if(state[node]==2) return true;
        state[node]=1;
        for(int nei:graph[node]){
            if(!dfs(nei,state,graph)){
                return false;
            }
        }
        state[node]=2;
        return true;


    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>state(graph.size(),0);
        vector<int>result;
        for(int i=0;i<graph.size();i++){
            if(dfs(i,state,graph)){
                result.push_back(i);
            }
        }
        return result;
        
    }
};