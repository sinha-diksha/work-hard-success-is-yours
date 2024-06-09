class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int count=0;
    int n=v.size();
    int sum=0;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        sum+=v[i];
        int rem=(sum%k +k)%k;
        if(mp.count(rem)>0){
            mp[rem]++;
        }else{
            mp[rem]=1;
        }
    }
    unordered_map<int,int>:: iterator it=mp.begin();
    while(it!=mp.end()){
        int r=it->second;
        if(it->first==0){
            
            int l=(r*(r+1))/2;
            count+=l;
        }else{
            int x=(r*(r-1))/2;
            count+=x;
        }
        it++;
    }
    return count;
    }
};