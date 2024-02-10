class Solution {
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int,int> > > pq;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int s=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({s, {i,j}});
                }else if(pq.top().first>s){
                    pq.pop();
                    pq.push({s, {i,j}});
                }else{
                    break;
                }
            }
        }
     
        vector<vector<int>> ans;
       
        while(!pq.empty()){

            int a=nums1[pq.top().second.first];
            int b=nums2[pq.top().second.second];
            ans.push_back({a,b});
            pq.pop();
        }

        return ans;
    }
};