class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        //we will use toposort , that ensures the //
        vector<int>indegree(n);
        vector<vector<int>>adj(n);
        for(auto edge : pre){
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0 ; i<n ;i++){
            for(auto it : adj[i]){
                indegree[it]++; 
            }
        }   
        queue<int>q;

        for(int i = 0 ; i<n ;i++){
            if(indegree[i] == 0 )q.push(i);
        }

        vector<int>topo; 

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] ==0 )q.push(it);
            }
        }
        if(topo.size() == n) return topo;
        return{};
    }
};
