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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int ans=root->val;
        while(!q.empty()){
            int n=q.size();
    
            bool isTaken=false;
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                if(isTaken==false){

                    ans=node->val;
                    isTaken=true;
                    
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                
            }
        }

        return ans;
    }
};