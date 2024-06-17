class Solution {
public:
    bool judgeSquareSum(int c) {
        long long r=sqrt(c)+1;
        long long i=0;
        long long j=r;
        while(i<=j){
            long long m=(i*i)+(j*j);
            if(m==c){
                return true;
            }else if(m>c){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};