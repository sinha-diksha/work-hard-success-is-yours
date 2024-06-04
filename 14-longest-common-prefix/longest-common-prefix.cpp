class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word=strs[0];
        for(int i=1; i<strs.size(); i++){
            if(strs[i].length()<word.length()){
                word=strs[i];
            }
        }
        for(int i=0; i<word.size(); i++){
       
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i]!=word[i]){
                  
                    return word.substr(0,i);
                
                }
            }
            
        }
        return word;
    }
};