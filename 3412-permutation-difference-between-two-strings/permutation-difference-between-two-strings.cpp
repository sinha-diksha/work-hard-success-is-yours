class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans=0;
        for(int i=0; i<s.length(); i++){
            int r=find(t.begin(), t.end(), s[i])-t.begin();
            ans+=abs(r-i);
        }

        return ans;
    }

};