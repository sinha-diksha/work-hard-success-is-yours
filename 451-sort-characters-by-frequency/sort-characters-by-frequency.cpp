class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int> mp;
       for(int i=0; i<s.length(); i++){
           mp[s[i]]++;
       }
       map<int, vector<char>, greater<int> >nMap;
       auto it=mp.begin();
       while(it!=mp.end()){
           nMap[it->second].push_back(it->first);
           it++;
       }
       string ans="";
       auto it2=nMap.begin();
       while(it2!=nMap.end()){
           int k=it2->second.size();
           for(int i=0; i<k; i++){
               for(int j=0; j<it2->first; j++){
                   ans+=it2->second[i];
               }
           }
           it2++;
       }

       return ans;
    }
};
