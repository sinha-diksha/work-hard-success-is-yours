class Solution {
public:
    int minimumChairs(string s) {
        int ans=0;
        int emptyChairs=0;
        for(auto i:s){
            if(i=='L'){
                emptyChairs++;
            }else{
                if(emptyChairs){
                    emptyChairs--;
                }
                else{
                    ans++;
                }
            }
        }

        return ans;
    }
};