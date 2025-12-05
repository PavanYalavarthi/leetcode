class Solution {
    vector<vector<bool>> row, col, block;

public:
    void solveSudoku(vector<vector<char>>& board) {
        row = col = block = vector<vector<bool>>(9, vector<bool>(9, false));

        // Initialize constraint matrices from the input board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    int blk = (i / 3) * 3 + (j / 3);
                    row[i][index] = col[j][index] = block[blk][index] = true;
                }
            }
        }

        sudokuHelper(board, 0, 0);
    }

    bool sudokuHelper(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return sudokuHelper(board, i + 1, 0);

        if (board[i][j] != '.') return sudokuHelper(board, i, j + 1);

        int blk = (i / 3) * 3 + (j / 3);
        for (char ch = '1'; ch <= '9'; ++ch) {
            int index = ch - '1';
            if (row[i][index] || col[j][index] || block[blk][index]) continue;

            board[i][j] = ch;
            row[i][index] = col[j][index] = block[blk][index] = true;

            if (sudokuHelper(board, i, j + 1)) return true;

            // Backtrack
            board[i][j] = '.';
            row[i][index] = col[j][index] = block[blk][index] = false;
        }

        return false;
    }
};