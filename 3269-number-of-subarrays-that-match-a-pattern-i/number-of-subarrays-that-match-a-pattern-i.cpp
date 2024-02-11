class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        queue<int> q2;
        for(int i=0; i<pattern.size(); i++){
            q2.push(pattern[i]);
        }
        int ans=0;
        queue<int> v;
        int m=pattern.size();
        for(int i=0; i<m; i++){
            if(nums[i+1]>nums[i]){
                v.push(1);
            }else if(nums[i+1]==nums[i]){
                v.push(0);
            }else{
                v.push(-1);
            }
        }
        if(v==q2){
            cout<<"fdsahfkdsa"<<endl;
            ans++;
        }
       
        for(int i=m+1; i<n; i++){
            v.pop();
            if(nums[i]>nums[i-1]){
                v.push(1);
            }else if(nums[i]==nums[i-1]){
                v.push(0);
            }else{
                v.push(-1);
            }

            if(v==q2){
                cout<<i<<endl;
                ans++;
            }  
        }
        

        return ans;
    }
};