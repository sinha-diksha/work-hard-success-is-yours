class Solution {
public:
    int numSquares(int n, vector<int>& arr) {
        if(sqrt(n)==ceil(sqrt(n))){
            arr[n]=1;
            return 1;
        }

        if(arr[n]!=-1){
            return arr[n];
        }
        int r=INT_MAX;
        for(int i=1; i<=sqrt(n); i++){
            if(n-pow(i,2)>0){
                r=min(r, numSquares(n-pow(i,2), arr));
            }
        }

        return arr[n]=r+1;
    }
    int numSquares(int n) {
        vector<int> arr(n+1, -1);
        numSquares(n, arr);
        return arr[n];
    }
};