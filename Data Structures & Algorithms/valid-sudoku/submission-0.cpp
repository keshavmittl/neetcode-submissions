class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for (int i = 0; i < 9; i++) {
            vector<int> freq(10);

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {

                    if (freq[board[i][j] - '0'])
                        return false;

                    freq[board[i][j] - '0']++;
                }
            }
        }

        // Check columns
        for (int i = 0; i < 9; i++) {
            vector<int> freq(10);

            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {

                    if (freq[board[j][i] - '0'])
                        return false;

                    freq[board[j][i] - '0']++;
                }
            }
        }

        // Check 3x3 boxes
        for (int sq = 0; sq < 9; sq++) {

            vector<int> freq(10);

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                    int r = (sq / 3) * 3 + i;
                    int c = (sq % 3) * 3 + j;

                    if (board[r][c] != '.') {

                        if (freq[board[r][c] - '0'])
                            return false;

                        freq[board[r][c] - '0']++;
                    }
                }
            }
        }

        return true;
    }
};