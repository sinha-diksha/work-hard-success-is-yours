class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        int a=n&(n-1);
        if(a==0){
            return true;
        }
        return false;
    }
};