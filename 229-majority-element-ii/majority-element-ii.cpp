class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1=NULL;
        int element2=NULL;
        int count1=0;
        int count2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==element1){
                count1++;
            }
            else if(nums[i]==element2){
                count2++;
            }else if(count1==0){
                element1=nums[i];
                count1=1;
            }
            else if(count2==0){
                element2=nums[i];
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }

        int n=nums.size();
        vector<int> ans;
        int c3=0;
        int c4=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==element1){
                c3++;
            }
            else if(nums[i]==element2){
                c4++;
            }
        }
        if(c3>n/3){
            ans.push_back(element1);
        }
        if(c4>n/3){
            ans.push_back(element2);
        }

        return ans;
    }
};