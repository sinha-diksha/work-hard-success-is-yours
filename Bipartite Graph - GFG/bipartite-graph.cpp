//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfs(int i, int V, vector<int> adj[], vector<int>& vis){
        vis[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            int col=vis[a];
            
            for(auto adjNode : adj[a]){
                if(vis[adjNode]==-1){
                    vis[adjNode]=(col^1);
                    q.push(adjNode);
                }else{
                    if(vis[adjNode]==col){
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V, -1);
	    for(int i=0; i<V; i++){
	        if(vis[i]==-1){
	            if(!bfs(i,V,adj,vis)){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends