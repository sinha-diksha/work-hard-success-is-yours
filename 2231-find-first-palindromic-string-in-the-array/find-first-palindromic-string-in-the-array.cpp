class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0; i<n; i++){
            string s=words[i];
            reverse(s.begin(), s.end());
            if(words[i]==s){
                return words[i];
            }
        }
        return "";
    }
};