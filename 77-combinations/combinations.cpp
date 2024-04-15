class Solution {
public:
    vector<vector<int> > result;
    void solve(int idx, int k,  vector<int>& temp, int n){
        if(k==0){
            result.push_back(temp);
            return;
        }
        if(idx>n){
            return;
        }
        temp.push_back(idx);
        solve(idx+1, k-1, temp,n);
        temp.pop_back();
        solve(idx+1, k, temp,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,k,temp,n);
        return result;
    }
};