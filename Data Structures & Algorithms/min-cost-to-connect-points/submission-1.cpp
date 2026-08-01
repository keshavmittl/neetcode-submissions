class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i =0 ; i< n ;i++){
            for(int j = i+1 ; j< n ;j++){
                int x = abs(points[j][0] - points[i][0]);
                int y = abs(points[j][1] - points[i][1]);

                adj[i].push_back({ j ,x+ y});
                adj[j].push_back({ i ,x+ y});
            }
        }

        //now we have an adj mat , just find the min spanning tree
        priority_queue<pair<int,int> , vector<pair<int ,int>> ,greater<pair<int ,int>>>pq;//store dst ,node
        vector<int>vis(n, 0);

        pq.push({0,0});
        int sum = 0 ; 
        while(!pq.empty()){
            auto[dst, node] = pq.top();
            pq.pop();

            if(vis[node])continue;
            vis[node] =1 ;
            sum +=dst;

            for(auto [neigh , wt]: adj[node]){
                if(!vis[neigh])
                    pq.push({wt , neigh});
            }
        }
        return sum; 
    }
};
