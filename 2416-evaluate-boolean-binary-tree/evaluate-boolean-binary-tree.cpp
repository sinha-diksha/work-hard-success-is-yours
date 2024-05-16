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
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        int l=helper(root->left);
        
        int r=helper(root->right);
        int v=root->val;
        int value;
        if(v==2){
            value=l||r;
        }else{
            value=l&&r;
        }
        return value;
    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};