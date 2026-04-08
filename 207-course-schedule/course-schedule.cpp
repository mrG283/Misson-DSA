class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto x:prerequisites){
            int a=x[0];
            int b=x[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int a:adj[node]){
                if(--indegree[a]==0){
                    q.push(a);
                }
            }
        }
        return count==numCourses;
        
    }
};