class Solution {
public:
    string longestPalindrome(string str) {
        int s=0;
        int e=0;
        int ans=0;
        int n=str.length();
        vector<vector<bool>> v(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            v[i][i]=true;
            ans=1;
            s=i; e=i;
        }
        for(int i=0; i<n-1; i++){
            if(str[i]==str[i+1]){
                v[i][i+1]=true;
        
                    ans=2;
                    s=i;
                    e=i+1;
                
            }
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i+2; j<n; j++){
                v[i][j]=str[i]==str[j] && v[i+1][j-1];
                if(v[i][j]){
                    if(ans<j-i+1){
                        ans=j-i+1;
                        s=i;
                        e=j;
                    }
                }
            }
        }
        return str.substr(s,ans);
    }
};