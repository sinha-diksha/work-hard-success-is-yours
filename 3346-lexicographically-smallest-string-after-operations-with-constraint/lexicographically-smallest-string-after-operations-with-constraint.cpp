class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans=s;
        for(int i=0; i<s.length(); i++){
            char a1=s[i];
            int b1=a1-'a';
            for(int j=0; j<26; j++){
                if(b1>j){
                    int a2=abs(j-b1);
                    int b2=26-a2;
                    int ans1=min(a2,b2);
                    if(ans1<=k){
                        k-=ans1;
                        ans[i]='a'+j;
                        break;
                    }
                }
            }
        }

        return ans;
    
    }
};