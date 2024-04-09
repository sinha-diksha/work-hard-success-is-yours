class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        deque<pair<int,int>> q;
        int n=tickets.size();
        for(int i=0; i<n; i++){
            q.push_back({i,tickets[i]});
        }
        while(!q.empty()){
            ans++;
            auto it=q.front();
            q.pop_front();
            it.second--;
            if(it.second==0 && it.first==k){
                return ans;
            }
            else if(it.second!=0){
                q.push_back({it.first, it.second});
            }
        }
        return ans;
    }
};