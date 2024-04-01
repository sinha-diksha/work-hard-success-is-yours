class Solution {
public:
    int lengthOfLastWord(string s1) {
        int s=0;
        int e=0;
        int ans=0;
        int n=s1.length();
        string lastWord="";
        while(e<n){
            if(s1[e]==' '){
                ans=e-s;
                if(ans>0){
                lastWord=s1.substr(s, ans);
                }
                e++;
                s=e;
            }else{
                e++;
                if(e==n){
                   ans=e-s;
                   if(ans>0){
                    lastWord=s1.substr(s, ans);
                    }  
                }
            }
        }
        return lastWord.length();
    }
};