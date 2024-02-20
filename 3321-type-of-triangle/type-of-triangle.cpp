class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[2]>=nums[0]+nums[1]){
            return "none";
        }
        unordered_map<int,bool> mp;
        
        for(int i=0; i<3; i++){
            mp[nums[i]]=true;
        }
        int a=mp.size();
        if(a==1){
            return "equilateral";
        }
        if(a==2){
            return "isosceles";
        }
        return "scalene";
    }
};