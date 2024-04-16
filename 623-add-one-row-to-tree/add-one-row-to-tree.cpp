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
    TreeNode* solve(TreeNode* root, int val, int cur, int depth){
        if(root==NULL){
            return NULL;
        }
        if(depth==1){
            TreeNode* newNode= new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        
        if(cur==depth-1){
            TreeNode* leftChild=root->left;

            TreeNode* rightChild=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=leftChild;
            root->right->right=rightChild;
        }else{
            solve(root->left, val, cur+1, depth);
            solve(root->right, val, cur+1, depth);
        }

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root, val, 1, depth);
    }
};