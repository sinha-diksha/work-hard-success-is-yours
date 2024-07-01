class Solution {
public:
    
    int count=0;

    void solve(vector<int>& nums, int& k, int idx, unordered_map<int,int>& mp, int& n){
        if(idx>=n){
            count++;
  
            return;
        }

        solve(nums, k, idx+1, mp, n);

     
        if( mp[nums[idx]-k]==0 && mp[nums[idx]+k]==0 ){
            mp[nums[idx]]++;
         
            solve(nums, k, idx+1, mp, n);
            mp[nums[idx]]--;
            
        }
       
        
        
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int idx=0;
        unordered_map<int,int> v;
        int n=nums.size();
        solve(nums, k, idx, v, n);
        return count-1;
    }
};