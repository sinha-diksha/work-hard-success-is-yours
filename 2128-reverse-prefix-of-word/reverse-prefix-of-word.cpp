class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        bool found=false;
        for(; i<word.length() && found==false; i++){
            if(word[i]==ch){
                found=true;
                break;
            }
        }
        if(found==false){
            return word;
        }
        reverse(word.begin(), word.begin()+i+1);
        return word;
    }
};