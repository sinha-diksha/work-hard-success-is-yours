class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue <int, vector<int>, greater<int>> pq;
        int k=0;
        vector<int> v;
        for(int i=0; i<score.size(); i++){
            v.push_back(score[i]);
        }
       
        sort(v.begin(), v.end(), greater<int>());
        vector<string> ans(score.size());
        for(int i=0; i<score.size(); i++){
            
            int idx=find(v.begin(), v.end(), score[i])-v.begin();
            cout<<idx<<endl;
            if(idx==0){
                ans[i]="Gold Medal";
            }else if(idx==1){
                ans[i]="Silver Medal";
            }else if(idx==2){
                ans[i]="Bronze Medal";
            }else{
                ans[i]=to_string(idx+1);
            }
        }

        return ans;

    }
};