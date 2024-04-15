class Solution {
public:
    void sieveOfErathosthenes(vector<bool>& v){
        int n=v.size();
        v[0]=false;
        v[1]=false;
        for(int i=2; i<n; i++){
            if(v[i]==true){
           
                    for(int j=i*i; j<n; j+=i){
                        v[j]=false;
                    }

            }
        }
    }

    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> findPrime(101, true);
        sieveOfErathosthenes(findPrime);
        // for(int i=0; i<101; i++){
        //     cout<<findPrime[i]<<" ";
        // }
        // cout<<endl;
        vector<int> v1;
        int ans=0;
        
        for(int i=0; i<nums.size(); i++){
            if(findPrime[nums[i]]){
                v1.push_back(i);
            }
        }
        int z=v1.size();
        // cout<<v1[0]<<" "<<v1[z-1]<<endl;
        ans=max(ans, v1[v1.size()-1]-v1[0]);
        return ans;
    }
};