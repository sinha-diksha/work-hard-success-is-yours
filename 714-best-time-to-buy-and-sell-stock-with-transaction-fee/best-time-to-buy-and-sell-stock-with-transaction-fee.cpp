class Solution {
    // int f(int idx, int buy, int n, vector<int>& prices, int fee, vector<vector<int>>& dp){
    //     if(idx>=n){
    //         return 0;
    //     }
    //     if(dp[idx][buy]!=-1){
    //         return dp[idx][buy];
    //     }
        
    // }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[idx] + dp[idx+1][0] , dp[idx+1][buy]);
                }else{
                    profit=max(+prices[idx] + dp[idx+1][1]- fee , dp[idx+1][0]);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};