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
    string result="";
    void solve(TreeNode* root, string curString){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            char a1=((root->val)+'a');
            curString=a1+curString;
            if(result==""){
                result=curString;
            }else if(result>curString){
                result=curString;
            }
            return;
        }
        char a1=((root->val)+'a');
        solve(root->left, a1+curString);
        solve(root->right, a1+curString);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        return result;
    }
};