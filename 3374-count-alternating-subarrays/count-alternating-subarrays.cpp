class Solution {
    
public:

 void countAlternatingSubarrays(vector<int>& nums, int i, vector<long long>& v) {
        if(i==nums.size()-1){
            v[i]=1;
            return;
        }
        countAlternatingSubarrays(nums, i+1,v);
        if(nums[i]==nums[i+1]){
            v[i]=1;
          
        }
        else{
            v[i]=v[i+1]+1;
        } 
    }
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<long long> v(n);
        countAlternatingSubarrays(nums,0,v);
        long long ans=0;
        for(int i=0; i<n; i++){
            ans+=v[i];
        }
        return ans;
    }
};