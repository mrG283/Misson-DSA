class DSU{
public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_p=find(x);
        int y_p=find(y);
        if(x_p==y_p){
            return;

        }
        else if(rank[x_p]>rank[y_p]){
            parent[y_p]=x_p;
        }
        else if(rank[y_p]>rank[x_p]){
            parent[x_p]=y_p;
        }
        else{
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }
};
class Solution {
public:

        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n+1);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(dsu.find(u)==dsu.find(v)){
                return edge;
            }
            dsu.Union(u,v);
        }
    
        return {};
        
    }
};