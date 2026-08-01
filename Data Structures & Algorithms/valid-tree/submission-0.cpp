class Solution {
public:
    // check wheather there is a cycle or not
    bool dfs(int node ,int parent , vector<vector<int>>&adj ,vector<int>&vis){
        vis[node] = 1 ;

        for(int neigh : adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh , node , adj ,vis))return true;
            }
            else if(neigh != parent) return true;
        }
        return false; 
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n, 0);

        if(dfs(0,-1,adj,vis))
            return false;

        for(int i=0;i<n;i++){

            if(!vis[i])
                return false;
        }
           
        return true;
    }
};
