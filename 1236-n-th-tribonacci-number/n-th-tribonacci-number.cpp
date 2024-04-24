class Solution {
public:
    
    int tribonacciHelp(int n, vector<int>& dp) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a=tribonacciHelp(n-1,dp);
        int b=tribonacciHelp(n-2,dp);
        int c=tribonacciHelp(n-3,dp);
        return dp[n]=a+b+c;
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
       return tribonacciHelp(n, dp);
    }
};