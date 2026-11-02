class Solution {
public:
    void dfs(int n,vector<int>&visited,vector<vector<int>>&adj){
        visited[n]=1;
        for(int v:adj[n]){
            if(!visited[v]){
                dfs(v,visited,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        for(auto i: connections){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int connection=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                connection++;
                dfs(i,visited,adj);
            }
        }
        return connection-1;

        
    }
};