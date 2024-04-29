class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans^=nums[i];
        }
        int a1=ans^k;
        int answer=0;
        while(a1>0){
            if((a1&1)==1){
                answer++;
            }
            a1=a1>>1;
        }

        return answer;
    }
};