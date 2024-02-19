class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<P, vector<P>, greater<P> > pq;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> v(nums.size()+1);
        for(auto&it:mp){
            int a=it.first;
            int b=it.second;
            v[b].push_back(a);
        }
        vector<int> ans;
        int i=nums.size();
        for(; i>=0 && k>0; i--){
            if(v[i].size()==0)
                continue;
            while(v[i].size()>0 && k>0){
                ans.push_back(v[i].back());
                v[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};