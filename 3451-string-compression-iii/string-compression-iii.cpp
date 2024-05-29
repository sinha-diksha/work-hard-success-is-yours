class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int curLen=1;
        for(int i=1; i<word.length(); ){
            if(word[i]==word[i-1] && curLen<9){
                i++;
                curLen++;
            }
            else if(word[i]!=word[i-1] || curLen==9){
                ans+=to_string(curLen);
                ans+=word[i-1];
                curLen=1;
                i++;
            }
        }
        ans+=to_string(curLen);
        ans+=word[word.length()-1];
        return ans;
    }
};