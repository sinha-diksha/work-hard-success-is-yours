class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        map<int, vector<char>, greater<int> > m;
        unordered_map<char,int>:: iterator it=mp.begin();
        while(it!=mp.end()){
            m[it->second].push_back(it->first);
            it++;
        }
        string k="";
         map<int, vector<char> >:: iterator it1=m.begin();
         while(it1!=m.end()){
            int x=it1->second.size();
            for(int i=0; i<x; i++){
                for(int j=0; j<it1->first; j++){
                    k+=it1->second[i];
                }
            }
            it1++;
         }
         return k;
    }
};
