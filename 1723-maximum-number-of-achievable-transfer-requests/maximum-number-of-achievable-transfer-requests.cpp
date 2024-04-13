class Solution {
public:
    int result=INT_MIN;
    int m;
    void solve(int idx, int n,vector<vector<int>>&  requests, vector<int>& resultant, int count){
        if(idx>=m){
            bool isZero=true;
            for(int i=0; i<n; i++){
                if(resultant[i]!=0){
                    isZero=false;
                    break;
                }
            }
            if(isZero){
                result=max(result,count);
            }
            return;
        }

        int from=requests[idx][0];
        int to=requests[idx][1];
        resultant[from]--;
        resultant[to]++;
        solve(idx+1, n, requests, resultant, count+1);
        resultant[from]++;
        resultant[to]--;
        solve(idx+1,n,requests,resultant,count);

    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> resultant(n,0);
        int count=0;
        m=requests.size();
        solve(0,n,requests, resultant, 0);
        return result;
    }
};