class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> zero(32);
        vector<int> one(32);
        for(int i=0; i<32; i++){
            for(int j=0; j<nums.size(); j++){
                if((nums[j]&(1<<i))!=0){
                    one[i]++;;
                }else{
                    zero[i]++;
                }
            }
        }
        cout<<"ashfkjas"<<endl;
        int ans=0;
        for(int i=0; i<32; i++){
            if(one[i]%3!=0){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};