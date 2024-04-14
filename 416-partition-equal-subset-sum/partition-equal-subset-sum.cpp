class Solution {
public:
    int dp[200][10001];
    bool solve(int idx, int target, vector<int>& nums){
        if(target==0){
            return true;
        }
        if(idx==0){
            return nums[idx]==target;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }

        bool notTake=solve(idx-1, target, nums);
        bool take=false;
        if(target>=nums[idx]){
            take=solve(idx-1, target-nums[idx], nums);
        }

        return dp[idx][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        return solve(n-1, sum/2, nums);
    }
};