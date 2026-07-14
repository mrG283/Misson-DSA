class Solution {
public:
    int calculate(string s) {
        int result=0;
        long number=0;
        int sign=1;
        stack<int>st;
        for(char c:s){
            if(isdigit(c)){
                number=number*10+(c-'0');
            }
            if(c=='+'){
                result+=sign*number;
                number=0;
                sign=1;
            }
            if(c=='-'){
                result+=sign*number;
                number=0;
                sign=-1;
            }
            if(c=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            if(c==')'){
                result+=sign*number;
                number=0;
                sign=1;
                int x=st.top();
                result*=x;
                st.pop();
                result+=st.top();
                st.pop();

            }
        }
        result+=sign*number;
        return result;
        
    }
};