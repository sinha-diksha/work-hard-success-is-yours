class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mp;
        int maxi=0;
        int n=word.length();
        for(int i=0; i<n; ){
            string ans=word.substr(i, k);
            i+=k;
            mp[ans]++;
            maxi=max(maxi, mp[ans]);
        }
        
        n-=(k*maxi);
        return n/k;
    }
};