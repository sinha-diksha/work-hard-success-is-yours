class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int,int> > > v;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                double value=arr[i]/(double)arr[j];
                v.push_back({value, {arr[i], arr[j]}});
            }
        }
        sort(v.begin(), v.end());
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
        // }
        vector<int> v1={v[k-1].second.first, v[k-1].second.second};
        return v1;
    }
};