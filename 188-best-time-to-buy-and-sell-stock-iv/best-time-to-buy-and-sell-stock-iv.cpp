class Solution {
    int f(int idx, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(cap<=0){
            return 0;
        }
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy][cap]!=-1){
            return dp[idx][buy][cap];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[idx] + f(idx+1, 0, cap, n, prices,dp), f(idx+1, buy, cap, n,prices,dp));
        }else{
            profit=max(prices[idx] + f(idx+1, 1, cap-1, n, prices,dp), f(idx+1, buy, cap, n, prices,dp) );
        }
        return dp[idx][buy][cap]=profit;
    }
public:

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, n, prices, dp);
    }
};