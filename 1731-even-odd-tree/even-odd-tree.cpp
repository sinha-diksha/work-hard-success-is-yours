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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            int lastVal=-1;
            // if(q.front()->left!=NULL){
            //             q.push(q.front()->left);
            // }
            // if(q.front()->right!=NULL){
            //             q.push(q.front()->right);
            // }
            // q.pop();
            
            if(level%2==0){
                while(n--){
                    
                    TreeNode* node=q.front();
                    q.pop();
                    if(node->val%2==0){
                        return false;
                    }
                    if(lastVal==-1){
                        lastVal=node->val;
                    }
                    else{
                        if(node->val<=lastVal){
                            return false;
                        }
                        lastVal=node->val;
                    }
                    if(node->left!=NULL){
                        q.push(node->left);
                    }
                    if(node->right!=NULL){
                        q.push(node->right);
                    }
                }
            }else{
                while(n--){
                    TreeNode* node=q.front();
                    q.pop();
                    if(node->val%2!=0){
                        return false;
                    }
                    if(lastVal==-1){
                        lastVal=node->val;
                    }
                    else{
                        if(node->val>=lastVal){
                            return false;
                        }
                        lastVal=node->val;
                    }
                    if(node->left!=NULL){
                        q.push(node->left);
                    }
                    if(node->right!=NULL){
                        q.push(node->right);
                    }
                }
            }
            level++;
        }

        return true;
    }
};