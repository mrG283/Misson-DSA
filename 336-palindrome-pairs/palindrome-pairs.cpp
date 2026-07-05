class Solution {
public:
    bool ispalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int>m;
        vector<vector<int>>ans;
        for(int i=0;i<words.size();i++){
            string x=words[i];
            reverse(x.begin(),x.end());
            m[x]=i;
        }
        for(int i=0;i<words.size();i++){
            string word=words[i];
            for(int j=0;j<=word.size();j++){
                string left=word.substr(0,j);
                string right=word.substr(j);
                if(m.count(left) && ispalindrome(right) && m[left]!=i){
                    ans.push_back({i,m[left]});
                }
                if(!left.empty() && m.count(right) && ispalindrome(left) && m[right]!=i){
                    ans.push_back({m[right],i});
                }
            }
        }
        return ans;
        
    }
};