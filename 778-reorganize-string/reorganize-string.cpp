class Solution {
public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        int n=s.length();
        vector<int> count(26);
        int r=(n+1)/2;
        int maxCount=0;
        char maxChar;
        for(int i=0; i<n; i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a']>r){
                return "";
            }
            if(count[s[i]-'a']>maxCount){
                maxChar=s[i];
                maxCount=count[s[i]-'a'];
            }
        }

        string result=s;
        int i=0;
        cout<<count[maxChar-'a']<<endl;
        while(count[maxChar-'a']>0){
            result[i]=maxChar;
            
            count[maxChar-'a']--;
            i+=2;
        }
        cout<<result<<endl;
        for(char ch='a'; ch<='z'; ch++){
            while(count[ch-'a']>0){
                cout<<ch<<" "<<i<<endl;
                if(i>=n){
                    i=1;
                }
                result[i]=ch;
                count[ch-'a']--;
                i+=2;
            }
        }

        return result;
    }
};