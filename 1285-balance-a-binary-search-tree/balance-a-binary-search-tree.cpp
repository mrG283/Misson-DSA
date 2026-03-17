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
    void inorder(TreeNode* root, vector<int>& v) {
        if(!root){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);

        
    }

    TreeNode* build(vector<int>& v, int l, int r) {
        if(l>r){
            return NULL;
        }
        int mid=(l+r)/2;
        TreeNode *a=new TreeNode(v[mid]);
        a->left=build(v,l,mid-1);
        a->right=build(v,mid+1,r);
        return a;
        
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return build(v, 0, v.size() - 1);
    }
};
