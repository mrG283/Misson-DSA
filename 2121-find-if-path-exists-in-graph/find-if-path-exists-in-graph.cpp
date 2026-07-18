class Solution {
public:
    // bool dfs(vector<vector<int>>& edges, int source, int destination,vector<vector<int>>&adj,vector<bool>&visited){
    //     if(source==destination){
    //         return true;
    //     }
    //     visited[source]=true;
    //     for(auto n:adj[source]){
    //         if(!visited[n]){
    //             if(dfs(edges,n,destination,adj,visited)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        // return dfs(edges,source,destination,adj,visited);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==destination){
                return true;
            }
            for(auto n:adj[node]){
                if(!visited[n]){
                    q.push(n);
                    visited[n]=true;
                }
            }
        }
        return false;
    }
};