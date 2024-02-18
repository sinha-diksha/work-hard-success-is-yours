class Solution {
    typedef pair<int,pair<int,int> > P;
    struct cmp{
        bool operator()(P p1, P p2){
            if(p1.first!=p2.first){
                return p1.first>p2.first;
            }
            return p1.second.first>p2.second.first;
        }
    };

    public:
    
    
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<P, vector<P>, cmp> pq;
        int n=costs.size();
        if(n<candidates*2){
            sort(costs.begin(), costs.end());
            int ans=0;
            for(int i=0; i<k; i++){
                ans+=costs[i];
            }
            return ans;
        }
        int l=0;
        int j=n-1;
        for(int i=0; i<candidates; i++){
            pq.push({costs[l],{l,1}});
            pq.push({costs[j],{j,-1}});
            l++;
            j--;
        }
        long long ans=0;
        cout<<pq.size()<<endl;
        cout<<pq.top().first<<endl;
        while(k>0 && l<=j){
            k--;
            auto p1=pq.top();
            pq.pop();
            ans+=p1.first;
            if(p1.second.second==1){
                pq.push({costs[l],{l,1}});
                l++;
            }else{
                pq.push({costs[j],{j,-1}});
                j--;
            }
        }
        if(k==0)
            return ans;
        while(k>0){
             k--;
            auto p1=pq.top();
            pq.pop();
            ans+=p1.first;
        }
        return ans;
    }
    
};