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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
       if(root->left==NULL && root->right==NULL){
           return {root->val};
        } 

        vector<int> leftSide=rightSideView(root->left);
        vector<int> rightSide=rightSideView(root->right);
        vector<int> ans;
        if(leftSide.size()<rightSide.size()){
            ans.push_back(root->val);
            for(int i=0; i<rightSide.size(); i++){
                ans.push_back(rightSide[i]);
            }
        }else{
            ans.push_back(root->val);
            int i;
            for(i=0; i<rightSide.size(); i++){
                ans.push_back(rightSide[i]);
            }
            for(; i<leftSide.size(); i++){
                ans.push_back(leftSide[i]);
            }
        }

        return ans;

    }
};