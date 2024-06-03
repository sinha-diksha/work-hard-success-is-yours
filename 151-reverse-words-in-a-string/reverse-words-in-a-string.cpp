class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int s1=0;
        int e=0;
        while(e<s.length()){
            if(s[s1]==' '){
                s1++;
                e++;
                
                continue;
            }
            e++;
            if(s[e]==' '){
                if(ans==""){
                    ans=s.substr(s1,e-s1);
                }else{
                    ans=s.substr(s1, e-s1)+" "+ans;
                }
                
                
                s1=e; 

            }
            if(e==s.length()){
                    if(ans==""){
                    ans=s.substr(s1,e-s1);
                    }else{
                        ans=s.substr(s1, e-s1)+" "+ans;
                    }
                
            }
            
        }

        return ans;
    }
};