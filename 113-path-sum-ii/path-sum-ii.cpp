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
    vector<vector<int> > result;
    void pathSumHelp(TreeNode* root, int targetSum, vector<int> temp, int sum){
        if(root==NULL){
            return;
        }
        
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum)
                result.push_back(temp);
            return;
        }
        pathSumHelp(root->left, targetSum, temp, sum);
        pathSumHelp(root->right, targetSum, temp, sum);
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        pathSumHelp(root,targetSum,temp,0);
        return result;
    }
};