class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long sum=nums[0]+nums[1];
        long long largestSide;
        long long ans=-1;
        for(int i=2; i<n; i++){
            largestSide=nums[i];
            if(sum>largestSide){
                ans=sum+largestSide;
                
            }
            sum+=largestSide;
        }

        return ans;
    }
};