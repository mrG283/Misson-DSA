class Solution {
public:
    unordered_map<int,int>position;
    map<pair<int,int>,bool>mp;
    bool solve(vector<int>&stones,int index,int jump){
        if(index==stones.size()-1){
            return true;
        }
        if(mp.count({index,jump})){
            return mp[{index,jump}];
        }
        for(int i=jump-1;i<=jump+1;i++){
            if(i<=0){
                continue;
            }
            int nextpos=stones[index]+i;
            if(position.count(nextpos)){
                if(solve(stones,position[nextpos],i)){
                    return mp[{index,nextpos}]=true;
                }
            }
        }
        return mp[{index,jump}]=false;
    }
    bool canCross(vector<int>& stones) {
        for(int i=0;i<stones.size();i++){
            position[stones[i]]=i;
        }
        return solve(stones,0,0);
        
    }
};