class Solution {
    int f(int idx, int buy, int n, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[idx] + f(idx+1, 0, n, prices, fee, dp) , f(idx+1, buy, n, prices, fee, dp));
        }else{
            profit=max(+prices[idx] + f(idx+1, 1, n, prices, fee, dp)- fee , f(idx+1, 0, n, prices, fee, dp));
        }
        return dp[idx][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0,1,n,prices, fee, dp);
    }
};