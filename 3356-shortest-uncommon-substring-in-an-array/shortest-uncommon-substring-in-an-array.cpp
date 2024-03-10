class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string,int> mp;
        for(int i=0; i<arr.size(); i++){
           
            for(int i1=0; i1<arr[i].length(); i1++){
                string ans="";
                for(int j=i1; j<arr[i].length(); j++){
                    ans+=arr[i][j];
                    mp[ans]++;
                }
            }
        }
        vector<string> ans2;
        for(int i=0; i<arr.size(); i++){
            for(int i1=0; i1<arr[i].length(); i1++){
                string ans="";
                for(int j=i1; j<arr[i].length(); j++){
                    ans+=arr[i][j];
                    mp[ans]--;
                }
            }
            string ans1="";
            for(int i1=0; i1<arr[i].length(); i1++){
                string ans="";
                for(int j=i1; j<arr[i].length(); j++){
                    ans+=arr[i][j];
                    if(mp[ans]==0){
                        if(ans1==""){
                            ans1=ans;
                        }else if(ans1.length()>ans.length()){
                            ans1=ans;
                        }else if(ans1.length()==ans.length() && ans1>ans){
                            ans1=ans;
                        }
                    }
                }
            }
            for(int i1=0; i1<arr[i].length(); i1++){
                string ans="";
                for(int j=i1; j<arr[i].length(); j++){
                    ans+=arr[i][j];
                    mp[ans]++;
                }
            }

            ans2.push_back(ans1);

        }

        return ans2;
    }
};