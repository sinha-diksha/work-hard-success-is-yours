class Solution {
    vector<int> LPS(string p, int m){
        vector<int> lps(m,0);
        int pre=0;
        int suf=1;
        while(suf<m){
            if(p[pre]==p[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps;
    }
    vector<int> KMP(string p, string s){
        int n=s.length();
        int m=p.length();
        vector<int> lps=LPS(p,m);
        for(int i=0; i<lps.size(); i++){
            cout<<lps[i]<<" ";
        }
        cout<<endl;
        vector<int> kmp;
        int i=0;
        int j=0;
        while(i<n){
            if(p[j]==s[i]){
                i++;
                j++;
            }
            if(j==m){
                kmp.push_back(i-j);
                j=lps[j-1];
            }else if(p[j]!=s[i]){
                if(j==0){
                    i++;
                }else{
                    j=lps[j-1];
                }
            }
        }
        return kmp;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> i_indexes=KMP(a,s);
        vector<int> j_indexes=KMP(b,s);
        for(int i=0; i<i_indexes.size(); i++){
            cout<<i_indexes[i]<<" ";
        }
        cout<<endl;
        cout<<j_indexes.size()<<endl;
        vector<int> lb;
        vector<int> ub;
        for(int i=0; i<i_indexes.size(); i++){
            int a=max(0, i_indexes[i]-k);
            int b=min((int)s.length()-1, i_indexes[i]+k);
            lb.push_back(a);
            ub.push_back(b);
        }
        vector<int> ans;
        for(int i=0; i<i_indexes.size(); i++){
            auto it=lower_bound(j_indexes.begin(), j_indexes.end(), lb[i]);
           
            if(it!=j_indexes.end() && *it<=ub[i]){
                ans.push_back(i_indexes[i]);
            }
        }
        return ans;
    }
};