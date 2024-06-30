class Solution {
    void zAlgorithm(vector<int>& z, string& t, int n){
        int l=0;
        int r=0;
        z[0]=0;
        int m=t.length();
        for(int i=1; i<m; i++){
            if(i>r){
                l=i;
                r=i;
                while(r<m && t[r-l]==t[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }else{
                int k=i-l;
                if(z[k]+i<=r){
                    z[i]=z[k];
                }else{
                    l=i;

                    while(r<m && t[r-l]==t[r]){
                        r++;
                    }
                    z[i]=r-l;
                    r--;

                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        string t=needle+"$"+haystack;
        int k=t.length();
        int n=needle.length();
        vector<int> z(k);
        cout<<"jfas"<<endl;
        zAlgorithm(z,t,n);
        for(int i=0; i<t.length(); i++){
            cout<<z[i]<<" ";
        }
        cout<<endl;
        for(int i=n+1; i<k; i++){
            if(z[i]==n){
                return i-n-1;
            }
        }

        return -1;
    
    }
};