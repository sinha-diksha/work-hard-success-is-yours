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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        if(root->left == NULL && (root->right->left==NULL && root->right->right==NULL)){
            return 0;
        }
        if(root->left!=NULL){
            q.push(root->left);
            if(root->left->left==NULL && root->left->right==NULL){
                ans+=root->left->val;
            }
        }
        cout<<ans<<endl;
        if(root->right!=NULL){
            q.push(root->right);
        }
        while(!q.empty()){
            int n=q.size();
            bool taken=false;
            for(int i=0; i<n; i++){
                auto f=q.front();
                q.pop();
                
                if(f->left!=NULL){
                    q.push(f->left);
                    if(f->left->left==NULL && f->left->right==NULL){
                        ans+=f->left->val;
                    }
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
                
            }
            cout<<ans<<endl;
        }

        return ans;
    }
};