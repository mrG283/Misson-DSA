class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>visited(rooms.size(),false);
        visited[0]=true;
        for(int i=0;i<rooms[0].size();i++) q.push(rooms[0][i]);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front();
                q.pop();
                if(!visited[x]){
                    for(int i=0;i<rooms[x].size();i++){
                        q.push(rooms[x][i]);
                    }
                }
                visited[x]=true;
            }

        }
        for(bool x:visited) if(!x) return false;
        return true;
        

        
    }
};