class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                mp[nums[i]]=1;
            }
        }
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>=0; i--){
            if(nums[i]<0){
                return -1;
            }
            else{
                if(mp.count(-1*nums[i])){
                    return nums[i];
                    break;
                }
            }
        }
        return -1;
    }
};