class Solution {
    bool f(int j, int n, string s, vector<string> &dictionary, vector<int>& v){
        if(j==s.length()){
            return true;
        }
        if(v[j]!=-1){
            if(v[j]==1){
                return true;
            }
            return false;
        }
        bool t=false;
        
        for(int i=j; i<s.length(); i++){
            if(find(dictionary.begin(), dictionary.end(),s.substr(j,i-j+1))!=dictionary.end()){
              
                t= t || f(i+1,n,s,dictionary,v);
            }
        }
        if(t){
            v[j]=1;
        }else{
            v[j]=0;
        }
        return t;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        
        vector<int> v(s.length()+1,-1);
        if(f(0,n,s,wordDict,v)){
            return true;
        }
        return false;
    }
};