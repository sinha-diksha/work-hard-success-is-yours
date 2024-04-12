class Solution {
    
public:

//  void countAlternatingSubarrays(vector<int>& nums, int i, vector<long long>& v) {
//         if(i==nums.size()-1){
//             v[i]=1;
//             return;
//         }
//         countAlternatingSubarrays(nums, i+1,v);
//         if(nums[i]==nums[i+1]){
//             v[i]=1;
          
//         }
//         else{
//             v[i]=v[i+1]+1;
//         } 
//     }
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<long long> v(n);
        // countAlternatingSubarrays(nums,0,v);
        v[n-1]=1;

        long long ans=1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]==nums[i+1]){
                v[i]=1;
          
            }
            else{
                v[i]=v[i+1]+1;
            } 
            ans+=v[i];
        }
        return ans;
    }
};