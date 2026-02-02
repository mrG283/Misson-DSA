class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
         const int mod = 1e9 + 7;
         sort(arr.begin(),arr.end());
         unordered_map<int,long long>dp;
         for(int i=0;i<arr.size();i++){
            dp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int b=arr[i]/arr[j];
                    if(dp.count(b)){
                        dp[arr[i]]=(dp[arr[i]]+dp[arr[j]]*dp[b])%mod;
                    }

                }
            }
         }
         int ans;
         for(auto x:dp){
            ans=(ans+x.second)%mod;
         }
         return ans;
        
    }
};