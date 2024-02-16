class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        map<int,int> nMap;
        auto it=mp.begin();
        while(it!=mp.end()){
            nMap[it->second]++;
            it++;
        }
        auto it1=nMap.begin();
        while(it1!=nMap.end() && k>0){
            int n=it1->second;
            for(int i=0; i<n && k>0; i++){
                if(k-it1->first>=0){
                    k-=it1->first;
                    it1->second--;
                }else{
                    k=0;
                    break;
                }
            }
            it1++;
        }
        int ans=0;
        it1=nMap.begin();
        while(it1!=nMap.end()){
            ans+=it1->second;
            it1++;
        }

        return ans;
    }
};