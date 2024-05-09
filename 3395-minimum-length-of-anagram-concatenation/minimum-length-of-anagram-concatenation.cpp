class Solution {
public:
    int minAnagramLength(string s) {
        vector<int> div;
        int n=s.length();
        for(int i=1; i<n; i++){
            if(n%i==0){
                div.push_back(i);
            }
        }
        for(auto k:div){
            string ans=s.substr(0, k);
            sort(ans.begin(), ans.end());
            bool isBreak=false;
            for(int i=k; i<n; ){
                string s2=s.substr(i,k);
                i+=k;
                sort(s2.begin(),s2.end());
                if(s2!=ans){
                    isBreak=true;
                    break;
                }
                
            }
            if(!isBreak){
                return k;
            }
        }

        return n;
    }
};