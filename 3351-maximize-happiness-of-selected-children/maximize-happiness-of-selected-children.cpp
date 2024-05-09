class Solution {
    typedef long long ll;
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll ans=0;
        ll count=0;
        sort(happiness.begin(), happiness.end(),greater<int>());
        for(int i=0; i<happiness.size() && k; i++){
            if(happiness[i]-count<=0){
                break;
            }
            ans+=(happiness[i]-count);
            count++;
            k--;
        }

        return ans;
    }
};