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
        int i=0;
        int j=0;
        vector<int> kmp;
        while(i<n){
            if(s[i]==p[j]){
                i++;
                j++;
            }
            if(j==m){
                kmp.push_back(i-j);
                j=lps[j-1];
            }else if(s[i]!=p[j]){
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
        int n=s.length();
        vector<int> i_indexes=KMP(a,s);
        vector<int> j_indexes=KMP(b,s);
        vector<int> lb;
        vector<int> ub;
        for(auto& i:i_indexes){
            int a=max(0, i-k);
            int b=min(n-1, i+k);
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