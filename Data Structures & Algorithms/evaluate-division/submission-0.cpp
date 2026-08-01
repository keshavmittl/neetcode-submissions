class Solution {
public:
    unordered_map<string ,vector<pair<string ,double>> >mp;
    double dfs(string src , string dst ,unordered_set<string>&vis){
        if(src == dst )return 1 ; 
        vis.insert(src);

        for(auto [neigh , wt] : mp[src] ){
            if(vis.count(neigh))continue;

            double val = dfs(neigh , dst ,vis);

            if(val != -1 )
            return wt * val ; 
        }
        return -1; 
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        int n  = eq.size();
        for(int i = 0 ;i< n ;i++){
            string u = eq[i][0];
            string v = eq[i][1];

            double val = values[i];

            mp[u].push_back({ v, val});
            mp[v].push_back({ u,1/val});
        }
        vector<double>ans;
        for(auto it : queries){
            string src = it[0];
            string dst = it[1];
            if(mp.find(src) == mp.end() || mp.find(dst) == mp.end()){
                ans.push_back(-1);
                continue;
            }
            unordered_set<string>vis;
            ans.push_back(dfs(src, dst , vis));
        }
        return ans ;
    }
};