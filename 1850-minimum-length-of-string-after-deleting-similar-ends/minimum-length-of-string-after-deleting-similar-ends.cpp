class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        vector<int> back(n);
        vector<int> front(n);
        front[0]=1;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                front[i]=front[i-1]+1;
            }else{
                front[i]=1;
            }
        }
        
        
        back[n-1]=1;
        for(int i=n-2; i>=0; i--){
            if(s[i]==s[i+1]){
                back[i]=back[i+1]+1;
            }else{
                back[i]=1;
            }
        }
        
        

        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                break;
            }
            
            i+=back[i];
            j-=front[j];
        }

        return max(0,j-i+1);
    }
};