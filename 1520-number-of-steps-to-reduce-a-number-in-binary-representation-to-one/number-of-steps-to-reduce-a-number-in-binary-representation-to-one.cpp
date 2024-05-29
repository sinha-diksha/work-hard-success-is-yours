class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int n=s.length();
        
        while(s.length()){
           
            if(s=="1"){
                return ans;
            }
            if(s.back()=='0'){
                ans++;
                s.pop_back();

            }else{
                int carry='1';
                for(int j=s.length()-1; j>=0; j--){
                    if(s[j]=='1' && carry=='1'){
                        s[j]='0';
                        carry='1';
                    }
                    else if(s[j]=='0' && carry=='1'){
                        s[j]='1';
                        carry='0';
                    }
                }
                if(carry=='1'){
                    s='1'+s;
                }
                s.pop_back();
                ans+=2;
          
            }
            // cout<<s<<" "<<ans<<endl;
        }

        return ans;

    }
};