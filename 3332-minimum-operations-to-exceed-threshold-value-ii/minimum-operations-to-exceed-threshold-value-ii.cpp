class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>, greater<long long> > pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        int count=0;
        while(!pq.empty() && pq.top()<k){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            pq.push(a*2+b);
            count++;
        }
        return count;
    }
};