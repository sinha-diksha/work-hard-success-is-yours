class Solution {
public:
    string customSortString(string order, string s) {
       string ans="";
       string left="";
       unordered_map<char,int> mp;
       for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
       for(int i=0; i<order.size(); i++){
        if(mp.count(order[i])>0){
          
            for(int j=0; j<mp[order[i]]; j++){
                ans+=order[i];
               
                
            }
          
         
            mp.erase(order[i]);
            
        }
       }
       for(auto& it:mp){
        for(int i=0; i<it.second ; i++){
            ans+=it.first;
        }
       }

       return ans;
    }
};