class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wT=0;
        wT+=customers[0][1];
        int eT=customers[0][0]+wT;
        int n=customers.size();
        for(int i=1; i<customers.size(); i++){
            if(eT>=customers[i][0]){
                eT+=customers[i][1];
                wT+=(eT-customers[i][0]);
            }else{
                wT+=customers[i][1];
                eT=customers[i][0]+customers[i][1];
            }
            cout<<wT<<endl;
        }
        cout<<wT<<endl;
        return wT/n;
    }
};