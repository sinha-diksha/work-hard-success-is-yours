class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n=s.length();
        int m=goal.length();
        if(n!=m){
            return false;
        }
        s=s+s;
        cout<<s<<endl;
        n=s.length();
        for(int i=0; i<=n-m; i++){
            bool isFound=true;
            int k=i;
            for(int j=0; j<m; j++){
                
                if(goal[j]!=s[j+k]){

                   
                    isFound=false;
                    break;
                }

            }
            if(isFound==true){
                return true;
            }else{
                continue;
            }
        }
        return false;
    }
};