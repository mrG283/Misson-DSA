class Solution {
public:
    int binaryGap(int n) {
        int ans=0,last=-1,pos=0;
        while(n>0){
            if(n&1){
                if(last!=-1){
                    ans=max(ans,pos-last);
                }
                last=pos;


            }
            n>>=1;
            pos++;
        }
        return ans;
    }
};