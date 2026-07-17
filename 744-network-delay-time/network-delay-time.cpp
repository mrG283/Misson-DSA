class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto a:times){
            int u=a[0];
            int v=a[1];
            int w=a[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        minheap.push({0,k});

        while(!minheap.empty()){
            auto[d,node]=minheap.top();
            minheap.pop();
            if(d>dist[node]){
                continue;
            }
            for(auto a:adj[node]){
                int neighbour=a.first;
                int weight=a.second;
                if(dist[node]+weight<dist[neighbour]){
                    dist[neighbour]=dist[node]+weight;
                    minheap.push({dist[neighbour],neighbour});
                }
            }
        }
        int ans=0;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;

        
    }
};