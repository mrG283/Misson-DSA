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
    void dfs(TreeNode * root,int target,vector<int>&path,vector<vector<int>>&result){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        target-=root->val;
        if(root->left==NULL && root->right==NULL && target==0){
            result.push_back(path);
        }
        dfs(root->left,target,path,result);
        dfs(root->right,target,path,result);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>path;
        dfs(root,targetSum,path,result);
        return result;
        
    }
};