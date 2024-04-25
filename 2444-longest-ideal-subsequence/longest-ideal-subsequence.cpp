class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans=1;
        int n=s.length();
        vector<int> hehe(n,1);
        vector<int> f(26, -1);
        f[s[0]-'a']=0;
        hehe[0]=1;
        for(int i=1; i<n; i++){
            cout<<i<<endl;
            int maxi=-1;
            int val=s[i]-'a';
            for(int j=0; j<26; j++){
               

                if(f[j]!=-1 && abs(val-j)<=k){
        
                    maxi=max(maxi, hehe[f[j]]);
                }
            }
            hehe[i]=max(hehe[i], maxi+1);
            ans=max(ans, hehe[i]);

            f[s[i]-'a']=i;

        }

        return ans;

    }
};