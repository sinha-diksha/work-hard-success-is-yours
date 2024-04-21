class Solution {
public:
    bool dfs(int n,vector<vector<int>>& v,int source, int destination, vector<int>& visited ){
     
        visited[source]=1;
        cout<<source<<endl;
        if(source==destination){
            return true;
        }
        for(auto i:v[source]){
            if(visited[i]== -1){
                if(dfs(n,v,i,destination,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int> > v(n);
        for(int i=0; i<edges.size(); i++){
            int i1=edges[i][0];
            int j=edges[i][1];
            v[i1].push_back(j);
            v[j].push_back(i1);
            
        }
        vector<int> visited(n,-1);
        return dfs(n,v,source,destination, visited);
    }
};