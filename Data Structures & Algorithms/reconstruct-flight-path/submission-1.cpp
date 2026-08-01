class Solution {
public:
    unordered_map<string ,multiset<string>>adj;
    vector<string>ans;
    void dfs(string node){
        while(!adj[node].empty()){
            auto it = adj[node].begin();
            string next = *it ; 
            adj[node].erase(it);

            dfs(next);
        } 
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets){
            adj[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");

        reverse(ans.begin() , ans.end());
        return ans; 
    }
};
