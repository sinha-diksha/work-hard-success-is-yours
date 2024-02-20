/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<TreeNode*> findPath(TreeNode* root, int value){
        
        if(root==NULL){
            return {};
        }
    
        if(root->val==value){
            return {root};
        }
        

        vector<TreeNode*> leftSide=findPath(root->left, value);
        if(leftSide.size()!=0){
            leftSide.push_back(root);
            return leftSide;
        }
        vector<TreeNode*> rightSide=findPath(root->right,value);
        if(rightSide.size()!=0){
            rightSide.push_back(root);
            return rightSide;
        }
        return {};
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v=findPath(root,p->val);
        vector<TreeNode*> v1=findPath(root,q->val);
        int i=v.size()-1;
        int j=v1.size()-1;
        
        TreeNode* ans;
      
        while(i>=0 && j>=0){
            if(v[i]==v1[j]){
                ans=v[i];
            
                i--;
                j--;
            }else{
                break;
            }
        }
        
        return ans;
    }
};