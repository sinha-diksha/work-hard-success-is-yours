class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> lower;
        unordered_map<char,int> upper;
        for(int i=0; i<word.size(); i++){
            if(word[i]>='a' && word[i]<='z'){
                if(upper.count(word[i]-32)==0){
                    lower[int(word[i])]=i;
                }else{
                    lower.erase(int(word[i]));
                }
                
            }
            else{
                upper[int(word[i])]=i;
            }
        }
        int ans=0;
        for(auto i: lower){
            if(upper.count(i.first-32)>0){
                if(lower[i.first]<upper[i.first-32])
                    ans++;
            }
        }
        return ans;
    }
};