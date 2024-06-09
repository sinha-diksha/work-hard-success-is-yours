class Solution {
public:
    string largestOddNumber(string s) {
        int j=s.length()-1;
        while(j>=0){
            if((s[j]-'0')%2!=0){
                return s.substr(0, j+1);
            }
            j--;
        }
        return "";
    }
};