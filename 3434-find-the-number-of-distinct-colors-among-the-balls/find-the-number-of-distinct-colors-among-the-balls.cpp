class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        int n=queries.size();
        vector<int> ans(n,0);
        ans[0]=1;
        mp[queries[0][0]]=queries[0][1];
        unordered_map<int,int> colCount;
        colCount[queries[0][1]]++;
        set<int> s;
        s.insert(queries[0][1]);
        for(int i=1; i<n; i++){
            
            if(mp.count(queries[i][0])==0){
                colCount[queries[i][1]]++;
                mp[queries[i][0]]=queries[i][1];
                s.insert(queries[i][1]);
                ans[i]=(s.size());
            }else{
                if(mp[queries[i][0]]==queries[i][1]){
                    
                    ans[i]=(s.size());
                }else{
                    int a=mp[queries[i][0]];
                    colCount[a]--;
                    if(colCount[a]==0){
                        s.erase(a);
                    }
                    colCount[queries[i][1]]++;
                    s.insert(queries[i][1]);
                    mp[queries[i][0]]=queries[i][1];
                    ans[i]=(s.size());
                }
            }
           
        }

        return ans;
    }
};