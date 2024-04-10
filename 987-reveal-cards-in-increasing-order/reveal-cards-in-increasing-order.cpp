class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(), deck.end());
        int skip=0;
        vector<int> ans(n);
        int i=0;
        int j=0;
        while(i<n){
            if(ans[j]==0){
                if(skip==1){
                    j=(j+1)%n;
                    skip^=1;
                }else{
                    ans[j]=deck[i];
                    j=(j+1)%n;
                    i++;
                    skip^=1;
                }
            }else{
                j=(j+1)%n;
            }
        }

        return ans;
    }
};