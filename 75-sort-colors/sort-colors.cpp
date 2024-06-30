class Solution {
public:
    void sortColors(vector<int>& nums) {
    vector<int> f(3);
    for(int i=0; i<nums.size(); i++){
        f[nums[i]]++;
    }
    int l=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<f[i]; j++){
            nums[l]=i;
            l++;
        }
    }
    
    }
};