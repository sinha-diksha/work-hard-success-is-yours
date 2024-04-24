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
        vector<int> dp(39);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3; i<=n; i++){
            int a=dp[i-1];
            int b=dp[i-2];
            int c=dp[i-3];
            dp[i]=a+b+c;
        }
       return dp[n];
    }
};