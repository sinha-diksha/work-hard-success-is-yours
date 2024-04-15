class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        vector<int> preSum(n);
        if(possible[0]==0){
            preSum[0]=-1;
        }else{
            preSum[0]=1;
        }
        for(int i=1; i<n; i++){
            if(possible[i]==0){
                preSum[i]=preSum[i-1]-1;
            }else{
                preSum[i]=preSum[i-1]+1;
            }
        }

        vector<int> sufSum(n);
        if(possible[n-1]==0){
            sufSum[n-1]=-1;
        }else{
            sufSum[n-1]=1;
        }
        for(int i=n-2; i>=0; i--){
            if(possible[i]==0){
                sufSum[i]=sufSum[i+1]-1;
            }else{
                sufSum[i]=sufSum[i+1]+1;
            }
        }

      

        for(int i=0; i<n-1; i++){
            if(preSum[i]>sufSum[i+1]){
                return i+1;
            }
        }

        return -1;

        
    }
};