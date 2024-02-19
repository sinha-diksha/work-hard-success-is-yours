class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int n=nums.size();
        int size=0;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
            size++;
            if(size>k){
                pq.pop();
                size--;
            }
        }

        return pq.top();
    }
};