class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLen=0;
        unordered_map<int,int> mp;
        for(int i=0; i<arr1.size(); i++){
            while(arr1[i]>0){
                mp[arr1[i]]=1;
                arr1[i]=arr1[i]/10;
            }
        }

        for(int i=0; i<arr2.size(); i++){
            while(arr2[i]>0){
                if(mp.count(arr2[i])>0){
                    maxLen=max(maxLen,arr2[i]);
                }
                arr2[i]=arr2[i]/10;
            }
        }

        int ans=0;
        while(maxLen>0){
            ans++;
            maxLen=maxLen/10;
        }

        return ans;

    }
};