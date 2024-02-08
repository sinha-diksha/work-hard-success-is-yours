class Solution {
public:
    int numSquares(int n) {
        vector<int> arr(n+1, -1);

        arr[0]=0;
        arr[1]=1;
        cout<<"asfashjfas"<<endl;
        for(int j=2; j<=n; j++){
            cout<<j<<endl;
            if(sqrt(j)==ceil(sqrt(j))){
                arr[j]=1;
                continue;
            }
            int r=INT_MAX;
            for(int i=1; i<=sqrt(j); i++){

                if(j-pow(i,2)>0){
                    r=min(r, arr[j-pow(i,2)]);
                }
            }
            arr[j]=1+r;
        }

        return arr[n];
    }
   
};