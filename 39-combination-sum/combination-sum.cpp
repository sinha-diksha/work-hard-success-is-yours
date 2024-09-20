class Solution {
    vector<vector<int>> ans;
    void help(vector<int>& candidates, int target, int i, vector<int>& v){
        if(target==0){
            if(v.size()!=0)
                ans.push_back(v);
            return;
        }
        if(i<0){
            return;
        }
        // take
        help(candidates, target, i-1, v);
        if(candidates[i]<=target){
            v.push_back(candidates[i]);
            help(candidates, target-candidates[i], i, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        int n=candidates.size();
        help(candidates, target, n-1, v);
        return ans;
    }
};