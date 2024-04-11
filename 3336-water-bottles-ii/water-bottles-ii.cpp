class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        int Empty=numBottles;
        while(numExchange<=Empty){
            Empty-=numExchange;
            ans++;
            numExchange+=1;
            Empty++;
        }
        return ans;
    }
};