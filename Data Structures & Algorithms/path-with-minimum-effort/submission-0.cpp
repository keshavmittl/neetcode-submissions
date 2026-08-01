class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>dist(n ,vector<int>(m , 1e9));// all the nodes are unreachable   
        priority_queue<pair<int , pair<int, int>> , vector<pair<int ,pair<int ,int>>> , greater<pair<int , pair<int ,int >>> >pq; // store dist , i , j
        pq.push({0 , {0 , 0}});
        dist[0][0] = 0 ; 
        int delr[] = {0 , 1, 0 ,-1}; 
        int delc[] = {1, 0 ,-1 , 0}; 

        while(!pq.empty()){
            auto [diff, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if(r == n-1 && c == m-1)return diff;
            for(int i = 0 ;i< 4 ;i++){
                int nr = r + delr[i];
                int nc = c + delc[i];


                if(nr>=0 && nr< n && nc>=0 && nc<m ){
                    int effort = abs(heights[nr][nc] - heights[r][c]);
                    int maxeffort = max(diff , effort);

                    if(dist[nr][nc] > maxeffort){
                        dist[nr][nc] = maxeffort;
                        pq.push({maxeffort,{nr , nc}});
                    }
                }
            }
            
        }
        return 0 ;     
    }
};