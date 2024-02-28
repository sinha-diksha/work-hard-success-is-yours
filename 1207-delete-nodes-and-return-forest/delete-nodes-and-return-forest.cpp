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
    TreeNode* deleteTreeNode(TreeNode* root, unordered_set<int>& s, vector<TreeNode*>& result){
        if(root==NULL){
            return NULL;
        }
        root->left=deleteTreeNode(root->left,s,result);
        root->right=deleteTreeNode(root->right, s,result);
        if(s.find(root->val)!=s.end()){
            if(root->left!=NULL){
                result.push_back(root->left);
            }
            if(root->right!=NULL){
                result.push_back(root->right);
            }
            return NULL;
        }else{
            return root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> s;
        for(auto& num:to_delete){
            s.insert(num);
        }
        deleteTreeNode(root,s,result);
        if(s.find(root->val)==s.end()){
            result.push_back(root);
        }

        return result;

    }
};