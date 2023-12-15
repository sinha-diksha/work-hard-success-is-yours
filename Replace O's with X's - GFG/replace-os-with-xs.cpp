//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
   
    void dfs(int n, int m,  vector<vector<char>>& mat, int r, int c,vector<vector<int> >& vis, int delrow[], int delCol[] ){
        vis[r][c]=1;
        for(int i=0; i<4; i++){
            int nR=r+delrow[i];
            int nC=c+delCol[i];
            if(nR>=0 && nR<n && nC>=0 && nC<m && mat[nR][nC]=='O' && !vis[nR][nC]){
                dfs(n,m,mat,nR,nC, vis, delrow, delCol);
            }
        }
    }
public:
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int delrow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        vector<vector<int> > vis(n, vector<int>(m,0));
        for(int j=0; j<m; j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(n,m,mat,0,j,vis, delrow, delCol);
            }
            
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n,m,mat,n-1,j,vis,delrow, delCol);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(n,m,mat,i,0,vis,delrow, delCol);
            }
            
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(n,m,mat,i,m-1,vis,delrow, delCol);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='O' && vis[i][j]!=1){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends