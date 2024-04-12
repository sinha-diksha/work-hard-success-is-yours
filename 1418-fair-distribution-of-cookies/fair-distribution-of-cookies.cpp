class Solution {
public:
    int result=INT_MAX;
    void solve(int ind, vector<int>& cookies, int k,vector<int>& children){
        if(ind>=cookies.size()){
            int maxi=*max_element(children.begin(), children.end());
            result=min(result,maxi);
            return;
        }
        int cookie=cookies[ind];
        for(int i=0; i<k; i++){
            children[i]+=cookie;
            solve(ind+1, cookies, k, children);
            children[i]-=cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k);
        solve(0,cookies,k,children);
        return result;
    }
};