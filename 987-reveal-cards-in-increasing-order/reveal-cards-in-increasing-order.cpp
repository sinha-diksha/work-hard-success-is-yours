class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(), deck.end());
        vector<int> ans(n);
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        int i=0;
        while(i<n){
            int index=q.front();
            q.pop();
            ans[index]=deck[i];
            i++;
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};