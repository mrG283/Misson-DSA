class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2){
            return n;
        }
        int result=0;
        for(int i=0;i<points.size();i++){
            map<pair<int,int>,int>mp;
            for(int j=i+1;j<n;j++){
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                else if (dx == 0) {
                    dy = 1;         
                }
                else if (dy == 0) {
                    dx = 1;        
                }
                mp[{dx,dy}]++;
            }
            int best=0;
            for(auto it:mp){
                best=max(best,it.second);
            }
            result=max(result,best+1);
        
        }
        return result;
        
    }
};