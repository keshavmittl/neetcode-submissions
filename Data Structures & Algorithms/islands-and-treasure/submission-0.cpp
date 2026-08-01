class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //multisrc bfs 
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q ; 
        for(int i = 0 ;i< n ;i++ ){
            for(int j =0 ; j<m; j++){
                if(grid[i][j] == 0 )q.push({0 ,{i , j}});
            }
        }
        int delr[]={-1 , 0 ,1, 0};
        int delc[]={0 ,1, 0 , -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int i = it.second.first;
            int j = it.second.second;
            int steps = it.first; 

            for(int k = 0 ; k< 4 ;k++){
                int r = i + delr[k];
                int c = j + delc[k];


                if(r>=0 && c>= 0 && r<n && c< m){
                    if(grid[r][c] > steps+1 ){
                        grid[r][c] = steps+1; 
                        q.push({steps +1 , {r, c}});
                    }
                } 
            }
        }
    }
};
