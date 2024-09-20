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
        bool isNeg=false;
        if(s[i]=='-'){
            isNeg=true;
            i++;
        }
        if(s[i]=='+' && isNeg){
            return 0;
        }else if(s[i]=='+'){
            i++;
        }
        long long ans=0;
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                ans=(ans*10)+(s[i]-'0');
                if(ans>INT_MAX){
                    if(isNeg){
                        return INT_MIN;
                    }return INT_MAX;
                }
            }else{
                break;
            }
            i++;
        }

        if(isNeg){
            return -ans;
        }
        return ans;
    }
};