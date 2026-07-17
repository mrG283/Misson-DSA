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
    unordered_map<int,int>mp;
    int preindex=0;
    TreeNode * build(vector<int>preorder,vector<int>inorder,int start,int end){
        if(start>end){
            return NULL;
        }
        int rootval=preorder[preindex++];
        TreeNode * root=new TreeNode(rootval);
        int index=mp[rootval];
        
        root->left=build(preorder,inorder,start,index-1);
        root->right=build(preorder,inorder,index+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,inorder.size()-1);
        
    }
};