class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOne=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                countOne++;
            }
        }
        
        for(int i=0; i<s.length(); i++){
            s[i]='0';
        }
        for(int i=0; i<countOne-1; i++){
            s[i]='1';
        }
        s[s.length()-1]='1';
        return s;
    }
};