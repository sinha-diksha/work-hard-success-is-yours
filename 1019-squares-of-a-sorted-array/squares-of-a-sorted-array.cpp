class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums[0]>=0){
            vector<int> ans;
            for(int i=0; i<nums.size(); i++){
                ans.push_back(nums[i]*nums[i]);
            }
            return ans;
        }
        int i=0;
        vector<int> ans;
        int j=lower_bound(nums.begin(), nums.end(),0)-nums.begin();
        i=j-1;
        int k=j;
        while(i>=0 && j<nums.size()){
            if(abs(nums[i])<nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<nums.size()){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
    }
};