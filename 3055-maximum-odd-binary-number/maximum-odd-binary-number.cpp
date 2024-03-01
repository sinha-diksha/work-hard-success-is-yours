class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOne=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                countOne++;
            }
        }
        string ans=s;
        for(int i=0; i<s.length(); i++){
            ans[i]='0';
        }
        for(int i=0; i<countOne-1; i++){
            ans[i]='1';
        }
        ans[s.length()-1]='1';
        return ans;
    }
};