class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int cnt=1;
        int maxi=INT_MAX;
        while(cnt<=maxi){
            if(mp.count(cnt)==0){
                return cnt;
            }
            cnt++;
        }

        return -1;
    }
};