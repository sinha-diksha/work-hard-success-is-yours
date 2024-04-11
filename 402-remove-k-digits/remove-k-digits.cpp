class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        int n=num.length();
        for(int i=0; i<n; i++){
       
          
            while(s.length()>0 && s.back()>num[i] && k>0){
                s.pop_back();
                k--;
            }

            if(s.length()>0 || num[i]!='0'){
                s.push_back(num[i]);
            }

        }

        while(s.size()>0 && k>0){
            s.pop_back();
            k--;
        }

        if(s.size()==0){
            return "0";
        }

        return s;
    }
};