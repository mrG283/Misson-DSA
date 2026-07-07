class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        int sum=0;
        for(string op : operations){
            if(op=="C"){
                s.pop();
            }
            else if(op=="D"){
                int x=s.top();
                s.push(x*2);
            }
            else if(op=="+"){
                int top1=s.top();
                s.pop();
                int top2=s.top();
                s.push(top1);
                s.push(top1+top2);
            }
            else{
                s.push(stoi(op));
            }
        }
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;

        
    }
};