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
    int postindex;
    TreeNode * bst(vector<int> &inorder,vector<int>&postorder,int left,int right){
        if(left>right){
            return NULL;
        }
        int rootval=postorder[postindex--];
        TreeNode * root=new TreeNode(rootval);
        int index=mp[rootval];

        root->right=bst(inorder,postorder,index+1,right);
        root->left=bst(inorder,postorder,left,index-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postindex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return bst(inorder,postorder,0,postindex);
        
    }
};