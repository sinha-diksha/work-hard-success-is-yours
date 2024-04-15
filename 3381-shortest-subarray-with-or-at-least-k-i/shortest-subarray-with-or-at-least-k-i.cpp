class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int myAns=INT_MAX;
        for(int i=0; i<n; i++){
            int ans=0;
            for(int j=i; j<n; j++){
                ans|=nums[j];
               
                if(ans>=k){
                    myAns=min(myAns,j-i+1);
                }
            }
        }

       if(myAns==INT_MAX){
        return -1;
       }
       return myAns;
    }
};