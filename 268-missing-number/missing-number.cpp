class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        for(int i=0; i<=n; i++){
            a^=i;
        }
        for(int i=0; i<nums.size(); i++){
            a^=nums[i];
        }
        return a;
    }
};