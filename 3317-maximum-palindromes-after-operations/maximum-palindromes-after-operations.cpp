class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<int,int> mp;
        vector<int> wordLength;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].length(); j++){
                mp[words[i][j]]++;
            }
            wordLength.push_back(words[i].length());
        }

        sort(wordLength.begin(), wordLength.end());
        int even=0;
        int odd=0;
        for(auto& it:mp){
            even+=(it.second/2);
            odd+=(it.second%2);
        }

        int ans=0;

        for(int i=0; i<wordLength.size(); i++){
            if(wordLength[i]%2!=0){
                if(odd>0){
                    odd--;
                }else{
                    even--;
                    odd+=2;
                    odd--;
                }
            }
            if(even<wordLength[i]/2){
                break;
            }
            even-=(wordLength[i]/2);
            ans++;
        }

        return ans;
    
    }
};