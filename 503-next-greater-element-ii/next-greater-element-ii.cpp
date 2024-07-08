class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        
        vector<int> v(n);
        for(int i=2*n-1; i>=0; i--){
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            if(i<n){
                if(s.empty()){
                    v[i]=-1;
                }else{
                    v[i]=s.top();
                }
            }
            s.push(nums[i%n]);
        }

        return v;
    }
};