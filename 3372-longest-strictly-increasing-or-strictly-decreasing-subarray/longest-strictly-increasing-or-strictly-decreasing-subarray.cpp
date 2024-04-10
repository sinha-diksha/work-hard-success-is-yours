class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1=1;
        int ans2=1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int a=nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j]>a){
                    a=nums[j];
                    ans1=max(ans1, j-i+1);
                }else{
                    
                    break;
                }
            }
        }

        for(int i=0; i<n; i++){
            int a=nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j]<a){
                    a=nums[j];
                    ans2=max(ans2, j-i+1);
                }else{
            
                    break;
                }
            }
        }
    
        return max(ans1, ans2);


    }
};