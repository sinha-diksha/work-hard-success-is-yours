class Solution {
public:
    bool checkValidString(string s) {
        stack<char> left;
        stack<char> star;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                left.push(i);
            }else if(s[i]=='*'){
                star.push(i);
            }else{
                if(left.size()==0 && star.size()==0){
                    return false;
                }
                else if(left.size()!=0){
                    left.pop();
                }else{
                    star.pop();
                }
            }
        }
        if(left.size()==0){
            return true;
        }
        while(left.size()!=0){
            while(!star.empty() && star.top()<left.top()){
                return false;
            }
            if(star.empty()){
                return false;
            }else{
                star.pop();
                left.pop();
            }
        }

        return true;
    }
};