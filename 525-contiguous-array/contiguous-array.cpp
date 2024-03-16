class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int> mp;
       mp[0]=0;
       int sum=0;
       int ans=0;
       for(int i=0; i<nums.size(); i++){
            sum+=(nums[i]==1?1:-1);
            if(mp.find(sum)!=mp.end()){
                ans=max(ans, i+1-mp[sum]);
            }else{
                mp[sum]=i+1;
            }
       }
       return ans;
    }
};