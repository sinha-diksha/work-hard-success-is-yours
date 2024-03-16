class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0; i<32; i++){
            if((c&1)==1){
                if((a&1)==0 && (b&1)==0){
                    ans++;
                }
            }else{
                if((a&1)==1){
                    ans++;
                }
                if((b&1) == 1){
                    ans++;
                }
            }
            c>>=1;
            a>>=1;
            b>>=1;
        }

        return ans;
    }
};