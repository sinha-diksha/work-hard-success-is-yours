class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int mid=0;
        mid=n/2;
        if(nums[mid]==k){
            return 0;
        }
        int answer=INT_MAX;
        
        long long sum=0;
      
        sum+=(abs(nums[mid]-k));
        for(int i=mid-1; i>=0 && nums[i]>k; i--){
        
            sum+=(abs(nums[i]-k));
        }
     
        
        for(int i=mid+1; i<n && nums[i]<k; i++){
            sum+=(abs(nums[i]-k));
        }
        
    
        

        return sum;
    }
};