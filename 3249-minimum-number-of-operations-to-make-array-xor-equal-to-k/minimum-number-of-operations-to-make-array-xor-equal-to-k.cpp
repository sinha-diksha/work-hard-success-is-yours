class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=k;
        for(int i=0; i<nums.size(); i++){
            ans^=nums[i];
        }

        int answer=0;
        while(ans>0){
            if((ans&1)==1){
                answer++;
            }
            ans=ans>>1;
        }

        return answer;
    }
};