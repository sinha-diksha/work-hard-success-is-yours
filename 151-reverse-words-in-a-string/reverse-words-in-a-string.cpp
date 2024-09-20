class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        while(i<n){
            if(s[i]==' '){
                i++;
            }else{
                break;
            }
        }
        
        int start=i;
        int end=i;
        string ans="";
        while(end<n){
            
            if(s[end]==' '){
                if(start!=end){
                    if(ans==""){
                        ans=s.substr(start,end-start);
                    }else{
                        ans=s.substr(start,end-start)+" "+ans;
                    }
                }
                end++;
                start=end;
            }
            else{
                end++;
            }
            if(end==n and s[end-1]!=' '){
                if(ans==""){
                        ans=s.substr(start,end-start);
                    }else{
                        ans=s.substr(start,end-start)+" "+ans;
                    }
            }
            
        }
        return ans;
    }
};