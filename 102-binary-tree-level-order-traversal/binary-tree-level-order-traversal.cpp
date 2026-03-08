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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;

            for(int i=0;i<size;i++){
                TreeNode* a= q.front();
                q.pop();
                
                level.push_back(a->val);
                if(a->left){
                    q.push(a->left);
                }
                if(a->right){
                    q.push(a->right);
                }

            }
            result.push_back(level);
        }
        return result;
        
    }
};