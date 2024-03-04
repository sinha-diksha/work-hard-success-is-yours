class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int> > v;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            vector<int> v1(m);
            int sum=0;
            for(int j=0; j<m; j++){
                sum+=grid[i][j];
                v1[j]=sum;
            }
            v.push_back(v1);
        }
        int ans=0;
        
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                v[i][j]=v[i-1][j]+v[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]<=k){
                    ans++;
                }
            }
        }

        return ans;
    }
};