class Solution {
public:
    string largestOddNumber(string s) {
        while(!s.empty()){
            if((s.back()-'0')%2!=0){
                return s;
            }
            s.pop_back();
        }
        return "";
    }
};