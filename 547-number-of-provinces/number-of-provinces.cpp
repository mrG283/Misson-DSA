class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y){
        parent[find(x)]= find(y);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    unite(i,j);
                }
            }
        }
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(find(i));
        }
        
        return s.size();
       
        
    }
};