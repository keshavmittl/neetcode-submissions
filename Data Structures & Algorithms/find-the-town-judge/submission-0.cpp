class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //there is a directed edge between a-->b 
        vector<int>indegree(n+1, 0 );
        vector<int>outdegree(n+1, 0 );

        for(auto t : trust){
            indegree[t[1]]++;
            outdegree[t[0]]++;
        }

        for(int i = 1 ; i< n+1 ; i++){
            if(outdegree[i] ==0  && indegree[i] == n-1){
                return i ; 
            }
        }
        return -1; 
    }
};