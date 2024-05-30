class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> divArray;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%k==0){
                divArray.push_back(nums1[i]/k);
            }
        }
        unordered_map<int,int> mp;
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]]++;
        }
        long long ans=0;
        for(int i=0; i<divArray.size(); i++){
            for(int j=1; j<=sqrt(divArray[i]); j++){
                if((divArray[i]%j)==0){
                    int a=j;
                    int b=divArray[i]/a;
                    if(a==b){
                        ans+=mp[a];
                    }else{
                        ans+=mp[a];
                        ans+=mp[b];
                    }
                }
            }
        }

        return ans;
    }
};