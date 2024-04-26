class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int> > dp(n, vector<int>(n,0));
        for(int i=0; i<n; i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int mini=INT_MAX;
                for(int j1=0; j1<n; j1++){
                    if(j1==j){
                        continue;
                    }
                    mini=min(mini, dp[i-1][j1]);
                }
                dp[i][j]=mini+grid[i][j];
            }
        }

        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};