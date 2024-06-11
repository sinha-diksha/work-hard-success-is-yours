class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A1, vector<int>& A2) {
        map<int,int> ourMap;
        int N=A1.size();
        int M=A2.size();
    for(int i=0; i<N; i++){
        if(ourMap.count(A1[i])>0){
            ourMap[A1[i]]++;
            continue;
        }
        ourMap[A1[i]]=1;
    }
    vector<int> v;
    for(int j=0; j<M; j++){
        if(ourMap.count(A2[j])>0){
            for(int k=0; k<ourMap[A2[j]]; k++){
                v.push_back(A2[j]);

            }
            ourMap.erase(A2[j]);
        }
    }
    auto i=ourMap.begin();
    while(i!=ourMap.end()){
        for(int j=0; j<i->second; j++){
            v.push_back(i->first);
        }
        i++;
    }
    return v;
    }
};