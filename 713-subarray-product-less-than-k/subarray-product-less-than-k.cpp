class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int ans=0;
        int s=0;
        int e=0;
        long long pro=1;
        int n=nums.size();
        while(e<n){
            pro*=nums[e];
           
          
                while(pro>=k && s<=e){
                    pro/=nums[s];
                    s++;
                } 
            if(s>e){
                ans+=0;
            }
            else{
            ans+=(e-s+1);
            }
            e++;
        }

        return ans;
    }
};