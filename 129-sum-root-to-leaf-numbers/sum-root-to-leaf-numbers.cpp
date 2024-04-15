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
    int ans=0;
    void solve(TreeNode* root, int sum){
        if(root->left==NULL && root->right==NULL){
            sum=((sum*10)+root->val);
            ans+=sum;
            return;
        }
        if(root->left!=NULL)
            solve(root->left, sum*10+root->val);
        if(root->right!=NULL)
            solve(root->right, sum*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};