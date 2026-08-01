class Solution {
public:
    bool dfs(int node, vector<int>&vis , vector<int>&pathvis, vector<vector<int>>&adj){
        vis[node] =1 ;
        pathvis[node] =1 ;
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh, vis , pathvis , adj)) return true ;
            }
            else if(pathvis[neigh]){
                return true ;
            }
        }
        pathvis[node] = 0 ; 
        return false ; 
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        //create an directed edge between b -> a 

        vector<vector<int>>adj(n);
        for(auto edge : pre){
            adj[edge[1]].push_back(edge[0]);
        }
        //check if there is a cycle in this 
        vector<int>vis(n , 0);
        vector<int>pathvis(n , 0);
        for(int i = 0 ; i<n ;i++){
            if(!vis[i])
            if(dfs(i , vis ,pathvis , adj))return false   ;
        }
        return true ; 
    }
};
