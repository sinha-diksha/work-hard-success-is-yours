class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        int n=piles.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(piles[i]);
        }
        for(int i=0; i<k; i++){
            int a=pq.top();
            pq.pop();
            a=a-(a/2);
            pq.push(a);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};