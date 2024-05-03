class Solution {
public:
    int compareVersion(string version1, string version2) {
        string T;
        stringstream X(version1);
        vector<string> v1;
        vector<string> v2;
        stringstream Y(version2);
        while(getline(X,T,'.' )){
            v1.push_back(T);
        }
        while(getline(Y,T,'.' )){
            v2.push_back(T);
        }
        int n=max(v1.size(), v2.size());
        cout<<n<<endl;
        for(int i=0; i<n; i++){
            int a;
            int b;
            if(i>=v1.size()){
                a=0;
            }else{
                a=stoi(v1[i]);
            }
            if(i>=v2.size()){
                b=0;
            }else{
                b=stoi(v2[i]);
            }
            
            
            if(a<b){
                return -1;
            }
            else if(a>b){
                return 1;
            }
        }
        return 0;
    }
};