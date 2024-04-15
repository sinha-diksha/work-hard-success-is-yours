class Solution {
public:
    //bellman ford.
    //just run it k+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int dst, int k) {
        
        vector<pair<int,int> > adj[n];
        for(auto itr: a){
            adj[itr[0]].push_back({itr[1], itr[2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stops>k){
                continue;
            }
            for(auto i:adj[node]){
                int edW=i.second;
                int adjNode=i.first;
                if(dis+edW < dist[adjNode] && stops<=k){
                    dist[adjNode]=dis+edW;
                    q.push({stops+1, {adjNode, dis+edW}});
                }
            }
        }

        if(dist[dst]!=1e9){
            return dist[dst];
        }
        return -1;
    }
};