#define m 1000000007
class Solution {
public:
    long long pow(long long n, long long x){
        if(x==0){
            return 1;
        }
        long long ans=1;
        long long smallAns=(pow(n,x/2))%m;
        if(x%2){
            ans=(ans*n)%m;
        }
        ans=(ans%m * smallAns%m)%m;
        ans=(smallAns%m * ans%m)%m;
        return ans;
    }
    int countGoodNumbers(long long n) {
        if(n%2==0){
            long long ans1=pow(4,n/2)%m;
            long long ans2=pow(5,n/2)%m;
            long long answer=((ans1%m) * (ans2%m))%m;
            return answer;
        }
        long long ans1=pow(4,n/2)%m;
        long long ans2=(pow(5,n/2)%m *5)%m;
        long long answer=((ans1%m) * (ans2%m))%m;
        return answer;

    }
};