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
    TreeNode* bstToGst(TreeNode* root) {
        vector<pair<int,TreeNode*>> storeNodes;
        queue<pair<int,TreeNode*>> q;
        q.push({root->val, root});
        while(!q.empty()){
            auto node1=q.front();
            TreeNode* node=node1.second;
            q.pop();
            int a=node->val;
            storeNodes.push_back({a,node});
            if(node->left!=NULL){
                q.push({node->left->val,node->left});
            }
            if(node->right!=NULL){
                q.push({node->right->val,node->right});
            }
        }
        sort(storeNodes.begin(), storeNodes.end());
        int n=storeNodes.size();
        int sum=0;
        for(int i=n-1; i>=0; i--){
            sum+=storeNodes[i].first;
            storeNodes[i].second->val=sum;
        }
        return root;
    }
};