class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3){
            return false;
        }
        vector<char> v={'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
        int vowelCount=0;
        int consonantCount=0;
        for(int i=0; i<word.length(); i++){
            if((word[i]>='0' && word[i]<='9') || (word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')){
                    if(find(v.begin(), v.end(), word[i])!=v.end()){
                        vowelCount++;
                    }else if(!(word[i]>='0' && word[i]<='9')){
                        consonantCount++;
                    }
            }else{
                return false;
            }
        }

        cout<<vowelCount<<" "<<consonantCount<<endl;

        if(vowelCount && consonantCount){
            return true;
        }
        return false;
    }
};