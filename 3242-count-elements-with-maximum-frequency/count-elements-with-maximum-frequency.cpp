class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        map<int,int,greater<int>> mp1;
        for(auto& it:mp){
            mp1[it.second]++;
        }
        return mp1.begin()->first*mp1.begin()->second;
    }
};