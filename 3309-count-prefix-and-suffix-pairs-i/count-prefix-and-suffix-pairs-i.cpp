class Solution {
    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.length()>str2.length()){
            return false;
        }
        int n=str1.length();
        string a=str2.substr(0,n);
        int n1=str2.length();
        string b=str2.substr(n1-n,n);
        // cout<<a<<" "<<b<<endl;
        return a==str1 && b==str1;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(i==j){
                    continue;
                }
                if(isPrefixAndSuffix(words[i], words[j])){
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    count++;
                }
            }
        }

        return count;
    }
};