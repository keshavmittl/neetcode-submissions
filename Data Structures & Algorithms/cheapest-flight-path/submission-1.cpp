class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto edge:flights){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        queue<tuple<int,int,int>>q;//store cost , node, stops

        vector<int>dist(n , 1e9);   
        q.push({0, src ,0});
        dist[src] = 0 ;

        while(!q.empty()){
            auto [cost, node, stops] = q.front();
            q.pop();

            if(stops > k)continue;

            for(auto edge : adj[node]){
                int wt= edge.second;
                int adjNode = edge.first;

                if(dist[adjNode] > wt+ cost){
                    dist[adjNode] = wt+ cost;
                    q.push({ dist[adjNode] , adjNode , stops+1});
                }
            }
        }
       if(dist[dst] == 1e9)return -1 ;
       return dist[dst];
    }
};
