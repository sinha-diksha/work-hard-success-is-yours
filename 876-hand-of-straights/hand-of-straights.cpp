class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[hand[i]]++;
        }
        while(mp.size()){
            auto it=mp.begin();
            int a=it->first;
            mp[it->first]--;
            if(mp[a]==0){
                mp.erase(a);
            }
        
            for(int i=1; i<groupSize; i++){
                
                if(mp.count(a+i)>0){
                    mp[a+i]--;
                    if(mp[a+i]==0){
                        mp.erase(a+i);
                    }
                }else{
                    
                    return false;
                }
            }
     
            
        }
        return true;
    }
};