class Solution {
    int ans=0;
    vector<int> r={1,-1,0,0};
    vector<int> c={0,0,-1,1};
    int dfs(int i, int j, vector<vector<int> >& grid, int n, int m){
        int temp=grid[i][j];
       
        grid[i][j]=0;
        int maxi=0;
        for(int k=0; k<4; k++){
            int nR=i+r[k];
            int nC=j+c[k];
            
            if(nR>=0 && nR<n && nC>=0 && nC<m && grid[nR][nC]!=0){
  
                int val=dfs(nR, nC, grid, n, m);
              
                maxi=max(val,maxi);
            }
        }
        grid[i][j]=temp;
        return temp+maxi;
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0){
                    int val=dfs(i, j, grid, grid.size(), grid[0].size());
                   
                    ans=max(ans, val);
                }
            }
        }

        return ans;
    }
};