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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> > ans;
        map<int, map<int, multiset<int> > > mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int v=a.second.first;
            int l=a.second.second;
            TreeNode* node=a.first;
            mp[v][l].insert(node->val);
            if(node->left!=NULL){
                q.push({node->left, {v-1, l+1}});
            }
            if(node->right!=NULL){
                q.push({node->right, {v+1, l+1}});
            }

        }

        for(auto p:mp){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};