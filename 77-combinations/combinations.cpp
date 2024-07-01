class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, int idx, vector<int>& v){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        if(idx>n){
            return;
        }
        v.push_back(idx);
        solve(n, k, idx+1, v);
        v.pop_back();
        solve(n,k,idx+1, v);
    }
    
    vector<vector<int>> combine(int n, int k) {
      int idx=1;
      vector<int> v;
      solve(n,k,idx,v);
      return ans;
    }
};