class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int> > v;
        for(int i=0; i<grid.size(); i++){
            vector<int> v1(grid[0].size());
            int sum=0;
            for(int j=0; j<grid[0].size(); j++){
                sum+=grid[i][j];
                v1[j]=sum;
            }
            v.push_back(v1);
        }
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > mat(n, vector<int>(m,0));
        // mat[0][0]=grid[0][0];
        // for(int i=1; i<m; i++){
        //     mat[0][i]=mat[0][i-1];
        // }
        // for(int i=1; i<n; i++){
        //     mat[i][0]=mat[i-1][0]+v[i][0];
        //     for(int j=1; j<m; j++){
        //         mat[i][j]=mat[i-1][j]+grid[i][j];
        //     }
        // }
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