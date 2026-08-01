class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //classix multisrc bfs
        queue<pair<int,int>>q;
        int n = grid.size();
        int m =grid[0].size();
        for(int i = 0 ;i< n ;i++){
            for(int j = 0 ;j< m ;j++){
                if(grid[i][j] == 2)q.push({i , j});
            }
        }
        
        int steps = 0 ;

        int delr[] ={ 0, 1 ,0 ,-1};
        int delc[] ={1 ,0 ,-1 , 0};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;

                for(int k = 0 ; k< 4 ; k++){
                    int r = i+ delr[k];
                    int c = j+ delc[k];


                    if(r>=0 && c>=0 && r< n && c< m && grid[r][c] == 1){
                        grid[r][c] = 2 ; 
                        q.push({r,c});
                    }
                }
            }
            if(!q.empty())steps++;
        }

        for(int i = 0 ;i<n ;i++){
            for(int j = 0 ;j< m ;j++){
                if(grid[i][j] == 1)return -1;
            }
        }
        return steps;
    }
};
