class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin() ,deadends.end());
        if(dead.count("0000")) return -1 ;

        queue<pair<string , int>>q; // stores string reached in steps
        unordered_set<string>vis;//stores the combi visited
        q.push({"0000" , 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string combi = it.first;
            int steps = it.second;

            if(combi == target) return steps; 
            for(int i = 0 ;i<4 ;i++){
                char ori = combi[i];
                //rotate up 
                combi[i] = (ori == '9') ? '0' :ori +1 ; 

                if (!dead.count(combi) && !vis.count(combi)) {
                    vis.insert(combi);
                    q.push({combi, steps + 1});
                }

                //rotate down 

                combi[i] = (ori == '0')?'9' : ori -1 ;
                if (!dead.count(combi) && !vis.count(combi)) {
                    vis.insert(combi);
                    q.push({combi, steps + 1});
                }

                combi[i] = ori;
            }
        }
        return -1; 
    }
};