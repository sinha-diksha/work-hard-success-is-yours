class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string> s;
        while(getline(ss,token, '/')){
            if(token=="." || token==""){
                continue;
            }
            else if(token!=".."){
                s.push(token);
            }else if(!s.empty()){
                s.pop();
            }
        }

        if(s.empty()){
            return "/";
        }
        string ans="";
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        return ans;
    }
};