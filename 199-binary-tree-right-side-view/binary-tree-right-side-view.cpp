/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * a=q.front();
                q.pop();
                if(i==size-1){
                    result.push_back(a->val);
                }
                if(a->left){
                    q.push(a->left);
                }
                if(a->right){
                    q.push(a->right);
                }
            }
        }
        return result;
        
    }
};