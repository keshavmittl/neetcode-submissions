class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 1 )return {0};
        vector<int>indegree(n);
        vector<vector<int>>adj(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int>q;
        for(int i = 0 ; i< n ;i++){
            if(indegree[i] == 1)q.push(i); // these are the leaf nodes
        }

        int remain = n ; 

        while(remain > 2){
            int sz = q.size();
            remain -=sz;

            while(sz--){
                int node= q.front();
                q.pop();

                for(int neigh : adj[node]){
                    indegree[neigh]-- ;
                    if(indegree[neigh] == 1 ){
                        q.push(neigh);
                    }
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
    return ans ; 
    }
};