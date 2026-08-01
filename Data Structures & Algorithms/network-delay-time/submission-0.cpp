class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int ,int>>>adj(n + 1);

        for(auto it : times){
            int u = it[0];
            int v= it[1];
            int t = it[2];
            adj[u].push_back({v ,t});
        }
        //we want the shortest route , we will use pq 
        priority_queue<pair<int,int> , vector<pair<int ,int>> , greater<pair<int,int>>>pq; 
        vector<int>dist(n +1  , 1e9);
        pq.push({0, k}); // k is the src
        dist[k] = 0 ;
        while(!pq.empty()){
            auto [time , node] =pq.top();
            pq.pop();
            if(time > dist[node])continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(time + wt < dist[adjNode]){
                    dist[adjNode] = time + wt;  
                    pq.push({time + wt , adjNode});
                }
            }
        }

        int maxi = 0 ; 
        for(int i= 1 ; i <= n ;i++){
            if(dist[i] >= 1e9)return -1;
            maxi = max(maxi , dist[i]); 
        }
        return maxi;
    }
};
