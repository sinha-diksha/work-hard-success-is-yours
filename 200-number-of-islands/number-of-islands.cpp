class Solution {
public:
    void bfs(vector<vector<char> > grid, int row, int col, vector<vector<int> >& visited){
        visited[row][col]=1;
        queue<pair<int,int> > q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int nr=r-1;
            int nc=c;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !visited[nr][nc]){
                q.push({nr,nc});
                visited[nr][nc]=1;
            }
            nr=r;
            nc=c+1;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !visited[nr][nc]){
                q.push({nr,nc});
                visited[nr][nc]=1;
            }
            nr=r;
            nc=c-1;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !visited[nr][nc]){
                q.push({nr,nc});
                visited[nr][nc]=1;
            }
            nr=r+1;
            nc=c;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !visited[nr][nc]){
                q.push({nr,nc});
                visited[nr][nc]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > visited;
        for(int i=0; i<n; i++){
            vector<int> v1(m);
            visited.push_back(v1);
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j,visited);
                }
            }
        }
        return count;
    }
};