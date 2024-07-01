class Solution {
public:
    
    int ans=INT_MIN;
    void solve(int idx, int count, vector<vector<int>> & requests, vector<int>& resultant, int n, int m){
        if(idx>=m){
            for(int i=0; i<n; i++){
                if(resultant[i]!=0){
                    ans=max(ans, INT_MIN);
                    return;
                }
            }
            ans=max(ans, count);
            return;
            
        }

        int f=requests[idx][0];
        int t=requests[idx][1];
        resultant[f]--;
        resultant[t]++;
        solve(idx+1, count+1, requests, resultant, n, m);
        resultant[f]++;
        resultant[t]--;
        solve(idx+1, count, requests, resultant, n, m);
        
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
       vector<int> resultant(n);
       solve(0, 0, requests, resultant, n, requests.size());
       return ans;
    }
};