class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, int> used;
        for(int i=0; i<s.length(); i++){
            if(mp.count(s[i])>0){
                
                if(mp[s[i]]!=t[i]){
                    return false;
                }
                
            }else{
                if(used[t[i]]==1){
                    return false;
                }
                mp[s[i]]=t[i];
                used[t[i]]=1;
            }
        }
        
        return true;

    }
};