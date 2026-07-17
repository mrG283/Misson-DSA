class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            int effort=a.first;
            int r=a.second.first;
            int c=a.second.second;
            if(r==m-1 && c==n-1){
                return effort;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int neweffort=max(effort,abs(heights[r][c]-heights[nr][nc]));
                    if(neweffort<dist[nr][nc]){
                        dist[nr][nc]=neweffort;
                        pq.push({neweffort,{nr,nc}});
                    }

                }
            }
        }
        return 0;
        
    }
};