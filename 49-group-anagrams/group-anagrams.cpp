class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string >> mp;
        for(int i=0; i<strs.size(); i++){
            string r=strs[i];
            sort(r.begin(), r.end());
            mp[r].push_back(strs[i]);
        }

        vector<vector<string> >ans;
        auto it=mp.begin();
        while(it!=mp.end()){
            ans.push_back(it->second);
            it++;
        }

        return ans;

    }
};