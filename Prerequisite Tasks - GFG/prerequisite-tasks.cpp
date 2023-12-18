//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<vector<int> > adj(N);
	    for(auto i:prerequisites){
	        adj[i.second].push_back(i.first);
	    }
	    
	    vector<int> indegree(N);
	    for(int i=0; i<N; i++){
	        for(auto adjNode : adj[i]){
	            indegree[adjNode]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<N; i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int a=q.front();
	        ans.push_back(a);
	        q.pop();
	        for(auto node: adj[a]){
	            indegree[node]--;
	            if(indegree[node]==0){
	                q.push(node);
	            }
	        }
	    }
	    
	    return ans.size()==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends