class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>> v(n, vector<int>(n,0));
        int sum=0;
        for(int i=0; i<n; i++){
            sum++;
            v[i][i]=1;
        }
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                v[i][i+1]=1;
                sum++;
            }
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i+2; j<n; j++){
                if(v[i+1][j-1]==1 && s[i]==s[j]){
                    v[i][j]=1;
                    sum++;
                }
            }
        }
        return sum;
    }
};