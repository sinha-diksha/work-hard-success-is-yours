class Solution {
public:
    bool check(int mid, vector<int>& position, int m){
    int total=1;
    int last=0;
    int n=position.size();
    for(int i=1; i<n; i++){
        if(position[i]-position[last]>=mid){
            total++;
            last=i;
        }
    }
    return total>=m;
}


int maxDistance(vector<int>& position, int m) {
    sort(position.begin(),position.end());
    int l=0;
    int r=1e9+5;
    int ans=1e9+5;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid,position,m)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
    // int maxDistance(vector<int>& position, int m) {
        
    // }
};