class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            char c=s[j];
            s[j--]=s[i];
            s[i++]=c;
            
        }
    }
};