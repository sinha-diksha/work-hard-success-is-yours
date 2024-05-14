class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> dp(n,0);
       
        dp[n-1]=energy[n-1];
         int maxi=dp[n-1];
        for(int i=n-2; i>=0; i--){
            if(i+k<n){
                dp[i]=energy[i]+dp[i+k];
            }else{
                dp[i]=energy[i];
            }
            maxi=max(maxi, dp[i]);
        }

        return maxi;
    }
};