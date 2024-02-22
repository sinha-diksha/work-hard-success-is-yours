class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        string ans="";
        for(int i=31; i>=0; i--){
            int l=(left&(1<<i));
            int r=(right&(1<<i));
            if(l==r){
           
                if(l==0){
                    ans+='0';
                }else{
                    ans+='1';
                }
            }
            else{
                break;
            }
        }
        int n=ans.length();
     
        if(n==0){
            return 0;
        }
        for(int i=0; i<32-n; i++){
            ans+='0';
        }

        int answer=0;
        for(int i=31; i>=0; i--){
            answer+=((ans[i]-'0')*(1<<(31-i)));
        }
        return answer;
    }
};