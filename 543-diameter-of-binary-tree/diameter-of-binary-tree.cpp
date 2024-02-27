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
    pair<int,int> f(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            return {1,0};
        }

        pair<int,int> a1=f(root->left);

        pair<int,int> b1=f(root->right);
        int a=a1.second;
        int b=b1.second;
        int l=a1.first;
        int r=b1.first;
        return {1+max(l,r),max(a,max(b,l+r))};
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> m=f(root);
        return m.second;
    }
};