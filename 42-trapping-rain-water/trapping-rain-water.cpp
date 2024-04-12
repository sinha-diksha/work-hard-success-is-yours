class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=-1;
        for(int i=1; i<n; i++){
            left[i]=max(height[i-1],left[i-1]);
        }
        right[n-1]=-1;
        for(int i=n-2; i>=0; i--){
            right[i]=max(height[i+1],right[i+1]);
        }
        // for(int i=0; i<n; i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;

        int ans=0;
        for(int i=1; i<n-1; i++){
            int r=min(left[i],right[i]);
            int k=r-height[i];
            ans+=max(0,k);
        }

        return ans;

    }
};