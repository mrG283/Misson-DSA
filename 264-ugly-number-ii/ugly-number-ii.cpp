class Solution {
public:
    int nthUglyNumber(int num) {
        vector<int>n(num);
        int i2=0,i3=0,i5=0;
        n[0]=1;
        for(int i=1;i<num;i++){
            int nexti2=n[i2]*2;
            int nexti3=n[i3]*3;
            int nexti5=n[i5]*5;
            int nextugly=min({nexti2,nexti3,nexti5});
            n[i]=nextugly;
            if(nextugly==nexti2){
                i2++;
            }
            if(nextugly==nexti3){
                i3++;
            }
            if(nextugly==nexti5){
                i5++;
            }
            
        }
        return n[num-1];
        
    }
};