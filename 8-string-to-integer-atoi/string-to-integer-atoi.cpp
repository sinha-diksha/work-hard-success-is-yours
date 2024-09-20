class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        while(i<n){
            if(s[i]==' '){
                i++;
            }else{
                break;
            }
        }
        s=s.substr(i);
        int sign=1;
        if(s[0]=='-'){
            sign=-1;
        }
        i=(s[0]=='+' || s[0]=='-')?1:0;
        long long ans=0;
        while(i<n){
            if(s[i]==' ' || !isdigit(s[i])){
                break;
            }
            ans=(ans*10)+(s[i]-'0');
            if(sign==-1 && (-1*ans)<INT_MIN){
                return INT_MIN;
            }else if(sign==1 && ans>INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return (int) (sign*ans);
    }
};