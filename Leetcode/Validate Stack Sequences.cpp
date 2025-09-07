#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    cout << (s.validateStackSequences(pushed, popped) ? "true" : "false") << endl;
}
