//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(int i, vector<pair<int,int >> adj[], stack<int>& ans, vector<int>& visited){
        visited[i]=1;
        for(auto adjNode: adj[i]){
            if(!visited[adjNode.first])
                dfs(adjNode.first, adj, ans, visited);
        }
        ans.push(i);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int> > adj[N];
        for(int i=0; i<M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        stack<int> ans;
        vector<int> visited(N,0);
        for(int i=0; i<N; i++){
            if(!visited[i]){
                dfs(i, adj, ans, visited);
            }
        }
        vector<int> ans1(N, INT_MAX);
        ans1[0]=0;
        
        while(!ans.empty()){
            int top=ans.top();
       
            ans.pop();
            int dis=ans1[top];
            for(auto adjNode: adj[top]){
                ans1[adjNode.first]=min((long long)ans1[adjNode.first], (long long)dis+adjNode.second);
            }
        }
       
        for(int i=0; i<ans1.size(); i++){
            if(ans1[i]==INT_MAX){
                ans1[i]=-1;
            }
        }
        return ans1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends