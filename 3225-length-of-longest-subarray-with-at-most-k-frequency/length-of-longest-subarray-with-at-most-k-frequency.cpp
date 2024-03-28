class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int s=0;
        int e=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        while(e<n){
            mp[nums[e]]++;
            while(mp[nums[e]]>k){
                mp[nums[s]]--;
                if(mp[nums[s]]==0){
                    mp.erase(nums[s]);
                }
                s++;
            }
            ans=max(ans, e-s+1);
            e++;

        }

        return ans;
    }
};