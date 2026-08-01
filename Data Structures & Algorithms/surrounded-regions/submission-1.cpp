class Solution {
public:
    void dfs(int i ,int j , vector<vector<char>>&board ,vector<vector<int>>&vis){
        vis[i][j] = 1; 
        int delr[]= {-1 ,0 ,1, 0};
        int delc[]= {0 ,1, 0 , -1};
        for(int k = 0 ; k< 4 ;k++){
            int r = i+ delr[k];
            int c = j + delc[k];

            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() &&!vis[r][c] && board[r][c] =='O'){
                dfs(r , c, board , vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        //start from all edges and marked points that are reachable as true and all the other will remain same
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m, 0));

        for(int i = 0 ; i < n ;i++){
            if(board[i][0] =='O')
            dfs(i , 0 ,board ,vis ) ;// first col
            if(board[i][m-1] =='O')
            dfs(i , m-1 ,board ,vis ) ;// last col
        }

        for(int j = 0 ;j<m ; j++){
            if(board[0][j] == 'O')
            dfs(0 , j , board, vis);
            if(board[n-1][j] =='O')
            dfs(n -1 , j , board , vis);
        }
        
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j<m ;j++){
                if(board[i][j]== 'O' && vis[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};
