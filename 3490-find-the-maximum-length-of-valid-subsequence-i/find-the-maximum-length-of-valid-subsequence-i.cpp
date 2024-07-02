class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        //every odd
        int l=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                l++;
            }
        }
        maxi=max(maxi,l);
        l=0;
        //every even
        l=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                l++;
            }
        }
        maxi=max(maxi,l);
        l=0;
        //even odd
        int j=0;
        for(int i=0; i<n; i++){
            if(j==0 && nums[i]%2==0){
                l++;
                j^=1;
            }else if(j==1 && nums[i]%2!=0){
                l++;
                j^=1;
            }
        }

        maxi=max(maxi,l);
        l=0;
        //even odd
        j=0;
        for(int i=0; i<n; i++){
            if(j==0 && nums[i]%2!=0){
                l++;
                j^=1;
            }else if(j==1 && nums[i]%2==0){
                l++;
                j^=1;
            }
        }
        maxi=max(maxi,l);
        return maxi;
    }
};