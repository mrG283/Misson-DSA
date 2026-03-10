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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode *>q;
        q.push(root);
        int lefttoright=true;
        while(!q.empty()){
            vector<int>level(q.size());
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* a=q.front();
                q.pop();
                int index;
                if(lefttoright){
                    index=i;
                }
                else{
                    index=size-1-i;
                }
                level[index]=a->val;  
                if(a->left){
                    q.push(a->left);
                }  
                if(a->right){
                    q.push(a->right);
                }          

            }
            lefttoright=!lefttoright;
            result.push_back(level);

        }
        return result;

       
        
        
    }
};